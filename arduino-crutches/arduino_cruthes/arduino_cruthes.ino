void setup() {
  Serial.begin(115200);  
}

void loop() {
  // read ADC0
  int adc0_value = analogRead(A0);
  float voltage_value = adc0_value * (5.0f / 1024.0f);
  Serial.print(voltage_value);
  Serial.print("\n");

  // delay 10ms
  delay(10);
}
