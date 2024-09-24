# STM32G431 In Applcation Programming via CLI
## **Description**

<font size = 3>
1.&ensp;Using CLI: Request version number, software reboot, firmware update.
<br>
2.&ensp;The application passes noinit varables to Bootloader for IAP without involving other hardware (such as buttons).
And uses UART Ymodem protocol for firmware update.
<br>
3.&ensp;The application includes an "app descriptor" to confirm whether the firmware update has programmed the correct MCU and flash size.
<br>
4.&ensp;If you are interested in Bootloader code, you can enter the submodule folder.
</font>
<br>

## **Hardware**

<font size = 3>

**B-G431B-ESC1:** official demo board<br>
**USART2:** Pinout PB3, PB4
</font>

![B-G431B-ESC1](images/B-G431B-ESC1.jfif)

## **Applcation Demo**
![APP Demo](images/Cli_Demo.gif)

<br>

## Bootloader Demo
![IAP Demo](images/IAP_Demo.gif)