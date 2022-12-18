void kytkin() {

  if(digitalRead(switch_pin) == HIGH){
    lcd.setCursor(0,0);
    lcd.print("Nopea pyoraytys"); //Kirjoitetaan lcd näyttöön
    pyoraytys = nopea;//Valitaan pyorayta.h funktioon nopea pyöräytys

    
  } else {
    lcd.setCursor(0,0);
    lcd.print("Hidas pyoraytys"); //Kirjoitetaan lcd näyttöön
    pyoraytys = hidas;//Valitaan pyorayta.h funktioon hidas pyöräytys
  }

}