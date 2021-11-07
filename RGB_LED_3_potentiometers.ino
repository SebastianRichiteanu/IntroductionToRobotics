// analog output
const int ledPinRed = 3,
          ledPinGreen = 5,
          ledPinBlue = 6;

// analog input
const int potPinRed = A2,
          potPinGreen = A1,
          potPinBlue = A0;

// bounds for led and potentiometer; used for mappings
const int potLowerBound = 0,
          brokenPotLowerB = 145, // 145 because one of the potentiometers is broken and that is the minimum
          potUpperBound = 1023,
          ledLowerBound = 0,
          ledUpperBound = 255;

// potentiometers values
int potValueRed = 0,
    potValueGreen = 0,
    potValueBlue = 0;

// mapped values of potentiometers
int mappedValueRed = 0,
    mappedValueGreen = 0,
    mappedValueBlue = 0;

void setup() {
  pinMode(ledPinRed, OUTPUT);
  pinMode(ledPinGreen, OUTPUT);
  pinMode(ledPinBlue, OUTPUT);

  pinMode(potPinRed, INPUT);
  pinMode(potPinGreen, INPUT);
  pinMode(potPinBlue, INPUT);

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  potValueRed = analogRead(potPinRed);
  mappedValueRed = map(potValueRed, brokenPotLowerB, potUpperBound, ledLowerBound, ledUpperBound); 

  potValueGreen = analogRead(potPinGreen);
  mappedValueGreen = map(potValueGreen, potLowerBound, potUpperBound, ledLowerBound, ledUpperBound);
  
  potValueBlue = analogRead(potPinBlue);
  mappedValueBlue = map(potValueBlue, potLowerBound, potUpperBound, ledLowerBound, ledUpperBound);
  
  // write the intensity
  analogWrite(ledPinRed, mappedValueRed);
  analogWrite(ledPinGreen, mappedValueGreen);
  analogWrite(ledPinBlue, mappedValueBlue);
}
