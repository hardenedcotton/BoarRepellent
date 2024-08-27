#include <SoftwareSerial.h>
#include <DFRobotDFPlayerMini.h>

SoftwareSerial mySoftwareSerial(10, 11);  // RX, TX
DFRobotDFPlayerMini myDFPlayer;

const int TOTAL_FILES = 9;
const int BUSY_PIN = 5;

int randomWaitTime(int secStart, int secEnd) {
  return random(secStart, secEnd);
}

int randomTrackNumber(int totalFiles) {
  return random(1, totalFiles + 1);
}


void setup() {
  mySoftwareSerial.begin(9600);
  Serial.begin(9600);

  if (!myDFPlayer.begin(mySoftwareSerial)) {
    Serial.println("DFPlayer Mini not found!");
    while (true);
  }

  Serial.println("DFPlayer Mini online.");
  myDFPlayer.setTimeOut(500);
  myDFPlayer.volume(30);  // (0 to 30)
  myDFPlayer.EQ(DFPLAYER_EQ_NORMAL);
  myDFPlayer.outputDevice(DFPLAYER_DEVICE_SD);
  randomSeed(analogRead(0));
}

void loop() {
  bool isPlayerAvailable = digitalRead(BUSY_PIN);  // Read the state of the BUSY pin
  
  if (isPlayerAvailable == HIGH) {  // HIGH means not playing
    int trackNumber = randomTrackNumber(TOTAL_FILES);
    myDFPlayer.play(trackNumber);
    Serial.print("Playing track: ");
    Serial.println(trackNumber);


    while (digitalRead(BUSY_PIN) == LOW) {
      // Do nothing, wait for the track to finish playing
    }

    // Once the track has finished, wait for a random interval
  }
  int waitTime = randomWaitTime(20, 60);
  Serial.print("Waiting for ");
  Serial.print(waitTime);
  Serial.println(" seconds before playing the next track.");
  delay(waitTime * 1000);
}
