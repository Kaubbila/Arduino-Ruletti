#define rekistereita 1 //Rekisterien määrä 
#define rekisteripinnit rekistereita * 8

void pyorayta();
void rekiTyhjennys(); // Nollaa rekisteri
void rekiKirjoitus(); // Kirjoita rekisteri
void asetaRekisteri(int luku, int luku2); // Aseta rekisterin pinnit high tai low
void pyoraytaViimeinen();

//Rekisterialustukset
int SER_Pin = 8;   //pin 14 on the 75HC595
int RCLK_Pin = 9;  //pin 12 on the 75HC595
int SRCLK_Pin = 10; //pin 11 on the 75HC595

bool rekisterit[rekisteripinnit];

//Muuttujat
int randomi = random(6,8);
 int dilsa = 5;
 int luku;

void pyorayta() {
  
for(int i = 0; i < randomi; i++) { //Määritetään monestikko pyöräytetään rulettia.
  for (luku = 0; luku <= rekisteripinnit; luku++) {// for looppi 36 mutta tässä prototyypissä 1 rekisteri joten 8 pinniä
      //Ledi päälle
      asetaRekisteri(luku, HIGH);
      rekiKirjoitus();

      delay(dilsa); //Tätä lukua inkrementoidaan. Jokaisen luvun jälkeen arvo kasvaa, jolloin ruletin pyöriminen hidastuu. 
      //Ledi pois päältä
      asetaRekisteri(luku, LOW);
      rekiKirjoitus();
      dilsa = dilsa + 1;
    }
  }
  pyoraytaViimeinen();
  }
  

void rekiTyhjennys(){
 for(int i = rekisteripinnit - 1; i >=  0; i--){
   rekisterit[i] = LOW;
 }
}

void rekiKirjoitus(){
 digitalWrite(RCLK_Pin, LOW);

 for(int i = rekisteripinnit - 1; i >=  0; i--){
   digitalWrite(SRCLK_Pin, LOW);

   int luku = rekisterit[i];

   digitalWrite(SER_Pin, luku);
   digitalWrite(SRCLK_Pin, HIGH);

 }
 digitalWrite(RCLK_Pin, HIGH);
}

void asetaRekisteri(int luku, int luku2){
 rekisterit[luku] = luku2;
}

void pyoraytaViimeinen() { //Jätetään arvottu ledi päälle. 

int randomPinnit = random(0,8); /* Arvotaan mikä ledi jätetään päälle.
                                  Ensimmäisessä prototyyppimallissa 8 lediä, joten lukujen arvonta 0,7 välillä.
                                  */
for(int luku1 = 0; luku1 <=  randomPinnit; luku1++) { //Ledi päälle, jos ei ole haluttu arvo, niin mennään if lausekkeeseen sammuttamaan led.
  asetaRekisteri(luku1, HIGH);
  rekiKirjoitus();

if(luku1 != randomPinnit) { 
  delay(dilsa);
  asetaRekisteri(luku1, LOW);
  rekiKirjoitus();
  dilsa = dilsa +1;
    } 
  }
  //Nollataan arvot seuraavaa pyöräytystä varten. 
  rekiTyhjennys(); 
  dilsa = 5;
}
