/**
 * @file data.c
 * @brief Performs simple data manipulation
 *
 * @author Geeta Navalyal
 * @date July 1, 2020
 */
#include <stdint.h>
#include "data.h"
#include <stdio.h>

uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base)
{
	int length = 0;
	int digit;
	int i,temp,len,offset;
	int is_neg = 0;

	if(data == 0)
	{
		*ptr = 48;
		return length;
	}
	else if(data < 0)
	{
		is_neg = 1;
		data *= -1;
	}
       
        if(is_neg)
	{
		*ptr = '-';
                length = 1;
                offset = 1;
	}
         else
        {
          	length = 0;
          	offset = 0;
        }

	while(data != 0)
	{
		digit = data % base;
		data /= base;
		
		if(digit > 9)
			*(ptr + length) = 55 + digit;
		else
			*(ptr + length) = 48 + digit;

		length++;
	}
       
	/* Add Null terminator*/ 
	*(ptr + length) = '\0'; 
        len=length;
	length++;
        

	for (i=offset;i<length/2;i++)
	{
            	temp = *(ptr+i);
            	*(ptr+i) = *(ptr+len-1);
            	*(ptr+len-1)=temp;
            	len=len-1;
   	}
        
	return length;
}

uint32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base)
{
	uint32_t c,offset,n = 0;
	int sign;
	
	if(*ptr=='-')
		sign = -1;
 
	if(sign==-1)
		offset=1;

	else
		offset=0;
       	
	for(c=offset; c < digits-1 ;c++)
	{
        	if(*(ptr+c) <= 57)
        		n = (n*base) + (*(ptr+c) - '0');
		
		else
			n = n*base + (*(ptr+c) - '7');
       	}

	if(sign==-1)
		n *= -1;

	return(n);
}
