#include <Arduino.h>
#include <Joystick.h>

#define switch_A_pin 7
#define switch_B_pin
#define debounce_time 10


uint8_t switch_A_state = 0;
uint8_t switch_B_state = 0;
long last_button_press = 0;

// Create the Joystick
Joystick_ Joystick(0x05,0x04,
  2, 0,                    //  Button Count, Hat Switch Count
  false, false, false,     //  X and Y and Z Axis
  false, false, false,        //  Rx, Ry, or Rz
  false, false,            //  rudder or throttle
  false, false, false);    //  accelerator, brake, or steering

void setup() {
  
  pinMode(switch_A_pin, INPUT_PULLUP);
  Joystick.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  if (millis() - last_button_press > debounce_time)
  {  
    last_button_press = millis();
    if (digitalRead(switch_A_pin) != switch_A_state)
    {
      switch_A_state = !switch_A_state;
      Joystick.setButton(1, switch_A_state);
    }
  }
}