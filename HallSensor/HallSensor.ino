word revolutions = 0;
unsigned long lastmillis = 0;
unsigned long measurementCounter = 0;
float velocity = 0;
float velocityAvg = 0;
char startStop;
void setup()
{
  Serial.begin(9600);
  pinMode(3, INPUT_PULLUP);
  attachInterrupt(0, incrementRevolutions, FALLING);
}

void loop()
{
  if (Serial.available())  {
    startStop = Serial.read();
  }

  if (startStop == 'T') {
    if (millis() - lastmillis == 1000 || millis() - lastmillis == 1001){
        detachInterrupt(0);

        Serial.print("S1:");
        Serial.println(revolutions); 

        revolutions = 0; // Restart the RPM counter
        lastmillis = millis(); // Uptade lasmillis

        attachInterrupt(0, incrementRevolutions, FALLING);
    }else if (millis() - lastmillis > 1000) {
        Serial.println(millis() - lastmillis);
    }
  } else {
    lastmillis = millis();
  }
}

void incrementRevolutions()
{
  revolutions++;
}
