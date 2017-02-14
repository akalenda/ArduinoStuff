/**
 * Connect the data cable to the Arduino and your computer.
 * Open the Arduino IDE after downloading and installing it.
 * From the menu, select Tools > Serial Monitor
 * Now click the Upload button (arrow pointing right at the top).
 * You should see "Hello, world!" in the serial monitor.
 * Now click on the field in the serial monitor that lets you enter text,
 * and send something to the Arduino. It should echo back.
 */

void setup() {
  Serial.begin(9600);
  Serial.println("Hello, world!");
}

void loop() {
  if (Serial.available() > 0) {
    char ch = Serial.read();
    Serial.print("Recieved: ");
    Serial.println(ch);
  }
}
