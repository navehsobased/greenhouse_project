void RTCtime() {
  DateTime now = rtc.now();
  second = now.second();
  minute =now.minute();
  hour = now.hour();
}