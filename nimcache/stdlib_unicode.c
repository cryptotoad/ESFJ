/* Generated by Nim Compiler v0.11.2 */
/*   (c) 2015 Andreas Rumpf */
/* The generated code is subject to the original license. */
/* Compiled for: Windows, amd64, gcc */
/* Command for C compiler:
   C:\Nim\dist\mingw\bin\gcc.exe -c  -w  -IC:\Nim\lib -o c:\users\owner\documents\nim\esfj\nimcache\stdlib_unicode.o c:\users\owner\documents\nim\esfj\nimcache\stdlib_unicode.c */
#define NIM_INTBITS 64
#include "nimbase.h"
typedef struct NimStringDesc NimStringDesc;
typedef struct TGenericSeq TGenericSeq;
struct  TGenericSeq  {
NI len;
NI reserved;
};
struct  NimStringDesc  {
  TGenericSeq Sup;
NIM_CHAR data[SEQ_DECL_SIZE];
};
N_NIMCALL(NimStringDesc*, mnewString)(NI len);
N_NIMCALL(NimStringDesc*, mnewString)(NI len);
N_NOINLINE(void, raiseIndexError)(void);
static N_INLINE(NI, chckRange)(NI i, NI a, NI b);
N_NOINLINE(void, raiseRangeError)(NI64 val);
static N_INLINE(void, nimFrame)(TFrame* s);
N_NOINLINE(void, stackoverflow_20001)(void);
static N_INLINE(void, popFrame)(void);
extern TFrame* frameptr_17042;

static N_INLINE(NI, chckRange)(NI i, NI a, NI b) {
	NI result;
{	result = 0;
	{
		NIM_BOOL LOC3;
		LOC3 = 0;
		LOC3 = (a <= i);
		if (!(LOC3)) goto LA4;
		LOC3 = (i <= b);
		LA4: ;
		if (!LOC3) goto LA5;
		result = i;
		goto BeforeRet;
	}
	goto LA1;
	LA5: ;
	{
		raiseRangeError(((NI64) (i)));
	}
	LA1: ;
	}BeforeRet: ;
	return result;
}

static N_INLINE(void, nimFrame)(TFrame* s) {
	NI LOC1;
	LOC1 = 0;
	{
		if (!(frameptr_17042 == NIM_NIL)) goto LA4;
		LOC1 = ((NI) 0);
	}
	goto LA2;
	LA4: ;
	{
		LOC1 = ((NI) ((NI16)((*frameptr_17042).calldepth + ((NI16) 1))));
	}
	LA2: ;
	(*s).calldepth = ((NI16) (LOC1));
	(*s).prev = frameptr_17042;
	frameptr_17042 = s;
	{
		if (!((*s).calldepth == ((NI16) 2000))) goto LA9;
		stackoverflow_20001();
	}
	LA9: ;
}

static N_INLINE(void, popFrame)(void) {
	frameptr_17042 = (*frameptr_17042).prev;
}

N_NIMCALL(NimStringDesc*, nuctoUTF8)(NI c) {
	NimStringDesc* result;
	NI i;
	nimfr("toUTF8", "unicode.nim")
	result = 0;
	nimln(139, "unicode.nim");
	i = c;
	nimln(140, "unicode.nim");
	{
		if (!((NU64)(i) <= (NU64)(((NI) 127)))) goto LA3;
		nimln(141, "unicode.nim");
		result = mnewString(((NI) 1));
		nimln(142, "unicode.nim");
		if ((NU)(((NI) 0)) > (NU)(result->Sup.len)) raiseIndexError();
		result->data[((NI) 0)] = ((NIM_CHAR) (((NI)chckRange(i, ((NI) 0), ((NI) 255)))));
	}
	goto LA1;
	LA3: ;
	{
		nimln(143, "unicode.nim");
		if (!((NU64)(i) <= (NU64)(((NI) 2047)))) goto LA6;
		nimln(144, "unicode.nim");
		result = mnewString(((NI) 2));
		nimln(145, "unicode.nim");
		if ((NU)(((NI) 0)) > (NU)(result->Sup.len)) raiseIndexError();
		result->data[((NI) 0)] = ((NIM_CHAR) (((NI)chckRange((NI)((NI)((NU64)(i) >> (NU64)(((NI) 6))) | ((NI) 192)), ((NI) 0), ((NI) 255)))));
		nimln(146, "unicode.nim");
		if ((NU)(((NI) 1)) > (NU)(result->Sup.len)) raiseIndexError();
		result->data[((NI) 1)] = ((NIM_CHAR) (((NI)chckRange((NI)(((NI) ((NI)(i & ((NI) 63)))) | ((NI) 128)), ((NI) 0), ((NI) 255)))));
	}
	goto LA1;
	LA6: ;
	{
		nimln(147, "unicode.nim");
		if (!((NU64)(i) <= (NU64)(((NI) 65535)))) goto LA9;
		nimln(148, "unicode.nim");
		result = mnewString(((NI) 3));
		nimln(149, "unicode.nim");
		if ((NU)(((NI) 0)) > (NU)(result->Sup.len)) raiseIndexError();
		result->data[((NI) 0)] = ((NIM_CHAR) (((NI)chckRange((NI)((NI)((NU64)(i) >> (NU64)(((NI) 12))) | ((NI) 224)), ((NI) 0), ((NI) 255)))));
		nimln(150, "unicode.nim");
		if ((NU)(((NI) 1)) > (NU)(result->Sup.len)) raiseIndexError();
		result->data[((NI) 1)] = ((NIM_CHAR) (((NI)chckRange((NI)(((NI) ((NI)((NI)((NU64)(i) >> (NU64)(((NI) 6))) & ((NI) 63)))) | ((NI) 128)), ((NI) 0), ((NI) 255)))));
		nimln(151, "unicode.nim");
		if ((NU)(((NI) 2)) > (NU)(result->Sup.len)) raiseIndexError();
		result->data[((NI) 2)] = ((NIM_CHAR) (((NI)chckRange((NI)(((NI) ((NI)(i & ((NI) 63)))) | ((NI) 128)), ((NI) 0), ((NI) 255)))));
	}
	goto LA1;
	LA9: ;
	{
		nimln(152, "unicode.nim");
		if (!((NU64)(i) <= (NU64)(((NI) 2097151)))) goto LA12;
		nimln(153, "unicode.nim");
		result = mnewString(((NI) 4));
		nimln(154, "unicode.nim");
		if ((NU)(((NI) 0)) > (NU)(result->Sup.len)) raiseIndexError();
		result->data[((NI) 0)] = ((NIM_CHAR) (((NI)chckRange((NI)((NI)((NU64)(i) >> (NU64)(((NI) 18))) | ((NI) 240)), ((NI) 0), ((NI) 255)))));
		nimln(155, "unicode.nim");
		if ((NU)(((NI) 1)) > (NU)(result->Sup.len)) raiseIndexError();
		result->data[((NI) 1)] = ((NIM_CHAR) (((NI)chckRange((NI)(((NI) ((NI)((NI)((NU64)(i) >> (NU64)(((NI) 12))) & ((NI) 63)))) | ((NI) 128)), ((NI) 0), ((NI) 255)))));
		nimln(156, "unicode.nim");
		if ((NU)(((NI) 2)) > (NU)(result->Sup.len)) raiseIndexError();
		result->data[((NI) 2)] = ((NIM_CHAR) (((NI)chckRange((NI)(((NI) ((NI)((NI)((NU64)(i) >> (NU64)(((NI) 6))) & ((NI) 63)))) | ((NI) 128)), ((NI) 0), ((NI) 255)))));
		nimln(157, "unicode.nim");
		if ((NU)(((NI) 3)) > (NU)(result->Sup.len)) raiseIndexError();
		result->data[((NI) 3)] = ((NIM_CHAR) (((NI)chckRange((NI)(((NI) ((NI)(i & ((NI) 63)))) | ((NI) 128)), ((NI) 0), ((NI) 255)))));
	}
	goto LA1;
	LA12: ;
	{
		nimln(158, "unicode.nim");
		if (!((NU64)(i) <= (NU64)(((NI) 67108863)))) goto LA15;
		nimln(159, "unicode.nim");
		result = mnewString(((NI) 5));
		nimln(160, "unicode.nim");
		if ((NU)(((NI) 0)) > (NU)(result->Sup.len)) raiseIndexError();
		result->data[((NI) 0)] = ((NIM_CHAR) (((NI)chckRange((NI)((NI)((NU64)(i) >> (NU64)(((NI) 24))) | ((NI) 248)), ((NI) 0), ((NI) 255)))));
		nimln(161, "unicode.nim");
		if ((NU)(((NI) 1)) > (NU)(result->Sup.len)) raiseIndexError();
		result->data[((NI) 1)] = ((NIM_CHAR) (((NI)chckRange((NI)(((NI) ((NI)((NI)((NU64)(i) >> (NU64)(((NI) 18))) & ((NI) 63)))) | ((NI) 128)), ((NI) 0), ((NI) 255)))));
		nimln(162, "unicode.nim");
		if ((NU)(((NI) 2)) > (NU)(result->Sup.len)) raiseIndexError();
		result->data[((NI) 2)] = ((NIM_CHAR) (((NI)chckRange((NI)(((NI) ((NI)((NI)((NU64)(i) >> (NU64)(((NI) 12))) & ((NI) 63)))) | ((NI) 128)), ((NI) 0), ((NI) 255)))));
		nimln(163, "unicode.nim");
		if ((NU)(((NI) 3)) > (NU)(result->Sup.len)) raiseIndexError();
		result->data[((NI) 3)] = ((NIM_CHAR) (((NI)chckRange((NI)(((NI) ((NI)((NI)((NU64)(i) >> (NU64)(((NI) 6))) & ((NI) 63)))) | ((NI) 128)), ((NI) 0), ((NI) 255)))));
		nimln(164, "unicode.nim");
		if ((NU)(((NI) 4)) > (NU)(result->Sup.len)) raiseIndexError();
		result->data[((NI) 4)] = ((NIM_CHAR) (((NI)chckRange((NI)(((NI) ((NI)(i & ((NI) 63)))) | ((NI) 128)), ((NI) 0), ((NI) 255)))));
	}
	goto LA1;
	LA15: ;
	{
		nimln(165, "unicode.nim");
		if (!((NU64)(i) <= (NU64)(((NI) 2147483647)))) goto LA18;
		nimln(166, "unicode.nim");
		result = mnewString(((NI) 6));
		nimln(167, "unicode.nim");
		if ((NU)(((NI) 0)) > (NU)(result->Sup.len)) raiseIndexError();
		result->data[((NI) 0)] = ((NIM_CHAR) (((NI)chckRange((NI)((NI)((NU64)(i) >> (NU64)(((NI) 30))) | ((NI) 252)), ((NI) 0), ((NI) 255)))));
		nimln(168, "unicode.nim");
		if ((NU)(((NI) 1)) > (NU)(result->Sup.len)) raiseIndexError();
		result->data[((NI) 1)] = ((NIM_CHAR) (((NI)chckRange((NI)(((NI) ((NI)((NI)((NU64)(i) >> (NU64)(((NI) 24))) & ((NI) 63)))) | ((NI) 128)), ((NI) 0), ((NI) 255)))));
		nimln(169, "unicode.nim");
		if ((NU)(((NI) 2)) > (NU)(result->Sup.len)) raiseIndexError();
		result->data[((NI) 2)] = ((NIM_CHAR) (((NI)chckRange((NI)(((NI) ((NI)((NI)((NU64)(i) >> (NU64)(((NI) 18))) & ((NI) 63)))) | ((NI) 128)), ((NI) 0), ((NI) 255)))));
		nimln(170, "unicode.nim");
		if ((NU)(((NI) 3)) > (NU)(result->Sup.len)) raiseIndexError();
		result->data[((NI) 3)] = ((NIM_CHAR) (((NI)chckRange((NI)(((NI) ((NI)((NI)((NU64)(i) >> (NU64)(((NI) 12))) & ((NI) 63)))) | ((NI) 128)), ((NI) 0), ((NI) 255)))));
		nimln(171, "unicode.nim");
		if ((NU)(((NI) 4)) > (NU)(result->Sup.len)) raiseIndexError();
		result->data[((NI) 4)] = ((NIM_CHAR) (((NI)chckRange((NI)(((NI) ((NI)((NI)((NU64)(i) >> (NU64)(((NI) 6))) & ((NI) 63)))) | ((NI) 128)), ((NI) 0), ((NI) 255)))));
		nimln(172, "unicode.nim");
		if ((NU)(((NI) 5)) > (NU)(result->Sup.len)) raiseIndexError();
		result->data[((NI) 5)] = ((NIM_CHAR) (((NI)chckRange((NI)(((NI) ((NI)(i & ((NI) 63)))) | ((NI) 128)), ((NI) 0), ((NI) 255)))));
	}
	goto LA1;
	LA18: ;
	{
	}
	LA1: ;
	popFrame();
	return result;
}
NIM_EXTERNC N_NOINLINE(void, stdlib_unicodeInit)(void) {
	nimfr("unicode", "unicode.nim")
	popFrame();
}

NIM_EXTERNC N_NOINLINE(void, stdlib_unicodeDatInit)(void) {
}

