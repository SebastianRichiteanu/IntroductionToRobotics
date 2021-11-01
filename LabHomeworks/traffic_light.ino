const int buttonPin = 2;
const int buzzerPin = 3;
const int pedRedPin = 4;
const int pedGreenPin = 5;
const int carRedPin = 6;
const int carYellowPin = 7;
const int carGreenPin = 8;

const int state1Timer = 10000;
const int state2Timer = 3000;
const int state3Timer = 10000;
const int state4Timer = 3000;

const int buzzerSound = 250;

const int buzzTime = 250;
const int buzzFastTime = 100;
const int blinkTime = 500;

int state = 1;

int buttonPressed = 0;
bool lastButtonState = LOW;
bool buttonState = LOW;
unsigned int lastDebounceTime = 0;
unsigned int debounceDelay = 50;

int lastBuzz = 0;
int lastBlink = 0;
int blinkValue = LOW;
int timer = 0;

void state1() {
  digitalWrite(pedRedPin, HIGH);
  digitalWrite(pedGreenPin, LOW);
  digitalWrite(carRedPin, LOW);
  digitalWrite(carYellowPin, LOW);
  digitalWrite(carGreenPin, HIGH);
  noTone(buzzerPin);    
}

void state2() {
  digitalWrite(pedRedPin, HIGH);
  digitalWrite(pedGreenPin, LOW);
  digitalWrite(carRedPin, LOW);
  digitalWrite(carYellowPin, HIGH);
  digitalWrite(carGreenPin, LOW);
  noTone(buzzerPin);    
}

void state3() {
  digitalWrite(pedRedPin, LOW);
  digitalWrite(pedGreenPin, HIGH);
  digitalWrite(carRedPin, HIGH);
  digitalWrite(carYellowPin, LOW);
  digitalWrite(carGreenPin, LOW);
  if (millis() - lastBuzz > buzzTime) {
    noTone(buzzerPin);
  }
  if (millis() - lastBuzz > 2 * buzzTime) {
    tone(buzzerPin, buzzerSound);
    lastBuzz = millis();
  }  
}

void state4() {
  digitalWrite(pedRedPin, LOW);


  if (millis() - lastBlink > blinkTime) {
    blinkValue = !blinkValue;
    lastBlink = millis();
  }
  digitalWrite(pedGreenPin, blinkValue);
  digitalWrite(carRedPin, HIGH);
  digitalWrite(carYellowPin, LOW);
  digitalWrite(carGreenPin, LOW);
  if (millis() - lastBuzz > buzzFastTime) {
    noTone(buzzerPin);
  }
  if (millis() - lastBuzz > 2 * buzzFastTime) {
    tone(buzzerPin, buzzerSound);
    lastBuzz = millis();
  }  
}

void stateChanger() {
  if (state == 1 && buttonPressed && millis() - timer > state1Timer) {
    state = 2;
    buttonPressed = 0;
    timer = millis();
  }
  if (state == 2 && millis() - timer > state2Timer) {
    state = 3;
    timer = millis();
  } else if (state == 3 && millis() - timer > state3Timer) {
    state = 4;
    timer = millis();
  } else if (state == 4 && millis() - timer > state4Timer) {
    state = 1;
    timer = millis();
  }
}

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);

  pinMode(pedRedPin, OUTPUT);
  pinMode(pedGreenPin, OUTPUT);

  pinMode(carRedPin, OUTPUT);
  pinMode(carYellowPin, OUTPUT);
  pinMode(carGreenPin, OUTPUT);
  
  Serial.begin(9600);
}

void loop() {
  int reading = digitalRead(buttonPin);

  if (reading != lastButtonState) {
    lastDebounceTime = millis();
  }
  if (millis() - lastDebounceTime > debounceDelay) {
    if (reading != buttonState) {
      buttonState = reading;
      if (buttonState == LOW) {
        buttonPressed = 1;
        timer = millis();
      }
    }
  }
  lastButtonState = reading;

  stateChanger();
  
  if (state == 1) {
    state1();
  }
  if (state == 2) {
    state2();
  }
  if (state == 3) {
    state3();
  }
  if (state == 4) {
    state4();
  }
  
  Serial.println(buttonPressed);
}
