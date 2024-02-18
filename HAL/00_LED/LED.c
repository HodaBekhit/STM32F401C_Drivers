/*
 * LED.c
 *
 * Created: 2/18/2024 11:25:25 AM
 *  Author: Dell
 */ 

#include "LED.h"
#include "GPIO.h"

extern const LED_cfg_t LEDS[_LED_NUM];

LED_ERRORSTATUS_t LED_Init(void)
{
	LED_ERRORSTATUS_t RetLedError=LED_OK;
	GPIO_PinCfg_t Loc_LED;
	u32 Idx=0;
	for(Idx=0;Idx<_LED_NUM;Idx++)
	{
		Loc_LED.GPIO_PORT=LEDS[Idx].LED_Port;
		Loc_LED.GPIO_PIN=LEDS[Idx].LED_Pin;
		Loc_LED.GPIO_MODE=LEDS[Idx].LED_Mode;
		Loc_LED.GPIO_SPEED=LEDS[Idx].LED_Speed;
		RetLedError=GPIO_InitPin(&Loc_LED);
	}
	return RetLedError;
}

LED_ERRORSTATUS_t LED_SetStatus(u32 Copy_LED, u8 Copy_Status)
{
	LED_ERRORSTATUS_t RetLedError=LED_OK;
	if(Copy_LED>_LED_NUM)
	{
		RetLedError=LED_InvalidLed;
	}
	else if(!(Copy_Status==LED_STATE_OFF)||(Copy_Status==LED_STATE_ON))
	{
		RetLedError=LED_InvalidStatus;
	}
	else
	{
		RetLedError=GPIO_SetPinValue(LEDS[Copy_LED].LED_Port,LEDS[Copy_LED].LED_Pin,LEDS[Copy_LED].LED_Conn^Copy_Status);
	}
	return RetLedError;
}