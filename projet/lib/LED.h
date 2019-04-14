//
// Created by simon on 3/18/19.
//

#ifndef MAIN_LED_H
#define MAIN_LED_H

#include "Utils.h"

#define LED_ONBOARD_OFF 0
#define LED_ONBOARD_GREEN 1
#define LED_ONBOARD_RED 2


/**
 * Classe Permettant de contrôler les DELs.
 */
class LED {


public:
    LED();

    uint8_t getLEDPosition(uint8_t numLED) const;

/**
 * Permet d'allumer en rouge la DEL avec un index
 * @param numLED Le numero de la DEL à allumer (1 à 5)
 */
    void turnOn(uint8_t numLED) const;

    void turnOn() const;

    void turnOff(uint8_t numLED) const;

/**
 * Permet d'éteindre toutes les DELs
 */
    void turnOff() const;


/**
 * Permet de définir l'état de toutes les DELs
 * @param state l'état
 */
    void setState(bool state) const;

    /**
     * Permet de définir l'état d'une DEL
     * @param state L'état
     * @param numLED Le numéro de la DEL
     */
    void setState(bool state, uint8_t numLED) const;


    /**
     * Permet de définir l'état de la DEL sur la carte mère
     *
     * @param state L'état de la DEL. 0: éteinte, 1: Vert, 2: Rouge
     */
    void setStateOnboardLED(uint8_t state) const;

};


#endif //MAIN_LED_H
