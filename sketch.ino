#include <Adafruit_NeoPixel.h>

#define PINONE 2	 // input pin Neopixel is attached to
#define PINTWO 3	 // input pin Neopixel is attached to
#define PINTHREE 4	 // input pin Neopixel is attached to

#define NUMPIXELS      16 // number of neopixels in strip

Adafruit_NeoPixel pixels1 = Adafruit_NeoPixel(NUMPIXELS, PINONE, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixels2 = Adafruit_NeoPixel(NUMPIXELS, PINTWO, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel pixels3 = Adafruit_NeoPixel(NUMPIXELS, PINTHREE, NEO_GRB + NEO_KHZ800);

int delayval = 100; // timing delay in milliseconds

int redColor = 0;
int greenColor = 0;
int blueColor = 0;
int i = random(0,16);
int k = random(0,16);
int j = random(0,16);
int inten = 0;
int front = 0;
int front1 = 0;
int front2 = 0;
int front3 = 0;
int ZONE_LENGTH = 5;
int randomDelay;

void setup() {
  // Initialize the NeoPixel library.
  pixels1.begin();
  pixels2.begin();
  pixels3.begin();
  randomDelay = random(80, 120);
}

void loop() {
//  displayStyleOne();
//  displayStyleTwo();
  displayStyleThree();
}

void displayStyleThree() {
  setAll(0,0,0);
  
  int tailLength = 5;
  int maxBrightness = 255;
  
  // increment pixels1
  for (int x = 0; x < tailLength; x++) {
    int brightness = 255; //TODO: use x (and taillength?) to make brightness fade along the tail, like a comet
    int num = front1 - x;
    pixels1.setPixelColor(num, pixels1.Color(brightness, brightness, 0));
  }
  pixels1.show();
  front1++;
  if (front1 > NUMPIXELS + tailLength) {
    front1 = 0;
  }

  // increment pixels2
  for (int x = 0; x < tailLength; x++) {
    int brightness = 255; //TODO: use x (and taillength?) to make brightness fade along the tail, like a comet
    int num = front2 - x;
    pixels2.setPixelColor(num, pixels2.Color(brightness, brightness, 0));
  }
  pixels2.show();
  front2++;
  if (front2 > NUMPIXELS + tailLength) {
    front2 = 0;
  }

  // increment pixels3
  for (int x = 0; x < tailLength; x++) {
    int brightness = 255; //TODO: use x (and taillength?) to make brightness fade along the tail, like a comet
    int num = front3 - x;
    pixels3.setPixelColor(num, pixels3.Color(brightness, brightness, 0));
  }
  pixels3.show();
  front3++;
  if (front3 > NUMPIXELS + tailLength) {
    front3 = 0;
  }
  
  
  
  
  delay(randomDelay);
  
}

void displayStyleTwo() {
  
  setAll(0,0,0);
  
  redColor = 25;
  greenColor = 0;
  blueColor = 0;

  for (int x = front - ZONE_LENGTH; x < front; x++) {
  	pixels1.setPixelColor(x, pixels1.Color(redColor, greenColor, blueColor));
  }
  
  
  front++;
  if (front > NUMPIXELS + ZONE_LENGTH) {
    front = 0;
  }
  pixels1.show();
  delay(delayval);  
}


void setAll(int r, int g, int b) {
  for (int x = 0; x < NUMPIXELS; x++) {
  	pixels1.setPixelColor(x, pixels1.Color(r, g, b));
  	pixels2.setPixelColor(x, pixels2.Color(r, g, b));
  	pixels3.setPixelColor(x, pixels3.Color(r, g, b));
  }
  pixels1.show();
  pixels2.show();
  pixels3.show();  
}

void displayStyleOne() {
  inten = inten + 1;
  i = random(0,16);
  j = random(0,16);
  k = random(0,16);
  
  setRandomColor();
  pixels1.setPixelColor(i, pixels1.Color(redColor, greenColor, blueColor));
  setRandomColor();
  pixels1.setPixelColor(j, pixels1.Color(redColor, greenColor, blueColor));
  setRandomColor();
  pixels1.setPixelColor(k, pixels1.Color(redColor, greenColor, blueColor));
  pixels1.show();
  delay(delayval);  
}

// setColor()
// picks random values to set for RGB
void setRandomColor(){
  redColor = random(0, 255);
  greenColor = random(0,255);
  blueColor = random(0, 255);
}
