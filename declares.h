#ifndef DECLARES_H__
#define DECLARES_H__
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <time.h>
#include <math.h>
#include <string>
#include <cstring>
#include <malloc.h>
#include <memory.h>
#include <immintrin.h>
#include <emmintrin.h>
#include <pmmintrin.h>
#include <nmmintrin.h>
#include <wmmintrin.h> 
#include <malloc.h>
#include <ipp.h>
#include <ippcp.h>
#include <map>
#include <unordered_map>
#include <list>
#include <set>
#include <unordered_set>
#include <vector>

#ifdef __GNUC__
#include <sched.h>
#include <sys/resource.h>
#include <x86intrin.h>
#else
#include <intrin.h>
#endif

using namespace std;

typedef unsigned long long u64;
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef long double ld64;

#ifndef nMin
#define nMin (12ULL)
#endif

#ifndef nMax
#define nMax (32ULL)
#endif

#define N (1ULL << n)

#ifndef s
//#define s ((n + 7ULL) / 8ULL)
//#define s ((n + 3ULL) / 4ULL)
//#define s ((n + 3ULL) / 4ULL)
#define s ((n + 7ULL) / 8ULL)
#endif

#define S (1ULL << s)

#ifndef t
//#define t ((n + 2ULL) / 3ULL)
//#define t (2 * (n + 2ULL) / 3ULL)
//#define t ((n + 1ULL) / 2ULL)
#define t (5 * s)
#endif

#define T (1ULL << t)

#define mask ( (N==(1ULL << 32)) ? 0xffffffffUL : ((1ULL << n) - 1ULL))

#define data_t u32

extern u64 n;
extern u64 functioncalls;

extern IppsAESSpec * pCtx1;

extern u8 m[16];

#define initfunc(CIPHER, pCtx)                                                                                                                                        \
{																																									  \
	status = ipps##CIPHER##GetSize(&ctxSize);																														  \
	pCtx = (Ipps##CIPHER##Spec *)malloc(ctxSize);																													  \
	status = ipps##CIPHER##Init(pKey, keylen, pCtx, ctxSize);																										  \
	switch (status)																																					  \
	{																																								  \
	case ippStsNoErr: /*cout << "ippStsNoErr: Indicates no error." << endl;*/ break;																				  \
	case ippStsNullPtrErr: cout << "ippStsNullPtrErr: Indicates an error condition if the pCtx pointer is NULL." << endl; break;									  \
	case ippStsLengthErr: cout << "ippStsLengthErr: Returns an error condition if keyLen is not equal to 16, 24, or 32." << endl; break;							  \
	case ippStsMemAllocErr: cout << "ippStsMemAllocErr: Indicates an error condition if the allocated memory is insufficient for the operation." << endl; break;	  \
	default: break;																																					  \
	}																																								  \
}

#define endfunc(pCtx)            \
{								 \
	if (pCtx != NULL)			 \
	{							 \
		free(pCtx);				 \
	}							 \
}

data_t f(data_t x, u64 fi);

typedef data_t(*func_t)(data_t x, u64 fi);

#endif