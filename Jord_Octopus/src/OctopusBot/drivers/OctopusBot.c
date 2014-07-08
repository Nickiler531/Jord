/*
 * OctopusBot.c
 *
 * Created: 3/30/2013 6:38:02 PM
 *  Author: Nick
 */ 

#include "./../OctopusBot.h"
#include <asf.h>




void init_octopus(void)
{
	sysclk_init();
	ioport_init();
	leds_init();
	//bluetooth_init();
	//bluetooth_init_interrupt();
	switch_init();
	motors_init();
	pwm_ini(SERVO_0);
	pwm_ini(SERVO_1);
	pwm_ini(SERVO_2);
	pwm_ini(SERVO_3);
	pwm_update(SERVO_2,52);
	
	//usb_init();	
	
}

void move_motor_1(int dir, int vel)
{
	if(dir == FORWARD)
	{
		ioport_set_pin_level(MOTOR1_B,OFF);
		pwm_start(&pwm_mot1, vel);
	}
	else
	{
		ioport_set_pin_level(MOTOR1_B,ON);
		pwm_start(&pwm_mot1, 100-vel);
	}
	
}

void blink(void){
	ioport_set_pin_level(LED1,ON);
	ioport_set_pin_level(LED2,ON);
	delay_s(1);
	ioport_set_pin_level(LED1,OFF);
	ioport_set_pin_level(LED2,OFF);
	delay_s(1);
}

