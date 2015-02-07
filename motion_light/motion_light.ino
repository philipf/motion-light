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
const int pirPin   = 7;
const int relayPin = 2;
const int relayLed = 13;
const int overridePin = 4;

unsigned int lightOnTime = 10000; // Minimum time for which light has to stay on
unsigned long previousHigh = 0;

void setup() {
  pinMode(pirPin, INPUT);
  pinMode(relayPin, OUTPUT);
  
  pinMode(overridePin, INPUT);
}

void loop() {
  if (isOverride()) {
    relayOn();
    digitalWrite(relayLed, HIGH);
    delay(300);
    return;
  }
  
  digitalWrite(relayLed, LOW);
  
  unsigned long currentMillis = millis();
  
  int pirState = digitalRead(pirPin);
  
  // Automatically extend the period for which the light should stay on.
  // This is important to prevent the problem of switching the lights off 
  // when movement was detected a just couple of seconds ago.
  // In other words the window for the light stays on is extended everytime movement
  // is detected.
  if (pirState == HIGH) {
    relayOn();
    previousHigh = currentMillis;
  } else if ((unsigned long)(currentMillis - previousHigh) >= lightOnTime) {
    relayOff();
  }
   
  delay(300);
}

void relayOn() {
  digitalWrite(relayPin, HIGH);
 // digitalWrite(relayLed, HIGH);  
}

void relayOff() {
  digitalWrite(relayPin, LOW);
//  digitalWrite(relayLed, LOW);    
}

bool isOverride() {
  return (digitalRead(overridePin) == HIGH);
}
