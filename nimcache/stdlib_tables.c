/* Generated by Nim Compiler v0.11.2 */
/*   (c) 2015 Andreas Rumpf */
/* The generated code is subject to the original license. */
/* Compiled for: Windows, amd64, gcc */
/* Command for C compiler:
   C:\Nim\dist\mingw\bin\gcc.exe -c  -w  -IC:\Nim\lib -o c:\users\owner\documents\nim\esfj\nimcache\stdlib_tables.o c:\users\owner\documents\nim\esfj\nimcache\stdlib_tables.c */
#define NIM_INTBITS 64
#include "nimbase.h"
typedef struct NimStringDesc NimStringDesc;
typedef struct TGenericSeq TGenericSeq;
typedef struct Table218371 Table218371;
typedef struct Keyvaluepairseq218374 Keyvaluepairseq218374;
typedef struct Keyvaluepair218377 Keyvaluepair218377;
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
struct  Table218371  {
Keyvaluepairseq218374* data;
NI counter;
};
struct Keyvaluepair218377 {
NI Field0;
NI64 Field1;
void* Field2;
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
struct Keyvaluepairseq218374 {
  TGenericSeq Sup;
  Keyvaluepair218377 data[SEQ_DECL_SIZE];
};
static N_INLINE(NIM_BOOL, isempty_215201)(NI hcode);
static N_INLINE(void, nimFrame)(TFrame* s);
N_NOINLINE(void, stackoverflow_20001)(void);
static N_INLINE(void, popFrame)(void);
static N_INLINE(NIM_BOOL, isfilled_215211)(NI hcode);
static N_INLINE(NIM_BOOL, mustrehash_215313)(NI length, NI counter);
N_NIMCALL(void, failedassertimpl_88817)(NimStringDesc* msg);
N_NIMCALL(NI, mulInt)(NI a, NI b);
static N_INLINE(NI, subInt)(NI a, NI b);
N_NOINLINE(void, raiseOverflow)(void);
static N_INLINE(NI, rightsize_215407)(NI count);
N_NIMCALL(NI, nextpoweroftwo_210531)(NI x);
static N_INLINE(NI, divInt)(NI a, NI b);
N_NOINLINE(void, raiseDivByZero)(void);
static N_INLINE(NI, addInt)(NI a, NI b);
static N_INLINE(NI, nexttry_215420)(NI h, NI maxhash);
static N_INLINE(NI, rawget_218633)(Table218371 t, NI64 key, NI* hc);
static N_INLINE(NI, hash_150814)(NI64 x);
N_NOINLINE(void, raiseIndexError)(void);
N_NIMCALL(void, enlarge_218720)(Table218371* t);
static N_INLINE(NI, chckRange)(NI i, NI a, NI b);
N_NOINLINE(void, raiseRangeError)(NI64 val);
N_NIMCALL(void, TMP1132)(void* p, NI op);
N_NIMCALL(void*, newSeq)(TNimType* typ, NI len);
N_NIMCALL(void, unsureAsgnRef)(void** dest, void* src);
static N_INLINE(NI, rawgetknownhc_218774)(Table218371 t, NI64 key, NI hc);
N_NIMCALL(void, rawinsert_218800)(Table218371* t, Keyvaluepairseq218374** data, NI64 key, void* val, NI hc, NI h);
STRING_LITERAL(TMP1080, "counter < length ", 17);
extern TFrame* frameptr_17042;
TNimType NTI218377; /* KeyValuePair */
extern TNimType NTI150019; /* THash */
extern TNimType NTI5710; /* BiggestInt */
extern TNimType NTI153; /* pointer */
TNimType NTI218374; /* KeyValuePairSeq */

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

static N_INLINE(NIM_BOOL, isempty_215201)(NI hcode) {
	NIM_BOOL result;
	nimfr("isEmpty", "tables.nim")
	result = 0;
	nimln(89, "tables.nim");
	result = (hcode == ((NI) 0));
	popFrame();
	return result;
}

static N_INLINE(NIM_BOOL, isfilled_215211)(NI hcode) {
	NIM_BOOL result;
	nimfr("isFilled", "tables.nim")
	result = 0;
	nimln(92, "tables.nim");
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

static N_INLINE(NIM_BOOL, mustrehash_215313)(NI length, NI counter) {
	NIM_BOOL result;
	NIM_BOOL LOC5;
	NI TMP1081;
	NI TMP1082;
	NI TMP1083;
	nimfr("mustRehash", "tables.nim")
	result = 0;
	nimln(128, "tables.nim");
	{
		if (!!((counter < length))) goto LA3;
		failedassertimpl_88817(((NimStringDesc*) &TMP1080));
	}
	LA3: ;
	nimln(129, "tables.nim");
	LOC5 = 0;
	TMP1081 = mulInt(length, ((NI) 2));
	TMP1082 = mulInt(counter, ((NI) 3));
	LOC5 = ((NI)(TMP1081) < (NI)(TMP1082));
	if (LOC5) goto LA6;
	TMP1083 = subInt(length, counter);
	LOC5 = ((NI)(TMP1083) < ((NI) 4));
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

static N_INLINE(NI, rightsize_215407)(NI count) {
	NI result;
	NI TMP1084;
	NI TMP1085;
	NI TMP1086;
	nimfr("rightSize", "tables.nim")
	result = 0;
	nimln(138, "tables.nim");
	TMP1084 = mulInt(((NI) (count)), ((NI) 3));
	TMP1085 = divInt(((NI) ((NI)(TMP1084))), ((NI) 2));
	TMP1086 = addInt(((NI) ((NI)(TMP1085))), ((NI) 4));
	result = nextpoweroftwo_210531(((NI) ((NI)(TMP1086))));
	popFrame();
	return result;
}

static N_INLINE(NI, nexttry_215420)(NI h, NI maxhash) {
	NI result;
	NI TMP1087;
	nimfr("nextTry", "tables.nim")
	result = 0;
	nimln(141, "tables.nim");
	TMP1087 = addInt(h, ((NI) 1));
	result = (NI)((NI)(TMP1087) & maxhash);
	popFrame();
	return result;
}

static N_INLINE(NI, hash_150814)(NI64 x) {
	NI result;
	nimfr("hash", "hashes.nim")
	result = 0;
	nimln(111, "hashes.nim");
	result = ((NI) (((NI32)(NU32)(NU64)(x))));
	popFrame();
	return result;
}

static N_INLINE(NI, rawget_218633)(Table218371 t, NI64 key, NI* hc) {
	NI result;
	NI h;
	NI TMP1127;
	nimfr("rawGet", "tables.nim")
{	result = 0;
	nimln(156, "tables.nim");
	(*hc) = hash_150814(key);
	nimln(157, "tables.nim");
	{
		if (!((*hc) == ((NI) 0))) goto LA3;
		nimln(158, "tables.nim");
		(*hc) = ((NI) 314159265);
	}
	LA3: ;
	nimln(144, "tables.nim");
	h = (NI)((*hc) & (t.data ? (t.data->Sup.len-1) : -1));
	{
		nimln(145, "tables.nim");
		while (1) {
			NIM_BOOL LOC7;
			if ((NU)(h) >= (NU)(t.data->Sup.len)) raiseIndexError();
			LOC7 = 0;
			LOC7 = isfilled_215211(t.data->data[h].Field0);
			if (!LOC7) goto LA6;
			nimln(150, "tables.nim");
			{
				NIM_BOOL LOC10;
				LOC10 = 0;
				if ((NU)(h) >= (NU)(t.data->Sup.len)) raiseIndexError();
				LOC10 = (t.data->data[h].Field0 == (*hc));
				if (!(LOC10)) goto LA11;
				if ((NU)(h) >= (NU)(t.data->Sup.len)) raiseIndexError();
				LOC10 = (t.data->data[h].Field1 == key);
				LA11: ;
				if (!LOC10) goto LA12;
				nimln(151, "tables.nim");
				result = h;
				goto BeforeRet;
			}
			LA12: ;
			nimln(152, "tables.nim");
			h = nexttry_215420(h, (t.data ? (t.data->Sup.len-1) : -1));
		} LA6: ;
	}
	nimln(153, "tables.nim");
	TMP1127 = subInt(((NI) -1), h);
	result = (NI)(TMP1127);
	}BeforeRet: ;
	popFrame();
	return result;
}

N_NIMCALL(void*, HEX5BHEX5D_218621)(Table218371 t, NI64 key) {
	void* result;
	NI hc;
	NI index;
	nimfr("[]", "tables.nim")
	result = 0;
	hc = 0;
	nimln(190, "tables.nim");
	index = rawget_218633(t, key, (&hc));
	nimln(191, "tables.nim");
	{
		if (!(((NI) 0) <= index)) goto LA3;
		if ((NU)(index) >= (NU)(t.data->Sup.len)) raiseIndexError();
		result = t.data->data[index].Field2;
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
N_NIMCALL(void, TMP1132)(void* p, NI op) {
	Keyvaluepairseq218374* a;
	NI LOC1;
	a = (Keyvaluepairseq218374*)p;
	LOC1 = 0;
	for (LOC1 = 0; LOC1 < a->Sup.len; LOC1++) {
	}
}

static N_INLINE(NI, rawgetknownhc_218774)(Table218371 t, NI64 key, NI hc) {
	NI result;
	NI h;
	NI TMP1133;
	nimfr("rawGetKnownHC", "tables.nim")
{	result = 0;
	nimln(144, "tables.nim");
	h = (NI)(hc & (t.data ? (t.data->Sup.len-1) : -1));
	{
		nimln(145, "tables.nim");
		while (1) {
			NIM_BOOL LOC3;
			if ((NU)(h) >= (NU)(t.data->Sup.len)) raiseIndexError();
			LOC3 = 0;
			LOC3 = isfilled_215211(t.data->data[h].Field0);
			if (!LOC3) goto LA2;
			nimln(150, "tables.nim");
			{
				NIM_BOOL LOC6;
				LOC6 = 0;
				if ((NU)(h) >= (NU)(t.data->Sup.len)) raiseIndexError();
				LOC6 = (t.data->data[h].Field0 == hc);
				if (!(LOC6)) goto LA7;
				if ((NU)(h) >= (NU)(t.data->Sup.len)) raiseIndexError();
				LOC6 = (t.data->data[h].Field1 == key);
				LA7: ;
				if (!LOC6) goto LA8;
				nimln(151, "tables.nim");
				result = h;
				goto BeforeRet;
			}
			LA8: ;
			nimln(152, "tables.nim");
			h = nexttry_215420(h, (t.data ? (t.data->Sup.len-1) : -1));
		} LA2: ;
	}
	nimln(153, "tables.nim");
	TMP1133 = subInt(((NI) -1), h);
	result = (NI)(TMP1133);
	}BeforeRet: ;
	popFrame();
	return result;
}

N_NIMCALL(void, rawinsert_218800)(Table218371* t, Keyvaluepairseq218374** data, NI64 key, void* val, NI hc, NI h) {
	nimfr("rawInsert", "tables.nim")
	nimln(171, "tables.nim");
	if ((NU)(h) >= (NU)((*data)->Sup.len)) raiseIndexError();
	(*data)->data[h].Field1 = key;
	nimln(172, "tables.nim");
	if ((NU)(h) >= (NU)((*data)->Sup.len)) raiseIndexError();
	(*data)->data[h].Field2 = val;
	nimln(173, "tables.nim");
	if ((NU)(h) >= (NU)((*data)->Sup.len)) raiseIndexError();
	(*data)->data[h].Field0 = hc;
	popFrame();
}

N_NIMCALL(void, enlarge_218720)(Table218371* t) {
	Keyvaluepairseq218374* n;
	NI TMP1130;
	Keyvaluepairseq218374* LOC1;
	nimfr("enlarge", "tables.nim")
	n = 0;
	nimln(224, "tables.nim");
	TMP1130 = mulInt(((*t).data ? (*t).data->Sup.len : 0), ((NI) 2));
	n = (Keyvaluepairseq218374*) newSeq((&NTI218374), ((NI)chckRange((NI)(TMP1130), ((NI) 0), ((NI) IL64(9223372036854775807)))));
	nimln(225, "tables.nim");
	LOC1 = 0;
	LOC1 = (*t).data;
	unsureAsgnRef((void**) (&(*t).data), n);
	n = LOC1;
	{
		NI i_218772;
		NI HEX3Atmp_218826;
		NI res_218829;
		i_218772 = 0;
		HEX3Atmp_218826 = 0;
		nimln(226, "tables.nim");
		HEX3Atmp_218826 = (n ? (n->Sup.len-1) : -1);
		nimln(1598, "system.nim");
		res_218829 = ((NI) 0);
		{
			nimln(1599, "system.nim");
			while (1) {
				NI TMP1135;
				if (!(res_218829 <= HEX3Atmp_218826)) goto LA4;
				nimln(1600, "system.nim");
				i_218772 = res_218829;
				nimln(227, "tables.nim");
				{
					NIM_BOOL LOC7;
					NI j;
					NI LOC10;
					NI TMP1134;
					if ((NU)(i_218772) >= (NU)(n->Sup.len)) raiseIndexError();
					LOC7 = 0;
					LOC7 = isfilled_215211(n->data[i_218772].Field0);
					if (!LOC7) goto LA8;
					nimln(228, "tables.nim");
					if ((NU)(i_218772) >= (NU)(n->Sup.len)) raiseIndexError();
					if ((NU)(i_218772) >= (NU)(n->Sup.len)) raiseIndexError();
					LOC10 = 0;
					LOC10 = rawgetknownhc_218774((*t), n->data[i_218772].Field1, n->data[i_218772].Field0);
					TMP1134 = subInt(((NI) -1), LOC10);
					j = (NI)(TMP1134);
					nimln(229, "tables.nim");
					if ((NU)(i_218772) >= (NU)(n->Sup.len)) raiseIndexError();
					if ((NU)(i_218772) >= (NU)(n->Sup.len)) raiseIndexError();
					if ((NU)(i_218772) >= (NU)(n->Sup.len)) raiseIndexError();
					rawinsert_218800(t, (&(*t).data), n->data[i_218772].Field1, n->data[i_218772].Field2, n->data[i_218772].Field0, j);
				}
				LA8: ;
				nimln(1614, "system.nim");
				TMP1135 = addInt(res_218829, ((NI) 1));
				res_218829 = (NI)(TMP1135);
			} LA4: ;
		}
	}
	popFrame();
}

N_NIMCALL(void, HEX5BHEX5DHEX3D_218683)(Table218371* t, NI64 key, void* val) {
	NI hc;
	NI index;
	nimfr("[]=", "tables.nim")
	hc = 0;
	nimln(248, "tables.nim");
	index = rawget_218633((*t), key, (&hc));
	nimln(249, "tables.nim");
	{
		if (!(((NI) 0) <= index)) goto LA3;
		if ((NU)(index) >= (NU)((*t).data->Sup.len)) raiseIndexError();
		(*t).data->data[index].Field2 = val;
	}
	goto LA1;
	LA3: ;
	{
		NI TMP1136;
		NI TMP1137;
		nimln(239, "tables.nim");
		{
			NIM_BOOL LOC8;
			LOC8 = 0;
			LOC8 = mustrehash_215313(((*t).data ? (*t).data->Sup.len : 0), (*t).counter);
			if (!LOC8) goto LA9;
			nimln(240, "tables.nim");
			enlarge_218720(t);
			nimln(241, "tables.nim");
			index = rawgetknownhc_218774((*t), key, hc);
		}
		LA9: ;
		nimln(242, "tables.nim");
		TMP1136 = subInt(((NI) -1), index);
		index = (NI)(TMP1136);
		nimln(243, "tables.nim");
		rawinsert_218800(t, (&(*t).data), key, val, hc, index);
		nimln(244, "tables.nim");
		TMP1137 = addInt((*t).counter, ((NI) 1));
		(*t).counter = (NI)(TMP1137);
	}
	LA1: ;
	popFrame();
}
NIM_EXTERNC N_NOINLINE(void, stdlib_tablesInit)(void) {
	nimfr("tables", "tables.nim")
	popFrame();
}

NIM_EXTERNC N_NOINLINE(void, stdlib_tablesDatInit)(void) {
static TNimNode* TMP1131[3];
static TNimNode TMP1078[4];
NTI218377.size = sizeof(Keyvaluepair218377);
NTI218377.kind = 18;
NTI218377.base = 0;
NTI218377.flags = 3;
TMP1131[0] = &TMP1078[1];
TMP1078[1].kind = 1;
TMP1078[1].offset = offsetof(Keyvaluepair218377, Field0);
TMP1078[1].typ = (&NTI150019);
TMP1078[1].name = "Field0";
TMP1131[1] = &TMP1078[2];
TMP1078[2].kind = 1;
TMP1078[2].offset = offsetof(Keyvaluepair218377, Field1);
TMP1078[2].typ = (&NTI5710);
TMP1078[2].name = "Field1";
TMP1131[2] = &TMP1078[3];
TMP1078[3].kind = 1;
TMP1078[3].offset = offsetof(Keyvaluepair218377, Field2);
TMP1078[3].typ = (&NTI153);
TMP1078[3].name = "Field2";
TMP1078[0].len = 3; TMP1078[0].kind = 2; TMP1078[0].sons = &TMP1131[0];
NTI218377.node = &TMP1078[0];
NTI218374.size = sizeof(Keyvaluepairseq218374*);
NTI218374.kind = 24;
NTI218374.base = (&NTI218377);
NTI218374.flags = 2;
NTI218374.marker = TMP1132;
}
