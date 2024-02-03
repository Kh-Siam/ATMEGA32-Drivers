#ifndef BIT_MATH_H
#define BIT_MATH_H

#define SET_BIT(PORT, BIT)    PORT |=  (1 << BIT)
#define CLR_BIT(PORT, BIT)    PORT &= ~(1 << BIT)
#define TGL_BIT(PORT, BIT)    PORT ^=  (1 << BIT)
#define GET_BIT(PORT, BIT)    (PORT >> BIT) & 0x01

#endif