const int sensorPin = A0;
const float baselineTemp = 25.0;

void setup() {
        Serial.begin(9600);

        for(int p = 2 ; p < 5 ; ++p) {
                pinMode(p, OUTPUT);
                digitalWrite(p, LOW);
        }
}

void loop() {
        int sensorVal = analogRead(sensorPin);
        Serial.print("Sensor Value: ");
        Serial.print(sensorVal);

        float voltage = (sensorVal/1024.0) * 5.0;
        Serial.print(", Volts: ");
        Serial.print(voltage);

        Serial.print(", degrees C: ");
        float temperature = (voltage - .5) * 100.0;
        Serial.println(temperature);

        if(temperature < baselineTemp) {
                digitalWrite(2, LOW);
                digitalWrite(3, LOW);
                digitalWrite(4, LOW);
        } else if(temperature >= baselineTemp+2 && temperature <= baselineTemp+4) {
                digitalWrite(2, HIGH);
                digitalWrite(3, LOW);
                digitalWrite(4, LOW);
        } else if(temperature >= baselineTemp+4 && temperature <= baselineTemp+6) {
                digitalWrite(2, HIGH);
                digitalWrite(3, HIGH);
                digitalWrite(4, LOW);
        } else {
                digitalWrite(2, HIGH);
                digitalWrite(3, HIGH);
                digitalWrite(4, HIGH);
        }

        delay(1);
}
