#include <ros/ros.h>
#include <iostream>
#include <string>
#include <ddynamic_reconfigure/ddynamic_reconfigure.h>


int main(int argc, char** argv) {
    ros::init(argc, argv, "ddynamic_example_node");
    ros::NodeHandle nhp("~");

    int i_param = 0;
    double d_param = 0.0;
    std::map<std::string, std::string> enum_map = {{"Key 1", "Value 1"}, {"Key 2", "Value 2"}};
    std::string enum_value = enum_map["Key 1"];

    std::shared_ptr<ddynamic_reconfigure::DDynamicReconfigure> ddr = std::make_shared<ddynamic_reconfigure::DDynamicReconfigure>(nhp);
    ddr->registerVariable<int>("int_param", &i_param, "An integer parameter", 0, 100);
    ddr->registerVariable<double>("double_param", &d_param, "A double parameter", 0.0, 10.0);
    
    ddr->registerEnumVariable<std::string>("string_enum", &enum_value,"param description", enum_map);
    
    ddr->publishServicesTopics();
    
    ros::Rate loop_rate(10);

    while (ros::ok()) {
        ros::spinOnce();
        
        ROS_INFO_STREAM("Current int_param: " << i_param);
        ROS_INFO_STREAM("Current double_param: " << d_param);
        ROS_INFO_STREAM("Current enum_param: " << enum_value);
        std::cout << std::endl << std::endl;
        
        loop_rate.sleep();
    }

    return 0;
}

