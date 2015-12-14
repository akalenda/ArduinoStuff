void setup() {
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    char ch = Serial.read();
    Serial.print("Recieved: ");
    Serial.println(ch);
  }
//  Serial.println("Hello, world!");
//  delay(1000);
}
