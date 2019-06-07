# A Day That Will Never Happen Again
A rhythm generator that changes every day built from sounds recorded in a single day.
For more background about this instrument: http://www.impracticaldevices.com/volume-1/

How does it work?
There is a library of 123 sounds, each recorded on a single day in December 2018.
Each day, the software selects a subset of 10 of these sounds to play, and creates a number of randomised tables of data. These tables are used to organise the 10 selected sound into a repeating loop, with various parameters controlling how they are played. The potentiometers control the playback speed of the sequence, the length of the playback of each sample, the length of the sequence, and "other". The "other" knob controls four semi-randomised parameters at once, each of these being in turn controlled by a graph drawn from random slopes that are reset each day. The parameters are the chance of the sound being played back at each step, the range of pitch shifting, the range of volume randomisation, and the chance of the sound being played in reverse.

This instrument uses the following hardware:
- Raspberry Pi 3 Model B
- Mini RTC Module
- Teensy LC 
- 4 Potentiometers
- 1 LED
- 1 Switch

And the following software:
- Pure Data
- Zexy externals for Pure Data

Some notes on each of these...

Raspberry Pi:
This uses a Pi 3 B+, though a number of the other models would probably work just as well, namely the A+ or even the Zero. The instrument uses the built-in headphone output of the Pi for simplicity's sake, though this is something of a compromise. Using a separate sound card or hat (such as Pisound) would improve the overall sound quality.
The Pi runs the Pure Data (PD) patches to create all the sound. It uses the "date" object from the Zexy external library to create the unique sound patterns for each day.
In order to keep track of the date when no network is available, the Mini RTC module is attached to the Pi. I used this one:
https://thepihut.com/products/mini-rtc-module-for-raspberry-pi

Teensy LC:
This is used as a USB MIDI Controller, converting the four potentiometers and the switch into MIDI values sent via USB to the Raspberry Pi. It also converts MIDI note data from the Pi to turn the LED on when the patch is ready to make noise. The code for this is included in the repo.
Using a USB MIDI Controller with a Raspberry Pi used to be quite simple but for reasons I can not work out this has become oddly complicated. I used a system developed by the folks over at Blokas, which involves installing an autoconnect utility on the Pi, as described here: 
https://community.blokas.io/t/script-for-launching-pd-patch-with-midi-without-aconnect/1010

Potentiometers:
I use 1kΩ linear potentiometers with solder lugs, each with a .1µf capacitor for smoothing. These are the ones:
https://www.rapidonline.com/taiwan-alpha-rv16af-1k-linear-16mm-metal-case-solder-lug-potentiometer-65-0751
I connect the outer two pins to 3.3v and Ground on the Teensy LC, and the middle pin to the analog input pins (14,15,16,17).
The capacitor connects between the ground and middle pin of each potentiometer. 

LED:
This simply lights up when the patch is ready to play. 

Switch:
Any type of switch is suitable. I use a latching anti-vandal button. This starts and stops the playback.

Software:
To install Pure Data using the command line on the Raspberry Pi, simply type "sudo apt-get install puredata". This will install the latest version of Pure Data "vanilla". For these patches you will also need the Zexy library, which is installed with the command "sudo apt-get install pd-zexy".
