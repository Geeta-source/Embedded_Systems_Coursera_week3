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
 * @file <stats.c> 
 * @brief <Call various functions to fine mean, median, maximum and minimum of an Array>
 *
 * <Pass arguments as Array and length of array>
 *
 * @author <Geeta Navalyal>
 * @date <30-05-2020>
 *
 */
#include <stdint.h>
#include "stats.h"
#include "platform.h"
  		
	/* Given an array of data and a length, prints the array to the screen */
	void print_array(unsigned char * arr, unsigned int length){
	#ifdef VERBOSE
	for(int i = 0; i < length/8; i++){
		for(int j = 0; j < length/4; j++){
		       PRINTF("%3d  ", arr[8*i+j]);
		}
		PRINTF("\n");
 	}
	PRINTF("\n");
	#endif
	return;
}

	
