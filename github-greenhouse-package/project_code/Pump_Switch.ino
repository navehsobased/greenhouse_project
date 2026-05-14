void PumpSwitch(int humidVal, int rainval, byte hour, byte minute) {
  static bool pumpStarted = false;
  
  if ((humidVal < 2700) && ((hour == 8) || (hour == 22)) && (minute == 0) && !pumpStarted) {
    
    if (rainval < 1000) {
      Serial.println("Watering with rain");
      RoofSwitch(true);  // פתיחת הגג
      pumpStarted = true;
    }
    else {
      // ☀️ אין גשם - צריך להשתמש במשאבה
      Serial.println("watering with pump");
      digitalWrite(PumpPin, HIGH);
      pumpStarted = true;
    }
  }
  
  if (pumpStarted && ((hour == 8) || (hour == 22)) && (minute == 1)) {
    digitalWrite(PumpPin, LOW);
    RoofSwitch(false);  // סגור את הגג
    pumpStarted = false;
    Serial.println("pump turned off");
  }
  
  // איפוס בחצות
  if (hour == 0 && minute == 0) {
    digitalWrite(PumpPin, LOW);
    RoofSwitch(false);
    pumpStarted = false;
  }
}