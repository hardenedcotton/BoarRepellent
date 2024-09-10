# Boar Repellent
This project aims to use different sound effects to scare the invasive boars that roam in the dark hours in farming areas.

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
