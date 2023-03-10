//Mi medidor de distancia
const int trigPin= 18;
const int echoPin= 5;
//define soundspeedin cm/uS
#define SOUND_SPEED 0.034
#define CM_TO_INCH 0.393701
long duration;
float distanceCm;
float distanceInch;

void setup() {
    Serial.begin(9600); // Startstheserial communication
    pinMode(trigPin, OUTPUT); // Sets thetrigPinas anOutput
    pinMode(echoPin, INPUT); // Sets theechoPinas anInput
}

void loop() {
    // Clears the trigPin
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    // Sets the trigPin on HIGH state for 10 micro seconds
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    // Reads the echoPin, returns the sound wave travel time in microseconds
    duration = pulseIn(echoPin, HIGH);
    // Calculatethedistance
    distanceCm = duration*SOUND_SPEED/2;
    // Converttoinches
    distanceInch = distanceCm*CM_TO_INCH;
    // Printsthedistancein theSerial Monitor
    // Serial.print("Distance(cm): ");
    Serial.println(distanceCm);
    // Serial.print("Distance(inch): ");
    // Serial.println(distanceInch);
    delay(500);
}