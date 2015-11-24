/* -----------------------------------------------------------------------------------------------------
[FILE NAME]: 	< macros.h >
[AUTHOR]: 		< Hossam Sayed Dessouky >
[DATE CREATED]: < 11/1/2015 >
[DESCRIPTION]: 	< This file contains the macros that the program will use to set a bit direction or
				  output, and check for its value >
----------------------------------------------------------------------------------------------------- */


#ifndef MACROS_H_
#define MACROS_H_

/*---------------------------------- Definitions and configurations ----------------------------------*/

/* -----------------------------------------------------------------------------------------------------
[Macro Name] : 	SET_BIT
[Description] : This macro is responsible for setting a bin direction as output , or setting a bits value as logic high.
[Args] :
[in] 			REG 	: The register that contains the bin.
				BITNUM	: The number of the bin that is needed to be set.
----------------------------------------------------------------------------------------------------- */
#define SET_BIT( REG , BIT_NUM ) ( REG = REG | (1<<BIT_NUM) )

/* -----------------------------------------------------------------------------------------------------
[Macro Name] : 	CLEAR_BIT
[Description] : This macro is responsible for setting a bin direction as input, or setting a bits value as logic low.
[Args] :
[in] 			REG 	: The register that contains the bin.
				BITNUM	: The number of the bin that is needed to be cleared.
----------------------------------------------------------------------------------------------------- */
#define CLEAR_BIT( REG , BIT_NUM ) ( REG = REG & (~(1<<BIT_NUM)) )

/* -----------------------------------------------------------------------------------------------------
[Macro Name] : 	BIT_IS_SET
[Description] : This macro is responsible for checking if a bit is set in any register and return true if yes.
[Args] :
[in] 			REG 	: The register that contains the bin.
				BITNUM	: The number of the bin that is needed to be checked.
[Returns] :		This shall return true if the bit in the register is set and false if the bit is clear.
----------------------------------------------------------------------------------------------------- */
#define BIT_IS_SET( REG , BIT_NUM ) ( REG & (1<<BIT_NUM) )

/* -----------------------------------------------------------------------------------------------------
[Macro Name] : 	BIT_IS_CLEAR
[Description] : This macro is responsible for checking if a bit is clear in any register and return true if yes.
[Args] :
[in] 			REG 	: The register that contains the bin.
				BITNUM	: The number of the bin that is needed to be checked.
[Returns] :		This shall return true if the bit in the register is clear and false if the bit is set.
----------------------------------------------------------------------------------------------------- */
#define BIT_IS_CLEAR( REG , BIT_NUM ) ( !(REG & (1<<BIT_NUM)) )

#endif /* MACROS_H_ */

/*----------------------------------------------------------------------------------------------------*/