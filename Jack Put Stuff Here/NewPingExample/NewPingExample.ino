
#include <NewPing.h>

#define TRIGGER_PIN  12  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     11  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define USPOWER_PIN  4
#define MAX_DISTANCE 300 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.

void setup() {
  Serial.begin(115200); // Open serial monitor at 115200 baud to see ping results.
  pinMode(USPOWER_PIN, OUTPUT);
  digitalWrite(USPOWER_PIN, HIGH);
}

void loop() {
  unsigned int cm = sonar.ping_cm();
  if (cm != 0)
  {
    Serial.print("Ping: ");
    Serial.print(cm); // Send ping, get distance in cm and print result (0 = outside set distance range)
    Serial.println("cm");
    delay(30);                     // Wait 30ms between pings (about 30 pings/sec). 29ms should be the shortest delay between pings.
  }
  if (cm <= 8 * 2.54 * 12 && cm != 0)
  {
    Serial.println("Intruder Alert");
  }
  if (cm == 0 && digitalRead(ECHO_PIN) == HIGH) {
    digitalWrite(USPOWER_PIN, LOW);
    delay(50);     // 50 mS is the minimum Off time to get clean restart
    digitalWrite(USPOWER_PIN, HIGH); // Adjust this value if your sensors don't read after reset
    delay(60);     // Some sensors throw out a very short false echo after timeout
    sonar.ping_cm(); // 5cm-10cm value.  If your sensors do not throw out
    // this false echo, you can get rid of this delay and ping after power HIGH
  }                // Conversely, if you still get a false echo, you may need to increase
}                  // the delay.
