
#define triggerPin 8
#define motorPin 9

const int sensorPin[] = {2, 3}; //(dailpin, 14 segment dail pin)
const int led = 13;


int sensorCount[3];

bool motorState = LOW;
long motorTime = 0;

bool triggerState = LOW;
long triggerTime = 0;
int lineCount = 0;
int charCount = 0;
int loopCount = 0;
int readPin = 1;

String disk1 = "E+x/^*STMC= -%";
String disk2 = "#0123456789-,.";

void setup() {
  Serial.begin(115200);
  pinMode(led, OUTPUT);

  pinMode(triggerPin, OUTPUT);
  pinMode(motorPin, OUTPUT);

  Serial.println("Set up finished");
}

void loop() {
  //  printChar(" ", false);
  //  printChar("4", false);
  //  printChar("3", false);
  //  printChar("1", false);
  //  printChar("1", false);
  //  printChar("0", true);

  //  printStr(greeting[0],true);
  //  printStr(greeting[1],true);
  for (int i = 0; i < sizeof(bitmap); i++) {
    printStr(bitmap[i], true);
  }
}


void pulseTrigger(int period) {
  digitalWrite(triggerPin, HIGH);
  delay(period);
  digitalWrite(triggerPin, LOW);
}

void printStr(String str, bool printLine) {
  Serial.println("size of str: " + String(sizeof(str)));
  for (int i = 12; i > 0; i--) {
    printChar(String(str[i]), false);
  }
  printChar(String(str[0]), printLine);
}

void printChar(String str, bool printLine) {
  int goal;
  if (charCount == 0) {                   //checks which disk we are using
    goal = disk1.indexOf(str);            //checks validity of char its trying to print
    if (goal == -1) {
      Serial.println("FAILED TO FIND CHAR ON DISK1: " + str);
      goal = 11;
    }
  } else {
    goal = disk2.indexOf(str);
    if (goal == -1) {
      Serial.println("FAILED TO FIND CHAR ON DISK2: " + str);
      return;
    }
  }
  toggleMotor(); //turn on
  wait(0); //wait for dial reset
  sensorCount[readPin] = 0; // dial count reset
  bool complete = false;



  while (!complete) {

    if (digitalRead(sensorPin[readPin])) {                      //count dial turns
      sensorCount[readPin] += 1;
      while (digitalRead(sensorPin[readPin])) {};
      //      Serial.println(sensorCount[readPin]);
    }


    if (sensorCount[readPin] == goal) {             //trigger the actuator
      if (printLine) {
        Serial.println("Writing Charactor " + String(charCount) + ": " + str + ", Completeing Line: " + String(lineCount));
        lineCount += 1;
        charCount = 0;
        pulseTrigger(100);
        //        delay(500);
      } else {
        Serial.println("Writing Charactor " + String(charCount) + ": " + str);
        pulseTrigger(30);
        charCount += 1;
      }
      complete = true;
    }
  }
  toggleMotor(); //turn off
}



void wait(int pin) {
  while (!digitalRead(sensorPin[pin])) {};
}

void toggleMotor() {
  motorState = !motorState;
  if (motorState) {
    digitalWrite(motorPin, HIGH);
  }
  else {
    digitalWrite(motorPin, LOW);
  }
}
