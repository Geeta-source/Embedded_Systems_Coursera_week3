/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file memory.c
 * @brief Abstraction of memory read and write operations
 *
 * This implementation file provides an abstraction of reading and
 * writing to memory via function calls. There is also a globally
 * allocated buffer array used for manipulation.
 *
 * @author Alex Fosdick
 * @date April 1 2017
 *
 */
#include <stdint.h>
#include <stdlib.h>
#include "memory.h"

/***********************************************************
 Function Definitions
***********************************************************/

int32_t * reserve_words(size_t length){
	int32_t *src = (int32_t*)malloc(length * sizeof(int32_t));
	return src;
}

void free_words(uint32_t * src){
	free(src);
}

uint8_t * my_memmove(uint8_t *src, uint8_t *dst, size_t length){
	uint8_t *tmp = (uint8_t*)malloc(length * sizeof(uint8_t));	
	int i;

	for(i = 0; i < length; i++){
		*(tmp + i) = *(src + i);
	}

	for(i = 0; i < length; i++){
		*(dst + i) = *(tmp + i);
	}

	free(tmp);
	return dst;
}
uint8_t * my_memcopy(uint8_t * src, uint8_t * dst, size_t length){
	int i;
	for(i = 0; i < length; i++){
		*(dst + i) = *(src + i);
	}

	return dst;
}
uint8_t * my_memset(uint8_t * src, size_t length, uint8_t value){
	int i;

	for(i = 0; i < length; i++){
		*(src + i) = value;
	}
     return src;
}
uint8_t * my_memzero(uint8_t * src, size_t length){
	int i;

	for(i = 0; i < length; i++){
		*(src + i) = 0;
	}

	return src;
}
uint8_t * my_reverse(uint8_t * src, size_t length){
	int i;
	uint8_t tmp;
        uint8_t tmp1 = length-1;
	for(i = 0; i < length/2 ; i++){
                tmp = *(src + i);
               	*(src + i) = *(src + tmp1);
               	*(src + tmp1) = tmp;
                 tmp1 = tmp1-1;
	}
	return src;
}


