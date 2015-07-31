/* Generated by Nim Compiler v0.11.2 */
/*   (c) 2015 Andreas Rumpf */
/* The generated code is subject to the original license. */
/* Compiled for: Windows, amd64, gcc */
/* Command for C compiler:
   C:\Nim\dist\mingw\bin\gcc.exe -c  -w  -IC:\Nim\lib -o c:\users\owner\documents\nim\esfj\nimcache\stdlib_parseutils.o c:\users\owner\documents\nim\esfj\nimcache\stdlib_parseutils.c */
#define NIM_INTBITS 64
#include "nimbase.h"
typedef struct NimStringDesc NimStringDesc;
typedef struct TGenericSeq TGenericSeq;
typedef struct Overflowerror3443 Overflowerror3443;
typedef struct Arithmeticerror3439 Arithmeticerror3439;
typedef struct Exception Exception;
typedef struct TNimObject TNimObject;
typedef struct TNimType TNimType;
typedef struct TNimNode TNimNode;
typedef struct Tcell46746 Tcell46746;
typedef struct Tcellseq46762 Tcellseq46762;
typedef struct Tgcheap48616 Tgcheap48616;
typedef struct Tcellset46758 Tcellset46758;
typedef struct Tpagedesc46754 Tpagedesc46754;
typedef struct Tmemregion28610 Tmemregion28610;
typedef struct Tsmallchunk27840 Tsmallchunk27840;
typedef struct Tllchunk28604 Tllchunk28604;
typedef struct Tbigchunk27842 Tbigchunk27842;
typedef struct Tintset27817 Tintset27817;
typedef struct Ttrunk27813 Ttrunk27813;
typedef struct Tavlnode28608 Tavlnode28608;
typedef struct Tgcstat48614 Tgcstat48614;
typedef struct Tbasechunk27838 Tbasechunk27838;
typedef struct Tfreecell27830 Tfreecell27830;
struct  TGenericSeq  {
NI len;
NI reserved;
};
struct  NimStringDesc  {
  TGenericSeq Sup;
NIM_CHAR data[SEQ_DECL_SIZE];
};
typedef N_NIMCALL_PTR(void, TY3289) (void* p, NI op);
typedef N_NIMCALL_PTR(void*, TY3294) (void* p);
struct  TNimType  {
NI size;
NU8 kind;
NU8 flags;
TNimType* base;
TNimNode* node;
void* finalizer;
TY3289 marker;
TY3294 deepcopy;
};
struct  TNimObject  {
TNimType* m_type;
};
struct  Exception  {
  TNimObject Sup;
Exception* parent;
NCSTRING name;
NimStringDesc* message;
NimStringDesc* trace;
};
struct  Arithmeticerror3439  {
  Exception Sup;
};
struct  Overflowerror3443  {
  Arithmeticerror3439 Sup;
};
struct  TNimNode  {
NU8 kind;
NI offset;
TNimType* typ;
NCSTRING name;
NI len;
TNimNode** sons;
};
struct  Tcell46746  {
NI refcount;
TNimType* typ;
};
struct  Tcellseq46762  {
NI len;
NI cap;
Tcell46746** d;
};
struct  Tcellset46758  {
NI counter;
NI max;
Tpagedesc46754* head;
Tpagedesc46754** data;
};
typedef Tsmallchunk27840* TY28622[512];
typedef Ttrunk27813* Ttrunkbuckets27815[256];
struct  Tintset27817  {
Ttrunkbuckets27815 data;
};
struct  Tmemregion28610  {
NI minlargeobj;
NI maxlargeobj;
TY28622 freesmallchunks;
Tllchunk28604* llmem;
NI currmem;
NI maxmem;
NI freemem;
NI lastsize;
Tbigchunk27842* freechunkslist;
Tintset27817 chunkstarts;
Tavlnode28608* root;
Tavlnode28608* deleted;
Tavlnode28608* last;
Tavlnode28608* freeavlnodes;
};
struct  Tgcstat48614  {
NI stackscans;
NI cyclecollections;
NI maxthreshold;
NI maxstacksize;
NI maxstackcells;
NI cycletablesize;
NI64 maxpause;
};
struct  Tgcheap48616  {
void* stackbottom;
NI cyclethreshold;
Tcellseq46762 zct;
Tcellseq46762 decstack;
Tcellset46758 cycleroots;
Tcellseq46762 tempstack;
NI recgclock;
Tmemregion28610 region;
Tgcstat48614 stat;
};
typedef NI TY27820[8];
struct  Tpagedesc46754  {
Tpagedesc46754* next;
NI key;
TY27820 bits;
};
struct  Tbasechunk27838  {
NI prevsize;
NI size;
NIM_BOOL used;
};
struct  Tsmallchunk27840  {
  Tbasechunk27838 Sup;
Tsmallchunk27840* next;
Tsmallchunk27840* prev;
Tfreecell27830* freelist;
NI free;
NI acc;
NF data;
};
struct  Tllchunk28604  {
NI size;
NI acc;
Tllchunk28604* next;
};
struct  Tbigchunk27842  {
  Tbasechunk27838 Sup;
Tbigchunk27842* next;
Tbigchunk27842* prev;
NI align;
NF data;
};
struct  Ttrunk27813  {
Ttrunk27813* next;
NI key;
TY27820 bits;
};
typedef Tavlnode28608* TY28614[2];
struct  Tavlnode28608  {
TY28614 link;
NI key;
NI upperbound;
NI level;
};
struct  Tfreecell27830  {
Tfreecell27830* next;
NI zerofield;
};
N_NIMCALL(NI, npuParseBiggestInt)(NimStringDesc* s, NI64* number, NI start);
N_NIMCALL(NI, rawparseint_93714)(NimStringDesc* s, NI64* b, NI start);
N_NOINLINE(void, raiseIndexError)(void);
static N_INLINE(NI, addInt)(NI a, NI b);
N_NOINLINE(void, raiseOverflow)(void);
N_NIMCALL(NI64, mulInt64)(NI64 a, NI64 b);
static N_INLINE(NI, subInt)(NI a, NI b);
static N_INLINE(NI64, subInt64)(NI64 a, NI64 b);
static N_INLINE(void, nimFrame)(TFrame* s);
N_NOINLINE(void, stackoverflow_20001)(void);
static N_INLINE(void, popFrame)(void);
N_NIMCALL(void*, newObj)(TNimType* typ, NI size);
N_NIMCALL(NimStringDesc*, copyStringRC1)(NimStringDesc* src);
static N_INLINE(void, nimGCunrefNoCycle)(void* p);
static N_INLINE(Tcell46746*, usrtocell_50246)(void* usr);
static N_INLINE(void, rtladdzct_51804)(Tcell46746* c);
N_NOINLINE(void, addzct_50217)(Tcellseq46762* s, Tcell46746* c);
N_NIMCALL(void, raiseException)(Exception* e, NCSTRING ename);
N_NIMCALL(NI, nimParseBiggestFloat)(NimStringDesc* s, NF* number, NI start);
N_NIMCALL(NI, nimParseBiggestFloat)(NimStringDesc* s, NF* number, NI start);
static N_INLINE(NIM_CHAR, tolower_93014)(NIM_CHAR c);
static N_INLINE(NI, chckRange)(NI i, NI a, NI b);
N_NOINLINE(void, raiseRangeError)(NI64 val);
STRING_LITERAL(TMP290, "overflow", 8);
extern TFrame* frameptr_17042;
extern TNimType NTI23401; /* ref OverflowError */
extern TNimType NTI3443; /* OverflowError */
extern Tgcheap48616 gch_48644;

static N_INLINE(NI, addInt)(NI a, NI b) {
	NI result;
{	result = 0;
	result = (NI)((NU64)(a) + (NU64)(b));
	{
		NIM_BOOL LOC3;
		LOC3 = 0;
		LOC3 = (((NI) 0) <= (NI)(result ^ a));
		if (LOC3) goto LA4;
		LOC3 = (((NI) 0) <= (NI)(result ^ b));
		LA4: ;
		if (!LOC3) goto LA5;
		goto BeforeRet;
	}
	LA5: ;
	raiseOverflow();
	}BeforeRet: ;
	return result;
}

static N_INLINE(NI, subInt)(NI a, NI b) {
	NI result;
{	result = 0;
	result = (NI)((NU64)(a) - (NU64)(b));
	{
		NIM_BOOL LOC3;
		LOC3 = 0;
		LOC3 = (((NI) 0) <= (NI)(result ^ a));
		if (LOC3) goto LA4;
		LOC3 = (((NI) 0) <= (NI)(result ^ (NI)((NU64) ~(b))));
		LA4: ;
		if (!LOC3) goto LA5;
		goto BeforeRet;
	}
	LA5: ;
	raiseOverflow();
	}BeforeRet: ;
	return result;
}

static N_INLINE(NI64, subInt64)(NI64 a, NI64 b) {
	NI64 result;
{	result = 0;
	result = (NI64)((NU64)(a) - (NU64)(b));
	{
		NIM_BOOL LOC3;
		LOC3 = 0;
		LOC3 = (IL64(0) <= (NI64)(result ^ a));
		if (LOC3) goto LA4;
		LOC3 = (IL64(0) <= (NI64)(result ^ (NI64)((NU64) ~(b))));
		LA4: ;
		if (!LOC3) goto LA5;
		goto BeforeRet;
	}
	LA5: ;
	raiseOverflow();
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

N_NIMCALL(NI, rawparseint_93714)(NimStringDesc* s, NI64* b, NI start) {
	NI result;
	NI64 sign;
	NI i;
	nimfr("rawParseInt", "parseutils.nim")
	result = 0;
	nimln(194, "parseutils.nim");
	sign = IL64(-1);
	nimln(195, "parseutils.nim");
	i = start;
	nimln(196, "parseutils.nim");
	{
		NI TMP281;
		if ((NU)(i) > (NU)(s->Sup.len)) raiseIndexError();
		if (!((NU8)(s->data[i]) == (NU8)(43))) goto LA3;
		TMP281 = addInt(i, ((NI) 1));
		i = (NI)(TMP281);
	}
	goto LA1;
	LA3: ;
	{
		NI TMP282;
		nimln(197, "parseutils.nim");
		if ((NU)(i) > (NU)(s->Sup.len)) raiseIndexError();
		if (!((NU8)(s->data[i]) == (NU8)(45))) goto LA6;
		nimln(198, "parseutils.nim");
		TMP282 = addInt(i, ((NI) 1));
		i = (NI)(TMP282);
		nimln(199, "parseutils.nim");
		sign = IL64(1);
	}
	goto LA1;
	LA6: ;
	LA1: ;
	nimln(200, "parseutils.nim");
	{
		NI64 TMP288;
		NI TMP289;
		if ((NU)(i) > (NU)(s->Sup.len)) raiseIndexError();
		if (!(((NU8)(s->data[i])) >= ((NU8)(48)) && ((NU8)(s->data[i])) <= ((NU8)(57)))) goto LA10;
		nimln(201, "parseutils.nim");
		(*b) = IL64(0);
		{
			nimln(202, "parseutils.nim");
			while (1) {
				NI64 TMP283;
				NI TMP284;
				NI64 TMP285;
				NI TMP286;
				if ((NU)(i) > (NU)(s->Sup.len)) raiseIndexError();
				if (!(((NU8)(s->data[i])) >= ((NU8)(48)) && ((NU8)(s->data[i])) <= ((NU8)(57)))) goto LA13;
				nimln(203, "parseutils.nim");
				TMP283 = mulInt64((*b), IL64(10));
				if ((NU)(i) > (NU)(s->Sup.len)) raiseIndexError();
				TMP284 = subInt(((NI) (((NU8)(s->data[i])))), ((NI) 48));
				TMP285 = subInt64((NI64)(TMP283), ((NI64) ((NI)(TMP284))));
				(*b) = (NI64)(TMP285);
				nimln(204, "parseutils.nim");
				TMP286 = addInt(i, ((NI) 1));
				i = (NI)(TMP286);
				{
					nimln(205, "parseutils.nim");
					while (1) {
						NI TMP287;
						if ((NU)(i) > (NU)(s->Sup.len)) raiseIndexError();
						if (!((NU8)(s->data[i]) == (NU8)(95))) goto LA15;
						TMP287 = addInt(i, ((NI) 1));
						i = (NI)(TMP287);
					} LA15: ;
				}
			} LA13: ;
		}
		nimln(206, "parseutils.nim");
		TMP288 = mulInt64((*b), sign);
		(*b) = (NI64)(TMP288);
		nimln(207, "parseutils.nim");
		TMP289 = subInt(i, start);
		result = (NI)(TMP289);
	}
	LA10: ;
	popFrame();
	return result;
}

N_NIMCALL(NI, npuParseBiggestInt)(NimStringDesc* s, NI64* number, NI start) {
	NI result;
	NI64 res;
	nimfr("parseBiggestInt", "parseutils.nim")
	result = 0;
	res = 0;
	nimln(218, "parseutils.nim");
	result = rawparseint_93714(s, (&res), start);
	nimln(219, "parseutils.nim");
	(*number) = res;
	popFrame();
	return result;
}

static N_INLINE(Tcell46746*, usrtocell_50246)(void* usr) {
	Tcell46746* result;
	nimfr("usrToCell", "gc.nim")
	result = 0;
	nimln(118, "gc.nim");
	result = ((Tcell46746*) ((NI)((NU64)(((NI) (usr))) - (NU64)(((NI)sizeof(Tcell46746))))));
	popFrame();
	return result;
}

static N_INLINE(void, rtladdzct_51804)(Tcell46746* c) {
	nimfr("rtlAddZCT", "gc.nim")
	nimln(199, "gc.nim");
	addzct_50217((&gch_48644.zct), c);
	popFrame();
}

static N_INLINE(void, nimGCunrefNoCycle)(void* p) {
	Tcell46746* c;
	nimfr("nimGCunrefNoCycle", "gc.nim")
	nimln(233, "gc.nim");
	c = usrtocell_50246(p);
	nimln(235, "gc.nim");
	{
		nimln(167, "gc.nim");
		(*c).refcount -= ((NI) 8);
		nimln(168, "gc.nim");
		if (!((NU64)((*c).refcount) < (NU64)(((NI) 8)))) goto LA3;
		nimln(236, "gc.nim");
		rtladdzct_51804(c);
	}
	LA3: ;
	popFrame();
}

N_NIMCALL(NI, npuParseInt)(NimStringDesc* s, NI* number, NI start) {
	NI result;
	NI64 res;
	nimfr("parseInt", "parseutils.nim")
	result = 0;
	res = 0;
	nimln(227, "parseutils.nim");
	result = npuParseBiggestInt(s, (&res), start);
	nimln(228, "parseutils.nim");
	{
		NIM_BOOL LOC3;
		NIM_BOOL LOC5;
		Overflowerror3443* e_93855;
		NimStringDesc* LOC9;
		LOC3 = 0;
		LOC3 = NIM_FALSE;
		if (!(LOC3)) goto LA4;
		nimln(229, "parseutils.nim");
		LOC5 = 0;
		LOC5 = (res < (IL64(-9223372036854775807) - IL64(1)));
		if (LOC5) goto LA6;
		LOC5 = (IL64(9223372036854775807) < res);
		LA6: ;
		LOC3 = LOC5;
		LA4: ;
		if (!LOC3) goto LA7;
		e_93855 = 0;
		nimln(2265, "system.nim");
		e_93855 = (Overflowerror3443*) newObj((&NTI23401), sizeof(Overflowerror3443));
		(*e_93855).Sup.Sup.Sup.m_type = (&NTI3443);
		nimln(2266, "system.nim");
		LOC9 = 0;
		LOC9 = (*e_93855).Sup.Sup.message; (*e_93855).Sup.Sup.message = copyStringRC1(((NimStringDesc*) &TMP290));
		if (LOC9) nimGCunrefNoCycle(LOC9);
		nimln(230, "parseutils.nim");
		raiseException((Exception*)e_93855, "OverflowError");
	}
	goto LA1;
	LA7: ;
	{
		nimln(231, "parseutils.nim");
		if (!!((result == ((NI) 0)))) goto LA11;
		nimln(232, "parseutils.nim");
		(*number) = ((NI) (res));
	}
	goto LA1;
	LA11: ;
	LA1: ;
	popFrame();
	return result;
}

N_NIMCALL(NI, npuParseFloat)(NimStringDesc* s, NF* number, NI start) {
	NI result;
	NF bf;
	nimfr("parseFloat", "parseutils.nim")
	result = 0;
	bf = 0;
	nimln(246, "parseutils.nim");
	result = nimParseBiggestFloat(s, (&bf), start);
	nimln(247, "parseutils.nim");
	{
		if (!!((result == ((NI) 0)))) goto LA3;
		nimln(248, "parseutils.nim");
		(*number) = bf;
	}
	LA3: ;
	popFrame();
	return result;
}

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

static N_INLINE(NIM_CHAR, tolower_93014)(NIM_CHAR c) {
	NIM_CHAR result;
	nimfr("toLower", "parseutils.nim")
	result = 0;
	nimln(26, "parseutils.nim");
	{
		NI TMP2575;
		NI TMP2576;
		if (!(((NU8)(c)) >= ((NU8)(65)) && ((NU8)(c)) <= ((NU8)(90)))) goto LA3;
		TMP2575 = subInt(((NI) (((NU8)(c)))), ((NI) 65));
		TMP2576 = addInt(((NI) ((NI)(TMP2575))), ((NI) 97));
		result = ((NIM_CHAR) (((NI)chckRange((NI)(TMP2576), ((NI) 0), ((NI) 255)))));
	}
	goto LA1;
	LA3: ;
	{
		result = c;
	}
	LA1: ;
	popFrame();
	return result;
}

N_NIMCALL(NI, skipignorecase_93447)(NimStringDesc* s, NimStringDesc* token, NI start) {
	NI result;
	nimfr("skipIgnoreCase", "parseutils.nim")
	result = 0;
	{
		nimln(132, "parseutils.nim");
		while (1) {
			NIM_BOOL LOC3;
			NI TMP2577;
			NIM_CHAR LOC5;
			NIM_CHAR LOC6;
			NI TMP2578;
			LOC3 = 0;
			LOC3 = (result < (token ? token->Sup.len : 0));
			if (!(LOC3)) goto LA4;
			nimln(133, "parseutils.nim");
			TMP2577 = addInt(result, start);
			if ((NU)((NI)(TMP2577)) > (NU)(s->Sup.len)) raiseIndexError();
			LOC5 = 0;
			LOC5 = tolower_93014(s->data[(NI)(TMP2577)]);
			if ((NU)(result) > (NU)(token->Sup.len)) raiseIndexError();
			LOC6 = 0;
			LOC6 = tolower_93014(token->data[result]);
			LOC3 = ((NU8)(LOC5) == (NU8)(LOC6));
			LA4: ;
			if (!LOC3) goto LA2;
			TMP2578 = addInt(result, ((NI) 1));
			result = (NI)(TMP2578);
		} LA2: ;
	}
	nimln(134, "parseutils.nim");
	{
		if (!!((result == (token ? token->Sup.len : 0)))) goto LA9;
		result = ((NI) 0);
	}
	LA9: ;
	popFrame();
	return result;
}
NIM_EXTERNC N_NOINLINE(void, stdlib_parseutilsInit)(void) {
	nimfr("parseutils", "parseutils.nim")
	popFrame();
}

NIM_EXTERNC N_NOINLINE(void, stdlib_parseutilsDatInit)(void) {
}

