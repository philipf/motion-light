/*
  Motion and Light
  
  Simple program that switches on a light via relay 
  when motion detection is detected with a passive infra red sensor
  
  Components:
  PIR:
  http://imall.iteadstudio.com/electronic-components/sensor/im120628009.html
  http://wiki.iteadstudio.com/PIR_Motion_Sensor_Module
  
Created 2015-02-07
by Philip Fourie
*/


// Pin allocations
const int pirPin      = 7;
const int relayPin    = 13;
const int overridePin = 2;

int lightOnTime = 30000; // light has to stay on for 30 seconds

void setup() {
  pinMode(pirPin, INPUT);
  pinMode(overridePin, INPUT);
  pinMode(relayPin, OUTPUT);
}

void loop() {
  if (isOverrided()) {
    delay(300);
    return;
  }
  
  if (isMovementDetected()) {
    relayOn();
    delay(lightOnTime);
  } else {
    relayOff();
    delay(300);
  }
}

bool isOverrided() {
    return digitalRead(overridePin) == 1;
}

bool isMovementDetected() {
  return digitalRead(pirPin) == 1;
}

void relayOn() {
  digitalWrite(relayPin, HIGH);  
}

void relayOff() {
  digitalWrite(relayPin, LOW);
}
