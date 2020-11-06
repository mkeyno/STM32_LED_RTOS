# STM32_LED_RTOS
This is project for controlling LED strip (ws2812) by RF 435 Mhz remote module, while the LED data frame send  by Ethernet ENC28j60 LAN module. 
An analogue lighting sensor installed, so in different daylight situation shows a different mode of LED strip. The remote control can light on , off the LED strip 


<img src="Debug/mcu.jpg" width="250" height="250">,,
<img src="Debug/lan.jpg" width="250" height="250">
<img src="Debug/rf.jpg" width="250" height="250">
<img src="Debug/sensor.png" width="250" height="250">
 <img src="Debug/led.jpg" width="250" height="250"> 

To accomplish this project STM32F103RG MCU has been selected due to its capabilities and features 
For programming this chip STM32 CubeIDE has been used. CMSIS version 2 as interfere for implementing of FreeRTOS has selected in the software . following image shows the pin configuration of the MCU

<img src="Debug/pin.jpg" width="600" height="500"> 
The main program is comprised of 4 identical tasks as follow. 


```c
void       LED_SHOW_Task(void *argument);
void   RaidoCommand_Task(void *argument);
void       Ethernet_Task(void *argument);
void LightingSensor_Task(void *argument);

```

To synchronize these task, one binary semaphore and one Queue pipe has created. `RaidoCommand` Task use to send user command and has higher priorities. It activated by external interrupt
 `LightingSensor` Task has lower priorities and rest of tasks has normal priorities
To drive the LED WS2812 chip specific timing cycle is needed, therefore during performing this task, a binary semaphore will be held until finishing the LED driving 
. `LED_SHOW_Task()` will light up LED strip if there is data in Queue. 

```cpp
osSemaphoreAcquire( DISPLAY, osWaitForever );
	/* read Queue  and display*/
osSemaphoreRelease( DISPLAY );
```


`RaidoCommand` Task normally suspended unless new interrupt resume it and after decoding the recived command it will suspended again.  The decoded command can suspend or resume the `LED_SHOW` Task
`Ethernet` Task constantly read UDP package and put it in `Queue`. `LightingSensor` Task with lowest priorities updates the light environment through ADC channel. Serial 2 has activated for debugging purpose 
