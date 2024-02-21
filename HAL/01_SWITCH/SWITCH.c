/*
 * SWITCH.c
 *
 * Created: 2/18/2024 11:25:25 AM
 *  Author: Dell
 */ 

#include "SWITCH.h"
#include "GPIO.h"

extern const SWITCH_cfg_t SWITCHS[_SWITCH_NUM];

SWITCH_ERRORSTATUS_t SWITCH_Init(void)
{
	SWITCH_ERRORSTATUS_t RetSwitchError=SWITCH_OK;
	GPIO_PinCfg_t Loc_SWITCH;
	u32 Idx=0;
	for(Idx=0;Idx<_SWITCH_NUM;Idx++)
	{
		Loc_SWITCH.GPIO_PORT=SWITCHS[Idx].SWITCH_Port;
		Loc_SWITCH.GPIO_PIN=SWITCHS[Idx].SWITCH_Pin;
		Loc_SWITCH.GPIO_MODE=SWITCHS[Idx].SWITCH_Mode;
		if(SWITCHS[Idx].SWITCH_Mode==SWITCH_INPUT_PU)
		{
			Loc_SWITCH.GPIO_MODE=input_PU;
		}
		else
		{
			Loc_SWITCH.GPIO_MODE=input_PD;
		}

		RetSwitchError=GPIO_InitPin(&Loc_SWITCH);
	}
	return RetSwitchError;
}

SWITCH_ERRORSTATUS_t SWITCH_GetStatus(u32 Copy_SWITCH, u8* Copy_Status)
{
	SWITCH_ERRORSTATUS_t RetSwitchError=SWITCH_OK;
	u8 Input_value;
	if(Copy_SWITCH>_SWITCH_NUM)
	{
		RetSwitchError=SWITCH_InvalidSwitch;
	}
	else if(Copy_Status==NULLPTR)
	{
		RetSwitchError=SWITCH_NULLPTR;
	}
	else
	{

		RetSwitchError=GPIO_GetPinValue(SWITCHS[Copy_SWITCH].SWITCH_Port,SWITCHS[Copy_SWITCH].SWITCH_Pin,&Input_value);
		*Copy_Status=Input_value^SWITCHS[Copy_SWITCH].SWITCH_Mode;
	}
	return RetSwitchError;
}
