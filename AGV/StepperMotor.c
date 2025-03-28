#include "StepperMotor.h"

void rijVooruit(void) {
    MOTORREGISTER &= ~(1 << ACHTERUIT_PIN1);
    MOTORREGISTER2 &= ~(1 << ACHTERUIT_PIN2);

    MOTORREGISTER |= (1 << VOORUIT_PIN1) | (1 << VOORUIT_PIN2);
    MOTORREGISTER |= (1 << MICROSTEP_1) | (1 << MICROSTEP_2);
}

void rijAchteruit(void) {
    MOTORREGISTER &= ~(1 << VOORUIT_PIN1);
    MOTORREGISTER2 &= ~(1 << VOORUIT_PIN2);

    MOTORREGISTER |= (1 << ACHTERUIT_PIN1) | (1 << MICROSTEP_1);
    MOTORREGISTER2 |= (1 << ACHTERUIT_PIN2) | (1 << MICROSTEP_2);
}

void draaiLinks(void) {
    MOTORREGISTER &= ~(1 << VOORUIT_PIN1); // Stop rechterkant
    MOTORREGISTER |= (1 << VOORUIT_PIN2);  // Beweeg linkerkant vooruit
    MOTORREGISTER |= (1 << MICROSTEP_2);
}

void draaiRechts(void) {
    MOTORREGISTER &= ~(1 << VOORUIT_PIN2); // Stop linkerkant
    MOTORREGISTER |= (1 << VOORUIT_PIN1);  // Beweeg rechterkant vooruit
    MOTORREGISTER |= (1 << MICROSTEP_1);
}

void stopAGV() {
    MOTORREGISTER &= ~(1 << VOORUIT_PIN1);
    MOTORREGISTER2 &= ~(1 << VOORUIT_PIN2);
    MOTORREGISTER &= ~(1 << ACHTERUIT_PIN1);
    MOTORREGISTER2 &= ~(1 << ACHTERUIT_PIN2);
}
