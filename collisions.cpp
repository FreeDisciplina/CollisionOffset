#include "declares.h"

using namespace std;

#if defined(__GNUC__)
typedef unsigned long mUL64;

inline unsigned long long read_tsc(void)
{
#if defined(__i386__)
	unsigned long long cycles;
	__asm__ volatile (".byte 0x0f, 0x31" : "=A"(cycles));
	return cycles;
#else
#if defined(__x86_64__)
	unsigned int hi, lo;
	__asm__ volatile ("rdtsc" : "a="(lo), "=d"(hi));
	return (((unsigned long long)lo) | ((unsigned long long)(hi) << 32));
#else
#error "Unsupported architecture for counting cycles"
#endif
#endif
}

#else
typedef unsigned long long mUL64;

#pragma intrinsic( __rdtsc )
__inline unsigned long long read_tsc(void)
{
	return __rdtsc();
}
#endif

#define RAND(a,b) (((a = 36969 * (a & 65535) + (a >> 16)) << 16) + \
	(b = 18000 * (b & 65535) + (b >> 16))  )

void block_rndfill(unsigned char *buf, const int len)
{
	static unsigned long a[2], mt = 1, count = 4;
	static unsigned char r[4];
	int                  i;

	if (mt) { mt = 0; *(unsigned long long*)a = read_tsc(); }

	for (i = 0; i < len; ++i)
	{
		if (count == 4)
		{
			*(unsigned long*)r = RAND(a[0], a[1]);
			count = 0;
		}

		buf[i] = r[count++];
	}
}

u64 n;
u64 functioncalls = 0ULL;

IppsAESSpec * pCtx1;

u8 m[16];

void randmblock(u8 mblock[16])
{
	//while (0 == _rdseed64_step((unsigned long long *)&mblock[0])) {}
	//while (0 == _rdseed64_step((unsigned long long *)&mblock[8])) {}
	block_rndfill(mblock, 16);
}

void init_func()
{
	IppStatus status;
	int keylen;
	int ctxSize;
	Ipp8u pKey[16];

	memcpy(pKey, m, sizeof(pKey));
	keylen = 16;
	initfunc(AES, pCtx1);
}

void end_func()
{
	endfunc(pCtx1);
}

void counting()
{
	cout << "Counting number of images/collisions at each offset..." << endl;
	ofstream foutimageN;
	ofstream foutcollisionN;
	string fnimageN;
	string fncollisionN;

	u64 *collisionN;

	for (n = nMin; n <= nMax; n++)
	{
		collisionN = new u64[S + 1];
		fnimageN = "n" + to_string(n) + "_t" + to_string(t) + "_s" + to_string(s) + "_counting_images_record.txt";
		foutimageN.open(fnimageN.c_str(), ios::app);
		foutimageN << "==================================================================" << endl;
		foutimageN << " n = " << n << endl;
		foutimageN << " t = " << t << endl;
		foutimageN << " s = " << s << endl;
		foutimageN << "==================================================================" << endl;

		fncollisionN = "n" + to_string(n) + "_t" + to_string(t) + "_s" + to_string(s) + "_counting_collisions_record.txt";
		foutcollisionN.open(fncollisionN.c_str(), ios::app);
		foutcollisionN << "==================================================================" << endl;
		foutcollisionN << " n = " << n << endl;
		foutcollisionN << " t = " << t << endl;
		foutcollisionN << " s = " << s << endl;
		foutcollisionN << "==================================================================" << endl;

		cout << "==================================================================" << endl;
		cout << " n = " << n << endl;
		cout << " t = " << t << endl;
		cout << " s = " << s << endl;
		cout << "==================================================================" << endl;

		foutimageN.close();
		foutcollisionN.close();

		clock_t t0 = clock();
		randmblock(m);
		init_func();

		u64 fin = 0ULL;
		unordered_set<data_t> Input;
		unordered_set<data_t>::iterator inputIt;
		unordered_set<data_t> Output;
		unordered_set<data_t> * InputPt;
		unordered_set<data_t> * OutputPt;
		unordered_set<data_t> * InOutPt;

		data_t randInput;
		Input.clear();
		if (T != N)
		{
			while (Input.size() < T)
			{
				while (0 == _rdseed32_step(&randInput)) {}
				randInput &= mask;
				Input.insert(randInput);
			}
		}
		else
		{
			for (u64 i = 0ULL; i < N; i++)
			{
				Input.insert(i & mask);
			}
		}

		fin += T;
		collisionN[0] = T;
		InputPt = &Input;
		OutputPt = &Output;

		foutimageN.open(fnimageN.c_str(), ios::app);
		foutcollisionN.open(fncollisionN.c_str(), ios::app);

		foutimageN << setw(6) << "offset" << setw(22) << "#images" << setw(22) << "log2(#images)" << endl;
		foutcollisionN << setw(6) << "offset" << setw(22) << "#collisions" << setw(22) << "log2(#collisions)" << endl;
		foutimageN << std::fixed << std::setprecision(10) << std::setfill(' ');
		foutcollisionN << std::fixed << std::setprecision(10) << std::setfill(' ');
		for (u64 fi = 0; fi < S; fi++)
		{
			for (inputIt = InputPt->begin(); inputIt != InputPt->end(); ++inputIt)
			{
				data_t x = *inputIt;
				data_t y = f(x, fi);
				OutputPt->insert(y);
			}

			u64 sizeofOutput = OutputPt->size();
			collisionN[fi + 1] = sizeofOutput;
			u64 collisionn = collisionN[fi] - collisionN[fi + 1];
			foutimageN << "(" << setw(4) << fi << ", " << setw(20) << sizeofOutput << ", " << setw(20) << logl((ld64)sizeofOutput) / logl(2.0L) << ")" << endl;
			foutcollisionN << "(" << setw(4) << fi << ", " << setw(20) << collisionn << ", " << setw(20) << logl((ld64)collisionn) / logl(2.0L) << ")" << endl;
			fin += sizeofOutput;
			InOutPt = InputPt;
			InputPt = OutputPt;
			OutputPt = InOutPt;
			OutputPt->clear();

		}
		end_func();

		Input.clear();
		Output.clear();

		t0 = clock() - t0;

		cout << "==================================================================" << endl;
		cout << "# Function call (real) = " << fin << endl;
		cout << "# Function call (if without collision) = " << ((S)* T) << endl << endl;
		foutimageN << "==================================================================" << endl;
		foutimageN << "# Function call (real) = " << fin << endl;
		foutimageN << "# Function call (if without collision) = " << ((S)* T) << endl << endl;
		foutcollisionN << "==================================================================" << endl;
		foutcollisionN << "# Function call (real) = " << fin << endl;
		foutcollisionN << "# Function call (if without collision) = " << ((S)* T) << endl << endl;

		cout << "Takes time: " << (double)(t0) / ((double)CLOCKS_PER_SEC * 60.0) << " mins." << endl;
		foutimageN << "Takes time: " << (double)(t0) / ((double)CLOCKS_PER_SEC * 60.0) << " mins." << endl;
		foutcollisionN << "Takes time: " << (double)(t0) / ((double)CLOCKS_PER_SEC * 60.0) << " mins." << endl;
		cout << endl;
		foutimageN << endl;
		foutcollisionN << endl;

		foutimageN.close();
		foutcollisionN.close();

		delete[] collisionN;
	}
}


int main()
{
	/* Init Intel IPP library */
	ippInit();

	counting();

#if defined(_MSC_VER)
	system("Pause");
#endif
	return 0;
}

