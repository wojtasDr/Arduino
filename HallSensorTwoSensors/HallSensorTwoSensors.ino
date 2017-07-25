word revolutions1 = 0;
word revolutions2 = 0;
unsigned long lastmillis = 0;
char startStop;

void setup()
{
  Serial.begin(9600);
  pinMode(3, INPUT_PULLUP);
  pinMode(7, INPUT_PULLUP);
  attachInterrupt(0, incrementRevolutions1, FALLING);
  attachInterrupt(4, incrementRevolutions2, FALLING);
}

void loop()
{
  if (Serial.available())  {
    startStop = Serial.read();
  }

  if (startStop == 'T') {
    if (millis() - lastmillis == 1000 || millis() - lastmillis == 1001){
        detachInterrupt(0);
        detachInterrupt(4);
        
        Serial.print("SR:");
        Serial.print(revolutions1); 
        Serial.print(",");
        Serial.println(revolutions2); 
        
        revolutions2 = 0; 
        revolutions1 = 0; 
        
        lastmillis = millis(); 

        attachInterrupt(0, incrementRevolutions1, FALLING);
        attachInterrupt(4, incrementRevolutions2, FALLING);

    }else if (millis() - lastmillis > 1001) {
        Serial.println(millis() - lastmillis);
    }
  } else {
    lastmillis = millis();
    revolutions2 = 0;
    revolutions1 = 0;
  }
}

void incrementRevolutions1()
{
  revolutions1++;
}

void incrementRevolutions2()
{
  revolutions2++;
}
