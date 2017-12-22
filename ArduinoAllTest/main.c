/*
 * main.h
 *
 * Created: 22.12.2017 6:13:53
 *  Author: asian
 */ 

#include "main.h"

//configurating PINS
void port_ini(void){
	PORTB = 0x00;
	DDRB = 0x00;
	DDRB |= (1 << PORTB3);
}

// test PWM
// int main(void)
// {
// 	unsigned char pwm_state=0;
// 	port_ini();
//     init_PWM_timer();
//     while (1) 
//     {	
// 		if( pwm_state == 0 ){
// 			OCR2A++;	
// 			if( OCR2A>254 ) pwm_state = 1;
// 		}
// 		if( pwm_state == 1){
// 			OCR2A--;
// 			if( OCR2A < 1 ) pwm_state = 0;
// 		}
// 		_delay_ms(3);
//     }
// }
// int main(void)
// 	{	
// 		unsigned char pwm_state=0;
// 		//pinMode(3, OUTPUT); // output pin for OCR2B
// 		//pinMode(5, OUTPUT); // output pin for OCR0B
// 		DDRB = 0x00;
// 		DDRB |= (1 << 3);
// 		DDRB |= (1 << 3);

	
	// Set up the 250KHz output
// 	TCCR2A = _BV(COM2A1) | _BV(COM2B1) | _BV(WGM21) | _BV(WGM20);
// 	TCCR2B = _BV(WGM22) | _BV(CS20);
// 	TCCR2A = 0b10100011;
// 	TCCR2B = 0b00001001;
// 	OCR2A = 63;
// 	OCR2B = 0;



	// Make the 250KHz rolling
// 	while (1) {
// 		_delay_us(5);
// 		if ( OCR2B < 63 )
// 		OCR2B += 5;
// 		else
// 		OCR2B = 0;
// 	}
//     while (1)
//     {
// 		if( pwm_state == 0 ){
// 			OCR2A++;
// 			if( OCR2A>254 ) pwm_state = 1;
// 		}
// 		else {
// 			OCR2A--;
// 			if( OCR2A < 1 ) pwm_state = 0;
// 		}
// 		_delay_ms(3);
//     }
// }

// this code sets up counter1 A output at 25% and B output at 75%
// using ICR1 as top (16bit), Fast PWM.




int main(void)
{
	DDRB |= (1 << DDB1)|(1 << DDB2);
	// PB1 and PB2 is now an output

	ICR1 = 0xFFFF;
	// set TOP to 16bit

	OCR1A = 0x3FFF;
	// set PWM for 25% duty cycle @ 16bit

	OCR1B = 0xBFFF;
	// set PWM for 75% duty cycle @ 16bit

	TCCR1A |= (1 << COM1A1)|(1 << COM1B1);
	// set none-inverting mode

	TCCR1A |= (1 << WGM11);
	TCCR1B |= (1 << WGM12)|(1 << WGM13);
	// set Fast PWM mode using ICR1 as TOP
	
	TCCR1B |= (1 << CS10);
	// START the timer with no prescaler

	

	while (1);
	{
		OCR1B-=20;
		_delay_ms(100);
	}
}