/* Generated by Nim Compiler v0.11.2 */
/*   (c) 2015 Andreas Rumpf */
/* The generated code is subject to the original license. */
/* Compiled for: Windows, amd64, gcc */
/* Command for C compiler:
   C:\Nim\dist\mingw\bin\gcc.exe -c  -w  -IC:\Nim\lib -o c:\users\owner\documents\nim\esfj\nimcache\stdlib_sqlite3.o c:\users\owner\documents\nim\esfj\nimcache\stdlib_sqlite3.c */
#define NIM_INTBITS 64
#include "nimbase.h"
typedef struct TGenericSeq TGenericSeq;
typedef struct NimStringDesc NimStringDesc;
typedef struct Tsqlite3165291 Tsqlite3165291;
typedef struct Tstmt165301 Tstmt165301;
struct  TGenericSeq  {
NI len;
NI reserved;
};
struct  NimStringDesc  {
  TGenericSeq Sup;
NIM_CHAR data[SEQ_DECL_SIZE];
};
typedef N_CDECL_PTR(NCSTRING, TY165547) (Tsqlite3165291* para1);
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
struct  Tsqlite3165291  {
char dummy;
};
struct  Tstmt165301  {
char dummy;
};
N_NIMCALL(void*, nimLoadLibrary)(NimStringDesc* path);
N_NOINLINE(void, nimLoadLibraryError)(NimStringDesc* path);
N_NIMCALL(void*, nimGetProcAddr)(void* lib, NCSTRING name);
static N_INLINE(void, nimFrame)(TFrame* s);
N_NOINLINE(void, stackoverflow_20001)(void);
static N_INLINE(void, popFrame)(void);
STRING_LITERAL(TMP686, "sqlite3.dll", 11);
STRING_LITERAL(TMP687, "sqlite3.dll", 11);
static void* TMP685;
TY165547 Dl_165546;
TY165571 Dl_165570;
TY165740 Dl_165739;
TY165815 Dl_165814;
TY165759 Dl_165758;
TY165794 Dl_165793;
TY165706 Dl_165705;
TY165379 Dl_165378;
TY165385 Dl_165384;
TY165362 Dl_165361;
TY165525 Dl_165524;
extern TFrame* frameptr_17042;

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
NIM_EXTERNC N_NOINLINE(void, stdlib_sqlite3Init)(void) {
	nimfr("sqlite3", "sqlite3.nim")
	popFrame();
}

NIM_EXTERNC N_NOINLINE(void, stdlib_sqlite3DatInit)(void) {
if (!((TMP685 = nimLoadLibrary((NimStringDesc*) &TMP686))
)) nimLoadLibraryError((NimStringDesc*) &TMP687);
	Dl_165546 = (TY165547) nimGetProcAddr(TMP685, "sqlite3_errmsg");
	Dl_165570 = (TY165571) nimGetProcAddr(TMP685, "sqlite3_prepare_v2");
	Dl_165739 = (TY165740) nimGetProcAddr(TMP685, "sqlite3_step");
	Dl_165814 = (TY165815) nimGetProcAddr(TMP685, "sqlite3_finalize");
	Dl_165758 = (TY165759) nimGetProcAddr(TMP685, "sqlite3_column_bytes");
	Dl_165793 = (TY165794) nimGetProcAddr(TMP685, "sqlite3_column_text");
	Dl_165705 = (TY165706) nimGetProcAddr(TMP685, "sqlite3_column_count");
	Dl_165378 = (TY165379) nimGetProcAddr(TMP685, "sqlite3_last_insert_rowid");
	Dl_165384 = (TY165385) nimGetProcAddr(TMP685, "sqlite3_changes");
	Dl_165361 = (TY165362) nimGetProcAddr(TMP685, "sqlite3_close");
	Dl_165524 = (TY165525) nimGetProcAddr(TMP685, "sqlite3_open");
}

