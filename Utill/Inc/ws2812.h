
#ifndef __WS2812_H__
#define __WS2812_H__

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "tim.h"
#include "dma.h"
#include "ws2812cfg.h"
/* Define --------------------------------------------------------------------*/

extern RCC_ClkInitTypeDef RCC_ClkInitStruct;


#define DMA_MODE 1
#define COMMON_MODE 0

#define WS2812_DMA_M2M_CHANNEL hdma_memtomem_dma1_channel2
#define WS2812_MODULE_NULL 0x0000

#if (WS2812_APB1_FREQ==72)
#define	WS2812_SET 58u				
#define WS2812_RESET 32u
#elif (WS2812_APB1_FREQ==84)
#define	WS2812_SET 61u				
#define WS2812_RESET 28u
#else
 #error
#endif

#if WS2812_MODULE_NUM>=1
	#define WS2812_1_NUM (WS2812_1_ROWNUM*WS2812_1_COLNUM)
	#define WS2812_MODULE_1 0x0001
#endif


#if WS2812_MODULE_NUM>=2
	#define WS2812_2_NUM (WS2812_2_ROWNUM*WS2812_2_COLNUM)
	#define WS2812_MODULE_2 0x0002
#endif

#if WS2812_MODULE_NUM>=3
	#define WS2812_3_NUM (WS2812_3_ROWNUM*WS2812_3_COLNUM)
	#define WS2812_MODULE_3 0x0004
#endif

#if WS2812_MODULE_NUM>=4
	#define WS2812_4_NUM (WS2812_4_ROWNUM*WS2812_4_COLNUM)
	#define WS2812_MODULE_4 0x0008
#endif

#if WS2812_MODULE_NUM>=5
	#define WS2812_5_NUM (WS2812_5_ROWNUM*WS2812_5_COLNUM)
	#define WS2812_MODULE_5 0x0010
#endif

#if WS2812_MODULE_NUM>=6
	#define WS2812_6_NUM (WS2812_6_ROWNUM*WS2812_6_COLNUM)
	#define WS2812_MODULE_6 0x0020
#endif

#if WS2812_MODULE_NUM>=7
	#define WS2812_7_NUM (WS2812_7_ROWNUM*WS2812_7_COLNUM)
	#define WS2812_MODULE_7 0x0040
#endif

#if WS2812_MODULE_NUM>=8
	#define WS2812_8_NUM (WS2812_8_ROWNUM*WS2812_8_COLNUM)
	#define WS2812_MODULE_8 0x0080
#endif



#if ((WS2812_MODULE_NUM>=9)||(WS2812_MODULE_NUM<=0))
	#error
	#line
#endif


#if WS2812_MODULE_NUM==1
	#define WS2812_MODULE_ALL 0x0001
#elif WS2812_MODULE_NUM==2
	#define WS2812_MODULE_ALL 0x0003
#elif WS2812_MODULE_NUM==3
	#define WS2812_MODULE_ALL 0x0007
#elif WS2812_MODULE_NUM==4
	#define WS2812_MODULE_ALL 0x000F
#elif WS2812_MODULE_NUM==5
	#define WS2812_MODULE_ALL 0x001F
#elif WS2812_MODULE_NUM==6
	#define WS2812_MODULE_ALL 0x003F
#elif WS2812_MODULE_NUM==7
	#define WS2812_MODULE_ALL 0x007F
#elif WS2812_MODULE_NUM==8
	#define WS2812_MODULE_ALL 0x00FF
#else
	#error
	#line
#endif


typedef struct {
	uint8_t R;
	uint8_t G;
	uint8_t B;
}RGB_Bit;  

#ifdef WS2812_MODULE_1
extern RGB_Bit WS2812_1_RGBBUFF[WS2812_1_ROWNUM][WS2812_1_COLNUM];
#endif

#ifdef WS2812_MODULE_2
extern RGB_Bit WS2812_2_RGBBUFF[WS2812_2_ROWNUM][WS2812_2_COLNUM];
#endif

#ifdef WS2812_MODULE_3
extern RGB_Bit WS2812_3_RGBBUFF[WS2812_3_ROWNUM][WS2812_3_COLNUM];
#endif

#ifdef WS2812_MODULE_4
extern RGB_Bit WS2812_4_RGBBUFF[WS2812_4_ROWNUM][WS2812_4_COLNUM];
#endif

#ifdef WS2812_MODULE_5
extern RGB_Bit WS2812_5_RGBBUFF[WS2812_5_ROWNUM][WS2812_5_COLNUM];
#endif

#ifdef WS2812_MODULE_6
extern RGB_Bit WS2812_6_RGBBUFF[WS2812_6_ROWNUM][WS2812_6_COLNUM];
#endif

#ifdef WS2812_MODULE_7
extern RGB_Bit WS2812_7_RGBBUFF[WS2812_7_ROWNUM][WS2812_7_COLNUM];
#endif

#ifdef WS2812_MODULE_8
extern RGB_Bit WS2812_8_RGBBUFF[WS2812_8_ROWNUM][WS2812_8_COLNUM];
#endif


/* Function prototypes -------------------------------------------------------*/
void WS2812_Init(void);
void WS2812_Clean(uint16_t WS2812_moudle);
void WS2812_Clean_Buff(uint16_t WS2812_MODULE);
void WS2812_Clean_RGBBuff(uint16_t WS2812_MODULE);
void WS2812_Send(uint16_t WS2812_MODULE);
#if WS2812_WRITE_MODE==COMMON_MODE
void WS2812_Write(uint32_t *RGB_BUFFADDR,uint16_t WS2812_MODULE);
void WS2812_Write_Mirror(uint32_t *RGB_BUFFADDR, uint16_t WS2812_MODULE);
#elif WS2812_WRITE_MODE==DMA_MODE
	#error
#else
	#error
#endif


#endif

/************************ (C) COPYRIGHT 2020 PHAGE *****END OF FILE**********************/
