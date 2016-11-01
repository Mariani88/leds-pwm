#include "leds.h"

#include <unmc_lcd_216.h>
#include <unmc_inout_02.h>
#include <delays.h>
#include <xc.h>

#include <unmc_config_01.h>
#include <unmc_inout_02.h>


void select_color(int value){
    if(value == 1 || value == 4 || value ==7){
        red_on;
    }
    
    if(value == 2 || value == 5 || value ==8){
        green_on;
    }
    
    if(value == 3 || value == 6 || value ==9){
        blue_on;
    }
}


void shutdown (){
    blue_off;
    green_off;
    red_off;
}


void on(int value ,short intensity){
    intensity = (intensity + 1) * 10;
    int i;
    
    for(i = 0; i < intensity; i++){
        select_color(value);
        __delay_us(500);
    }
    
    for(i = intensity; i < 32; i++){
        shutdown();
        __delay_us(500);
    }
}


void on_led(char pressed_key){
    float row_detector = 3.5;
    int value = (int)pressed_key;
    short intensity = value / row_detector;
    on(value, intensity);
    //clear_keyboard();
}