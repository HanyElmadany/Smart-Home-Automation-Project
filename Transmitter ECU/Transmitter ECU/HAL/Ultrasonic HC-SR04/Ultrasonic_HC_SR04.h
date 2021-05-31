/*
 * Ultrasonic_HC_SR04.h
 *
 * Created: 3/13/2020 9:51:18 AM
 *  Author: Hany Elmadany
 */ 


#ifndef ULTRASONIC_HC_SR04_H_
#define ULTRASONIC_HC_SR04_H_

#define ULTRASONIC_ECHO_PIN 





void Ultrasonic_Init(void);
void Ultrasonic_send_trigger(void);
void Ultrasonic_Get_Distance(uint16* ptr_distance);


#endif /* ULTRASONIC HC-SR04_H_ */