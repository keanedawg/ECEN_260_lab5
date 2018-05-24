#include "msp.h"


/**
 * main.c
 */
void main(void)
{
	WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;		// stop watchdog timer

	P1DIR |= BIT0;      // Set P1.0 (LED) to output direction
	                    // 1 = out, 0 = in
	P1DIR &= ~BIT1;     // Set P1.1 to input direction
	P1REN |= BIT1;      // Enables PULL register on P1.1
	                    // 1 = enable, o = disable (default)
	P1OUT |= BIT1;      // Configure Register on P1.1 as pull up
	                    // 1 = pull-up, 0 = pull-down


	// Poll button S1 on P1.1
	while (1)
	{
	    if (P1IN & BIT1)        // If P1.1 is high (S1 NOT Pushed)
	        P1OUT &= ~BIT0;     // Clear P1.0 (LED off)
	    else
	        P1OUT |= BIT0;      // else, turn the LED on

	}
}
