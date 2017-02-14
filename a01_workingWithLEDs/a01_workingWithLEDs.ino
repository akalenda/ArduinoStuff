/**
 * When you run this program, it should periodically say
 * "Hello, world!" in the serial monitor.
 * 
 * But if you look at the motherboard (beneath the motor shield),
 * you should also see a blinking light.
 * 
 * That light is controlled by Pin #13. The digitalWrite function
 * tells a particular pin to switch from on to off, or from high
 * to low. So when we say, digitalWrite(13, HIGH), the electricity
 * starts flowing again in circuit 13, and the LED light turns on.
 */

void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}

void loop() {
  Serial.println("Hello, world!");
  digitalWrite(13, HIGH);
  delay(500);
  digitalWrite(13, LOW);
  delay(500);
}
