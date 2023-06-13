const int motorPin = 2;
const int buttonPin = 9;
const int switchPin = 10;
int buttonState = LOW;
int oldButtonState = LOW;
int switchState = LOW;
int motorState = LOW;

void setup() {
  Serial.begin(9600);
  pinMode(motorPin, OUTPUT);
  pinMode(buttonPin, INPUT);
  pinMode(buttonState, INPUT);
  digitalWrite(motorPin, LOW);
}

void loop() {
  buttonState = digitalRead(buttonPin);
  switchState = digitalRead(switchPin);

  if(buttonState != oldButtonState && buttonState == HIGH && switchState == HIGH){
    motorState = (motorState == LOW ? HIGH : LOW);
    digitalWrite(motorPin, motorState);
    delay(50);
  }
  oldButtonState = buttonState;
}
