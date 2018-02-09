#include "declares.h"

data_t f(data_t x, u64 fi)
{
	functioncalls++;
	IppStatus status;
	int srclen;
	srclen = 16;
	Ipp8u pSrc[16];
	Ipp8u pDst[16];

	x &= mask;
	data_t y;
	for (size_t i = 0; i < 16; i++)
	{
		pSrc[i] = 0;
		pDst[i] = 0;
	}
	memcpy(pSrc, &x, sizeof(data_t));
	memcpy(&pSrc[8], &fi, sizeof(fi));
	status = ippsAESEncryptECB(pSrc, pDst, srclen, pCtx1);
	switch (status)
	{
	case ippStsNoErr: /*cout << "ippStsNoErr: Indicates no error." << endl;*/ break;
	case ippStsNullPtrErr: cout << "ippStsNullPtrErr: Indicates an error condition if the specified  pointer is NULL." << endl; break;
	case ippStsLengthErr: cout << "ippStsLengthErr: Indicates an error condition if the input data stream length is less than or equal to zero." << endl; break;
	case ippStsUnderRunErr: cout << "ippStsUnderRunErr: Indicates an error condition if srclen is not divisible by cipher block size." << endl; break;
	case ippStsContextMatchErr: cout << "ippStsContextMatchErr: Indicates an error condition if the context parameter does not match the operation." << endl; break;
	default: break;
	}
	memcpy(&y, pDst, sizeof(data_t));
	return ((y & mask) ^ x);
}