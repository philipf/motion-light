# motion-light

Simple relay switch controlled by a ATtiny85 when motion is detected.  
It has the following features:
- Reset the 'On' window with 20 seconds each time movement is detected.
- Override switch to disable the on/off logic if required.
- If the controller fails for whatever reason the relay will close.

## Special notes
The passive infra red (PIR) and the relay switch depicted in the diagram are assembled modules.
- The PIR module is similar to this http://imall.iteadstudio.com/im120628009.html
- The relay module similar to this https://www.pololu.com/product/2482.  A 5V would have result in a simpler circuit but I only had a 12V in stock.
- The relay switch should be connected in NC (normally closed) mode ensuring that the circuit is closed when the controller fails.

## Circuit diagram
![Image](../master/designs/Circuit/Circuit.png?raw=true)

## Stripboard
![Image](../master/designs/Stripboard/Stripboard.png?raw=true)

## Known issues:
- The current version of the relayLed is not working.  Measuring it with a volt meter shows an output of 1.7V.  I think it is because the LED pin is not set each time when loop() is run.
