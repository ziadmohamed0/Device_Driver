/* 
 * File:   Mcal_Bit_Math.h
 * Author: s
 *
 * Created on 16 ??????, 2024, 02:28 ?
 */

#ifndef MCAL_BIT_MATH_H
#define	MCAL_BIT_MATH_H

/* -------------------- Include Start -------------------- */
/* -------------------- Include End  -------------------- */

/* -------------------- Macro Start -------------------- */
/* -------------------- Macro End  -------------------- */

/* -------------------- Functions Macro Start -------------------- */
#define CLR_BIT(reg,bit)      reg &= ~ (1 << bit)
#define SET_BIT(reg,bit)      reg |=   (1 << bit)
#define TOGGLE_BIT(reg,bit)   reg ^=   (1 << bit)
#define GET_BIT(reg,bit)      ((reg >> bit) & 1 )
/* -------------------- Functions Macro End -------------------- */

/* -------------------- Standard Types Start -------------------- */
/* -------------------- Standard Types End -------------------- */

/* -------------------- API Start -------------------- */
/* -------------------- API End -------------------- */

#endif	/* MCAL_BIT_MATH_H */

