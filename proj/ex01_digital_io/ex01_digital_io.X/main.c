/*
 * File:   main.c
 * Author: sasha
 *
 * Created on July 4, 2021, 10:19 PM
 */

#include "system.h"
//#include "xc.h"

#define TICKS (65535)

int main(void)
{
    unsigned int i;

    /* OSCILLATOR DIVIDER CLKDIV[10-8] or CLKDIV.RCDIV[2-0] :
     * bit 14-12 DOZE[2:0]: CPU and Peripheral Clock Ratio Select bits
     *     111 = 1:128
     *     110 = 1:64
     *     101 = 1:32
     *     100 = 1:16
     *     011 = 1:8
     *     010 = 1:4
     *     001 = 1:2
     *     000 = 1:1    
     */
    CLKDIVbits.RCDIV = 0;

    
    /* Clock Control Logic OSCCON[10-8] or OSCON.NOSC0[2:0] :
     * bit 10-8 NOSC[2:0]: New Oscillator Selection bits(1)
     *      111 = 8 MHz Fast RC Oscillator with Postscaler (FRCDIV)
     *      110 = 500 kHz Low-Power Fast RC Oscillator (FRC) with Postscaler (LPFRCDIV)
     *      101 = Low-Power RC Oscillator (LPRC)
     *      100 = Secondary Oscillator (SOSC)
     *      011 = Primary Oscillator with PLL module (XTPLL, HSPLL, ECPLL)
     *      010 = Primary Oscillator (XT, HS, EC)
     *      001 = 8 MHz FRC Oscillator with Postscaler and PLL module (FRCPLL)
     *      000 = 8 MHz FRC Oscillator (FRC) 
     */
    OSCCONbits.NOSC0 = 1; // 0b111
    /*
     * bit 7 CLKLOCK: Clock Selection Lock Enable bit
     *      If FSCM is Enabled (FCKSM1 = 1):
     *      1 = Clock and PLL selections are locked
     *      0 = Clock and PLL selections are not locked and may be modified by setting the OSWEN bit
     *      If FSCM is Disabled (FCKSM1 = 0):
     *      Clock and PLL selections are never locked and may be modified by setting the OSWEN bit.
     *
     * bit 5 LOCK: PLL Lock Status bit(2)
     *      1 = PLL module is in lock or PLL module start-up timer is satisfied
     *      0 = PLL module is out of lock, PLL start-up timer is running or PLL is disabled
     * 
     * bit 3 CF: Clock Fail Detect bit
     *      1 = FSCM has detected a clock failure
     *      0 = No clock failure has been detected
     * 
     * bit 2 SOSCDRV: Secondary Oscillator Drive Strength bit(3)
     *      1 = High-power SOSC circuit is selected
     *      0 = Low/high-power select is done via the SOSCSRC Configuration bit
     * 
     * bit 1 SOSCEN: 32 kHz Secondary Oscillator (SOSC) Enable bit
     *      1 = Enables the Secondary Oscillator
     *      0 = Disables the Secondary Oscillator
     * 
     * bit 0 OSWEN: Oscillator Switch Enable bit
     *      1 = Initiates an oscillator switch to
     *      0 = Oscillator switch is complete
     */
    
    /* CPU/CLKO Post-Scaler CLKDIV[14-12] or CLKDIV.DOZE :
     * bit 14-12 DOZE[2:0]: CPU and Peripheral Clock Ratio Select bits
     *     111 = 1:128
     *     110 = 1:64
     *     101 = 1:32
     *     100 = 1:16
     *     011 = 1:8
     *     010 = 1:4
     *     001 = 1:2
     *     000 = 1:1
     * bit 11 DOZEN: Doze Enable bit(1)
     *     1 = DOZE[2:0] bits specify the CPU and peripheral   
     * 
     * Description: Setting DOZE field slows down the CPU clock by the selected value.  
     */
    CLKDIVbits.DOZEN = 1;
    CLKDIVbits.DOZE  = 3; // slows down
    
    /* REFO Post-Scaler
     * 
     *  */
    //REFOCONbits.
    
    
    /* Set up output pin for LED
     *  TRIS = 1: INPUT
     *  TRIS = 0: OUTPUT
     */
    TRISAbits.TRISA0 = 0;
    
    /* Configure pin 26 as a digital INPUT*/
    ANSBbits.ANSB15   = 0; // Digital input buffer is active (use as digital input)
    TRISBbits.TRISB15 = 1; // configure pin 26 as INPUT 

    while(1)
    {

        // (insert your application code here)



        // To make the LED blink visibly, we have to wait a while between toggling

        if (PORTBbits.RB15 == 1){
            // the LED pin.
            for(i = 0; i < TICKS; ) i++;
            for(i = 0; i < TICKS; ) i++;
        

            // Toggle the LED output pin to alternate between the LED being on and off
            LATAbits.LATA0 ^= 1;
        } 

    }
}
