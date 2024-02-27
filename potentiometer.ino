
//gpio pin 39 for ldr
//gpio pin 34 for lm35
//gpio pin 35 for analog sensor
//pgio pin 36 for potentiameter

const int micPin = 36

.; // Analog pin connected to the microphone output
int micValue = 0;      // Variable to store the microphone value

void setup() {
  Serial.begin(9600);
  pinMode(micPin, INPUT);
}

void loop() {
  // Read the microphone value from the analog pin
  micValue = analogRead(micPin);

  // Print the microphone value to the Serial Monitor
  Serial.print("Microphone Value: ");
  Serial.println(micValue);

  delay(500); // Add a small delay to avoid flooding the Serial Monitor
}
