/*********************************************************************
 *
 *                Unimic 01 Version 1.1   10 September 2015
 *
 ***********************************************************************
 * FileName:        main.c
 * Dependencies:
 * Processor:       PIC18F26J50
 * Compiler:        XC8 1.34
 * Company:         Microchip Technology, Inc.
 *
 * Software License Agreement
 * ||
 * THIS SOFTWARE IS PROVIDED IN AN �AS IS� CONDITION. NO WARRANTIES,
 * WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING, BUT NOT LIMITED
 * TO, IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
 * PARTICULAR PURPOSE APPLY TO THIS SOFTWARE. THE COMPANY SHALL NOT,
 * IN ANY CIRCUMSTANCES, BE LIABLE FOR SPECIAL, INCIDENTAL OR
 * CONSEQUENTIAL DAMAGES, FOR ANY REASON WHATSOEVER.
 ***********************************************************************/
#include "head.h"
#include "leds.h"
#include "keyboard.h"



//[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[
/// Funcion Setup
///
///
//[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[

    void Setup(void)
    {
    OSCTUNEbits.INTSRC=1;       //setea el oscilador de 32768 para el RTC
    OSCTUNEbits.PLLEN=0;        //desactiva PLL
    OSCCONbits.IRCF0=1;         //selecciona el clock en 8MHz
    OSCCONbits.IRCF1=1;
    OSCCONbits.IRCF2=1;
    OSCCONbits.SCS0=0;              //oscilator INTRC
    OSCCONbits.SCS1=0;
    TRISA = 0b01010111;
    TRISB = 0b11100000;
    TRISC = 0;
    //TRISAbits.TRISA0=1;
    //TRISBbits.TRISB0=0;
    //TRISCbits.TRISC0=0;
    ANCON0=0b11111111;              // Config AN7 to AN0 Digital Ports
    //ANCON1=0b10010111;            // Config AN11 Analog Port
    ANCON1=0b11111111;              // Config AN12 to AN8 Digital Ports
    //ADCON0=0b00101101;
    //ADCON1=0b00010000;            Sin Conversor AD
    RTCCFGbits.RTCEN=1;
    RTCCFGbits.RTCWREN=1;
    T1CONbits.T1OSCEN=1;
    //Write_RTC();
    //LED_1_Off;
    //LED_2_Off;
    //LED_3_Off;
    }
/*------------------------------------------------------------------------------
********************************************************************************
Funcion main
Funcion principal del programa
********************************************************************************
--------------------------------------------------------------------------------*/    
int main(void){
    Setup();
    shutdown();
    while(1){
        /*row3 = 1;
        if(column1 ==1 || column2 ==1 ||column3 ==1 ){
        red_on;
        green_off;
        }else {
            green_on;
        red_off;
        }*/
        on_led(read_keyboard());
    }
    return 0;
}