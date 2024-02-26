# Passive brake light  

Passive brake light for bicycle use an arduino with the adxl345 sensor.  

I use arduino promini powered from 1 cell of lithium battery from old smartphone and 2 blocks with 3 red leds from some navigation lamp.  

### How it works?
When the acceleration is greater than or equal to zero, the LEDs blink slowly alternately, when the bike decelerates they begin to blink more often and are constantly lit when the deceleration reaches 0.1G*

*You may have to choose your own range values of "G" for the device to work correctly.
