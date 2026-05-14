void BulbSwitch(float tempval) { //פונקצייה להדלקת נורת חימום
  if (tempval < 23.0) {
    digitalWrite(bulbPin, LOW);
    BulbToken = true;
  }
  else {
    digitalWrite(bulbPin, HIGH);
    BulbToken = false;
  }
}