/*
 * DIO_Config.h
 *
 * Created: 3/8/2020 2:07:33 PM
 *  Author: Hany Elmadany
 */ 


#ifndef DIO_CONFIG_H_
#define DIO_CONFIG_H_


/****************************************************************/
// list our peripherals into an enum
typedef enum {
	
	//write your peripheral (channels) here .........
	MOTOR_A_1,
	MOTOR_A_2,
	MOTOR_B_1,
	MOTOR_B_2,
	CS,
	ULTRASONIC_TRIGGER_PIN,
	ULTRASONIC_ECHO_PIN,
	
	number_of_channels
	
}channel_id;
/****************************************************************/




#endif /* DIO_CONFIG_H_ */