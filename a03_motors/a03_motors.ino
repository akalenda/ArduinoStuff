int i;
int HI;
void setup()
{
  HI = HIGH;
  i = 0;
  pinMode(12, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(8, OUTPUT);
    
  if (i < 4) {
  // based on tutorial info at http://www.instructables.com/id/Arduino-Motor-Shield-Tutorial/step5/Two-Motors
      digitalWrite(8, HIGH);
      
      digitalWrite(12, HIGH); //forward A
      digitalWrite(9, LOW); //brake A off
      analogWrite(3, 255);  // full speed A
      delay(1000);
      digitalWrite(8, HIGH);
      analogWrite(11, 0); // speed 0 A
      digitalWrite(9, HIGH);  // brake on A
      delay(1000);
      digitalWrite(8, HIGH);
      digitalWrite(12, LOW);  //backward A
      digitalWrite(9, LOW); //brake A off
      analogWrite(11, 255); //full speed A
      delay(1000);
      digitalWrite(8, HIGH);
      analogWrite(11, 0); // speed 0 A
      digitalWrite(9, HIGH);  // brake A on
      delay(1000);
      ++i;
  }
}

void loop()
{
}
