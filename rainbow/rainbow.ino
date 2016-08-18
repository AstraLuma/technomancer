/*
 * 3: Neck blue
 * 5: Neck green
 * 6: Arm red
 * 9: Neck red
 * 10: Arm green
 * 11: Arm blue
 */
#define ARM_RED    6
#define ARM_GREEN  10
#define ARM_BLUE   11
#define NECK_RED   9
#define NECK_GREEN 5
#define NECK_BLUE  3

#define RADS_PER_MILLI 6.28318530718 / (60.0 * 1000.0)

#define CHANNEL_OFFSET (3.14159265359 / 3.0)

float get_hue() {
  return millis() * RADS_PER_MILLI;
}

byte red(float hue) {
  return sin(hue + CHANNEL_OFFSET) * 127 + 127;
}

byte green(float hue) {
  return sin(hue - CHANNEL_OFFSET) * 127 + 127;
}

byte blue(float hue) {
  return sin(hue) * 127 + 127;
}

void setup() {
  // nothing happens in setup
}

void loop() {
  float hue = get_hue();
  byte r = red(hue);
  byte g = green(hue);
  byte b = blue(hue);
  analogWrite(ARM_RED, r);
  analogWrite(ARM_GREEN, g);
  analogWrite(ARM_BLUE, b);
  
  analogWrite(NECK_RED, r);
  analogWrite(NECK_GREEN, g);
  analogWrite(NECK_BLUE, b);
}


