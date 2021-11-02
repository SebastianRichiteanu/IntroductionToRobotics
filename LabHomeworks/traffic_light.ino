// button + buzzer + led pins
const int buttonPin = 2;
const int buzzerPin = 3;
const int pedRedPin = 4;
const int pedGreenPin = 5;
const int vehRedPin = 6;
const int vehYellowPin = 7;
const int vehGreenPin = 8;

// states time duration
const int state1Timer = 10000;
const int state2Timer = 3000;
const int state3Timer = 10000;
const int state4Timer = 5000;

// buzzer + blinking settings
const int buzzerSound = 250;
const int buzzTime = 250;
const int buzzFastTime = 150;
const int blinkTime = 300;
int blinkValue = LOW;

// buzzer + blinking timers
unsigned long lastBuzz = 0;
unsigned long lastBlink = 0;

// button reading
int reading = 0;
bool buttonPressed = 0;
bool lastButtonState = LOW;
bool buttonState = LOW;
unsigned long lastDebounceTime = 0;
unsigned long debounceDelay = 50;

// current state + timer for state
int state = 1;
unsigned long timer = 0;

// to check if someone pressed the button (IN STATE 1)
void buttonChecker() { 
  reading = digitalRead(buttonPin);
  if (reading != lastButtonState) {
    lastDebounceTime = millis();
  }
  if (millis() - lastDebounceTime > debounceDelay) {
    if (reading != buttonState) {
      buttonState = reading;
      if (buttonState == LOW && state == 1) {
        if (!buttonPressed) { // to not reset the timer if the button is pressed multiple times
          buttonPressed = 1;
          timer = millis();
        }
      }
    }
  }
  lastButtonState = reading;
}

void state1() {
  digitalWrite(pedRedPin, HIGH);
  digitalWrite(pedGreenPin, LOW);
  digitalWrite(vehRedPin, LOW);
  digitalWrite(vehYellowPin, LOW);
  digitalWrite(vehGreenPin, HIGH);
  noTone(buzzerPin);    
}

void state2() {
  digitalWrite(pedRedPin, HIGH);
  digitalWrite(pedGreenPin, LOW);
  digitalWrite(vehRedPin, LOW);
  digitalWrite(vehYellowPin, HIGH);
  digitalWrite(vehGreenPin, LOW);
  noTone(buzzerPin);    
}

void state3() {
  digitalWrite(pedRedPin, LOW);
  digitalWrite(pedGreenPin, HIGH);
  digitalWrite(vehRedPin, HIGH);
  digitalWrite(vehYellowPin, LOW);
  digitalWrite(vehGreenPin, LOW);
  // buzz checker
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
  // blink checker
  if (millis() - lastBlink > blinkTime) {
    blinkValue = !blinkValue;
    lastBlink = millis();
  }
  digitalWrite(pedGreenPin, blinkValue);
  
  digitalWrite(vehRedPin, HIGH);
  digitalWrite(vehYellowPin, LOW);
  digitalWrite(vehGreenPin, LOW);
  
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
  } else if (state == 2 && millis() - timer > state2Timer) {
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
  pinMode(vehRedPin, OUTPUT);
  pinMode(vehYellowPin, OUTPUT);
  pinMode(vehGreenPin, OUTPUT);
  
  Serial.begin(9600);
}

void loop() {
  buttonChecker();

  stateChanger();
  
  if (state == 1) {
    state1();
  } else if (state == 2) {
    state2();
  } else if (state == 3) {
    state3();
  } else if (state == 4) {
    state4();
  }

  Serial.println(buttonPressed);
  
}
