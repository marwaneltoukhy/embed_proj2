# Project 2

## Authors: 
- Marwan Abbas
- Omar Abu Gabal

## Repo link:
https://github.com/marwaneltoukhy/embed_proj2/tree/main

## Hardware Used:
- STM32
- ESP32
- dagu car

## software components:
- STM32cubMX
- keil vision v5
- arduino IDE 

## Problem Statement: 

Indoor positioning systems has been around for decades now, and it has been a hot topic in research eversince. But Indoor positioning systems has a huge overhead of collecting the data of the Received Signal Strength Indicator (RSSI) of WiFi inside the buildings, researchers have to walk through the whole building with a reader to read the RSSI, which is tedious. Our project is a proposed solution to help researchers with their mission, by collecting the RSSI of a floor automatically. Our system will have minimal human interaction, it would need the user to write a simple text file that describes the floor for the dagu to move accordingly. The text file would need to be saved on a Micro SD card, and inserted in the Micro SD Card Adapter. The user will then leave the dagu at the starting position, the dagu will then go through the whole floor stopping every 1 meter and buzz when it is done, the SD card will have a file called "wifidata.csv" that has all the WiFi points names and the respective RSSI.

## Architecture:

### Architecture of the system:

As shown in the figure bellow, there is a feedback loop between the STM32 and the ESP32 in order for the STM32 to notify the ESP32 when the Dagu is done with moving the 1 meter, and then the ESP32 notifies the STM32 that it is done collecting data and the Dagu can start moving again.

The wheel encoder is put on the Dagu wheels to calculate exactly how many times the wheel turned in order to calculate the distance that the Dagu moved to have accurate readings and localize the Dagu offline.

There's a MUX so that one Micro SD card is used for both reading the directions by the STM32 and writing the .csv file using the ESP32

The Pololu TRex DMC takes the commands from the STM32 UART to drive the motors of the Dagu

![](https://github.com/marwaneltoukhy/embed_proj2/blob/main/media/architecture.png)

### Flow of the system:
![](https://github.com/marwaneltoukhy/embed_proj2/blob/main/archi_des.png)

<!-- ### Black box architecture:
![](https://github.com/marwaneltoukhy/embed_proj2/blob/main/black_box.png)

### Architecture of STM32 with dagu:
![](https://github.com/marwaneltoukhy/embed_proj2/blob/main/proto_desing_1.PNG) -->


# Demo 1:

[Dagu moving 1 meter](https://drive.google.com/file/d/1-ZOl79PqEXByu9dAtm5cUPRgDmWicd5Q/view?usp=sharing)

[ESP32 data gathering](https://drive.google.com/file/d/1Y1yaBVXY792gIeG7-uqBGNeryCGUzogs/view?usp=sharing)

## Challenges:

- To control the dagu to stop at certain points to collect the finger prints
- Creating a feedback loob between the esp32 and stm32 to stop and start the movement of the car when we are not collecting the fingerprint.

We believe that this project would be beneficial because it will reduce the overhead of collecting the RSSI "WIFI signal strength at different location" to build the fingerprint of the building. by automating this process researchers can concentrate more on the different algorithms and techniques in which they can create to reduce the absolute mean error between the user location and the estimated location and try to create better techniques that can be robust to environment changes and can be generalized to different building at different locations. 


## Presentation Link
https://drive.google.com/file/d/1tfSCS1q_egZYdxbkJUDPdCJWKFP4syyZ/view?usp=sharing
