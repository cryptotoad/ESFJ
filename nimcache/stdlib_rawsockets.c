/* Generated by Nim Compiler v0.11.2 */
/*   (c) 2015 Andreas Rumpf */
/* The generated code is subject to the original license. */
/* Compiled for: Windows, amd64, gcc */
/* Command for C compiler:
   C:\Nim\dist\mingw\bin\gcc.exe -c  -w  -IC:\Nim\lib -o c:\users\owner\documents\nim\esfj\nimcache\stdlib_rawsockets.o c:\users\owner\documents\nim\esfj\nimcache\stdlib_rawsockets.c */
#define NIM_INTBITS 64
#include "nimbase.h"

#include "winsock2.h"

#include <string.h>
typedef struct TGenericSeq TGenericSeq;
typedef struct NimStringDesc NimStringDesc;
typedef struct Addrinfo106868 Addrinfo106868;
typedef struct Servent222610 Servent222610;
typedef struct Servent106860 Servent106860;
typedef struct Oserror3433 Oserror3433;
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
typedef struct TY13606 TY13606;
typedef struct Hostent222612 Hostent222612;
typedef struct Hostent106862 Hostent106862;
typedef struct Timeval106866 Timeval106866;
typedef struct Tfdset106864 Tfdset106864;
typedef struct TY225637 TY225637;
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
typedef N_STDCALL_PTR(int, TY222661) (NI s, long cmd, long* argptr);
typedef N_STDCALL_PTR(NI, TY107024) (int af, int typ, int protocol);
typedef N_STDCALL_PTR(int, TY107032) (NI s);
typedef N_STDCALL_PTR(int, TY107048) (NI s, SOCKADDR* name, unsigned int namelen);
typedef N_STDCALL_PTR(int, TY107097) (NI s, int backlog);
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
typedef N_STDCALL_PTR(int, TY107244) (NCSTRING nodename, NCSTRING servname, Addrinfo106868* hints, Addrinfo106868** res);
typedef N_STDCALL_PTR(void, TY107256) (Addrinfo106868* ai);
typedef N_STDCALL_PTR(Servent106860*, TY106991) (NCSTRING name, NCSTRING proto);
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
struct  Oserror3433  {
  Systemerror3429 Sup;
NI32 errorcode;
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
struct  Servent222610  {
NimStringDesc* name;
TY13606* aliases;
NU16 port;
NimStringDesc* proto;
};
struct  Servent106860  {
NCSTRING sname;
NCSTRING* saliases;
NCSTRING sproto;
NI16 sport;
};
typedef N_STDCALL_PTR(Servent106860*, TY106999) (int port, NCSTRING proto);
typedef N_STDCALL_PTR(NI32, TY107179) (NCSTRING cp);
typedef N_STDCALL_PTR(Hostent106862*, TY107007) (IN_ADDR* ip, unsigned int len, int thetype);
struct  Hostent222612  {
NimStringDesc* name;
TY13606* aliases;
NU8 addrtype;
NI length;
TY13606* addrlist;
};
struct  Hostent106862  {
NCSTRING hname;
NCSTRING* haliases;
NI16 haddrtype;
NI16 hlength;
NCSTRING* haddrlist;
};
typedef N_STDCALL_PTR(Hostent106862*, TY107017) (NCSTRING name);
typedef NIM_CHAR TY106890[8];
typedef N_STDCALL_PTR(int, TY107066) (NI s, SOCKADDR* name, unsigned int* namelen);
typedef N_STDCALL_PTR(int, TY107076) (NI s, int level, int optname, void* optval, unsigned int* optlen);
typedef N_STDCALL_PTR(int, TY107087) (NI s, int level, int optname, void* optval, unsigned int optlen);
struct  Timeval106866  {
NI32 tvsec;
NI32 tvusec;
};
typedef NI TY106915[64];
struct  Tfdset106864  {
int fdcount;
TY106915 fdarray;
};
typedef N_STDCALL_PTR(int, TY107126) (int nfds, Tfdset106864* readfds, Tfdset106864* writefds, Tfdset106864* exceptfds, Timeval106866* timeout);
typedef NIM_CHAR TY106873[257];
typedef NIM_CHAR TY106876[129];
typedef N_STDCALL_PTR(int, TY107236) (NI16 wversionrequired, WSADATA* Wsdata);
typedef NIM_CHAR TY106883[14];
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
struct TY13606 {
  TGenericSeq Sup;
  NimStringDesc* data[SEQ_DECL_SIZE];
};
struct TY225637 {
  TGenericSeq Sup;
  NI data[SEQ_DECL_SIZE];
};
N_NIMCALL(void*, nimLoadLibrary)(NimStringDesc* path);
N_NOINLINE(void, nimLoadLibraryError)(NimStringDesc* path);
N_NIMCALL(void*, nimGetProcAddr)(void* lib, NCSTRING name);
N_NIMCALL(int, toint_222829)(NU8 domain);
static N_INLINE(void, nimFrame)(TFrame* s);
N_NOINLINE(void, stackoverflow_20001)(void);
static N_INLINE(void, popFrame)(void);
N_NIMCALL(int, toint_222835)(NU8 typ);
N_NIMCALL(int, toint_222841)(NU8 p);
N_NIMCALL(NI, newrawsocket_223004)(NU8 domain, NU8 typ, NU8 protocol);
N_NIMCALL(NI, newrawsocket_223016)(int domain, int typ, int protocol);
N_NIMCALL(void, close_223028)(NI socket);
N_NIMCALL(int, bindaddr_223207)(NI socket, SOCKADDR* name, unsigned int namelen);
N_NIMCALL(int, listen_223220)(NI socket, int backlog);
N_NIMCALL(Addrinfo106868*, getaddrinfo_223408)(NimStringDesc* address, NU16 port, NU8 af, NU8 typ, NU8 prot);
N_NIMCALL(NimStringDesc*, HEX24_6401)(NU64 x);
N_NIMCALL(void, raiseoserror_115430)(NI32 errorcode);
N_NIMCALL(NI32, oslasterror_115454)(void);
N_NIMCALL(void, dealloc_223608)(Addrinfo106868* ai);
N_NIMCALL(NI32, ntohl_223618)(NI32 x);
N_NIMCALL(NI16, ntohs_223807)(NI16 x);
N_NIMCALL(NI32, htonl_224007)(NI32 x);
N_NIMCALL(NI16, htons_224017)(NI16 x);
N_NIMCALL(void, getservbyname_224027)(NimStringDesc* name, NimStringDesc* proto, Servent222610* Result);
N_NIMCALL(void*, newObj)(TNimType* typ, NI size);
N_NIMCALL(NimStringDesc*, copyStringRC1)(NimStringDesc* src);
static N_INLINE(void, nimGCunrefNoCycle)(void* p);
static N_INLINE(Tcell46746*, usrtocell_50246)(void* usr);
static N_INLINE(void, rtladdzct_51804)(Tcell46746* c);
N_NOINLINE(void, addzct_50217)(Tcellseq46762* s, Tcell46746* c);
N_NIMCALL(void, raiseException)(Exception* e, NCSTRING ename);
N_NIMCALL(NimStringDesc*, cstrToNimstr)(NCSTRING str);
N_NIMCALL(void, unsureAsgnRef)(void** dest, void* src);
N_NIMCALL(TY13606*, cstringarraytoseq_13843)(NCSTRING* a);
N_NIMCALL(void, getservbyport_224233)(NU16 port, NimStringDesc* proto, Servent222610* Result);
static N_INLINE(NI, chckRange)(NI i, NI a, NI b);
N_NOINLINE(void, raiseRangeError)(NI64 val);
N_NIMCALL(void, gethostbyaddr_224433)(NimStringDesc* ip, Hostent222612* Result);
N_NIMCALL(void, gethostbyname_224810)(NimStringDesc* name, Hostent222612* Result);
N_NIMCALL(NU16, getsockname_225208)(NI socket);
N_NIMCALL(NI, getsockoptint_225421)(NI socket, NI level, NI optname);
N_NIMCALL(void, setsockoptint_225439)(NI socket, NI level, NI optname, NI optval);
N_NIMCALL(void, setblocking_225453)(NI s, NIM_BOOL blocking);
N_NIMCALL(Timeval106866, timevalfrommilliseconds_225618)(NI timeout);
static N_INLINE(NI, divInt)(NI a, NI b);
N_NOINLINE(void, raiseDivByZero)(void);
N_NOINLINE(void, raiseOverflow)(void);
N_NIMCALL(NI, mulInt)(NI a, NI b);
static N_INLINE(NI, subInt)(NI a, NI b);
N_NIMCALL(void, createfdset_225633)(Tfdset106864* fd, TY225637* s, NI* m);
N_NIMCALL(void, Fdzero_107225)(Tfdset106864* s);
N_NOINLINE(void, raiseIndexError)(void);
N_NIMCALL(void, Fdset_107204)(NI socket, Tfdset106864* s);
static N_INLINE(NI, addInt)(NI a, NI b);
N_NIMCALL(void, failedassertimpl_88817)(NimStringDesc* msg);
N_NIMCALL(void, prunesocketset_225838)(TY225637** s, Tfdset106864* fd);
N_NIMCALL(int, Fdisset_107192)(NI socket, Tfdset106864* set);
N_NIMCALL(TGenericSeq*, setLengthSeq)(TGenericSeq* seq, NI elemsize, NI newlen);
N_NIMCALL(NI, select_225896)(TY225637** readfds, NI timeout);
N_NIMCALL(NI, selectwrite_225923)(TY225637** writefds, NI timeout);
N_NIMCALL(void, TMP2454)(void* p, NI op);
STRING_LITERAL(TMP1273, "ws2_32.dll", 10);
STRING_LITERAL(TMP1274, "ws2_32.dll", 10);
STRING_LITERAL(TMP1275, "Service not found.", 18);
STRING_LITERAL(TMP1282, "len(a) == L seq modified while iterating over it", 48);
NI osinvalidsocket_222650;
static void* TMP1272;
TY222661 Dl_222660;
extern TFrame* frameptr_17042;
extern TY107024 Dl_107023;
extern TY107032 Dl_107031;
extern TY107048 Dl_107047;
extern TY107097 Dl_107096;
extern TY107244 Dl_107243;
extern TY107256 Dl_107255;
extern TY106991 Dl_106990;
extern TNimType NTI115433; /* ref OSError */
extern TNimType NTI3433; /* OSError */
extern Tgcheap48616 gch_48644;
extern TY106999 Dl_106998;
extern TY107179 Dl_107178;
extern TY107007 Dl_107006;
extern TY107017 Dl_107016;
extern TY107066 Dl_107065;
extern TY107076 Dl_107075;
extern TY107087 Dl_107086;
extern TY107126 Dl_107125;
WSADATA wsa_225950;
extern TY107236 Dl_107235;
TNimType NTI222604; /* Domain */
extern TNimType NTI108; /* int */
TNimType NTI225637; /* seq[SocketHandle] */

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

N_NIMCALL(int, toint_222829)(NU8 domain) {
	int result;
	nimfr("toInt", "rawsockets.nim")
	result = 0;
	nimln(145, "rawsockets.nim");
	result = ((int) (((NI16)(NU16)(NU)(((NI) (domain))))));
	popFrame();
	return result;
}

N_NIMCALL(int, toint_222835)(NU8 typ) {
	int result;
	nimfr("toInt", "rawsockets.nim")
	result = 0;
	nimln(148, "rawsockets.nim");
	result = ((int) (typ));
	popFrame();
	return result;
}

N_NIMCALL(int, toint_222841)(NU8 p) {
	int result;
	nimfr("toInt", "rawsockets.nim")
	result = 0;
	nimln(151, "rawsockets.nim");
	result = ((int) (p));
	popFrame();
	return result;
}

N_NIMCALL(NI, newrawsocket_223004)(NU8 domain, NU8 typ, NU8 protocol) {
	NI result;
	int LOC1;
	int LOC2;
	int LOC3;
	nimfr("newRawSocket", "rawsockets.nim")
	result = 0;
	nimln(156, "rawsockets.nim");
	nimln(157, "rawsockets.nim");
	LOC1 = 0;
	LOC1 = toint_222829(domain);
	LOC2 = 0;
	LOC2 = toint_222835(typ);
	LOC3 = 0;
	LOC3 = toint_222841(protocol);
	result = Dl_107023(LOC1, LOC2, LOC3);
	popFrame();
	return result;
}

N_NIMCALL(NI, newrawsocket_223016)(int domain, int typ, int protocol) {
	NI result;
	nimfr("newRawSocket", "rawsockets.nim")
	result = 0;
	nimln(160, "rawsockets.nim");
	nimln(164, "rawsockets.nim");
	result = Dl_107023(domain, typ, protocol);
	popFrame();
	return result;
}

N_NIMCALL(void, close_223028)(NI socket) {
	int LOC1;
	nimfr("close", "rawsockets.nim")
	nimln(169, "rawsockets.nim");
	LOC1 = 0;
	LOC1 = Dl_107031(socket);
	popFrame();
}

N_NIMCALL(int, bindaddr_223207)(NI socket, SOCKADDR* name, unsigned int namelen) {
	int result;
	nimfr("bindAddr", "rawsockets.nim")
	result = 0;
	nimln(176, "rawsockets.nim");
	result = Dl_107047(socket, name, namelen);
	popFrame();
	return result;
}

N_NIMCALL(int, listen_223220)(NI socket, int backlog) {
	int result;
	nimfr("listen", "rawsockets.nim")
	result = 0;
	nimln(183, "rawsockets.nim");
	result = Dl_107096(socket, backlog);
	popFrame();
	return result;
}

N_NIMCALL(Addrinfo106868*, getaddrinfo_223408)(NimStringDesc* address, NU16 port, NU8 af, NU8 typ, NU8 prot) {
	Addrinfo106868* result;
	Addrinfo106868 hints;
	int gairesult;
	NimStringDesc* LOC1;
	nimfr("getAddrInfo", "rawsockets.nim")
	result = 0;
	memset((void*)(&hints), 0, sizeof(hints));
	nimln(193, "rawsockets.nim");
	result = NIM_NIL;
	nimln(194, "rawsockets.nim");
	hints.aifamily = toint_222829(af);
	nimln(195, "rawsockets.nim");
	hints.aisocktype = toint_222835(typ);
	nimln(196, "rawsockets.nim");
	hints.aiprotocol = toint_222841(prot);
	nimln(197, "rawsockets.nim");
	LOC1 = 0;
	LOC1 = HEX24_6401(port);
	gairesult = Dl_107243(address->data, LOC1->data, (&hints), &result);
	nimln(198, "rawsockets.nim");
	{
		NI32 LOC6;
		if (!!((gairesult == ((NI32) 0)))) goto LA4;
		nimln(200, "rawsockets.nim");
		LOC6 = 0;
		LOC6 = oslasterror_115454();
		raiseoserror_115430(LOC6);
	}
	LA4: ;
	popFrame();
	return result;
}

N_NIMCALL(void, dealloc_223608)(Addrinfo106868* ai) {
	nimfr("dealloc", "rawsockets.nim")
	nimln(205, "rawsockets.nim");
	Dl_107255(ai);
	popFrame();
}

N_NIMCALL(NI32, ntohl_223618)(NI32 x) {
	NI32 result;
	nimfr("ntohl", "rawsockets.nim")
	result = 0;
	nimln(212, "rawsockets.nim");
	nimln(214, "rawsockets.nim");
	nimln(213, "rawsockets.nim");
	nimln(212, "rawsockets.nim");
	nimln(213, "rawsockets.nim");
	nimln(214, "rawsockets.nim");
	nimln(215, "rawsockets.nim");
	result = (NI32)((NI32)((NI32)((NI32)((NU32)(x) >> (NU32)(((NI32) 24))) | (NI32)((NI32)((NU32)(x) >> (NU32)(((NI32) 8))) & ((NI32) 65280))) | (NI32)((NI32)((NU32)(x) << (NU32)(((NI32) 8))) & ((NI32) 16711680))) | (NI32)((NU32)(x) << (NU32)(((NI32) 24))));
	popFrame();
	return result;
}

N_NIMCALL(NI16, ntohs_223807)(NI16 x) {
	NI16 result;
	nimfr("ntohs", "rawsockets.nim")
	result = 0;
	nimln(222, "rawsockets.nim");
	result = (NI16)((NI16)((NU16)(x) >> (NU16)(((NI16) 8))) | (NI16)((NU16)(x) << (NU16)(((NI16) 8))));
	popFrame();
	return result;
}

N_NIMCALL(NI32, htonl_224007)(NI32 x) {
	NI32 result;
	nimfr("htonl", "rawsockets.nim")
	result = 0;
	nimln(228, "rawsockets.nim");
	result = ntohl_223618(x);
	popFrame();
	return result;
}

N_NIMCALL(NI16, htons_224017)(NI16 x) {
	NI16 result;
	nimfr("htons", "rawsockets.nim")
	result = 0;
	nimln(234, "rawsockets.nim");
	result = ntohs_223807(x);
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

N_NIMCALL(void, getservbyname_224027)(NimStringDesc* name, NimStringDesc* proto, Servent222610* Result) {
	Servent106860* s;
	nimfr("getServByName", "rawsockets.nim")
	nimln(243, "rawsockets.nim");
	s = Dl_106990(name->data, proto->data);
	nimln(246, "rawsockets.nim");
	{
		Oserror3433* e_224216;
		NimStringDesc* LOC5;
		if (!(s == NIM_NIL)) goto LA3;
		e_224216 = 0;
		nimln(2265, "system.nim");
		e_224216 = (Oserror3433*) newObj((&NTI115433), sizeof(Oserror3433));
		(*e_224216).Sup.Sup.Sup.m_type = (&NTI3433);
		nimln(2266, "system.nim");
		LOC5 = 0;
		LOC5 = (*e_224216).Sup.Sup.message; (*e_224216).Sup.Sup.message = copyStringRC1(((NimStringDesc*) &TMP1275));
		if (LOC5) nimGCunrefNoCycle(LOC5);
		nimln(246, "rawsockets.nim");
		raiseException((Exception*)e_224216, "OSError");
	}
	LA3: ;
	nimln(247, "rawsockets.nim");
	unsureAsgnRef((void**) (&(*Result).name), cstrToNimstr((*s).sname));
	nimln(248, "rawsockets.nim");
	unsureAsgnRef((void**) (&(*Result).aliases), cstringarraytoseq_13843((*s).saliases));
	nimln(249, "rawsockets.nim");
	(*Result).port = ((NU16) ((*s).sport));
	nimln(250, "rawsockets.nim");
	unsureAsgnRef((void**) (&(*Result).proto), cstrToNimstr((*s).sproto));
	popFrame();
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

N_NIMCALL(void, getservbyport_224233)(NU16 port, NimStringDesc* proto, Servent222610* Result) {
	Servent106860* s;
	nimfr("getServByPort", "rawsockets.nim")
	nimln(259, "rawsockets.nim");
	s = Dl_106998(((int)chckRange(((NI)(NU)(NU16)(((NI16)chckRange(port, ((NI16) -32768), ((NI16) 32767))))), ((int) (-2147483647 -1)), ((int) 2147483647))), proto->data);
	nimln(262, "rawsockets.nim");
	{
		Oserror3433* e_224416;
		NimStringDesc* LOC5;
		if (!(s == NIM_NIL)) goto LA3;
		e_224416 = 0;
		nimln(2265, "system.nim");
		e_224416 = (Oserror3433*) newObj((&NTI115433), sizeof(Oserror3433));
		(*e_224416).Sup.Sup.Sup.m_type = (&NTI3433);
		nimln(2266, "system.nim");
		LOC5 = 0;
		LOC5 = (*e_224416).Sup.Sup.message; (*e_224416).Sup.Sup.message = copyStringRC1(((NimStringDesc*) &TMP1275));
		if (LOC5) nimGCunrefNoCycle(LOC5);
		nimln(262, "rawsockets.nim");
		raiseException((Exception*)e_224416, "OSError");
	}
	LA3: ;
	nimln(263, "rawsockets.nim");
	unsureAsgnRef((void**) (&(*Result).name), cstrToNimstr((*s).sname));
	nimln(264, "rawsockets.nim");
	unsureAsgnRef((void**) (&(*Result).aliases), cstringarraytoseq_13843((*s).saliases));
	nimln(265, "rawsockets.nim");
	(*Result).port = ((NU16) ((*s).sport));
	nimln(266, "rawsockets.nim");
	unsureAsgnRef((void**) (&(*Result).proto), cstrToNimstr((*s).sproto));
	popFrame();
}

N_NIMCALL(void, gethostbyaddr_224433)(NimStringDesc* ip, Hostent222612* Result) {
	IN_ADDR myaddr;
	Hostent106862* s;
	nimfr("getHostByAddr", "rawsockets.nim")
	memset((void*)(&myaddr), 0, sizeof(myaddr));
	nimln(271, "rawsockets.nim");
	myaddr.s_addr = Dl_107178(ip->data);
	nimln(274, "rawsockets.nim");
	s = Dl_107006((&myaddr), ((unsigned int) (((NI)sizeof(IN_ADDR)))), ((int) 2));
	nimln(276, "rawsockets.nim");
	{
		NI32 LOC5;
		if (!(s == NIM_NIL)) goto LA3;
		LOC5 = 0;
		LOC5 = oslasterror_115454();
		raiseoserror_115430(LOC5);
	}
	LA3: ;
	nimln(283, "rawsockets.nim");
	unsureAsgnRef((void**) (&(*Result).name), cstrToNimstr((*s).hname));
	nimln(284, "rawsockets.nim");
	unsureAsgnRef((void**) (&(*Result).aliases), cstringarraytoseq_13843((*s).haliases));
	nimln(286, "rawsockets.nim");
	(*Result).addrtype = ((NU8)chckRange((*s).haddrtype, ((NU8) 0), ((NU8) 23)));
	nimln(294, "rawsockets.nim");
	unsureAsgnRef((void**) (&(*Result).addrlist), cstringarraytoseq_13843((*s).haddrlist));
	nimln(295, "rawsockets.nim");
	(*Result).length = ((NI) ((*s).hlength));
	popFrame();
}

N_NIMCALL(void, gethostbyname_224810)(NimStringDesc* name, Hostent222612* Result) {
	Hostent106862* s;
	nimfr("getHostByName", "rawsockets.nim")
	nimln(300, "rawsockets.nim");
	s = Dl_107016(name->data);
	nimln(303, "rawsockets.nim");
	{
		NI32 LOC5;
		if (!(s == NIM_NIL)) goto LA3;
		LOC5 = 0;
		LOC5 = oslasterror_115454();
		raiseoserror_115430(LOC5);
	}
	LA3: ;
	nimln(304, "rawsockets.nim");
	unsureAsgnRef((void**) (&(*Result).name), cstrToNimstr((*s).hname));
	nimln(305, "rawsockets.nim");
	unsureAsgnRef((void**) (&(*Result).aliases), cstringarraytoseq_13843((*s).haliases));
	nimln(307, "rawsockets.nim");
	(*Result).addrtype = ((NU8)chckRange((*s).haddrtype, ((NU8) 0), ((NU8) 23)));
	nimln(315, "rawsockets.nim");
	unsureAsgnRef((void**) (&(*Result).addrlist), cstringarraytoseq_13843((*s).haddrlist));
	nimln(316, "rawsockets.nim");
	(*Result).length = ((NI) ((*s).hlength));
	popFrame();
}

N_NIMCALL(NU16, getsockname_225208)(NI socket) {
	NU16 result;
	SOCKADDR_IN name;
	unsigned int namelen;
	NI16 LOC7;
	nimfr("getSockName", "rawsockets.nim")
	result = 0;
	memset((void*)(&name), 0, sizeof(name));
	nimln(322, "rawsockets.nim");
	name.sin_family = ((NI16) 2);
	nimln(327, "rawsockets.nim");
	namelen = ((unsigned int) (((NI)sizeof(SOCKADDR_IN))));
	nimln(328, "rawsockets.nim");
	{
		int LOC3;
		NI32 LOC6;
		nimln(329, "rawsockets.nim");
		nimln(328, "rawsockets.nim");
		LOC3 = 0;
		LOC3 = Dl_107065(socket, ((SOCKADDR*) ((&name))), (&namelen));
		if (!(LOC3 == ((NI32) -1))) goto LA4;
		nimln(330, "rawsockets.nim");
		LOC6 = 0;
		LOC6 = oslasterror_115454();
		raiseoserror_115430(LOC6);
	}
	LA4: ;
	nimln(331, "rawsockets.nim");
	LOC7 = 0;
	LOC7 = ntohs_223807(name.sin_port);
	result = ((NU16) (LOC7));
	popFrame();
	return result;
}

N_NIMCALL(NI, getsockoptint_225421)(NI socket, NI level, NI optname) {
	NI result;
	int res;
	unsigned int size;
	nimfr("getSockOptInt", "rawsockets.nim")
	result = 0;
	res = 0;
	nimln(337, "rawsockets.nim");
	size = ((unsigned int) 4);
	nimln(338, "rawsockets.nim");
	{
		int LOC3;
		NI32 LOC6;
		nimln(339, "rawsockets.nim");
		nimln(338, "rawsockets.nim");
		LOC3 = 0;
		LOC3 = Dl_107075(socket, ((int)chckRange(level, ((int) (-2147483647 -1)), ((int) 2147483647))), ((int)chckRange(optname, ((int) (-2147483647 -1)), ((int) 2147483647))), ((void*) ((&res))), (&size));
		if (!(LOC3 < ((NI32) 0))) goto LA4;
		nimln(340, "rawsockets.nim");
		LOC6 = 0;
		LOC6 = oslasterror_115454();
		raiseoserror_115430(LOC6);
	}
	LA4: ;
	nimln(341, "rawsockets.nim");
	result = ((NI) (res));
	popFrame();
	return result;
}

N_NIMCALL(void, setsockoptint_225439)(NI socket, NI level, NI optname, NI optval) {
	int value;
	nimfr("setSockOptInt", "rawsockets.nim")
	nimln(346, "rawsockets.nim");
	value = ((int)chckRange(optval, ((int) (-2147483647 -1)), ((int) 2147483647)));
	nimln(347, "rawsockets.nim");
	{
		int LOC3;
		NI32 LOC6;
		nimln(348, "rawsockets.nim");
		nimln(347, "rawsockets.nim");
		LOC3 = 0;
		LOC3 = Dl_107086(socket, ((int)chckRange(level, ((int) (-2147483647 -1)), ((int) 2147483647))), ((int)chckRange(optname, ((int) (-2147483647 -1)), ((int) 2147483647))), ((void*) ((&value))), ((unsigned int) 4));
		if (!(LOC3 < ((NI32) 0))) goto LA4;
		nimln(349, "rawsockets.nim");
		LOC6 = 0;
		LOC6 = oslasterror_115454();
		raiseoserror_115430(LOC6);
	}
	LA4: ;
	popFrame();
}

N_NIMCALL(void, setblocking_225453)(NI s, NIM_BOOL blocking) {
	long mode;
	nimfr("setBlocking", "rawsockets.nim")
	nimln(356, "rawsockets.nim");
	mode = ((long) (!(blocking)));
	nimln(357, "rawsockets.nim");
	{
		int LOC3;
		NI32 LOC6;
		LOC3 = 0;
		LOC3 = Dl_222660(s, ((NI32) -2147195266), (&mode));
		if (!(LOC3 == ((NI32) -1))) goto LA4;
		nimln(358, "rawsockets.nim");
		LOC6 = 0;
		LOC6 = oslasterror_115454();
		raiseoserror_115430(LOC6);
	}
	LA4: ;
	popFrame();
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

N_NIMCALL(Timeval106866, timevalfrommilliseconds_225618)(NI timeout) {
	Timeval106866 result;
	nimfr("timeValFromMilliseconds", "rawsockets.nim")
	memset((void*)(&result), 0, sizeof(result));
	nimln(369, "rawsockets.nim");
	{
		NI seconds;
		NI TMP1276;
		NI TMP1277;
		NI TMP1278;
		NI TMP1279;
		if (!!((timeout == ((NI) -1)))) goto LA3;
		nimln(370, "rawsockets.nim");
		TMP1276 = divInt(timeout, ((NI) 1000));
		seconds = (NI)(TMP1276);
		nimln(371, "rawsockets.nim");
		result.tvsec = ((NI32)chckRange(seconds, ((NI32) (-2147483647 -1)), ((NI32) 2147483647)));
		nimln(372, "rawsockets.nim");
		TMP1277 = mulInt(seconds, ((NI) 1000));
		TMP1278 = subInt(timeout, (NI)(TMP1277));
		TMP1279 = mulInt((NI)(TMP1278), ((NI) 1000));
		result.tvusec = ((NI32)chckRange((NI)(TMP1279), ((NI32) (-2147483647 -1)), ((NI32) 2147483647)));
	}
	LA3: ;
	popFrame();
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

N_NIMCALL(void, createfdset_225633)(Tfdset106864* fd, TY225637* s, NI* m) {
	nimfr("createFdSet", "rawsockets.nim")
	nimln(375, "rawsockets.nim");
	Fdzero_107225(fd);
	{
		NI i_225811;
		NI i_225820;
		NI L_225822;
		i_225811 = 0;
		nimln(3084, "system.nim");
		i_225820 = ((NI) 0);
		nimln(3085, "system.nim");
		L_225822 = (s ? s->Sup.len : 0);
		{
			nimln(3086, "system.nim");
			while (1) {
				NI TMP1281;
				if (!(i_225820 < L_225822)) goto LA3;
				nimln(3087, "system.nim");
				if ((NU)(i_225820) >= (NU)(s->Sup.len)) raiseIndexError();
				i_225811 = s->data[i_225820];
				nimln(377, "rawsockets.nim");
				(*m) = (((*m) >= i_225811) ? (*m) : i_225811);
				nimln(378, "rawsockets.nim");
				Fdset_107204(i_225811, fd);
				nimln(3088, "system.nim");
				TMP1281 = addInt(i_225820, ((NI) 1));
				i_225820 = (NI)(TMP1281);
				nimln(3089, "system.nim");
				{
					if (!!(((s ? s->Sup.len : 0) == L_225822))) goto LA6;
					failedassertimpl_88817(((NimStringDesc*) &TMP1282));
				}
				LA6: ;
			} LA3: ;
		}
	}
	popFrame();
}

N_NIMCALL(void, prunesocketset_225838)(TY225637** s, Tfdset106864* fd) {
	NI i;
	NI L;
	nimfr("pruneSocketSet", "rawsockets.nim")
	nimln(381, "rawsockets.nim");
	i = ((NI) 0);
	nimln(382, "rawsockets.nim");
	L = ((*s) ? (*s)->Sup.len : 0);
	{
		nimln(383, "rawsockets.nim");
		while (1) {
			if (!(i < L)) goto LA2;
			nimln(384, "rawsockets.nim");
			{
				int LOC5;
				NI TMP1283;
				NI TMP1284;
				if ((NU)(i) >= (NU)((*s)->Sup.len)) raiseIndexError();
				LOC5 = 0;
				LOC5 = Fdisset_107192((*s)->data[i], fd);
				if (!(LOC5 == ((NI32) 0))) goto LA6;
				nimln(385, "rawsockets.nim");
				if ((NU)(i) >= (NU)((*s)->Sup.len)) raiseIndexError();
				TMP1283 = subInt(L, ((NI) 1));
				if ((NU)((NI)(TMP1283)) >= (NU)((*s)->Sup.len)) raiseIndexError();
				(*s)->data[i] = (*s)->data[(NI)(TMP1283)];
				nimln(386, "rawsockets.nim");
				TMP1284 = subInt(L, ((NI) 1));
				L = (NI)(TMP1284);
			}
			goto LA3;
			LA6: ;
			{
				NI TMP1285;
				nimln(388, "rawsockets.nim");
				TMP1285 = addInt(i, ((NI) 1));
				i = (NI)(TMP1285);
			}
			LA3: ;
		} LA2: ;
	}
	nimln(389, "rawsockets.nim");
	(*s) = (TY225637*) setLengthSeq(&((*s))->Sup, sizeof(NI), ((NI)chckRange(L, ((NI) 0), ((NI) IL64(9223372036854775807)))));
	popFrame();
}

N_NIMCALL(NI, select_225896)(TY225637** readfds, NI timeout) {
	NI result;
	Timeval106866 tv;
	Tfdset106864 rd;
	NI m;
	nimfr("select", "rawsockets.nim")
	result = 0;
	nimln(399, "rawsockets.nim");
	tv = timevalfrommilliseconds_225618(timeout);
	memset((void*)(&rd), 0, sizeof(rd));
	nimln(402, "rawsockets.nim");
	m = ((NI) 0);
	nimln(403, "rawsockets.nim");
	createfdset_225633((&rd), (*readfds), (&m));
	nimln(405, "rawsockets.nim");
	{
		NI TMP1286;
		int LOC5;
		if (!!((timeout == ((NI) -1)))) goto LA3;
		nimln(406, "rawsockets.nim");
		TMP1286 = addInt(m, ((NI) 1));
		LOC5 = 0;
		LOC5 = Dl_107125(((int)chckRange((NI)(TMP1286), ((int) (-2147483647 -1)), ((int) 2147483647))), (&rd), NIM_NIL, NIM_NIL, (&tv));
		result = ((NI) (LOC5));
	}
	goto LA1;
	LA3: ;
	{
		NI TMP1287;
		int LOC7;
		nimln(408, "rawsockets.nim");
		TMP1287 = addInt(m, ((NI) 1));
		LOC7 = 0;
		LOC7 = Dl_107125(((int)chckRange((NI)(TMP1287), ((int) (-2147483647 -1)), ((int) 2147483647))), (&rd), NIM_NIL, NIM_NIL, NIM_NIL);
		result = ((NI) (LOC7));
	}
	LA1: ;
	nimln(410, "rawsockets.nim");
	prunesocketset_225838(readfds, (&rd));
	popFrame();
	return result;
}

N_NIMCALL(NI, selectwrite_225923)(TY225637** writefds, NI timeout) {
	NI result;
	Timeval106866 tv;
	Tfdset106864 wr;
	NI m;
	nimfr("selectWrite", "rawsockets.nim")
	result = 0;
	nimln(421, "rawsockets.nim");
	tv = timevalfrommilliseconds_225618(timeout);
	memset((void*)(&wr), 0, sizeof(wr));
	nimln(424, "rawsockets.nim");
	m = ((NI) 0);
	nimln(425, "rawsockets.nim");
	createfdset_225633((&wr), (*writefds), (&m));
	nimln(427, "rawsockets.nim");
	{
		NI TMP1288;
		int LOC5;
		if (!!((timeout == ((NI) -1)))) goto LA3;
		nimln(428, "rawsockets.nim");
		TMP1288 = addInt(m, ((NI) 1));
		LOC5 = 0;
		LOC5 = Dl_107125(((int)chckRange((NI)(TMP1288), ((int) (-2147483647 -1)), ((int) 2147483647))), NIM_NIL, (&wr), NIM_NIL, (&tv));
		result = ((NI) (LOC5));
	}
	goto LA1;
	LA3: ;
	{
		NI TMP1289;
		int LOC7;
		nimln(430, "rawsockets.nim");
		TMP1289 = addInt(m, ((NI) 1));
		LOC7 = 0;
		LOC7 = Dl_107125(((int)chckRange((NI)(TMP1289), ((int) (-2147483647 -1)), ((int) 2147483647))), NIM_NIL, (&wr), NIM_NIL, NIM_NIL);
		result = ((NI) (LOC7));
	}
	LA1: ;
	nimln(432, "rawsockets.nim");
	prunesocketset_225838(writefds, (&wr));
	popFrame();
	return result;
}
N_NIMCALL(void, TMP2454)(void* p, NI op) {
	TY225637* a;
	NI LOC1;
	a = (TY225637*)p;
	LOC1 = 0;
	for (LOC1 = 0; LOC1 < a->Sup.len; LOC1++) {
	}
}
NIM_EXTERNC N_NOINLINE(void, stdlib_rawsocketsInit)(void) {
	nimfr("rawsockets", "rawsockets.nim")
	nimln(87, "rawsockets.nim");
	osinvalidsocket_222650 = INVALID_SOCKET;
	nimln(436, "rawsockets.nim");
	{
		int LOC3;
		NI32 LOC6;
		LOC3 = 0;
		LOC3 = Dl_107235(((NI16) 257), (&wsa_225950));
		if (!!((LOC3 == ((NI32) 0)))) goto LA4;
		LOC6 = 0;
		LOC6 = oslasterror_115454();
		raiseoserror_115430(LOC6);
	}
	LA4: ;
	popFrame();
}

NIM_EXTERNC N_NOINLINE(void, stdlib_rawsocketsDatInit)(void) {
static TNimNode* TMP2369[3];
NI TMP2371;
static char* NIM_CONST TMP2370[3] = {
"AF_UNIX", 
"AF_INET", 
"AF_INET6"};
static TNimNode TMP1270[4];
NTI222604.size = sizeof(NU8);
NTI222604.kind = 14;
NTI222604.base = 0;
NTI222604.flags = 3;
for (TMP2371 = 0; TMP2371 < 3; TMP2371++) {
TMP1270[TMP2371+0].kind = 1;
TMP1270[TMP2371+0].offset = TMP2371;
TMP1270[TMP2371+0].name = TMP2370[TMP2371];
TMP2369[TMP2371] = &TMP1270[TMP2371+0];
}
TMP1270[0].offset = 0;
TMP1270[1].offset = 2;
TMP1270[2].offset = 23;
TMP1270[3].len = 3; TMP1270[3].kind = 2; TMP1270[3].sons = &TMP2369[0];
NTI222604.node = &TMP1270[3];
NTI222604.flags = 1<<2;
NTI225637.size = sizeof(TY225637*);
NTI225637.kind = 24;
NTI225637.base = (&NTI108);
NTI225637.flags = 2;
NTI225637.marker = TMP2454;
if (!((TMP1272 = nimLoadLibrary((NimStringDesc*) &TMP1273))
)) nimLoadLibraryError((NimStringDesc*) &TMP1274);
	Dl_222660 = (TY222661) nimGetProcAddr(TMP1272, "ioctlsocket");
}
