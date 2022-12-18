#include <NewPing.h> //Ultraäänisensorikirjasto parannettuna
bool sensori();
void sensori2();
NewPing sonar (11,12,15); /*11 = TRIG
                            12 = ECHO
                            Kolmas sarake = Kuinka kauas se tunnistaa senttimetreinä
                          */

bool sensori() { //Kun sensori tunnistaa liikkeen halutulta etäisyydeltä, lähetetään arvo true.
  if(sonar.ping_cm() > 5){
    return true;
    } else {
    return false;
    }
}

