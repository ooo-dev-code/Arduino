#include <Adafruit_LiquidCrystal.h>
#include <Keypad.h>

String code = ""; 
const byte ROWS = 4; 
const byte COLS = 4; 

char hexaKeys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[ROWS] = {9, 8, 7, 6}; 
byte colPins[COLS] = {5, 4, 3, 2}; 

Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);
Adafruit_LiquidCrystal lcd_1(0);  

void setup() {
  lcd_1.begin(16, 2);
  lcd_1.setBacklight(1);
  Serial.begin(9600);
}

void loop() {
  char customKey = customKeypad.getKey();

  if (customKey) {
    lcd_1.clear();
    lcd_1.setCursor(0, 1);

    if (customKey == 'A') {
      code = "";
      Serial.println("Code effacé");
    } 
    else if (customKey == 'B') {
      if (code.length() > 0) {
        code = code.substring(0, code.length() - 1);
        Serial.println("Dernière lettre effacée");
      }
    } 
    else if (customKey == 'C') {
      Serial.println("Test");
    } 
    else if (customKey == 'D') {
      Serial.println("Exécution");
      if (code == "1234") {
        digitalWrite(12, HIGH);  
        digitalWrite(13, LOW);
      } else {
        digitalWrite(12, LOW);  
        digitalWrite(13, HIGH);
      }
    } 
    else {
      code += customKey;
      Serial.println("Ajout : " + String(customKey));
    }

    lcd_1.print(code);
  }
}
