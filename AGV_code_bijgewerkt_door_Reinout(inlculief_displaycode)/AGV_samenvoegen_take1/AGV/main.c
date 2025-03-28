/*
 */

#include "StepperMotor.h"
#include "Ultrasoon.h"

int main(void)
{
    display1();
    ultrasoon_setup();
    while(1) {
        float afstand_links = ultrasoon_getDistance_L();
        float afstand_rechts = ultrasoon_getDistance_R();
        while((int)afstand_links == (int)afstand_rechts) {
            stopAGV();
            rijVooruit();
        } while((int)afstand_links > (int)afstand_rechts) {
            stopAGV();
            draaiLinks();
        } while((int)afstand_links < (int)afstand_rechts) {
            stopAGV();
            draaiRechts();
        }
    }
    return 0;
}
