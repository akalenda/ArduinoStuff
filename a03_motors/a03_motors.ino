int i;

void setup()
{
    i = 0;
    pinMode(12, OUTPUT);
    pinMode(9, OUTPUT);
    pinMode(13, OUTPUT);
    pinMode(8, OUTPUT);
}

void loop()
{
  if (i < 4) {
  // based on tutorial info at http://www.instructables.com/id/Arduino-Motor-Shield-Tutorial/step5/Two-Motors
  digitalWrite(12, HIGH); //forward A
  digitalWrite(13, HIGH); //forward B
  digitalWrite(9, LOW); //brake A off
  digitalWrite(8, LOW); //brake B off
  analogWrite(3, 255);  // full speed A
  analogWrite(11, 255); // full speed B
  delay(3000);
  analogWrite(11, 0); // speed 0 A
  analogWrite(3, 0);  // speed 0 B
  digitalWrite(8, HIGH);  // brake on A
  digitalWrite(9, HIGH);  // brake on B
//  delay(1000);
  digitalWrite(12, LOW);  //backward A
  digitalWrite(13, LOW);  //backward B
  digitalWrite(9, LOW); //brake A off
  digitalWrite(8, LOW); //brake B off
  analogWrite(11, 255); //full speed A
  analogWrite(3, 255);  // full speeed B
  delay(3000);
  analogWrite(11, 0); // speed 0 A
  analogWrite(3, 0);  // speed 0 B
  digitalWrite(9, HIGH);  // brake A on
  digitalWrite(8, HIGH);  // brake B on
  delay(1000);
  ++i;
  }
}
