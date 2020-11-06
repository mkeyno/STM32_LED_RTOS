#ifndef __DEFINE_H
#define __DEFINE_H

#define MYWWWPORT 80

#define BUFFER_SIZE 1500

typedef struct {
	uint8_t R;
	uint8_t G;
	uint8_t B;
}RGB_Bit;  
 RGB_Bit RGB[16];

typedef struct ProjectData {
 uint8_t mymac[6];
 uint8_t buf[BUFFER_SIZE + 1];
uint16_t plen, dat_p;
 uint8_t myip[4] ;
 uint8_t mynetmask[4];
 uint8_t websrvip[4];
 uint8_t gwip[4];
 uint8_t dnsip[4];
 uint8_t dhcpsvrip[4];
 uint8_t RFcommand[4];
 uint16_t LightSensor;
} ;
static ProjectData DATA;

void initiliaze_project(void) {

	DATA = (ProjectData) {
					 .mymac[] = { 0x54, 0x55, 0x58, 0x10, 0x00, 0x25 },
					 .myip[] = { 0, 0, 0, 0 },
					  .mynetmask[] = { 255, 255, 255, 0} ,
					 .websrvip[] = { 0, 0, 0, 0 },
					 .gwip[] = { 192, 168, 0, 1 },
					 .dnsip[] = { 0, 0, 0, 0 },
					 .dhcpsvrip[] = { 0, 0, 0, 0 }
					 };
}
#endif
