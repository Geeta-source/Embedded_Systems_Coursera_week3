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

#include "stats.h"

void main() 
{
  	unsigned char test[SIZE] = {34,201,190,154,8,194,2,6,114,88,45,76,123,87,25,23,200,122,150,90,92,87,177,244,201,6,12,60,8,2,5,67,7,87,250,230,99,3,100,90};

  		
	/* Given an array of data and a length, prints the array to the screen */
	void print_array(unsigned char* arr)
	{
		for(int i=0; i<SIZE; i++)
			printf("%d=%u\n",i, arr[i]);
		printf("*********************\n");
	}


	/* A function that prints the statistics of an array including minimum, maximum, mean, and median. */
	void print_statistics()
	{
		printf("Minimum= %u\n", find_minimum(test, SIZE));
		printf("Maximum= %u\n", find_maximum(test, SIZE));
		printf("Mean= %u\n", find_mean(test, SIZE));
		printf("Median= %u\n", find_median(test, SIZE));

	}
	
	sort_array(test);
	print_array(test);
	print_statistics();

}




