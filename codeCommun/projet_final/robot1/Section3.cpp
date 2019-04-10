//
// Created by simon on 4/9/19.
//

#include "Section3.h"

Section3::Section3() {
    setVitesse(VITESSE_LENT);
}


bool Section3::suivreLigneSection3(uint8_t code) {
    return suivreLigne(code);

}

bool Section3::evaluateState(uint8_t code) {
    switch (state)
    {
        case 0:
            if (code == 0b11111)
            {
                moteur.arreterMoteurs();
                button.init();

                convertisseur.setShouldUpdateDel(false);//todo

                state++;

            }
            break;
        case 1:
        case 3:
            if (button.getState())
            {
                moteur.init();
                if (state == 3)
                {
                    return false;
                }
                else
                {
                    convertisseur.setShouldUpdateDel(true);//todo
                }
                state++;
            }
            break;
        case 2:

            if (code == 0)
            {

                convertisseur.setShouldUpdateDel(false);
                del.eteindre();
                del.allumer(2);//todo

                moteur.arreterMoteurs();
                button.init();
                state++;
            }
            break;
    }
    return true;
}

void Section3::evaluateAction(uint8_t code) {

    switch (state)
    {
        case 0:
            suivreLigne(code);
            break;
        case 1:
        case 3:
            break;
        case 2:
            suivreLigneSection3(code);
            break;
    }

}
