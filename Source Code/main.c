#include "myled.h"
#include <stdint.h>

#include "bsp.h"


int set_rpm=0;
int tou = 2;
int dir=0;
volatile int encoder1 , encoder2;
volatile int duty_cycle1,duty_cycle2;
extern float current_rpm1 , current_rpm2;
extern int pidtime;



/* Test UART interrupt mode */
void uart_read_handler(char ch)
{
    uart_putc('[');
    uart_putc(ch);
    uart_putc(']');
}

void encoder1_callback(void){
    encoder1++;

}

void encoder2_callback(void){
    encoder2++;

}

 
// for callback

int touch_flag=1;
int result=0;
static const int T = TOUCH;

int main(void)
{
    uart_init(UART_RX, UART_TX);
    timer_init();
		touchInit(T);
		buttonInit(buttonA);
		buttonInit(buttonB);
	

	
	
  
	  motor_init(P0, P1, P2, P16);
		gpio_inten(P4, 0 ,GPIO_RISINGEDGE,encoder1_callback);
	  gpio_inten(P10, 1 ,GPIO_RISINGEDGE,encoder2_callback);
	
		set_rpm=100;
		
		duty_cycle1 = motor_1_duty(set_rpm);
		duty_cycle2 = motor_2_duty(set_rpm);
		
	
		while(1){
	
		while(1){
			if(touchGet(TOUCH)){
					while(touchGet(TOUCH)) ;
					break;
			}
				if(button_pressed(buttonB)){
					break;
				}
			
		}
			
		
			
		if(dir%2==0){
			motor_on(MOTOR_FORWARD, duty_cycle2, MOTOR_REVERSE,duty_cycle1);
		}
		else
		{
			motor_on(MOTOR_REVERSE, duty_cycle2, MOTOR_FORWARD,duty_cycle1);
		}
		
		//pid
		
		for(int i=0;i <100;i++){
		//	while(1){
			
		pid1(set_rpm);
		pid2(set_rpm);
	
		
		 
		if(dir%2==0){
			motor_on(MOTOR_FORWARD, duty_cycle2, MOTOR_REVERSE,duty_cycle1);
		}
		else
		{
			motor_on(MOTOR_REVERSE, duty_cycle2, MOTOR_FORWARD,duty_cycle1);
		}
		
		timer_delay(pidtime);
			
		if(!touchGet(T)) tou++;
		else { while(touchGet(TOUCH)); 
			tou = 1;
			dir++;}
		if(tou==1){ tou++; break;}
		
		
}
		motor_off();

		
}
    return 0;
}