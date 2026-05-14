int rainRead() { //פונקציה קריאה מחיישן הגשם
  rainval = analogRead(rainPin);
  return(rainval);
}