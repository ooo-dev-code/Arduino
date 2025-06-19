int buttonTiles = 0;
int count = 1;
const int firstLEDPin = 3;  
const int totalLEDPins = 11;

void setup() {
  pinMode(2, INPUT); 

  for (int i = 0; i < totalLEDPins; i++) {
    pinMode(firstLEDPin + i, OUTPUT);
  }
}

void loop() {
  buttonTiles = digitalRead(2);

  if (buttonTiles == HIGH) {
    displayBinary(count);

    count++;
    if (count >= (1 << totalLEDPins)) {
      count = 0;
    }

    delay(500); 
  }
}


void displayBinary(int n) {
  for (int i = 0; i < totalLEDPins; i++) {
    int bit = (n >> i) & 1;
    digitalWrite(firstLEDPin + i, bit);
  }
}
