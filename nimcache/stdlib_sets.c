/* Generated by Nim Compiler v0.11.2 */
/*   (c) 2015 Andreas Rumpf */
/* The generated code is subject to the original license. */
/* Compiled for: Windows, amd64, gcc */
/* Command for C compiler:
   C:\Nim\dist\mingw\bin\gcc.exe -c  -w  -IC:\Nim\lib -o c:\users\owner\documents\nim\esfj\nimcache\stdlib_sets.o c:\users\owner\documents\nim\esfj\nimcache\stdlib_sets.c */
#define NIM_INTBITS 64
#include "nimbase.h"
typedef struct NimStringDesc NimStringDesc;
typedef struct TGenericSeq TGenericSeq;
typedef struct Hashset258026 Hashset258026;
typedef struct Keyvaluepairseq258029 Keyvaluepairseq258029;
typedef struct Keyvaluepair258032 Keyvaluepair258032;
typedef struct TNimType TNimType;
typedef struct TNimNode TNimNode;
struct  TGenericSeq  {
NI len;
NI reserved;
};
struct  NimStringDesc  {
  TGenericSeq Sup;
NIM_CHAR data[SEQ_DECL_SIZE];
};
struct  Hashset258026  {
Keyvaluepairseq258029* data;
NI counter;
};
struct Keyvaluepair258032 {
NI Field0;
NI Field1;
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
struct  TNimNode  {
NU8 kind;
NI offset;
TNimType* typ;
NCSTRING name;
NI len;
TNimNode** sons;
};
struct Keyvaluepairseq258029 {
  TGenericSeq Sup;
  Keyvaluepair258032 data[SEQ_DECL_SIZE];
};
static N_INLINE(NIM_BOOL, isempty_256434)(NI hcode);
static N_INLINE(void, nimFrame)(TFrame* s);
N_NOINLINE(void, stackoverflow_20001)(void);
static N_INLINE(void, popFrame)(void);
static N_INLINE(NIM_BOOL, isfilled_256444)(NI hcode);
static N_INLINE(NIM_BOOL, mustrehash_256503)(NI length, NI counter);
N_NIMCALL(void, failedassertimpl_88817)(NimStringDesc* msg);
N_NIMCALL(NI, mulInt)(NI a, NI b);
static N_INLINE(NI, subInt)(NI a, NI b);
N_NOINLINE(void, raiseOverflow)(void);
static N_INLINE(NI, rightsize_256607)(NI count);
N_NIMCALL(NI, nextpoweroftwo_119531)(NI x);
static N_INLINE(NI, divInt)(NI a, NI b);
N_NOINLINE(void, raiseDivByZero)(void);
static N_INLINE(NI, addInt)(NI a, NI b);
static N_INLINE(NI, nexttry_256620)(NI h, NI maxhash);
N_NIMCALL(void, init_258075)(Hashset258026* s, NI initialsize);
N_NIMCALL(NIM_BOOL, ispoweroftwo_119521)(NI x);
static N_INLINE(NI, chckRange)(NI i, NI a, NI b);
N_NOINLINE(void, raiseRangeError)(NI64 val);
N_NIMCALL(void, TMP2333)(void* p, NI op);
N_NIMCALL(void*, newSeq)(TNimType* typ, NI len);
N_NIMCALL(void, unsureAsgnRef)(void** dest, void* src);
N_NIMCALL(NIM_BOOL, isvalid_258267)(Hashset258026 s);
static N_INLINE(NI, rawget_258403)(Hashset258026 s, NI key, NI* hc);
static N_INLINE(NI, hash_116804)(NI x);
N_NOINLINE(void, raiseIndexError)(void);
N_NIMCALL(void, enlarge_258438)(Hashset258026* s);
static N_INLINE(NI, rawgetknownhc_258490)(Hashset258026 s, NI key, NI hc);
N_NIMCALL(void, rawinsert_258515)(Hashset258026* s, Keyvaluepairseq258029** data, NI key, NI hc, NI h);
STRING_LITERAL(TMP2323, "counter < length ", 17);
STRING_LITERAL(TMP2331, "isPowerOfTwo(initialSize) ", 26);
STRING_LITERAL(TMP2334, "isValid(s) The set needs to be initialized.", 43);
extern TFrame* frameptr_17042;
TNimType NTI258032; /* KeyValuePair */
extern TNimType NTI116023; /* THash */
extern TNimType NTI108; /* int */
TNimType NTI258029; /* KeyValuePairSeq */
TNimType NTI258026; /* HashSet */

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

static N_INLINE(NIM_BOOL, isempty_256434)(NI hcode) {
	NIM_BOOL result;
	nimfr("isEmpty", "sets.nim")
	result = 0;
	nimln(47, "sets.nim");
	result = (hcode == ((NI) 0));
	popFrame();
	return result;
}

static N_INLINE(NIM_BOOL, isfilled_256444)(NI hcode) {
	NIM_BOOL result;
	nimfr("isFilled", "sets.nim")
	result = 0;
	nimln(50, "sets.nim");
	result = !((hcode == ((NI) 0)));
	popFrame();
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

static N_INLINE(NIM_BOOL, mustrehash_256503)(NI length, NI counter) {
	NIM_BOOL result;
	NIM_BOOL LOC5;
	NI TMP2324;
	NI TMP2325;
	NI TMP2326;
	nimfr("mustRehash", "sets.nim")
	result = 0;
	nimln(114, "sets.nim");
	{
		if (!!((counter < length))) goto LA3;
		failedassertimpl_88817(((NimStringDesc*) &TMP2323));
	}
	LA3: ;
	nimln(115, "sets.nim");
	LOC5 = 0;
	TMP2324 = mulInt(length, ((NI) 2));
	TMP2325 = mulInt(counter, ((NI) 3));
	LOC5 = ((NI)(TMP2324) < (NI)(TMP2325));
	if (LOC5) goto LA6;
	TMP2326 = subInt(length, counter);
	LOC5 = ((NI)(TMP2326) < ((NI) 4));
	LA6: ;
	result = LOC5;
	popFrame();
	return result;
}

static N_INLINE(NI, divInt)(NI a, NI b) {
	NI result;
{	result = 0;
	{
		if (!(b == ((NI) 0))) goto LA3;
		raiseDivByZero();
	}
	LA3: ;
	{
		NIM_BOOL LOC7;
		LOC7 = 0;
		LOC7 = (a == ((NI) (IL64(-9223372036854775807) - IL64(1))));
		if (!(LOC7)) goto LA8;
		LOC7 = (b == ((NI) -1));
		LA8: ;
		if (!LOC7) goto LA9;
		raiseOverflow();
	}
	LA9: ;
	result = (NI)(a / b);
	goto BeforeRet;
	}BeforeRet: ;
	return result;
}

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

static N_INLINE(NI, rightsize_256607)(NI count) {
	NI result;
	NI TMP2327;
	NI TMP2328;
	NI TMP2329;
	nimfr("rightSize", "sets.nim")
	result = 0;
	nimln(124, "sets.nim");
	TMP2327 = mulInt(((NI) (count)), ((NI) 3));
	TMP2328 = divInt(((NI) ((NI)(TMP2327))), ((NI) 2));
	TMP2329 = addInt(((NI) ((NI)(TMP2328))), ((NI) 4));
	result = nextpoweroftwo_119531(((NI) ((NI)(TMP2329))));
	popFrame();
	return result;
}

static N_INLINE(NI, nexttry_256620)(NI h, NI maxhash) {
	NI result;
	NI TMP2330;
	nimfr("nextTry", "sets.nim")
	result = 0;
	nimln(127, "sets.nim");
	TMP2330 = addInt(h, ((NI) 1));
	result = (NI)((NI)(TMP2330) & maxhash);
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
N_NIMCALL(void, TMP2333)(void* p, NI op) {
	Keyvaluepairseq258029* a;
	NI LOC1;
	a = (Keyvaluepairseq258029*)p;
	LOC1 = 0;
	for (LOC1 = 0; LOC1 < a->Sup.len; LOC1++) {
	}
}

N_NIMCALL(void, init_258075)(Hashset258026* s, NI initialsize) {
	nimfr("init", "sets.nim")
	nimln(331, "sets.nim");
	{
		NIM_BOOL LOC3;
		LOC3 = 0;
		LOC3 = ispoweroftwo_119521(initialsize);
		if (!!(LOC3)) goto LA4;
		failedassertimpl_88817(((NimStringDesc*) &TMP2331));
	}
	LA4: ;
	nimln(332, "sets.nim");
	(*s).counter = ((NI) 0);
	nimln(333, "sets.nim");
	unsureAsgnRef((void**) (&(*s).data), (Keyvaluepairseq258029*) newSeq((&NTI258029), ((NI)chckRange(initialsize, ((NI) 0), ((NI) IL64(9223372036854775807))))));
	popFrame();
}

N_NIMCALL(void, initset_258067)(NI initialsize, Hashset258026* Result) {
	nimfr("initSet", "sets.nim")
	nimln(345, "sets.nim");
	init_258075(Result, initialsize);
	popFrame();
}

N_NIMCALL(NIM_BOOL, isvalid_258267)(Hashset258026 s) {
	NIM_BOOL result;
	nimfr("isValid", "sets.nim")
	result = 0;
	nimln(64, "sets.nim");
	result = !(s.data == 0);
	popFrame();
	return result;
}

static N_INLINE(NI, hash_116804)(NI x) {
	NI result;
	nimfr("hash", "hashes.nim")
	result = 0;
	nimln(107, "hashes.nim");
	result = x;
	popFrame();
	return result;
}

static N_INLINE(NI, rawget_258403)(Hashset258026 s, NI key, NI* hc) {
	NI result;
	NI h;
	NI TMP2335;
	nimfr("rawGet", "sets.nim")
{	result = 0;
	nimln(142, "sets.nim");
	(*hc) = hash_116804(key);
	nimln(143, "sets.nim");
	{
		if (!((*hc) == ((NI) 0))) goto LA3;
		nimln(144, "sets.nim");
		(*hc) = ((NI) 314159265);
	}
	LA3: ;
	nimln(130, "sets.nim");
	h = (NI)((*hc) & (s.data ? (s.data->Sup.len-1) : -1));
	{
		nimln(131, "sets.nim");
		while (1) {
			NIM_BOOL LOC7;
			if ((NU)(h) >= (NU)(s.data->Sup.len)) raiseIndexError();
			LOC7 = 0;
			LOC7 = isfilled_256444(s.data->data[h].Field0);
			if (!LOC7) goto LA6;
			nimln(136, "sets.nim");
			{
				NIM_BOOL LOC10;
				LOC10 = 0;
				if ((NU)(h) >= (NU)(s.data->Sup.len)) raiseIndexError();
				LOC10 = (s.data->data[h].Field0 == (*hc));
				if (!(LOC10)) goto LA11;
				if ((NU)(h) >= (NU)(s.data->Sup.len)) raiseIndexError();
				LOC10 = (s.data->data[h].Field1 == key);
				LA11: ;
				if (!LOC10) goto LA12;
				nimln(137, "sets.nim");
				result = h;
				goto BeforeRet;
			}
			LA12: ;
			nimln(138, "sets.nim");
			h = nexttry_256620(h, (s.data ? (s.data->Sup.len-1) : -1));
		} LA6: ;
	}
	nimln(139, "sets.nim");
	TMP2335 = subInt(((NI) -1), h);
	result = (NI)(TMP2335);
	}BeforeRet: ;
	popFrame();
	return result;
}

static N_INLINE(NI, rawgetknownhc_258490)(Hashset258026 s, NI key, NI hc) {
	NI result;
	NI h;
	NI TMP2337;
	nimfr("rawGetKnownHC", "sets.nim")
{	result = 0;
	nimln(130, "sets.nim");
	h = (NI)(hc & (s.data ? (s.data->Sup.len-1) : -1));
	{
		nimln(131, "sets.nim");
		while (1) {
			NIM_BOOL LOC3;
			if ((NU)(h) >= (NU)(s.data->Sup.len)) raiseIndexError();
			LOC3 = 0;
			LOC3 = isfilled_256444(s.data->data[h].Field0);
			if (!LOC3) goto LA2;
			nimln(136, "sets.nim");
			{
				NIM_BOOL LOC6;
				LOC6 = 0;
				if ((NU)(h) >= (NU)(s.data->Sup.len)) raiseIndexError();
				LOC6 = (s.data->data[h].Field0 == hc);
				if (!(LOC6)) goto LA7;
				if ((NU)(h) >= (NU)(s.data->Sup.len)) raiseIndexError();
				LOC6 = (s.data->data[h].Field1 == key);
				LA7: ;
				if (!LOC6) goto LA8;
				nimln(137, "sets.nim");
				result = h;
				goto BeforeRet;
			}
			LA8: ;
			nimln(138, "sets.nim");
			h = nexttry_256620(h, (s.data ? (s.data->Sup.len-1) : -1));
		} LA2: ;
	}
	nimln(139, "sets.nim");
	TMP2337 = subInt(((NI) -1), h);
	result = (NI)(TMP2337);
	}BeforeRet: ;
	popFrame();
	return result;
}

N_NIMCALL(void, rawinsert_258515)(Hashset258026* s, Keyvaluepairseq258029** data, NI key, NI hc, NI h) {
	nimfr("rawInsert", "sets.nim")
	nimln(148, "sets.nim");
	if ((NU)(h) >= (NU)((*data)->Sup.len)) raiseIndexError();
	(*data)->data[h].Field1 = key;
	nimln(149, "sets.nim");
	if ((NU)(h) >= (NU)((*data)->Sup.len)) raiseIndexError();
	(*data)->data[h].Field0 = hc;
	popFrame();
}

N_NIMCALL(void, enlarge_258438)(Hashset258026* s) {
	Keyvaluepairseq258029* n;
	NI TMP2336;
	Keyvaluepairseq258029* LOC1;
	nimfr("enlarge", "sets.nim")
	n = 0;
	nimln(191, "sets.nim");
	TMP2336 = mulInt(((*s).data ? (*s).data->Sup.len : 0), ((NI) 2));
	n = (Keyvaluepairseq258029*) newSeq((&NTI258029), ((NI)chckRange((NI)(TMP2336), ((NI) 0), ((NI) IL64(9223372036854775807)))));
	nimln(192, "sets.nim");
	LOC1 = 0;
	LOC1 = (*s).data;
	unsureAsgnRef((void**) (&(*s).data), n);
	n = LOC1;
	{
		NI i_258488;
		NI HEX3Atmp_258538;
		NI res_258541;
		i_258488 = 0;
		HEX3Atmp_258538 = 0;
		nimln(193, "sets.nim");
		HEX3Atmp_258538 = (n ? (n->Sup.len-1) : -1);
		nimln(1598, "system.nim");
		res_258541 = ((NI) 0);
		{
			nimln(1599, "system.nim");
			while (1) {
				NI TMP2339;
				if (!(res_258541 <= HEX3Atmp_258538)) goto LA4;
				nimln(1600, "system.nim");
				i_258488 = res_258541;
				nimln(194, "sets.nim");
				{
					NIM_BOOL LOC7;
					NI j;
					NI LOC10;
					NI TMP2338;
					if ((NU)(i_258488) >= (NU)(n->Sup.len)) raiseIndexError();
					LOC7 = 0;
					LOC7 = isfilled_256444(n->data[i_258488].Field0);
					if (!LOC7) goto LA8;
					nimln(195, "sets.nim");
					if ((NU)(i_258488) >= (NU)(n->Sup.len)) raiseIndexError();
					if ((NU)(i_258488) >= (NU)(n->Sup.len)) raiseIndexError();
					LOC10 = 0;
					LOC10 = rawgetknownhc_258490((*s), n->data[i_258488].Field1, n->data[i_258488].Field0);
					TMP2338 = subInt(((NI) -1), LOC10);
					j = (NI)(TMP2338);
					nimln(196, "sets.nim");
					if ((NU)(i_258488) >= (NU)(n->Sup.len)) raiseIndexError();
					if ((NU)(i_258488) >= (NU)(n->Sup.len)) raiseIndexError();
					rawinsert_258515(s, (&(*s).data), n->data[i_258488].Field1, n->data[i_258488].Field0, j);
				}
				LA8: ;
				nimln(1614, "system.nim");
				TMP2339 = addInt(res_258541, ((NI) 1));
				res_258541 = (NI)(TMP2339);
			} LA4: ;
		}
	}
	popFrame();
}

N_NIMCALL(void, incl_258257)(Hashset258026* s, NI key) {
	NI hc;
	NI index;
	nimfr("incl", "sets.nim")
	nimln(230, "sets.nim");
	{
		NIM_BOOL LOC3;
		LOC3 = 0;
		LOC3 = isvalid_258267((*s));
		if (!!(LOC3)) goto LA4;
		failedassertimpl_88817(((NimStringDesc*) &TMP2334));
	}
	LA4: ;
	hc = 0;
	nimln(200, "sets.nim");
	index = rawget_258403((*s), key, (&hc));
	nimln(201, "sets.nim");
	{
		NI TMP2340;
		NI TMP2341;
		if (!(index < ((NI) 0))) goto LA8;
		nimln(202, "sets.nim");
		{
			NIM_BOOL LOC12;
			LOC12 = 0;
			LOC12 = mustrehash_256503(((*s).data ? (*s).data->Sup.len : 0), (*s).counter);
			if (!LOC12) goto LA13;
			nimln(203, "sets.nim");
			enlarge_258438(s);
			nimln(204, "sets.nim");
			index = rawgetknownhc_258490((*s), key, hc);
		}
		LA13: ;
		nimln(205, "sets.nim");
		TMP2340 = subInt(((NI) -1), index);
		rawinsert_258515(s, (&(*s).data), key, hc, (NI)(TMP2340));
		nimln(206, "sets.nim");
		TMP2341 = addInt((*s).counter, ((NI) 1));
		(*s).counter = (NI)(TMP2341);
	}
	LA8: ;
	popFrame();
}

N_NIMCALL(NIM_BOOL, contains_258612)(Hashset258026 s, NI key) {
	NIM_BOOL result;
	NI hc;
	NI index;
	nimfr("contains", "sets.nim")
	result = 0;
	nimln(180, "sets.nim");
	{
		NIM_BOOL LOC3;
		LOC3 = 0;
		LOC3 = isvalid_258267(s);
		if (!!(LOC3)) goto LA4;
		failedassertimpl_88817(((NimStringDesc*) &TMP2334));
	}
	LA4: ;
	hc = 0;
	nimln(182, "sets.nim");
	index = rawget_258403(s, key, (&hc));
	nimln(183, "sets.nim");
	result = (((NI) 0) <= index);
	popFrame();
	return result;
}

N_NIMCALL(NI, len_258842)(Hashset258026 s) {
	NI result;
	nimfr("len", "sets.nim")
	result = 0;
	nimln(78, "sets.nim");
	result = s.counter;
	popFrame();
	return result;
}

N_NIMCALL(void, excl_264225)(Hashset258026* s, NI key) {
	NI hc;
	NI i;
	NI msk;
	nimfr("excl", "sets.nim")
{	nimln(263, "sets.nim");
	{
		NIM_BOOL LOC3;
		LOC3 = 0;
		LOC3 = isvalid_258267((*s));
		if (!!(LOC3)) goto LA4;
		failedassertimpl_88817(((NimStringDesc*) &TMP2334));
	}
	LA4: ;
	hc = 0;
	nimln(265, "sets.nim");
	i = rawget_258403((*s), key, (&hc));
	nimln(266, "sets.nim");
	msk = ((*s).data ? ((*s).data->Sup.len-1) : -1);
	nimln(267, "sets.nim");
	{
		NI TMP2367;
		if (!(((NI) 0) <= i)) goto LA8;
		nimln(268, "sets.nim");
		if ((NU)(i) >= (NU)((*s).data->Sup.len)) raiseIndexError();
		(*s).data->data[i].Field0 = ((NI) 0);
		nimln(269, "sets.nim");
		TMP2367 = subInt((*s).counter, ((NI) 1));
		(*s).counter = (NI)(TMP2367);
		{
			nimln(270, "sets.nim");
			while (1) {
				NI j;
				NI r;
				nimln(271, "sets.nim");
				j = i;
				nimln(272, "sets.nim");
				r = j;
				nimln(273, "sets.nim");
				if ((NU)(i) >= (NU)((*s).data->Sup.len)) raiseIndexError();
				(*s).data->data[i].Field0 = ((NI) 0);
				{
					nimln(249, "sets.nim");
					while (1) {
						NI TMP2368;
						nimln(275, "sets.nim");
						TMP2368 = addInt(i, ((NI) 1));
						i = (NI)((NI)(TMP2368) & msk);
						nimln(276, "sets.nim");
						{
							NIM_BOOL LOC16;
							if ((NU)(i) >= (NU)((*s).data->Sup.len)) raiseIndexError();
							LOC16 = 0;
							LOC16 = isempty_256434((*s).data->data[i].Field0);
							if (!LOC16) goto LA17;
							nimln(277, "sets.nim");
							goto BeforeRet;
						}
						LA17: ;
						nimln(278, "sets.nim");
						if ((NU)(i) >= (NU)((*s).data->Sup.len)) raiseIndexError();
						r = (NI)((*s).data->data[i].Field0 & msk);
						nimln(251, "sets.nim");
						{
							NIM_BOOL LOC21;
							NIM_BOOL LOC22;
							NIM_BOOL LOC23;
							NIM_BOOL LOC26;
							NIM_BOOL LOC29;
							nimln(274, "sets.nim");
							LOC21 = 0;
							LOC22 = 0;
							LOC23 = 0;
							LOC23 = (r <= i);
							if (!(LOC23)) goto LA24;
							LOC23 = (j < r);
							LA24: ;
							LOC22 = LOC23;
							if (LOC22) goto LA25;
							LOC26 = 0;
							LOC26 = (j < r);
							if (!(LOC26)) goto LA27;
							LOC26 = (i < j);
							LA27: ;
							LOC22 = LOC26;
							LA25: ;
							LOC21 = LOC22;
							if (LOC21) goto LA28;
							LOC29 = 0;
							LOC29 = (i < j);
							if (!(LOC29)) goto LA30;
							LOC29 = (r <= i);
							LA30: ;
							LOC21 = LOC29;
							LA28: ;
							if (!!(LOC21)) goto LA31;
							nimln(251, "sets.nim");
							goto LA12;
						}
						LA31: ;
					}
				} LA12: ;
				nimln(279, "sets.nim");
				if ((NU)(j) >= (NU)((*s).data->Sup.len)) raiseIndexError();
				if ((NU)(i) >= (NU)((*s).data->Sup.len)) raiseIndexError();
				(*s).data->data[j] = (*s).data->data[i];
			}
		}
	}
	LA8: ;
	}BeforeRet: ;
	popFrame();
}
NIM_EXTERNC N_NOINLINE(void, stdlib_setsInit)(void) {
	nimfr("sets", "sets.nim")
	popFrame();
}

NIM_EXTERNC N_NOINLINE(void, stdlib_setsDatInit)(void) {
static TNimNode* TMP2332[2];
static TNimNode* TMP2370[2];
static TNimNode TMP2321[6];
NTI258032.size = sizeof(Keyvaluepair258032);
NTI258032.kind = 18;
NTI258032.base = 0;
NTI258032.flags = 3;
TMP2332[0] = &TMP2321[1];
TMP2321[1].kind = 1;
TMP2321[1].offset = offsetof(Keyvaluepair258032, Field0);
TMP2321[1].typ = (&NTI116023);
TMP2321[1].name = "Field0";
TMP2332[1] = &TMP2321[2];
TMP2321[2].kind = 1;
TMP2321[2].offset = offsetof(Keyvaluepair258032, Field1);
TMP2321[2].typ = (&NTI108);
TMP2321[2].name = "Field1";
TMP2321[0].len = 2; TMP2321[0].kind = 2; TMP2321[0].sons = &TMP2332[0];
NTI258032.node = &TMP2321[0];
NTI258029.size = sizeof(Keyvaluepairseq258029*);
NTI258029.kind = 24;
NTI258029.base = (&NTI258032);
NTI258029.flags = 2;
NTI258029.marker = TMP2333;
NTI258026.size = sizeof(Hashset258026);
NTI258026.kind = 18;
NTI258026.base = 0;
NTI258026.flags = 2;
TMP2370[0] = &TMP2321[4];
TMP2321[4].kind = 1;
TMP2321[4].offset = offsetof(Hashset258026, data);
TMP2321[4].typ = (&NTI258029);
TMP2321[4].name = "data";
TMP2370[1] = &TMP2321[5];
TMP2321[5].kind = 1;
TMP2321[5].offset = offsetof(Hashset258026, counter);
TMP2321[5].typ = (&NTI108);
TMP2321[5].name = "counter";
TMP2321[3].len = 2; TMP2321[3].kind = 2; TMP2321[3].sons = &TMP2370[0];
NTI258026.node = &TMP2321[3];
}

