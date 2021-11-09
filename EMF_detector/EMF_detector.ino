// pins for display + buzzer + antenna
const int pinA = 2;
const int pinB = 3;
const int pinC = 4;
const int pinD = 5;
const int pinE = 6;
const int pinF = 7;
const int pinG = 8;
const int pinDP = 9;
const int buzzerPin = 11;
const int antennaPin = A0;

// delay
const int delayDuration = 300;

// nr of samples for reading
const int sample = 300;

// max of antenna 
const int analogReadMax = 10;

// buzzer settings
const int toneDuration = 300;
const int toneMultiplier = 100;

// display
const int segSize = 8;
const int noOfDigits = 11;
int segments[segSize] = {
  pinA, pinB, pinC, pinD, pinE, pinF, pinG, pinDP
};

byte digitMatrix[noOfDigits][segSize - 1] = {
// a  b  c  d  e  f  g
  {1, 1, 1, 1, 1, 1, 0}, // 0
  {0, 1, 1, 0, 0, 0, 0}, // 1
  {1, 1, 0, 1, 1, 0, 1}, // 2
  {1, 1, 1, 1, 0, 0, 1}, // 3
  {0, 1, 1, 0, 0, 1, 1}, // 4
  {1, 0, 1, 1, 0, 1, 1}, // 5
  {1, 0, 1, 1, 1, 1, 1}, // 6
  {1, 1, 1, 0, 0, 0, 0}, // 7
  {1, 1, 1, 1, 1, 1, 1}, // 8
  {1, 1, 1, 1, 0, 1, 1}  // 9
};

bool state = HIGH;

// antenna current value
float antennaRead = 0;

void displayNumber(byte digit) {
  for (int i = 0; i < segSize - 1; ++i) {
    digitalWrite(segments[i], digitMatrix[digit][i]);
  }
  digitalWrite(segments[segSize-1],state);
}

int getReading() {
  // reading value of antenna 300 (sample) times and calculate the average
  int val;
  unsigned long avg = 0;
  for (int i = 0; i < sample; ++i) {
    val = analogRead(antennaPin);
    avg += val;
  }
  val = avg / sample;
  // mapping the value to the number of digits
  val = map(val, LOW, analogReadMax, LOW, noOfDigits);
  
  return val;
}

void setup() {
  // setting display pins for output
  for(int i = 0; i < segSize; ++i){
    pinMode(segments[i], OUTPUT);
  }
  // antenna for input
  pinMode(antennaPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  antennaRead = getReading();
  displayNumber(antennaRead);
  tone(buzzerPin, antennaRead * toneMultiplier, toneDuration);
  delay(delayDuration);
}
