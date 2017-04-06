// FIB.h
// Define in-memory data structures for reading MS Word's .DOC File Information Block
// Adapted from https://msdn.microsoft.com/en-us/library/office/dd952676(v=office.14).aspx

#include <cstdint>

typedef uint8_t BYTE;
typedef uint16_t WORD;
typedef uint32_t DWORD;
typedef int32_t LONG;
/*
typedef struct _FILETIME
{
	DWORD dwLowDateTime;
	DWORD dwHighDateTime;
} FILETIME, *PFILETIME, *LPFILETIME;
*/

#pragma pack(push, 1)
struct FibBase
{
	WORD wldent;							// 0xA5EC
	WORD nFib;								// 0x00C1
	WORD unused;
	WORD lid;
	WORD pnNext;
	BYTE fDot : 1;
	BYTE fGlsy : 1;
	BYTE fComplex : 1;
	BYTE fHasPic : 1;
	BYTE cQuickSaves : 4;
	BYTE fEncrypted : 1;
	BYTE fWhichTblStm : 1;
	BYTE fReadOnlyRecommended : 1;
	BYTE fWriteReservation : 1;
	BYTE fExtChar : 1;
	BYTE fLoadOverride : 1;
	BYTE fFarEast : 1;
	BYTE fObfuscated : 1;
	WORD nFibBack;
	LONG lkey;
	BYTE envr;
	BYTE fMac : 1;
	BYTE fEmptySpecial : 1;
	BYTE fLoadOverridePage : 1;
	BYTE reserved1 : 1;
	BYTE reserved2 : 1;
	BYTE fSpare0 : 3;
	WORD reserved3;
	WORD reserved4;
	DWORD reserved5;
	DWORD reserved6;
};

struct FibRgW97
{
	WORD reserved1;
	WORD reserved2;
	WORD reserved3;
	WORD reserved4;
	WORD reserved5;
	WORD reserved6;
	WORD reserved7;
	WORD reserved8;
	WORD reserved9;
	WORD reserved10;
	WORD reserved11;
	WORD reserved12;
	WORD reserved13;
	WORD lidFE;
};

struct FibRgLw97
{
	DWORD cbMac;
	DWORD reserved1;
	DWORD reserved2;
	LONG ccpText;
	LONG ccpFtn;
	LONG ccpHdd;
	DWORD reserved3;
	LONG ccpAtn;
	LONG ccpEdn;
	LONG ccpTxbx;
	LONG ccpHdrTxbx;
	DWORD reserved4;
	DWORD reserved5;
	DWORD reserved6;
	DWORD reserved7;
	DWORD reserved8;
	DWORD reserved9;
	DWORD reserved10;
	DWORD reserved11;
	DWORD reserved12;
	DWORD reserved13;
	DWORD reserved14;
};

union FibRgFcLcb
{
	struct FibRgFcLcb97
	{
		DWORD fcStshfOrig;
		DWORD lcbStshfOrig;
		DWORD fcStshf;
		DWORD lcbStshf;
		DWORD fcPlcffndRef;
		DWORD lcbPlcffndRef;
		DWORD fcPlcffndTxt;
		DWORD lcbPlcffndTxt;
		DWORD fcPlcfandRef;
		DWORD lcbPlcfandRef;
		DWORD fcPlcfandTxt;
		DWORD lcbPlcfandTxt;
		DWORD fcPlcfSed;
		DWORD lcbPlcfSed;
		DWORD fcPlcPad;
		DWORD lcbPlcPad;
		DWORD fcPlcfPhe;
		DWORD lcbPlcfPhe;
		DWORD fcSttbfGlsy;
		DWORD lcbSttbfGlsy;
		DWORD fcPlcfGlsy;
		DWORD lcbPlcfGlsy;
		DWORD fcPlcfHdd;
		DWORD lcbPlcfHdd;
		DWORD fcPlcfBteChpx;
		DWORD lcbPlcfBteChpx;
		DWORD fcPlcfBtePapx;
		DWORD lcbPlcfBtePapx;
		DWORD fcPlcfSea;
		DWORD lcbPlcfSea;
		DWORD fcSttbfFfn;
		DWORD lcbSttbfFfn;
		DWORD fcPlcfFldMom;
		DWORD lcbPlcfFldMom;
		DWORD fcPlcfFldHdr;
		DWORD lcbPlcfFldHdr;
		DWORD fcPlcfFldFtn;
		DWORD lcbPlcfFldFtn;
		DWORD fcPlcfFldAtn;
		DWORD lcbPlcfFldAtn;
		DWORD fcPlcfFldMcr;
		DWORD lcbPlcfFldMcr;
		DWORD fcSttbfBkmk;
		DWORD lcbSttbfBkmk;
		DWORD fcPlcfBkf;
		DWORD lcbPlcfBkf;
		DWORD fcPlcfBkl;
		DWORD lcbPlcfBkl;
		DWORD fcCmds;
		DWORD lcbCmds;
		DWORD fcUnused1;
		DWORD lcbUnused1;
		DWORD fcSttbfMcr;
		DWORD lcbSttbfMcr;
		DWORD fcPrDrvr;
		DWORD lcbPrDrvr;
		DWORD fcPrEnvPort;
		DWORD lcbPrEnvPort;
		DWORD fcPrEnvLand;
		DWORD lcbPrEnvLand;
		DWORD fcWss;
		DWORD lcbWss;
		DWORD fcDop;
		DWORD lcbDop;
		DWORD fcSttbfAssoc;
		DWORD lcbSttbfAssoc;
		DWORD fcClx;
		DWORD lcbClx;
		DWORD fcPlcfPgdFtn;
		DWORD lcbPlcfPgdFtn;
		DWORD fcAutosaveSource;
		DWORD lcbAutosaveSource;
		DWORD fcGrpXstAtnOwners;
		DWORD lcbGrpXstAtnOwners;
		DWORD fcSttbfAtnBkmk;
		DWORD lcbSttbfAtnBkmk;
		DWORD fcUnused2;
		DWORD lcbUnused2;
		DWORD fcUnused3;
		DWORD lcbUnused3;
		DWORD fcPlcSpaMom;
		DWORD lcbPlcSpaMom;
		DWORD fcPlcSpaHdr;
		DWORD lcbPlcSpaHdr;
		DWORD fcPlcfAtnBkf;
		DWORD lcbPlcfAtnBkf;
		DWORD fcPlcfAtnBkl;
		DWORD lcbPlcfAtnBkl;
		DWORD fcPms;
		DWORD lcbPms;
		DWORD fcFormFldSttbs;
		DWORD lcbFormFldSttbs;
		DWORD fcPlcfendRef;
		DWORD lcbPlcfendRef;
		DWORD fcPlcfendTxt;
		DWORD lcbPlcfendTxt;
		DWORD fcPlcfFldEdn;
		DWORD lcbPlcfFldEdn;
		DWORD fcUnused4;
		DWORD lcbUnused4;
		DWORD fcDggInfo;
		DWORD lcbDggInfo;
		DWORD fcSttbfRMark;
		DWORD lcbSttbfRMark;
		DWORD fcSttbfCaption;
		DWORD lcbSttbfCaption;
		DWORD fcSttbfAutoCaption;
		DWORD lcbSttbfAutoCaption;
		DWORD fcPlcfWkb;
		DWORD lcbPlcfWkb;
		DWORD fcPlcfSpl;
		DWORD lcbPlcfSpl;
		DWORD fcPlcftxbxTxt;
		DWORD lcbPlcftxbxTxt;
		DWORD fcPlcfFldTxbx;
		DWORD lcbPlcfFldTxbx;
		DWORD fcPlcfHdrtxbxTxt;
		DWORD lcbPlcfHdrtxbxTxt;
		DWORD fcPlcffldHdrTxbx;
		DWORD lcbPlcffldHdrTxbx;
		DWORD fcStwUser;
		DWORD lcbStwUser;
		DWORD fcSttbTtmbd;
		DWORD lcbSttbTtmbd;
		DWORD fcCookieData;
		DWORD lcbCookieData;
		DWORD fcPgdMotherOldOld;
		DWORD lcbPgdMotherOldOld;
		DWORD fcBkdMotherOldOld;
		DWORD lcbBkdMotherOldOld;
		DWORD fcPgdFtnOldOld;
		DWORD lcbPgdFtnOldOld;
		DWORD fcBkdFtnOldOld;
		DWORD lcbBkdFtnOldOld;
		DWORD fcPgdEdnOldOld;
		DWORD lcbPgdEdnOldOld;
		DWORD fcBkdEdnOldOld;
		DWORD lcbBkdEdnOldOld;
		DWORD fcSttbfIntlFld;
		DWORD lcbSttbfIntlFld;
		DWORD fcRouteSlip;
		DWORD lcbRouteSlip;
		DWORD fcSttbSavedBy;
		DWORD lcbSttbSavedBy;
		DWORD fcSttbFnm;
		DWORD lcbSttbFnm;
		DWORD fcPlfLst;
		DWORD lcbPlfLst;
		DWORD fcPlfLfo;
		DWORD lcbPlfLfo;
		DWORD fcPlcfTxbxBkd;
		DWORD lcbPlcfTxbxBkd;
		DWORD fcPlcfTxbxHdrBkd;
		DWORD lcbPlcfTxbxHdrBkd;
		DWORD fcDocUndoWord9;
		DWORD lcbDocUndoWord9;
		DWORD fcRgbUse;
		DWORD lcbRgbUse;
		DWORD fcUsp;
		DWORD lcbUsp;
		DWORD fcUskf;
		DWORD lcbUskf;
		DWORD fcPlcupcRgbUse;
		DWORD lcbPlcupcRgbUse;
		DWORD fcPlcupcUsp;
		DWORD lcbPlcupcUsp;
		DWORD fcSttbGlsyStyle;
		DWORD lcbSttbGlsyStyle;
		DWORD fcPlgosl;
		DWORD lcbPlgosl;
		DWORD fcPlcocx;
		DWORD lcbPlcocx;
		DWORD fcPlcfBteLvc;
		DWORD lcbPlcfBteLvc;
		DWORD dwLowDateTime;
		DWORD dwHighDateTime;
		DWORD fcPlcfLvcPre10;
		DWORD lcbPlcfLvcPre10;
		DWORD fcPlcfAsumy;
		DWORD lcbPlcfAsumy;
		DWORD fcPlcfGram;
		DWORD lcbPlcfGram;
		DWORD fcSttbListNames;
		DWORD lcbSttbListNames;
		DWORD fcSttbfUssr;
		DWORD lcbSttbfUssr;
	};

	struct FibRgFcLcb2000
	{
		FibRgFcLcb97 rgFcLcb97;
		DWORD fcPlcfTch;
		DWORD lcbPlcfTch;
		DWORD fcRmdThreading;
		DWORD lcbRmdThreading;
		DWORD fcMid;
		DWORD lcbMid;
		DWORD fcSttbRgtplc;
		DWORD lcbSttbRgtplc;
		DWORD fcMsoEnvelope;
		DWORD lcbMsoEnvelope;
		DWORD fcPlcfLad;
		DWORD lcbPlcfLad;
		DWORD fcRgDofr;
		DWORD lcbRgDofr;
		DWORD fcPlcosl;
		DWORD lcbPlcosl;
		DWORD fcPlcfCookieOld;
		DWORD lcbPlcfCookieOld;
		DWORD fcPgdMotherOld;
		DWORD lcbPgdMotherOld;
		DWORD fcBkdMotherOld;
		DWORD lcbBkdMotherOld;
		DWORD fcPgdFtnOld;
		DWORD lcbPgdFtnOld;
		DWORD fcBkdFtnOld;
		DWORD lcbBkdFtnOld;
		DWORD fcPgdEdnOld;
		DWORD lcbPgdEdnOld;
		DWORD fcBkdEdnOld;
		DWORD lcbBkdEdnOld;
	};

	struct FibRgFcLcb2002
	{
		FibRgFcLcb2000 rgFcLcb2000;
		DWORD fcUnused1;
		DWORD lcbUnused1;
		DWORD fcPlcfPgp;
		DWORD lcbPlcfPgp;
		DWORD fcPlcfuim;
		DWORD lcbPlcfuim;
		DWORD fcPlfguidUim;
		DWORD lcbPlfguidUim;
		DWORD fcAtrdExtra;
		DWORD lcbAtrdExtra;
		DWORD fcPlrsid;
		DWORD lcbPlrsid;
		DWORD fcSttbfBkmkFactoid;
		DWORD lcbSttbfBkmkFactoid;
		DWORD fcPlcfBkfFactoid;
		DWORD lcbPlcfBkfFactoid;
		DWORD fcPlcfcookie;
		DWORD lcbPlcfcookie;
		DWORD fcPlcfBklFactoid;
		DWORD lcbPlcfBklFactoid;
		DWORD fcFactoidData;
		DWORD lcbFactoidData;
		DWORD fcDocUndo;
		DWORD lcbDocUndo;
		DWORD fcSttbfBkmkFcc;
		DWORD lcbSttbfBkmkFcc;
		DWORD fcPlcfBkfFcc;
		DWORD lcbPlcfBkfFcc;
		DWORD fcPlcfBklFcc;
		DWORD lcbPlcfBklFcc;
		DWORD fcSttbfbkmkBPRepairs;
		DWORD lcbSttbfbkmkBPRepairs;
		DWORD fcPlcfbkfBPRepairs;
		DWORD lcbPlcfbkfBPRepairs;
		DWORD fcPlcfbklBPRepairs;
		DWORD lcbPlcfbklBPRepairs;
		DWORD fcPmsNew;
		DWORD lcbPmsNew;
		DWORD fcODSO;
		DWORD lcbODSO;
		DWORD fcPlcfpmiOldXP;
		DWORD lcbPlcfpmiOldXP;
		DWORD fcPlcfpmiNewXP;
		DWORD lcbPlcfpmiNewXP;
		DWORD fcPlcfpmiMixedXP;
		DWORD lcbPlcfpmiMixedXP;
		DWORD fcUnused2;
		DWORD lcbUnused2;
		DWORD fcPlcffactoid;
		DWORD lcbPlcffactoid;
		DWORD fcPlcflvcOldXP;
		DWORD lcbPlcflvcOldXP;
		DWORD fcPlcflvcNewXP;
		DWORD lcbPlcflvcNewXP;
		DWORD fcPlcflvcMixedXP;
		DWORD lcbPlcflvcMixedXP;
	};

	struct FibRgFcLcb2003
	{
		FibRgFcLcb2002 rgFcLcb2002;
		DWORD fcHplxsdr;
		DWORD lcbHplxsdr;
		DWORD fcSttbfBkmkSdt;
		DWORD lcbSttbfBkmkSdt;
		DWORD fcPlcfBkfSdt;
		DWORD lcbPlcfBkfSdt;
		DWORD fcPlcfBklSdt;
		DWORD lcbPlcfBklSdt;
		DWORD fcCustomXForm;
		DWORD lcbCustomXForm;
		DWORD fcSttbfBkmkProt;
		DWORD lcbSttbfBkmkProt;
		DWORD fcPlcfBkfProt;
		DWORD lcbPlcfBkfProt;
		DWORD fcPlcfBklProt;
		DWORD lcbPlcfBklProt;
		DWORD fcSttbProtUser;
		DWORD lcbSttbProtUser;
		DWORD fcUnused;
		DWORD lcbUnused;
		DWORD fcPlcfpmiOld;
		DWORD lcbPlcfpmiOld;
		DWORD fcPlcfpmiOldInline;
		DWORD lcbPlcfpmiOldInline;
		DWORD fcPlcfpmiNew;
		DWORD lcbPlcfpmiNew;
		DWORD fcPlcfpmiNewInline;
		DWORD lcbPlcfpmiNewInline;
		DWORD fcPlcflvcOld;
		DWORD lcbPlcflvcOld;
		DWORD fcPlcflvcOldInline;
		DWORD lcbPlcflvcOldInline;
		DWORD fcPlcflvcNew;
		DWORD lcbPlcflvcNew;
		DWORD fcPlcflvcNewInline;
		DWORD lcbPlcflvcNewInline;
		DWORD fcPgdMother;
		DWORD lcbPgdMother;
		DWORD fcBkdMother;
		DWORD lcbBkdMother;
		DWORD fcAfdMother;
		DWORD lcbAfdMother;
		DWORD fcPgdFtn;
		DWORD lcbPgdFtn;
		DWORD fcBkdFtn;
		DWORD lcbBkdFtn;
		DWORD fcAfdFtn;
		DWORD lcbAfdFtn;
		DWORD fcPgdEdn;
		DWORD lcbPgdEdn;
		DWORD fcBkdEdn;
		DWORD lcbBkdEdn;
		DWORD fcAfdEdn;
		DWORD lcbAfdEdn;
		DWORD fcAfd;
		DWORD lcbAfd;
	};

	struct FibRgFcLcb2007
	{
		FibRgFcLcb2003 rgFcLcb2003;
		DWORD fcPlcfmthd;
		DWORD lcbPlcfmthd;
		DWORD fcSttbfBkmkMoveFrom;
		DWORD lcbSttbfBkmkMoveFrom;
		DWORD fcPlcfBkfMoveFrom;
		DWORD lcbPlcfBkfMoveFrom;
		DWORD fcPlcfBklMoveFrom;
		DWORD lcbPlcfBklMoveFrom;
		DWORD fcSttbfBkmkMoveTo;
		DWORD lcbSttbfBkmkMoveTo;
		DWORD fcPlcfBkfMoveTo;
		DWORD lcbPlcfBkfMoveTo;
		DWORD fcPlcfBklMoveTo;
		DWORD lcbPlcfBklMoveTo;
		DWORD fcUnused1;
		DWORD lcbUnused1;
		DWORD fcUnused2;
		DWORD lcbUnused2;
		DWORD fcUnused3;
		DWORD lcbUnused3;
		DWORD fcSttbfBkmkArto;
		DWORD lcbSttbfBkmkArto;
		DWORD fcPlcfBkfArto;
		DWORD lcbPlcfBkfArto;
		DWORD fcPlcfBklArto;
		DWORD lcbPlcfBklArto;
		DWORD fcArtoData;
		DWORD lcbArtoData;
		DWORD fcUnused4;
		DWORD lcbUnused4;
		DWORD fcUnused5;
		DWORD lcbUnused5;
		DWORD fcUnused6;
		DWORD lcbUnused6;
		DWORD fcOssTheme;
		DWORD lcbOssTheme;
		DWORD fcColorSchemeMapping;
		DWORD lcbColorSchemeMapping;
	};

};

union FibRgCswNewData
{
	struct FibRgCswNewData2000
	{
		WORD cQuickSavesNew;
	};

	struct FibRgCswNewData2007
	{
		FibRgCswNewData2000 rgCswNewData2000;
		WORD lidThemeOther;
		WORD lidThemeFE;
		WORD lidThemeCS;
	};

};


struct FibRgCswNew
{
	WORD nFibNew;
	FibRgCswNewData rgCswNewData;
};

struct Fib
{
	FibBase base;
	WORD csw;
	FibRgW97 fibRgW;
	WORD cslw;
	FibRgLw97 fibRgLw;
	WORD cbRgFcLcb;
	FibRgFcLcb fibRgFcLcbBlob;
	WORD cswNew;
	FibRgCswNew fibRgCswNew;
};
#pragma pack(pop)
