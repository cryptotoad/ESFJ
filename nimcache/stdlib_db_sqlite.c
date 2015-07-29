/* Generated by Nim Compiler v0.11.2 */
/*   (c) 2015 Andreas Rumpf */
/* The generated code is subject to the original license. */
/* Compiled for: Windows, amd64, gcc */
/* Command for C compiler:
   C:\Nim\dist\mingw\bin\gcc.exe -c  -w  -IC:\Nim\lib -o c:\users\owner\documents\nim\esfj\nimcache\stdlib_db_sqlite.o c:\users\owner\documents\nim\esfj\nimcache\stdlib_db_sqlite.c */
#define NIM_INTBITS 64
#include "nimbase.h"

#include <string.h>
typedef struct NimStringDesc NimStringDesc;
typedef struct TGenericSeq TGenericSeq;
typedef struct Tsqlite3165291 Tsqlite3165291;
typedef struct Edb167009 Edb167009;
typedef struct Ioerror3431 Ioerror3431;
typedef struct Systemerror3429 Systemerror3429;
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
typedef struct Tstmt165301 Tstmt165301;
typedef struct TY13606 TY13606;
typedef struct TY167494 TY167494;
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
struct  Systemerror3429  {
  Exception Sup;
};
struct  Ioerror3431  {
  Systemerror3429 Sup;
};
struct  Edb167009  {
  Ioerror3431 Sup;
};
struct  TNimNode  {
NU8 kind;
NI offset;
TNimType* typ;
NCSTRING name;
NI len;
TNimNode** sons;
};
typedef N_CDECL_PTR(NCSTRING, TY165547) (Tsqlite3165291* para1);
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
typedef N_CDECL_PTR(int, TY165571) (Tsqlite3165291* db, NCSTRING zsql, int nbyte, Tstmt165301** ppstmt, NCSTRING* pztail);
typedef N_CDECL_PTR(NI32, TY165740) (Tstmt165301* para1);
typedef N_CDECL_PTR(NI32, TY165815) (Tstmt165301* pstmt);
typedef N_CDECL_PTR(NI32, TY165759) (Tstmt165301* para1, NI32 icol);
typedef N_CDECL_PTR(NCSTRING, TY165794) (Tstmt165301* para1, NI32 icol);
typedef N_CDECL_PTR(NI32, TY165706) (Tstmt165301* pstmt);
typedef N_CDECL_PTR(NI64, TY165379) (Tsqlite3165291* para1);
typedef N_CDECL_PTR(NI32, TY165385) (Tsqlite3165291* para1);
typedef N_CDECL_PTR(NI32, TY165362) (Tsqlite3165291* para1);
typedef N_CDECL_PTR(NI32, TY165525) (NCSTRING filename, Tsqlite3165291** ppdb);
typedef NimStringDesc* TY167666[1];
typedef NimStringDesc* TY161637[1];
struct  Tsqlite3165291  {
char dummy;
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
struct  Tstmt165301  {
char dummy;
};
struct  Tfreecell27830  {
Tfreecell27830* next;
NI zerofield;
};
struct TY13606 {
  TGenericSeq Sup;
  NimStringDesc* data[SEQ_DECL_SIZE];
};
struct TY167494 {
  TGenericSeq Sup;
  TY13606* data[SEQ_DECL_SIZE];
};
static N_INLINE(NimStringDesc*, sql_167021)(NimStringDesc* query);
N_NIMCALL(NimStringDesc*, copyString)(NimStringDesc* src);
static N_INLINE(void, nimFrame)(TFrame* s);
N_NOINLINE(void, stackoverflow_20001)(void);
static N_INLINE(void, popFrame)(void);
N_NIMCALL(void, dberror_167032)(Tsqlite3165291* db);
N_NIMCALL(void, nimGCvisit)(void* d, NI op);
N_NIMCALL(void, TMP684)(void* p, NI op);
N_NIMCALL(void*, newObj)(TNimType* typ, NI size);
N_NIMCALL(NimStringDesc*, cstrToNimstr)(NCSTRING str);
static N_INLINE(void, asgnRefNoCycle)(void** dest, void* src);
static N_INLINE(Tcell46746*, usrtocell_50246)(void* usr);
static N_INLINE(void, rtladdzct_51804)(Tcell46746* c);
N_NOINLINE(void, addzct_50217)(Tcellseq46762* s, Tcell46746* c);
N_NIMCALL(void, raiseException)(Exception* e, NCSTRING ename);
N_NIMCALL(void, dberror_167052)(NimStringDesc* msg);
N_NIMCALL(NimStringDesc*, copyStringRC1)(NimStringDesc* src);
static N_INLINE(void, nimGCunrefNoCycle)(void* p);
N_NIMCALL(NimStringDesc*, dbquote_167072)(NimStringDesc* s);
N_NOINLINE(void, raiseIndexError)(void);
static N_INLINE(void, appendString)(NimStringDesc* dest, NimStringDesc* src);
N_NIMCALL(NimStringDesc*, resizeString)(NimStringDesc* dest, NI addlen);
N_NIMCALL(NimStringDesc*, addChar)(NimStringDesc* s, NIM_CHAR c);
static N_INLINE(NI, addInt)(NI a, NI b);
N_NOINLINE(void, raiseOverflow)(void);
N_NIMCALL(void, failedassertimpl_88817)(NimStringDesc* msg);
N_NIMCALL(NimStringDesc*, dbformat_167098)(NimStringDesc* formatstr, NimStringDesc** args, NI argsLen0);
N_NIMCALL(NIM_BOOL, tryexec_167138)(Tsqlite3165291* db, NimStringDesc* query, NimStringDesc** args, NI argsLen0);
static N_INLINE(NI, chckRange)(NI i, NI a, NI b);
N_NOINLINE(void, raiseRangeError)(NI64 val);
N_NIMCALL(void, exec_167155)(Tsqlite3165291* db, NimStringDesc* query, NimStringDesc** args, NI argsLen0);
N_NIMCALL(TY13606*, newrow_167167)(NI L);
N_NIMCALL(void*, newSeq)(TNimType* typ, NI len);
static N_INLINE(NI, subInt)(NI a, NI b);
N_NIMCALL(Tstmt165301*, setupquery_167215)(Tsqlite3165291* db, NimStringDesc* query, NimStringDesc** args, NI argsLen0);
N_NIMCALL(void, setrow_167230)(Tstmt165301* stmt, TY13606** r, int cols);
N_NIMCALL(NimStringDesc*, setLengthStr)(NimStringDesc* s, NI newlen);
N_NIMCALL(void, add_9054)(NimStringDesc** x, NCSTRING y);
N_NIMCALL(TY13606*, getrow_167472)(Tsqlite3165291* db, NimStringDesc* query, NimStringDesc** args, NI argsLen0);
N_NIMCALL(TY167494*, getallrows_167488)(Tsqlite3165291* db, NimStringDesc* query, NimStringDesc** args, NI argsLen0);
N_NIMCALL(void, TMP700)(void* p, NI op);
N_NIMCALL(TGenericSeq*, incrSeq)(TGenericSeq* seq, NI elemsize);
N_NIMCALL(void, genericSeqAssign)(void* dest, void* src_83404, TNimType* mt);
N_NIMCALL(NimStringDesc*, getvalue_167577)(Tsqlite3165291* db, NimStringDesc* query, NimStringDesc** args, NI argsLen0);
N_NIMCALL(NimStringDesc*, rawNewString)(NI space);
N_NIMCALL(NimStringDesc*, rawNewString)(NI cap);
N_NIMCALL(NI64, tryinsertid_167593)(Tsqlite3165291* db, NimStringDesc* query, NimStringDesc** args, NI argsLen0);
N_NIMCALL(NI64, insertid_167610)(Tsqlite3165291* db, NimStringDesc* query, NimStringDesc** args, NI argsLen0);
N_NIMCALL(NI64, execaffectedrows_167623)(Tsqlite3165291* db, NimStringDesc* query, NimStringDesc** args, NI argsLen0);
N_NIMCALL(void, close_167636)(Tsqlite3165291* db);
N_NIMCALL(Tsqlite3165291*, open_167645)(NimStringDesc* connection, NimStringDesc* user, NimStringDesc* password, NimStringDesc* database);
N_NIMCALL(NIM_BOOL, setencoding_167661)(Tsqlite3165291* connection, NimStringDesc* encoding);
static N_INLINE(NIM_BOOL, eqStrings)(NimStringDesc* a, NimStringDesc* b);
STRING_LITERAL(TMP688, "NULL", 4);
STRING_LITERAL(TMP689, "\'", 1);
STRING_LITERAL(TMP690, "\'\'", 2);
STRING_LITERAL(TMP692, "len(a) == L string modified while iterating over it", 51);
STRING_LITERAL(TMP693, "", 0);
STRING_LITERAL(TMP701, "PRAGMA encoding = ?", 19);
STRING_LITERAL(TMP702, "PRAGMA encoding", 15);
extern TFrame* frameptr_17042;
extern TNimType NTI3431; /* IOError */
TNimType NTI167009; /* EDb */
TNimType NTI167035; /* ref EDb */
extern TY165547 Dl_165546;
extern Tgcheap48616 gch_48644;
extern TY165571 Dl_165570;
extern TY165740 Dl_165739;
extern TY165815 Dl_165814;
extern TNimType NTI13606; /* seq[string] */
extern TY165759 Dl_165758;
extern TY165794 Dl_165793;
extern TY165706 Dl_165705;
TNimType NTI167494; /* seq[TRow] */
extern TY165379 Dl_165378;
extern TY165385 Dl_165384;
extern TY165362 Dl_165361;
extern TY165525 Dl_165524;

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

static N_INLINE(NimStringDesc*, sql_167021)(NimStringDesc* query) {
	NimStringDesc* result;
	nimfr("sql", "db_sqlite.nim")
	result = 0;
	nimln(34, "db_sqlite.nim");
	result = copyString(query);
	popFrame();
	return result;
}
N_NIMCALL(void, TMP684)(void* p, NI op) {
	Edb167009* a;
	a = (Edb167009*)p;
	nimGCvisit((void*)(*a).Sup.Sup.Sup.parent, op);
	nimGCvisit((void*)(*a).Sup.Sup.Sup.message, op);
	nimGCvisit((void*)(*a).Sup.Sup.Sup.trace, op);
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

static N_INLINE(void, asgnRefNoCycle)(void** dest, void* src) {
	nimfr("asgnRefNoCycle", "gc.nim")
	nimln(251, "gc.nim");
	{
		Tcell46746* c;
		if (!!((src == NIM_NIL))) goto LA3;
		nimln(252, "gc.nim");
		c = usrtocell_50246(src);
		nimln(169, "gc.nim");
		(*c).refcount += ((NI) 8);
	}
	LA3: ;
	nimln(254, "gc.nim");
	{
		Tcell46746* c;
		if (!!(((*dest) == NIM_NIL))) goto LA7;
		nimln(255, "gc.nim");
		c = usrtocell_50246((*dest));
		nimln(256, "gc.nim");
		{
			nimln(167, "gc.nim");
			(*c).refcount -= ((NI) 8);
			nimln(168, "gc.nim");
			if (!((NU64)((*c).refcount) < (NU64)(((NI) 8)))) goto LA11;
			nimln(257, "gc.nim");
			rtladdzct_51804(c);
		}
		LA11: ;
	}
	LA7: ;
	nimln(258, "gc.nim");
	(*dest) = src;
	popFrame();
}

N_NIMCALL(void, dberror_167032)(Tsqlite3165291* db) {
	Edb167009* e;
	NCSTRING LOC1;
	nimfr("dbError", "db_sqlite.nim")
	e = 0;
	nimln(39, "db_sqlite.nim");
	e = (Edb167009*) newObj((&NTI167035), sizeof(Edb167009));
	(*e).Sup.Sup.Sup.Sup.m_type = (&NTI167009);
	nimln(40, "db_sqlite.nim");
	LOC1 = 0;
	LOC1 = Dl_165546(db);
	asgnRefNoCycle((void**) (&(*e).Sup.Sup.Sup.message), cstrToNimstr(LOC1));
	nimln(41, "db_sqlite.nim");
	raiseException((Exception*)e, "EDb");
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

N_NIMCALL(void, dberror_167052)(NimStringDesc* msg) {
	Edb167009* e;
	NimStringDesc* LOC1;
	nimfr("dbError", "db_sqlite.nim")
	e = 0;
	nimln(46, "db_sqlite.nim");
	e = (Edb167009*) newObj((&NTI167035), sizeof(Edb167009));
	(*e).Sup.Sup.Sup.Sup.m_type = (&NTI167009);
	nimln(47, "db_sqlite.nim");
	LOC1 = 0;
	LOC1 = (*e).Sup.Sup.Sup.message; (*e).Sup.Sup.Sup.message = copyStringRC1(msg);
	if (LOC1) nimGCunrefNoCycle(LOC1);
	nimln(48, "db_sqlite.nim");
	raiseException((Exception*)e, "EDb");
	popFrame();
}

static N_INLINE(void, appendString)(NimStringDesc* dest, NimStringDesc* src) {
	memcpy(((NCSTRING) ((&(*dest).data[((*dest).Sup.len)- 0]))), ((NCSTRING) ((*src).data)), (NI)((*src).Sup.len + ((NI) 1)));
	(*dest).Sup.len += (*src).Sup.len;
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

N_NIMCALL(NimStringDesc*, dbquote_167072)(NimStringDesc* s) {
	NimStringDesc* result;
	nimfr("dbQuote", "db_sqlite.nim")
{	result = 0;
	nimln(51, "db_sqlite.nim");
	{
		if (!s == 0) goto LA3;
		result = copyString(((NimStringDesc*) &TMP688));
		goto BeforeRet;
	}
	LA3: ;
	nimln(52, "db_sqlite.nim");
	result = copyString(((NimStringDesc*) &TMP689));
	{
		NIM_CHAR c_167076;
		NI i_167080;
		NI L_167082;
		c_167076 = 0;
		nimln(3102, "system.nim");
		i_167080 = ((NI) 0);
		nimln(3103, "system.nim");
		L_167082 = (s ? s->Sup.len : 0);
		{
			nimln(3104, "system.nim");
			while (1) {
				NI TMP691;
				if (!(i_167080 < L_167082)) goto LA7;
				nimln(3105, "system.nim");
				if ((NU)(i_167080) > (NU)(s->Sup.len)) raiseIndexError();
				c_167076 = s->data[i_167080];
				nimln(54, "db_sqlite.nim");
				{
					if (!((NU8)(c_167076) == (NU8)(39))) goto LA10;
					result = resizeString(result, 2);
appendString(result, ((NimStringDesc*) &TMP690));
				}
				goto LA8;
				LA10: ;
				{
					nimln(55, "db_sqlite.nim");
					result = addChar(result, c_167076);
				}
				LA8: ;
				nimln(3106, "system.nim");
				TMP691 = addInt(i_167080, ((NI) 1));
				i_167080 = (NI)(TMP691);
				nimln(3107, "system.nim");
				{
					if (!!(((s ? s->Sup.len : 0) == L_167082))) goto LA15;
					failedassertimpl_88817(((NimStringDesc*) &TMP692));
				}
				LA15: ;
			} LA7: ;
		}
	}
	nimln(56, "db_sqlite.nim");
	result = addChar(result, 39);
	}BeforeRet: ;
	popFrame();
	return result;
}

N_NIMCALL(NimStringDesc*, dbformat_167098)(NimStringDesc* formatstr, NimStringDesc** args, NI argsLen0) {
	NimStringDesc* result;
	NI a;
	nimfr("dbFormat", "db_sqlite.nim")
	result = 0;
	nimln(59, "db_sqlite.nim");
	result = copyString(((NimStringDesc*) &TMP693));
	nimln(60, "db_sqlite.nim");
	a = ((NI) 0);
	{
		NIM_CHAR c_167105;
		NimStringDesc* HEX3Atmp_167117;
		NI i_167120;
		NI L_167122;
		c_167105 = 0;
		HEX3Atmp_167117 = 0;
		nimln(61, "db_sqlite.nim");
		HEX3Atmp_167117 = formatstr;
		nimln(3102, "system.nim");
		i_167120 = ((NI) 0);
		nimln(3103, "system.nim");
		L_167122 = (HEX3Atmp_167117 ? HEX3Atmp_167117->Sup.len : 0);
		{
			nimln(3104, "system.nim");
			while (1) {
				NI TMP695;
				if (!(i_167120 < L_167122)) goto LA3;
				nimln(3105, "system.nim");
				if ((NU)(i_167120) > (NU)(HEX3Atmp_167117->Sup.len)) raiseIndexError();
				c_167105 = HEX3Atmp_167117->data[i_167120];
				nimln(62, "db_sqlite.nim");
				{
					NimStringDesc* LOC8;
					NI TMP694;
					if (!((NU8)(c_167105) == (NU8)(63))) goto LA6;
					nimln(63, "db_sqlite.nim");
					if ((NU)(a) >= (NU)(argsLen0)) raiseIndexError();
					LOC8 = 0;
					LOC8 = dbquote_167072(args[a]);
					result = resizeString(result, LOC8->Sup.len + 0);
appendString(result, LOC8);
					nimln(64, "db_sqlite.nim");
					TMP694 = addInt(a, ((NI) 1));
					a = (NI)(TMP694);
				}
				goto LA4;
				LA6: ;
				{
					nimln(66, "db_sqlite.nim");
					result = addChar(result, c_167105);
				}
				LA4: ;
				nimln(3106, "system.nim");
				TMP695 = addInt(i_167120, ((NI) 1));
				i_167120 = (NI)(TMP695);
				nimln(3107, "system.nim");
				{
					if (!!(((HEX3Atmp_167117 ? HEX3Atmp_167117->Sup.len : 0) == L_167122))) goto LA12;
					failedassertimpl_88817(((NimStringDesc*) &TMP692));
				}
				LA12: ;
			} LA3: ;
		}
	}
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

N_NIMCALL(NIM_BOOL, tryexec_167138)(Tsqlite3165291* db, NimStringDesc* query, NimStringDesc** args, NI argsLen0) {
	NIM_BOOL result;
	NimStringDesc* q;
	Tstmt165301* stmt;
	nimfr("tryExec", "db_sqlite.nim")
	result = 0;
	nimln(71, "db_sqlite.nim");
	q = dbformat_167098(query, args, argsLen0);
	stmt = 0;
	nimln(73, "db_sqlite.nim");
	{
		int LOC3;
		LOC3 = 0;
		LOC3 = Dl_165570(db, q->data, ((int)chckRange((q ? q->Sup.len : 0), ((int) (-2147483647 -1)), ((int) 2147483647))), &stmt, NIM_NIL);
		if (!(LOC3 == ((NI32) 0))) goto LA4;
		nimln(74, "db_sqlite.nim");
		{
			NI32 LOC8;
			NI32 LOC11;
			LOC8 = 0;
			LOC8 = Dl_165739(stmt);
			if (!(LOC8 == ((NI32) 101))) goto LA9;
			nimln(75, "db_sqlite.nim");
			LOC11 = 0;
			LOC11 = Dl_165814(stmt);
			result = (LOC11 == ((NI32) 0));
		}
		LA9: ;
	}
	LA4: ;
	popFrame();
	return result;
}

N_NIMCALL(void, exec_167155)(Tsqlite3165291* db, NimStringDesc* query, NimStringDesc** args, NI argsLen0) {
	nimfr("exec", "db_sqlite.nim")
	nimln(80, "db_sqlite.nim");
	{
		NIM_BOOL LOC3;
		LOC3 = 0;
		LOC3 = tryexec_167138(db, query, args, argsLen0);
		if (!!(LOC3)) goto LA4;
		dberror_167032(db);
	}
	LA4: ;
	popFrame();
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

N_NIMCALL(TY13606*, newrow_167167)(NI L) {
	TY13606* result;
	nimfr("newRow", "db_sqlite.nim")
	result = 0;
	nimln(83, "db_sqlite.nim");
	result = (TY13606*) newSeq((&NTI13606), ((NI)chckRange(L, ((NI) 0), ((NI) IL64(9223372036854775807)))));
	{
		NI i_167191;
		NI HEX3Atmp_167193;
		NI TMP696;
		NI res_167196;
		i_167191 = 0;
		HEX3Atmp_167193 = 0;
		nimln(84, "db_sqlite.nim");
		TMP696 = subInt(L, ((NI) 1));
		HEX3Atmp_167193 = (NI)(TMP696);
		nimln(1598, "system.nim");
		res_167196 = ((NI) 0);
		{
			nimln(1599, "system.nim");
			while (1) {
				NimStringDesc* LOC4;
				NI TMP697;
				if (!(res_167196 <= HEX3Atmp_167193)) goto LA3;
				nimln(1600, "system.nim");
				i_167191 = res_167196;
				nimln(84, "db_sqlite.nim");
				if ((NU)(i_167191) >= (NU)(result->Sup.len)) raiseIndexError();
				LOC4 = 0;
				LOC4 = result->data[i_167191]; result->data[i_167191] = copyStringRC1(((NimStringDesc*) &TMP693));
				if (LOC4) nimGCunrefNoCycle(LOC4);
				nimln(1619, "system.nim");
				TMP697 = addInt(res_167196, ((NI) 1));
				res_167196 = (NI)(TMP697);
			} LA3: ;
		}
	}
	popFrame();
	return result;
}

N_NIMCALL(Tstmt165301*, setupquery_167215)(Tsqlite3165291* db, NimStringDesc* query, NimStringDesc** args, NI argsLen0) {
	Tstmt165301* result;
	NimStringDesc* q;
	nimfr("setupQuery", "db_sqlite.nim")
	result = 0;
	nimln(88, "db_sqlite.nim");
	q = dbformat_167098(query, args, argsLen0);
	nimln(89, "db_sqlite.nim");
	{
		int LOC3;
		LOC3 = 0;
		LOC3 = Dl_165570(db, q->data, ((int)chckRange((q ? q->Sup.len : 0), ((int) (-2147483647 -1)), ((int) 2147483647))), &result, NIM_NIL);
		if (!!((LOC3 == ((NI32) 0)))) goto LA4;
		dberror_167032(db);
	}
	LA4: ;
	popFrame();
	return result;
}

N_NIMCALL(void, setrow_167230)(Tstmt165301* stmt, TY13606** r, int cols) {
	nimfr("setRow", "db_sqlite.nim")
	{
		NI32 col_167423;
		NI32 HEX3Atmp_167427;
		NI TMP698;
		NI res_167430;
		col_167423 = 0;
		HEX3Atmp_167427 = 0;
		nimln(92, "db_sqlite.nim");
		TMP698 = subInt(cols, ((NI32) 1));
		if (TMP698 < (-2147483647 -1) || TMP698 > 2147483647) raiseOverflow();
		HEX3Atmp_167427 = (NI32)(TMP698);
		nimln(1598, "system.nim");
		res_167430 = ((NI) 0);
		{
			nimln(1599, "system.nim");
			while (1) {
				NI32 LOC4;
				NCSTRING x;
				NI TMP699;
				if (!(res_167430 <= ((NI) (HEX3Atmp_167427)))) goto LA3;
				nimln(1600, "system.nim");
				col_167423 = ((NI32)chckRange(res_167430, ((NI32) (-2147483647 -1)), ((NI32) 2147483647)));
				nimln(93, "db_sqlite.nim");
				if ((NU)(col_167423) >= (NU)((*r)->Sup.len)) raiseIndexError();
				LOC4 = 0;
				LOC4 = Dl_165758(stmt, col_167423);
				(*r)->data[col_167423] = setLengthStr((*r)->data[col_167423], ((NI)chckRange(LOC4, ((NI) 0), ((NI) IL64(9223372036854775807)))));
				nimln(94, "db_sqlite.nim");
				if ((NU)(col_167423) >= (NU)((*r)->Sup.len)) raiseIndexError();
				(*r)->data[col_167423] = setLengthStr((*r)->data[col_167423], ((NI) 0));
				nimln(95, "db_sqlite.nim");
				x = Dl_165793(stmt, col_167423);
				nimln(96, "db_sqlite.nim");
				{
					if (!!(x == 0)) goto LA7;
					if ((NU)(col_167423) >= (NU)((*r)->Sup.len)) raiseIndexError();
					add_9054((&(*r)->data[col_167423]), x);
				}
				LA7: ;
				nimln(1619, "system.nim");
				TMP699 = addInt(res_167430, ((NI) 1));
				res_167430 = (NI)(TMP699);
			} LA3: ;
		}
	}
	popFrame();
}

N_NIMCALL(TY13606*, getrow_167472)(Tsqlite3165291* db, NimStringDesc* query, NimStringDesc** args, NI argsLen0) {
	TY13606* result;
	Tstmt165301* stmt;
	NI32 L;
	nimfr("getRow", "db_sqlite.nim")
	result = 0;
	nimln(115, "db_sqlite.nim");
	stmt = setupquery_167215(db, query, args, argsLen0);
	nimln(116, "db_sqlite.nim");
	L = Dl_165705(stmt);
	nimln(117, "db_sqlite.nim");
	result = newrow_167167(((NI) (L)));
	nimln(118, "db_sqlite.nim");
	{
		NI32 LOC3;
		LOC3 = 0;
		LOC3 = Dl_165739(stmt);
		if (!(LOC3 == ((NI32) 100))) goto LA4;
		nimln(119, "db_sqlite.nim");
		setrow_167230(stmt, (&result), L);
	}
	LA4: ;
	nimln(120, "db_sqlite.nim");
	{
		NI32 LOC8;
		LOC8 = 0;
		LOC8 = Dl_165814(stmt);
		if (!!((LOC8 == ((NI32) 0)))) goto LA9;
		dberror_167032(db);
	}
	LA9: ;
	popFrame();
	return result;
}
N_NIMCALL(void, TMP700)(void* p, NI op) {
	TY167494* a;
	NI LOC1;
	a = (TY167494*)p;
	LOC1 = 0;
	for (LOC1 = 0; LOC1 < a->Sup.len; LOC1++) {
	nimGCvisit((void*)a->data[LOC1], op);
	}
}

N_NIMCALL(TY167494*, getallrows_167488)(Tsqlite3165291* db, NimStringDesc* query, NimStringDesc** args, NI argsLen0) {
	TY167494* result;
	nimfr("getAllRows", "db_sqlite.nim")
	result = 0;
	nimln(125, "db_sqlite.nim");
	result = (TY167494*) newSeq((&NTI167494), 0);
	{
		TY13606* r_167512;
		Tstmt165301* stmt_167526;
		NI32 L_167528;
		TY13606* result_167530;
		r_167512 = 0;
		nimln(103, "db_sqlite.nim");
		stmt_167526 = setupquery_167215(db, query, args, argsLen0);
		nimln(104, "db_sqlite.nim");
		L_167528 = Dl_165705(stmt_167526);
		nimln(105, "db_sqlite.nim");
		result_167530 = newrow_167167(((NI) (L_167528)));
		{
			nimln(106, "db_sqlite.nim");
			while (1) {
				NI32 LOC4;
				LOC4 = 0;
				LOC4 = Dl_165739(stmt_167526);
				if (!(LOC4 == ((NI32) 100))) goto LA3;
				nimln(107, "db_sqlite.nim");
				setrow_167230(stmt_167526, (&result_167530), L_167528);
				nimln(105, "db_sqlite.nim");
				r_167512 = result_167530;
				nimln(127, "db_sqlite.nim");
				result = (TY167494*) incrSeq(&(result)->Sup, sizeof(TY13606*));
				genericSeqAssign((&result->data[result->Sup.len-1]), r_167512, (&NTI13606));
			} LA3: ;
		}
		nimln(109, "db_sqlite.nim");
		{
			NI32 LOC7;
			LOC7 = 0;
			LOC7 = Dl_165814(stmt_167526);
			if (!!((LOC7 == ((NI32) 0)))) goto LA8;
			dberror_167032(db);
		}
		LA8: ;
	}
	popFrame();
	return result;
}

N_NIMCALL(NimStringDesc*, getvalue_167577)(Tsqlite3165291* db, NimStringDesc* query, NimStringDesc** args, NI argsLen0) {
	NimStringDesc* result;
	Tstmt165301* stmt;
	nimfr("getValue", "db_sqlite.nim")
	result = 0;
	nimln(139, "db_sqlite.nim");
	stmt = setupquery_167215(db, query, args, argsLen0);
	nimln(140, "db_sqlite.nim");
	{
		NI32 LOC3;
		NI32 cb;
		LOC3 = 0;
		LOC3 = Dl_165739(stmt);
		if (!(LOC3 == ((NI32) 100))) goto LA4;
		nimln(141, "db_sqlite.nim");
		cb = Dl_165758(stmt, ((NI32) 0));
		nimln(142, "db_sqlite.nim");
		{
			if (!(cb == ((NI32) 0))) goto LA8;
			nimln(143, "db_sqlite.nim");
			result = copyString(((NimStringDesc*) &TMP693));
		}
		goto LA6;
		LA8: ;
		{
			NCSTRING LOC11;
			nimln(145, "db_sqlite.nim");
			result = rawNewString(((NI)chckRange(cb, ((NI) 0), ((NI) IL64(9223372036854775807)))));
			nimln(146, "db_sqlite.nim");
			LOC11 = 0;
			LOC11 = Dl_165793(stmt, ((NI32) 0));
			add_9054((&result), LOC11);
		}
		LA6: ;
	}
	goto LA1;
	LA4: ;
	{
		nimln(148, "db_sqlite.nim");
		result = copyString(((NimStringDesc*) &TMP693));
	}
	LA1: ;
	nimln(149, "db_sqlite.nim");
	{
		NI32 LOC15;
		LOC15 = 0;
		LOC15 = Dl_165814(stmt);
		if (!!((LOC15 == ((NI32) 0)))) goto LA16;
		dberror_167032(db);
	}
	LA16: ;
	popFrame();
	return result;
}

N_NIMCALL(NI64, tryinsertid_167593)(Tsqlite3165291* db, NimStringDesc* query, NimStringDesc** args, NI argsLen0) {
	NI64 result;
	NimStringDesc* q;
	Tstmt165301* stmt;
	nimfr("tryInsertID", "db_sqlite.nim")
	result = 0;
	nimln(156, "db_sqlite.nim");
	q = dbformat_167098(query, args, argsLen0);
	stmt = 0;
	nimln(158, "db_sqlite.nim");
	result = IL64(-1);
	nimln(159, "db_sqlite.nim");
	{
		int LOC3;
		LOC3 = 0;
		LOC3 = Dl_165570(db, q->data, ((int)chckRange((q ? q->Sup.len : 0), ((int) (-2147483647 -1)), ((int) 2147483647))), &stmt, NIM_NIL);
		if (!(LOC3 == ((NI32) 0))) goto LA4;
		nimln(160, "db_sqlite.nim");
		{
			NI32 LOC8;
			LOC8 = 0;
			LOC8 = Dl_165739(stmt);
			if (!(LOC8 == ((NI32) 101))) goto LA9;
			nimln(161, "db_sqlite.nim");
			result = Dl_165378(db);
		}
		LA9: ;
		nimln(162, "db_sqlite.nim");
		{
			NI32 LOC13;
			LOC13 = 0;
			LOC13 = Dl_165814(stmt);
			if (!!((LOC13 == ((NI32) 0)))) goto LA14;
			nimln(163, "db_sqlite.nim");
			result = IL64(-1);
		}
		LA14: ;
	}
	LA4: ;
	popFrame();
	return result;
}

N_NIMCALL(NI64, insertid_167610)(Tsqlite3165291* db, NimStringDesc* query, NimStringDesc** args, NI argsLen0) {
	NI64 result;
	nimfr("insertID", "db_sqlite.nim")
	result = 0;
	nimln(171, "db_sqlite.nim");
	result = tryinsertid_167593(db, query, args, argsLen0);
	nimln(172, "db_sqlite.nim");
	{
		if (!(result < IL64(0))) goto LA3;
		dberror_167032(db);
	}
	LA3: ;
	popFrame();
	return result;
}

N_NIMCALL(NI64, execaffectedrows_167623)(Tsqlite3165291* db, NimStringDesc* query, NimStringDesc** args, NI argsLen0) {
	NI64 result;
	NI32 LOC1;
	nimfr("execAffectedRows", "db_sqlite.nim")
	result = 0;
	nimln(179, "db_sqlite.nim");
	exec_167155(db, query, args, argsLen0);
	nimln(180, "db_sqlite.nim");
	LOC1 = 0;
	LOC1 = Dl_165384(db);
	result = ((NI64) (LOC1));
	popFrame();
	return result;
}

N_NIMCALL(void, close_167636)(Tsqlite3165291* db) {
	nimfr("close", "db_sqlite.nim")
	nimln(184, "db_sqlite.nim");
	{
		NI32 LOC3;
		LOC3 = 0;
		LOC3 = Dl_165361(db);
		if (!!((LOC3 == ((NI32) 0)))) goto LA4;
		dberror_167032(db);
	}
	LA4: ;
	popFrame();
}

N_NIMCALL(Tsqlite3165291*, open_167645)(NimStringDesc* connection, NimStringDesc* user, NimStringDesc* password, NimStringDesc* database) {
	Tsqlite3165291* result;
	Tsqlite3165291* db;
	nimfr("open", "db_sqlite.nim")
	result = 0;
	db = 0;
	nimln(191, "db_sqlite.nim");
	{
		NI32 LOC3;
		LOC3 = 0;
		LOC3 = Dl_165524(connection->data, &db);
		if (!(LOC3 == ((NI32) 0))) goto LA4;
		nimln(192, "db_sqlite.nim");
		result = db;
	}
	goto LA1;
	LA4: ;
	{
		nimln(194, "db_sqlite.nim");
		dberror_167032(db);
	}
	LA1: ;
	popFrame();
	return result;
}

static N_INLINE(NIM_BOOL, eqStrings)(NimStringDesc* a, NimStringDesc* b) {
	NIM_BOOL result;
	NIM_BOOL LOC11;
	int LOC13;
{	result = 0;
	{
		if (!(a == b)) goto LA3;
		result = NIM_TRUE;
		goto BeforeRet;
	}
	LA3: ;
	{
		NIM_BOOL LOC7;
		LOC7 = 0;
		LOC7 = (a == NIM_NIL);
		if (LOC7) goto LA8;
		LOC7 = (b == NIM_NIL);
		LA8: ;
		if (!LOC7) goto LA9;
		result = NIM_FALSE;
		goto BeforeRet;
	}
	LA9: ;
	LOC11 = 0;
	LOC11 = ((*a).Sup.len == (*b).Sup.len);
	if (!(LOC11)) goto LA12;
	LOC13 = 0;
	LOC13 = memcmp(((NCSTRING) ((*a).data)), ((NCSTRING) ((*b).data)), (*a).Sup.len);
	LOC11 = (LOC13 == ((NI32) 0));
	LA12: ;
	result = LOC11;
	goto BeforeRet;
	}BeforeRet: ;
	return result;
}

N_NIMCALL(NIM_BOOL, setencoding_167661)(Tsqlite3165291* connection, NimStringDesc* encoding) {
	NIM_BOOL result;
	NimStringDesc* LOC1;
	TY167666 LOC2;
	NimStringDesc* LOC3;
	TY161637 LOC4;
	NimStringDesc* LOC5;
	nimfr("setEncoding", "db_sqlite.nim")
	result = 0;
	nimln(205, "db_sqlite.nim");
	LOC1 = 0;
	LOC1 = sql_167021(((NimStringDesc*) &TMP701));
	memset((void*)LOC2, 0, sizeof(LOC2));
	LOC2[0] = copyString(encoding);
	exec_167155(connection, LOC1, LOC2, 1);
	nimln(206, "db_sqlite.nim");
	LOC3 = 0;
	LOC3 = sql_167021(((NimStringDesc*) &TMP702));
	memset((void*)LOC4, 0, sizeof(LOC4));
	LOC5 = 0;
	LOC5 = getvalue_167577(connection, LOC3, LOC4, 0);
	result = eqStrings(LOC5, encoding);
	popFrame();
	return result;
}
NIM_EXTERNC N_NOINLINE(void, stdlib_db_sqliteInit)(void) {
	nimfr("db_sqlite", "db_sqlite.nim")
	popFrame();
}

NIM_EXTERNC N_NOINLINE(void, stdlib_db_sqliteDatInit)(void) {
static TNimNode TMP680[1];
NTI167009.size = sizeof(Edb167009);
NTI167009.kind = 17;
NTI167009.base = (&NTI3431);
TMP680[0].len = 0; TMP680[0].kind = 2;
NTI167009.node = &TMP680[0];
NTI167035.size = sizeof(Edb167009*);
NTI167035.kind = 22;
NTI167035.base = (&NTI167009);
NTI167035.marker = TMP684;
NTI167494.size = sizeof(TY167494*);
NTI167494.kind = 24;
NTI167494.base = (&NTI13606);
NTI167494.flags = 2;
NTI167494.marker = TMP700;
}
