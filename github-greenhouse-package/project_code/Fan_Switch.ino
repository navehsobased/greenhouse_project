void fanSwitch(float tempval) { //פונקציית הדלקה וכיבוי המאוורר
  if (tempval > 26.0) {
    digitalWrite(fanPin, LOW);
    FanToken = true;
  }
  else {
    digitalWrite(fanPin, HIGH);
    FanToken = false;
  }
}