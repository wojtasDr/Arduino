
void setup(){
  Serial.begin(115200); //Ustawienie prędkości transmisji
  Serial.println("Hello!"); //Jednorazowe wysłanie tekstu
}
void loop() {
  delay(1000);
  Serial.println("Minelo 5 sekund!"); //Wysyłanie w pętli
}
