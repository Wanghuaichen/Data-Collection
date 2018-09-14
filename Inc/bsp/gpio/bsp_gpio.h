#ifndef __BSP_GPIO_H__
#define __BSP_GPIO_H__

/* ����ͷ�ļ� ----------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

/* ���Ͷ��� --------------------------------------------------------------*/
/* �궨�� --------------------------------------------------------------------*/
/* ���º궨����YS-F4Pro������ר����������12�����ż��Ϲ�����Ϊ��������� */
#define OUTPUT1_RCC_CLK_ENABLE           __HAL_RCC_GPIOF_CLK_ENABLE
#define OUTPUT1_GPIO_PIN                 GPIO_PIN_12
#define OUTPUT1_GPIO                     GPIOF

#define OUTPUT2_RCC_CLK_ENABLE           __HAL_RCC_GPIOF_CLK_ENABLE
#define OUTPUT2_GPIO_PIN                 GPIO_PIN_13
#define OUTPUT2_GPIO                     GPIOF

#define OUTPUT3_RCC_CLK_ENABLE          __HAL_RCC_GPIOF_CLK_ENABLE
#define OUTPUT3_GPIO_PIN                 GPIO_PIN_14
#define OUTPUT3_GPIO                     GPIOF

#define OUTPUT4_RCC_CLK_ENABLE           __HAL_RCC_GPIOF_CLK_ENABLE
#define OUTPUT4_GPIO_PIN                 GPIO_PIN_15
#define OUTPUT4_GPIO                     GPIOF


#define OUTPUT1_GPIO_ON                       HAL_GPIO_WritePin(OUTPUT1_GPIO,OUTPUT1_GPIO_PIN,GPIO_PIN_SET)    // ����ߵ�ƽ
#define OUTPUT1_GPIO_OFF                      HAL_GPIO_WritePin(OUTPUT1_GPIO,OUTPUT1_GPIO_PIN,GPIO_PIN_RESET)    // ����͵�ƽ

#define OUTPUT2_GPIO_ON                       HAL_GPIO_WritePin(OUTPUT2_GPIO,OUTPUT1_GPIO_PIN,GPIO_PIN_SET)    // ����ߵ�ƽ
#define OUTPUT2_GPIO_OFF                      HAL_GPIO_WritePin(OUTPUT2_GPIO,OUTPUT1_GPIO_PIN,GPIO_PIN_RESET)    // ����͵�ƽ

#define OUTPUT3_GPIO_ON                       HAL_GPIO_WritePin(OUTPUT3_GPIO,OUTPUT1_GPIO_PIN,GPIO_PIN_SET)    // ����ߵ�ƽ
#define OUTPUT3_GPIO_OFF                      HAL_GPIO_WritePin(OUTPUT3_GPIO,OUTPUT1_GPIO_PIN,GPIO_PIN_RESET)    // ����͵�ƽ

#define OUTPUT4_GPIO_ON                       HAL_GPIO_WritePin(OUTPUT4_GPIO,OUTPUT1_GPIO_PIN,GPIO_PIN_SET)    // ����ߵ�ƽ
#define OUTPUT4_GPIO_OFF                      HAL_GPIO_WritePin(OUTPUT4_GPIO,OUTPUT1_GPIO_PIN,GPIO_PIN_RESET)    // ����͵�ƽ

/* ��չ���� ------------------------------------------------------------------*/
/* �������� ------------------------------------------------------------------*/
void OUTPUT_GPIO_Init(void);

#endif  // __BSP_GPIO_H__

/******************* (C) COPYRIGHT 2015-2020 ӲʯǶ��ʽ�����Ŷ� *****END OF FILE****/
