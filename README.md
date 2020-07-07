/* Add Author and Project Details here */
 Name : Geeta Navalyal

 Project Details: This project uses Make and GCC build system for a C-application to manipulate memory using operations such as copying from source to destination with and without overlap, reversing contents of memory, setting and resetting memory contents and so on..

NOTE : The definition of VERBOSE isn't taking effect the first time. In that case please copy the below lines to main.c in order to verify its effect and help the execution.

  PRINTF("VERBOSE:%d\n",VERBOSE);


1. Command to run Makefile: (For HOST Platform)
       ~$cd course1

~course1$make build COURSE=COURSE1 PLATFORM=HOST VERBOSE=VERBOSE

~course1$./c1m3.out


3. Command to run Makefile: (For MSP432 Platform)
~       $cd course1

~course1$make clean
 
~course1$make build COURSE=COURSE1 PLATFORM=MSP432 VERBOSE=VERBOSE


