int humidRead () { //קריאה מחיישן לחות האדמה
  humidVal = analogRead(HumidPin);
  return (humidVal);
}