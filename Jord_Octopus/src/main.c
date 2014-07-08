/**
 * \file
 *
 * \brief Empty user application template
 *
 */

/*
 * Include header files for all drivers that have been imported from
 * Atmel Software Framework (ASF).
 */
#include "./OctopusBot/OctopusBot.h"
#include <asf.h>

ISR(USARTD0_RXC_vect)
{
	int data = usart_getchar(BLUETOOTH);
	switch(data)
	{
		case '1':
			ioport_toggle_pin_level(LED1);
		break;
		case '2':
			ioport_toggle_pin_level(LED2);
		break;
		case '3':
			ioport_toggle_pin_level(LED3);
		break;
		case '4':
			ioport_toggle_pin_level(LED4);
		break;
		case '5':
			ioport_toggle_pin_level(LED5);
		break;
		case '6':
			ioport_toggle_pin_level(LED6);
		break;
	}
}

#define INIT_MAX 100
void initial_animation(void)
{
	volatile int i;
	for(i = 50;i<INIT_MAX;i+=15)
	{
		ioport_set_pin_level(LED1,1);
		delay_ms(i);
		ioport_set_pin_level(LED2,1);
		delay_ms(i);
		ioport_set_pin_level(LED3,1);
		delay_ms(i);
		ioport_set_pin_level(LED4,1);
		delay_ms(i);
		ioport_set_pin_level(LED5,1);
		delay_ms(i);
		ioport_set_pin_level(LED6,1);
		delay_ms(i);
		
		ioport_set_pin_level(LED1,0);
		delay_ms(i);
		ioport_set_pin_level(LED2,0);
		delay_ms(i);
		ioport_set_pin_level(LED3,0);
		delay_ms(i);
		ioport_set_pin_level(LED4,0);
		delay_ms(i);
		ioport_set_pin_level(LED5,0);
		delay_ms(i);
		ioport_set_pin_level(LED6,0);
		delay_ms(i);
	}
}

#define SENS1 IO_1
#define SENS2 IO_2
#define SENS3 IO_7
#define SENS4 IO_8 
#define SENS5 IO_3
#define SENS6 IO_4
#define SENS_IR IO_5
#define SENS_METAL IO_6

// void servo_test(void)
// {
// 	int pos;
// 	scanf("%3i",&pos);
// 	pwm_update(SERVO_2,pos);
// }
void rotate_left(void);
void servo_test(void)
{
	int pos;
	scanf("%1i",&pos);
	
	if(pos==9)
	{
		rotate_left();
	}
	else if(pos==1)
	{
		pwm_update(SERVO_0,75);
		pwm_update(SERVO_1,45);
	}
	else if(pos==2)
	{
		pwm_update(SERVO_2,110);
	}
	else if(pos==3)
	{
		pwm_update(SERVO_3,35);
	}
	else if(pos==3)
	{
		pwm_update(SERVO_3,35);
	}
	else if(pos==4)
	{
		pwm_update(SERVO_3,105);
	}
	else
	{
		pwm_update(SERVO_0,34);
		pwm_update(SERVO_1,100);
		pwm_update(SERVO_2,48);
	}
	
	
}

void remote_controlled(void)
{
	/*¨Parts:
	-Leds (L)
	-Motors (M)
	-servos (S)
	-complete movement (R) */
	char part;
	int opt1=0;
	int opt2=0;
	int opt3=0;
	//scanf("%1c%1i%3i%3i",&part,&opt1,&opt2,&opt3);
	scanf("%1c%1i%3i",&part,&opt1,&opt2);
	switch (part)
	{
		/* Motors M+#of motor + speed (99 to -99) */
		case 'M':
			switch (opt1)
			{
				case 1:
				motor1(opt2);
				break;
				case 2:
				motor2(opt2);
				break;
				case 3:
				motor3(opt2);
				break;
				case 4:
				motor4(opt2);
				break;
			}
		break;
		
		case 'R':
			move(opt2,opt3);
		break;
		
		
		case 'S':
			switch(opt1)
			{
				case 1: 
					pwm_update(SERVO_0,opt2);
				break;
				case 2:
					pwm_update(SERVO_1,opt2);
				break;
				case 3:
					pwm_update(SERVO_2,opt2);
				break;
				case 4:
					pwm_update(SERVO_3,opt2);
				break;
				
			}
		break;
		
		
		/* Leds, L + # of led + option
			L1000 turn off led 1
			L1001 turn on led 1
			L1002 toggle led 1 */
		case 'L':
			switch (opt1)
			{
			case 1:
				switch(opt2)
				{
					case 0:
					ioport_set_pin_level(LED1,0);
					break;
				
					case 1:
					ioport_set_pin_level(LED1,1);
					break;
				
					case 2:
					ioport_toggle_pin_level(LED1);
					break;
				}
			break;
				
			case 2:
				switch(opt2)
				{
					case 0:
					ioport_set_pin_level(LED2,0);
					break;
					
					case 1:
					ioport_set_pin_level(LED2,1);
					break;
					
					case 2:
					ioport_toggle_pin_level(LED2);
					break;
				}
			break;
			
			case 3:
			switch(opt2)
			{
				case 0:
				ioport_set_pin_level(LED3,0);
				break;
				
				case 1:
				ioport_set_pin_level(LED3,1);
				break;
				
				case 2:
				ioport_toggle_pin_level(LED3);
				break;
			}
			break;
			
			case 4:
			switch(opt2)
			{
				case 0:
				ioport_set_pin_level(LED4,0);
				break;
				
				case 1:
				ioport_set_pin_level(LED4,1);
				break;
				
				case 2:
				ioport_toggle_pin_level(LED4);
				break;
			}
			break;
			
			case 5:
			switch(opt2)
			{
				case 0:
				ioport_set_pin_level(LED5,0);
				break;
							
				case 1:
				ioport_set_pin_level(LED5,1);
				break;
							
				case 2:
				ioport_toggle_pin_level(LED5);
				break;
			}
			break;
			
			case 6:
			switch(opt2)
			{
				case 0:
				ioport_set_pin_level(LED6,0);
				break;
				
				case 1:
				ioport_set_pin_level(LED6,1);
				break;
				
				case 2:
				ioport_toggle_pin_level(LED6);
				break;
			}
		break;
		}

// 		case 'M':
// 		break;
// 		
// 		case 'S':
// 		break;
// 		
// 		case 'R':
// 		break;
	}
}

// FAST
// #define MOVE_CENTER move(100,100)
// #define MOVE_LEFT1 move(100,90)
// #define MOVE_LEFT2 move(100,80)
// #define MOVE_LEFT3 move(100,55)
// #define MOVE_RIGTH1 move(90,100)
// #define MOVE_RIGTH2 move(80,100)
// #define MOVE_RIGHT3 move(55,100)
// #define ROT_LEFT move(100,-99)
// #define ROT_RIGHT move(-99, 100)
//SLOW
#define MOVE_CENTER move(60,60)
#define MOVE_LEFT1 move(60,50)
#define MOVE_LEFT2 move(60,40)
#define MOVE_LEFT3 move(60,30)
#define MOVE_RIGTH1 move(50,60)
#define MOVE_RIGTH2 move(40,60)
#define MOVE_RIGHT3 move(30,60)
#define ROT_LEFT move(60,-60)
#define ROT_RIGHT move(-60, 60)

void rotate_left(void)
{
	int sens_LL=ioport_get_pin_level(SENS1);
	int sens_RR=ioport_get_pin_level(SENS2);
	int sens_MR=ioport_get_pin_level(SENS3);
	int sens_ML=ioport_get_pin_level(SENS4);
	int sens_LLL=ioport_get_pin_level(SENS5);
	int sens_RRR=ioport_get_pin_level(SENS6);
	
	while(ioport_get_pin_level(SENS5) == 1 || ioport_get_pin_level(SENS6) == 1);
	ROT_LEFT;
	delay_ms(800);
	while(ioport_get_pin_level(SENS3) == 0 && ioport_get_pin_level(SENS4) == 0);
	
	//move(80,60);
	move(0,0);
	delay_ms(1000);
}

void rotate_rigth(void)
{
	int sens_LL=ioport_get_pin_level(SENS1);
	int sens_RR=ioport_get_pin_level(SENS2);
	int sens_MR=ioport_get_pin_level(SENS3);
	int sens_ML=ioport_get_pin_level(SENS4);
	int sens_LLL=ioport_get_pin_level(SENS5);
	int sens_RRR=ioport_get_pin_level(SENS6);
	
	while(ioport_get_pin_level(SENS5) == 1 || ioport_get_pin_level(SENS6) == 1 );
	ROT_RIGHT;
	delay_ms(800);
	while(ioport_get_pin_level(SENS1) == 0 && ioport_get_pin_level(SENS4) == 0 && ioport_get_pin_level(SENS3));
	
	//move(60,80);
	move(0,0);
	delay_ms(1000);
}

void show_sens(void)
{
	int sens_LL=ioport_get_pin_level(SENS1);
	int sens_RR=ioport_get_pin_level(SENS2);
	int sens_MR=ioport_get_pin_level(SENS3);
	int sens_ML=ioport_get_pin_level(SENS4);
	int sens_LLL=ioport_get_pin_level(SENS5);
	int sens_RRR=ioport_get_pin_level(SENS6);
	ioport_set_pin_level(LED5,sens_RRR);
	ioport_set_pin_level(LED6,sens_RR);
	ioport_set_pin_level(LED1,sens_MR);
	ioport_set_pin_level(LED2,sens_ML);
	ioport_set_pin_level(LED3,sens_LL);
	ioport_set_pin_level(LED4,sens_LLL);
}


void claw_up(void)
{
	pwm_update(SERVO_2,115);
}
void claw_down(void)
{
	pwm_update(SERVO_2,52);
}
void claw_pick(void)
{
	pwm_update(SERVO_2,47);
}
void hands_close(void)
{
	pwm_update(SERVO_0,80);
	pwm_update(SERVO_1,45);
}
void hands_open(void)
{
	pwm_update(SERVO_0,34);
	pwm_update(SERVO_1,100);
}
void hands_stand(void)
{
	pwm_update(SERVO_0,65);
	pwm_update(SERVO_1,55);
}

void class_plastic(void)
{
	pwm_update(SERVO_3,35);
}
void class_metal(void)
{
	pwm_update(SERVO_3,105);
}


void test_ir_metal(void)
{
	
	ioport_set_pin_level(LED5,ioport_get_pin_level(SENS_IR));
	ioport_set_pin_level(LED4,ioport_get_pin_level(SENS_IR));
	ioport_set_pin_level(LED6,ioport_get_pin_level(SENS_METAL));
}

int move_adelante(void)
{
	while(ioport_get_pin_level(SENS5) == 1 || ioport_get_pin_level(SENS6) == 1);
}

enum{
	DERECHA,
	IZQUIERDA,
	ADELANTE,
	RECOGER_DERECHA,
	RECOGER_IZQUIERDA,
	RECOGER_ADELANTE
};

void pick(void)
{
	class_plastic();
	move(50,50);
	while (ioport_get_pin_level(SENS_IR) == 0);
	move(0,0);
	claw_pick();
	hands_close();
	int aux=0;
	for(int i=0;i<1000;i++)
	{
		if (ioport_get_pin_level(SENS_METAL)==1)
		{
			class_metal();
		}
		delay_ms(1);
	}
	delay_ms(1000);
	hands_stand();
	delay_ms(500);
	hands_open();
	delay_ms(500);
	claw_up();
	delay_ms(1500);
	claw_down();
	delay_s(5);
	

}

void follow(int * cont, int * inst,int * schmit)
{
	int sens_LL=ioport_get_pin_level(SENS1);
	int sens_RR=ioport_get_pin_level(SENS2);
	int sens_MR=ioport_get_pin_level(SENS3);
	int sens_ML=ioport_get_pin_level(SENS4);
	int sens_LLL=ioport_get_pin_level(SENS5);
	int sens_RRR=ioport_get_pin_level(SENS6);
	ioport_set_pin_level(LED5,sens_RRR);
	ioport_set_pin_level(LED6,sens_RR);
	ioport_set_pin_level(LED1,sens_MR);
	ioport_set_pin_level(LED2,sens_ML);
	ioport_set_pin_level(LED3,sens_LL);
	ioport_set_pin_level(LED4,sens_LLL);
	if(sens_MR==1 && sens_ML==1)
	{
		MOVE_CENTER;
	}
	else if(sens_ML == 1 && sens_LL == 1)
	{
		MOVE_LEFT1;
	}
	else if(sens_MR == 1 && sens_RR == 1)
	{
		MOVE_RIGTH1;
	}
	
	else if(sens_ML == 1)
	{
		MOVE_LEFT2;
	}
	else if(sens_MR == 1)
	{
		MOVE_RIGTH2;
	}
	else if(sens_LL == 1)
	{
		MOVE_LEFT3;
	}
	else if(sens_RR == 1)
	{
		MOVE_RIGHT3;
	}
	
	if (*schmit>100)
	{
		if( (sens_LLL==1 || sens_RRR==1 ) )
		{
			*schmit=0;
			switch (inst[*cont])
				{
				 			case ADELANTE:
				 			move_adelante();
				 			break;
				 			case DERECHA:
				 				rotate_rigth();
				 			break;
				 			case IZQUIERDA:
				 				rotate_left();
				 			break;
				 		}
				 		*cont+=1;
		}
	}
	
	delay_ms(10);
	*schmit+=1;
}



int main (void)
{
	init_octopus();
	
	ioport_set_pin_dir(SENS1,IOPORT_DIR_INPUT);
	ioport_set_pin_dir(SENS2,IOPORT_DIR_INPUT);
	ioport_set_pin_dir(SENS3,IOPORT_DIR_INPUT);
	ioport_set_pin_dir(SENS4,IOPORT_DIR_INPUT);
	ioport_set_pin_dir(SENS5,IOPORT_DIR_INPUT);
	ioport_set_pin_dir(SENS6,IOPORT_DIR_INPUT);
	ioport_set_pin_dir(SENS_IR,IOPORT_DIR_INPUT);
	ioport_set_pin_dir(SENS_METAL,IOPORT_DIR_INPUT);
	
	int instrucciones[10]={ADELANTE,ADELANTE,ADELANTE,DERECHA,ADELANTE,DERECHA,DERECHA,DERECHA,DERECHA,DERECHA};
	//int instrucciones[10]={ADELANTE,ADELANTE,IZQUIERDA,ADELANTE};
	int contador=0;
	int schmit=0;
 	initial_animation();
	 initial_animation();
	 initial_animation();
	for(;;)
	{
		follow(&contador,&instrucciones,&schmit);
	}
}

