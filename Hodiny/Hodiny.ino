#include <FastLED.h>

#define NUM_LEDS 60
#define DATA_PIN 5
#define CLOCK_PIN 13
int s;
int m;
int h;
bool t;
CRGB leds[NUM_LEDS];
void sync(){
      String vst = Serial.readStringUntil('\n');
      char* buf = vst.c_str();
      char *Hs = strtok(buf, ":"); 
      char *Ms = strtok(NULL, ":");
      char *Ss = strtok(NULL, ":");
      h = atoi(Hs);
      if(h >= 12){
        h = h - 12;
      }
      h = h * 5;
      m = atoi(Ms);
      s = atoi(Ss);
}

void setup() { 
  	  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
      Serial.begin(9600);
      while(!Serial.available()){}
      sync();
}

void loop() { 
  while(Serial.available() < 1){
  
  leds[s] = CRGB(100, 0, 0);
  leds[m] = CRGB(0, 0, 100);
  leds[h] = CRGB(0, 100, 0);
  FastLED.show();
  delay(1000);
  leds[s] = CRGB::Black;
  leds[m] = CRGB::Black;
  leds[h] = CRGB::Black;
  s++;
  timing();
  }
  sync();
}
void timing(){
    if(s == 59){
    s = 0;
    m++;
  }
  else if(m == 59){
    s = 0;
    m = 0;
    h = h + 5;
  }
  else if(h == 55){
    s = 0;
    m = 0;
    h = 0;
  }
}
