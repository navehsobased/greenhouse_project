void LCDscreen(bool LEDtoken, bool BulbToken, bool FanToken, int ldrv, int rainv, int humidv, float tempv, byte hour, byte minute, byte second) { //פונקציית הצגת הנתנוים על המסך
  //-------------------------
  lcd.setCursor(0, 0);
  lcd.print("Light:");
  lcd.print(ldrv);

  lcd.print(" | ");

  if (LEDtoken) {
    lcd.print("Led:on ");
  }
  else {
    lcd.print("Led:off");
  }
  //-------------------------
  lcd.setCursor(0, 1);
  lcd.print("Temp:");
  lcd.print(tempv, 1);
  
  lcd.print(" | ");

  if (rainv < 1000) {
    lcd.print("Rain:yes");
  }
  else {
    lcd.print("Rain:no ");
  }
  //-------------------------
  lcd.setCursor(0, 2);
  lcd.print("Humid:");
  lcd.print(humidv);

  lcd.print(" | ");

  if (FanToken) {
    lcd.print("Fan:on ");
  }
  else {
    lcd.print("Fan:off");
  }
  //-------------------------
  lcd.setCursor(0, 3);  
  if (BulbToken) {
    lcd.print("Bulb:on ");
  }
  else {
    lcd.print("Bulb:off");
  }

  lcd.print(" | ");

  lcd.print(hour);
  lcd.print(":");
  lcd.print(minute);
  lcd.print(":");
  lcd.print(second);
  //-------------------------
}