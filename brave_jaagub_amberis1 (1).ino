#define RED_PIN 13
#define YELLOW_PIN 12
#define GREEN_PIN 11

int vehicleCount;  // Simulated number of vehicles

void setup() {
  pinMode(RED_PIN, OUTPUT);
  pinMode(YELLOW_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);

  Serial.begin(9600); // vehicle count
}

void loop() {
  // Simulate vehicle density (0–10 vehicles)
  vehicleCount = random(0, 11); 
  Serial.print("Vehicle Count: ");
  Serial.println(vehicleCount);

  //  vehicle density
  int greenTime;
  if(vehicleCount >= 7){
    greenTime = 8000; // Heavy traffic → 8 sec
  } else if(vehicleCount >= 4){
    greenTime = 5000; // Medium traffic → 5 sec
  } else{
    greenTime = 3000; // Light traffic → 3 sec
  }

  // Red light ON
  digitalWrite(RED_PIN, HIGH);
  digitalWrite(YELLOW_PIN, LOW);
  digitalWrite(GREEN_PIN, LOW);
  delay(5000);

  // Green light ON (dynamic)
  digitalWrite(RED_PIN, LOW);
  digitalWrite(YELLOW_PIN, LOW);
  digitalWrite(GREEN_PIN, HIGH);
  delay(greenTime);

  // Yellow light ON
  digitalWrite(RED_PIN, LOW);
  digitalWrite(YELLOW_PIN, HIGH);
  digitalWrite(GREEN_PIN, LOW);
  delay(2000);
}