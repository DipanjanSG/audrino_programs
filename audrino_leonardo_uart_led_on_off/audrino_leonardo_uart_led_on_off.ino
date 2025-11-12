void setup() {
  Serial1.begin(9600); 
}

void loop() {
  Serial1.println("ON");   
  delay(3000);

  Serial1.println("OFF");
  delay(3000);
}
