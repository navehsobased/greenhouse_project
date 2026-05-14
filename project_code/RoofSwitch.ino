void RoofSwitch(bool openToken) {
  if (openToken) {
    // פתיחת הגג
    dutyCycle = 2000;
    Serial.println("Opening roof...");
    ledcWrite(enable1Pin, dutyCycle);
    digitalWrite(motor1Pin1, LOW);
    digitalWrite(motor1Pin2, HIGH);
  } 

  else {
    // סגירת הגג
    dutyCycle = 150;
    Serial.println("Closing roof...");
    ledcWrite(enable1Pin, dutyCycle);
    digitalWrite(motor1Pin1, HIGH);
    digitalWrite(motor1Pin2, LOW);
  }
}