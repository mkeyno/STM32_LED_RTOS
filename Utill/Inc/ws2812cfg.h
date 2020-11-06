/**
  ******************************************************************************
  * @file          ws2812cfg.h
  * @brief         配置WS2812驱动
  *
  *                根据需求进行配置
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
#define WS2812_WRITE_MODE 			COMMON_MODE   /**<   WS2812的写入模式选择  */
/**  需在定时器配置中修改值   */
/**   72MHZ 预分频系数0  重装计数89*/
/**   84MHZ 预分频系数0  重装计数99*/
#define WS2812_APB1_FREQ 			84          /**<  STM32 APB1频率  可选择  72MHZ 84MHZ*/
#define WS2812_MAX_NUM 				256           /**<  单个模块中WS2812最大级联数   */
#define WS2812_MODULE_NUM 			1             /**<   WS2812模块数量  */
#define WS2812_RGBBUFF				1			  /**<   启用WS2812默认RGB缓存  */
#define WS2812_DOUBLE_BUFF			0			  /**<   启动WS2812双缓存(未完成)  */
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
    #define WS2812_1_ROWNUM 		16            /**<  WS2812行数   */
    #define WS2812_1_COLNUM 		16             /**<   WS2812列数  */
    #define WS2812_1_PWM_htim 		htim4         /**<   驱动此模块的定时器  */
    #define WS2812_1_PWM_CHANNEL 	TIM_CHANNEL_1 /**<   驱动此模块的定时器通道  */
#endif
/**
  * @}
  */

/**
  * @defgroup 			WS2812_MODULE_2_CONFIG
  * @{
  */
#if (WS2812_MODULE_NUM>=2)
    #define WS2812_2_ROWNUM 		16            /**<  WS2812行数   */
    #define WS2812_2_COLNUM 		16             /**<   WS2812列数  */
    #define WS2812_2_PWM_htim 		htim4         /**<   驱动此模块的定时器  */
    #define WS2812_2_PWM_CHANNEL 	TIM_CHANNEL_1 /**<   驱动此模块的定时器通道  */
#endif
/**
  * @}
  */
  
/**
  * @defgroup 			WS2812_MODULE_3_CONFIG
  * @{
  */
#if (WS2812_MODULE_NUM>=3)
    #define WS2812_3_ROWNUM 		1            /**<  WS2812行数   */
    #define WS2812_3_COLNUM 		1             /**<   WS2812列数  */
    #define WS2812_3_PWM_htim 		htim2         /**<   驱动此模块的定时器  */
    #define WS2812_3_PWM_CHANNEL 	TIM_CHANNEL_2 /**<   驱动此模块的定时器通道  */
#endif
/**
  * @}
  */
  
/**
  * @defgroup 			WS2812_MODULE_4_CONFIG
  * @{
  */
#if (WS2812_MODULE_NUM>=4)
    #define WS2812_4_ROWNUM 		12            /**<  WS2812行数   */
    #define WS2812_4_COLNUM 		1             /**<   WS2812列数  */
    #define WS2812_4_PWM_htim 		htim2         /**<   驱动此模块的定时器  */
    #define WS2812_4_PWM_CHANNEL 	TIM_CHANNEL_2 /**<   驱动此模块的定时器通道  */
#endif
/**
  * @}
  */
  
/**
  * @defgroup 			WS2812_MODULE_5_CONFIG
  * @{
  */
#if (WS2812_MODULE_NUM>=5)
    #define WS2812_5_ROWNUM 		1            /**<  WS2812行数   */
    #define WS2812_5_COLNUM 		1             /**<   WS2812列数  */
    #define WS2812_5_PWM_htim 		htim2         /**<   驱动此模块的定时器  */
    #define WS2812_5_PWM_CHANNEL 	TIM_CHANNEL_2 /**<   驱动此模块的定时器通道  */
#endif
/**
  * @}
  */
  
/**
  * @defgroup 			WS2812_MODULE_6_CONFIG
  * @{
  */
#if (WS2812_MODULE_NUM>=6)
    #define WS2812_6_ROWNUM 		1            /**<  WS2812行数   */
    #define WS2812_6_COLNUM 		1             /**<   WS2812列数  */
    #define WS2812_6_PWM_htim 		htim2         /**<   驱动此模块的定时器  */
    #define WS2812_6_PWM_CHANNEL 	TIM_CHANNEL_2 /**<   驱动此模块的定时器通道  */
#endif
/**
  * @}
  */
  
/**
  * @defgroup 			WS2812_MODULE_7_CONFIG
  * @{
  */
#if (WS2812_MODULE_NUM>=7)
    #define WS2812_7_ROWNUM 		1            /**<  WS2812行数   */
    #define WS2812_7_COLNUM 		1             /**<   WS2812列数  */
    #define WS2812_7_PWM_htim 		htim2         /**<   驱动此模块的定时器  */
    #define WS2812_7_PWM_CHANNEL 	TIM_CHANNEL_2 /**<   驱动此模块的定时器通道  */
#endif
/**
  * @}
  */
  
/**
  * @defgroup 			WS2812_MODULE_8_CONFIG
  * @{
  */
#if (WS2812_MODULE_NUM>=8)
    #define WS2812_8_ROWNUM 		1            /**<  WS2812行数   */
    #define WS2812_8_COLNUM 		1             /**<   WS2812列数  */
    #define WS2812_8_PWM_htim 		htim2         /**<   驱动此模块的定时器  */
    #define WS2812_8_PWM_CHANNEL 	TIM_CHANNEL_2 /**<   驱动此模块的定时器通道  */
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
