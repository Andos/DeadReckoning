// ============================================================================
//
// This file are where the Conditions/Actions/Expressions are defined.
// You can manually enter these, or use CICK (recommended)
// See the Extension FAQ in this SDK for more info and where to download it
//
// ============================================================================

// Common Include
#include	"common.h"

// Quick memo: content of the eventInformations arrays
// ---------------------------------------------------
// Menu ID
// String ID
// Code
// Flags
// Number_of_parameters
// Parameter_type [Number_of_parameters]
// Parameter_TitleString [Number_of_parameters]

// Definitions of parameters for each condition
short conditionsInfos[]=
		{
		IDMN_OBJISINOBSTACLE, IDS_CND_OBJISINOBSTACLE, CND_OBJISINOBSTACLE, 0, 1, PARAM_OBJECT, IDS_SELECTOBJECT
		};

// Definitions of parameters for each action
short actionsInfos[]=
		{
		IDMN_ADDOBJECT,						IDS_ACT_ADDOBJECT,						ACT_ADDOBJECT,						0, 1, PARAM_OBJECT, IDS_OBJECTTOADD,
		IDMN_REMOVEOBJECT,					IDS_ACT_REMOVEOBJECT,					ACT_REMOVEOBJECT,					0, 1, PARAM_OBJECT, IDS_OBJECTTOREMOVE,
		IDMN_UPDATEPOSITION,				IDS_ACT_UPDATEPOSITION,					ACT_UPDATEPOSITION,					0, 3, PARAM_OBJECT, PARAM_EXPRESSION, PARAM_EXPRESSION,	IDS_OBJECTTOUPDATE, IDS_XCOORD, IDS_YCOORD,
		IDMN_UPDATEX,						IDS_ACT_UPDATEX,						ACT_UPDATEX,						0, 2, PARAM_OBJECT, PARAM_EXPRESSION,					IDS_OBJECTTOUPDATE, IDS_XCOORD,
		IDMN_UPDATEY,						IDS_ACT_UPDATEY,						ACT_UPDATEY,						0, 2, PARAM_OBJECT, PARAM_EXPRESSION,					IDS_OBJECTTOUPDATE, IDS_YCOORD,
		IDMN_UPDATEDIR,						IDS_ACT_UPDATEDIR,						ACT_UPDATEDIR,						0, 2, PARAM_OBJECT, PARAM_EXPRESSION,					IDS_OBJECTTOUPDATE, IDS_DIR,
		IDMN_UPDATEANGLE,					IDS_ACT_UPDATEANGLE,					ACT_UPDATEANGLE,					0, 2, PARAM_OBJECT, PARAM_EXPRESSION,					IDS_OBJECTTOUPDATE, IDS_ANGLE,
		IDMN_SETX,							IDS_ACT_SETX,							ACT_SETX,							0, 2, PARAM_OBJECT, PARAM_EXPRESSION,					IDS_OBJECTTOUPDATE, IDS_XCOORD,
		IDMN_SETY,							IDS_ACT_SETY,							ACT_SETY,							0, 2, PARAM_OBJECT, PARAM_EXPRESSION,					IDS_OBJECTTOUPDATE, IDS_YCOORD,
		IDMN_SETDIR,						IDS_ACT_SETDIR,							ACT_SETDIR,							0, 2, PARAM_OBJECT, PARAM_EXPRESSION,					IDS_OBJECTTOUPDATE, IDS_DIR,
		IDMN_SETANGLE,						IDS_ACT_SETANGLE,						ACT_SETANGLE,						0, 2, PARAM_OBJECT, PARAM_EXPRESSION,					IDS_OBJECTTOUPDATE, IDS_ANGLE,
		IDMN_SETXSPEED,						IDS_ACT_SETXSPEED,						ACT_SETXSPEED,						0, 2, PARAM_OBJECT, PARAM_EXPRESSION,					IDS_OBJECTTOUPDATE, IDS_XSPEED,
		IDMN_SETYSPEED,						IDS_ACT_SETYSPEED,						ACT_SETYSPEED,						0, 2, PARAM_OBJECT, PARAM_EXPRESSION,					IDS_OBJECTTOUPDATE, IDS_YSPEED,
		IDMN_SETDIRSPEED,					IDS_ACT_SETDIRSPEED,					ACT_SETDIRSPEED,					0, 2, PARAM_OBJECT, PARAM_EXPRESSION,					IDS_OBJECTTOUPDATE, IDS_DIRSPEED,
		IDMN_SETANGLESPEED,					IDS_ACT_SETANGLESPEED,					ACT_SETANGLESPEED,					0, 2, PARAM_OBJECT, PARAM_EXPRESSION,					IDS_OBJECTTOUPDATE, IDS_ANGLESPEED,
		IDMN_OBJWASSTOPPED,					IDS_ACT_OBJWASSTOPPED,					ACT_OBJWASSTOPPED,					0, 1, PARAM_OBJECT,										IDS_OBJWASSTOPPED,
		IDMN_OBJBOUNCED,					IDS_ACT_OBJBOUNCED,						ACT_OBJBOUNCED,						0, 1, PARAM_OBJECT,										IDS_OBJBOUNCED,
		IDMN_SETOBJEXTRAPOLATIONMODE,		IDS_ACT_SETOBJEXTRAPOLATIONMODE,		ACT_SETOBJEXTRAPOLATIONMODE,		0, 2, PARAM_OBJECT, PARAM_EXPRESSION,					IDS_SELECTOBJECT, IDS_EXTRAPOLATIONPARAM,
		IDMN_SETOBJACCELERATIONMODE,		IDS_ACT_SETOBJACCELERATIONMODE,			ACT_SETOBJACCELERATIONMODE,			0, 2, PARAM_OBJECT, PARAM_EXPRESSION,					IDS_SELECTOBJECT, IDS_USEACCELERATIONPARAM,
		IDMN_SETOBJSMOOTHING,				IDS_ACT_SETOBJSMOOTHING,				ACT_SETOBJSMOOTHING,				0, 2, PARAM_OBJECT, PARAM_EXPRESSION,					IDS_SELECTOBJECT, IDS_SMOOTHING,
		IDMN_SETOBJXEXTRAPOLATIONMODE,		IDS_ACT_SETOBJXEXTRAPOLATIONMODE,		ACT_SETOBJXEXTRAPOLATIONMODE,		0, 2, PARAM_OBJECT, PARAM_EXPRESSION,					IDS_SELECTOBJECT, IDS_EXTRAPOLATIONPARAM,
		IDMN_SETOBJXACCELERATIONMODE,		IDS_ACT_SETOBJXACCELERATIONMODE,		ACT_SETOBJXACCELERATIONMODE,		0, 2, PARAM_OBJECT, PARAM_EXPRESSION,					IDS_SELECTOBJECT, IDS_USEACCELERATIONPARAM,
		IDMN_SETOBJXSMOOTHING,				IDS_ACT_SETOBJXSMOOTHING,				ACT_SETOBJXSMOOTHING,				0, 2, PARAM_OBJECT, PARAM_EXPRESSION,					IDS_SELECTOBJECT, IDS_SMOOTHING,
		IDMN_SETOBJYEXTRAPOLATIONMODE,		IDS_ACT_SETOBJYEXTRAPOLATIONMODE,		ACT_SETOBJYEXTRAPOLATIONMODE,		0, 2, PARAM_OBJECT, PARAM_EXPRESSION,					IDS_SELECTOBJECT, IDS_EXTRAPOLATIONPARAM,
		IDMN_SETOBJYACCELERATIONMODE,		IDS_ACT_SETOBJYACCELERATIONMODE,		ACT_SETOBJYACCELERATIONMODE,		0, 2, PARAM_OBJECT, PARAM_EXPRESSION,					IDS_SELECTOBJECT, IDS_USEACCELERATIONPARAM,
		IDMN_SETOBJYSMOOTHING,				IDS_ACT_SETOBJYSMOOTHING,				ACT_SETOBJYSMOOTHING,				0, 2, PARAM_OBJECT, PARAM_EXPRESSION,					IDS_SELECTOBJECT, IDS_SMOOTHING,
		IDMN_SETOBJDIREXTRAPOLATIONMODE,	IDS_ACT_SETOBJDIREXTRAPOLATIONMODE,		ACT_SETOBJDIREXTRAPOLATIONMODE,		0, 2, PARAM_OBJECT, PARAM_EXPRESSION,					IDS_SELECTOBJECT, IDS_EXTRAPOLATIONPARAM,
		IDMN_SETOBJDIRACCELERATIONMODE,		IDS_ACT_SETOBJDIRACCELERATIONMODE,		ACT_SETOBJDIRACCELERATIONMODE,		0, 2, PARAM_OBJECT, PARAM_EXPRESSION,					IDS_SELECTOBJECT, IDS_USEACCELERATIONPARAM,
		IDMN_SETOBJDIRSMOOTHING,			IDS_ACT_SETOBJDIRSMOOTHING,				ACT_SETOBJDIRSMOOTHING,				0, 2, PARAM_OBJECT, PARAM_EXPRESSION,					IDS_SELECTOBJECT, IDS_SMOOTHING,
		IDMN_SETOBJANGLEEXTRAPOLATIONMODE,	IDS_ACT_SETOBJANGLEEXTRAPOLATIONMODE,	ACT_SETOBJANGLEEXTRAPOLATIONMODE,	0, 2, PARAM_OBJECT, PARAM_EXPRESSION,					IDS_SELECTOBJECT, IDS_EXTRAPOLATIONPARAM,
		IDMN_SETOBJANGLEACCELERATIONMODE,	IDS_ACT_SETOBJANGLEACCELERATIONMODE,	ACT_SETOBJANGLEACCELERATIONMODE,	0, 2, PARAM_OBJECT, PARAM_EXPRESSION,					IDS_SELECTOBJECT, IDS_USEACCELERATIONPARAM,
		IDMN_SETOBJANGLESMOOTHING,			IDS_ACT_SETOBJANGLESMOOTHING,			ACT_SETOBJANGLESMOOTHING,			0, 2, PARAM_OBJECT, PARAM_EXPRESSION,					IDS_SELECTOBJECT, IDS_SMOOTHING,
		IDMN_PUSHOBJOUTOFOBSTACLE,			IDS_ACT_PUSHOBJOUTOFOBSTACLE,			ACT_PUSHOBJOUTOFOBSTACLE,			0, 1, PARAM_OBJECT,										IDS_SELECTOBJECT,
		IDMN_OBJECTISINSIDEOBSTACLE,		IDS_ACT_OBJECTISINSIDEOBSTACLE,			ACT_OBJECTISINSIDEOBSTACLE,			0, 0,
		};

// Definitions of parameters for each expression
short expressionsInfos[]=
		{
		IDMN_NUMOBJECTS,		IDS_EXP_NUMOBJECTS,		EXP_NUMOBJECTS,		
		IDMN_PREDICTEDX,		IDS_EXP_PREDICTEDX,		EXP_PREDICTEDX,		
		IDMN_PREDICTEDY,		IDS_EXP_PREDICTEDY,		EXP_PREDICTEDY,		
		IDMN_PREDICTEDDIR,		IDS_EXP_PREDICTEDDIR,	EXP_PREDICTEDDIR,	
		IDMN_PREDICTEDANGLE,	IDS_EXP_PREDICTEDANGLE,	EXP_PREDICTEDANGLE,	
		IDMN_XSPEED,			IDS_EXP_XSPEED,			EXP_XSPEED,			
		IDMN_YSPEED,			IDS_EXP_YSPEED,			EXP_YSPEED,			
		IDMN_DIRSPEED,			IDS_EXP_DIRSPEED,		EXP_DIRSPEED,		
		IDMN_ANGLESPEED,		IDS_EXP_ANGLESPEED,		EXP_ANGLESPEED,		
		IDMN_XSMOOTHING,		IDS_EXP_XSMOOTHING,		EXP_XSMOOTHING,		
		IDMN_YSMOOTHING,		IDS_EXP_YSMOOTHING,		EXP_YSMOOTHING,		
		IDMN_DIRSMOOTHING,		IDS_EXP_DIRSMOOTHING,	EXP_DIRSMOOTHING,	
		IDMN_ANGLESMOOTHING,	IDS_EXP_ANGLESMOOTHING,	EXP_ANGLESMOOTHING,	
		IDMN_MOVESPEED,			IDS_EXP_MOVESPEED,		EXP_MOVESPEED,		
		IDMN_MOVEDDIRECTION,	IDS_EXP_MOVEDDIRECTION,	EXP_MOVEDDIRECTION,	
		IDMN_MOVEDANGLE,		IDS_EXP_MOVEDANGLE,		EXP_MOVEDANGLE,		
		};


_inline float GetFloatParamEx(LPRDATA rdPtr)
{
	long val = CNC_GetFloatParameter(rdPtr);
	return *(float*)&val;
}

_inline float RecastToFloat(long value)
{
	return *(float*)&value;
}

_inline long RecastToLong(float value)
{
	return *(long*)&value;
}



// ============================================================================
//
// CONDITION ROUTINES
// 
// ============================================================================

long WINAPI DLLExport cnd_objisinobstacle(LPRDATA rdPtr, long param1, long param2)
{
	if(rdPtr->objectToPush == NULL)
		return false;
	
	ObjectSelection select = ObjectSelection(rdPtr->rHo.hoAdRunHeader);
	select.SelectOneObject(rdPtr->objectToPush);
	return true;
}


// ============================================================================
//
// ACTIONS ROUTINES
// 
// ============================================================================

short WINAPI DLLExport act_addobject(LPRDATA rdPtr, long param1, long param2)
{
	LPRO object = (LPRO)CNC_GetParameter(rdPtr);
	long fixedValue = FixedVal(object);

	//Loop through all elements to ensure it isn't added twice.
	DRMap::iterator it = rdPtr->objects->begin();
	DRMap::iterator end = rdPtr->objects->end();
	for(; it != end; ++it)
		if(it->second.fixedValue == fixedValue)
			return 0;

	DRObj newObj;
	newObj.Reset();
	newObj.fixedValue = fixedValue;
	
	newObj.xPosition.lastUpdate = rdPtr->time;
	newObj.yPosition.lastUpdate = rdPtr->time;
	newObj.direction.lastUpdate = rdPtr->time;
	newObj.angle.lastUpdate = rdPtr->time;

	newObj.xPosition.SetValue((float)object->roHo.hoX);
	newObj.yPosition.SetValue((float)object->roHo.hoY);
	newObj.direction.SetValue((float)object->roc.rcDir);

	if(rdPtr->hwa)
	{
		float angle;
		memcpy(&angle, &object->roc.rcAngle, sizeof(int));
		newObj.angle.SetValue(angle);
	}
	else	
		newObj.angle.SetValue((float)object->roc.rcAngle);
	
	newObj.xPosition.extrapolationMode = rdPtr->extrapolationMethod;
	newObj.yPosition.extrapolationMode = rdPtr->extrapolationMethod;
	newObj.direction.extrapolationMode = rdPtr->extrapolationMethod;
	newObj.angle.extrapolationMode = rdPtr->extrapolationMethod;

	newObj.xPosition.useAcceleration = rdPtr->useAcceleration;
	newObj.yPosition.useAcceleration = rdPtr->useAcceleration;
	newObj.direction.useAcceleration = rdPtr->useAcceleration;
	newObj.angle.useAcceleration = rdPtr->useAcceleration;

	newObj.xPosition.smoothing = rdPtr->XSmoothing;
	newObj.yPosition.smoothing = rdPtr->YSmoothing;
	newObj.direction.smoothing = rdPtr->DirSmoothing;
	newObj.angle.smoothing = rdPtr->AngleSmoothing;

	newObj.xPosition.wrapMode = WRAP_LINEAR;
	newObj.yPosition.wrapMode = WRAP_LINEAR;

	newObj.direction.wrapMode = WRAP_CIRCULAR;
	newObj.angle.wrapMode = WRAP_CIRCULAR;

	newObj.direction.wrapValue = 32.0f;
	newObj.angle.wrapValue = 360.0f;

	pair<long,DRObj> newObjPair = pair<long,DRObj>(fixedValue,newObj);
	rdPtr->objects->insert(newObjPair);
	return 0;
}


short WINAPI DLLExport act_removeobject(LPRDATA rdPtr, long param1, long param2)
{
	LPRO object = (LPRO)CNC_GetParameter(rdPtr);;
	long fixedValue = FixedVal(object);

	//Find the object and then delete it
	DRMap::iterator it = rdPtr->objects->begin();
	DRMap::iterator end = rdPtr->objects->end();
	for(; it != end; ++it)
		if(it->second.fixedValue == fixedValue)
		{
			rdPtr->objects->erase(it);
			return 0;
		}
	return 0;
}

short WINAPI DLLExport act_updateposition(LPRDATA rdPtr, long param1, long param2)
{
	LPRO object = (LPRO)CNC_GetParameter(rdPtr);;
	long fixedValue = FixedVal(object);
	DRMap::iterator find = rdPtr->objects->find(fixedValue);
	if(find == rdPtr->objects->end())
		return 0;

	DRObj & obj = find->second;
	float x = RecastToFloat(CNC_GetFloatParameter(rdPtr));
	float y = RecastToFloat(CNC_GetFloatParameter(rdPtr));

	obj.xPosition.UpdateValue(x, rdPtr->time);
	obj.yPosition.UpdateValue(y, rdPtr->time);
	return 0;
}

short WINAPI DLLExport act_updatex(LPRDATA rdPtr, long param1, long param2)
{
	LPRO object = (LPRO)CNC_GetParameter(rdPtr);;
	long fixedValue = FixedVal(object);
	DRMap::iterator find = rdPtr->objects->find(fixedValue);
	if(find == rdPtr->objects->end())
		return 0;

	DRObj & obj = find->second;
	float x = RecastToFloat(CNC_GetFloatParameter(rdPtr));
	obj.xPosition.UpdateValue(x, rdPtr->time);
	return 0;
}

short WINAPI DLLExport act_updatey(LPRDATA rdPtr, long param1, long param2)
{
	LPRO object = (LPRO)CNC_GetParameter(rdPtr);;
	long fixedValue = FixedVal(object);
	DRMap::iterator find = rdPtr->objects->find(fixedValue);
	if(find == rdPtr->objects->end())
		return 0;

	DRObj & obj = find->second;
	float y = RecastToFloat(CNC_GetFloatParameter(rdPtr));
	obj.yPosition.UpdateValue(y, rdPtr->time);
	return 0;
}

short WINAPI DLLExport act_updatedir(LPRDATA rdPtr, long param1, long param2)
{
	LPRO object = (LPRO)CNC_GetParameter(rdPtr);;
	long fixedValue = FixedVal(object);
	DRMap::iterator find = rdPtr->objects->find(fixedValue);
	if(find == rdPtr->objects->end())
		return 0;

	DRObj & obj = find->second;
	float dir = RecastToFloat(CNC_GetFloatParameter(rdPtr));
	obj.direction.UpdateValue(dir, rdPtr->time);
	return 0;
}

short WINAPI DLLExport act_updateangle(LPRDATA rdPtr, long param1, long param2)
{
	LPRO object = (LPRO)CNC_GetParameter(rdPtr);;
	long fixedValue = FixedVal(object);
	DRMap::iterator find = rdPtr->objects->find(fixedValue);
	if(find == rdPtr->objects->end())
		return 0;

	DRObj & obj = find->second;
	float angle = RecastToFloat(CNC_GetFloatParameter(rdPtr));
	obj.angle.UpdateValue(angle, rdPtr->time);
	return 0;
}

//===================
// MOVEMENT HINTS
//===================

short WINAPI DLLExport act_setx(LPRDATA rdPtr, long param1, long param2)
{
	LPRO object = (LPRO)CNC_GetParameter(rdPtr);;
	long fixedValue = FixedVal(object);
	DRMap::iterator find = rdPtr->objects->find(fixedValue);
	if(find == rdPtr->objects->end())
		return 0;

	DRObj & obj = find->second;
	float x = RecastToFloat(CNC_GetFloatParameter(rdPtr));
	obj.xPosition.SetValue(x);
	return 0;
}

short WINAPI DLLExport act_sety(LPRDATA rdPtr, long param1, long param2)
{
	LPRO object = (LPRO)CNC_GetParameter(rdPtr);;
	long fixedValue = FixedVal(object);
	DRMap::iterator find = rdPtr->objects->find(fixedValue);
	if(find == rdPtr->objects->end())
		return 0;

	DRObj & obj = find->second;
	float y = RecastToFloat(CNC_GetFloatParameter(rdPtr));
	obj.yPosition.SetValue(y);
	return 0;
}

short WINAPI DLLExport act_setdir(LPRDATA rdPtr, long param1, long param2)
{
	LPRO object = (LPRO)CNC_GetParameter(rdPtr);;
	long fixedValue = FixedVal(object);
	DRMap::iterator find = rdPtr->objects->find(fixedValue);
	if(find == rdPtr->objects->end())
		return 0;

	DRObj & obj = find->second;
	float dir = RecastToFloat(CNC_GetFloatParameter(rdPtr));
	obj.direction.SetValue(dir);
	return 0;
}

short WINAPI DLLExport act_setangle(LPRDATA rdPtr, long param1, long param2)
{
	LPRO object = (LPRO)CNC_GetParameter(rdPtr);;
	long fixedValue = FixedVal(object);
	DRMap::iterator find = rdPtr->objects->find(fixedValue);
	if(find == rdPtr->objects->end())
		return 0;

	DRObj & obj = find->second;
	float angle = RecastToFloat(CNC_GetFloatParameter(rdPtr));
	obj.angle.SetValue(angle);
	return 0;
}

short WINAPI DLLExport act_setxspeed(LPRDATA rdPtr, long param1, long param2)
{
	LPRO object = (LPRO)CNC_GetParameter(rdPtr);;
	long fixedValue = FixedVal(object);
	DRMap::iterator find = rdPtr->objects->find(fixedValue);
	if(find == rdPtr->objects->end())
		return 0;

	DRObj & obj = find->second;
	float xspeed = RecastToFloat(CNC_GetFloatParameter(rdPtr));
	obj.xPosition.SetSpeed(xspeed);
	return 0;
}

short WINAPI DLLExport act_setyspeed(LPRDATA rdPtr, long param1, long param2)
{
	LPRO object = (LPRO)CNC_GetParameter(rdPtr);;
	long fixedValue = FixedVal(object);
	DRMap::iterator find = rdPtr->objects->find(fixedValue);
	if(find == rdPtr->objects->end())
		return 0;

	DRObj & obj = find->second;
	float yspeed = RecastToFloat(CNC_GetFloatParameter(rdPtr));
	obj.yPosition.SetSpeed(yspeed);
	return 0;
}

short WINAPI DLLExport act_setdirspeed(LPRDATA rdPtr, long param1, long param2)
{
	LPRO object = (LPRO)CNC_GetParameter(rdPtr);;
	long fixedValue = FixedVal(object);
	DRMap::iterator find = rdPtr->objects->find(fixedValue);
	if(find == rdPtr->objects->end())
		return 0;

	DRObj & obj = find->second;
	float dirspeed = RecastToFloat(CNC_GetFloatParameter(rdPtr));
	obj.direction.SetSpeed(dirspeed);
	return 0;
}

short WINAPI DLLExport act_setanglespeed(LPRDATA rdPtr, long param1, long param2)
{
	LPRO object = (LPRO)CNC_GetParameter(rdPtr);;
	long fixedValue = FixedVal(object);
	DRMap::iterator find = rdPtr->objects->find(fixedValue);
	if(find == rdPtr->objects->end())
		return 0;

	DRObj & obj = find->second;
	float anglespeed = RecastToFloat(CNC_GetFloatParameter(rdPtr));
	obj.angle.SetSpeed(anglespeed);
	return 0;
}

short WINAPI DLLExport act_objwasstopped(LPRDATA rdPtr, long param1, long param2)
{
	LPRO object = (LPRO)CNC_GetParameter(rdPtr);;
	long fixedValue = FixedVal(object);
	DRMap::iterator find = rdPtr->objects->find(fixedValue);
	if(find == rdPtr->objects->end())
		return 0;

	DRObj & obj = find->second;
	obj.xPosition.SetValue((float)object->roHo.hoX);
	obj.yPosition.SetValue((float)object->roHo.hoY);
	return 0;
}

short WINAPI DLLExport act_objbounced(LPRDATA rdPtr, long param1, long param2)
{
	LPRO object = (LPRO)CNC_GetParameter(rdPtr);;
	long fixedValue = FixedVal(object);
	DRMap::iterator find = rdPtr->objects->find(fixedValue);
	if(find == rdPtr->objects->end())
		return 0;

	DRObj & obj = find->second;
	obj.xPosition.SetValue((float)object->roHo.hoX);
	obj.yPosition.SetValue((float)object->roHo.hoY);
	obj.direction.SetValue((float)object->roc.rcDir);
	return 0;
}

  ////////////////////////////
 /////  ALL PARAMETERS  /////
////////////////////////////

short WINAPI DLLExport act_setobjextrapolationmode(LPRDATA rdPtr, long param1, long param2)
{
	LPRO object = (LPRO)CNC_GetParameter(rdPtr);
	int mode = CNC_GetParameter(rdPtr);
	DRMap::iterator find = rdPtr->objects->find(FixedVal(object));
	if(find == rdPtr->objects->end()) return 0;
	DRObj & obj = find->second;
	
	mode = min(max(mode, 0),1);

	obj.xPosition.extrapolationMode = mode;
	obj.yPosition.extrapolationMode = mode;
	obj.direction.extrapolationMode = mode;
	obj.angle.extrapolationMode = mode;
	return 0;
}

short WINAPI DLLExport act_setobjaccelerationmode(LPRDATA rdPtr, long param1, long param2)
{
	LPRO object = (LPRO)CNC_GetParameter(rdPtr);
	int mode = CNC_GetParameter(rdPtr);
	DRMap::iterator find = rdPtr->objects->find(FixedVal(object));
	if(find == rdPtr->objects->end()) return 0;
	DRObj & obj = find->second;
	
	bool uA = (mode == 1);
	obj.xPosition.useAcceleration = uA;
	obj.yPosition.useAcceleration = uA;
	obj.direction.useAcceleration = uA;
	obj.angle.useAcceleration = uA;
	return 0;
}

short WINAPI DLLExport act_setobjmovementsmoothing(LPRDATA rdPtr, long param1, long param2)
{
	LPRO object = (LPRO)CNC_GetParameter(rdPtr);
	float smoothing = RecastToFloat(CNC_GetFloatParameter(rdPtr));
	DRMap::iterator find = rdPtr->objects->find(FixedVal(object));
	if(find == rdPtr->objects->end()) return 0;
	DRObj & obj = find->second;

	obj.xPosition.smoothing = smoothing;
	obj.yPosition.smoothing = smoothing;
	obj.direction.smoothing = smoothing;
	obj.angle.smoothing = smoothing;
	return 0;
}

  ////////////////////////
 /////  X MOVEMENT  /////
////////////////////////

short WINAPI DLLExport act_setobjxextrapolationmode(LPRDATA rdPtr, long param1, long param2)
{
	LPRO object = (LPRO)CNC_GetParameter(rdPtr);
	int mode = CNC_GetParameter(rdPtr);
	DRMap::iterator find = rdPtr->objects->find(FixedVal(object));
	if(find == rdPtr->objects->end()) return 0;
	DRObj & obj = find->second;
	
	obj.xPosition.extrapolationMode = min(max(mode, 0),1);
	return 0;
}

short WINAPI DLLExport act_setobjxaccelerationmode(LPRDATA rdPtr, long param1, long param2)
{
	LPRO object = (LPRO)CNC_GetParameter(rdPtr);
	int mode = CNC_GetParameter(rdPtr);
	DRMap::iterator find = rdPtr->objects->find(FixedVal(object));
	if(find == rdPtr->objects->end()) return 0;
	DRObj & obj = find->second;
	
	obj.xPosition.useAcceleration = (mode == 1);
	return 0;
}

short WINAPI DLLExport act_setobjxsmootging(LPRDATA rdPtr, long param1, long param2)
{
	LPRO object = (LPRO)CNC_GetParameter(rdPtr);
	float smoothing = RecastToFloat(CNC_GetFloatParameter(rdPtr));
	DRMap::iterator find = rdPtr->objects->find(FixedVal(object));
	if(find == rdPtr->objects->end()) return 0;
	DRObj & obj = find->second;

	obj.xPosition.smoothing = smoothing;
	return 0;
}

  ////////////////////////
 /////  Y MOVEMENT  /////
////////////////////////

short WINAPI DLLExport act_setobjyextrapolationmode(LPRDATA rdPtr, long param1, long param2)
{
	LPRO object = (LPRO)CNC_GetParameter(rdPtr);
	int mode = CNC_GetParameter(rdPtr);
	DRMap::iterator find = rdPtr->objects->find(FixedVal(object));
	if(find == rdPtr->objects->end()) return 0;
	DRObj & obj = find->second;
	
	obj.yPosition.extrapolationMode = min(max(mode, 0),1);
	return 0;
}

short WINAPI DLLExport act_setobjyaccelerationmode(LPRDATA rdPtr, long param1, long param2)
{
	LPRO object = (LPRO)CNC_GetParameter(rdPtr);
	int mode = CNC_GetParameter(rdPtr);
	DRMap::iterator find = rdPtr->objects->find(FixedVal(object));
	if(find == rdPtr->objects->end()) return 0;
	DRObj & obj = find->second;
	
	obj.yPosition.useAcceleration = (mode == 1);
	return 0;
}

short WINAPI DLLExport act_setobjysmootging(LPRDATA rdPtr, long param1, long param2)
{
	LPRO object = (LPRO)CNC_GetParameter(rdPtr);
	float smoothing = RecastToFloat(CNC_GetFloatParameter(rdPtr));
	DRMap::iterator find = rdPtr->objects->find(FixedVal(object));
	if(find == rdPtr->objects->end()) return 0;
	DRObj & obj = find->second;

	obj.yPosition.smoothing = smoothing;
	return 0;
}

short WINAPI DLLExport act_setobjdirextrapolationmode(LPRDATA rdPtr, long param1, long param2)
{
	LPRO object = (LPRO)CNC_GetParameter(rdPtr);
	int mode = CNC_GetParameter(rdPtr);
	DRMap::iterator find = rdPtr->objects->find(FixedVal(object));
	if(find == rdPtr->objects->end()) return 0;
	DRObj & obj = find->second;
	
	obj.direction.extrapolationMode = min(max(mode, 0),1);
	return 0;
}

short WINAPI DLLExport act_setobjdiraccelerationmode(LPRDATA rdPtr, long param1, long param2)
{
	LPRO object = (LPRO)CNC_GetParameter(rdPtr);
	int mode = CNC_GetParameter(rdPtr);
	DRMap::iterator find = rdPtr->objects->find(FixedVal(object));
	if(find == rdPtr->objects->end()) return 0;
	DRObj & obj = find->second;
	
	obj.direction.useAcceleration = (mode == 1);
	return 0;
}

short WINAPI DLLExport act_setobjdirsmootging(LPRDATA rdPtr, long param1, long param2)
{
	LPRO object = (LPRO)CNC_GetParameter(rdPtr);
	float smoothing = RecastToFloat(CNC_GetFloatParameter(rdPtr));
	DRMap::iterator find = rdPtr->objects->find(FixedVal(object));
	if(find == rdPtr->objects->end()) return 0;
	DRObj & obj = find->second;

	obj.direction.smoothing = smoothing;
	return 0;
}

  ////////////////////////////
 /////  ANGLE MOVEMENT  /////
////////////////////////////


short WINAPI DLLExport act_setobjangleextrapolationmode(LPRDATA rdPtr, long param1, long param2)
{
	LPRO object = (LPRO)CNC_GetParameter(rdPtr);
	int mode = CNC_GetParameter(rdPtr);
	DRMap::iterator find = rdPtr->objects->find(FixedVal(object));
	if(find == rdPtr->objects->end()) return 0;
	DRObj & obj = find->second;
	
	obj.angle.extrapolationMode = min(max(mode, 0),1);
	return 0;	
}

short WINAPI DLLExport act_setobjangleaccelerationmode(LPRDATA rdPtr, long param1, long param2)
{
	LPRO object = (LPRO)CNC_GetParameter(rdPtr);
	int mode = CNC_GetParameter(rdPtr);
	DRMap::iterator find = rdPtr->objects->find(FixedVal(object));
	if(find == rdPtr->objects->end()) return 0;
	DRObj & obj = find->second;
	
	obj.angle.useAcceleration = (mode == 1);
	return 0;
}

short WINAPI DLLExport act_setobjanglesmootging(LPRDATA rdPtr, long param1, long param2)
{
	LPRO object = (LPRO)CNC_GetParameter(rdPtr);
	float smoothing = RecastToFloat(CNC_GetFloatParameter(rdPtr));
	DRMap::iterator find = rdPtr->objects->find(FixedVal(object));
	if(find == rdPtr->objects->end()) return 0;
	DRObj & obj = find->second;

	obj.angle.smoothing = smoothing;
	return 0;
}

short WINAPI DLLExport act_pushobjoutofobstacle(LPRDATA rdPtr, long param1, long param2)
{
	LPRO object = (LPRO)CNC_GetParameter(rdPtr);
	DRMap::iterator find = rdPtr->objects->find(FixedVal(object));
	if(find == rdPtr->objects->end()) return 0;
	DRObj & obj = find->second;
	rdPtr->objectToPush = object;

	int x = object->roHo.hoX;
	int y = object->roHo.hoY;
	int oX = obj.oldX;
	int oY = obj.oldY;
	int dX = x-oX;
	int dY = y-oY;

	//No previous position recorded, cannot reliably push out
	if(dX == 0 && dY == 0)
		return 0;

	int distance = (int)ceil(sqrt((float)(dX*dX+dY*dY)));

	int lowerbound = 0;
	int upperbound = distance;
	int current = distance/2;
	float progress = 0.5f;
	object->roc.rcChanged = true;

	//Push out, maximum 20 iterations
	for(int i=0; i<20; ++i)
	{
		int nX = (int)(oX+dX*progress);
		int nY = (int)(oY+dY*progress);

		//If it's done pusing out
		if(object->roHo.hoX == nX && object->roHo.hoY == nY)
			break;
		
		object->roHo.hoX = nX;
		object->roHo.hoY = nY;
		object->roc.rcCheckCollides = 1;

		rdPtr->isInObstacle = false;
		callRunTimeFunction(rdPtr, RFUNCTION_GENERATEEVENT, CND_OBJISINOBSTACLE, 0);

		if(rdPtr->isInObstacle)
			upperbound = current;
		else
			lowerbound = current;

		current = (upperbound+lowerbound)/2;
		progress = current/(float)distance;
	}

	obj.xPosition.SetValue((float)object->roHo.hoX);
	obj.yPosition.SetValue((float)object->roHo.hoY);

	rdPtr->objectToPush = NULL;

	return 0;
}

short WINAPI DLLExport act_objectisinsideobstacle(LPRDATA rdPtr, long param1, long param2)
{
	rdPtr->isInObstacle = true;
	return 0;
}


// ============================================================================
//
// EXPRESSIONS ROUTINES
// 
// ============================================================================

long WINAPI DLLExport exp_numobjects(LPRDATA rdPtr,long param1)
{
	return rdPtr->objects->size();
}

long WINAPI DLLExport exp_predictedx(LPRDATA rdPtr,long param1)
{
	rdPtr->rHo.hoFlags |= HOF_FLOAT;
	long fixedValue = CNC_GetFirstExpressionParameter(rdPtr, param1, TYPE_INT);
	DRMap::iterator find = rdPtr->objects->find(fixedValue);
	if(find == rdPtr->objects->end())
		return 0;
	DRObj & obj = find->second;
	return RecastToLong(obj.xPosition.nextPos);
}

long WINAPI DLLExport exp_predictedy(LPRDATA rdPtr,long param1)
{
	rdPtr->rHo.hoFlags |= HOF_FLOAT;
	long fixedValue = CNC_GetFirstExpressionParameter(rdPtr, param1, TYPE_INT);
	DRMap::iterator find = rdPtr->objects->find(fixedValue);
	if(find == rdPtr->objects->end())
		return 0;
	DRObj & obj = find->second;
	return RecastToLong(obj.yPosition.nextPos);
}

long WINAPI DLLExport exp_predicteddir(LPRDATA rdPtr,long param1)
{
	rdPtr->rHo.hoFlags |= HOF_FLOAT;
	long fixedValue = CNC_GetFirstExpressionParameter(rdPtr, param1, TYPE_INT);
	DRMap::iterator find = rdPtr->objects->find(fixedValue);
	if(find == rdPtr->objects->end())
		return 0;
	DRObj & obj = find->second;
	return RecastToLong(obj.direction.nextPos);
}

long WINAPI DLLExport exp_predictedangle(LPRDATA rdPtr,long param1)
{
	rdPtr->rHo.hoFlags |= HOF_FLOAT;
	long fixedValue = CNC_GetFirstExpressionParameter(rdPtr, param1, TYPE_INT);
	DRMap::iterator find = rdPtr->objects->find(fixedValue);
	if(find == rdPtr->objects->end())
		return 0;
	DRObj & obj = find->second;
	return RecastToLong(obj.angle.nextPos);
}

long WINAPI DLLExport exp_xspeed(LPRDATA rdPtr,long param1)
{
	rdPtr->rHo.hoFlags |= HOF_FLOAT;
	long fixedValue = CNC_GetFirstExpressionParameter(rdPtr, param1, TYPE_INT);
	DRMap::iterator find = rdPtr->objects->find(fixedValue);
	if(find == rdPtr->objects->end())
		return 0;
	DRObj & obj = find->second;
	return RecastToLong(obj.xPosition.oldSpeed);
}

long WINAPI DLLExport exp_yspeed(LPRDATA rdPtr,long param1)
{
	rdPtr->rHo.hoFlags |= HOF_FLOAT;
	long fixedValue = CNC_GetFirstExpressionParameter(rdPtr, param1, TYPE_INT);
	DRMap::iterator find = rdPtr->objects->find(fixedValue);
	if(find == rdPtr->objects->end())
		return 0;
	DRObj & obj = find->second;
	return RecastToLong(obj.yPosition.oldSpeed);
}

long WINAPI DLLExport exp_dirspeed(LPRDATA rdPtr,long param1)
{
	rdPtr->rHo.hoFlags |= HOF_FLOAT;
	long fixedValue = CNC_GetFirstExpressionParameter(rdPtr, param1, TYPE_INT);
	DRMap::iterator find = rdPtr->objects->find(fixedValue);
	if(find == rdPtr->objects->end())
		return 0;
	DRObj & obj = find->second;
	return RecastToLong(obj.direction.oldSpeed);
}

long WINAPI DLLExport exp_anglespeed(LPRDATA rdPtr,long param1)
{
	rdPtr->rHo.hoFlags |= HOF_FLOAT;
	long fixedValue = CNC_GetFirstExpressionParameter(rdPtr, param1, TYPE_INT);
	DRMap::iterator find = rdPtr->objects->find(fixedValue);
	if(find == rdPtr->objects->end())
		return 0;
	DRObj & obj = find->second;
	return RecastToLong(obj.angle.oldSpeed);
}

long WINAPI DLLExport exp_xsmoothing(LPRDATA rdPtr,long param1)
{
	rdPtr->rHo.hoFlags |= HOF_FLOAT;
	long fixedValue = CNC_GetFirstExpressionParameter(rdPtr, param1, TYPE_INT);
	DRMap::iterator find = rdPtr->objects->find(fixedValue);
	if(find == rdPtr->objects->end())
		return 0;
	DRObj & obj = find->second;
	return RecastToLong(obj.xPosition.smoothing);
}

long WINAPI DLLExport exp_ysmoothing(LPRDATA rdPtr,long param1)
{
	rdPtr->rHo.hoFlags |= HOF_FLOAT;
	long fixedValue = CNC_GetFirstExpressionParameter(rdPtr, param1, TYPE_INT);
	DRMap::iterator find = rdPtr->objects->find(fixedValue);
	if(find == rdPtr->objects->end())
		return 0;
	DRObj & obj = find->second;
	return RecastToLong(obj.yPosition.smoothing);
}

long WINAPI DLLExport exp_dirsmoothing(LPRDATA rdPtr,long param1)
{
	rdPtr->rHo.hoFlags |= HOF_FLOAT;
	long fixedValue = CNC_GetFirstExpressionParameter(rdPtr, param1, TYPE_INT);
	DRMap::iterator find = rdPtr->objects->find(fixedValue);
	if(find == rdPtr->objects->end())
		return 0;
	DRObj & obj = find->second;
	return RecastToLong(obj.direction.smoothing);
}

long WINAPI DLLExport exp_anglesmoothing(LPRDATA rdPtr,long param1)
{
	rdPtr->rHo.hoFlags |= HOF_FLOAT;
	long fixedValue = CNC_GetFirstExpressionParameter(rdPtr, param1, TYPE_INT);
	DRMap::iterator find = rdPtr->objects->find(fixedValue);
	if(find == rdPtr->objects->end())
		return 0;
	DRObj & obj = find->second;
	return RecastToLong(obj.angle.smoothing);
}

long WINAPI DLLExport exp_movespeed(LPRDATA rdPtr,long param1)
{
	rdPtr->rHo.hoFlags |= HOF_FLOAT;
	DRMap::iterator find = rdPtr->objects->find(CNC_GetFirstExpressionParameter(rdPtr, param1, TYPE_INT));
	if(find == rdPtr->objects->end()) return 0;
	DRObj & obj = find->second;

	float speed = sqrt( obj.xPosition.oldSpeed*obj.xPosition.oldSpeed + obj.yPosition.oldSpeed*obj.yPosition.oldSpeed );
	return RecastToLong(speed);
}

float ToRadians(float degrees)
{
	return degrees * (float)PI/180.0f;
}

float ToDegrees(float radians)
{
	float ret = radians * 180.0f/(float)PI;
	if (ret < 0)
		return 360+ret;
	else
		return ret;
}

long WINAPI DLLExport exp_moveddirection(LPRDATA rdPtr,long param1)
{
	DRMap::iterator find = rdPtr->objects->find(CNC_GetFirstExpressionParameter(rdPtr, param1, TYPE_INT));
	if(find == rdPtr->objects->end()) return 0;
	DRObj & obj = find->second;

	if(obj.xPosition.oldSpeed < 0.001f && obj.yPosition.oldSpeed < 0.001f)
		(int)(obj.previousAngle/11.25f);

	obj.previousAngle = 360.0f - ToDegrees(atan2(obj.yPosition.oldSpeed, obj.xPosition.oldSpeed));
	return (int)(obj.previousAngle/11.25f);
}

long WINAPI DLLExport exp_movedangle(LPRDATA rdPtr,long param1)
{
	rdPtr->rHo.hoFlags |= HOF_FLOAT;
	DRMap::iterator find = rdPtr->objects->find(CNC_GetFirstExpressionParameter(rdPtr, param1, TYPE_INT));
	if(find == rdPtr->objects->end()) return 0;
	DRObj & obj = find->second;

	if(obj.xPosition.oldSpeed < 0.001f && obj.yPosition.oldSpeed < 0.001f)
		return RecastToLong(obj.previousAngle);

	obj.previousAngle = 360.0f - ToDegrees(atan2(obj.yPosition.oldSpeed, obj.xPosition.oldSpeed));
	return RecastToLong(obj.previousAngle);
}


// ----------------------------------------------------------
// Condition / Action / Expression jump table
// ----------------------------------------------------------
// Contains the address inside the extension of the different
// routines that handle the action, conditions and expressions.
// Located at the end of the source for convinience
// Must finish with a 0
//
long (WINAPI * ConditionJumps[])(LPRDATA rdPtr, long param1, long param2) = 
			{ 
			cnd_objisinobstacle,
			0
			};
	
short (WINAPI * ActionJumps[])(LPRDATA rdPtr, long param1, long param2) =
			{
			act_addobject,
			act_removeobject,
			act_updateposition,
			act_updatex,
			act_updatey,
			act_updatedir,
			act_updateangle,
			act_setx,
			act_sety,
			act_setdir,
			act_setangle,
			act_setxspeed,
			act_setyspeed,
			act_setdirspeed,
			act_setanglespeed,
			act_objwasstopped,
			act_objbounced,
			act_setobjextrapolationmode,
			act_setobjaccelerationmode,
			act_setobjmovementsmoothing,
			act_setobjxextrapolationmode,
			act_setobjxaccelerationmode,
			act_setobjxsmootging,
			act_setobjyextrapolationmode,
			act_setobjyaccelerationmode,
			act_setobjysmootging,
			act_setobjdirextrapolationmode,
			act_setobjdiraccelerationmode,
			act_setobjdirsmootging,
			act_setobjangleextrapolationmode,
			act_setobjangleaccelerationmode,
			act_setobjanglesmootging,
			act_pushobjoutofobstacle,
			act_objectisinsideobstacle,
			0
			};

long (WINAPI * ExpressionJumps[])(LPRDATA rdPtr, long param) = 
			{     
			exp_numobjects,
			exp_predictedx,
			exp_predictedy,
			exp_predicteddir,
			exp_predictedangle,
			exp_xspeed,
			exp_yspeed,
			exp_dirspeed,
			exp_anglespeed,
			exp_xsmoothing,
			exp_ysmoothing,
			exp_dirsmoothing,
			exp_anglesmoothing,
			exp_movespeed,
			exp_moveddirection,
			exp_movedangle,
			0
			};











