//******Tehnyt: Jaakko Kauppila******

#include "Sensori.h"
#include "Pyorayta.h"
#include "Naytto.h"
#include "Kytkin.h"

int nappi = 2;

void setup() {

 
 //Näytön alustus + Tervetuloa näyttö
 lcd.clear();
 lcd.begin(16, 2); 
 lcd.setCursor(5, 0);
 lcd.print("GL & HF");
 lcd.setCursor(2, 1);
 lcd.print("Alustetaan...");
 
 
 //74HC595 Pinnien alustus
 pinMode(SER_Pin, OUTPUT);
 pinMode(RCLK_Pin, OUTPUT);  
 pinMode(SRCLK_Pin, OUTPUT);

 //Kytkimien alustus
 int switch_pin = 4; //Arduinon 4 pinnille kytkin.
 pinMode(switch_pin, INPUT);

 //Randomlukugeneraattorin alustus
 randomSeed(analogRead(0));

 //Rekistereiden alustus 
 rekiTyhjennys();
 rekiKirjoitus();
 
 //Ledien alustus. Käydään jokainen ledi yksitellen nopeaa läpi 0-36 ja takaisin. Varmistetaan, että kaikki ledit palaa. 
 alustaLedit();
 delay(2000);

 //Napin alustus
 pinMode(nappi,INPUT_PULLUP);

  lcd.clear(); // Tyhjentää näytön
}

void loop() {
  
  kytkin(); //Onko nopea vai hidas pyöräytys kytkimen perusteella. Päivitetään arvo näytölle ja pyorayta headeriin.
  if(digitalRead(nappi) == LOW) {  //Jos nappia on painettu, tapahtuu pyöräytys
   pyorayta();
   } else if (sensori() == true) { //Jos kättä on heilautettu, tapahtuu pyöräytys
     pyorayta();
    }
}
























