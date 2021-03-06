/******************************************************
 *    S E T H E O                                     
 *                                                    
 * FILE: i_set_maxtc.c
 * VERSION:
 * DATE:
 * AUTHOR:
 * NAME OF FILE:
 * DESCR:
 * MOD:
 * BUGS:
 ******************************************************/

#include <stdio.h>
#include "tags.h"
#include "machine.h"
/**/
#include "deref.h"
#include "errors.h"

#define INSTR_LENGTH		2


instr_result i_set_maxtc()
{
    WORD           *ga;

    ga = deref(ARGPTR(1),bp);

    if (ISNUMBER(*ga)) {
        trail_int(&maxtc);
	maxtc = GETNUMBER(*ga);
        tc_bound = TRUE;
        pc +=INSTR_LENGTH;
        return success;
    }
    sam_error ("set_maxtc: must be a number", ga, 1);
    return failure;
}
