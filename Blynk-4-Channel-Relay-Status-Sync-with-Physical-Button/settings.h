                           
                           
                           /////////////////////////////////////////////////////////////////
                          //                           Settings                          //
                         /////////////////////////////////////////////////////////////////

                         

/***************************************************
 *      Hardware Settings
 **************************************************/

/* Relay to NodeMCU Connection */

#define RELAY_PIN_1      12   //D6
#define RELAY_PIN_2      16   //D0
#define RELAY_PIN_3       4   //D2
#define RELAY_PIN_4       5   //D1 

/* NodeMCU to Push Button switch  */ 
/*
  For push button/switch action I don't have push button so I will be keep those wire open and 
  touch each of these wires with GND wire on NodeMCU to perform On and OFF action.
 */

#define PUSH_BUTTON_1     2   //D4
#define PUSH_BUTTON_2    14   //D5
#define PUSH_BUTTON_3    13   //D7
#define PUSH_BUTTON_4     1   //TX //keep here itself for me it didn't work on other pins


/***************************************************
 *        Blynk Virtual Pin Assignment
 **************************************************/

#define VPIN_BUTTON_1    V12 
#define VPIN_BUTTON_2    V13
#define VPIN_BUTTON_3    V14
#define VPIN_BUTTON_4    V15         

/***************************************************
 *       Blynk Settings 
 **************************************************/
 
#define AUTH "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" //Live


/***************************************************
 *        WiFi Settings
 **************************************************/
  
#define WIFI_SSID "xxxxxxxxxxxx"
#define WIFI_PASS "xxxxxxxxxxxx"


/***************************************************
 *        Server Settings
 **************************************************/
      
#define OTA_HOSTNAME "4 Channel Relay with Push Button Sync"
#define SERVER "xxx.xxx.xx.xxx"
#define PORT 8080
