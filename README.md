### Project 2 proposal

## Authors: 
- Marwan Abbas
- Omar Abu Gabal
## Problem Description: 

Our project proposal is using Loomo, the Segway robot, the robot already comes preinstalled with an application that converts it from a Segway to a robot that can recognize people and follow them. We are planning on building an application on top of the application preinstalled, that would use all the functionality that Loomo provides. We are going to develop an application that help people navigate to a desired location, we are planning on doing that on campus, where we are going to have a docking station (starting point) for students to wake up Loomo by saying “Hey Loomo” or “Okay Loomo”, then tell them where they are planning to go, example “take me to SSE” then ride Loomo, our application will navigate the student to SSE, using only left and right turns, that means that the user has to get Loomo to walk straight. After Loomo arrives at the destination it will go back on its own to the docking station after the user gets off. 

The application will have only 1 starting point, but several ending points, each time a user needs to take Loomo on a trip, Loomo must be in the docking station (starting point). The application flow is as follows:

To get Loomo familiar with the end points, we are planning to use the application that is preinstalled and make the robot follow us from the starting point to the end point, then save this path that we would use to navigate the user. We will not enable obstacle detection when there is a user on the Segway, as we believe that it won’t be safe for the user to be riding and relying on the obstacle detection in Loomo as it is still a beta version. But the obstacle detection will be working when Loomo is going back to the docking station to avoid people walking or objects that were not in the robot’s way before. 

We are also planning on giving Loomo a kind of personality that is interactive with students, like facial expressions, asking for help if stuck in a place or giving people a funny attitude, to appeal to students.

## Architecture:

![](https://github.com/marwaneltoukhy/cooperative-scheduler/blob/main/Aspose.Words.48a9896e-7f27-4d77-ae5b-6e929b80d0f3.001.png)



## Challenges:

- Overwriting how the robot changes to a Segway, in order to use the robot’s intelligence while the device is used as a Segway
- Making sure that if we overwrite the Segway directions it is safe for the user
- Storing the paths to the end point on the memory
- Getting Loomo to go back to the docking station alone

We believe that this project would be beneficial for not only university students trying to navigate through their massive campus, like in the AUC. But we also this this project could be used in shopping malls, to navigate people to their desired location, for example the user can go to Loomo and say “Take me to Zara” and Loomo will navigate the user to Zara. Also, it is scalable, developers can build on this application to get Loomo more intelligent, for example enhance the obstacle detection, or detect where the elevators are. We are going to make the paths and directions static, so you have a limited amount of end points, but a developer willing to extend on our application might make Loomo’s end points dynamic and the user can change them easily. 


## Presentation Link
https://drive.google.com/file/d/1j4hYCJNUV6ayM_FY_umlU4pv447H8c0Y/view?usp=sharing
