#ifndef __MAIN_H_
#define __MAIN_H_

#include "mico.h"
#include "MiCOKit_EXT.h"

#define VERSION "v0.0.0"

#define TYPE 1
#define TYPE_NAME "tc1"

#define SETTING_MQTT_STRING_LENGTH_MAX  32      //必须 4 字节对齐。

#define SLOT_NAME_LENGTH 32
#define SLOT_NUM 6              //插座数量
#define SLOT_TIME_TASK_NUM 5    //每个插座最多5组定时任务

#define Led         MICO_GPIO_5
#define Button      MICO_GPIO_23
#define POWER      MICO_GPIO_15

#define Relay_ON     1
#define Relay_OFF     0

#define Relay_0     MICO_GPIO_6
#define Relay_1     MICO_GPIO_8
#define Relay_2     MICO_GPIO_10
#define Relay_3     MICO_GPIO_7
#define Relay_4     MICO_GPIO_9
#define Relay_5     MICO_GPIO_18
#define Relay_NUM   SLOT_NUM

//自定义
#define ZTC_NAME "tc1_%s"                       //设备名称模板，默认生成的设备名称为tc1_{{MAC地址}}，PS：如修改要保留%s，将填充MAC地址
#define CONFIG_SSID "ssid"                      //WiFi名称
#define CONFIG_USER_KEY "password"              //WiFi密码
#define CONFIG_MQTT_IP "mqtt_ip"                //MQTT服务器IP
#define CONFIG_MQTT_PORT 1883                   //MQTT服务器端口，数值    
#define CONFIG_MQTT_USER "mqtt_user"            //MQTT用户名
#define CONFIG_MQTT_PASSWORD "mqtt_password"    //MQTT密码
#define STATE_UPDATE_INTERVAL 10000             //功率上报间隔，单位ms，数值
#define MQTT_CLIENT_SUB_TOPIC   "cmnd/%s"       //命令控制接收topic模板，%s取ZTC_NAME（默认tc1_{{MAC地址}}），PS：请勿修改此处，可修改ZTC_NAME
#define MQTT_CLIENT_PUB_TOPIC   "stat/%s"       //状态信息topic模板，%s取ZTC_NAME（默认tc1_{{MAC地址}}），PS：请勿修改此处，可修改ZTC_NAME
#define USER_CONFIG_VERSION 2                   //OTA注意修改为与上次固件不同，触发重载wifi、mqtt等配置信息

//用户保存参数结构体
typedef struct
{
    char mqtt_ip[SETTING_MQTT_STRING_LENGTH_MAX];   //mqtt service ip
    int mqtt_port;        //mqtt service port
    char mqtt_user[SETTING_MQTT_STRING_LENGTH_MAX];     //mqtt service user
    char mqtt_password[SETTING_MQTT_STRING_LENGTH_MAX];     //mqtt service user
//     char mqtt_device_id[SETTING_MQTT_STRING_LENGTH_MAX];        //mqtt service user  device name

    char version;
    char slot[SLOT_NUM];
    char user[maxNameLen];
} user_config_t;

extern char first_sntp;
extern uint32_t sntp_count;

extern uint32_t run_time;
extern char strMac[16];
extern uint32_t power;
extern system_config_t * sys_config;
extern user_config_t * user_config;

extern mico_gpio_t Relay[Relay_NUM];

#endif
