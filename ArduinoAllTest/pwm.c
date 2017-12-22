/*
 * pwm.c
 *
 * Created: 22.12.2017 8:12:02
 *  Author: asian
 */ 

#include "pwm.h"

/*
Register => TTCR2A
=====================================================================================================
7		6		5		4		3		2		1		0
COM2A1	COM2A0	COM2B1	COM2B0					WGM21	WGM20
=====================================================================================================
Mode	WGM22	WGM21	WGM20	Timer/Counter		TOP			Update of		TOV Flag Set
								Mode of	Operation	OCR0x at	on(1)
=====================================================================================================									 								
2		0		1		0		CTC					OCRA		Immediate		MAX
=====================================================================================================

~~~~~~~~~~~~~~~~~~~~~~~~~Compare Output Mode, Phase Correct PWM Mode(~~~~~~~~~~~~~~~~
COM2B1	COM2B0	Description
=====================================================================================================
1		0		Clear OC2B on Compare Match when up-counting. Set OC2B on Compare Match
				when down-counting.
=====================================================================================================

*/

void init_PWM_timer(void){
	ASSR = 0x00;
	TCCR2A = 0b10100010;
	//clkI/O/1024 (From prescaler)
	TCCR2B = 0b00000110;
	// TC2 Counter Value Register
	TCNT2 = 0x00;
	//TC2 Output Compare Register A
	//generate a waveform output on the OC2A pin
	OCR2A = 0;
	//TC2 Output Compare Register B
	//generate a waveform output on the OC2B pin
	OCR2B = 0;
	// TC2 Interrupt Mask Register
	TIMSK2 |= 0x00;
	
	
	
}