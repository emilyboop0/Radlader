// Uno Master Code

#include <PS2X_lib.h>
#include <Wire.h>

#define PS2_DAT //PIN
#define PS2_CMD //PIN
#define PS2_SEL //PIN
#define PS2_CLK //PIN

#define pressures false
#define rumble false

PS2X ps2x; // Klasse erstellen

// Variablen
int error = 0;
byte 

void setup(){

  Serial.begin(57600);
  delay(300); //Zeit zum starten

  error = ps2x.config_gammepad(PS2_CLK, PS2_CMD, PS2_SEL, PS2_DAT, pressures, rumble); //setup check
  
  if (error == 0){
    Serial.print("Verbindung erfolgreich");
  }

  else if (error == 1)
    Serial.println("Kein Controller gefunden");
  
  else if (error == 2)
    Serial.println("Controller gefunden, Eingabe nicht möglich");

  Wire.begin;
}


