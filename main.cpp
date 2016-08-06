#include "boost/thread.hpp"
#include "ros/ros.h"
#include "std_msgs/Int64.h"

#include <iostream>

volatile bool kill = false;

void threadf()
{
  ros::NodeHandle nh;
  ros::Publisher p(nh.advertise<std_msgs::Int64>("abc", 1));
  std_msgs::Int64 msg;

  while (1)
  {
    msg.data++;
    p.publish(msg);
    ros::Duration(0.01).sleep();
    if (kill)
    {
      std::cout << "calling shutdown()";
      ros::shutdown();
      return;
    }
  }
}

int main(int argc, char** argv)
{
  ros::init(argc, argv, "demo");
  boost::thread_group tg;

  for (int i = 0; i < 1000; i++)
  {
    tg.create_thread(threadf);
  }

  ros::Duration(5).sleep();
  kill = true;
  ros::Duration(1).sleep();
}
