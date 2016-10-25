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
#include <xc.h>
#include<delays.h>
#include<stdio.h>
#include <unmc_lcd_216.h>
#include <unmc_rtcc_01.h>
#include <unmc_config_01.h>
#include <unmc_inout_02.h>
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
    TRISA = 0b11110000;
    TRISB = 0;
    TRISC = 0b00000111;
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
    LED_1_Off;
    LED_2_Off;
    LED_3_Off;
    }
/*------------------------------------------------------------------------------
********************************************************************************
Funcion main
Funcion principal del programa
********************************************************************************
--------------------------------------------------------------------------------*/

on_led(char key){
    int i = 0;
    short intensity = (short)key * 2 - 1;
    
    for(i = 0; i < intensity; i++){
        LED_1_On;
        __delay_us(500);
    }
    
    for(i = intensity; i < 32; i++){
        LED_1_Off;
        __delay_us(500);
    }
}    
    
int main(void){
Setup();


while(1){
    
    on_led(read_keyboard());
    
    
       
        /*row1=1;
        row2=0;
        row3=0;
        row4=0;
        {
            if (column1==1&&row1==1){key=1;LED_1_On;__delay_us(500);LED_1_Off;__delay_ms(15);}
            if (column2==1&&row1==1){key=2;LED_2_On;__delay_ms(2);LED_2_Off;__delay_ms(14);}
            if (column3==1&&row1==1){key=3;LED_3_On;__delay_ms(4);LED_3_Off;__delay_ms(10);}
        }
        row1=0;
        row2=1;
        row3=0;
        row4=0;
        {
            if (column1==1&&row2==1){key=4;LED_1_On;__delay_ms(8);LED_1_Off;__delay_ms(8);}
            if (column2==1&&row2==1){key=5;LED_2_On;__delay_ms(16);LED_2_Off;__delay_ms(1);}
        }
    
    //__delay_ms(98);             // 98ms retardo maximo para esta funcion*/
    }
return 0;
}
