/**
  ******************************************************************************
  * @file          ws2812cfg.h
  * @brief         ����WS2812����
  *
  *                ���������������
  * @author        Phage  
  *                Email:2687434412@qq.com
  * @version       2.1
  * @date          2020.3
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 Phage.
  * All rights reserved.</center></h2>
  *
  *S
  * This program is free software: you can redistribute it and/or modify
  * it under the terms of the GNU General Public License as published by
  * the Free Software Foundation, either version 3 of the License, or
  * (at your option) any later version.
  *
  * This program is distributed in the hope that it will be useful,
  * but WITHOUT ANY WARRANTY; without even the implied warranty of
  * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  * GNU General Public License for more details.
  *
  * You should have received a copy of the GNU General Public License
  * along with this program.  If not, see <https://www.gnu.org/licenses/>.
  ******************************************************************************
  */
  
#ifndef __WS2812CFG_H__
#define __WS2812CFG_H__

/* Includes ------------------------------------------------------------------*/
#include "tim.h"
#include "ws2812.h"

/* Define --------------------------------------------------------------------*/



/**
  * @defgroup 		   WS2812 
  * @brief			
  * @{
  */	
/**
  * @defgroup 			WS2812_CONFIG
  * @{
  */

/**
  * @defgroup 			WS2812_GLOBAL_CONFIG
  * @{
  */
#define WS2812_WRITE_MODE 			COMMON_MODE   /**<   WS2812��д��ģʽѡ��  */
/**  ���ڶ�ʱ���������޸�ֵ   */
/**   72MHZ Ԥ��Ƶϵ��0  ��װ����89*/
/**   84MHZ Ԥ��Ƶϵ��0  ��װ����99*/
#define WS2812_APB1_FREQ 			84          /**<  STM32 APB1Ƶ��  ��ѡ��  72MHZ 84MHZ*/
#define WS2812_MAX_NUM 				256           /**<  ����ģ����WS2812�������   */
#define WS2812_MODULE_NUM 			1             /**<   WS2812ģ������  */
#define WS2812_RGBBUFF				1			  /**<   ����WS2812Ĭ��RGB����  */
#define WS2812_DOUBLE_BUFF			0			  /**<   ����WS2812˫����(δ���)  */
/**
  * @}
  */



/**
  * @defgroup 			WS2812_MODULE_CONFIG
  * @{
  */
/**
  * @defgroup 			WS2812_MODULE_1_CONFIG
  * @{
  */
#if (WS2812_MODULE_NUM>=1)
    #define WS2812_1_ROWNUM 		16            /**<  WS2812����   */
    #define WS2812_1_COLNUM 		16             /**<   WS2812����  */
    #define WS2812_1_PWM_htim 		htim4         /**<   ������ģ��Ķ�ʱ��  */
    #define WS2812_1_PWM_CHANNEL 	TIM_CHANNEL_1 /**<   ������ģ��Ķ�ʱ��ͨ��  */
#endif
/**
  * @}
  */

/**
  * @defgroup 			WS2812_MODULE_2_CONFIG
  * @{
  */
#if (WS2812_MODULE_NUM>=2)
    #define WS2812_2_ROWNUM 		16            /**<  WS2812����   */
    #define WS2812_2_COLNUM 		16             /**<   WS2812����  */
    #define WS2812_2_PWM_htim 		htim4         /**<   ������ģ��Ķ�ʱ��  */
    #define WS2812_2_PWM_CHANNEL 	TIM_CHANNEL_1 /**<   ������ģ��Ķ�ʱ��ͨ��  */
#endif
/**
  * @}
  */
  
/**
  * @defgroup 			WS2812_MODULE_3_CONFIG
  * @{
  */
#if (WS2812_MODULE_NUM>=3)
    #define WS2812_3_ROWNUM 		1            /**<  WS2812����   */
    #define WS2812_3_COLNUM 		1             /**<   WS2812����  */
    #define WS2812_3_PWM_htim 		htim2         /**<   ������ģ��Ķ�ʱ��  */
    #define WS2812_3_PWM_CHANNEL 	TIM_CHANNEL_2 /**<   ������ģ��Ķ�ʱ��ͨ��  */
#endif
/**
  * @}
  */
  
/**
  * @defgroup 			WS2812_MODULE_4_CONFIG
  * @{
  */
#if (WS2812_MODULE_NUM>=4)
    #define WS2812_4_ROWNUM 		12            /**<  WS2812����   */
    #define WS2812_4_COLNUM 		1             /**<   WS2812����  */
    #define WS2812_4_PWM_htim 		htim2         /**<   ������ģ��Ķ�ʱ��  */
    #define WS2812_4_PWM_CHANNEL 	TIM_CHANNEL_2 /**<   ������ģ��Ķ�ʱ��ͨ��  */
#endif
/**
  * @}
  */
  
/**
  * @defgroup 			WS2812_MODULE_5_CONFIG
  * @{
  */
#if (WS2812_MODULE_NUM>=5)
    #define WS2812_5_ROWNUM 		1            /**<  WS2812����   */
    #define WS2812_5_COLNUM 		1             /**<   WS2812����  */
    #define WS2812_5_PWM_htim 		htim2         /**<   ������ģ��Ķ�ʱ��  */
    #define WS2812_5_PWM_CHANNEL 	TIM_CHANNEL_2 /**<   ������ģ��Ķ�ʱ��ͨ��  */
#endif
/**
  * @}
  */
  
/**
  * @defgroup 			WS2812_MODULE_6_CONFIG
  * @{
  */
#if (WS2812_MODULE_NUM>=6)
    #define WS2812_6_ROWNUM 		1            /**<  WS2812����   */
    #define WS2812_6_COLNUM 		1             /**<   WS2812����  */
    #define WS2812_6_PWM_htim 		htim2         /**<   ������ģ��Ķ�ʱ��  */
    #define WS2812_6_PWM_CHANNEL 	TIM_CHANNEL_2 /**<   ������ģ��Ķ�ʱ��ͨ��  */
#endif
/**
  * @}
  */
  
/**
  * @defgroup 			WS2812_MODULE_7_CONFIG
  * @{
  */
#if (WS2812_MODULE_NUM>=7)
    #define WS2812_7_ROWNUM 		1            /**<  WS2812����   */
    #define WS2812_7_COLNUM 		1             /**<   WS2812����  */
    #define WS2812_7_PWM_htim 		htim2         /**<   ������ģ��Ķ�ʱ��  */
    #define WS2812_7_PWM_CHANNEL 	TIM_CHANNEL_2 /**<   ������ģ��Ķ�ʱ��ͨ��  */
#endif
/**
  * @}
  */
  
/**
  * @defgroup 			WS2812_MODULE_8_CONFIG
  * @{
  */
#if (WS2812_MODULE_NUM>=8)
    #define WS2812_8_ROWNUM 		1            /**<  WS2812����   */
    #define WS2812_8_COLNUM 		1             /**<   WS2812����  */
    #define WS2812_8_PWM_htim 		htim2         /**<   ������ģ��Ķ�ʱ��  */
    #define WS2812_8_PWM_CHANNEL 	TIM_CHANNEL_2 /**<   ������ģ��Ķ�ʱ��ͨ��  */
#endif
/**
  * @}
  */
/**
  * @}
  */
/**
  * @}
  */
/**
  * @}
  */








#endif

/************************ (C) COPYRIGHT 2020 PHAGE *****END OF FILE*************/
