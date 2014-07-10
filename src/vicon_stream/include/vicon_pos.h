/*
 * vicon_pos.h
 *
 *  Created on: Jan 20, 2011
 *      Author: nlacock
 *
 * DON'T directly output a string from a Vicon result, the << operator (for strings) that they wrote is broken.
 */

#ifndef VICON_POS_H_
#define VICON_POS_H_

#include "Client.h"
//#include "gps.h"
#include <vector>
#include <iostream>
#include <string>

#define VSLEEP 10
#define VICONIP  "192.168.0.112:801"

//using namespace ViconDataStreamSDK::CPP;
//using namespace std;



//class vicon_pos: public virtual gps {
class vicon_pos{
	//vicon client class
	ViconDataStreamSDK::CPP::Client* c;

	//names of detected subjects
	std::string * subjects;

	//positions of subject's segment and gripper

	//quaternions of subjects
	//float ** quats;

	//names of components universal to all the robots
	std::string* segment,*pos_name;

	unsigned int num_subs;

	//temporaries
	unsigned int i,l,m;
	ViconDataStreamSDK::CPP::Output_GetSegmentGlobalTranslation temp_segment;
	ViconDataStreamSDK::CPP::Output_GetMarkerGlobalTranslation temp_marker;
	ViconDataStreamSDK::CPP::Output_GetSegmentGlobalRotationEulerXYZ temp_rpy;
	ViconDataStreamSDK::CPP::Output_GetSegmentGlobalRotationQuaternion temp_quat;
	ViconDataStreamSDK::CPP::Output_GetUnlabeledMarkerGlobalTranslation unlabeled_marker;


public:
	float ** positions;

	//roll, pitch, yaw of segments
	float ** rpy;
	/* segmentname: The name of the segment that all robots have in common
	 * posname: Optional, the common name of the marker used to specify position
	 * grippername: Optional, the common name of the marker used for gripper location
	 * */
	vicon_pos();

	/*
		Puts the global coordinates of given subject in the given floats
	    You can access subjects either by name or by index (the index is the order
	    in which they were found, USUALLY the reverse of the order they are listed in
	    the Vicon Nexus 3D interface)

	    Does NOT call update 
	 */
	void get_subject_coord(int,float&,float&,float&);
	void get_subject_coord(std::string,float&,float&,float&);

	void get_subject_euler_xyz(unsigned int,float&,float&,float&);
	void get_subject_euler_xyz(std::string,float&,float&,float&);

	//void get_subject_quaternion(unsigned int,float&,float&,float&,float&);
	//void get_subject_quaternion(std::string,float&,float&,float&,float&);

	//puts the global coordinates of given subject's given marker into given floats
	void get_subject_marker(unsigned int,std::string,float&,float&,float&);
	void get_subject_marker(std::string,std::string,float&,float&,float&);

	//puts the global coordinates of the given unlabeled marker into given floats
	void get_coord_unlabeled(unsigned int,float&,float&,float&);

	//returns the index of given subject
	int find_sub(std::string subjectname);

	//gets a new frame and updates everything, should call once per cycle
	void update();
	~vicon_pos();
};

#endif /* VICON_POS_H_ */
