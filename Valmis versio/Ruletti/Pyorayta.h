#define rekistereita 5 //Rekisterien määrä 
#define rekisteripinnit rekistereita * 8 - 3 // 37 lediä.

void pyorayta();
void rekiTyhjennys(); // Nollaa rekisteri
void asetaRekisteri(int luku, int luku2); // Aseta rekisterin pinnit high tai low
void rekiKirjoitus(); // Kirjoita rekisteri
void pyoraytaViimeinen(); //Jätetään random arvottu led päälle.

//Rekisterialustukset
int SER_Pin = 8;   //pin 14 on 75HC595
int RCLK_Pin = 9;  //pin 12 on 75HC595
int SRCLK_Pin = 10; //pin 11 on 75HC595

bool rekisterit[rekisteripinnit];

//Muuttujat
int delayx = 20; //Aloitusaika delaylle, jota inkrementoidaan pyörityksen edetessä.
int dilsa = delayx;
int luku;
int alustusNopeus = delayx; //Alustaledit funktiota varten. 

int hidas = random(4,6);
int nopea = random(1,3);
int pyoraytys; // Alustetaan hidas tai nopea pyöräytys kytkimestä
int switch_pin = 4;

void pyorayta() {
for(int i = 0; i < pyoraytys; i++) {
  for (luku = 0; luku <= rekisteripinnit; luku++) {

      //Ledi päälle
      asetaRekisteri(luku, HIGH); //Asetetaan rekisteriin arvo 1
      rekiKirjoitus(); //Tuodaan ledeille rekisteriin annettu arvo. Ledi syttyy

      delay(dilsa); // Ledien vaihdon välissä pieni tauko joka inkrementoituu joka toistolla.

      //Ledi pois päältä
      asetaRekisteri(luku, LOW); //Asetetaan rekisteriin arvo 0
      rekiKirjoitus(); // Tuodaan ledeille rekisteriin annettu arvo. Ledi sammuu

      dilsa = dilsa + 1; //Lisätään aikaa ledien vaihdon välille.
    }
  }
  pyoraytaViimeinen(); //Kun uloin for loop on käyty, suoritetaan viimeinen pyöräytys.
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

void pyoraytaViimeinen() {

int randomPinni = random(0,rekisteripinnit); //Arvotaan luku 0 - 36 väliltä.

for(int luku1 = 0; luku1 <=  randomPinni; luku1++) { /*Jos luku1 ei ole sama kuin randomPinnit niin sammutetaan ledi.
                                                    Saman luvun kohdalle osuessaan jätetään ledi palamaan.*/

  asetaRekisteri(luku1, HIGH); //Asetetaan rekisteriin arvo 1
  rekiKirjoitus();//Tuodaan ledeille rekisteriin annettu arvo. Ledi syttyy

if(luku1 != randomPinni) { 
  delay(dilsa);
  asetaRekisteri(luku1, LOW);//Asetetaan rekisteriin arvo 0
  rekiKirjoitus();//Tuodaan ledeille rekisteriin annettu arvo. Ledi sammuuu
  dilsa = dilsa +1;//Lisätään delayn arvoa. 
    } 
  }
  rekiTyhjennys(); //Tyhjennetään rekisteri seuraavaa pyöräytystä varten
  dilsa = delayx; //Alustetaan delay arvo alulleen seuraavaa pyöräytystä varten
}

void alustaLedit() {
  for (int luku2 = 0; luku2 <= rekisteripinnit; luku2++) {

      asetaRekisteri(luku2, HIGH);
      rekiKirjoitus();

      delay(alustusNopeus);

      asetaRekisteri(luku2, LOW);
      rekiKirjoitus();

  }
  for (int luku2 = rekisteripinnit; luku2 >= 0; luku2--) {

      asetaRekisteri(luku2, HIGH);
      rekiKirjoitus();

      delay(alustusNopeus);

      asetaRekisteri(luku2, LOW);
      rekiKirjoitus();
  }
  rekiTyhjennys();
}
