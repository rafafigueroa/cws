#include "ros/ros.h"
#include "std_msgs/String.h"
#include "geometry_msgs/Twist.h"
#include "std_msgs/Float64.h"
#include "shared_memory.h"
#include <sstream>

const double PI= 3.141592653589793;

// ****** GAIN ***** //
	float Kp=0.1; //balancing gain
	float Ka=1.75; //aligment gain

// ***** DESIRED PARAMETERS *****//
float r0=0.5; //desired radius
float w0=0.403;//0.267; //desired angular velocity
float v0=w0*r0;//desired linear velocity
	
//TODO:in real program eliminate spaces in names
std::string robots[] = {"David","Bishop","quadrotor_2b","quadrotor_3"};
int robotNum = 4; //total number of robots
int N=floor(robotNum/2); //robots per group
int coordNum = 6; //coordinates on state vector
int myID = 0; //0 David ,1 Bishop (not used for tsim)

// X state of 6 elements [xpos ypox zpos ang_x ang_y ang_z]
float X[4][6]; 
double theta_d[4]={0}; //all thetas

//pose has the following variables
float x;
float y;
double theta_i;

//control law additional coordinate system
float r_i;
double eta_i; 

//functions
float dP_r; //derivative of P respect to r
float f; // f = -dP_r + Lambda + Phi
float Lambda; //Sepulchre component (balancing)
float Phi; //Phase Aligment

//control (input)
float u; // theta dot

//for calculating angle differences following 
//paper assumptions
double minAngle(double angle){
	return atan2(sin(angle),cos(angle));
}

int main(int argc, char **argv)
{

	SharedMemory *shm = new SharedMemory("ViconShared",41234,sizeof(X));
	ros::init(argc, argv, "ViconSocket");
	std::cout << "Vicon Socket Initialized\n";

	ros::NodeHandle ViconNode;
	ros::Publisher vicon_pub = ViconNode.advertise<geometry_msgs::Twist>("/mobile_base/commands/velocity", 1000);
	ros::Rate loop_rate(50);
	

// ************** //
// **** LOOP **** //
// ************** //
  int count = 0;
  while (ros::ok())
  {
	//READ STATE FROM SHARED MEMORY 
	shm->read((void *)X);
	
	//MY CURRENT POSITION
	std::cout << robots[myID] << std::endl
			<< std::setprecision(4) 
			<< " pos:\t" 
			<< X[myID][0] << " "  
			<< X[myID][1] << " " 
			<< X[myID][2] << " " 
			<< X[myID][3]
			<< std::endl;
	
	//CONTROL LAW
	
	//get theta_d (vector with all angles)
	for(int robotID=0;robotID<4;robotID++){
		if (robotID<2){
			theta_d[robotID]=X[robotID][5];
		} else {
			//approximating theta_d of quadrotors
			//by assuming equilibrium conditions (theta=eta+PI/2)
			float xq=X[robotID][0];
			float yq=X[robotID][1];
			float eta_q = atan2(yq,xq);
			theta_d[robotID]=minAngle(eta_q+PI/2);
		}	
	}
	
	//calculate control for current turtle (myID)
		
		int robotID=myID; //for compatibility with sim
		
		//get current state
		x=X[robotID][0];
		y=X[robotID][1];
		theta_i=minAngle(X[robotID][5]);
		//std::cout << theta_i << "\t";
		//std::cout << minAngle(theta_i) << "\n";
		
		//translate x,y into r,eta coordinates
		r_i = sqrt(pow(x,2)+pow(y,2));
		eta_i = atan2(y,x); // angles from -PI to PI

		//CALCULATE COMPONENTS
		
		//radial function component
		dP_r = Kp*(r0/pow(r_i,3))*(r_i-r0); 

		//Sepulchre
		Lambda=0.0;
		//with 4 robots: N=2,m=1
		
		//sum over d (d is an index of theta_d)
		
		//TODO:Uncomment when david is working
		
		for(int d=0;d<N;d++){
			//sum over m (m is a value)
			for(float m=1;m<=floor(N/2);m++){
				//by group
				if (robotID<2){ //first group
					Lambda += (1/m)*sin(m*minAngle(theta_i - theta_d[d]));
				} else { //second group of theta_d angles
					Lambda += (1/m)*sin(m*minAngle(theta_i - theta_d[d+N]));
				}
			}
		}	
		
		
		//Phase Alignment
		//quadrotors will not know of other group
		//only turtlebots follow
		switch(robotID){
			case 0:Phi=minAngle(theta_d[2]-theta_i);
			case 1:Phi=minAngle(theta_d[3]-theta_i);
			case 2:Phi=0;//minAngle(theta_d[0]-theta_i);
			case 3:Phi=0;//minAngle(theta_d[1]-theta_i);
		}
		float quadAligment = abs(minAngle(theta_d[2]-theta_d[3]));
		//Phi=Phi*(1/(0.0001+quadAligment));
		Phi=Phi*Ka;
		

//LUIS
		f = -1.0*dP_r;
		//u = w0*cos(theta_i-eta_i)+f*sin(theta_i-eta_i);

		//LUIS MODIFIED

		//u = f*cos(theta_i-eta_i)+w0*sin(theta_i-eta_i);

		//PATRICIO
		float r_i_dot = v0*cos(theta_i-eta_i);
		float eta_i_dot = (v0/r_i)*sin(theta_i-eta_i);
	
		u = w0+(Kp*(r_i-r0)/(w0*pow(r_i,2)))*eta_i_dot + r_i_dot;
		
		u += Lambda*w0;
		u += Phi;
	//CREATE MESSAGE FROM CONTROL LAW
	geometry_msgs::Twist twistMsg;
	twistMsg.linear.x=v0;//linear velocity
	twistMsg.linear.y=0.0;
	twistMsg.linear.z=0.0;
	twistMsg.angular.x=0.0;
	twistMsg.angular.y=0.0;
	twistMsg.angular.z=u;//angular velocity
    
    //COMMAND ROBOT WITH TWIST MESSAGE
   	vicon_pub.publish(twistMsg);

    ros::spinOnce();

    loop_rate.sleep();
    ++count;
  }
	delete shm;
  return 0;
}

