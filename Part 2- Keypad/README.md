# Keypad

## Keypad Library
![keypad](https://user-images.githubusercontent.com/32713072/36920534-6af87bbc-1e7a-11e8-8fd7-a7445af125d6.PNG) <br/>
Keypad is a library for using matrix style keypads with the Arduino. As of version 3.0 it now supports mulitple keypresses. <br/>
It was created to promote Hardware Abstraction. It improves readability of the code by hiding the pinMode and digitalRead calls for the user.
You won't need external resistors or diodes because the library uses the internal pullup resistors and additonally ensures that all unused column pins are high-impedance.

## Description of the module 
![keypad circuit](https://user-images.githubusercontent.com/32713072/36920262-9a6b8d22-1e79-11e8-8281-b189b924ac0a.png) <br/>

Typically one port pin is required to read a digital input into the controller. When there are a lot of digital inputs that have to be read, it is not feasible to allocate one pin for each of them. This is when a matrix keypad arrangement is used to reduce the pin count.
Therefore, the number of pins that are required to interface a given number of inputs decreases with increase in the order of the matrix.




