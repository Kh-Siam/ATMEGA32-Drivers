#ifndef STD_TYPES_H
#define STD_TYPES_H

typedef unsigned char 			        u8;
typedef unsigned short 	int 	        u16;
typedef unsigned long 	int 	        u32;
typedef unsigned long   long    int     u64;
typedef signed	 		char 	        s8;
typedef signed 	 short 	int 	        s16;
typedef signed   long 	int 	        s32;
typedef 				float 	        f32;
typedef 				double 	        f64;
typedef          long   double          f128;

/* pointer to a function that returns void and takes no arguments */
typedef void (*ptrVoidFunction)(void);

#define NULL    ((void*) 0)

#endif