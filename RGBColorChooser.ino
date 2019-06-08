#include <Keypad.h>

const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
//define the cymbols on the buttons of the keypads
char hexaKeys[ROWS][COLS] = {
  {'1', '2', '3', NULL},
  {'4', '5', '6', NULL},
  {'7', '8', '9', NULL},
  {NULL, '0', NULL, NULL}
};

byte rowPins[ROWS] = {13, 12, 7, 6}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {5, 4, 3, 2}; //connect to the column pinouts of the keypad

//initialize an instance of class NewKeypad
Keypad customKeypad = Keypad( makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS);

void setup() {
  Serial.begin(9600);
}
//waits for a new input until it recieves 9. It will then display a color that corrosponds to the hexidecimal.
void loop() {
  char customKey = customKeypad.getKey();
  int input = 0;
  int r = 0;
  int g = 0;
  int b = 0;
  int x = 0;
  int y = 0;
  while (y == 0) {
    customKey = customKeypad.getKey();
    if (customKey && x == 0) {
      input = customKey - '0';
      r += input * 100;
      x++;
      Serial.println(customKey);
      delay(100);
    } else if (customKey && x == 1) {
      input = customKey - '0';
      r += input * 10;
      x++;
      Serial.println(customKey);
      delay(100);
    } else if (customKey && x == 2) {
      input = customKey - '0';
      r += input;
      x = 0;
      y = 1;
      Serial.println(customKey);
      Serial.println(r);
      delay(100);
    }
  }
  while (y == 1) {
    customKey = customKeypad.getKey();
    if (customKey && x == 0) {
      input = customKey - '0';
      g += input * 100;
      x++;
      Serial.println(customKey);
      delay(100);
    } else if (customKey && x == 1) {
      input = customKey - '0';
      g += input * 10;
      x++;
      Serial.println(customKey);
      delay(100);
    } else if (customKey && x == 2) {
      input = customKey - '0';
      g += input;
      x = 0;
      y = 2;
      Serial.println(customKey);
      Serial.println(g);
      delay(100);
    }
  }
  while (y == 2) {
    customKey = customKeypad.getKey();
    if (customKey && x == 0) {
      input = customKey - '0';
      b += input * 100;
      x++;
      Serial.println(customKey);
      delay(100);
    } else if (customKey && x == 1) {
      input = customKey - '0';
      b += input * 10;
      x++;
      Serial.println(customKey);
      delay(100);
    } else if (customKey && x == 2) {
      input = customKey - '0';
      b += input;
      Serial.println(customKey);
      Serial.println(b);
      delay(100);
      analogWrite(9, r);
      analogWrite(10, g);
      analogWrite(11, b);
      y = 0;
      x = 0;
      delay(1000);
    }
  }
}
