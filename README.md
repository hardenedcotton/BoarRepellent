# Boar Repellent
This project aims to use different sound effects to scare the invasive boars that roam in the dark hours in farming areas.

The system can be seen here (We used caulk to isolate terminals, secure boards and seal the cable hole for waterproofing):
![System](https://github.com/user-attachments/assets/047c9caa-d92c-49cc-b4a9-e2cdaea49fd2)

The system while working (Speaker is muffled on the couch due to loudness):
https://github.com/user-attachments/assets/0228eaed-50c0-4ad3-9799-def11d571db1

## Design
- The system is charged using a solar panel.
- The audio files are managed with an Arduino Uno and a DF Player Mini
- The output is amplified using a mono 30W amp and then played through a single 15W speaker.

</br>
The system is divided to two sub systems:

### 12V system:
This includes the:
- Speaker
- Amplifier
- Relay

### 5V system:
This includes the:
- Arduino
- DF Player Mini

## Processes
### Day time
During day time, the system only charges a 12V 12mAh lead-acid battery. This action is interfaced by a PWN BMU.
### Night time
In the night time, there are two phases:
#### Waiting Phase:
- After the sun sets, the BMU allows the load output to activate.
- The load output is then powers up a time relay and pulls the contacts. Which then counts down from 3 hours.
- The flasher LEDs turn on during this period alongside the relay. Which is to indicate the load output is active.
#### Working Phase:
- When the relay releases the contacts, the rest of the 5V system activates.
  - The arduino sends a signal every 60-80 seconds to play a random track.
  - The randow track signal is recieved by the DF Player Mini
  - The random track is then selected from the preloaded sound effects in the microSD Card
- This phase lasts until the solar panel gets enough sunlight or until the set time on the relay pulls the contacts again.

## Components:
- Orbus 12V 12mAh Lead-Acid Battery
- Gesper Energy 15W Watt Monocrystal Solar Panel 12V 36 Cells
- Lexron 12V/24V 10A PWM Charge Control Unit
- Arduino Nano Clone (CH340)
- DF Player Mini HW-247A
- TDA8932 Mono Digital Amplifier
- HCW-M421 Timer Module
- Magicvoice MV-30600 12V 15W Speaker
- 5mm Flasher RGB LED
