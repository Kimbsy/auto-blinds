#define OUT1  2
#define OUT2  3
#define OUT3  4
#define OUT4  5

int steps = 0;
int direction = 1;

void setup()
{
  Serial.begin(115200);
  pinMode(OUT1, OUTPUT);
  pinMode(OUT2, OUTPUT);
  pinMode(OUT3, OUTPUT);
  pinMode(OUT4, OUTPUT);
  delay(1000);
}

void loop()
{
  // doSteps(4096);
  doRotations(1);
  delay(1000);
  direction = -direction;
}

void doRotations(int rotationCount) {
  doSteps(4096 * rotationCount);
}

void doSteps(int stepCount){
  for (int i = 0; i < stepCount; i++){
    switch(steps){
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

void incByDirection(){
  steps += direction;
  if (steps > 7) { steps = 0; }
  if (steps < 0) { steps = 7; }
}
