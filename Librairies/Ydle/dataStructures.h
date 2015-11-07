#ifndef dataStructures_H_
#define dataStructures_H_

#include  "Float.h"

/*typedef struct {
	uint8_t cmd;
	uint8_t nid;
} sReceivedCommand;
 */ 


typedef struct {
	uint16_t temperature;
	int16_t humidity;
} sDht11Data;

typedef struct {
	unsigned long index_base;
	uint16_t iinst;
	int papp;
} sTeleInfoData;

#endif
