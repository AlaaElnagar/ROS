![Ros picture](https://raw.githubusercontent.com/AlaaElnagar/ROS/master/pic/ROSPic.jpg)
# Introduction
In this repository i will share with you all of my ROS projects and also the the important tips and tricks concerned with Gazebo and ROS
# Task 1:
Lets start with gazebo first project :
- <img src="https://raw.githubusercontent.com/AlaaElnagar/ROS/master/RosModel.jpg" alt="" data-canonical-src="https://gyazo.com/eb5c5741b6a9a16c692170a41a49c858.png" width="200" height="200" />
⋅⋅*the project based on making the folloiwng:-                                                                                                                        
- [x]   Finish my changesMaking gazebo world
- [x]  making two robots 
- [x]  fetching some models from gazebo online liberary 
- [x]  making C++ code to print entery message when we start gazebo

# Task 2:

.Project2                          # Go Chase It Project
    ├── my_robot                       # my_robot package                   
    │   ├── launch                     # launch folder for launch files   
    │   │   ├── robot_description.launch
    │   │   ├── world.launch
    │   ├── meshes                     # meshes folder for sensors
    │   │   ├── hokuyo.dae
    │   ├── urdf                       # urdf folder for xarco files
    │   │   ├── my_robot.gazebo
    │   │   ├── my_robot.xacro
    │   ├── world                      # world folder for world files
    │   │   ├── <yourworld>.world
    │   ├── CMakeLists.txt             # compiler instructions
    │   ├── package.xml                # package info
    ├── ball_chaser                    # ball_chaser package                   
    │   ├── launch                     # launch folder for launch files   
    │   │   ├── ball_chaser.launch
    │   ├── src                        # source folder for C++ scripts
    │   │   ├── drive_bot.cpp
    │   │   ├── process_images.cpp
    │   ├── srv                        # service folder for ROS services
    │   │   ├── DriveToTarget.srv
    │   ├── CMakeLists.txt             # compiler instructions
    │   ├── package.xml                # package info                  
    └──                              
