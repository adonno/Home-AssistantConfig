# Adonno's Assistant Configuration

So here we are, I finally managed to put my conifg on github and will try to keep it up to date. Follow along in this journey.

# My homeassitant Dashboards

I fully moved to lovelacelce-Ui. It took me several evenings in order to get it right and I am still tweaking. The main view is mostly used on big 21" built-in tablets. But is also usable on mobile devices. It shows the current state of an entity and it is possible to control the state of that entity by tapping the icon. 
Please note that the scrennshots are only to give you an idea and maybe these aren't the most recent version

<img src="https://github.com/adonno/Home-AssistantConfig/blob/master/docs/daymode.PNG" alt="Daymode" height="500px" />
<img src="https://github.com/adonno/Home-AssistantConfig/blob/master/docs/Nightmode.PNG" alt="Nightmode" height="500px" />
<img src="https://github.com/adonno/Home-AssistantConfig/blob/master/docs/page1.PNG" alt="Page1" height="500px" />
<img src="https://github.com/adonno/Home-AssistantConfig/blob/master/docs/Page2.png" alt="Page2" height="500px" />
<img src="https://github.com/adonno/Home-AssistantConfig/blob/master/docs/nas.PNG" alt="Nas" height="500px" />

## History

So how did i stumble on Home-assitant an how i started with a hassbian then moved to a docker container and came back on Hass.io on a pi.

My house is running on a KNX backbone, but the servers provided cost an arm and a leg and I didn't want to Invest in that. Somehow while looking for OpenHab I found homeassitant. I had already tried with OpenHab but I never really managed to get i working. Then i landed on HA website and saw some screenshots I installed it on the Pi and was amazed at how simple it was to use and configure. 
The community is amazing and quickly growing. There are several youtubers regurarely posting tutorials and the system is kept up to date on a 2 week schedule as of now.

## House Automation Hardware

### Host system: Intel Nuc

I have ESXi Running on an Intel Nuc and Hassio running on a VM

### Backbone: KNX

This is the Controlled electrical installation
There is not much to say about this. As the house was a new construction this was the best way to go imho. Having everything wired makes it less error/interference prone and avoid additional radio frequencies.

| Device        |Quantities           |More Info          |Image    |
| ------------- |:-------------:|:-----:|-----------:|
| ABB - SV/S 30.640.3.1 | **1X** | [PowerSupply,640mA](https://new.abb.com/products/ABB2CDG110167R0011) |<img src="https://github.com/adonno/Home-AssistantConfig/blob/master/docs/PowersupplyKNX.jpg"  height="100px" />|
| ABB - SA/S12.16.5.1   | **1X** | [Switch Act, 12F 16-C-Load](https://new.abb.com/products/ABB2TAZ710121R5161) |<img src="https://github.com/adonno/Home-AssistantConfig/blob/master/docs/SA-S12.16.5.1.jpg"  height="100px" />|
| ABB - SA/S4.16.2.1    | **1X** | [Switch Act, 4F, 16A](https://new.abb.com/products/ABB2TAZ710041R2161) |<img src="https://github.com/adonno/Home-AssistantConfig/blob/master/docs/ABB-SA-S4.16.2.1.jpg"  height="100px" />|
| ABB - JRA/S4.230.5.1  | **2X** | [Blind/RolShtAct.TravD,M,4f](https://new.abb.com/products/ABB2CDG110125R0011) |<img src="https://github.com/adonno/Home-AssistantConfig/blob/master/docs/JRA-S4.230.5.1.jpg"  height="100px" />|
| Hager - TXM620D       | **1X** | [Output module 20x 16A (C)/230V~, KNX](https://www.hager.co.uk/product-catalogue/building-automation/easy-e./easy-e./easy-outputs/txm620d/75824.htm) |<img src="https://github.com/adonno/Home-AssistantConfig/blob/master/docs/txm620d_1.jpg" height="100px" />|
| Hager - TYA628C       | **1X** |  [Output device for 8 shutters or blinds 230V~](https://www.hager.co.uk/product-catalogue/building-automation/system-s./system-s./system-blinds/tya628c/77809.htm?Suchbegriffe=TYA628C) |<img src="https://github.com/adonno/Home-AssistantConfig/blob/master/docs/TYA628C.jpg"   height="100px" />|
| Hager - TXA207C       | **1X** |  [Output 10 -fold 16A](http://www.hager.co.in/product-catalogue/building-automation-wiring-accessories/building-automation/output-module/switching-actuators/txa207c/9195.htm) |<img src="https://github.com/adonno/Home-AssistantConfig/blob/master/docs/TXA207C.jpg" height="100px" />|
| Theben - DM 4 T       | **4X** |  [4-way universal dimmer actuator FIX2](https://www.theben.de/en/dm-4-t-knx-4940275) |<img src="https://github.com/adonno/Home-AssistantConfig/blob/master/docs/theben%20DM4T.jpg"   height="100px" />|
| Theben - DMB 1 T      | **1X** | [Switch Act, 12F 16-C-Load](https://new.abb.com/products/ABB2TAZ710121R5161) |<img src="https://github.com/adonno/Home-AssistantConfig/blob/master/docs/DMB1T.png"  height="100px" />|
| MDT - AKH-0400.02     | **1X** |  [Heating Actuators 4-fold](https://www.mdt.de/EN_Heating_Actuators.html) |<img src="https://github.com/adonno/Home-AssistantConfig/blob/master/docs/MDT_AKH-040002.jpg"  height="100px" />|
| MDT - AKH-0800.02     | **1X** |  [Heating Actuators 4-fold](https://www.mdt.de/EN_Heating_Actuators.html) |<img src="https://github.com/adonno/Home-AssistantConfig/blob/master/docs/mdtakh080002.jpg"  height="100px" />|
| MDT - SCN-IP100.02    | **1X** | [IP Router](https://www.mdt.de/EN_Interfaces.html) |<img src="https://github.com/adonno/Home-AssistantConfig/blob/master/docs/ip%20router.jpg"  height="100px" />|
| BEG - PD11-KNX-FLAT   | **3X** | [Low profile KNX occupancy detector](https://www.beg-luxomat.com/en/products/luxomatnet/knx/knx-standard-presence-detectors/pd11-knx-flat-st/) |<img src="https://github.com/adonno/Home-AssistantConfig/blob/master/docs/PD11-KNX.jpg"  height="100px" />|
| MDT - BE-TA55P2.01    | **1X** | [Push Button 2-fold](https://www.mdt.de/EN_Push_Buttons.html) |<img src="https://github.com/adonno/Home-AssistantConfig/blob/master/docs/BE-TA55P2.01.jpg"  height="100px" />|
| MDT - BE-TA55P6.01    | **1X** | [Push Button 6-fold](https://www.mdt.de/EN_Push_Buttons.html) |<img src="https://github.com/adonno/Home-AssistantConfig/blob/master/docs/BE-TA55P6.01.jpg"  height="100px" />|
| MDT - BE-TA55P8.01    | **1X** | [Push Button 8-fold](https://www.mdt.de/EN_Push_Buttons.html) |<img src="https://github.com/adonno/Home-AssistantConfig/blob/master/docs/TA55P8.01.jpg"  height="100px" />|
| MDT - BE-GT2Tx.01     | **11X** | [Glass Push Buttons II Smart With Temperature Sensor](https://www.mdt.de/EN_Glas_Push_Buttons_Smart.html) |<img src="https://github.com/adonno/Home-AssistantConfig/blob/master/docs/be-gt2tw.01_1.jpg"  height="100px" />|
| MDT - BE-GT20x.01     | **4X** | [Glass Push Buttons II Smart](https://www.mdt.de/EN_Glas_Push_Buttons_Smart.html) |<img src="https://github.com/adonno/Home-AssistantConfig/blob/master/docs/be-gt2tw.01_1.jpg"  height="100px" />|
| Zennio - ZAS          | **1X** |[ZAS Zennio Analog Screen](https://www.zennio.com/products/touch-panels-room-controllers/zas) |<img src="https://github.com/adonno/Home-AssistantConfig/blob/master/docs/ZAS_White.png"  height="100px" />|

### Fibaro

|Device        |Quantities            |Image    |
|------------- |:-------------:|-----------:|
|Fibaro Smoke Sensors          | **3X** | <img src="https://github.com/adonno/Home-AssistantConfig/blob/master/docs/fibaromultisensor.png"   height="100px" />|
|Fibaro RGBW controllers         | **4x**    | <img src="https://github.com/adonno/Home-AssistantConfig/blob/master/docs/fibarorgbw.png"     height="100px" />|
|Fibaro 3-1 Motion Sensor         | **1X** | <img src="https://github.com/adonno/Home-AssistantConfig/blob/master/docs/Fibsmokesensor.jpg"  height="100px" />|
|Fibaro Intercom          | **1X** | <img src="https://github.com/adonno/Home-AssistantConfig/blob/master/docs/fibaro_intercom.jpg"  height="100px" />|

(I would not recommend this intercom)
Though it looks nice, it is not usable with home assitant except for the camera feed. If someone rings the bell, the phones where the app is installed on rings but there is no API as of now for HA to access.
Contacted their support about the issue and still waiting on a reply from their side.

### Audio

I have several Choromecasts for my home audio entertainment system. I am actually using 1 for the Partental suite and 1 for the living/kitchen/entrance area 1 is used for TTS mesages
I am using several Speakers:
* 4 above the TV/couch  - 224mm 60W
* 2 in the kitchen - 224mm 60W
* 1 in the WC - 80mm 10W
* 1 in the main antrance  - 80mm 10W
* 1 in the hallway  - 80mm 10W
* 1 in the parental Bedroom - 224mm  60W
* 1 in the Wardrobe  - 80mm 10W
* 1 in the Parental Bathroom -224mm 60W

There will be more speakers addedd in the Garage and in the Wellness Aera at a later

I am currently working with mixers as chromecast don't continue with playback after a message as been broadcast over tts.
Maybe this issue could be solved by using alexa devices instead of Chormecasts.
I will also need a big per channel amplifyer as i will have at least 6-7 Zones and have more powerful amps in a 2nd pahse as the current ones caon't keep up with the speakers

Device List

|Device        |Quantities            |Image    |
|:-----------|:----------------:|--------------:|
|[Chomrecast Audio](https://www.google.com/chromecast/audio/explore/)| **4X**|<img src="https://github.com/adonno/Home-AssistantConfig/blob/master/docs/chromecast-audio.png"  height="100px" /> |
|[Loxone Speaker]( https://shop.loxone.com/enus/speaker.html)| **8X** |<img src="https://github.com/adonno/Home-AssistantConfig/blob/master/docs/seitlich_rund.png"  height="100px" />|
|[Visaton Deckenlautsprecher Dl-8](https://www.amazon.de/gp/product/B0000WP8XM/ref=oh_aui_detailpage_o03_s00?ie=UTF8&psc=1)| **4X** |<img src="https://github.com/adonno/Home-AssistantConfig/blob/master/docs/Visaton.jpg"  height="100px" />|
|[Lepy-808 Black Digital-Amplifyer Stereo-Audio,20W](https://www.amazon.de/gp/product/B01M8NLFV8/ref=oh_aui_detailpage_o09_s00?ie=UTF8&psc=1) | **5X** |<img src="https://github.com/adonno/Home-AssistantConfig/blob/master/lepy.png"  height="100px" /> |
|[Behringer Xenyx 502](https://www.thomann.de/gb/behringer_xenyx_502.htm) | **4X** |<img src="https://github.com/adonno/Home-AssistantConfig/blob/master/docs/behringer-xenyx.jpg"  height="100px" /> |

### Storage/Server

Synology DS415+ <img src="https://github.com/adonno/Home-AssistantConfig/blob/master/docs/Synology.jpg" height="100px" />

### Screens:

[XORO Megapad](https://www.amazon.de/Xoro-MegaPAD-2151-Tablet-PC-Android/dp/B00JIKWBKK) A 21" Wallmounted Tabled (with no batteires)running on android for HA display   **2X**

Lenovo

### Amazon Alexa
### Harmony Hub

## BACKUP

Every Sunday at 3:00 AM an automation creates a snapshot of my Setup. Knowing that SD cards can fail and maybe running the risk i could loose my snapshot is preocupating so I mounted the Backup folder with my Sonolgy nas and have a Job running on it copies the snapshots to a local folder. 
I think i will create a Tutorial or a video Later on that matter

### On Hassio

```yaml
- alias: weeklysnapshot
  initial_state: True
  id: weeklysnapshot
  trigger:
    - platform: time
      at: 03:00:00
  condition:
  - condition: time
    weekday:
    - sun
  action:
  - service: hassio.snapshot_full
    data_template:
      name: Automated Backup {{ now().strftime('%Y-%m-%d') }}
```

## TODO

This is an extenisve list of all the stuff i would like to work on soon.

### Automations

### Install Sensors
I have several stuff I would monitor for "flood/Waterleaks"

* Heating Central
* Dishwasher
* Water mains
* Washingingmachine
* (maybe in the bathoroom cabinets ? )

### Install CO sensor

That one will be installed in the heating central as it is GAS fueled. (i could maybe have a device having both flood and CO monitoring)

### Tidy up my Hassio config

Tidy up and Document my config better inspired by @freck

That will be a hell lot of work

### Alarm

