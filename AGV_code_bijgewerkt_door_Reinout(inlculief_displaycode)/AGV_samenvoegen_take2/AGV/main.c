/*
 */

#include "Display1.h"
#include "StepperMotor.h"
#include "Ultrasoon.h"

int main(void)
{
    _7segment_setup();
    ultrasoon_setup();
    initMotor();
    while(1) {
        float afstand_links = ultrasoon_getDistance_L();
        float afstand_rechts = ultrasoon_getDistance_R();
        if(afstand_links == afstand_rechts) {
            rijVooruit();
        } if(afstand_links > afstand_rechts) {
            draaiLinks();
        } if(afstand_links < afstand_rechts) {
            draaiRechts();
        }
        if(detecteerPakket())
        {
            displayAantalPakketten();
        }
    }
    return 0;
}
