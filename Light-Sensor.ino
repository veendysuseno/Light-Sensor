/* Sensor Cahaya,
LED menyala pada kondisi lingkungan Gelap,dan padam bila kondisi lingkungan terang
 */

const int pinLDR = 0;//Inisialisasi SensorLDR  pin analog 0  
const int pinLED = 8;//inisialisasi LED pada pin 8 
int sensorValue = 0;// inisialisasi nilai terbaca di sensor
int outputValue = 0;// penskalaan nilai sensor 
void setup() {
}
void loop() {
	sensorValue = analogRead(pinLDR); // baca nilai sensor:
	// penskalaan nilai sensor (0-1023) mnjdi nilai output (0-500)
	outputValue = map(sensorValue, 0, 1023, 0, 500);
	// deteksi, jika nilai OutputValue <=300, kondisi redup/gelap
	if(outputValue <= 300)
		digitalWrite(pinLED, HIGH); // ON-kan LED
	else 
		digitalWrite(pinLED, LOW); // OFF-kan LED
	delay(200);
}
