#include <Adafruit_LiquidCrystal.h>
#include <Keypad.h>

String code = ""; 
int all = 0;
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
  
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);

}

void loop() {
  char customKey = customKeypad.getKey();

  if (customKey) {
    lcd_1.clear();
    lcd_1.setCursor(0, 1);

    lcd_1.print(customKey);
    int num = customKey - '0';
    int LED = 0;
    if (num == 1 || num == 4 || num == 7) {
      LED = 10;
    }
    else if (num == 2 || num == 5 || num == 8) {
      LED = 11;
    }
    else if (num == 3 || num == 6 || num == 9) {
      LED = 12;
    }
    else {
      LED = 13;
    }
    
    for (int i = 0; i <= 3; i++) {
      digitalWrite(i+10, LOW);
    }
    digitalWrite(LED, HIGH);
    

  }
}
