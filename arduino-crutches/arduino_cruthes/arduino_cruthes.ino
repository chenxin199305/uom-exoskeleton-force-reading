void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);  
  Serial.print("Arduino Nano Setup \n");
}

void loop() {
  // put your main code here, to run repeatedly:

  // read ADC0
  int adc0_value = analogRead(A0);
  float voltage_value = adc0_value * (5.0f / 1024.0f);
  Serial.print("adc0_value = ");
  Serial.print(adc0_value);
  Serial.print("\n");
  Serial.print("voltage_value = ");
  Serial.print(voltage_value);
  Serial.print("\n");

  // delay 1s
  delay(1000);
}
