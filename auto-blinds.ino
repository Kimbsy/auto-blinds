#define STEP_PIN 3
#define DIR_PIN 4
#define IN1 6
#define IN2 7

int direction = 0;

void setup() {
  pinMode(STEP_PIN, OUTPUT); 
  pinMode(DIR_PIN, OUTPUT);
  Serial.begin(115200);
}

void loop() {
  getInput();
  if (direction != -1) {
    doSteps(1);
  }
}

void getInput() {
  if (digitalRead(IN1) == HIGH) {
    direction = HIGH;
    digitalWrite(DIR_PIN, direction);
  } else if (digitalRead(IN2) == HIGH) {
    direction = LOW;
    digitalWrite(DIR_PIN, direction);
  } else {
    direction = -1;
  }
}

void doSteps(int stepCount) {
  for(int i = 0; i < stepCount; i++) {
    digitalWrite(STEP_PIN, HIGH); 
    delayMicroseconds(500); 
    digitalWrite(STEP_PIN, LOW); 
    delayMicroseconds(500); 
  }
}
