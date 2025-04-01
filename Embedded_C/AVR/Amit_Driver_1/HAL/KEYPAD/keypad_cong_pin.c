/*
 * keypad_pattern.c
 *
 *  Created on: Sep 16, 2023
 *      Author: hp
 */
#include "../../SERV/std_type.h"
#include "keypad_confg.h"


uint8 Pattern[NO_ROW][NO_COL]={{'1','2','3','+'},
		                       {'4','5','6','-'},
					           {'7','8','9','*'},
					           {'AC','0','=','/'}};



uint8 Row_Pin[NO_ROW]={16,17,18,19};
uint8 Col_Pin[NO_COL]={20,21,22,23};
