# Adonno's Assistant Configuration

So here we are, I finally managed to put my conifg on github and will try to keep it up to date. Follow along in this journey. 

#My homeassitant Dashboards

I fully moved to lovelacelce-Ui. It took me several evenings in order to get it right and I am still tweaking. The main view is mostly used on big 21" built-in tablets. But is also usable on mobile devices. It shows the current state of an entity and it is possible to control the state of that entity by tapping the icon. 
Please note that the scrennshots are only to give you an idea and maybe these aren't the most recent version 




## History

So how did i stumble on Home-assitant an how i started with a hassbian then moved to a docker container and came back on Hass.io on a pi 

My house is running on a KNX backbone, but the servers provided cost an arm and a leg and I didn't want to Invest in that. Somehow while looking for OpenHab I found homeassitant. I had already tried with OpenHab but I never really managed to get i working. Then i landed on HA website and saw some screenshots I installed it on the Pi and was amazed at how simple it was to use and configure. 
The community is amazing and quickly growing. There are several youtubers regurarely posting tutorials and the system is kept up to date on a 2 week schedule as of now. 

## Hardware

* Host system: RPi 3
* Backbone: KNX
    * ABB - SV/S 30.640.3.1     1X
        <img src="https://github.com/adonno/Home-AssistantConfig/blob/master/docs/PowersupplyKNX.jpg"s=200 alt="Powersupply" />
    * ABB - SA/S12.16.5.1       1X
    * ABB - SA/S4.46.2.1        1X
    * ABB - JRA/S4.230.5.1      2X
    * Hager - TXM620D           1X
    * Hager - TYA628C           1X
    * Hager - TXA207C           1x
    * Theben - DM 4 T           4X
    * Theben - DMB 1 T          1X
    * MDT - AKH-0400.02         1X
    * MDT - AKH-0800.02         1X
    * MDT - SCN-IP100.02        1X
    * BEG - PD11-KNX-FLAT       3X
    * MDT - BE-TA55P2.01        1X
    * MDT - BE-TA55P6.01        1X
    * MDT - BE-TA55P8.01        1X
    * MDT - BE-GT2Tx.01 (Temp)  11X
    * MDT - BE-GT20X.01         4X
    * Zennio - ZAS              1X




