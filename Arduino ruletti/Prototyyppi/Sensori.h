#include <NewPing.h> //Ultraäänisensorikirjasto parannettuna
bool sensori();
NewPing sonar (10,11,20); /*10 = TRIG
                            11 = ECHO
                            20 = Kuinka kauas se tunnistaa (20cm)
                          */

bool sensori() { //Kun sensori tunnistaa liikkeen, lähetetään arvo true.
  if(sonar.ping_cm() > 5){
    return true;
  } else {
    return false;
  }
}
