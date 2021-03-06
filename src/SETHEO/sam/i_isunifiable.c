/******************************************************
 *    S E T H E O                                     
 *                                                    
 * FILE: i_isunifiable.c
 * VERSION:
 * DATE:
 * AUTHOR:
 * NAME OF FILE:
 * DESCR:
 * MOD:
 * BUGS:
 ******************************************************/

#include <stdio.h>
#include "constraints.h"
#include "tags.h"
#include "machine.h"
/**/
#include "deref.h"

#define INSTR_LENGTH		2


#define FAIL_U {return failure;}
#ifdef STATISTICS1
#define UNIF_FAIL(x) {unif_fails++;FAIL_U}
#else
#define UNIF_FAIL(x) FAIL_U
#endif


#include "unification.h"

/**************************************************************************
 * code
 **************************************************************************/



/*+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  + i_isunifiable
  + - function for built-in predicate is_unifiable(X, Y)
  +
  + special remarks:
  + - <e.g. called from>
  + - return success when X and Y are unifiable and failure else
  +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++*/

instr_result i_isunifiable()

{ /*=====================================================================*/
  
  register WORD     *farg1, *farg2;
  register s_trail  *ltr;
  WORD              *lhp; 
#ifdef CONSTRAINTS
  WORD              *lc_sp;
#endif
  
  /*-----------------------------------------------------------------------*/
  
  farg1 = deref(ARGPTR(1), bp);
  farg2 = deref(ARGPTR(1)+1, bp);
  ltr = tr;
  lhp = hp;
#ifdef CONSTRAINTS
  lc_sp = c_sp;
#endif
  
  switch(GETTAG(*farg1)) {
  case T_CONST:
    UN_CONST(farg1, bp, farg2, bp)
    break;
  case T_FVAR:
    UN_FVAR(farg1, bp, farg2, bp)
    break;
  case T_CRTERM:
    UN_CRTERM(farg1, bp, farg2, bp)
    break;
  case T_GTERM:
    UN_GTERM(farg1, bp, farg2, bp)
    break;
  case T_NGTERM:
    UN_NGTERM(farg1, bp, farg2, bp)
    break;
  case T_GLOBL:
    UN_GLOBL(farg1, bp, farg2, bp)
    break;
  default:
    FAIL_U;
  }

  untrail(ltr);
  tr = ltr;
  hp = lhp;
#ifdef CONSTRAINTS
  c_sp = lc_sp;
#endif
  
  pc +=INSTR_LENGTH;
  return success;
} /*=====================================================================*/


/*#######################################################################*/
