#include <Adafruit_LiquidCrystal.h>
#include <Keypad.h>

int red = 1;
int blue = 1;
int green = 1;

String rgb = "RED";

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

void color() {
   lcd_1.print("Type " + rgb + " color.");
}

void setup() {
  lcd_1.begin(16, 2);
  lcd_1.setBacklight(1);
	pinMode(10, OUTPUT);
  	pinMode(12, OUTPUT);
	pinMode(11, OUTPUT);
  
    digitalWrite(10, HIGH);
    digitalWrite(12, HIGH);
    digitalWrite(11, HIGH);
  color();
  Serial.begin(9600);
}

void loop() {
  char customKey = customKeypad.getKey();

    
    
    analogWrite(10, red);
    analogWrite(12, blue);
    analogWrite(11, green);
  
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
      
      if (code.toInt() >= 255) {
        code = "255";
      }
      else if (code.toInt() <= 0) {
        code = "0";
      }
      
      if (rgb == "RED") {
        red = code.toInt();
        rgb = "GREEN";
      }
      else if (rgb == "GREEN") {
        green = code.toInt();
        rgb = "BLUE";
      }
      else if (rgb == "BLUE") {
        blue = code.toInt();
        rgb = "";
    	lcd_1.print(String(red) + " " + String(green) + " " + String(blue));
      }
      
      if (rgb != "") {
        color();
        code = "";
      }
    } 
    else {
      code += customKey;
      Serial.println("Ajout : " + String(customKey));
    }

    if (rgb != "") {
    	lcd_1.print(code);
    }
  }
}
