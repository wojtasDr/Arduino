void setup() {
  // put your setup code here, to run once:
  pinMode(8, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(8, HIGH); //Włączenie diody
  delay(1000); //Odczekanie 1 sekundy
  digitalWrite(8, LOW); //Wyłączenie diody
  delay(1000); //Odczekanie jednej sekundy
}
