# Passive brake light  :uk:

Passive brake light for :bicyclist: bicycle use an arduino with the adxl345 sensor.  

I use arduino promini powered from 1 cell of lithium battery from old smartphone and 2 blocks with 3 red leds from some navigation lamp.  

### How it works?
When the acceleration is greater than or equal to zero, the LEDs blink slowly alternately :rotating_light:, when the bike decelerates they begin to blink more often and are constantly lit when the deceleration reaches 0.1G*

:triangular_flag_on_post:  
\* You may have to choose your own range values of "G" for the device to work correctly.

# Бесконтактный стоп-сигнал :ru:  

Бесконтактный стоп-сигнал для :bicyclist: велосипеда на Ардуино с датчиком adxl345.  

Для проекта использовалась плата ProMini с питанием от батареи старого смартфона, светодиоды из неисправной лампы для огней светоограждения типа "Пермь"

### Как это работает   
При ускорении либо движении с постоянной скоростью светидиоды медленно попеременно мигают :rotating_light: , при замедлении мигание становится чаще,в случае если значение замедления стало больше или равно 0,1G* Светодиоды светятся постоянно. 
:triangular_flag_on_post:  
\* Для того чтобы ваше устройство работало корректно возможно вам прийдется подобрать собственное значение "G".
