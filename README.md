# Project 2

## Authors: 
- Marwan Abbas        [Github Profile](https://github.com/marwaneltoukhy)
- Omar Abu Gabal

## Repo link:
https://github.com/marwaneltoukhy/embed_proj2/tree/main

## Hardware Used:
- STM32
- ESP32
- dagu car
- Wheel Encoder
- Micro SD Card Module
- Pololu TReX DMC
- SN74HC00N chip

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

### Software Architecture:

This is the flow of our software, we did not need to use the FREERTOS as we didn't find the need for it as we are communicating two devices together and there is no priorities in taks.

![](https://github.com/marwaneltoukhy/embed_proj2/blob/main/archi_des.png)

<!-- ### Black box architecture:
![](https://github.com/marwaneltoukhy/embed_proj2/blob/main/black_box.png)

### Architecture of STM32 with dagu:
![](https://github.com/marwaneltoukhy/embed_proj2/blob/main/proto_desing_1.PNG) -->

## Hardware:

### ESP32

The ESP32 is used because the STM32 does not have a WiFi module, so we used the ESP32 in order to collect the required data. 

The WiFi library was used to get the SSID and the RSSI of the WiFi points visible to the ESP32.

The SD and SPI libraries were used to write the .csv file on the SD card.

### Micro SD Card Reader Module

- This module was used to communicate with the Micro SD card through SPI.
- The module is used to read and write files through a FATFS file system, it can interface with a circuit board with 5V or 3.3V (used the 5V in this project)
- The communication interface is typical SPI interface.
- There are six pins as shown in the diagram below. GND, VCC, MISO, MOSI, SCK, CS.
- Voltage regulator for 4.5V ~ 5.5V down to 3.3V
- MicroSD card connector, self bomb deck, easy card insertion.
- Supported Card Types:
  - Micro SD Card (<=2G)
  - Micro SDHC Card (<=32G) (USED IN THIS PROJECT)
- Issues faced:
  - When interfaced with STM32 an old driver had to be installed
  - Formatting the MicroSD card to support FATFS
  - Doesn't support MicroSD cards with memory size greater than 32GB

![](https://github.com/marwaneltoukhy/embed_proj2/blob/main/media/sd.png)

[Datasheet for reference](http://datalogger.pbworks.com/w/file/fetch/89507207/Datalogger%20-%20SD%20Memory%20Reader%20Datasheet.pdf)
[Source of the picture](https://lastminuteengineers.com/arduino-micro-sd-card-module-tutorial/)

### Multiplexer
Due to the lack of components we had to make our own multiplexer using NAND gates.

Used 4 SN74HC00N chip to construct the MUX
![](https://github.com/marwaneltoukhy/embed_proj2/blob/main/media/nand.png)

Architecure of one MUX
![](https://github.com/marwaneltoukhy/embed_proj2/blob/main/media/mux.png)

Architecure of the MUX in our system
![](https://github.com/marwaneltoukhy/embed_proj2/blob/main/media/mux_archi.png)

### Wheel Encoder

OMAR


# Demo 1:

[Dagu moving 1 meter](https://drive.google.com/file/d/1-ZOl79PqEXByu9dAtm5cUPRgDmWicd5Q/view?usp=sharing)

[ESP32 data gathering](https://drive.google.com/file/d/1Y1yaBVXY792gIeG7-uqBGNeryCGUzogs/view?usp=sharing)

## Challenges:

- Our main challenge was to insert the wheel encoder in the dagu, as the dagu wheels are connected directly to the DC motor
  1. The first solution was to change the DC motors in the dagu and use a DC motor that has a wheen encoder embedded in it
  2. The second solution was to modify the already existing wheels to put an encoder in it, which is the solution that we went with. After some research and help from Mechanical engineers we found a way to put the wheel encoder on the already existing wheels
- The SD card interface with the STM was not working as we were trying to make it work with the wrong drivers
- We needed to construct a MUX so that both ESP32 and STM32 read and write on the same MicroSD

## Future work
For future engineers, we might need a more autonomous way to control the Dagu, maybe using cameras to detect doors and go through them. Also, another feature that would be extremely useful is obsticle detection, as this project would stop working if the user is not extremely precise with their commands.

We believe that this project would be beneficial because it will reduce the overhead of collecting the RSSI "WIFI signal strength at different location" to build the fingerprint of the building. by automating this process researchers can concentrate more on the different algorithms and techniques in which they can create to reduce the absolute mean error between the user location and the estimated location and try to create better techniques that can be robust to environment changes and can be generalized to different building at different locations. 


## Presentation Link
https://drive.google.com/file/d/1tfSCS1q_egZYdxbkJUDPdCJWKFP4syyZ/view?usp=sharing
