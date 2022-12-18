#include "Sensori.h"
#include "Pyorayta.h"

int nappi = 2;
void setup() {

 pinMode(SER_Pin, OUTPUT);
 pinMode(RCLK_Pin, OUTPUT);  
 pinMode(SRCLK_Pin, OUTPUT);

 randomSeed(analogRead(0));

 //Rekistereiden alustus 
 rekiTyhjennys();
 rekiKirjoitus();

 //Nappi
 
 pinMode(nappi,INPUT_PULLUP);  //Nappikytkin

}

void loop() {

    if(digitalRead(nappi) == LOW) {
    pyorayta();
  } else if (sensori() == true) {
    pyorayta();
  }
}
//IDEA. Näyttö, joka ilmoittaa onko HIGH vai LOW pyöräytys valittuna??
//***************************************************************************************  
    //Nopea pyöräytys!
//***************************************************************************************  
    //Hidas pyöräytys!
