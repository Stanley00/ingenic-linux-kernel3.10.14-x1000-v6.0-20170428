#ifndef __BOARD_H__
#define __BOARD_H__
#include <gpio.h>
#include <soc/gpio.h>



#ifdef  CONFIG_BROADCOM_RFKILL
#define BLUETOOTH_UART_GPIO_PORT        GPIO_PORT_D
#define BLUETOOTH_UART_GPIO_FUNC        GPIO_FUNC_2
#define BLUETOOTH_UART_FUNC_SHIFT       0x4
#define HOST_WAKE_BT    GPIO_PG(6)
#define BT_WAKE_HOST    GPIO_PF(7)
#define BT_REG_EN       GPIO_PG(9)
#define BT_UART_RTS     GPIO_PD(29)
#define BT_PWR_EN   -1
#define HOST_BT_RST    -1
#define GPIO_PB_FLGREG      (0x10010158)
#define GPIO_BT_INT_BIT     (1 << (GPIO_BT_INT % 32))
#define BLUETOOTH_UPORT_NAME  "ttyS1"
#endif

/* KEY gpio */
#define GPIO_VOLUMEDOWN_KEY			GPIO_PC(9)
#define GPIO_VOLUMEUP_KEY			GPIO_PC(2)
#define GPIO_PLAY_KEY               GPIO_PC(3)
#define GPIO_AP_STA_KEY             GPIO_PC(12)
//#define GPIO_POWER               GPIO_PA(30)

#define ACTIVE_LOW_VOLUMEDOWN    1
#define ACTIVE_LOW_VOLUMEUP      1
#define ACTIVE_LOW_PLAY          1
#define ACTIVE_LOW_AP_STA        1
//#define ACTIVE_LOW_POWER         1



/*wifi*/
#define GPIO_WLAN_PW_EN     -1//GPIO_PD(24)
#define WL_WAKE_HOST        GPIO_PG(7)
#define WL_REG_EN       GPIO_PG(8)

/*wifi  LED */
#ifdef CONFIG_LEDS_GPIO
#define	WL_LED_R	GPIO_PC(5)
#define	WL_LED_G	GPIO_PC(4)
#define	WL_LED_B	GPIO_PC(13)
#endif

#ifdef CONFIG_SPI_GPIO
#define GPIO_SPI_SCK  GPIO_PA(18)
#define GPIO_SPI_MOSI GPIO_PA(19)
#define GPIO_SPI_MISO GPIO_PA(20)
#endif

/* ****************************GPIO AUDIO START****************************** */
#define GPIO_HP_MUTE        -1  /*hp mute gpio*/
#define GPIO_HP_MUTE_LEVEL  -1  /*vaild level*/

#define GPIO_SPEAKER_EN		GPIO_PC(7)         /*speaker enable gpio*/
#define GPIO_SPEAKER_EN_LEVEL   1

#define GPIO_HANDSET_EN     -1  /*handset enable gpio*/
#define GPIO_HANDSET_EN_LEVEL   -1

#define GPIO_HP_DETECT		GPIO_PC(6)      /*hp detect gpio*/
#define GPIO_HP_INSERT_LEVEL    1
#define GPIO_MIC_SELECT     -1  /*mic select gpio*/
#define GPIO_BUILDIN_MIC_LEVEL  -1  /*builin mic select level*/
#define GPIO_MIC_DETECT     -1
#define GPIO_MIC_INSERT_LEVEL   -1
#define GPIO_MIC_DETECT_EN  -1  /*mic detect enable gpio*/
#define GPIO_MIC_DETECT_EN_LEVEL -1 /*mic detect enable gpio*/

#define HP_SENSE_ACTIVE_LEVEL   1
#define HOOK_ACTIVE_LEVEL       -1
/* ****************************GPIO AUDIO END******************************** */

#ifdef CONFIG_VIDEO_JZ_CIM_HOST_V11
#define CAMERA_INDEX		0
#define BACK_CAMERA_INDEX  1
#define FRONT_CAMERA_INDEX  0

#if defined(CONFIG_SOC_JZ_CIM0)
#define FRONT_CAMERA_SENSOR_EN  		GPIO_PC(4)
#define FRONT_CAMERA_SENSOR_RESET 		GPIO_PC(7)

#define BACK_CAMERA_SENSOR_EN  			GPIO_PC(11)
#define BACK_CAMERA_SENSOR_RESET 		GPIO_PC(14)
#endif
#endif


/* ****************************GPIO I2C START ******************************** */
#define GPIO_I2C1_SDA		GPIO_PE(30)
#define GPIO_I2C1_SCK		GPIO_PE(31)
/* ****************************GPIO I2C END  ******************************** */

#define GPIO_EFUSE_VDDQ			-ENODEV		/* EFUSE must be -ENODEV or a gpio */

#endif /* __BOARD_H__ */

