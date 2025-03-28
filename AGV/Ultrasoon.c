#include "Ultrasoon.h"
#include "avr/io.h"
#include "avr/interrupt.h"

//edit naar OCB
#define ULTRASOON_L_TRIG_BIT PL4  //OC5B
#define ULTRASOON_L_TRIG_DDR DDRL
#define ULTRASOON_R_TRIG_BIT PH4  //OC4B
#define ULTRASOON_R_TRIG_DDR DDRH
#define ULTRASOON_L_ECHO_BIT PL1  //ICP5
#define ULTRASOON_L_ECHO_DDR DDRL
#define ULTRASOON_R_ECHO_BIT PL0  //ICP4
#define ULTRASOON_R_ECHO_DDR DDRL

#define PRESCALAR 64


void ultrasoon_setup(){
    ultrasoon_setup_L();
    ultrasoon_setup_R();
}


void ultrasoon_setup_L(){
    //--timer pwm pulse van min 10us periode van min 60ms--
    //pin direction
    ULTRASOON_L_TRIG_DDR |= (1<<ULTRASOON_L_TRIG_BIT);

    //wgm fast pwm
    TCCR5A |= (1<<WGM50)|(1<<WGM51);
    TCCR5B |= (1<<WGM52)|(1<<WGM53);

    //output OCR5B
    TCCR5A |= (1<<COM5B1);

    //prescaler 64
    TCCR5B |= (1<<CS50)|(1<<CS51);

    //OCRA dutycycle 60ms
    OCR5A=15000;

    //OCRA pulse 12us
    OCR5B = 3;

    //--input capture falling edge--
    //pin direction
    ULTRASOON_L_ECHO_DDR &= ~(1<<ULTRASOON_L_ECHO_BIT);

    //edge select
    TCCR5B &= ~(1<<ICES5);
}

void ultrasoon_setup_R(){
    //--timer pwm pulse van min 10us periode van min 60ms--
    //pin direction
    ULTRASOON_R_TRIG_DDR |= (1<<ULTRASOON_R_TRIG_BIT);

    //wgm fast pwm
    TCCR4A |= (1<<WGM40)|(1<<WGM41);
    TCCR4B |= (1<<WGM42)|(1<<WGM43);

    //output OCR4B
    TCCR4A |= (1<<COM4B1);

    //prescaler 64
    TCCR4B |= (1<<CS40)|(1<<CS41);

    //OCRA dutycycle 60ms
    OCR4A = 15000;

    //OCRA pulse 12us
    OCR4B = 3;


    //--input capture falling edge--
    //pin direction
    ULTRASOON_R_ECHO_DDR &= ~(1<<ULTRASOON_R_ECHO_BIT);

    //edge select
    TCCR4B &= ~(1<<ICES4);
}


float ultrasoon_getDistance_L(){
    //bereken tijd in ICR om naar us en trek de tijd tot eerste puls (TCNT = 550) ervanaf
    unsigned int icrVal = ICR5;
    unsigned int pulseTime_us = (icrVal>550)?(((icrVal-550)*PRESCALAR)/16):0;

    //reken tijd om naar afstand in cm
    return pulseTime_us/58.0;

}

float ultrasoon_getDistance_R(){
    //bereken tijd in ICR om naar us en trek de tijd tot eerste puls (TCNT = 550) ervanaf
    unsigned int icrVal = ICR5;
    unsigned int pulseTime_us = (icrVal>550)?(((icrVal-550)*PRESCALAR)/16):0;

    //reken tijd om naar afstand in cm
    return pulseTime_us/58.0;
}
