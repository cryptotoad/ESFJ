/* Generated by Nim Compiler v0.11.2 */
/*   (c) 2015 Andreas Rumpf */
/* The generated code is subject to the original license. */
/* Compiled for: Windows, amd64, gcc */
/* Command for C compiler:
   C:\Nim\dist\mingw\bin\gcc.exe -c  -w  -IC:\Nim\lib -o c:\users\owner\documents\nim\esfj\nimcache\stdlib_base64.o c:\users\owner\documents\nim\esfj\nimcache\stdlib_base64.c */
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
typedef NU8 TY77659[32];
N_NIMCALL(NimStringDesc*, encode_238174)(NimStringDesc* s, NI linelen, NimStringDesc* newline);
static N_INLINE(NI, addInt)(NI a, NI b);
N_NOINLINE(void, raiseOverflow)(void);
static N_INLINE(NI, divInt)(NI a, NI b);
N_NOINLINE(void, raiseDivByZero)(void);
N_NIMCALL(NI, mulInt)(NI a, NI b);
static N_INLINE(NI, subInt)(NI a, NI b);
N_NIMCALL(NimStringDesc*, mnewString)(NI len);
N_NIMCALL(NimStringDesc*, mnewString)(NI len);
static N_INLINE(NI, chckRange)(NI i, NI a, NI b);
N_NOINLINE(void, raiseRangeError)(NI64 val);
N_NOINLINE(void, raiseIndexError)(void);
N_NIMCALL(void, failedassertimpl_88817)(NimStringDesc* msg);
N_NIMCALL(NimStringDesc*, setLengthStr)(NimStringDesc* s, NI newlen);
static N_INLINE(void, nimFrame)(TFrame* s);
N_NOINLINE(void, stackoverflow_20001)(void);
static N_INLINE(void, popFrame)(void);
static N_INLINE(NI, decodebyte_238335)(NIM_CHAR b);
N_NIMCALL(NimStringDesc*, decode_238390)(NimStringDesc* s);
STRING_LITERAL(TMP1355, "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+"
"/", 64);
STRING_LITERAL(TMP1365, "len(a) == L string modified while iterating over it", 51);
NIM_CONST TY77659 Whitespace_238394 = {
0x00, 0x3E, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00}
;
STRING_LITERAL(TMP1393, "i == len(s) ", 12);
extern TFrame* frameptr_17042;

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

N_NIMCALL(NimStringDesc*, encode_238174)(NimStringDesc* s, NI linelen, NimStringDesc* newline) {
	NimStringDesc* result;
	NI total_238182;
	NI TMP1343;
	NI TMP1344;
	NI TMP1345;
	NI numlines_238184;
	NI TMP1346;
	NI TMP1347;
	NI TMP1348;
	NI i_238186;
	NI r_238188;
	NI currline_238190;
	nimfr("encode", "base64.nim")
	result = 0;
	nimln(18, "base64.nim");
	TMP1343 = addInt((s ? s->Sup.len : 0), ((NI) 2));
	TMP1344 = divInt((NI)(TMP1343), ((NI) 3));
	TMP1345 = mulInt((NI)(TMP1344), ((NI) 4));
	total_238182 = (NI)(TMP1345);
	nimln(19, "base64.nim");
	TMP1346 = addInt(total_238182, linelen);
	TMP1347 = subInt((NI)(TMP1346), ((NI) 1));
	TMP1348 = divInt((NI)(TMP1347), linelen);
	numlines_238184 = (NI)(TMP1348);
	nimln(20, "base64.nim");
	{
		NI TMP1349;
		NI TMP1350;
		NI TMP1351;
		if (!(((NI) 0) < numlines_238184)) goto LA3;
		TMP1349 = subInt(numlines_238184, ((NI) 1));
		TMP1350 = mulInt((NI)(TMP1349), (newline ? newline->Sup.len : 0));
		TMP1351 = addInt(total_238182, (NI)(TMP1350));
		total_238182 = (NI)(TMP1351);
	}
	LA3: ;
	nimln(22, "base64.nim");
	result = mnewString(((NI)chckRange(total_238182, ((NI) 0), ((NI) IL64(9223372036854775807)))));
	nimln(23, "base64.nim");
	i_238186 = ((NI) 0);
	nimln(24, "base64.nim");
	r_238188 = ((NI) 0);
	nimln(25, "base64.nim");
	currline_238190 = ((NI) 0);
	{
		nimln(26, "base64.nim");
		while (1) {
			NI TMP1352;
			NI a_238192;
			NI b_238194;
			NI TMP1353;
			NI c_238196;
			NI TMP1354;
			NI TMP1356;
			NI TMP1357;
			NI TMP1358;
			NI TMP1359;
			NI TMP1360;
			NI TMP1361;
			TMP1352 = subInt((s ? s->Sup.len : 0), ((NI) 2));
			if (!(i_238186 < (NI)(TMP1352))) goto LA6;
			nimln(27, "base64.nim");
			if ((NU)(i_238186) > (NU)(s->Sup.len)) raiseIndexError();
			a_238192 = ((NU8)(s->data[i_238186]));
			nimln(28, "base64.nim");
			TMP1353 = addInt(i_238186, ((NI) 1));
			if ((NU)((NI)(TMP1353)) > (NU)(s->Sup.len)) raiseIndexError();
			b_238194 = ((NU8)(s->data[(NI)(TMP1353)]));
			nimln(29, "base64.nim");
			TMP1354 = addInt(i_238186, ((NI) 2));
			if ((NU)((NI)(TMP1354)) > (NU)(s->Sup.len)) raiseIndexError();
			c_238196 = ((NU8)(s->data[(NI)(TMP1354)]));
			nimln(30, "base64.nim");
			if ((NU)(r_238188) > (NU)(result->Sup.len)) raiseIndexError();
			if ((NU)((NI)((NU64)(((NI) (a_238192))) >> (NU64)(((NI) 2)))) > (NU)(((NimStringDesc*) &TMP1355)->Sup.len)) raiseIndexError();
			result->data[r_238188] = ((NimStringDesc*) &TMP1355)->data[(NI)((NU64)(((NI) (a_238192))) >> (NU64)(((NI) 2)))];
			nimln(31, "base64.nim");
			TMP1356 = addInt(r_238188, ((NI) 1));
			if ((NU)((NI)(TMP1356)) > (NU)(result->Sup.len)) raiseIndexError();
			if ((NU)((NI)((NI)((NU64)(((NI) ((NI)(((NI) (a_238192)) & ((NI) 3))))) << (NU64)(((NI) 4))) | (NI)((NU64)((NI)(((NI) (b_238194)) & ((NI) 240))) >> (NU64)(((NI) 4))))) > (NU)(((NimStringDesc*) &TMP1355)->Sup.len)) raiseIndexError();
			result->data[(NI)(TMP1356)] = ((NimStringDesc*) &TMP1355)->data[(NI)((NI)((NU64)(((NI) ((NI)(((NI) (a_238192)) & ((NI) 3))))) << (NU64)(((NI) 4))) | (NI)((NU64)((NI)(((NI) (b_238194)) & ((NI) 240))) >> (NU64)(((NI) 4))))];
			nimln(32, "base64.nim");
			TMP1357 = addInt(r_238188, ((NI) 2));
			if ((NU)((NI)(TMP1357)) > (NU)(result->Sup.len)) raiseIndexError();
			if ((NU)((NI)((NI)((NU64)(((NI) ((NI)(((NI) (b_238194)) & ((NI) 15))))) << (NU64)(((NI) 2))) | (NI)((NU64)((NI)(((NI) (c_238196)) & ((NI) 192))) >> (NU64)(((NI) 6))))) > (NU)(((NimStringDesc*) &TMP1355)->Sup.len)) raiseIndexError();
			result->data[(NI)(TMP1357)] = ((NimStringDesc*) &TMP1355)->data[(NI)((NI)((NU64)(((NI) ((NI)(((NI) (b_238194)) & ((NI) 15))))) << (NU64)(((NI) 2))) | (NI)((NU64)((NI)(((NI) (c_238196)) & ((NI) 192))) >> (NU64)(((NI) 6))))];
			nimln(33, "base64.nim");
			TMP1358 = addInt(r_238188, ((NI) 3));
			if ((NU)((NI)(TMP1358)) > (NU)(result->Sup.len)) raiseIndexError();
			if ((NU)((NI)(((NI) (c_238196)) & ((NI) 63))) > (NU)(((NimStringDesc*) &TMP1355)->Sup.len)) raiseIndexError();
			result->data[(NI)(TMP1358)] = ((NimStringDesc*) &TMP1355)->data[(NI)(((NI) (c_238196)) & ((NI) 63))];
			nimln(34, "base64.nim");
			TMP1359 = addInt(r_238188, ((NI) 4));
			r_238188 = (NI)(TMP1359);
			nimln(35, "base64.nim");
			TMP1360 = addInt(i_238186, ((NI) 3));
			i_238186 = (NI)(TMP1360);
			nimln(36, "base64.nim");
			TMP1361 = addInt(currline_238190, ((NI) 4));
			currline_238190 = (NI)(TMP1361);
			nimln(37, "base64.nim");
			{
				NIM_BOOL LOC9;
				NI TMP1362;
				LOC9 = 0;
				LOC9 = (linelen <= currline_238190);
				if (!(LOC9)) goto LA10;
				TMP1362 = subInt((s ? s->Sup.len : 0), ((NI) 2));
				LOC9 = !((i_238186 == (NI)(TMP1362)));
				LA10: ;
				if (!LOC9) goto LA11;
				{
					NIM_CHAR x_238198;
					NI i_238311;
					NI L_238313;
					x_238198 = 0;
					nimln(3102, "system.nim");
					i_238311 = ((NI) 0);
					nimln(3103, "system.nim");
					L_238313 = (newline ? newline->Sup.len : 0);
					{
						nimln(3104, "system.nim");
						while (1) {
							NI TMP1363;
							NI TMP1364;
							if (!(i_238311 < L_238313)) goto LA15;
							nimln(3105, "system.nim");
							if ((NU)(i_238311) > (NU)(newline->Sup.len)) raiseIndexError();
							x_238198 = newline->data[i_238311];
							nimln(39, "base64.nim");
							if ((NU)(r_238188) > (NU)(result->Sup.len)) raiseIndexError();
							result->data[r_238188] = x_238198;
							nimln(40, "base64.nim");
							TMP1363 = addInt(r_238188, ((NI) 1));
							r_238188 = (NI)(TMP1363);
							nimln(3106, "system.nim");
							TMP1364 = addInt(i_238311, ((NI) 1));
							i_238311 = (NI)(TMP1364);
							nimln(3107, "system.nim");
							{
								if (!!(((newline ? newline->Sup.len : 0) == L_238313))) goto LA18;
								failedassertimpl_88817(((NimStringDesc*) &TMP1365));
							}
							LA18: ;
						} LA15: ;
					}
				}
				nimln(41, "base64.nim");
				currline_238190 = ((NI) 0);
			}
			LA11: ;
		} LA6: ;
	}
	nimln(43, "base64.nim");
	{
		NI TMP1366;
		NI a_238200;
		NI b_238202;
		NI TMP1367;
		NI TMP1368;
		NI TMP1369;
		NI TMP1370;
		TMP1366 = subInt((s ? s->Sup.len : 0), ((NI) 1));
		if (!(i_238186 < (NI)(TMP1366))) goto LA22;
		nimln(44, "base64.nim");
		if ((NU)(i_238186) > (NU)(s->Sup.len)) raiseIndexError();
		a_238200 = ((NU8)(s->data[i_238186]));
		nimln(45, "base64.nim");
		TMP1367 = addInt(i_238186, ((NI) 1));
		if ((NU)((NI)(TMP1367)) > (NU)(s->Sup.len)) raiseIndexError();
		b_238202 = ((NU8)(s->data[(NI)(TMP1367)]));
		nimln(46, "base64.nim");
		if ((NU)(r_238188) > (NU)(result->Sup.len)) raiseIndexError();
		if ((NU)((NI)((NU64)(((NI) (a_238200))) >> (NU64)(((NI) 2)))) > (NU)(((NimStringDesc*) &TMP1355)->Sup.len)) raiseIndexError();
		result->data[r_238188] = ((NimStringDesc*) &TMP1355)->data[(NI)((NU64)(((NI) (a_238200))) >> (NU64)(((NI) 2)))];
		nimln(47, "base64.nim");
		TMP1368 = addInt(r_238188, ((NI) 1));
		if ((NU)((NI)(TMP1368)) > (NU)(result->Sup.len)) raiseIndexError();
		if ((NU)((NI)((NI)((NU64)(((NI) ((NI)(((NI) (a_238200)) & ((NI) 3))))) << (NU64)(((NI) 4))) | (NI)((NU64)((NI)(((NI) (b_238202)) & ((NI) 240))) >> (NU64)(((NI) 4))))) > (NU)(((NimStringDesc*) &TMP1355)->Sup.len)) raiseIndexError();
		result->data[(NI)(TMP1368)] = ((NimStringDesc*) &TMP1355)->data[(NI)((NI)((NU64)(((NI) ((NI)(((NI) (a_238200)) & ((NI) 3))))) << (NU64)(((NI) 4))) | (NI)((NU64)((NI)(((NI) (b_238202)) & ((NI) 240))) >> (NU64)(((NI) 4))))];
		nimln(48, "base64.nim");
		TMP1369 = addInt(r_238188, ((NI) 2));
		if ((NU)((NI)(TMP1369)) > (NU)(result->Sup.len)) raiseIndexError();
		if ((NU)((NI)((NU64)(((NI) ((NI)(((NI) (b_238202)) & ((NI) 15))))) << (NU64)(((NI) 2)))) > (NU)(((NimStringDesc*) &TMP1355)->Sup.len)) raiseIndexError();
		result->data[(NI)(TMP1369)] = ((NimStringDesc*) &TMP1355)->data[(NI)((NU64)(((NI) ((NI)(((NI) (b_238202)) & ((NI) 15))))) << (NU64)(((NI) 2)))];
		nimln(49, "base64.nim");
		TMP1370 = addInt(r_238188, ((NI) 3));
		if ((NU)((NI)(TMP1370)) > (NU)(result->Sup.len)) raiseIndexError();
		result->data[(NI)(TMP1370)] = 61;
		nimln(50, "base64.nim");
		{
			NI TMP1371;
			NI TMP1372;
			TMP1371 = addInt(r_238188, ((NI) 4));
			if (!!(((NI)(TMP1371) == (result ? result->Sup.len : 0)))) goto LA26;
			nimln(51, "base64.nim");
			TMP1372 = addInt(r_238188, ((NI) 4));
			result = setLengthStr(result, ((NI)chckRange((NI)(TMP1372), ((NI) 0), ((NI) IL64(9223372036854775807)))));
		}
		LA26: ;
	}
	goto LA20;
	LA22: ;
	{
		NI a_238204;
		NI TMP1373;
		NI TMP1374;
		NI TMP1375;
		nimln(52, "base64.nim");
		if (!(i_238186 < (s ? s->Sup.len : 0))) goto LA29;
		nimln(53, "base64.nim");
		if ((NU)(i_238186) > (NU)(s->Sup.len)) raiseIndexError();
		a_238204 = ((NU8)(s->data[i_238186]));
		nimln(54, "base64.nim");
		if ((NU)(r_238188) > (NU)(result->Sup.len)) raiseIndexError();
		if ((NU)((NI)((NU64)(((NI) (a_238204))) >> (NU64)(((NI) 2)))) > (NU)(((NimStringDesc*) &TMP1355)->Sup.len)) raiseIndexError();
		result->data[r_238188] = ((NimStringDesc*) &TMP1355)->data[(NI)((NU64)(((NI) (a_238204))) >> (NU64)(((NI) 2)))];
		nimln(55, "base64.nim");
		TMP1373 = addInt(r_238188, ((NI) 1));
		if ((NU)((NI)(TMP1373)) > (NU)(result->Sup.len)) raiseIndexError();
		if ((NU)((NI)((NU64)(((NI) ((NI)(((NI) (a_238204)) & ((NI) 3))))) << (NU64)(((NI) 4)))) > (NU)(((NimStringDesc*) &TMP1355)->Sup.len)) raiseIndexError();
		result->data[(NI)(TMP1373)] = ((NimStringDesc*) &TMP1355)->data[(NI)((NU64)(((NI) ((NI)(((NI) (a_238204)) & ((NI) 3))))) << (NU64)(((NI) 4)))];
		nimln(56, "base64.nim");
		TMP1374 = addInt(r_238188, ((NI) 2));
		if ((NU)((NI)(TMP1374)) > (NU)(result->Sup.len)) raiseIndexError();
		result->data[(NI)(TMP1374)] = 61;
		nimln(57, "base64.nim");
		TMP1375 = addInt(r_238188, ((NI) 3));
		if ((NU)((NI)(TMP1375)) > (NU)(result->Sup.len)) raiseIndexError();
		result->data[(NI)(TMP1375)] = 61;
		nimln(58, "base64.nim");
		{
			NI TMP1376;
			NI TMP1377;
			TMP1376 = addInt(r_238188, ((NI) 4));
			if (!!(((NI)(TMP1376) == (result ? result->Sup.len : 0)))) goto LA33;
			nimln(59, "base64.nim");
			TMP1377 = addInt(r_238188, ((NI) 4));
			result = setLengthStr(result, ((NI)chckRange((NI)(TMP1377), ((NI) 0), ((NI) IL64(9223372036854775807)))));
		}
		LA33: ;
	}
	goto LA20;
	LA29: ;
	{
	}
	LA20: ;
	popFrame();
	return result;
}

static N_INLINE(NI, decodebyte_238335)(NIM_CHAR b) {
	NI result;
	nimfr("decodeByte", "base64.nim")
	result = 0;
	nimln(75, "base64.nim");
	switch (((NU8)(b))) {
	case 43:
	{
		nimln(76, "base64.nim");
		result = ((NI) 62);
	}
	break;
	case 48 ... 57:
	{
		NI TMP1378;
		nimln(77, "base64.nim");
		TMP1378 = addInt(((NI) (((NU8)(b)))), ((NI) 4));
		result = ((NI) ((NI)(TMP1378)));
	}
	break;
	case 65 ... 90:
	{
		NI TMP1379;
		nimln(78, "base64.nim");
		TMP1379 = subInt(((NI) (((NU8)(b)))), ((NI) 65));
		result = ((NI) ((NI)(TMP1379)));
	}
	break;
	case 97 ... 122:
	{
		NI TMP1380;
		nimln(79, "base64.nim");
		TMP1380 = subInt(((NI) (((NU8)(b)))), ((NI) 71));
		result = ((NI) ((NI)(TMP1380)));
	}
	break;
	default:
	{
		nimln(80, "base64.nim");
		result = ((NI) 63);
	}
	break;
	}
	popFrame();
	return result;
}

N_NIMCALL(NimStringDesc*, decode_238390)(NimStringDesc* s) {
	NimStringDesc* result;
	NI total;
	NI TMP1381;
	NI TMP1382;
	NI TMP1383;
	NI i;
	NI r;
	nimfr("decode", "base64.nim")
	result = 0;
	nimln(86, "base64.nim");
	TMP1381 = addInt((s ? s->Sup.len : 0), ((NI) 3));
	TMP1382 = divInt((NI)(TMP1381), ((NI) 4));
	TMP1383 = mulInt((NI)(TMP1382), ((NI) 3));
	total = (NI)(TMP1383);
	nimln(88, "base64.nim");
	result = mnewString(((NI)chckRange(total, ((NI) 0), ((NI) IL64(9223372036854775807)))));
	nimln(90, "base64.nim");
	i = ((NI) 0);
	nimln(91, "base64.nim");
	r = ((NI) 0);
	{
		nimln(92, "base64.nim");
		while (1) {
			{
				nimln(93, "base64.nim");
				while (1) {
					NI TMP1384;
					if ((NU)(i) > (NU)(s->Sup.len)) raiseIndexError();
					if (!(((NU8)(s->data[i])) == ((NU8)(32)) || ((NU8)(s->data[i])) == ((NU8)(9)) || ((NU8)(s->data[i])) == ((NU8)(11)) || ((NU8)(s->data[i])) == ((NU8)(13)) || ((NU8)(s->data[i])) == ((NU8)(10)) || ((NU8)(s->data[i])) == ((NU8)(12)))) goto LA4;
					TMP1384 = addInt(i, ((NI) 1));
					i = (NI)(TMP1384);
				} LA4: ;
			}
			nimln(94, "base64.nim");
			{
				NI TMP1385;
				NI a;
				NI b;
				NI TMP1386;
				NI c;
				NI TMP1387;
				NI d;
				NI TMP1388;
				NI TMP1389;
				NI TMP1390;
				NI TMP1391;
				NI TMP1392;
				TMP1385 = subInt((s ? s->Sup.len : 0), ((NI) 3));
				if (!(i < (NI)(TMP1385))) goto LA7;
				nimln(95, "base64.nim");
				if ((NU)(i) > (NU)(s->Sup.len)) raiseIndexError();
				a = decodebyte_238335(s->data[i]);
				nimln(96, "base64.nim");
				TMP1386 = addInt(i, ((NI) 1));
				if ((NU)((NI)(TMP1386)) > (NU)(s->Sup.len)) raiseIndexError();
				b = decodebyte_238335(s->data[(NI)(TMP1386)]);
				nimln(97, "base64.nim");
				TMP1387 = addInt(i, ((NI) 2));
				if ((NU)((NI)(TMP1387)) > (NU)(s->Sup.len)) raiseIndexError();
				c = decodebyte_238335(s->data[(NI)(TMP1387)]);
				nimln(98, "base64.nim");
				TMP1388 = addInt(i, ((NI) 3));
				if ((NU)((NI)(TMP1388)) > (NU)(s->Sup.len)) raiseIndexError();
				d = decodebyte_238335(s->data[(NI)(TMP1388)]);
				nimln(100, "base64.nim");
				if ((NU)(r) > (NU)(result->Sup.len)) raiseIndexError();
				result->data[r] = ((NIM_CHAR) (((NI)chckRange((NI)(((NI) ((NI)((NI)((NU64)(a) << (NU64)(((NI) 2))) & ((NI) 255)))) | ((NI) ((NI)((NI)((NU64)(b) >> (NU64)(((NI) 4))) & ((NI) 3))))), ((NI) 0), ((NI) 255)))));
				nimln(101, "base64.nim");
				TMP1389 = addInt(r, ((NI) 1));
				if ((NU)((NI)(TMP1389)) > (NU)(result->Sup.len)) raiseIndexError();
				result->data[(NI)(TMP1389)] = ((NIM_CHAR) (((NI)chckRange((NI)(((NI) ((NI)((NI)((NU64)(b) << (NU64)(((NI) 4))) & ((NI) 255)))) | ((NI) ((NI)((NI)((NU64)(c) >> (NU64)(((NI) 2))) & ((NI) 15))))), ((NI) 0), ((NI) 255)))));
				nimln(102, "base64.nim");
				TMP1390 = addInt(r, ((NI) 2));
				if ((NU)((NI)(TMP1390)) > (NU)(result->Sup.len)) raiseIndexError();
				result->data[(NI)(TMP1390)] = ((NIM_CHAR) (((NI)chckRange((NI)(((NI) ((NI)((NI)((NU64)(c) << (NU64)(((NI) 6))) & ((NI) 255)))) | ((NI) ((NI)(d & ((NI) 63))))), ((NI) 0), ((NI) 255)))));
				nimln(103, "base64.nim");
				TMP1391 = addInt(r, ((NI) 3));
				r = (NI)(TMP1391);
				nimln(104, "base64.nim");
				TMP1392 = addInt(i, ((NI) 4));
				i = (NI)(TMP1392);
			}
			goto LA5;
			LA7: ;
			{
				nimln(105, "base64.nim");
				goto LA1;
			}
			LA5: ;
		}
	} LA1: ;
	nimln(106, "base64.nim");
	{
		if (!!((i == (s ? s->Sup.len : 0)))) goto LA12;
		failedassertimpl_88817(((NimStringDesc*) &TMP1393));
	}
	LA12: ;
	nimln(108, "base64.nim");
	{
		NIM_BOOL LOC16;
		NI TMP1394;
		NI TMP1395;
		LOC16 = 0;
		LOC16 = (((NI) 0) < i);
		if (!(LOC16)) goto LA17;
		TMP1394 = subInt(i, ((NI) 1));
		if ((NU)((NI)(TMP1394)) > (NU)(s->Sup.len)) raiseIndexError();
		LOC16 = ((NU8)(s->data[(NI)(TMP1394)]) == (NU8)(61));
		LA17: ;
		if (!LOC16) goto LA18;
		nimln(109, "base64.nim");
		TMP1395 = subInt(r, ((NI) 1));
		r = (NI)(TMP1395);
		nimln(110, "base64.nim");
		{
			NIM_BOOL LOC22;
			NI TMP1396;
			NI TMP1397;
			LOC22 = 0;
			LOC22 = (((NI) 1) < i);
			if (!(LOC22)) goto LA23;
			TMP1396 = subInt(i, ((NI) 2));
			if ((NU)((NI)(TMP1396)) > (NU)(s->Sup.len)) raiseIndexError();
			LOC22 = ((NU8)(s->data[(NI)(TMP1396)]) == (NU8)(61));
			LA23: ;
			if (!LOC22) goto LA24;
			TMP1397 = subInt(r, ((NI) 1));
			r = (NI)(TMP1397);
		}
		LA24: ;
	}
	LA18: ;
	nimln(111, "base64.nim");
	result = setLengthStr(result, ((NI)chckRange(r, ((NI) 0), ((NI) IL64(9223372036854775807)))));
	popFrame();
	return result;
}
NIM_EXTERNC N_NOINLINE(void, stdlib_base64Init)(void) {
	nimfr("base64", "base64.nim")
	popFrame();
}

NIM_EXTERNC N_NOINLINE(void, stdlib_base64DatInit)(void) {
}

