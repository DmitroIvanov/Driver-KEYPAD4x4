//keypad4x4.h

#ifndef __KEYPAD4X4_H__
#define __KEYPAD4X4_H__

#include <stm32f0xx.h>
#include <system_stm32f0xx.h>
#include "string.h" 
#include "stdlib.h"

//**********************************************************************************
//инициализация GPIO работающей с клавиатурой
#define KEYPAD_GPIO_RCC		RCC->AHBENR |= RCC_AHBENR_GPIOAEN //тактирование кнопок
#define COLUMNS_init		GPIOA->MODER |= GPIO_MODER_MODER0_0 | GPIO_MODER_MODER1_0 | GPIO_MODER_MODER2_0 | GPIO_MODER_MODER3_0 //выход без подтяжки
#define ROWS_init			GPIOA->MODER &= ~(GPIO_MODER_MODER4 | GPIO_MODER_MODER5 |GPIO_MODER_MODER6 | GPIO_MODER_MODER7) //вход без подтяжки

//**********************************************************************************
//установка выходов колонок
#define COLUMN_1_SET 		GPIOA->BSRR |= GPIO_BSRR_BR_0 | GPIO_BSRR_BS_1 | GPIO_BSRR_BS_2 | GPIO_BSRR_BS_3 //0b 0111
#define COLUMN_2_SET 		GPIOA->BSRR |= GPIO_BSRR_BS_0 | GPIO_BSRR_BR_1 | GPIO_BSRR_BS_2 | GPIO_BSRR_BS_3 //0b 1011
#define COLUMN_3_SET 		GPIOA->BSRR |= GPIO_BSRR_BS_0 | GPIO_BSRR_BS_1 | GPIO_BSRR_BR_2 | GPIO_BSRR_BS_3 //0b 1101
#define COLUMN_4_SET 		GPIOA->BSRR |= GPIO_BSRR_BS_0 | GPIO_BSRR_BS_1 | GPIO_BSRR_BS_2 | GPIO_BSRR_BR_3 //0b 1110
#define COLUMN_init_SET 	GPIOA->BSRR |= GPIO_BSRR_BS_0 | GPIO_BSRR_BS_1 | GPIO_BSRR_BS_2 | GPIO_BSRR_BS_3 //0b 1111

//**********************************************************************************
//опрос выводов строк
#define ROW_1_IS_SET 		((GPIOA->IDR & GPIO_IDR_4) == GPIO_IDR_4)
#define ROW_2_IS_SET 		((GPIOA->IDR & GPIO_IDR_5) == GPIO_IDR_5)
#define ROW_3_IS_SET 		((GPIOA->IDR & GPIO_IDR_6) == GPIO_IDR_6)
#define ROW_4_IS_SET 		((GPIOA->IDR & GPIO_IDR_7) == GPIO_IDR_7)

//**********************************************************************************
//переменные в которых хранится текущие состояния
extern static volatile STATE_column stateColumn;
extern static volatile STATE_key_out stateKeypad;

//**********************************************************************************
//состояния
typedef enum {
	column1,	//опрос строк 1-й колонки
	column2,	//опрос строк 2-й колонки
	column3,	//опрос строк 3-й колонки
	column4		//опрос строк 4-й колонки
} STATE_column;

typedef enum {
	key_out_state_NULL,	//ничего не нажато
	key_out_state_0,	//нажата кнопка 0
	key_out_state_1,	//нажата кнопка 1
	key_out_state_2,	//....
	key_out_state_3,
	key_out_state_4, 
	key_out_state_5,
	key_out_state_6,
	key_out_state_7,
	key_out_state_8,
	key_out_state_9,
	key_out_state_A,
	key_out_state_B,
	key_out_state_C,
	key_out_state_D,
	key_out_state_E,
	key_out_state_F,
	key_out_state_*,
	key_out_state_#
} STATE_key_out;

//функции для работы с состояниями:
STATE_column getStateColumn(void);//получить текущий опрашиваемый столбец
void setStateColumn(STATE_column newState);//установить опрашиваемый столбец

STATE_key_out getStateKeypad(void);//получить текущее состояние клавы
void setStateKeypad(STATE_key_out newState);//установить новое состояние клавы

//**********************************************************************************
void keypad_init(void);//инициализация выводов под кнопки
//**********************************************************************************
void dispatch_keypad(void);//диспетчер выполняющий задачи реагирующие на нажатие клавиш 
//**********************************************************************************
void get_keypad_push(void);//опрашиваем клавиатуру
//**********************************************************************************
#endif /* __KEYPAD4X4_H_ */
