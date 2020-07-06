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
 * @file <stats.h> 
 * @brief <Declare various functions to fine mean, median, maximum and minimum of an Array>
 *
 * @author <Geeta Navalyal>
 * @date <30-05-2020>
 *
 */
#ifndef __STATS_H__
#define __STATS_H__
#include <stdio.h>
#include <math.h>

/* Size of the Data Set */
#define SIZE (40)

    int temp = 0;
/* Given an array of data and a length, sorts the array from largest to smallest. (The zeroth Element should be the largest value, and the last element (n-1) should be the smallest value. )  */
         
	void sort_array(unsigned char* arr)
	{
          for (int i = 0; i < SIZE; i++)
		{
			for (int j = i + 1; j < SIZE; j++)
			{
				if(arr[i] < arr[j])
				{
					temp = arr[i];
					arr[i] = arr[j];
					arr[j] = temp;
				}
			
			}
		}
	} 

/**
 * @brief <Given an array of data and a length, returns the median value>
 *
 * @param <arr> <Pointer to Sorted Array>
 * @param <len> <Length of Array>
 *
 * @return <Median Value>
 */
unsigned char find_median(unsigned char* arr, int len)
{
	
       unsigned char med=0;
	float sum;
	int high = ceil(len/2);

	if(len%2 == 0)
	      {
		sum = (arr[(len/2)-1]+arr[(len/2)]);
                sum = round(sum/2);
	      }
	else
		sum = arr[high];
  	med = sum;
	
	return med;
}

/**
 * @brief <Given an array of data and a length, returns the mean>
 *
 * @param <arr> <Pointer to Sorted Array>
 * @param <len> <Length of Array>
 *
 * @return <Mean Value>
 */
unsigned char find_mean(unsigned char* arr, int len)
{
	unsigned char mean=0;
	float sum = 0;

	for(int i = 0; i<len; i++)
		sum += arr[i];

	sum/= len;
	mean = round(sum);
	return mean;
}

/**
 * @brief <Given an array of data and a length, returns the maximum>
 *
 * @param <arr> <Pointer to Sorted Array>
 * @param <len> <Length of Array>
 *
 * @return <Maximum Value>
 */
unsigned char find_maximum(unsigned char* arr, int len)
{
	unsigned char max=0;
	max = arr[0];
	return max;
}

/**
 * @brief <Given an array of data and a length, returns the minimum>
 *
 * @param <arr> <Pointer to Sorted Array>
 * @param <len> <Length of Array>
 *
 * @return <Minimum Value>
 */
unsigned char find_minimum(unsigned char* arr, int len)
{
	unsigned char min=0;
	min = arr[len-1];
	return min;
}

#endif /* __STATS_H__ */
