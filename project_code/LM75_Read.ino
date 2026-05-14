float tempRead() { //פונקציה קריאה מחיישן הטמפרטורה
  Wire.beginTransmission(LM75_ADDR);
  Wire.write(0x00);
  Wire.endTransmission();

  Wire.requestFrom(LM75_ADDR, 2);
  msb = Wire.read();
  lsb = Wire.read();

  raw = ((msb << 8) | lsb);
  raw >>= 7;
  tempval = raw * 0.5;
  return(tempval);
}