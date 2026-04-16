
const int MOSFET_GATE_PIN = 9;   

const float FREQUENCY_HZ    = 1.0;   
const float DUTY_CYCLE_PCT  = 20.0; 


const unsigned long PERIOD_MS   = (unsigned long)(1000.0 / FREQUENCY_HZ);
const unsigned long ON_TIME_MS  = (unsigned long)(PERIOD_MS * DUTY_CYCLE_PCT / 100.0);
const unsigned long OFF_TIME_MS = PERIOD_MS - ON_TIME_MS;


const int LED_PIN = 13;  

void setup() {
  pinMode(MOSFET_GATE_PIN, OUTPUT);
  pinMode(LED_PIN,         OUTPUT);

  digitalWrite(MOSFET_GATE_PIN, LOW);
  digitalWrite(LED_PIN,         LOW);

  Serial.begin(9600);
  Serial.println("Fuel Injector Driver Ready");
  Serial.print("Frequency  : "); Serial.print(FREQUENCY_HZ);  Serial.println(" Hz");
  Serial.print("Period     : "); Serial.print(PERIOD_MS);      Serial.println(" ms");
  Serial.print("ON  time   : "); Serial.print(ON_TIME_MS);     Serial.println(" ms");
  Serial.print("OFF time   : "); Serial.print(OFF_TIME_MS);    Serial.println(" ms");
  Serial.print("Duty cycle : "); Serial.print(DUTY_CYCLE_PCT); Serial.println(" %");
  Serial.println("=====================================");

  delay(1000);  
}

void loop() {
  
  digitalWrite(MOSFET_GATE_PIN, HIGH);
  digitalWrite(LED_PIN,         HIGH);
  Serial.print("INJECTOR HAS OPENED  | t = ");
  Serial.print(millis());
  Serial.println(" ms");

  delay(ON_TIME_MS);

  digitalWrite(MOSFET_GATE_PIN, LOW);
  digitalWrite(LED_PIN,         LOW);
  Serial.print("    INJECTOR CLOSED | t = ");
  Serial.print(millis());
  Serial.println(" ms");

  delay(OFF_TIME_MS);
}
