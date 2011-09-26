// Object identifier "DeRe"
#define IDENTIFIER  MAKEID(D,e,R,e)

// ------------------------------
// DEFINITION OF CONDITIONS CODES
// ------------------------------
#define	CND_OBJISINOBSTACLE					0
#define	CND_LAST							1

// ---------------------------
// DEFINITION OF ACTIONS CODES
// ---------------------------
#define	ACT_ADDOBJECT						0
#define	ACT_REMOVEOBJECT					1
#define	ACT_UPDATEPOSITION					2
#define	ACT_UPDATEX							3
#define	ACT_UPDATEY							4
#define	ACT_UPDATEDIR						5
#define	ACT_UPDATEANGLE						6
#define	ACT_SETX							7
#define	ACT_SETY							8
#define	ACT_SETDIR							9
#define	ACT_SETANGLE						10
#define	ACT_SETXSPEED						11
#define	ACT_SETYSPEED						12
#define	ACT_SETDIRSPEED						13
#define	ACT_SETANGLESPEED					14
#define	ACT_OBJWASSTOPPED					15
#define	ACT_OBJBOUNCED						16
#define	ACT_SETOBJEXTRAPOLATIONMODE			17
#define	ACT_SETOBJACCELERATIONMODE			18
#define	ACT_SETOBJSMOOTHING					19
#define	ACT_SETOBJXEXTRAPOLATIONMODE		20
#define	ACT_SETOBJXACCELERATIONMODE			21
#define	ACT_SETOBJXSMOOTHING				22
#define	ACT_SETOBJYEXTRAPOLATIONMODE		23
#define	ACT_SETOBJYACCELERATIONMODE			24
#define	ACT_SETOBJYSMOOTHING				25
#define	ACT_SETOBJDIREXTRAPOLATIONMODE		26
#define	ACT_SETOBJDIRACCELERATIONMODE		27
#define	ACT_SETOBJDIRSMOOTHING				28
#define	ACT_SETOBJANGLEEXTRAPOLATIONMODE	29
#define	ACT_SETOBJANGLEACCELERATIONMODE		30
#define	ACT_SETOBJANGLESMOOTHING			31
#define	ACT_PUSHOBJOUTOFOBSTACLE			32
#define	ACT_OBJECTISINSIDEOBSTACLE			33

#define	ACT_LAST							34

// -------------------------------
// DEFINITION OF EXPRESSIONS CODES
// -------------------------------
#define	EXP_NUMOBJECTS						0
#define	EXP_PREDICTEDX						1
#define	EXP_PREDICTEDY						2
#define	EXP_PREDICTEDDIR					3
#define	EXP_PREDICTEDANGLE					4
#define	EXP_XSPEED							5
#define	EXP_YSPEED							6
#define	EXP_DIRSPEED						7
#define	EXP_ANGLESPEED						8
#define	EXP_XSMOOTHING						9
#define	EXP_YSMOOTHING						10
#define	EXP_DIRSMOOTHING					11
#define	EXP_ANGLESMOOTHING					12
#define	EXP_MOVESPEED						13
#define	EXP_MOVEDDIRECTION					14
#define	EXP_MOVEDANGLE						15

#define EXP_LAST							16

// ---------------------
// OBJECT DATA STRUCTURE 
// ---------------------
// Used at edit time and saved in the MFA/CCN/EXE files

typedef struct tagEDATA_V2
{
	extHeader		eHeader;
	int				extrapolationMethod;
	bool			useAcceleration;
	int				XSmoothing;
	int				YSmoothing;
	int				DirSmoothing;
	int				AngleSmoothing;

} EDITDATA;
typedef EDITDATA * LPEDATA;

typedef struct tagEDATA_V1
{
	// Header - required
	extHeader		eHeader;

	int				extrapolationMethod;
	bool			useAcceleration;

} EDITDATA_1;
typedef EDITDATA *			LPEDATA_1;

// Object versions
#define	KCX_CURRENT_VERSION			2

// --------------------------------
// RUNNING OBJECT DATA STRUCTURE
// --------------------------------
// Used at runtime. Initialize it in the CreateRunObject function.
// Free any allocated memory or object in the DestroyRunObject function.
//
// Note: if you store C++ objects in this structure and do not store 
// them as pointers, you must call yourself their constructor in the
// CreateRunObject function and their destructor in the DestroyRunObject
// function. As the RUNDATA structure is a simple C structure and not a C++ object.

typedef struct tagRDATA
{
	// Main header - required
	headerObject	rHo;					// Header

	long			time;
	DRMap*			objects;
	int				extrapolationMethod;
	bool			useAcceleration;
	float			XSmoothing;
	float			YSmoothing;
	float			DirSmoothing;
	float			AngleSmoothing;
	bool			hwa;
	bool			isInObstacle;
	LPRO			objectToPush;

} RUNDATA;
typedef	RUNDATA	*			LPRDATA;

// Size when editing the object under level editor
// -----------------------------------------------
#define	MAX_EDITSIZE			sizeof(EDITDATA)

// Default flags - see documentation for more info
// -------------
#define	OEFLAGS      			0
#define	OEPREFS      			0


// If to handle message, specify the priority of the handling procedure
// 0= low, 255= very high. You should use 100 as normal.                                                
// --------------------------------------------------------------------
#define	WINDOWPROC_PRIORITY		100



