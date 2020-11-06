/**
  ******************************************************************************
  * @file          color_table.h
  * @brief         调色板
  *
  *                用于快速查表
  *	@author		   Phage		
  *                Email:2687434412@qq.com
  * @version	   1.0
  * @date		   2020.3
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 Phage.
  * All rights reserved.</center></h2>
  *
  *S
  *	This program is free software: you can redistribute it and/or modify
  *	it under the terms of the GNU General Public License as published by
  *	the Free Software Foundation, either version 3 of the License, or
  *	(at your option) any later version.
  *
  *	This program is distributed in the hope that it will be useful,
  *	but WITHOUT ANY WARRANTY; without even the implied warranty of
  *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  *	GNU General Public License for more details.
  *
  *	You should have received a copy of the GNU General Public License
  *	along with this program.  If not, see <https://www.gnu.org/licenses/>.
  ******************************************************************************
  */


#ifndef __COLOR_TABLE_H__
#define __COLOR_TABLE_H__
/* Includes ------------------------------------------------------------------*/
#include "ws2812.h"
/* Typedef -------------------------------------------------------------------*/

/* Define --------------------------------------------------------------------*/

/* Variables -----------------------------------------------------------------*/
extern RGB_Bit COLOR_TABLE1[360];
extern RGB_Bit COLOR_TABLE2[360];
extern RGB_Bit COLOR_TABLE3[360];
/* Function prototypes -------------------------------------------------------*/

/* Code ----------------------------------------------------------------------*/
RGB_Bit Table1(uint16_t speed,uint16_t span);
RGB_Bit Table2(uint8_t span);
RGB_Bit Table3(void);
RGB_Bit RGB_Copy(RGB_Bit rgb);

#endif

/************************ (C) COPYRIGHT 2020 PHAGE *****END OF FILE*************/
