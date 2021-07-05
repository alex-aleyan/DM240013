/*
 * File:   main.c
 * Author: sasha
 *
 * Created on July 4, 2021, 10:19 PM
 */

#include "system.h"
//#include "xc.h"

int main(void)
{
    unsigned int i;
    
    // Set up output pin for LED
    TRISAbits.TRISA0 = 0;

    while(1)
    {

        // (insert your application code here)



        // To make the LED blink visibly, we have to wait a while between toggling

        // the LED pin.
        for(i = 0; i < 65535; i++)
        {
            Nop();
            Nop();
            Nop();
            Nop();
        }
        

        // Toggle the LED output pin to alternate between the LED being on and off
        LATAbits.LATA0 ^= 1;
    }
}
