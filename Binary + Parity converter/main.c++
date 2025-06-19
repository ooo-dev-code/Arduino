#include <Adafruit_LiquidCrystal.h>

int button = 0;
int count = 0;

int buttonTiles = 0;

Adafruit_LiquidCrystal lcd_1(0);

// button
void parity()
{ 
  if (count % 2 == 0) {
      digitalWrite(13, HIGH);
      digitalWrite(12, LOW);
      lcd_1.print(" Even");
  }
  
  if (count % 2 != 0) {
     digitalWrite(12, HIGH);
    digitalWrite(13, LOW);
    lcd_1.print(" Odd");
  }
}

void convertToBinary(unsigned int n)
{
    if (n / 2 != 0) {
        convertToBinary(n / 2);
    }
    lcd_1.print(n % 2);

}

// buttonTiles

//
void setup()
{
  pinMode(2, INPUT);     // button input
  pinMode(4, INPUT);     // second button input
  pinMode(13, OUTPUT);   // LED for Even
  pinMode(12, OUTPUT);   // LED for Odd
  pinMode(7, OUTPUT);   // LED for Tiles

  lcd_1.begin(16, 2);     // 16x2 LCD
  lcd_1.setBacklight(1);  // Turn on backlight
}

void loop()
{
  lcd_1.setCursor(0, 1);
  lcd_1.print(count);
  lcd_1.setBacklight(1);
  
  button = digitalRead(2);
  buttonTiles = digitalRead(4);
  
  if (buttonTiles == HIGH) {
     digitalWrite(7, HIGH);
  }
  
  if(button == HIGH)
  {
    count+=1;
    
  	lcd_1.setBacklight(0);
  	lcd_1.setBacklight(1);
    parity();
    lcd_1.print("  ");
    convertToBinary(count);

  } else {
    digitalWrite(13, LOW);
  }
  
}
