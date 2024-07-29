# litter-robot3_motor_control_arduinoR4

Do you have a litter robot 3 (connect or open air) with sensor issue, i.e. sphere not moving for all sorts of reasons, but still have a working motor (https://litter-robot.com/litter-robot-3-motor-assembly.html)? 

Well, you are in luck cuz i want to show you how you can build a motor driver that can be remote control by a web app thanks to the power of arduino R4 wifi.

You litter-robot 3 have three sensor/fail-safe built in:

  -Cat sensor (https://litter-robot.com/litter-robot-3-motor-assembly.html) : This is a pressure sensor that measure how much weight is in the machine to know whether your cat just release itself or still inside to trigger the cleaning movement.
  
  -Pinch and DFI sensor (https://www.litter-robot.com/lr3-pinch-contact-dfi-kit.html) : This is to sense whether the litter bin is full or your cat/random stuff got stuck to the weight bin opening. 
  
  -Blue LED inside Bonnet: This is the blue led light you can see when lights off so your cat can see better at night (well i don't think my cat need it tbh....)

It all sounded really good as these three system make sure that your cat is not going to be stuck in the litter robot and it is not going to move if the bin is full or too much litter added. The problem is that all those three thing can be damaged as years go. The litter robot company believe that if any of those three thing broke then the robot is not gonna to move even when you have a perfectly good motor and you can manuelly make sure those problem are not there....... Well if this is not planned obsolescence then i dont know what it is.  For me the big one i cant really fix is the weight sensor and i can't really calibrate my way out of it. 

There are some tutorials online about how to fix each sensor like these: 
https://www.youtube.com/watch?v=n3BnZOcWR54 Weight Sensor Tutorial
https://www.youtube.com/watch?v=k7fGvQjg8uE&t=541s Pinch sensor By Pass
But at some point it could be challenging to exactly fixes those thing. 

So, why not just control/drive the motor yourself. You can easily setup a camera to watch the litter robot so no cat can be hurt in the process as litter robot company was intented. 

You need:

  Arudino UNO R4 WIFI (Any Arduino with WIFI module would work)
  
  12V Power Supply
  
  L298n Motor Driver 
  
  Arduino Cloud Free Account (This is for easier deployment of a web app)

For the L298n driver, it require power for the 12V GND pin from the 12V power supply and a logic signal on whether channel A or B depending whether you wire the motor to the top terminal or the lower one. Basically the control signal from your arduino control the motor movement. For code showing here i wire the digital output 2, 3 to the L298n control. 
![Alt text](https://m.media-amazon.com/images/I/71rrEdpUD+L._SX522_.jpg)

On the arduino side, it served esstenially as two buttom, a Go/Stop Switch and a Left/Right Switch. If the Go switch is on then the litter motion start in the direction you choose. Check the .ino file for more details.

The easiest way to deploy this project is to utilize the arudino cloud hosting with a template .tino file i included here.


<img width="264" alt="image" src="https://github.com/user-attachments/assets/6feb0ae6-35d4-40e8-9624-6df23f54fbc6">

Go to the Arduino cloud Templates tab

<img width="1632" alt="image" src="https://github.com/user-attachments/assets/1e441e7f-8bc0-4133-be7b-d2661aca996f">

Import the .tino file manuelly, then plug in your R4 wifi borad, follow the setup process. You would need to change add your wifi information to network in "Things" tab setup to to connect R4 to your wifi. 

<img width="1914" alt="image" src="https://github.com/user-attachments/assets/121ef1a5-658a-4857-ba5d-19becc713265">

After all setup with power provided and all wires attached, you can control your litter robot in the web app in "Dashborad" as shown here. This also works on your phone if you install the Arduino IOT app and log in to your account.  


###You can also modified the .ino file to make this work only in your local network, like you have to go to "192.168.x.x" to control the litter robot. I choosed arduino cloud so i dont have to deal with all tunneling issue. 



