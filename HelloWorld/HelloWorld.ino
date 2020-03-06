/**
 * 
 * @author Bousselmi Bessem 
 * Sources for this can be found at:
 * https://github.com/bassouma21001/iot_workshop
 * 
 */
 
// the setup function runs once when you press reset or power the board
#define LED 16
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(LED, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(LED, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);                       // wait for a second
}
