#define OUT1 2
#define OUT2 3
#define OUT3 4
#define OUT4 5
#define IN1 6
#define IN2 7

int steps = 0;
int direction = 1;

void setup() {
  Serial.begin(115200);
  pinMode(OUT1, OUTPUT);
  pinMode(OUT2, OUTPUT);
  pinMode(OUT3, OUTPUT);
  pinMode(OUT4, OUTPUT);
  pinMode(IN1, INPUT);
  pinMode(IN2, INPUT);
  delay(1000);
}

void loop() {
  getInput();
  doSteps(1);
}

void getInput() {
  Serial.println(digitalRead(IN1));
  Serial.println(digitalRead(IN2));
  if (digitalRead(IN1) == HIGH) {
    direction = 1;
  } else if (digitalRead(IN2) == HIGH) {
    direction = -1;
  } else {
    direction = 0;
  }
}

void doRotations(int rotationCount) {
  doSteps(4096 * rotationCount);
}

void doSteps(int stepCount) {
  for (int i = 0; i < stepCount; i++) {
    switch(steps) {
      case 0:
        digitalWrite(OUT1, LOW);
        digitalWrite(OUT2, LOW);
        digitalWrite(OUT3, LOW);
        digitalWrite(OUT4, HIGH);
      break;
      case 1:
        digitalWrite(OUT1, LOW);
        digitalWrite(OUT2, LOW);
        digitalWrite(OUT3, HIGH);
        digitalWrite(OUT4, HIGH);
      break;
      case 2:
        digitalWrite(OUT1, LOW);
        digitalWrite(OUT2, LOW);
        digitalWrite(OUT3, HIGH);
        digitalWrite(OUT4, LOW);
      break;
      case 3:
        digitalWrite(OUT1, LOW);
        digitalWrite(OUT2, HIGH);
        digitalWrite(OUT3, HIGH);
        digitalWrite(OUT4, LOW);
      break;
      case 4:
        digitalWrite(OUT1, LOW);
        digitalWrite(OUT2, HIGH);
        digitalWrite(OUT3, LOW);
        digitalWrite(OUT4, LOW);
      break;
      case 5:
        digitalWrite(OUT1, HIGH);
        digitalWrite(OUT2, HIGH);
        digitalWrite(OUT3, LOW);
        digitalWrite(OUT4, LOW);
      break;
        case 6:
        digitalWrite(OUT1, HIGH);
        digitalWrite(OUT2, LOW);
        digitalWrite(OUT3, LOW);
        digitalWrite(OUT4, LOW);
      break;
      case 7:
        digitalWrite(OUT1, HIGH);
        digitalWrite(OUT2, LOW);
        digitalWrite(OUT3, LOW);
        digitalWrite(OUT4, HIGH);
      break;
      default:
        digitalWrite(OUT1, LOW);
        digitalWrite(OUT2, LOW);
        digitalWrite(OUT3, LOW);
        digitalWrite(OUT4, LOW);
      break;
    }
    incByDirection();
    delay(1);
  }
}

void incByDirection() {
  steps += direction;
  if (steps > 7) { steps = 0; }
  if (steps < 0) { steps = 7; }
}
