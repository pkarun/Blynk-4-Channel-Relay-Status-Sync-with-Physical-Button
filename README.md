# Blynk Relay Status Sync with Physical Button
Blynk: 4 channel relay status sync with Blynk app, Relay and with Physical button/Switch/Push button. If you perform ON/OFF with Physical Switch/Push button switch it lets you change the ON/OFF status on Blynk app as well. 
<h2>Features</h2>
1) 4 Channel Relay control with blynk app<br>
2) If you perform ON/OFF with Physical/Push button switch, the status gets updated on Blynk app<br>
3) If Internet is not available, you can still operate Relay/Light with offline switch <br>

<h2>Requirements</h2>
1) <a href="https://play.google.com/store/apps/details?id=cc.blynk">Blynk App</a><br>
2) <a href="http://s.click.aliexpress.com/e/nlefJ4PI">NodeMCU</a> <br>
3) <a href="http://s.click.aliexpress.com/e/qrl4Fj32">4 Channel Relay Module</a> <br>
<h2>Installation</h2>
Open settings.h and change Bynk Auth code, Wifi settings, server settings and flow calibration.

<h2>Hardware Connections</h2>

<h2>NodeMCU to 4 Channel Relay Module Connection</h2>
D6 or 12 to IN1<br>
D0 or 16 to IN2<br>
D2 or 4 to IN3<br>
D1 or 5 to IN4<br>
Vin to VCC<br>
GND to GND<br>

<h2>NodeMCU Connection for Switch Actions (NodeMCU to NodeMCU)</h2>

D4 or 2 to GND (in NodeMCU)<br>
D5 or 14 to GND (in NodeMCU)<br>
D7 or 13 to GND (in NodeMCU)<br>
TX or 1 to GND (in NodeMCU)<br>

<h2>Software Setup</h2>

1) Download and install the Blynk Mobile App for iOS or Android.<br>

2) Scan the QR code at the bottom of this page to clone the screenshot below, or create a new project yourself and manually arrange and setup the widgets.<br>

3) Email yourself the Auth code.<br>

4) Download this repo and copy the files in to your sketches directory. Open the sketch in Arduino IDE.<br>

5) Go to the settings.h tab. This is where all the customisable settings are. You should be able to change almost everything from there before compiling.<br>

<h2>Screenshots</h2>

<h3>Project Screenshots</h3>
<img src="/images/blynk/project-screenshot.png" width="400" height=""alt="project screenshot" title="project screenshot">
<img src="/images/blynk/blynk-vpin-assignment.png" width="400" height=""alt="blynk vpin assignment" title="blynk vpin assignment">
<img src="/images/blynk/blynk-button-settings.png" width="400" height=""alt="blynk button settings" title="blynk button settings">

<h3>Project Setup</h3>
<img src="/images/setup/1.jpg" width="400" height=""alt="1" title="1">
<img src="/images/setup/2.jpg" width="400" height=""alt="2" title="2">
<img src="/images/setup/3.jpg" width="400" height=""alt="3" title="3">
<img src="/images/setup/4.jpg" width="400" height=""alt="3" title="3">

<h2>Scan QR Code on Blynk App</h2>
<img src="/images/blynk/project-qr-code.png" width="400" height=""alt="Scan QR Code on Blynk App" title="Scan QR Code on Blynk App">