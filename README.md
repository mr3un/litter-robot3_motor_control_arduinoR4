# litter-robot3_motor_control_arduinoR4
What should i do?
![IMG_6104](https://github.com/user-attachments/assets/ea73822f-2f85-48e7-8eb8-fefe3342336e)
![IMG_6083 (2)](https://github.com/user-attachments/assets/1c10cd64-80f5-43e3-817d-df9cb1d55945)

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

  Arudino UNO R4 WIFI (Any Arduino with WIFI module would work) - https://www.amazon.com/Arduino-UNO-WiFi-ABX00087-Bluetooth/dp/B0C8V88Z9D/ref=sr_1_5?dib=eyJ2IjoiMSJ9.6-55ZkgVCQpz5t-A9OQ_Ig9Y7KdmzoFCl5dBdjSQZO5gwGcdtxRWubPgPzFcMTYiD_x_t1BC_T1cC5xX2n7YKV8Rc44YpQn5EEB1gDi07pI3xNfF-kKRxvddOfJwdT7AbDktHN9SyRmGzP82FSXPCcL33GqJ6HqPScQIATo-ihn9EOCiUCIKpnHRmeKQopqlt8CaHDJiBZQA2DBwgw7CPGfXcJvXEMuUM42KX99QqH8ikvuI432zAUdpyG07Y_gYb0mRtzIuD_hsqf1QWPkD8G1JMVgqk6453BIZJXQMpXs.fYr0hVb75T1tcqKcN5q75z1OGOh_lYXleReIq3WpN1Q&dib_tag=se&keywords=arduino+r4+wifi&qid=1722267641&sr=8-5
  
  12V Power Supply - https://www.amazon.com/Adapter-100-240V-Transformer-Charger-Security/dp/B091XSVV1Y/ref=sr_1_9?crid=1Y2XMHWP22OMK&dib=eyJ2IjoiMSJ9.hfVvVsJ0kMTmlJR24sRzRNMPJtBhVbHyKIiAVcF25u-ZRIm4OJxO0hfjfoZ2nPVBaUijinuwJ9UQklKBW_OAp0SqLQ7HboU3fBUweyAtXIYGtBqrS36LKMXDlGJzUU3HmxNIJeo1w5Q2im-Fl3nGxwSzWzY1FYILcReKyGML_AtvwbDNSukErHc3m7E_tuIktVnAMKQ2YXuJ7d9VGuzW5Db6KtjlBYI72OckYMcDwD-FUETsz375uhthPU4bCGRqEjF4XSYb1DPRIlVXqESbZF8yiFxtOv_2SticygjvzOw.nhir2BZ61eI-xycc33Ytdn4V_Q6p9YTR6g8L6SKpU7Q&dib_tag=se&keywords=12v+power+supply&qid=1722267657&sprefix=12v%2Caps%2C90&sr=8-9
  
  L298n Motor Driver -https://www.amazon.com/WWZMDiB-L298N-H-Bridge-Controller-Raspberry/dp/B0CR6BX5QL/ref=sr_1_6?crid=21B1CG1GVXOYK&dib=eyJ2IjoiMSJ9.hK2FjV8Ukp8CCyVTI1seMk4n3aguoO_lNXX3xoiH-O38t-On6SSb-8za6hi423P24Clvvz-QC0YIK6ixOCNOO_1PeZwvJA1tepbuO9DRpiM-tbhuugF6939ckXhQRGOrmdZpEHuade01KDDpsvZmRfP4zOnVQq-8oT6Uwx-oqRyqW0jX5-2DnmUPtWHraDXvDEzP6e8vY851mmDS4TbTuW-msTN_uDQ32cnkmjol3pw9jpYKwW26Cw5FAU_Z7l0nvbDYdX9drjNoHvGiEYQQvGSEv_XSJ40wIbpOPR-_ir8.62cw2VniBTsOKjMMO2-85EUO3OFIAExSg-r1hrW4hTw&dib_tag=se&keywords=l298n&qid=1722267680&sprefix=l29%2Caps%2C88&sr=8-6
  
  Arduino Cloud Free Account (This is for easier deployment of a web app) - https://cloud.arduino.cc/

  These cost around ~50 bucks on amazon US. 

![Alt text](https://m.media-amazon.com/images/I/71rrEdpUD+L._SX522_.jpg)

For the L298n driver, it require power for the 12V GND pin from the 12V power supply and a logic signal on whether channel A or B depending whether you wire the motor to the top terminal or the lower one. Basically the control signal from your arduino control the motor movement. For code showing here i wire the digital output 2, 3 to the L298n control. 


On the arduino side, it served esstenially as two buttom, a Go/Stop Switch and a Left/Right Switch. If the Go switch is on then the litter motion start in the direction you choose. Check the .ino file for more details.

The easiest way to deploy this project is to utilize the arudino cloud hosting with a template .tino file i included here.


<img width="264" alt="image" src="https://github.com/user-attachments/assets/6feb0ae6-35d4-40e8-9624-6df23f54fbc6">

Go to the Arduino cloud Templates tab

<img width="1632" alt="image" src="https://github.com/user-attachments/assets/1e441e7f-8bc0-4133-be7b-d2661aca996f">

Import the .tino file manuelly, then plug in your R4 wifi borad, follow the setup process. You would need to change add your wifi information to network in "Things" tab setup to to connect R4 to your wifi. 

<img width="1914" alt="image" src="https://github.com/user-attachments/assets/121ef1a5-658a-4857-ba5d-19becc713265">

After all setup with power provided and all wires attached, you can control your litter robot in the web app in "Dashborad" as shown here. This also works on your phone if you install the Arduino IOT app and log in to your account.  

![FullSizeRender (1)](https://github.com/user-attachments/assets/69ab60dd-52c3-4cdf-8106-1487bffc2056)

Your litter robot is back in order!

###You can also modified the .ino file to make this work only in your local network, like you have to go to "192.168.x.x" to control the litter robot. I choosed arduino cloud so i dont have to deal with all tunneling issue. 

###Also the LED in R4 indicate the states this control is in. The default "Arudino" animate is when "Go" is off and the arrow spining is for when "Go" is on. You can also use this to check system online or not by looking at the LED. You would want to disable those matrix code if your arduino is not a R4 WIFI. 



