particle-photon-testing-curcuit
####################

USE AT YOUR OWN RISK!

Making a Particle-Photon-Testing breadboard and perhaps a PCB to go along with it.

Follow the blog at https://community.particle.io/t/photon-test-breakout-board/33222


Update June14, 2017
Looks like the serial Master and Slave Photon testing of uART, I2C and SPI serial communication is working. Note that it has to run a coupple of loops until it has tested both way communication.

update June 13, 2017

Just started working on the full photon master slave uART, I2C, SPI check breadboard

![](photon-master-slave01-02.png)

Still have to include SPI in the main programs.

Update June 10th, 2017

The Photon master and slave is working for I2C and uART. I am having trouble with SPI in finding good example code. Note that for both I2C and uART I have found a way to read Strings as Strings not char arrays hopefully making things as simple as possible for my students. Not sure if I will be able to do the same for SPI.

The photon-alone.ino is ready to go. Steps through every Photon GPIO pin and tests it against the neighboring pin or DAC pin. I hope to make a PCB board but if you can't wait you can wire up the breadboard below.

![](photon-alone.png)






Note: Use at your own risk, presently this software runs with a fully working Photon, no idea what it will do with a photon with a broken GPIO pin!


...


Update June 6, 2017

Gave up on the LED's, Peekay123 made the suggestion to test PWM using pulseIn() works great, so expanding the DAC pins to test all analogReads. See his repositories at https://github.com/pkourany


Update June 4, 2017

Now working on AnalogWrite PWM to an analogRead using an LED and photoresitor. Will need to think through the fuzzy logic to be able to test if it is working since light levels may be different using diffrerent LED's


Got DACs working set DAC variable voltage to analogReads to test 3 levels 1000, 2000, 3000 with a little fuzzy logic to see if they were correct.



Started Jun 2, 2017

Got digital input and outputs all working byu connecting every pin together and setting all of them to inputs until one at a time set to output.
