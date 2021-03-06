/* Generated by Nim Compiler v0.11.2 */
/*   (c) 2015 Andreas Rumpf */
/* The generated code is subject to the original license. */
/* Compiled for: Windows, amd64, gcc */
/* Command for C compiler:
   C:\Nim\dist\mingw\bin\gcc.exe -c  -w  -IC:\Nim\lib -o c:\users\owner\documents\nim\esfj\nimcache\stdlib_winlean.o c:\users\owner\documents\nim\esfj\nimcache\stdlib_winlean.c */
#define NIM_INTBITS 64
#include "nimbase.h"

#include <string.h>

#include "winsock2.h"
typedef struct Tguid107614 Tguid107614;
typedef struct TGenericSeq TGenericSeq;
typedef struct NimStringDesc NimStringDesc;
typedef struct Tfiletime105245 Tfiletime105245;
typedef struct TNimType TNimType;
typedef struct TNimNode TNimNode;
typedef struct Tsecurityattributes105239 Tsecurityattributes105239;
typedef struct Tstartupinfo105241 Tstartupinfo105241;
typedef struct Tprocessinformation105243 Tprocessinformation105243;
typedef struct Addrinfo106868 Addrinfo106868;
typedef struct Servent106860 Servent106860;
typedef struct Hostent106862 Hostent106862;
typedef struct Tfdset106864 Tfdset106864;
typedef struct Timeval106866 Timeval106866;
typedef struct Toverlapped107608 Toverlapped107608;
typedef NI8 TY107627[8];
struct  Tguid107614  {
NI32 D1;
NI16 D2;
NI16 D3;
TY107627 D4;
};
typedef NI8 TY107712[8];
struct  TGenericSeq  {
NI len;
NI reserved;
};
struct  NimStringDesc  {
  TGenericSeq Sup;
NIM_CHAR data[SEQ_DECL_SIZE];
};
typedef N_STDCALL_PTR(void, TY106625) (Tfiletime105245* lpsystemtimeasfiletime);
struct  Tfiletime105245  {
NI32 dwlowdatetime;
NI32 dwhighdatetime;
};
typedef N_STDCALL_PTR(NI16*, TY106440) (void);
typedef N_STDCALL_PTR(int, TY107236) (NI16 wversionrequired, WSADATA* Wsdata);
typedef N_STDCALL_PTR(NI32, TY105663) (NI32 dwflags, void* lpsource, NI32 dwmessageid, NI32 dwlanguageid, void* lpbuffer, NI32 nsize, void* Arguments);
typedef N_STDCALL_PTR(void, TY105805) (void* p);
typedef N_STDCALL_PTR(NI32, TY105658) (void);
typedef N_STDCALL_PTR(NI16*, TY106435) (void);
typedef N_STDCALL_PTR(NI32, TY106437) (NI16* para1);
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
typedef N_STDCALL_PTR(void, TY106632) (NI32 dwmilliseconds);
typedef N_STDCALL_PTR(NI32, TY105431) (NI hfile, void* Buffer, NI32 nnumberofbytestoread, NI32* lpnumberofbytesread, void* lpoverlapped);
typedef N_STDCALL_PTR(NI32, TY105442) (NI hfile, void* Buffer, NI32 nnumberofbytestowrite, NI32* lpnumberofbyteswritten, void* lpoverlapped);
typedef N_STDCALL_PTR(NI32, TY105453) (NI* hreadpipe, NI* hwritepipe, Tsecurityattributes105239* lppipeattributes, NI32 nsize);
typedef N_STDCALL_PTR(NI32, TY105425) (NI hobject);
typedef N_STDCALL_PTR(NI, TY105639) (NI32 nstdhandle);
typedef N_STDCALL_PTR(NI32, TY105464) (NI16* lpapplicationname, NI16* lpcommandline, Tsecurityattributes105239* lpprocessattributes, Tsecurityattributes105239* lpthreadattributes, NI32 binherithandles, NI32 dwcreationflags, NI16* lpenvironment, NI16* lpcurrentdirectory, Tstartupinfo105241* lpstartupinfo, Tprocessinformation105243* lpprocessinformation);
typedef N_STDCALL_PTR(NI32, TY105605) (NI hthread);
typedef N_STDCALL_PTR(NI32, TY105611) (NI hthread);
typedef N_STDCALL_PTR(NI32, TY105617) (NI hhandle, NI32 dwmilliseconds);
typedef N_STDCALL_PTR(NI32, TY105624) (NI hprocess, NI uexitcode);
typedef N_STDCALL_PTR(NI32, TY105631) (NI hprocess, NI32* lpexitcode);
typedef N_STDCALL_PTR(NI32, TY107281) (NI32 ncount, NI* lphandles, NI32 bwaitall, NI32 dwmilliseconds);
typedef N_STDCALL_PTR(NI, TY107024) (int af, int typ, int protocol);
typedef N_STDCALL_PTR(int, TY107032) (NI s);
typedef N_STDCALL_PTR(int, TY107048) (NI s, SOCKADDR* name, unsigned int namelen);
typedef N_STDCALL_PTR(int, TY107097) (NI s, int backlog);
typedef N_STDCALL_PTR(int, TY107244) (NCSTRING nodename, NCSTRING servname, Addrinfo106868* hints, Addrinfo106868** res);
typedef N_STDCALL_PTR(void, TY107256) (Addrinfo106868* ai);
typedef N_STDCALL_PTR(Servent106860*, TY106991) (NCSTRING name, NCSTRING proto);
typedef N_STDCALL_PTR(Servent106860*, TY106999) (int port, NCSTRING proto);
typedef N_STDCALL_PTR(NI32, TY107179) (NCSTRING cp);
typedef N_STDCALL_PTR(Hostent106862*, TY107007) (IN_ADDR* ip, unsigned int len, int thetype);
typedef N_STDCALL_PTR(Hostent106862*, TY107017) (NCSTRING name);
typedef N_STDCALL_PTR(int, TY107066) (NI s, SOCKADDR* name, unsigned int* namelen);
typedef N_STDCALL_PTR(int, TY107076) (NI s, int level, int optname, void* optval, unsigned int* optlen);
typedef N_STDCALL_PTR(int, TY107087) (NI s, int level, int optname, void* optval, unsigned int optlen);
typedef NI TY106915[64];
struct  Tfdset106864  {
int fdcount;
TY106915 fdarray;
};
typedef N_STDCALL_PTR(NIM_BOOL, TY107185) (NI s, Tfdset106864* set);
typedef N_STDCALL_PTR(int, TY107126) (int nfds, Tfdset106864* readfds, Tfdset106864* writefds, Tfdset106864* exceptfds, Timeval106866* timeout);
typedef N_STDCALL_PTR(NI, TY107652) (NI Filehandle, NI Existingcompletionport, NI32 Completionkey, NI32 Numberofconcurrentthreads);
typedef N_STDCALL_PTR(NI32, TY107661) (NI Completionport, NI32* lpnumberofbytestransferred, NI* lpcompletionkey, Toverlapped107608** lpoverlapped, NI32 dwmilliseconds);
typedef N_STDCALL_PTR(void, Poverlappedcompletionroutine107612) (NI32 para1, NI32 para2, Toverlapped107608* para3);
typedef N_STDCALL_PTR(int, TY107733) (NI s, NI32 dwiocontrolcode, void* lpvinbuffer, NI32 cbinbuffer, void* lpvoutbuffer, NI32 cboutbuffer, NI32* lpcbbytesreturned, Toverlapped107608* lpoverlapped, Poverlappedcompletionroutine107612 lpcompletionroutine);
struct  Toverlapped107608  {
NI* internal;
NI* internalhigh;
NI32 offset;
NI32 offsethigh;
NI hevent;
};
struct  TNimNode  {
NU8 kind;
NI offset;
TNimType* typ;
NCSTRING name;
NI len;
TNimNode** sons;
};
typedef N_STDCALL_PTR(int, TY107754) (NI s, WSABUF* buf, NI32 bufcount, NI32* bytesreceived, NI32* flags, Toverlapped107608* lpoverlapped, Poverlappedcompletionroutine107612 completionproc);
typedef N_STDCALL_PTR(int, TY107767) (NI s, WSABUF* buf, NI32 bufcount, NI32* bytessent, NI32 flags, Toverlapped107608* lpoverlapped, Poverlappedcompletionroutine107612 completionproc);
typedef N_STDCALL_PTR(NCSTRING, TY107263) (IN_ADDR i);
typedef N_STDCALL_PTR(int, TY107104) (NI s, void* buf, int len, int flags);
typedef N_STDCALL_PTR(int, TY107057) (NI s, SOCKADDR* name, unsigned int namelen);
typedef N_STDCALL_PTR(int, TY107138) (NI s, void* buf, int len, int flags);
typedef NIM_CHAR TY106873[257];
typedef NIM_CHAR TY106876[129];
struct  Tsecurityattributes105239  {
NI32 nlength;
void* lpsecuritydescriptor;
NI32 binherithandle;
};
struct  Tstartupinfo105241  {
NI32 cb;
NCSTRING lpreserved;
NCSTRING lpdesktop;
NCSTRING lptitle;
NI32 dwx;
NI32 dwy;
NI32 dwxsize;
NI32 dwysize;
NI32 dwxcountchars;
NI32 dwycountchars;
NI32 dwfillattribute;
NI32 dwflags;
NI16 wshowwindow;
NI16 cbreserved2;
void* lpreserved2;
NI hstdinput;
NI hstdoutput;
NI hstderror;
};
struct  Tprocessinformation105243  {
NI hprocess;
NI hthread;
NI32 dwprocessid;
NI32 dwthreadid;
};
typedef NIM_CHAR TY106883[14];
struct  Addrinfo106868  {
int aiflags;
int aifamily;
int aisocktype;
int aiprotocol;
NI aiaddrlen;
NCSTRING aicanonname;
SOCKADDR* aiaddr;
Addrinfo106868* ainext;
};
struct  Servent106860  {
NCSTRING sname;
NCSTRING* saliases;
NCSTRING sproto;
NI16 sport;
};
struct  Hostent106862  {
NCSTRING hname;
NCSTRING* haliases;
NI16 haddrtype;
NI16 hlength;
NCSTRING* haddrlist;
};
struct  Timeval106866  {
NI32 tvsec;
NI32 tvusec;
};
N_NIMCALL(void*, nimLoadLibrary)(NimStringDesc* path);
N_NOINLINE(void, nimLoadLibraryError)(NimStringDesc* path);
N_NIMCALL(void*, nimGetProcAddr)(void* lib, NCSTRING name);
static N_INLINE(void, nimFrame)(TFrame* s);
N_NOINLINE(void, stackoverflow_20001)(void);
static N_INLINE(void, popFrame)(void);
N_NOINLINE(void, raiseIndexError)(void);
static N_INLINE(NI, addInt)(NI a, NI b);
N_NOINLINE(void, raiseOverflow)(void);
NIM_CONST TY107712 TMP151 = {((NI8) -114),
((NI8) -23),
((NI8) 118),
((NI8) -27),
((NI8) -116),
((NI8) 116),
((NI8) 6),
((NI8) 62)}
;
NIM_CONST TY107712 TMP152 = {((NI8) -107),
((NI8) -54),
((NI8) 0),
((NI8) -128),
((NI8) 95),
((NI8) 72),
((NI8) -95),
((NI8) -110)}
;
STRING_LITERAL(TMP189, "kernel32", 8);
STRING_LITERAL(TMP190, "kernel32", 8);
STRING_LITERAL(TMP529, "Ws2_32.dll", 10);
STRING_LITERAL(TMP530, "Ws2_32.dll", 10);
Tguid107614 Wsaidconnectex_107714;
Tguid107614 Wsaidacceptex_107718;
Tguid107614 Wsaidgetacceptexsockaddrs_107722;
static void* TMP188;
TY106625 Dl_106624;
extern TFrame* frameptr_17042;
TY106440 Dl_106439;
static void* TMP528;
TY107236 Dl_107235;
TY105663 Dl_105662;
TY105805 Dl_105804;
TY105658 Dl_105657;
TY106435 Dl_106434;
TY106437 Dl_106436;
TNimType NTI105219; /* THandle */
TY106632 Dl_106631;
TY105431 Dl_105430;
TY105442 Dl_105441;
TY105453 Dl_105452;
TY105425 Dl_105424;
TY105639 Dl_105638;
TY105464 Dl_105463;
TY105605 Dl_105604;
TY105611 Dl_105610;
TY105617 Dl_105616;
TY105624 Dl_105623;
TY105631 Dl_105630;
TY107281 Dl_107280;
TY107024 Dl_107023;
TY107032 Dl_107031;
TY107048 Dl_107047;
TY107097 Dl_107096;
TY107244 Dl_107243;
TY107256 Dl_107255;
TY106991 Dl_106990;
TY106999 Dl_106998;
TY107179 Dl_107178;
TY107007 Dl_107006;
TY107017 Dl_107016;
TY107066 Dl_107065;
TY107076 Dl_107075;
TY107087 Dl_107086;
TY107185 Dl_107184;
TY107126 Dl_107125;
TY107652 Dl_107651;
TY107661 Dl_107660;
TY107733 Dl_107732;
TNimType NTI107608; /* TOVERLAPPED */
extern TNimType NTI105225; /* PULONG */
TNimType NTI105229; /* DWORD */
TNimType NTI107747; /* TWSABuf */
TNimType NTI105223; /* ULONG */
extern TNimType NTI151; /* cstring */
TY107754 Dl_107753;
TY107767 Dl_107766;
TY107263 Dl_107262;
TY107104 Dl_107103;
TY107057 Dl_107056;
TY107138 Dl_107137;

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

N_NIMCALL(NI64, rdfiletime_106604)(Tfiletime105245 f) {
	NI64 result;
	nimfr("rdFileTime", "winlean.nim")
	result = 0;
	nimln(330, "winlean.nim");
	result = (NI64)(((NI64)(NU64)(NU32)(f.dwlowdatetime)) | (NI64)((NU64)(((NI64)(NU64)(NU32)(f.dwhighdatetime))) << (NU64)(IL64(32))));
	popFrame();
	return result;
}

N_NIMCALL(void, Fdzero_107225)(Tfdset106864* s) {
	nimfr("FD_ZERO", "winlean.nim")
	nimln(555, "winlean.nim");
	(*s).fdcount = ((int) 0);
	popFrame();
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

N_NIMCALL(void, Fdset_107204)(NI socket, Tfdset106864* s) {
	nimfr("FD_SET", "winlean.nim")
	nimln(550, "winlean.nim");
	{
		NI TMP1280;
		if (!((*s).fdcount < ((NI32) 64))) goto LA3;
		nimln(551, "winlean.nim");
		if ((NU)(((NI) ((*s).fdcount))) > (NU)(63)) raiseIndexError();
		(*s).fdarray[(((NI) ((*s).fdcount)))- 0] = socket;
		nimln(552, "winlean.nim");
		TMP1280 = addInt((*s).fdcount, ((NI) 1));
		if (TMP1280 < (-2147483647 -1) || TMP1280 > 2147483647) raiseOverflow();
		(*s).fdcount = (int)(TMP1280);
	}
	LA3: ;
	popFrame();
}

N_NIMCALL(int, Fdisset_107192)(NI socket, Tfdset106864* set) {
	int result;
	nimfr("FD_ISSET", "winlean.nim")
	result = 0;
	nimln(547, "winlean.nim");
	{
		NIM_BOOL LOC3;
		LOC3 = 0;
		LOC3 = Dl_107184(socket, set);
		if (!LOC3) goto LA4;
		result = ((NI32) 1);
	}
	goto LA1;
	LA4: ;
	{
		result = ((NI32) 0);
	}
	LA1: ;
	popFrame();
	return result;
}
NIM_EXTERNC N_NOINLINE(void, stdlib_winleanInit)(void) {
	Tguid107614 LOC1;
	Tguid107614 LOC2;
	Tguid107614 LOC3;
	nimfr("winlean", "winlean.nim")
	nimln(720, "winlean.nim");
	memset((void*)(&LOC1), 0, sizeof(LOC1));
	LOC1.D1 = ((NI32) 631375801);
	LOC1.D2 = ((NI16) -8717);
	LOC1.D3 = ((NI16) 18016);
	memcpy((void*)LOC1.D4, (NIM_CONST void*)TMP151, sizeof(LOC1.D4));
	Wsaidconnectex_107714 = LOC1;
	nimln(722, "winlean.nim");
	memset((void*)(&LOC2), 0, sizeof(LOC2));
	LOC2.D1 = ((NI32) -1254720015);
	LOC2.D2 = ((NI16) -13396);
	LOC2.D3 = ((NI16) 4559);
	memcpy((void*)LOC2.D4, (NIM_CONST void*)TMP152, sizeof(LOC2.D4));
	Wsaidacceptex_107718 = LOC2;
	nimln(724, "winlean.nim");
	memset((void*)(&LOC3), 0, sizeof(LOC3));
	LOC3.D1 = ((NI32) -1254720014);
	LOC3.D2 = ((NI16) -13396);
	LOC3.D3 = ((NI16) 4559);
	memcpy((void*)LOC3.D4, (NIM_CONST void*)TMP152, sizeof(LOC3.D4));
	Wsaidgetacceptexsockaddrs_107722 = LOC3;
	popFrame();
}

NIM_EXTERNC N_NOINLINE(void, stdlib_winleanDatInit)(void) {
static TNimNode* TMP2309[5];
static TNimNode* TMP2314[2];
static TNimNode TMP149[9];
NTI105219.size = sizeof(NI);
NTI105219.kind = 31;
NTI105219.base = 0;
NTI105219.flags = 3;
NTI107608.size = sizeof(Toverlapped107608);
NTI107608.kind = 18;
NTI107608.base = 0;
NTI107608.flags = 1;
TMP2309[0] = &TMP149[1];
TMP149[1].kind = 1;
TMP149[1].offset = offsetof(Toverlapped107608, internal);
TMP149[1].typ = (&NTI105225);
TMP149[1].name = "internal";
TMP2309[1] = &TMP149[2];
TMP149[2].kind = 1;
TMP149[2].offset = offsetof(Toverlapped107608, internalhigh);
TMP149[2].typ = (&NTI105225);
TMP149[2].name = "internalHigh";
TMP2309[2] = &TMP149[3];
NTI105229.size = sizeof(NI32);
NTI105229.kind = 34;
NTI105229.base = 0;
NTI105229.flags = 3;
TMP149[3].kind = 1;
TMP149[3].offset = offsetof(Toverlapped107608, offset);
TMP149[3].typ = (&NTI105229);
TMP149[3].name = "offset";
TMP2309[3] = &TMP149[4];
TMP149[4].kind = 1;
TMP149[4].offset = offsetof(Toverlapped107608, offsethigh);
TMP149[4].typ = (&NTI105229);
TMP149[4].name = "offsetHigh";
TMP2309[4] = &TMP149[5];
TMP149[5].kind = 1;
TMP149[5].offset = offsetof(Toverlapped107608, hevent);
TMP149[5].typ = (&NTI105219);
TMP149[5].name = "hEvent";
TMP149[0].len = 5; TMP149[0].kind = 2; TMP149[0].sons = &TMP2309[0];
NTI107608.node = &TMP149[0];
NTI107747.size = sizeof(WSABUF);
NTI107747.kind = 18;
NTI107747.base = 0;
NTI107747.flags = 3;
TMP2314[0] = &TMP149[7];
NTI105223.size = sizeof(NI);
NTI105223.kind = 31;
NTI105223.base = 0;
NTI105223.flags = 3;
TMP149[7].kind = 1;
TMP149[7].offset = offsetof(WSABUF, len);
TMP149[7].typ = (&NTI105223);
TMP149[7].name = "len";
TMP2314[1] = &TMP149[8];
TMP149[8].kind = 1;
TMP149[8].offset = offsetof(WSABUF, buf);
TMP149[8].typ = (&NTI151);
TMP149[8].name = "buf";
TMP149[6].len = 2; TMP149[6].kind = 2; TMP149[6].sons = &TMP2314[0];
NTI107747.node = &TMP149[6];
if (!((TMP188 = nimLoadLibrary((NimStringDesc*) &TMP189))
)) nimLoadLibraryError((NimStringDesc*) &TMP190);
	Dl_106624 = (TY106625) nimGetProcAddr(TMP188, "GetSystemTimeAsFileTime");
	Dl_106439 = (TY106440) nimGetProcAddr(TMP188, "GetCommandLineW");
if (!((TMP528 = nimLoadLibrary((NimStringDesc*) &TMP529))
)) nimLoadLibraryError((NimStringDesc*) &TMP530);
	Dl_107235 = (TY107236) nimGetProcAddr(TMP528, "WSAStartup");
	Dl_105662 = (TY105663) nimGetProcAddr(TMP188, "FormatMessageW");
	Dl_105804 = (TY105805) nimGetProcAddr(TMP188, "LocalFree");
	Dl_105657 = (TY105658) nimGetProcAddr(TMP188, "GetLastError");
	Dl_106434 = (TY106435) nimGetProcAddr(TMP188, "GetEnvironmentStringsW");
	Dl_106436 = (TY106437) nimGetProcAddr(TMP188, "FreeEnvironmentStringsW");
	Dl_106631 = (TY106632) nimGetProcAddr(TMP188, "Sleep");
	Dl_105430 = (TY105431) nimGetProcAddr(TMP188, "ReadFile");
	Dl_105441 = (TY105442) nimGetProcAddr(TMP188, "WriteFile");
	Dl_105452 = (TY105453) nimGetProcAddr(TMP188, "CreatePipe");
	Dl_105424 = (TY105425) nimGetProcAddr(TMP188, "CloseHandle");
	Dl_105638 = (TY105639) nimGetProcAddr(TMP188, "GetStdHandle");
	Dl_105463 = (TY105464) nimGetProcAddr(TMP188, "CreateProcessW");
	Dl_105604 = (TY105605) nimGetProcAddr(TMP188, "SuspendThread");
	Dl_105610 = (TY105611) nimGetProcAddr(TMP188, "ResumeThread");
	Dl_105616 = (TY105617) nimGetProcAddr(TMP188, "WaitForSingleObject");
	Dl_105623 = (TY105624) nimGetProcAddr(TMP188, "TerminateProcess");
	Dl_105630 = (TY105631) nimGetProcAddr(TMP188, "GetExitCodeProcess");
	Dl_107280 = (TY107281) nimGetProcAddr(TMP188, "WaitForMultipleObjects");
	Dl_107023 = (TY107024) nimGetProcAddr(TMP528, "socket");
	Dl_107031 = (TY107032) nimGetProcAddr(TMP528, "closesocket");
	Dl_107047 = (TY107048) nimGetProcAddr(TMP528, "bind");
	Dl_107096 = (TY107097) nimGetProcAddr(TMP528, "listen");
	Dl_107243 = (TY107244) nimGetProcAddr(TMP528, "getaddrinfo");
	Dl_107255 = (TY107256) nimGetProcAddr(TMP528, "freeaddrinfo");
	Dl_106990 = (TY106991) nimGetProcAddr(TMP528, "getservbyname");
	Dl_106998 = (TY106999) nimGetProcAddr(TMP528, "getservbyport");
	Dl_107178 = (TY107179) nimGetProcAddr(TMP528, "inet_addr");
	Dl_107006 = (TY107007) nimGetProcAddr(TMP528, "gethostbyaddr");
	Dl_107016 = (TY107017) nimGetProcAddr(TMP528, "gethostbyname");
	Dl_107065 = (TY107066) nimGetProcAddr(TMP528, "getsockname");
	Dl_107075 = (TY107076) nimGetProcAddr(TMP528, "getsockopt");
	Dl_107086 = (TY107087) nimGetProcAddr(TMP528, "setsockopt");
	Dl_107184 = (TY107185) nimGetProcAddr(TMP528, "__WSAFDIsSet");
	Dl_107125 = (TY107126) nimGetProcAddr(TMP528, "select");
	Dl_107651 = (TY107652) nimGetProcAddr(TMP188, "CreateIoCompletionPort");
	Dl_107660 = (TY107661) nimGetProcAddr(TMP188, "GetQueuedCompletionStatus");
	Dl_107732 = (TY107733) nimGetProcAddr(TMP528, "WSAIoctl");
	Dl_107753 = (TY107754) nimGetProcAddr(TMP528, "WSARecv");
	Dl_107766 = (TY107767) nimGetProcAddr(TMP528, "WSASend");
	Dl_107262 = (TY107263) nimGetProcAddr(TMP528, "inet_ntoa");
	Dl_107103 = (TY107104) nimGetProcAddr(TMP528, "recv");
	Dl_107056 = (TY107057) nimGetProcAddr(TMP528, "connect");
	Dl_107137 = (TY107138) nimGetProcAddr(TMP528, "send");
}

