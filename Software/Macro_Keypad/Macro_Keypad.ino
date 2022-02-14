#include <Keypad_Matrix.h>
#include <Keyboard.h>


#define KEY1 KEY_F13
#define KEY2 KEY_F14
#define KEY3 KEY_F15
#define KEY4 KEY_F16
#define KEY5 KEY_F8
#define KEY6 KEY_F18
#define KEY7 KEY_F9
#define KEY8 KEY_F20
#define ALT KEY_LEFT_ALT


const byte ROWS = 2;
const byte COLS = 4;


// keypad layout
const char keys[ROWS][COLS] = {{'1','2','3','4'},{'5','6','7','8'}};

const byte rowPins[ROWS] = {10, 16};
const byte colPins[COLS] = {14, 15, 18, 19};


Keypad_Matrix kpd = Keypad_Matrix( makeKeymap (keys), rowPins, colPins, ROWS, COLS );


void keyDown (const char which)
  {
  switch (which) {
  case '1':
    Keyboard.press(KEY1);
    break;
  case '2':
    Keyboard.press(KEY2);
    break;
   case '3':
    Keyboard.press(KEY3);
    break;
   case '4':
    Keyboard.press(KEY4);
    break;
   case '5':
    Keyboard.press(ALT);
    Keyboard.press(KEY5);
    break;
   case '6':
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press(KEY_LEFT_ALT);
    Keyboard.press(206);
    break;
   case '7':
    Keyboard.press(KEY_LEFT_ALT);
    Keyboard.press(KEY7);
    break;
   case '8':
    Keyboard.press(KEY8);
    break;
}
  }

void keyUp (const char which)
  {
  switch (which) {
  case '1':
    Keyboard.release(KEY1);
    break;
  case '2':
    Keyboard.release(KEY6);
    break;
   case '3':
    Keyboard.release(KEY3);
    break;
   case '4':
    Keyboard.release(KEY4);
    break;
   case '5':
    Keyboard.release(ALT);
    Keyboard.release(KEY5);
    break;
   case '6':
    Keyboard.release(KEY_LEFT_CTRL);
    Keyboard.release(KEY_LEFT_ALT);
    Keyboard.release(206);
    break;
   case '7':
    Keyboard.release(KEY_LEFT_ALT);
    Keyboard.release(KEY7);
    break;
   case '8':
    Keyboard.release(KEY8);
    break;
  }
}



void setup() {
  delay(1000);
  kpd.begin ();
  kpd.setKeyDownHandler (keyDown);
  kpd.setKeyUpHandler   (keyUp);
  Keyboard.begin();
}

void loop() {
  kpd.scan ();
}
