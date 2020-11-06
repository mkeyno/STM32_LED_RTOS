/**
  ******************************************************************************
  * @file          ws2812.c
  * @brief         STM32ʹ��PWM+DMA��ʽ����WS2812
  *
  *                ����ͷ�ļ��н������ò���ʹ��,��֧�ֶ�·WS2812����,Ч�ʽϸ�.
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
  *
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



/* Includes ------------------------------------------------------------------*/
#include "ws2812.h"
#include "tim.h"
#include "dma.h"

/* Variables -----------------------------------------------------------------*/
extern uint8_t WS2812_MODULE_SEND;

/*******************************************************************************
  * @brief          ����Ϩ��WS2812ģ��
  *
  *
  ******************************************************************************
  */
struct
{
    const uint16_t h[4];
    uint16_t data[24 * WS2812_MAX_NUM];
    const uint16_t t;
} WS2812_CLEAN_BUFF;


#if WS2812_MODULE_NUM>=1
struct
{
    const uint16_t h[4];
    uint16_t data[24 * WS2812_1_ROWNUM * WS2812_1_COLNUM];
    const uint16_t t;
} WS2812_1_BUFF;

#define WS2812_1_BUFFADDR ((uint32_t *)&WS2812_1_BUFF.h[0])
#define WS2812_1_BUFFSIZE (WS2812_1_NUM*24+5)
#endif

#if WS2812_MODULE_NUM>=2
struct
{
    const uint16_t h[4];
    uint16_t data[24 * WS2812_2_ROWNUM * WS2812_2_COLNUM];
    const uint16_t t;
} WS2812_2_BUFF;

#define WS2812_2_BUFFADDR ((uint32_t *)&WS2812_2_BUFF.h[0])
#define WS2812_2_BUFFSIZE (WS2812_2_NUM*24+5)
#endif

#if WS2812_MODULE_NUM>=3
struct
{
    const uint16_t h[4];
    uint16_t data[24 * WS2812_3_ROWNUM * WS2812_3_COLNUM];
    const uint16_t t;
} WS2812_3_BUFF;

#define WS2812_3_BUFFADDR ((uint32_t *)&WS2812_3_BUFF.h[0])
#define WS2812_3_BUFFSIZE (WS2812_3_NUM*24+5)
#endif

#if WS2812_MODULE_NUM>=4
struct
{
    const uint16_t h[4];
    uint16_t data[24 * WS2812_4_ROWNUM * WS2812_4_COLNUM];
    const uint16_t t;
} WS2812_4_BUFF;

#define WS2812_4_BUFFADDR ((uint32_t *)&WS2812_4_BUFF.h[0])
#define WS2812_4_BUFFSIZE (WS2812_4_NUM*24+5)
#endif

#if WS2812_MODULE_NUM>=5
struct
{
    const uint16_t h[4];
    uint16_t data[24 * WS2812_5_ROWNUM * WS2812_5_COLNUM];
    const uint16_t t;
} WS2812_5_BUFF;

#define WS2812_5_BUFFADDR ((uint32_t *)&WS2812_5_BUFF.h[0])
#define WS2812_5_BUFFSIZE (WS2812_5_NUM*24+5)
#endif

#if WS2812_MODULE_NUM>=6
struct
{
    const uint16_t h[4];
    uint16_t data[24 * WS2812_6_ROWNUM * WS2812_6_COLNUM];
    const uint16_t t;
} WS2812_6_BUFF;

#define WS2812_6_BUFFADDR ((uint32_t *)&WS2812_6_BUFF.h[0])
#define WS2812_6_BUFFSIZE (WS2812_6_NUM*24+5)
#endif

#if WS2812_MODULE_NUM>=7
struct
{
    const uint16_t h[4];
    uint16_t data[24 * WS2812_7_ROWNUM * WS2812_7_COLNUM];
    const uint16_t t;
} WS2812_7_BUFF;

#define WS2812_7_BUFFADDR ((uint32_t *)&WS2812_7_BUFF.h[0])
#define WS2812_7_BUFFSIZE (WS2812_7_NUM*24+5)
#endif

#if WS2812_MODULE_NUM>=8
struct
{
    const uint16_t h[4];
    uint16_t data[24 * WS2812_8_ROWNUM * WS2812_8_COLNUM];
    const uint16_t t;
} WS2812_8_BUFF;

#define WS2812_8_BUFFADDR ((uint32_t *)&WS2812_8_BUFF.h[0])
#define WS2812_8_BUFFSIZE (WS2812_8_NUM*24+5)
#endif


/* Function prototypes -------------------------------------------------------*/
void WS2812_Clean(uint16_t WS2812_MODULE);
void WS2812_Clean_Buff(uint16_t WS2812_MODULE);
void WS2812_Clean_RGBBuff(uint16_t WS2812_MODULE);
void WS2812_Write(uint32_t *RGB_BUFFADDR, uint16_t WS2812_MODULE);
void WS2812_Write_Mirror(uint32_t *RGB_BUFFADDR, uint16_t WS2812_MODULE);
void WS2812_Send(uint16_t WS2812_MODULE);



/* Code ----------------------------------------------------------------------*/





/**
  * @defgroup       WS2812
  * @brief
  * @{
  */



/**
  * @defgroup       WS2812_CLEAN
  * @brief
  * @{
  */
/**
  ******************************************************************************
  * @fn             void WS2812_Clean(uint16_t WS2812_MODULE)
  * @brief          ���
  *
  *                 ��ָ����WS2812ģ��Ϩ��,����ı��Ӧ��buff
  * @pre            ָ��ģ���Ѷ���
  * @param          WS2812_MODULE:ģ�����
  * @return         None
  * @par ʾ��1:
  * @code
  *                 WS2812_Clean(WS2812_MODULE_1);
  *                 Ϩ��WS2812ģ��1
  * @endcode
  * @par ʾ��2:
  * @code
  *                 WS2812_Clean(WS2812_MODULE_ALL);
  *                 Ϩ������WS2812ģ��,ǰ��ģ����������1
  * @endcode
  ******************************************************************************
  */
void WS2812_Clean(uint16_t WS2812_MODULE)
{
    switch (WS2812_MODULE)
    {
#if WS2812_MODULE_NUM>1
    case WS2812_MODULE_ALL:
        break;
#endif
#ifdef WS2812_MODULE_1
    case WS2812_MODULE_1:
        WS2812_MODULE_SEND = WS2812_MODULE_1;
        HAL_TIM_PWM_Start_DMA(&WS2812_1_PWM_htim, WS2812_1_PWM_CHANNEL, (uint32_t *)&WS2812_CLEAN_BUFF, WS2812_1_BUFFSIZE);
        break;
#endif
#ifdef WS2812_MODULE_2
    case WS2812_MODULE_2:
        WS2812_MODULE_SEND = WS2812_MODULE_2;
        HAL_TIM_PWM_Start_DMA(&WS2812_2_PWM_htim, WS2812_2_PWM_CHANNEL, (uint32_t *)&WS2812_CLEAN_BUFF, WS2812_2_BUFFSIZE);
        break;
#endif
#ifdef WS2812_MODULE_3
    case WS2812_MODULE_3:
        WS2812_MODULE_SEND = WS2812_MODULE_3;
        HAL_TIM_PWM_Start_DMA(&WS2812_3_PWM_htim, WS2812_3_PWM_CHANNEL, (uint32_t *)&WS2812_CLEAN_BUFF, WS2812_3_BUFFSIZE);
        break;
#endif
#ifdef WS2812_MODULE_4
    case WS2812_MODULE_4:
        WS2812_MODULE_SEND = WS2812_MODULE_4;
        HAL_TIM_PWM_Start_DMA(&WS2812_4_PWM_htim, WS2812_4_PWM_CHANNEL, (uint32_t *)&WS2812_CLEAN_BUFF, WS2812_4_BUFFSIZE);
        break;
#endif
#ifdef WS2812_MODULE_5
    case WS2812_MODULE_5:
        WS2812_MODULE_SEND = WS2812_MODULE_5;
        HAL_TIM_PWM_Start_DMA(&WS2812_5_PWM_htim, WS2812_5_PWM_CHANNEL, (uint32_t *)&WS2812_CLEAN_BUFF, WS2812_5_BUFFSIZE);
        break;
#endif
#ifdef WS2812_MODULE_6
    case WS2812_MODULE_6:
        WS2812_MODULE_SEND = WS2812_MODULE_6;
        HAL_TIM_PWM_Start_DMA(&WS2812_6_PWM_htim, WS2812_6_PWM_CHANNEL, (uint32_t *)&WS2812_CLEAN_BUFF, WS2812_6_BUFFSIZE);
        break;
#endif
#ifdef WS2812_MODULE_7
    case WS2812_MODULE_7:
        WS2812_MODULE_SEND = WS2812_MODULE_7;
        HAL_TIM_PWM_Start_DMA(&WS2812_7_PWM_htim, WS2812_7_PWM_CHANNEL, (uint32_t *)&WS2812_CLEAN_BUFF, WS2812_7_BUFFSIZE);
        break;
#endif
#ifdef WS2812_MODULE_8
    case WS2812_MODULE_8:
        WS2812_MODULE_SEND = WS2812_MODULE_8;
        HAL_TIM_PWM_Start_DMA(&WS2812_8_PWM_htim, WS2812_8_PWM_CHANNEL, (uint32_t *)&WS2812_CLEAN_BUFF, WS2812_8_BUFFSIZE);
        break;
#endif
    default:
        break;
    }
}
/**
  * @}
  */




/**
  * @defgroup 		WS2812_CLEAN_BUFF
  * @brief			��ջ���������
  * @{
  */
/**
  ******************************************************************************
  * @fn 			void WS2812_Clean_Buff(uint16_t WS2812_MODULE)
  * @brief 			�������������
  *
  *					ָ��ģ��Ļ��������ݱ����
  * @pre			ָ��ģ���Ѷ���
  * @param 			WS2812_MODULE:ģ�����
  * @return 		None
  * @par ʾ��:
  * @code
  *					WS2812_Clean_Buff(WS2812_MODULE_1);
  *                 ���WS2812ģ��һ�Ļ���������
  * @endcode
  ******************************************************************************
  */
void WS2812_Clean_Buff(uint16_t WS2812_MODULE) {
    switch(WS2812_MODULE) {
#ifdef WS2812_MODULE_1
    case WS2812_MODULE_1:
        for (uint16_t ws2812bit_bit = 0; ws2812bit_bit < 24 * WS2812_1_NUM; ws2812bit_bit++)
        {
            WS2812_1_BUFF.data[ws2812bit_bit] = WS2812_RESET;
        }
        break;
#endif
#ifdef WS2812_MODULE_2
    case WS2812_MODULE_2:
        for (uint16_t ws2812bit_bit = 0; ws2812bit_bit < 24 * WS2812_2_NUM; ws2812bit_bit++)
        {
            WS2812_2_BUFF.data[ws2812bit_bit] = WS2812_RESET;
        }
        break;
#endif
#ifdef WS2812_MODULE_3
    case WS2812_MODULE_3:
        for (uint16_t ws2812bit_bit = 0; ws2812bit_bit < 24 * WS2812_3_NUM; ws2812bit_bit++)
        {
            WS2812_3_BUFF.data[ws2812bit_bit] = WS2812_RESET;
        }
        break;
#endif
#ifdef WS2812_MODULE_4
    case WS2812_MODULE_4:
        for (uint16_t ws2812bit_bit = 0; ws2812bit_bit < 24 * WS2812_4_NUM; ws2812bit_bit++)
        {
            WS2812_4_BUFF.data[ws2812bit_bit] = WS2812_RESET;
        }
        break;
#endif
#ifdef WS2812_MODULE_5
    case WS2812_MODULE_5:
        for (uint16_t ws2812bit_bit = 0; ws2812bit_bit < 24 * WS2812_5_NUM; ws2812bit_bit++)
        {
            WS2812_5_BUFF.data[ws2812bit_bit] = WS2812_RESET;
        }
        break;
#endif
#ifdef WS2812_MODULE_6
    case WS2812_MODULE_6:
        for (uint16_t ws2812bit_bit = 0; ws2812bit_bit < 24 * WS2812_6_NUM; ws2812bit_bit++)
        {
            WS2812_6_BUFF.data[ws2812bit_bit] = WS2812_RESET;
        }
        break;
#endif
#ifdef WS2812_MODULE_7
    case WS2812_MODULE_7:
        for (uint16_t ws2812bit_bit = 0; ws2812bit_bit < 24 * WS2812_7_NUM; ws2812bit_bit++)
        {
            WS2812_7_BUFF.data[ws2812bit_bit] = WS2812_RESET;
        }
        break;
#endif
#ifdef WS2812_MODULE_8
    case WS2812_MODULE_8:
        for (uint16_t ws2812bit_bit = 0; ws2812bit_bit < 24 * WS2812_8_NUM; ws2812bit_bit++)
        {
            WS2812_8_BUFF.data[ws2812bit_bit] = WS2812_RESET;
        }
        break;
#endif
    }
}

/**
  * @}
  */

#if (WS2812_RGBBUFF==1)
/**
  * @defgroup 		WS2812_CLEAN_RGBBUFF
  * @brief			���RGB������
  * @{
  */
/**
  ******************************************************************************
  * @fn 			void WS2812_Clean_RGBBuff(uint16_t WS2812_MODULE)
  * @brief 			���RGB������
  *
  *					���ָ��ģ��RGB������,
  * @pre			ָ��ģ���Ѷ���
  * @param 			WS2812_MODULE:ģ�����
  * @return 		None
  * @par ʾ��:
  * @code
  *					WS2812_Clean_RGBBuff(WS2812_MODULE_1);
  *                 ���WS2812ģ��һ��RGB������
  * @endcode
  ******************************************************************************
  */
void WS2812_Clean_RGBBuff(uint16_t WS2812_MODULE) {
    switch(WS2812_MODULE) {
#ifdef WS2812_MODULE_1
    case WS2812_MODULE_1:
        for(uint16_t row=0; row<WS2812_1_ROWNUM; row++) {
            for(uint16_t col=0; col<WS2812_1_COLNUM; col++) {
                WS2812_1_RGBBUFF[row][col].R=0;
                WS2812_1_RGBBUFF[row][col].G=0;
                WS2812_1_RGBBUFF[row][col].B=0;
            }
        }
        break;
#endif
#ifdef WS2812_MODULE_2
    case WS2812_MODULE_2:
        for(uint16_t row=0; row<WS2812_2_ROWNUM; row++) {
            for(uint16_t col=0; col<WS2812_2_COLNUM; col++) {
                WS2812_2_RGBBUFF[row][col].R=0;
                WS2812_2_RGBBUFF[row][col].G=0;
                WS2812_2_RGBBUFF[row][col].B=0;
            }
        }
        break;
#endif
#ifdef WS2812_MODULE_3
    case WS2812_MODULE_3:
        for(uint16_t row=0; row<WS2812_3_ROWNUM; row++) {
            for(uint16_t col=0; col<WS2812_3_COLNUM; col++) {
                WS2812_3_RGBBUFF[row][col].R=0;
                WS2812_3_RGBBUFF[row][col].G=0;
                WS2812_3_RGBBUFF[row][col].B=0;
            }
        }
        break;
#endif
#ifdef WS2812_MODULE_4
    case WS2812_MODULE_4:
        for(uint16_t row=0; row<WS2812_4_ROWNUM; row++) {
            for(uint16_t col=0; col<WS2812_4_COLNUM; col++) {
                WS2812_4_RGBBUFF[row][col].R=0;
                WS2812_4_RGBBUFF[row][col].G=0;
                WS2812_4_RGBBUFF[row][col].B=0;
            }
        }
        break;
#endif
#ifdef WS2812_MODULE_5
    case WS2812_MODULE_5:
        for(uint16_t row=0; row<WS2812_5_ROWNUM; row++) {
            for(uint16_t col=0; col<WS2812_5_COLNUM; col++) {
                WS2812_5_RGBBUFF[row][col].R=0;
                WS2812_5_RGBBUFF[row][col].G=0;
                WS2812_5_RGBBUFF[row][col].B=0;
            }
        }
        break;
#endif
#ifdef WS2812_MODULE_6
    case WS2812_MODULE_6:
        for(uint16_t row=0; row<WS2812_6_ROWNUM; row++) {
            for(uint16_t col=0; col<WS2812_6_COLNUM; col++) {
                WS2812_6_RGBBUFF[row][col].R=0;
                WS2812_6_RGBBUFF[row][col].G=0;
                WS2812_6_RGBBUFF[row][col].B=0;
            }
        }
        break;
#endif
#ifdef WS2812_MODULE_7
    case WS2812_MODULE_7:
        for(uint16_t row=0; row<WS2812_7_ROWNUM; row++) {
            for(uint16_t col=0; col<WS2812_7_COLNUM; col++) {
                WS2812_7_RGBBUFF[row][col].R=0;
                WS2812_7_RGBBUFF[row][col].G=0;
                WS2812_7_RGBBUFF[row][col].B=0;
            }
        }
        break;
#endif
#ifdef WS2812_MODULE_8
    case WS2812_MODULE_8:
        for(uint16_t row=0; row<WS2812_8_ROWNUM; row++) {
            for(uint16_t col=0; col<WS2812_8_COLNUM; col++) {
                WS2812_8_RGBBUFF[row][col].R=0;
                WS2812_8_RGBBUFF[row][col].G=0;
                WS2812_8_RGBBUFF[row][col].B=0;
            }
        }
        break;
#endif
    }
}
/**
  * @}
  */
#endif




/**
  * @defgroup       WS2812_WRITE
  * @brief          ��RGB����������д�뻺����
  * @{
  */

/**
  ******************************************************************************
  * @fn             void WS2812_Write(uint32_t *RGB_BUFFADDR, uint16_t WS2812_MODULE)
  * @brief          д��
  *
  *                 ��ָ����ַ������д��ָ����ģ��
  * @pre            ָ��ģ���Ѷ��������ݷ���Ҫ��
  * @param          WS2812_MODULE:ģ�����
  * @param  [in]    *RGB_BUFFADDR:ָ�����ݵĵ�ַ,Ҫ��uint32_t *����
  * @return         none
  * @par ʾ��:
  * @code
  *                 WS2812_Write((uint32_t *)RGB_BUFF1, WS2812_MODULE_1);
  *                 ��ָ����ַ������д��WS2812ģ��1
  * @endcode
  ******************************************************************************
  */
#if WS2812_WRITE_MODE==COMMON_MODE
void WS2812_Write(uint32_t *RGB_BUFFADDR, uint16_t WS2812_MODULE)
{
    uint32_t *WS2812_BUFFADDR = NULL;
    uint16_t WS2812_NUM = NULL;

    switch (WS2812_MODULE)
    {
#ifdef WS2812_MODULE_1
    case WS2812_MODULE_1:
        WS2812_BUFFADDR = WS2812_1_BUFFADDR;
        WS2812_NUM = WS2812_1_NUM;
        break;
#endif
#ifdef WS2812_MODULE_2
    case WS2812_MODULE_2:
        WS2812_BUFFADDR = WS2812_2_BUFFADDR;
        WS2812_NUM = WS2812_2_NUM;
        break;
#endif
#ifdef WS2812_MODULE_3
    case WS2812_MODULE_3:
        WS2812_BUFFADDR = WS2812_3_BUFFADDR;
        WS2812_NUM = WS2812_3_NUM;
        break;
#endif
#ifdef WS2812_MODULE_4
    case WS2812_MODULE_4:
        WS2812_BUFFADDR = WS2812_4_BUFFADDR;
        WS2812_NUM = WS2812_4_NUM;
        break;
#endif
#ifdef WS2812_MODULE_5
    case WS2812_MODULE_5:
        WS2812_BUFFADDR = WS2812_5_BUFFADDR;
        WS2812_NUM = WS2812_5_NUM;
        break;
#endif
#ifdef WS2812_MODULE_6
    case WS2812_MODULE_6:
        WS2812_BUFFADDR = WS2812_6_BUFFADDR;
        WS2812_NUM = WS2812_6_NUM;
        break;
#endif
#ifdef WS2812_MODULE_7
    case WS2812_MODULE_7:
        WS2812_BUFFADDR = WS2812_7_BUFFADDR;
        WS2812_NUM = WS2812_7_NUM;
        break;
#endif
#ifdef WS2812_MODULE_8
    case WS2812_MODULE_8:
        WS2812_BUFFADDR = WS2812_8_BUFFADDR;
        WS2812_NUM = WS2812_8_NUM;
        break;
#endif
    }
    uint8_t temp;

    uint8_t *RGB_BUFFADDR_TEMP = (uint8_t *)RGB_BUFFADDR - 3;
    uint8_t *RGB_BUFFADDR_TEMP_R = RGB_BUFFADDR_TEMP + 0;
    uint8_t *RGB_BUFFADDR_TEMP_G = RGB_BUFFADDR_TEMP + 1;
    uint8_t *RGB_BUFFADDR_TEMP_B = RGB_BUFFADDR_TEMP + 2;

    uint16_t *WS2812_BUFFADDR_TEMP = (uint16_t *)WS2812_BUFFADDR + 4 - 24;
    uint16_t *WS2812_BUFFADDR_TEMP_G = WS2812_BUFFADDR_TEMP + 0;
    uint16_t *WS2812_BUFFADDR_TEMP_R = WS2812_BUFFADDR_TEMP + 8;
    uint16_t *WS2812_BUFFADDR_TEMP_B = WS2812_BUFFADDR_TEMP + 16;

    for (uint16_t ws2812_bit = 0; ws2812_bit < WS2812_NUM; ws2812_bit++)
    {
        RGB_BUFFADDR_TEMP_R += 3;
        RGB_BUFFADDR_TEMP_G += 3;
        RGB_BUFFADDR_TEMP_B += 3;

        WS2812_BUFFADDR_TEMP_G += 24;
        WS2812_BUFFADDR_TEMP_R += 24;
        WS2812_BUFFADDR_TEMP_B += 24;
        for (uint8_t bit = 0; bit < 8; bit++)
        {
            temp = 0x80 >> bit;
            *(WS2812_BUFFADDR_TEMP_G + bit) = *RGB_BUFFADDR_TEMP_G & temp ? WS2812_SET : WS2812_RESET;
            *(WS2812_BUFFADDR_TEMP_R + bit) = *RGB_BUFFADDR_TEMP_R & temp ? WS2812_SET : WS2812_RESET;
            *(WS2812_BUFFADDR_TEMP_B + bit) = *RGB_BUFFADDR_TEMP_B & temp ? WS2812_SET : WS2812_RESET;
        }
    }
}
#elif WS2812_WRITE_MODE==DMA_MODE
#error
#else
#error
#endif
/**
  * @}
  */




/**
  * @defgroup       WS2812_WRITE_MIRROR
  * @brief          ��RGB�����������������о����д�뻺����
  * @{
  */

/**
  ******************************************************************************
  * @fn             void WS2812_Write(uint32_t *RGB_BUFFADDR, uint16_t WS2812_MODULE)
  * @brief          д��
  *
  *                 ��ָ����ַ�������������о����д��ָ����ģ��
  * @pre            ָ��ģ���Ѷ��������ݷ���Ҫ��
  * @param          WS2812_MODULE:ģ�����
  * @param  [in]    *RGB_BUFFADDR:ָ�����ݵĵ�ַ,Ҫ��uint32_t *����
  * @return         none
  * @par ʾ��:
  * @code
  *                 WS2812_Write_Mirror((uint32_t *)RGB_BUFF1, WS2812_MODULE_1);
  *                 ��ָ����ַ������д��WS2812ģ��1
  * @endcode
  ******************************************************************************
  */
#if WS2812_WRITE_MODE==COMMON_MODE
void WS2812_Write_Mirror(uint32_t *RGB_BUFFADDR, uint16_t WS2812_MODULE)
{
    uint32_t *WS2812_BUFFADDR = NULL;
    uint16_t WS2812_NUM = NULL;

    int16_t ws2812_rownum=0;
    uint16_t WS2812_COLNUM;

    switch (WS2812_MODULE)
    {
#ifdef WS2812_MODULE_1
    case WS2812_MODULE_1:
        WS2812_BUFFADDR = WS2812_1_BUFFADDR;
        WS2812_NUM = WS2812_1_NUM;
        WS2812_COLNUM=WS2812_1_COLNUM;
        break;
#endif
#ifdef WS2812_MODULE_2
    case WS2812_MODULE_2:
        WS2812_BUFFADDR = WS2812_2_BUFFADDR;
        WS2812_NUM = WS2812_2_NUM;
        break;
#endif
#ifdef WS2812_MODULE_3
    case WS2812_MODULE_3:
        WS2812_BUFFADDR = WS2812_3_BUFFADDR;
        WS2812_NUM = WS2812_3_NUM;
        break;
#endif
#ifdef WS2812_MODULE_4
    case WS2812_MODULE_4:
        WS2812_BUFFADDR = WS2812_4_BUFFADDR;
        WS2812_NUM = WS2812_4_NUM;
        break;
#endif
#ifdef WS2812_MODULE_5
    case WS2812_MODULE_5:
        WS2812_BUFFADDR = WS2812_5_BUFFADDR;
        WS2812_NUM = WS2812_5_NUM;
        break;
#endif
#ifdef WS2812_MODULE_6
    case WS2812_MODULE_6:
        WS2812_BUFFADDR = WS2812_6_BUFFADDR;
        WS2812_NUM = WS2812_6_NUM;
        break;
#endif
#ifdef WS2812_MODULE_7
    case WS2812_MODULE_7:
        WS2812_BUFFADDR = WS2812_7_BUFFADDR;
        WS2812_NUM = WS2812_7_NUM;
        break;
#endif
#ifdef WS2812_MODULE_8
    case WS2812_MODULE_8:
        WS2812_BUFFADDR = WS2812_8_BUFFADDR;
        WS2812_NUM = WS2812_8_NUM;
        break;
#endif
    }
    uint8_t temp;

    uint8_t *RGB_BUFFADDR_TEMP = (uint8_t *)RGB_BUFFADDR - 3*WS2812_COLNUM;
    uint8_t *RGB_BUFFADDR_TEMP_R = RGB_BUFFADDR_TEMP + 0;
    uint8_t *RGB_BUFFADDR_TEMP_G = RGB_BUFFADDR_TEMP + 1;
    uint8_t *RGB_BUFFADDR_TEMP_B = RGB_BUFFADDR_TEMP + 2;

    uint16_t *WS2812_BUFFADDR_TEMP = (uint16_t *)WS2812_BUFFADDR + 4 -24;

    uint16_t *WS2812_BUFFADDR_TEMP_G = WS2812_BUFFADDR_TEMP + 0;
    uint16_t *WS2812_BUFFADDR_TEMP_R = WS2812_BUFFADDR_TEMP + 8;
    uint16_t *WS2812_BUFFADDR_TEMP_B = WS2812_BUFFADDR_TEMP + 16;

    for (uint16_t ws2812_bit = 0; ws2812_bit < WS2812_NUM; ws2812_bit++)
    {
        if(ws2812_bit%WS2812_COLNUM==0) {
            ws2812_rownum+=1;
            RGB_BUFFADDR_TEMP_R+=3*WS2812_COLNUM;
            RGB_BUFFADDR_TEMP_G+=3*WS2812_COLNUM;
            RGB_BUFFADDR_TEMP_B+=3*WS2812_COLNUM;
        }
        else {
            if(ws2812_rownum%2==0) {
                RGB_BUFFADDR_TEMP_R -= 3;
                RGB_BUFFADDR_TEMP_G -= 3;
                RGB_BUFFADDR_TEMP_B -= 3;
            }
            else if (ws2812_rownum%2==1) {
                RGB_BUFFADDR_TEMP_R += 3;
                RGB_BUFFADDR_TEMP_G += 3;
                RGB_BUFFADDR_TEMP_B += 3;
            }
        }


        WS2812_BUFFADDR_TEMP_G += 24;
        WS2812_BUFFADDR_TEMP_R += 24;
        WS2812_BUFFADDR_TEMP_B += 24;

        for (uint8_t bit = 0; bit < 8; bit++)
        {
            temp = 0x80 >> bit;
            *(WS2812_BUFFADDR_TEMP_G + bit) = *RGB_BUFFADDR_TEMP_G & temp ? WS2812_SET : WS2812_RESET;
            *(WS2812_BUFFADDR_TEMP_R + bit) = *RGB_BUFFADDR_TEMP_R & temp ? WS2812_SET : WS2812_RESET;
            *(WS2812_BUFFADDR_TEMP_B + bit) = *RGB_BUFFADDR_TEMP_B & temp ? WS2812_SET : WS2812_RESET;
        }
    }
}
#elif WS2812_WRITE_MODE==DMA_MODE
#error
#else
#error
#endif
/**
  * @}
  */



/**
  * @defgroup       WS2812_SEND
  * @brief          ���ͻ���������
  * @{
  */
/**
  ******************************************************************************
  * @fn             void WS2812_Send(uint16_t WS2812_MODULE)
  * @brief          ����
  *
  *                 ��ָ��WS2812ģ��Ļ�������������Ӧ��WS2812ģ��
  * @pre            ָ��ģ���Ѷ���
  * @param          WS2812_MODULE:ģ�����
  * @return         none
  * @par ʾ��:
  * @code
  *                 WS2812_Send(WS2812_MODULE_1);
  *                 ����WS2812ģ��1�Ļ��浽ģ��
  * @endcode
  ******************************************************************************
  */
void WS2812_Send(uint16_t WS2812_MODULE)
{
    switch (WS2812_MODULE)
    {
#ifdef WS2812_MODULE_1
    case WS2812_MODULE_1:
        WS2812_MODULE_SEND = WS2812_MODULE_1;
        HAL_TIM_PWM_Start_DMA(&WS2812_1_PWM_htim, WS2812_1_PWM_CHANNEL, (uint32_t *)&WS2812_1_BUFF, WS2812_1_BUFFSIZE);
        break;
#endif
#ifdef WS2812_MODULE_2
    case WS2812_MODULE_2:
        WS2812_MODULE_SEND = WS2812_MODULE_2;
        HAL_TIM_PWM_Start_DMA(&WS2812_2_PWM_htim, WS2812_2_PWM_CHANNEL, (uint32_t *)&WS2812_2_BUFF, WS2812_2_BUFFSIZE);
        break;
#endif
#ifdef WS2812_MODULE_3
    case WS2812_MODULE_3:
        WS2812_MODULE_SEND = WS2812_MODULE_3;
        HAL_TIM_PWM_Start_DMA(&WS2812_3_PWM_htim, WS2812_3_PWM_CHANNEL, (uint32_t *)&WS2812_3_BUFF, WS2812_3_BUFFSIZE);
        break;
#endif
#ifdef WS2812_MODULE_4
    case WS2812_MODULE_4:
        WS2812_MODULE_SEND = WS2812_MODULE_4;
        HAL_TIM_PWM_Start_DMA(&WS2812_4_PWM_htim, WS2812_4_PWM_CHANNEL, (uint32_t *)&WS2812_4_BUFF, WS2812_4_BUFFSIZE);
        break;
#endif
#ifdef WS2812_MODULE_5
    case WS2812_MODULE_5:
        WS2812_MODULE_SEND = WS2812_MODULE_5;
        HAL_TIM_PWM_Start_DMA(&WS2812_5_PWM_htim, WS2812_5_PWM_CHANNEL, (uint32_t *)&WS2812_5_BUFF, WS2812_5_BUFFSIZE);
        break;
#endif
#ifdef WS2812_MODULE_6
    case WS2812_MODULE_6:
        WS2812_MODULE_SEND = WS2812_MODULE_6;
        HAL_TIM_PWM_Start_DMA(&WS2812_6_PWM_htim, WS2812_6_PWM_CHANNEL, (uint32_t *)&WS2812_6_BUFF, WS2812_6_BUFFSIZE);
        break;
#endif
#ifdef WS2812_MODULE_7
    case WS2812_MODULE_7:
        WS2812_MODULE_SEND = WS2812_MODULE_7;
        HAL_TIM_PWM_Start_DMA(&WS2812_7_PWM_htim, WS2812_7_PWM_CHANNEL, (uint32_t *)&WS2812_7_BUFF, WS2812_7_BUFFSIZE);
        break;
#endif
#ifdef WS2812_MODULE_8
    case WS2812_MODULE_8:
        WS2812_MODULE_SEND = WS2812_MODULE_8;
        HAL_TIM_PWM_Start_DMA(&WS2812_8_PWM_htim, WS2812_8_PWM_CHANNEL, (uint32_t *)&WS2812_8_BUFF, WS2812_8_BUFFSIZE);
        break;
#endif
    }
}
/**
  * @}
  */



/**
  * @defgroup       WS2812_INIT
  * @brief			��WS2812���г�ʼ��
  * @{
  */

/**
  ******************************************************************************
  * @fn             void WS2812_Init(void)
  * @brief          ��ʼ��WS2812
  *
  *                 ��WS2812���г�ʼ��
  * @return         none
  * @par ʾ��:
  * @code
  *                 WS2812_Init();
  * @endcode
  ******************************************************************************
  */
void WS2812_Init(void)
{
    for (uint16_t ws2812bit_bit = 0; ws2812bit_bit < 24 * WS2812_MAX_NUM; ws2812bit_bit++)
    {
        WS2812_CLEAN_BUFF.data[ws2812bit_bit] = WS2812_RESET;
    }
#ifdef WS2812_MODULE_1
    WS2812_Clean_Buff(WS2812_MODULE_1);
#endif
#ifdef WS2812_MODULE_2
    WS2812_Clean_Buff(WS2812_MODULE_2);
#endif
#ifdef WS2812_MODULE_3
    WS2812_Clean_Buff(WS2812_MODULE_3);
#endif
#ifdef WS2812_MODULE_4
    WS2812_Clean_Buff(WS2812_MODULE_4);
#endif
#ifdef WS2812_MODULE_5
    WS2812_Clean_Buff(WS2812_MODULE_5);
#endif
#ifdef WS2812_MODULE_6
    WS2812_Clean_Buff(WS2812_MODULE_6);
#endif
#ifdef WS2812_MODULE_7
    WS2812_Clean_Buff(WS2812_MODULE_7);
#endif
#ifdef WS2812_MODULE_8
    WS2812_Clean_Buff(WS2812_MODULE_8);
#endif

}

/**
  * @}
  */









/**
  * @defgroup       WS2812_SEND_FINISHED
  * @brief
  * @{
  */
/**
  ******************************************************************************
  * @fn             HAL_TIM_PWM_PulseFinishedCallback(TIM_HandleTypeDef *htim)
  * @brief          WS2812������ɻص�
  *
  *                 ������ɺ�ֹͣ���Ͳ����ֵ͵�ƽ״̬
  * @pre            ָ��ģ���Ѷ���,�ҷ������
  * @param          *htim:�����жϵĶ�ʱ��
  * @return         none
  ******************************************************************************
  */
void HAL_TIM_PWM_PulseFinishedCallback(TIM_HandleTypeDef *htim)
{
    switch (WS2812_MODULE_SEND)
    {
    case WS2812_MODULE_NULL:
        break;
#ifdef WS2812_MODULE_1
    case WS2812_MODULE_1:
        WS2812_MODULE_SEND = WS2812_MODULE_NULL;
        HAL_TIM_PWM_Stop_DMA(&WS2812_1_PWM_htim, WS2812_1_PWM_CHANNEL);
        break;
#endif
#ifdef WS2812_MODULE_2
    case WS2812_MODULE_2:
        WS2812_MODULE_SEND = WS2812_MODULE_NULL;
        HAL_TIM_PWM_Stop_DMA(&WS2812_2_PWM_htim, WS2812_2_PWM_CHANNEL);
        break;
#endif
#ifdef WS2812_MODULE_3
    case WS2812_MODULE_3:
        WS2812_MODULE_SEND = WS2812_MODULE_NULL;
        HAL_TIM_PWM_Stop_DMA(&WS2812_3_PWM_htim, WS2812_3_PWM_CHANNEL);
        break;
#endif
#ifdef WS2812_MODULE_4
    case WS2812_MODULE_4:
        WS2812_MODULE_SEND = WS2812_MODULE_NULL;
        HAL_TIM_PWM_Stop_DMA(&WS2812_4_PWM_htim, WS2812_4_PWM_CHANNEL);
        break;
#endif
#ifdef WS2812_MODULE_5
    case WS2812_MODULE_5:
        WS2812_MODULE_SEND = WS2812_MODULE_NULL;
        HAL_TIM_PWM_Stop_DMA(&WS2812_5_PWM_htim, WS2812_5_PWM_CHANNEL);
        break;
#endif
#ifdef WS2812_MODULE_6
    case WS2812_MODULE_6:
        WS2812_MODULE_SEND = WS2812_MODULE_NULL;
        HAL_TIM_PWM_Stop_DMA(&WS2812_6_PWM_htim, WS2812_6_PWM_CHANNEL);
        break;
#endif
#ifdef WS2812_MODULE_7
    case WS2812_MODULE_7:
        WS2812_MODULE_SEND = WS2812_MODULE_NULL;
        HAL_TIM_PWM_Stop_DMA(&WS2812_7_PWM_htim, WS2812_7_PWM_CHANNEL);
        break;
#endif
#ifdef WS2812_MODULE_8
    case WS2812_MODULE_8:
        WS2812_MODULE_SEND = WS2812_MODULE_NULL;
        HAL_TIM_PWM_Stop_DMA(&WS2812_8_PWM_htim, WS2812_8_PWM_CHANNEL);
        break;
#endif
    }
}
/**
  * @}
  */



/**
  * @}
  */


#if (WS2812_RGBBUFF==1)
#if WS2812_MODULE_NUM>=1
RGB_Bit WS2812_1_RGBBUFF[WS2812_1_ROWNUM][WS2812_1_COLNUM] = {0};
#endif
#if WS2812_MODULE_NUM>=2
RGB_Bit WS2812_2_RGBBUFF[WS2812_2_ROWNUM][WS2812_2_COLNUM] = {0};
#endif
#if WS2812_MODULE_NUM>=3
RGB_Bit WS2812_3_RGBBUFF[WS2812_3_ROWNUM][WS2812_3_COLNUM] = {0};
#endif
#if WS2812_MODULE_NUM>=4
RGB_Bit WS2812_4_RGBBUFF[WS2812_4_ROWNUM][WS2812_4_COLNUM] = {0};
#endif
#if WS2812_MODULE_NUM>=5
RGB_Bit WS2812_5_RGBBUFF[WS2812_5_ROWNUM][WS2812_5_COLNUM] = {0};
#endif
#if WS2812_MODULE_NUM>=6
RGB_Bit WS2812_6_RGBBUFF[WS2812_6_ROWNUM][WS2812_6_COLNUM] = {0};
#endif
#if WS2812_MODULE_NUM>=7
RGB_Bit WS2812_7_RGBBUFF[WS2812_7_ROWNUM][WS2812_7_COLNUM] = {0};
#endif
#if WS2812_MODULE_NUM>=8
RGB_Bit WS2812_8_RGBBUFF[WS2812_8_ROWNUM][WS2812_8_COLNUM] = {0};
#endif
#endif


uint8_t WS2812_MODULE_SEND = WS2812_MODULE_NULL;





/************************ (C) COPYRIGHT 2020 PHAGE *****END OF FILE**********************/
