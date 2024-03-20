/*
 * Runnables_List.c
 *
 *  Created on: Mar 14, 2024
 *      Author: Dell
 */
#include "Runnables_List.h"
#include "scheduler.h"
//extern void SWITCH_Runnable(void);
extern void ToggleRedRunnable(void);
const runnable_t RunnablesList[_Runnables_NUM]={
	//[SWITCH]={.name={"Switch Runnable"}, .periodicity_ms=50, .cb=SWITCH_Runnable}
		[ToggleRed]={.name={"ToggleRunnable"}, .periodicity_ms=1000, .cb=ToggleRedRunnable}
};
