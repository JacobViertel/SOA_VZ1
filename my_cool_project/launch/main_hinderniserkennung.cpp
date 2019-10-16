#include <ros/ros.h>

#include <dynamic_reconfigure/server.h>
#include <my_cool_project/MyParamsConfig.h>




void callback(my_cool_project::MyParamsConfig &config, uint32_t level) {
  ROS_INFO("new values: %f %f %s %s %d", 
            config.x, config.y);
}

int main(int argc, char **argv) {
  ros::init(argc, argv, "main_hinderniserkennung");

  dynamic_reconfigure::Server<my_cool_project::MyParamsConfig> server;
  dynamic_reconfigure::Server<my_cool_project::MyParamsConfig>::CallbackType f;

  f = boost::bind(&callback, _1, _2);
  server.setCallback(f);

  ros::spin(); //Spinning node
  return 0;
}
