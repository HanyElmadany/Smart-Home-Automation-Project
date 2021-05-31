# Smart-Home-Automation-Project

Components:
1-	2X Atmega32 Microcontroller.
2-	HC-06 Bluetooth Module.
3-	LM016L LCD.
4-	2X DC Motors.
5-	L298 Motor Driver Module.
6-	2X LED.

Design:
This program designed to control home automation, we have 2 actuators (2 LEDs) and 2 motors control window curtains of 2 pieces 
We will control it by Bluetooth module, the program designed to take one of 7 commends from the Bluetooth module using USART protocol, each commend must do a specific task, the receiver ECU will receive the commend from Bluetooth module then display the corresponding action on the LCD, then transmit this commend to the transmitter ECU using SPI protocol , Transmitter ECU will take an action depend on the commend it received.
This program provide protection for the motors, you cannot send open commend and then send close commend, in this case close commend will stop the motors then you need to send that commend again to start closing the curtains.
I was planning to use limit switches with motors, I tried to make it by external interrupt but I faced some problems that I couldn’t solve, so I made it manual some how, when you send opening curtains commend you need to send the close commend to stop the motors.
