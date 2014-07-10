#include "ros/ros.h"
#include "std_msgs/String.h"
#include "geometry_msgs/Twist.h"
#include "std_msgs/Float64.h"
#include "vicon_pos.h"
#include "math.h"

#include "shared_memory_feedback.h"

#include <sstream>
#include <sys/time.h>
#include <stdio.h>

float x;
float y;
float z;
float ox;
float oy;
float oz;

//using namespace ViconDataStreamSDK::CPP;
using namespace std;

void exportData(FILE *fp, float timestamp,  float stats[6])
{
	int x;

	fprintf(fp, "%f,", timestamp);
	for (x = 0; x < 5; x++)
		fprintf(fp, "%f,",stats[x]);
	fprintf(fp, "%f\n", stats[5]);
} 
	
int main(int argc, char **argv)
{
	vicon_pos* vicon = new vicon_pos();
	std::string robots[] = {"quadrotor_1b","quadrotor_1b"};
	FILE *fp[2]; //array of file pointers, one for each robot.
	time_t startTime, currentTime;

	int robotNum = 2;
	int coordNum = 6;
	
	// X state of 6 elements [xpos ypox zpos ang_x ang_y ang_z]
	float X[2][6]; 

	for (int i = 0; i < 2; i++)
	{
		fp[i] = fopen(robots[i].c_str(),"w");
		fprintf(fp[i],"time(seconds), x, y, z, roll, pitch, yaw\n");
	}

  	geometry_msgs::Twist twistMsg;

  	SharedMemory *shm = new SharedMemory("ViconShared",61234, sizeof(X));
 
  	ros::init(argc, argv, "vicon_stream");
	ros::Time::init();
  	ros::Rate loop_rate(100);
  	int count = 0;

 while (ros::ok())
  {
	//get latest info from vicon
	vicon->update();
		
	for (int robotIndex=0; robotIndex < robotNum; robotIndex++) {

		//robotID=vicon->find_sub(robots[robotIndex]);

		vicon->get_subject_coord(robots[robotIndex],
		X[robotIndex][0],X[robotIndex][1],X[robotIndex][2]);
		
		vicon->get_subject_euler_xyz(robots[robotIndex],
		X[robotIndex][3],X[robotIndex][4],X[robotIndex][5]);
		
		//change to meters
		X[robotIndex][0] = X[robotIndex][0] /1000;
		X[robotIndex][1] = X[robotIndex][1] /1000;
		X[robotIndex][2] = X[robotIndex][2] /1000;
	}
	//update state to the shared memory
	shm->write((void *)X);

	//after updating, display results
	if ( count == 0)
		time(&startTime);
	time(&currentTime);

	float elapsedTime = difftime(currentTime, startTime);

	if (count % 10 == 0)
		printf("\n");

	for (int robotIndex=0; robotIndex < robotNum; robotIndex++) {
		
		x=X[robotIndex][0];
		y=X[robotIndex][1];
		z=X[robotIndex][2];
		ox = atan2(sin(X[robotIndex][3]),cos(X[robotIndex][3]));
		oy = atan2(sin(X[robotIndex][4]),cos(X[robotIndex][4]));
		oz = atan2(sin(X[robotIndex][5]),cos(X[robotIndex][5]));
		
		if (count % 10 == 0){
			printf("% 12s \t x % 1.2f y % 1.2f z %1.2f ox % 1.2f oy % 1.2f oz %1.2f  \n", robots[robotIndex].c_str(),x,y,z,ox,oy,oz);
		exportData(fp[robotIndex],elapsedTime, X[robotIndex]);
		}
	}

    ros::spinOnce();

    loop_rate.sleep();
    ++count;
  }

	delete shm;
	for (int i = 0; i < 2; i++)
		fclose(fp[i]);
  return 0;
}

