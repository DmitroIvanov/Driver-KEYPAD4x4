//keypad4x4.c

#include "keypad4x4.h"
//**********************************************************************************
//переменные в которых хранится текущие состояния
static volatile STATE_column stateColumn = column1;
static volatile STATE_key_out stateKeypad = key_out_state_NULL;

//**********************************************************************************
void keypad_init(void)
{
	KEYPAD_GPIO_RCC;
	COLUMNS_init;
	ROWS_init;
	COLUMN_init_SET;
}

//**********************************************************************************
//состояния системы
STATE_column getStateColumn(void);//получить текущий опрашиваемый столбец
{
	return stateColumn;
}
void setStateColumn(STATE_column newState);//установить опрашиваемый столбец
{
	stateColumn = newState;
}

STATE_key_out getStateKeypad(void);//получить текущее состояние клавы
{
	return stateKeypad;
}
void setStateKeypad(STATE_key_out newState);//установить новое состояние клавы
{
	stateKeypad = newState;
}

/*******************************************************************************************
функция реакции на нажатие кнопок клавы 
!!!это надо запускать чаще чем опрос клавы, чтобы небыло пропусков в нажатии клавиш!!!
********************************************************************************************/
void dispatch_keypad(void)//диспетчер выполняющий задачи реагирующие на нажатие клавиш 
{
	switch (getStateKeypad())//
	{
		/****************************************************************/
		case key_out_state_1://была нажата кн. 1
		{
			/****************************************************************/
			//здесь ваш код, например:
			LED_1_ON; 
			/****************************************************************/
			setStateKeypad(key_out_state_NULL);
			break;			
		}
		/****************************************************************/
		case key_out_state_2://была нажата кн. 2
		{
			LED_1_OFF;					
			setStateKeypad(key_out_state_NULL);
			break;			
		}
		/****************************************************************/
		case key_out_state_3://была нажата кн. 3
		{
			LED_1_OFF;					
			setStateKeypad(key_out_state_NULL);
			break;			
		}
		/****************************************************************/
		case key_out_state_4://была нажата кн. 4
		{
			LED_1_OFF;					
			setStateKeypad(key_out_state_NULL);
			break;			
		}
		/****************************************************************/
		case key_out_state_5://была нажата кн. 5
		{
			LED_1_OFF;					
			setStateKeypad(key_out_state_NULL);
			break;			
		}
		/****************************************************************/
		case key_out_state_6://была нажата кн. 6
		{
			LED_1_OFF;					
			setStateKeypad(key_out_state_NULL);
			break;			
		}
		/****************************************************************/
		case key_out_state_7://была нажата кн. 7
		{
			LED_1_OFF;					
			setStateKeypad(key_out_state_NULL);
			break;			
		}
		/****************************************************************/
		case key_out_state_8://была нажата кн. 8
		{
			LED_1_OFF;					
			setStateKeypad(key_out_state_NULL);
			break;			
		}
		/****************************************************************/
		case key_out_state_9://была нажата кн. 9
		{
			LED_1_OFF;					
			setStateKeypad(key_out_state_NULL);
			break;			
		}
		/****************************************************************/
		case key_out_state_0://была нажата кн. 0
		{
			LED_1_OFF;					
			setStateKeypad(key_out_state_NULL);
			break;			
		}
		/****************************************************************/
		case key_out_state_A://была нажата кн. A
		{
			LED_1_OFF;					
			setStateKeypad(key_out_state_NULL);
			break;			
		}
		/****************************************************************/
		case key_out_state_B://была нажата кн. B
		{
			LED_1_OFF;					
			setStateKeypad(key_out_state_NULL);
			break;			
		}
		/****************************************************************/
		case key_out_state_C://была нажата кн. C
		{
			LED_1_OFF;					
			setStateKeypad(key_out_state_NULL);
			break;			
		}
		/****************************************************************/
		case key_out_state_D://была нажата кн. D
		{
			LED_1_OFF;					
			setStateKeypad(key_out_state_NULL);
			break;			
		}
		/****************************************************************/
		case key_out_state_*://была нажата кн. *
		{
			LED_1_OFF;					
			setStateKeypad(key_out_state_NULL);
			break;			
		}
		/****************************************************************/
		case key_out_state_#://была нажата кн. #
		{
			LED_1_OFF;					
			setStateKeypad(key_out_state_NULL);
			break;			
		}
		/****************************************************************/		
	}
}
/*******************************************************************************************
функция опроса клавы:
- каждый вызов ф-ции опрашивает кнопки одного столбца. 
- для опроса всей клавы нужно вызвать ф-цию 4-ре раза.
- запускать в прерывании таймера с перидом 10-50 мс.
********************************************************************************************/
void get_keypad_push(void)//опрашиваем клавиатуру
{
	switch (getStateColumn())//переключаем режимы опроса столбцов
	{
		/****************************************************************/
		case column1://опрашиваем строки 1-го столбца
		{
			COLUMN_1_SET;
			if (ROW_1_IS_SET) 		{setStateKeypad(key_out_state_1);} //если нажатие в 1-й строке, то нажата кн - "1"
			else if (ROW_2_IS_SET)	{setStateKeypad(key_out_state_4);} //если нажатие во 2-й строке, то нажата кн - "4"
			else if (ROW_3_IS_SET)	{setStateKeypad(key_out_state_7);}
			else if (ROW_4_IS_SET)	{setStateKeypad(key_out_state_*);}
			else 					{setStateKeypad(key_out_state_NULL);}//если ничего не нажато			
			setStateColumn(column2);
			break;			
		}
		/****************************************************************/
		case column2://опрашиваем строки 2-го столбца
		{
			COLUMN_2_SET;
			if (ROW_1_IS_SET) 		{setStateKeypad(key_out_state_2);} //если нажатие в 1-й строке, то нажата кн - "2"
			else if (ROW_2_IS_SET)	{setStateKeypad(key_out_state_5);} //если нажатие во 2-й строке, то нажата кн - "5"
			else if (ROW_3_IS_SET)	{setStateKeypad(key_out_state_8);}
			else if (ROW_4_IS_SET)	{setStateKeypad(key_out_state_0);}
			else 					{setStateKeypad(key_out_state_NULL);}//если ничего не нажато			
			setStateColumn(column3);
			break;			
		}
		/****************************************************************/
		case column3://опрашиваем строки 3-го столбца
		{
			COLUMN_3_SET;
			if (ROW_1_IS_SET) 		{setStateKeypad(key_out_state_3);} //если нажатие в 1-й строке, то нажата кн - "3"
			else if (ROW_2_IS_SET)	{setStateKeypad(key_out_state_6);} //если нажатие во 2-й строке, то нажата кн - "6"
			else if (ROW_3_IS_SET)	{setStateKeypad(key_out_state_9);}
			else if (ROW_4_IS_SET)	{setStateKeypad(key_out_state_#);}
			else 					{setStateKeypad(key_out_state_NULL);}//если ничего не нажато			
			setStateColumn(column4);
			break;			
		}
		/****************************************************************/
		case column4://опрашиваем строки 4-го столбца
		{
			COLUMN_4_SET;
			if (ROW_1_IS_SET) 		{setStateKeypad(key_out_state_3);} //если нажатие в 1-й строке, то нажата кн - "A"
			else if (ROW_2_IS_SET)	{setStateKeypad(key_out_state_6);} //если нажатие во 2-й строке, то нажата кн - "B"
			else if (ROW_3_IS_SET)	{setStateKeypad(key_out_state_9);}
			else if (ROW_4_IS_SET)	{setStateKeypad(key_out_state_#);}
			else 					{setStateKeypad(key_out_state_NULL);}//если ничего не нажато			
			setStateColumn(column1);
			break;			
		}		
	}/****************************************************************/
}
//**********************************************************************************
