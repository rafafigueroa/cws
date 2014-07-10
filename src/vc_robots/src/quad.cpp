#include "ros/ros.h"
#include "std_msgs/String.h"
#include "geometry_msgs/Twist.h"
#include "std_msgs/Float64.h"
#include "shared_memory.h"
#include <sstream>
#include <stdlib.h>
#include <stdio.h>


const double PI= 3.141592653589793;
const double Ts=.01;
bool safe = true;
bool pos_received = false;
bool initial_done = false;

std::string robots[] = {"quadrotor_1b","quadrotor_1b"};
int robotNum = 2; //total number of robots
int coordNum = 6; //coordinates on state vector
int quadID = 0; //0 first entry in robots

// X state of 6 elements [xpos ypox zpos ang_x ang_y ang_z]
float X[2][6]; 

//pose has the following variables
float x;
float y;
float z;
float ox;
float oy;
float oz;

float dx;
float dy;
float dz;
float dox;
float doy;
float doz;

float px=0;
float py=0;
float pz=0;
float pox=0;
float poy=0;
float poz=0;

float pdx=0;
float pdy=0;
float pdz=0;
float pdox=0;
float pdoy=0;
float pdoz=0;

float x_error_abs;
float y_error_abs;
float z_error_abs;

float z_sat_count = 0;
float z_sat_max = 300;

float x_error_kill = 0.4;
float y_error_kill = 0.4;
float z_error_kill = 0.5;

// State setup
float thrust, torquex, torquey, torquez;
float  w1sq,  w2sq,  w3sq,  w4sq;
float  w1 = 0,  w2 = 0,  w3 = 0,  w4 = 0;

// Controller gains and Saturation values
float Kx = 2.8284, Ky = -2.8284, Kz = 4.4721;
float Kdx = 2.6856, Kdy = -2.6856, Kdz = 3.0455;
float Kox = 9.0393, Koy = 9.0393, Koz = 2;
float Kdox = 1.4871, Kdoy = 1.4871, Kdoz = 1.4469;
float x_limit = 0.05, y_limit = 0.05, z_limit = 0.04;

// Error definitions
float x_error, y_error, z_error, dx_error, dy_error, dz_error;
float ox_error, oy_error, oz_error, dox_error, doy_error, doz_error;

// Transformation information
float groundfactor;
const float g = 9.81, M = 0.478, L = 0.18, Rrotor = 0.1;
const float Tfactor = 6.11*pow(10,-8);
const float Dfactor = 1.5*pow(10,-9);
const float rpm2rads = 2*PI/60.0;
const float rads2rpm =60.0/(2*PI);
const float b = 5.57165*pow(10,-6); 
const float k = 1.36784*pow(10,-7);
const float omegamax = 8600*rpm2rads, omegamin = 1200*rpm2rads;

//Reference
float xref=0;
float yref=0; 
float zref=0.3; 
float dxref=0; 
float dyref=0;  
float dzref=0; 
float oxref=0;  
float oyref=0;  
float ozref=0;  
float doxref=0;  
float doyref=0;  
float dozref=0; 


using namespace std;

void uqFromXqref() {

	// Calculate errors
	x_error = xref - x;
    y_error = yref - y;
    z_error = zref - z;
    dx_error = dxref - dx;
    dy_error = dyref - dy;
    dz_error = dzref - dz;
    ox_error = oxref - ox;
    oy_error = oyref - oy;
    oz_error = ozref - oz;
    dox_error = doxref - dox;
    doy_error = doyref - doy;
    doz_error = dozref - doz;

		// Implement saturations
	if(x_error > x_limit) {
        x_error = x_limit;  
	}
    else if(x_error < -x_limit) {
        x_error = -x_limit;	
	}
    
    if(y_error > y_limit) {
        y_error = y_limit;
	}
    else if(y_error < -y_limit) {
        y_error = -y_limit;
	}
	    
    if(z_error > (z_limit*z_sat_count/z_sat_max)) {
        z_error = (z_limit*z_sat_count/z_sat_max);
	}
    else if(z_error < -(z_limit*z_sat_count/z_sat_max)) {
        z_error = -(z_limit*z_sat_count/z_sat_max);
	}
	

	// Thrust and Torque controllers
	thrust = (Kz*z_error + Kdz*dz_error + M*g)/(cos(ox)*cos(oy));
    torquex = Ky*y_error + Kdy*dy_error + Kox*ox_error + Kdox*dox_error;
    torquey = Kx*x_error + Kdx*dx_error + Koy*oy_error + Kdoy*doy_error;
    torquez = Koz*oz_error + Kdoz*doz_error;
	
	// Finds omega squared values
	groundfactor = 1;//(1 - (pow(Rrotor,2)/(16*pow(z,2)+0.0000001)));
	 w1sq = groundfactor*((thrust/(4.0*b)) - (torquey/(2*b*L)) + (torquez/(4*k)));
	 w2sq = groundfactor*((thrust/(4.0*b)) + (torquex/(2*b*L)) - (torquez/(4*k)));
	 w3sq = groundfactor*((thrust/(4.0*b)) + (torquey/(2*b*L)) + (torquez/(4*k)));
	 w4sq = groundfactor*((thrust/(4.0*b)) - (torquex/(2*b*L)) - (torquez/(4*k)));
	
	if(w1sq > 810000.0) {
		w1sq = 810000.0;
	}
	else if(w1sq < 16000.0) {
		w1sq = 16000.0;
	}
	
	if(w2sq > 810000.0) {
		w2sq = 810000.0;
	}
	else if(w2sq < 16000.0) {
		w2sq = 16000.0;
	}
	
	if(w3sq > 810000.0) {
		w3sq = 810000.0;
	}
	else if(w3sq < 16000.0) {
		w3sq = 16000.0;
	}
	
	if(w4sq > 810000.0) {
		w4sq = 810000.0;
	}
	else if(w4sq < 16000.0) {
		w4sq = 16000.0;
	}
	
	
	w1 = sqrt(w1sq);
	w2 = sqrt(w2sq);
	w3 = sqrt(w3sq);
	w4 = sqrt(w4sq);
	
	if(initial_done && (z_sat_count < z_sat_max)) {
		z_sat_count++;
	}
}

//for sending direct motor control to quadrotor



void setMotorSpeeds(FILE *fp, float speeds[4])
{
	int i;
	float rpms[4];
	unsigned char dmc[4] = {0,0,0,0}; //direct motor commands
	unsigned char swap; // Motor 1 = 1st, 2 = 3rd, 3 = 2nd, 4th = 4

	for (i = 0; i < 4; i++)
	{

		// Convert from radians per second to RPM
		// 60 Sec / Min, 2PI Radians per Revolution
		rpms[i] = (speeds[i] * 60) / (2.0 * 3.1415926); 
		
		// Now convert from RPM's to Direct Motor Commands.
		if ( rpms[i] < 1075 )
			dmc[i] = 0;
		// From sdk.h in ASCTEC 3.0 SDK: RPM = (25+(motor*175)/200)*43
		else 
			dmc[i] = (int)((((double)rpms[i]/43.0)-25.0)*(200.0/175.0)); //8600 rpm is max

		if ( dmc[i] > 150)
		{
			//printf("Waring! Motor %i Direct Motor Control commanded to be greater than 200! [D:%i, S:%f, R:%f]\n", i + 1, dmc[i],speeds[i], rpms[i] );
			dmc[i] = 150;
		}
		
	}

	swap = dmc[1];
	dmc[1] = dmc[2];
	dmc[2] = swap; //Swap values to match our model.
	fwrite(dmc, 1, 4, fp);

}


//for calculating angle differences following 
//paper assumptions
double minAngle(double angle){
	return atan2(sin(angle),cos(angle));
}

int main(int argc, char **argv)
{

	SharedMemory *shm = new SharedMemory("ViconShared",61234,sizeof(X));
	ros::init(argc, argv, "quad");
	std::cout << "Vicon Socket Initialized\n";
	
	std::cout << omegamax;
	
	ros::NodeHandle ViconNode;
	ros::Rate loop_rate(100);
	
	float omegas[4] = {0,0,0,0};
	
	//Opening zigbee comm port
	FILE *fp;
	
	fp = fopen("/dev/ttyUSB0","rw+");
	
	if (!fp)
	{
		printf("Could not open Zigbee port!\n");
		exit(-1);
	}
	
	setvbuf(fp, NULL, _IONBF,0); // No buffering
	

// ************** //
// **** LOOP **** //
// ************** //
  int count = 0;
  while (ros::ok())
  {
	//READ STATE FROM SHARED MEMORY 
	shm->read((void *)X);
	
	//MY CURRENT POSITION
	std::cout << robots[quadID] << std::endl
			<< std::setprecision(8) 
			<< " pos:\t" 
			<< X[quadID][0] << "\t"  
			<< X[quadID][1] << "\t" 
			<< X[quadID][2] << "\n ang:\t"
			<< X[quadID][3] << "\t" 
			<< X[quadID][4] << "\t" 
			<< X[quadID][5]
			<< std::endl;
	
	
		//get current state
		x=X[quadID][0];
		y=X[quadID][1];
		z=X[quadID][2];
		ox=X[quadID][3]; //check if minangle() is needed
		oy=X[quadID][4];
		oz=X[quadID][5];
		
		//get estimate of derivatives using
		//The Al-Alaoui differentiator
		dx=-(1.0/7.0)*pdx+(8.0/(7.0*Ts))*(x-px);
		dy=-(1.0/7.0)*pdy+(8.0/(7.0*Ts))*(y-py);
		dz=-(1.0/7.0)*pdz+(8.0/(7.0*Ts))*(z-pz);
		dox=-(1.0/7.0)*pdox+(8.0/(7.0*Ts))*(ox-pox);
		doy=-(1.0/7.0)*pdoy+(8.0/(7.0*Ts))*(oy-poy);
		doz=-(1.0/7.0)*pdoz+(8.0/(7.0*Ts))*(oz-poz);
		
		std::cout
		<< std::setprecision(4) 
		<< "dx: " << dx << "\t"  
		<< "dy: " << dy << "\t" 
		<< "dz: " << dz << "\n"
		<< "dox: " << dox << "\t"  
		<< "doy: " << doy << "\t" 
		<< "doz: " << doz << "\n"

		<< std::endl;

		//update values for the next update
		px=x;
		py=y;
		pz=z;
		pox=ox;
		poy=oy;
		poz=oz;
		pdx=dx;
		pdy=dy;
		pdz=dz;
		pdox=dox;
		pdoy=doy;
		pdoz=doz;

		//CONTROL LAW
		//updates all omegas (w)
		 uqFromXqref();
		 
		x_error_abs = abs(x_error);
		y_error_abs = abs(y_error);
		z_error_abs = abs(z_error);
\
		
		if(x_error_abs>x_error_kill || y_error_abs>y_error_kill || z_error_abs>z_error_kill) safe=false;
		if(x != 0 && y !=0 && z !=0 && ox != 0 && oy != 0 && oz != 0) pos_received=true;
		
		if(safe && pos_received){
			if(initial_done){
				omegas[0] = w1;
				omegas[1] = w2;
				omegas[2] = w3;
				omegas[3] = w4;
			} else {
				omegas[0] = 2600*rpm2rads;
				omegas[1] = 2600*rpm2rads;
				omegas[2] = 2600*rpm2rads;
				omegas[3] = 2600*rpm2rads;
			}
		} else {
			omegas[0] = 0;
			omegas[1] = 0;
			omegas[2] = 0;
			omegas[3] = 0;
			cout << "\n FAILSAFE!!!! \n";
		}
			
			
		 setMotorSpeeds(fp,omegas);
		 
		 //CONTROL ROBOT
		 	std::cout
			<< std::setprecision(6) 
			<< "T : " << thrust << "\t"
			<< "tx: " << torquex << "\t"
			<< "ty: " << torquey << "\t"
			<< "tz: " << torquez << "\n"
			<< "w1: " << w1*rads2rpm << "\t"  
			<< "w2: " << w2*rads2rpm << "\t" 
			<< "w3: " << w3*rads2rpm << "\t"
			<< "w4: " << w4*rads2rpm 
			<< std::endl;

    ros::spinOnce();

    loop_rate.sleep();
    ++count;
    if(count>1000) initial_done=true;
  }
	delete shm;
	omegas[0] = 0;
	omegas[1] = 0;
	omegas[2] = 0;
	omegas[3] = 0;
	setMotorSpeeds(fp, omegas);
	fclose(fp);
  return 0;
}

