### Project 2 proposal

## Authors: 
- Marwan Abbas
- Omar Abu Gabal

## Repo link:
https://github.com/marwaneltoukhy/embed_proj2/tree/main

## Used Materials:
- stm32
- esp32
- dagu car

## software components:
- STM32cubMX
- keil vision v5
- arduino ide 
## Problem Description: 

Our project proposal is using STM32 Nucleo board and esp32. we are building an application using those 2 microcontrollers to automate the process of collecting the finger print for indoor localization. Indoor localization interest have been on the rise lately and researchers are trying to create an app like GPS that can be used anywhere in any kind of building to estimate the user location to help him/her navigate inside a huge building or to help in the discovery of close by services. but the overhead of collecting the fingerprint manually reduce the efficiency of the system because researcher don't collect a lot of data and by that they are not certain if their technique can be generalized or not. so we are planning on building an application which will automate this process for the researchers so that they can concentrate more on the techniques they are developing rather than the collection of data.

until now The application  have only 1 starting point, and the map is being hardcoded in the micro-controller 

## Architecture:

![](https://github.com/marwaneltoukhy/embed_proj2/blob/main/proto_desing_1.PNG)



## Challenges:

- To control the dagu to stop at certain points to collect the finger prints
- Creating a feedback loob between the esp32 and stm32 to stop and start the movement of the car when we are not collecting the fingerprint.

We believe that this project would be beneficial because it will reduce the overhead of collecting the RSSI "WIFI signal strength at different location" to build the fingerprint of the building. by automating this process researchers can concentrate more on the different algorithms and techniques in which they can create to reduce the absolute mean error between the user location and the estimated location and try to create better techniques that can be robust to environment changes and can be generalized to different building at different locations. 


## Presentation Link
https://drive.google.com/file/d/1tfSCS1q_egZYdxbkJUDPdCJWKFP4syyZ/view?usp=sharing
