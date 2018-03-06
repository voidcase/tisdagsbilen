#include <RH_ASK.h>
#include <Button.h>
#define FWPIN 2
#define BWPIN 3
#define RAJTPIN 6
#define LTPIN 5

uint8_t FWCODE = 122;
uint8_t BWCODE = 221;
uint8_t RTCODE = 1;
uint8_t LTCODE = 100;
uint8_t STOPCODE = 0;


RH_ASK driver;

Button fwbtn = Button(FWPIN, PULLUP);
Button bwbtn = Button(BWPIN, PULLUP);
Button rtbtn = Button(RAJTPIN, PULLUP);
Button ltbtn = Button(LTPIN, PULLUP);

void setup() {
	Serial.begin(9600);
	if (!driver.init()) {
		Serial.println("init failed");
	}
	pinMode(FWPIN, OUTPUT);
	pinMode(BWPIN, OUTPUT);
	pinMode(RAJTPIN, OUTPUT);
	pinMode(LTPIN, OUTPUT);

}

/* void snd(uint8_t code, ) */

void loop() {
	if (fwbtn.isPressed()) {
		Serial.println("FWCODE");
		driver.send(&FWCODE, 1);
		driver.waitPacketSent();
	} else if (bwbtn.isPressed()) {
		Serial.println("BWCODE");
		driver.send(&BWCODE, 1);
		driver.waitPacketSent();
	} else if (rtbtn.isPressed()) {
		Serial.println("RTCODE");
		driver.send(&RTCODE, 1);
		driver.waitPacketSent();
	} else if (ltbtn.isPressed()) {
		Serial.println("LTCODE");
		driver.send(&LTCODE, 1);
		driver.waitPacketSent();
	} /*else {
		driver.send(&STOPCODE, 1);
		driver.waitPacketSent();
	}*/
}
