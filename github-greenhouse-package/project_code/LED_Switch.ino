void LEDswitch(int light) { //פונקציה של הדלקה וכיבוי האורות לפי ldr
  if (light < 1900) {
    for (int i = 0; i < NUM_LEDS; i++){
    strip.setPixelColor(i,strip.Color(0, 0, 255));
    }
    strip.show();
    LEDtoken = true;
  }
  else {
    for (int i = 0; i < NUM_LEDS; i++){
    strip.setPixelColor(i,strip.Color(0, 0, 0));
    }
    strip.show();
    LEDtoken = false;
  }
} 