#!/usr/bin/env python
import rospy
from std_msgs.msg import String

def potfield():
    pub = rospy.Publisher('pub_potfield', String)
    rospy.init_node('node_potfield')
    while not rospy.is_shutdown():
        str = "hello world %s" % rospy.get_time()
        rospy.loginfo(str)
        pub.publish(String(str))
        rospy.sleep(1.0)


if __name__ == '__main__':
    try:
        potfield()
    except rospy.ROSInterruptException:
        pass
