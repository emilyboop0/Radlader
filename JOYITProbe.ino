// Joy it ausprobier code

#include <PS2X_lib.h>


#define PS2_DAT //PIN
#define PS2_CMD //PIN
#define PS2_SEL //PIN
#define PS2_CLK //PIN

#define pressures false
#define rumble false

PS2X ps2x; // Klasse erstellen

// Variablen
int error = 0;

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

}

void loop() {
  
  if (error == 1)
    return;

  else{
    ps2x.read_gamepad();

    if(ps2x.Button(PSB_START)) 
      Serial.println("Start wird gehalten");
    if(ps2x.Button(PSB_SELECT)) 
      Serial.println("Select wird gehalten");

    if(ps2x.Button(PSB_PAD_UP)) {
      Serial.print("UP wird gehalten");
      Serial.println(ps2x.Analog(PSB_PAD_UP), DEC);
    }
        if(ps2x.Button(PSB_PAD_DOWN)) {
      Serial.print("DOWN wird gehalten");
      Serial.println(ps2x.Analog(PSB_PAD_DOWN), DEC);
    }
        if(ps2x.Button(PSB_PAD_LEFT)) {
      Serial.print("LEFT wird gehalten");
      Serial.println(ps2x.Analog(PSB_PAD_LEFT), DEC);
    }
        if(ps2x.Button(PSB_PAD_RIGHT)) {
      Serial.print("RIGHT wird gehalten");
      Serial.println(ps2x.Analog(PSB_PAD_RIGHT), DEC);
    }

    if (ps2x.NewButtonState()) {
      if(ps2x.Button(PSB_L3))
        Serial.println("L3 wird gehalten");
      if(ps2x.Button(PSB_R3))
        Serial.println("R3 wird gehalten");
      if(ps2x.Button(PSB_L2))
        Serial.println("L2 wird gehalten");
      if(ps2x.Button(PSB_R2))
        Serial.println("R2 wird gehalten");
    }

    if(ps2x.ButtonPressed(PSB_CIRCLE)) 
      Serial.println("KREIS wird gehalten");
    if(ps2x.ButtonPressed(PSB_CROSS)) 
      Serial.println("X wird gehalten");
    if(ps2x.ButtonPressed(PSB_TRIANGLE)) 
      Serial.println("DREIECK wird gehalten");
    if(ps2x.ButtonPressed(PSB_SQUARE)) 
      Serial.println("VIERECK wird gehalten");

    if(ps2x.Button(PSB_L1) || ps2x.Button(PSB_R1)) {
      Serial.print("Stick Values: ");
      Serial.print(ps2x.Analog(PSS_LY), DEC);
      Serial.print(ps2x.Analog(PSS_LX), DEC);
      Serial.print(ps2x.Analog(PSS_RY), DEC);
      Serial.print(ps2x.Analog(PSS_RX), DEC);
    } 
  }
  delay(50);
}
