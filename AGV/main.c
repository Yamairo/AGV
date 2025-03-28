/*
 */

#include "StepperMotor.h"
#include "Ultrasoon.h"

int main(void)
{
    ultrasoon_setup();
    while(1) {
        float afstand_links = ultrasoon_getDistance_L();
        float afstand_rechts = ultrasoon_getDistance_R();
        if((int)afstand_links == (int)afstand_rechts) {
            rijVooruit();
        } if((int)afstand_links > (int)afstand_rechts) {
            draaiLinks();
        } if((int)afstand_links < (int)afstand_rechts) {
            draaiRechts();
        }
    }
    return 0;
}
