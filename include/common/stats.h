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

/* Given an array of data and a length, prints the array to the screen
 *
 * @param array A pointer to an array of unsigned chars
 * @param length The length of the array
 *
 * @return NULL
 */
void print_array(unsigned char * arr, unsigned int length);

#endif /* __STATS_H__ */
