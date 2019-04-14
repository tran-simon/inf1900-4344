#include <avr/io.h>

#include "Robot1.h"
#include "Section1.h"
#include "Section2.h"
#include "Section3.h"
#include "Section4.h"
#include "../../lib/Motors.h"

void start(uint8_t section);

void start(Robot1 & robot1);

void start(uint8_t section) {
    if (section <= SECTION_COUNT && section > 0)
    {
        for (uint8_t i = 0; i < SECTION_COUNT; ++i)
        {
            DEBUG_SOUND();
            LED led;
            led.turnOff();
            led.turnOn(section);
            wait(100);
            DEBUG_SOUND();
            switch (section)
            {
                case 1:
                {
                    Section1 section1;
                    if (i == 3) {
                        section1.setShouldTransition(false);
                    }
                    section1.run();
                }
                    break;
                case 2:
                {
                    Section2 section2;
                    if (i == 3) {
                        section2.setShouldTransition(false);
                    }
                    section2.run();
                }
                    break;
                case 3:
                {
                    Section3 section3;
                    if (i == 3) {
                        section3.setShouldTransition(false);
                    }
                    section3.run();
                }
                    break;
                case 4:
                {
                    Section4 section4;
                    if (i == 3) {
                        section4.setShouldTransition(false);
                    }
                    section4.run();
                }
                    break;
                default:
                    break;
            }


            section = (section == 4) ? 1 : section + 1;


        }
        Motors motors;
        motors.stop();
        Speaker speaker;
        speaker.jouerSon(LA4);
        wait(500);
        speaker.jouerMelodie();
    }
}

void start() {
    uint8_t section = 0;
    while (!(section <= SECTION_COUNT && section > 0))
    {
        LED led;
        led.setStateOnboardLED(LED_ONBOARD_RED);
        wait(500);
        led.setStateOnboardLED(LED_ONBOARD_OFF);

        Robot1 robot1;
        section = robot1.receiveData();


    }
    LED del;
    del.turnOff();
    del.turnOn(section);
    wait(3000);
    start(section);
}

int main() {


    initUART();
    //    Robot1::transitionState();
//    start(2);
//start()            changeSectionSound();;



//    start();
    start();
//    section1.realign();
//    Motors motors;
//    motors.tournerDroite90();
//    while (true) {
//        motors.adjust(255, 255);
//

//    start(1);


//s1.run();

//    robot1.transitionState();
//    Section2 section2;
//    section2.run();

//    Section4 section4;
//    section4.run();
//            start(robot1);
//    start(2);
}