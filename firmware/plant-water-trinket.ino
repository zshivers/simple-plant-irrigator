// palm, living room
const unsigned long watering_time_sec = 120ul;
const unsigned long watering_period_hours = 72ul; // 3 days

// ferns, bathroom
//const unsigned long watering_time_sec = 120ul;
//const unsigned long watering_period_hours = 24ul;

#define SEC_TO_MS(S)    ((S)*1000ul)
#define HOURS_TO_MS(H)  ((H)*1000ul*60ul*60ul)

const unsigned long watering_time = SEC_TO_MS(watering_time_sec);
const unsigned long watering_period = HOURS_TO_MS(watering_period_hours) - watering_time;

#define PUMP_PIN 0
#define LED_PIN 1

void setup() {
  pinMode(PUMP_PIN, OUTPUT);
  pinMode(LED_PIN,  OUTPUT);
  digitalWrite(PUMP_PIN, LOW);
  digitalWrite(LED_PIN,  LOW);
}

void loop() {
  while(1) {
    pump_on();
    delay(watering_time);
    pump_off();
    delay(watering_period);
  }
}

void pump_on() {
    digitalWrite(PUMP_PIN, HIGH);
    digitalWrite(LED_PIN,  HIGH);
}

void pump_off() {
    digitalWrite(PUMP_PIN, LOW);
    digitalWrite(LED_PIN,  LOW);
}
