#include <ros/ros.h>
#include "sensor_msgs/JointState.h"

void JointStateCallback(const sensor_msgs::JointState::ConstPtr& msg){

  for (size_t i = 0; i < msg->position.size(); i++) {
        ROS_INFO("Joint %zu: %f", i, msg->position[i]);
  }
}



int main(int argc, char* argv[]){

    ros::init(argc, argv, "arm_controller_node");

    ros::NodeHandle nodeHandle;

    ros::Subscriber joint_state_subscriber = nodeHandle.subscribe("/arm/joint_states",10,JointStateCallback);

    ros::spin();
    return 0;
}


