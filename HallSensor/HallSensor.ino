word revolutions = 0;
unsigned long lastmillis = 0;
unsigned long measurementCounter = 0;
float velocity = 0;
float velocityAvg = 0;
void setup()
{
  Serial.begin(9600);
  pinMode(3, INPUT_PULLUP);
  attachInterrupt(0, incrementRevolutions, FALLING);
}

void loop()
{
  if (millis() - lastmillis == 1000){
    detachInterrupt(0);

//    velocity = revolutions *2.1 * 3.6;
//    
//    if(measurementCounter  > 10){
//      measurementCounter = 1;
//    }
//
//    if(velocity !=0){
//      measurementCounter++;
//
//      velocityAvg = (velocityAvg + velocity) / measurementCounter;
//    }
    Serial.print("S1:");
    Serial.println(revolutions); 
   // Serial.write(revolutions);
   // Serial.write("\n");
//    Serial.print("\t V[km/h]=\t");
//    Serial.print(velocity); 
//    Serial.print("\t MCounter=\t");
//    Serial.print(measurementCounter); 
//    Serial.print("\t Vacg[km/h]=\t");
//    Serial.println(velocityAvg); 
    
//    velocity = 0;
    revolutions = 0; // Restart the RPM counter
    lastmillis = millis(); // Uptade lasmillis

    attachInterrupt(0, incrementRevolutions, FALLING);
  }
}

void incrementRevolutions()
{
  revolutions++;
}
