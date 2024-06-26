// Arduitronics.com
long phTot;
float phAvg;
int i;

float m = (7-9.18)/(563-513); // Slope of straight line (Y = mx + C)
float C = 7-m*(563); //Constant of straight line (Y = mx + C)

void setup() {
  Serial.begin(9600);
}
void loop() {
  phTot = 0;
  phAvg = 0;
  
  //taking  50 samples
  for(i=0; i<50 ; i++)
  {
    phTot += analogRead(A0);
    delay(10);
  }  
  float phAvg = phTot/50;
  float pHValue = phAvg*m+C;
   
  Serial.print("phVoltage = ");
  Serial.print(phAvg);
  Serial.print(" ");
  Serial.print("pH=");
  Serial.println(pHValue);
  delay(1000);
}
