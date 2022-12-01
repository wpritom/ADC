void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}
float val;

void loop() {
  // put your main code here, to run repeatedly:
  val = analogRead(A2);
  Serial.println(val);
  delay(400);
}
