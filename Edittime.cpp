
// ============================================================================
//
// This file contains routines that are handled only during the Edittime,
// under the Frame and Event editors.
//
// Including creating, display, and setting up your object.
// 
// ============================================================================

// Common
#include	"common.h"

#if !defined(RUN_ONLY)

// PROPERTIES /////////////////////////////////////////////////////////////////

enum {
	PROPID_SETTINGS = PROPID_EXTITEM_CUSTOM_FIRST,
	PROPID_EXTRAPOLATION,
	PROPID_USEACCELERATION,
	PROPID_XSMOOTHING,
	PROPID_YSMOOTHING,
	PROPID_DIRSMOOTHING,
	PROPID_ANGLESMOOTHING
};

LPCSTR ExtrapolationMethod[] =
	{
	0,
	MAKEINTRESOURCE(IDS_LINEAR),
	MAKEINTRESOURCE(IDS_CUBIC),
	NULL
	};

int    smoothingRange[] = { 0, 10 };

PropData Properties[] =
{
	PropData_ComboBox	( PROPID_EXTRAPOLATION, IDS_EXTRAPOLATION, IDS_EXTRAPOLATION_DESC, ExtrapolationMethod ),
	PropData_CheckBox	( PROPID_USEACCELERATION, IDS_USEACCELERATION, IDS_USEACCELERATION_DESC ),
	PropData_SpinEdit	( PROPID_XSMOOTHING, IDS_XSMOOTHING, IDS_XSMOOTHING_DESC, &smoothingRange ),
	PropData_SpinEdit	( PROPID_YSMOOTHING, IDS_YSMOOTHING, IDS_YSMOOTHING_DESC, &smoothingRange ),
	PropData_SpinEdit	( PROPID_DIRSMOOTHING, IDS_DIRSMOOTHING, IDS_DIRSMOOTHING_DESC, &smoothingRange ),
	PropData_SpinEdit	( PROPID_ANGLESMOOTHING, IDS_ANGLESMOOTHING, IDS_ANGLESMOOTHING_DESC, &smoothingRange ),

	PropData_End()
};


// Structure defined to pass edptr and mv into setup box
typedef struct tagSetP
{
	EDITDATA _far *	edpt;
	mv _far	*		kv;
} setupParams;

#endif // !defined(RUN_ONLY)


// -----------------
// GetObjInfos
// -----------------
// Return object info
//
// Info displayed in the object's About properties
// Note: ObjComment is also displayed in the Quick Description box in the Insert Object dialog box
//
void WINAPI	DLLExport GetObjInfos (mv _far *mV, LPEDATA edPtr, LPSTR ObjName, LPSTR ObjAuthor, LPSTR ObjCopyright, LPSTR ObjComment, LPSTR ObjHttp)
{
#ifndef RUN_ONLY
	// Name
	LoadString(hInstLib, IDST_OBJNAME,ObjName, 255);

	// Author
	LoadString(hInstLib, IDST_AUTHOR,ObjAuthor,255);

	// Copyright
	LoadString(hInstLib, IDST_COPYRIGHT,ObjCopyright,255);

	// Comment
	LoadString(hInstLib, IDST_COMMENT,ObjComment,1024);

	// Internet address
	LoadString(hInstLib, IDST_HTTP,ObjHttp,255);
#endif // !defined(RUN_ONLY)
}

// -----------------
// GetHelpFileName
// -----------------
// Returns the help filename of the object.
//
LPCSTR WINAPI GetHelpFileName()
{
#ifndef RUN_ONLY
	// Return a file without path if your help file can be loaded by the MMF help file.
//	return "MyExt.chm";

	// Or return the path of your file, relatively to the MMF directory
	// if your file is not loaded by the MMF help file.
	return "Help\\DeadReckoning.chm";
#else
	return NULL;
#endif // !defined(RUN_ONLY)
}



// --------------------
// CreateObject
// --------------------
// Called when you choose "Create new object". It should display the setup box 
// and initialize everything in the datazone.

int WINAPI DLLExport CreateObject(mv _far *mV, fpLevObj loPtr, LPEDATA edPtr)
{
#ifndef RUN_ONLY
	// Check compatibility
	if ( IS_COMPATIBLE(mV) )
	{
		edPtr->extrapolationMethod = 0;
		edPtr->useAcceleration = false;
		edPtr->XSmoothing = 0;
		edPtr->YSmoothing = 0;
		edPtr->DirSmoothing = 0;
		edPtr->AngleSmoothing = 0;
	}
#endif // !defined(RUN_ONLY)

	// Error
	return -1;
}

// --------------------
// EditObject
// --------------------
// Called when the user selects the Edit command in the object's popup menu
//
BOOL WINAPI EditObject (mv _far *mV, fpObjInfo oiPtr, fpLevObj loPtr, LPEDATA edPtr)
{
	return FALSE;
}


// --------------------
// PutObject
// --------------------
// Called when each individual object is dropped in the frame.
//
void WINAPI	DLLExport PutObject(mv _far *mV, fpLevObj loPtr, LPEDATA edPtr, ushort cpt)
{
#ifndef RUN_ONLY
#endif // !defined(RUN_ONLY)
}

// --------------------
// RemoveObject
// --------------------
// Called when each individual object is removed from the frame.
//
void WINAPI	DLLExport RemoveObject(mv _far *mV, fpLevObj loPtr, LPEDATA edPtr, ushort cpt)
{
#ifndef RUN_ONLY
	// Is the last object removed?
    if (0 == cpt)
	{
		// Do whatever necessary to remove our data
	}
#endif // !defined(RUN_ONLY)
}

// --------------------
// DuplicateObject
// --------------------
// Called when an object is created from another one (note: should be called CloneObject instead...)
//
void WINAPI DLLExport DuplicateObject(mv __far *mV, fpObjInfo oiPtr, LPEDATA edPtr)
{
#ifndef RUN_ONLY
#endif // !defined(RUN_ONLY)
}

// --------------------
// GetObjectRect
// --------------------
// Returns the size of the rectangle of the object in the frame editor.
//
void WINAPI DLLExport GetObjectRect(mv _far *mV, RECT FAR *rc, fpLevObj loPtr, LPEDATA edPtr)
{
#ifndef RUN_ONLY
	rc->right = rc->left + 32;	// edPtr->swidth;
	rc->bottom = rc->top + 32;	// edPtr->sheight;
#endif // !defined(RUN_ONLY)
	return;
}


// --------------------
// IsTransparent
// --------------------
// This routine tells CC&C if the mouse pointer is over a transparent zone of the object.
// 

extern "C" BOOL WINAPI DLLExport IsTransparent(mv _far *mV, fpLevObj loPtr, LPEDATA edPtr, int dx, int dy)
{
#ifndef RUN_ONLY
	// Write your code here
#endif // !defined(RUN_ONLY)
	return FALSE;
}

// --------------------
// PrepareToWriteObject
// --------------------
// Just before writing the datazone when saving the application, CC&C calls this routine.
// 
void WINAPI	DLLExport PrepareToWriteObject(mv _far *mV, LPEDATA edPtr, fpObjInfo adoi)
{
#ifndef RUN_ONLY
	// Write your code here
#endif // !defined(RUN_ONLY)
}

// --------------------
// GetFilters
// --------------------

BOOL WINAPI GetFilters(LPMV mV, LPEDATA edPtr, DWORD dwFlags, LPVOID pReserved)
{
	return FALSE;
}

// --------------------
// UsesFile
// --------------------
// Triggers when a file is dropped onto the frame
// Return TRUE if you can create an object from the given file
//
BOOL WINAPI	DLLExport UsesFile (LPMV mV, LPSTR fileName)
{
	BOOL r = FALSE;
	return r;
}


// --------------------
// CreateFromFile
// --------------------
// Creates a new object from file
//
void WINAPI	DLLExport CreateFromFile (LPMV mV, LPSTR fileName, LPEDATA edPtr)
{
#ifndef RUN_ONLY
	// Initialize your extension data from the given file
//	edPtr->swidth = 32;
//	edPtr->sheight = 32;

	// Example: store the filename
	// strcpy(edPtr->myFileName, fileName);
#endif // !defined(RUN_ONLY)
}

// ============================================================================
//
// PROPERTIES
// 
// ============================================================================

// --------------------
// GetProperties
// --------------------
// Inserts properties into the properties of the object.
//
BOOL WINAPI DLLExport GetProperties(LPMV mV, LPEDATA edPtr, BOOL bMasterItem)
{
#ifndef RUN_ONLY
	mvInsertProps(mV, edPtr, Properties, PROPID_TAB_GENERAL, TRUE);
#endif // !defined(RUN_ONLY)

	// OK
	return TRUE;
}

// --------------------
// ReleaseProperties
// --------------------
// Called when the properties are removed from the property window.
//
void WINAPI DLLExport ReleaseProperties(LPMV mV, LPEDATA edPtr, BOOL bMasterItem)
{
#ifndef RUN_ONLY
	// Write your code here
#endif // !defined(RUN_ONLY)
}

// --------------------
// GetPropCreateParam
// --------------------
// Called when a property is initialized and its creation parameter is NULL (in the PropData).
// Allows you, for example, to change the content of a combobox property according to specific settings in the EDITDATA structure.
//
LPARAM WINAPI DLLExport GetPropCreateParam(LPMV mV, LPEDATA edPtr, UINT nPropID)
{
#ifndef RUN_ONLY
	// Example
	// -------
//	if ( nPropID == PROPID_COMBO )
//	{
//		switch (edPtr->sType)
//		{
//		case TYPE1:
//			return (LPARAM)ComboList1;
//		case TYPE2:
//			return (LPARAM)ComboList2;
//		}
//	}
#endif // !defined(RUN_ONLY)
	return NULL;
}

// ----------------------
// ReleasePropCreateParam
// ----------------------
// Called after a property has been initialized.
// Allows you, for example, to free memory allocated in GetPropCreateParam.
//
void WINAPI DLLExport ReleasePropCreateParam(LPMV mV, LPEDATA edPtr, UINT nPropID, LPARAM lParam)
{
#ifndef RUN_ONLY
#endif // !defined(RUN_ONLY)
}

// --------------------
// GetPropValue
// --------------------
// Returns the value of properties that have a value.
// Note: see GetPropCheck for checkbox properties
//
LPVOID WINAPI DLLExport GetPropValue(LPMV mV, LPEDATA edPtr, UINT nPropID)
{
#ifndef RUN_ONLY
	// Example
	// -------
	switch (nPropID)
	{

	case PROPID_EXTRAPOLATION:
		return new CPropDWordValue(edPtr->extrapolationMethod);
	case PROPID_XSMOOTHING:
		return new CPropDWordValue(edPtr->XSmoothing);
	case PROPID_YSMOOTHING:
		return new CPropDWordValue(edPtr->YSmoothing);
	case PROPID_DIRSMOOTHING:
		return new CPropDWordValue(edPtr->DirSmoothing);
	case PROPID_ANGLESMOOTHING:
		return new CPropDWordValue(edPtr->AngleSmoothing);
	}
#endif // !RUN_ONLY
	return NULL;
}

// --------------------
// GetPropCheck
// --------------------
// Returns the checked state of properties that have a check box.
//
BOOL WINAPI DLLExport GetPropCheck(LPMV mV, LPEDATA edPtr, UINT nPropID)
{
#ifndef RUN_ONLY
	// Example
	// -------
	switch (nPropID) {
//	// Return 0 (unchecked) or 1 (checked)
	case PROPID_USEACCELERATION:
		return edPtr->useAcceleration;
	}

#endif // !RUN_ONLY
	return 0;		// Unchecked
}

// --------------------
// SetPropValue
// --------------------
// This routine is called by MMF after a property has been modified.
//
void WINAPI DLLExport SetPropValue(LPMV mV, LPEDATA edPtr, UINT nPropID, LPVOID lParam)
{
#ifndef RUN_ONLY
	// Gets the pointer to the CPropValue structure
	CPropValue* pValue = (CPropValue*)lParam;
	int value = ((CPropDWordValue*)pValue)->m_dwValue;

	switch (nPropID)
	{
	case PROPID_EXTRAPOLATION:
		edPtr->extrapolationMethod = value; break;
	case PROPID_XSMOOTHING:
		edPtr->XSmoothing = value; break;
	case PROPID_YSMOOTHING:
		edPtr->YSmoothing = value; break;
	case PROPID_DIRSMOOTHING:
		edPtr->DirSmoothing = value; break;
	case PROPID_ANGLESMOOTHING:
		edPtr->AngleSmoothing = value; break;
	}

	// mvInvalidateObject(mV, edPtr);

#endif // !RUN_ONLY
}

// --------------------
// SetPropCheck
// --------------------
// This routine is called by MMF when the user modifies a checkbox in the properties.
//
void WINAPI DLLExport SetPropCheck(LPMV mV, LPEDATA edPtr, UINT nPropID, BOOL nCheck)
{
#ifndef RUN_ONLY
	// Example
	// -------
	switch (nPropID)
	{
	case PROPID_USEACCELERATION:
		edPtr->useAcceleration = (nCheck==1);
		mvRefreshProp(mV, edPtr, PROPID_USEACCELERATION, false);
		break;
	}
#endif // !RUN_ONLY
}

// --------------------
// EditProp
// --------------------
// This routine is called when the user clicks the button of a Button or EditButton property.
//
BOOL WINAPI DLLExport EditProp(LPMV mV, LPEDATA edPtr, UINT nPropID)
{
#ifndef RUN_ONLY

	// Example
	// -------
/*
	if (nPropID==PROPID_EDITCONTENT)
	{
		if ( EditObject(mV, NULL, NULL, edPtr) )
			return TRUE;
	}
*/

#endif // !defined(RUN_ONLY)
	return FALSE;
}

// --------------------
// IsPropEnabled
// --------------------
// This routine returns the enabled state of a property.
//
BOOL WINAPI IsPropEnabled(LPMV mV, LPEDATA edPtr, UINT nPropID)
{
#ifndef RUN_ONLY
	// Example
	// -------
/*
	switch (nPropID) {

	case PROPID_CHECK:
		return (edPtr->nComboIndex != 0);
	}
*/
#endif // !defined(RUN_ONLY)
	return TRUE;
}


// ============================================================================
//
// TEXT PROPERTIES
// 
// ============================================================================

// --------------------
// GetTextCaps
// --------------------
// Return the text capabilities of the object under the frame editor.
//
DWORD WINAPI DLLExport GetTextCaps(mv _far *mV, LPEDATA edPtr)
{
	return 0;	// (TEXT_ALIGN_LEFT|TEXT_ALIGN_HCENTER|TEXT_ALIGN_RIGHT|TEXT_ALIGN_TOP|TEXT_ALIGN_VCENTER|TEXT_ALIGN_BOTTOM|TEXT_FONT|TEXT_COLOR);
}

// --------------------
// GetTextFont
// --------------------
// Return the font used the object.
// Note: the pStyle and cbSize parameters are obsolete and passed for compatibility reasons only.
//
BOOL WINAPI DLLExport GetTextFont(mv _far *mV, LPEDATA edPtr, LPLOGFONT plf, LPSTR pStyle, UINT cbSize)
{
#if !defined(RUN_ONLY)
	// Example: copy LOGFONT structure from EDITDATA
	// memcpy(plf, &edPtr->m_lf, sizeof(LOGFONT));
#endif // !defined(RUN_ONLY)

	return TRUE;
}

// --------------------
// SetTextFont
// --------------------
// Change the font used the object.
// Note: the pStyle parameter is obsolete and passed for compatibility reasons only.
//
BOOL WINAPI DLLExport SetTextFont(mv _far *mV, LPEDATA edPtr, LPLOGFONT plf, LPCSTR pStyle)
{
#if !defined(RUN_ONLY)
	// Example: copy LOGFONT structure to EDITDATA
	// memcpy(&edPtr->m_lf, plf, sizeof(LOGFONT));
#endif // !defined(RUN_ONLY)

	return TRUE;
}

// --------------------
// GetTextClr
// --------------------
// Get the text color of the object.
//
COLORREF WINAPI DLLExport GetTextClr(mv _far *mV, LPEDATA edPtr)
{
	// Example
	return 0;	// edPtr->fontColor;
}

// --------------------
// SetTextClr
// --------------------
// Set the text color of the object.
//
void WINAPI DLLExport SetTextClr(mv _far *mV, LPEDATA edPtr, COLORREF color)
{
	// Example
	//edPtr->fontColor = color;
}

// --------------------
// GetTextAlignment
// --------------------
// Get the text alignment of the object.
//
DWORD WINAPI DLLExport GetTextAlignment(mv _far *mV, LPEDATA edPtr)
{
	DWORD dw = 0;
#if !defined(RUN_ONLY)
	// Example
	// -------
/*	if ( (edPtr->eData.dwFlags & ALIGN_LEFT) != 0 )
		dw |= TEXT_ALIGN_LEFT;
	if ( (edPtr->eData.dwFlags & ALIGN_HCENTER) != 0 )
		dw |= TEXT_ALIGN_HCENTER;
	if ( (edPtr->eData.dwFlags & ALIGN_RIGHT) != 0 )
		dw |= TEXT_ALIGN_RIGHT;
	if ( (edPtr->eData.dwFlags & ALIGN_TOP) != 0 )
		dw |= TEXT_ALIGN_TOP;
	if ( (edPtr->eData.dwFlags & ALIGN_VCENTER) != 0 )
		dw |= TEXT_ALIGN_VCENTER;
	if ( (edPtr->eData.dwFlags & ALIGN_BOTTOM) != 0 )
		dw |= TEXT_ALIGN_BOTTOM;
*/
#endif // !defined(RUN_ONLY)
	return dw;
}

// --------------------
// SetTextAlignment
// --------------------
// Set the text alignment of the object.
//
void WINAPI DLLExport SetTextAlignment(mv _far *mV, LPEDATA edPtr, DWORD dwAlignFlags)
{
#if !defined(RUN_ONLY)
	// Example
	// -------
/*	DWORD dw = edPtr->eData.dwFlags;

	if ( (dwAlignFlags & TEXT_ALIGN_LEFT) != 0 )
		dw = (dw & ~(ALIGN_LEFT|ALIGN_HCENTER|ALIGN_RIGHT)) | ALIGN_LEFT;
	if ( (dwAlignFlags & TEXT_ALIGN_HCENTER) != 0 )
		dw = (dw & ~(ALIGN_LEFT|ALIGN_HCENTER|ALIGN_RIGHT)) | ALIGN_HCENTER;
	if ( (dwAlignFlags & TEXT_ALIGN_RIGHT) != 0 )
		dw = (dw & ~(ALIGN_LEFT|ALIGN_HCENTER|ALIGN_RIGHT)) | ALIGN_RIGHT;

	if ( (dwAlignFlags & TEXT_ALIGN_TOP) != 0 )
		dw = (dw & ~(ALIGN_TOP|ALIGN_VCENTER|ALIGN_BOTTOM)) | ALIGN_TOP;
	if ( (dwAlignFlags & TEXT_ALIGN_VCENTER) != 0 )
		dw = (dw & ~(ALIGN_TOP|ALIGN_VCENTER|ALIGN_BOTTOM)) | ALIGN_VCENTER;
	if ( (dwAlignFlags & TEXT_ALIGN_BOTTOM) != 0 )
		dw = (dw & ~(ALIGN_TOP|ALIGN_VCENTER|ALIGN_BOTTOM)) | ALIGN_BOTTOM;

	edPtr->eData.dwFlags = dw;
*/
#endif // !defined(RUN_ONLY)
}


// ============================================================================
//
// ROUTINES USED UNDER EVENT / TIME / STEP-THROUGH EDITOR
// You should not need to change these routines
// 
// ============================================================================

// -----------------
// menucpy
// -----------------
// Internal routine used later, copy one menu onto another
// 
#ifndef RUN_ONLY
void menucpy(HMENU hTargetMenu, HMENU hSourceMenu)
{
	int			n, id, nMn;
	NPSTR		strBuf;
	HMENU		hSubMenu;

	nMn = GetMenuItemCount(hSourceMenu);
	strBuf = (NPSTR)LocalAlloc(LPTR, 80);
	for (n=0; n<nMn; n++)
	{
		if (0 == (id = GetMenuItemID(hSourceMenu, n)))
			AppendMenu(hTargetMenu, MF_SEPARATOR, 0, 0L);
		else
		{
			GetMenuString(hSourceMenu, n, strBuf, 80, MF_BYPOSITION);
			if (id != -1)
				AppendMenu(hTargetMenu, GetMenuState(hSourceMenu, n, MF_BYPOSITION), id, strBuf);
			else
			{
				hSubMenu = CreatePopupMenu();
				AppendMenu(hTargetMenu, MF_POPUP | MF_STRING, (uint)hSubMenu, strBuf);
				menucpy(hSubMenu, GetSubMenu(hSourceMenu, n));
			}
		}
	}
	LocalFree((HLOCAL)strBuf);
}

// -----------------
// GetPopupMenu
// -----------------
// Internal routine used later. Returns the first popup from a menu
// 
HMENU GetPopupMenu(short mn)
{
	HMENU	hMn, hSubMenu, hPopup = NULL;

	if ((hMn = LoadMenu(hInstLib, MAKEINTRESOURCE(mn))) != NULL)
	{
		if ((hSubMenu = GetSubMenu(hMn, 0)) != NULL)
		{
			if ((hPopup = CreatePopupMenu()) != NULL)
				menucpy(hPopup, hSubMenu);
		}
		DestroyMenu(hMn);
	}
	return hPopup;
}

// --------------------
// GetEventInformations
// --------------------
// Internal routine used later. Look for one event in one of the eventInfos array...
// No protection to go faster: you must properly enter the conditions/actions!
// 
static LPEVENTINFOS2 GetEventInformations(LPEVENTINFOS2 eiPtr, short code)

{
	while(eiPtr->infos.code != code)
		eiPtr = EVINFO2_NEXT(eiPtr);
	
	return eiPtr;
}
#endif // !defined(RUN_ONLY)


// ----------------------------------------------------
// GetConditionMenu / GetActionMenu / GetExpressionMenu
// ----------------------------------------------------
// Load the condition/action/expression menu from the resource, eventually
// enable or disable some options, and returns it to CC&C.
//
HMENU WINAPI DLLExport GetConditionMenu(mv _far *mV, fpObjInfo oiPtr, LPEDATA edPtr)
{
#ifndef RUN_ONLY
	// Check compatibility
	if ( IS_COMPATIBLE(mV) )
		return GetPopupMenu(MN_CONDITIONS);
#endif // !defined(RUN_ONLY)
	return NULL;
}

HMENU WINAPI DLLExport GetActionMenu(mv _far *mV, fpObjInfo oiPtr, LPEDATA edPtr)
{
#ifndef RUN_ONLY
	// Check compatibility
	if ( IS_COMPATIBLE(mV) )
		return GetPopupMenu(MN_ACTIONS);
#endif // !defined(RUN_ONLY)
	return NULL;
}

HMENU WINAPI DLLExport GetExpressionMenu(mv _far *mV, fpObjInfo oiPtr, LPEDATA edPtr)
{
#ifndef RUN_ONLY
	// Check compatibility
	if ( IS_COMPATIBLE(mV) )
		return GetPopupMenu(MN_EXPRESSIONS);
#endif // !defined(RUN_ONLY)
	return NULL;
}


// -------------------------------------------------------
// GetConditionTitle / GetActionTitle / GetExpressionTitle
// -------------------------------------------------------
// Returns the title of the dialog box displayed when entering
// parameters for the condition, action or expressions, if any.
// Here, we simply return the title of the menu option
//

#ifndef RUN_ONLY
void GetCodeTitle(LPEVENTINFOS2 eiPtr, short code, short param, short mn, LPSTR strBuf, WORD maxLen)
{
	HMENU		hMn;

	// Finds event in array
	eiPtr=GetEventInformations(eiPtr, code);

	// If a special string is to be returned
	short strID = EVINFO2_PARAMTITLE(eiPtr, param);

	if ( strID != 0 )
		LoadString(hInstLib, strID, strBuf, maxLen);
	else
	{
		// Otherwise, returns the menu option 
		if ((hMn = LoadMenu(hInstLib, MAKEINTRESOURCE(mn))) != NULL )
		{
			GetMenuString(hMn, eiPtr->menu, strBuf, maxLen, MF_BYCOMMAND);
			DestroyMenu(hMn);
		}
	}
}
#else
#define GetCodeTitle(a,b,c,d,e,f)
#endif // !defined(RUN_ONLY)

void WINAPI DLLExport GetConditionTitle(mv _far *mV, short code, short param, LPSTR strBuf, short maxLen)
{
	GetCodeTitle((LPEVENTINFOS2)conditionsInfos, code, param, MN_CONDITIONS, strBuf, maxLen);
}
void WINAPI DLLExport GetActionTitle(mv _far *mV, short code, short param, LPSTR strBuf, short maxLen)
{
	GetCodeTitle((LPEVENTINFOS2)actionsInfos, code, param, MN_ACTIONS, strBuf, maxLen);
}
void WINAPI DLLExport GetExpressionTitle(mv _far *mV, short code, LPSTR strBuf, short maxLen)
{
	GetCodeTitle((LPEVENTINFOS2)expressionsInfos, code, 0, MN_EXPRESSIONS, strBuf, maxLen);
}

// -------------------------------------------------------
// GetConditionTitle / GetActionTitle / GetExpressionTitle
// -------------------------------------------------------
// From a menu ID, these routines returns the code of the condition,
// action or expression, as defined in the .H file
//

short WINAPI DLLExport GetConditionCodeFromMenu(mv _far *mV, short menuId)
{
#ifndef RUN_ONLY
	LPEVENTINFOS2	eiPtr;
	int				n;

	for (n=CND_LAST, eiPtr=(LPEVENTINFOS2)conditionsInfos; n>0 && eiPtr->menu!=menuId; n--)
		eiPtr = EVINFO2_NEXT(eiPtr);
	if (n>0) 
		return eiPtr->infos.code;
#endif // !defined(RUN_ONLY)
	return -1;
}

short WINAPI DLLExport GetActionCodeFromMenu(mv _far *mV, short menuId)
{
#ifndef RUN_ONLY
	LPEVENTINFOS2	eiPtr;
	int				n;

	for (n=ACT_LAST, eiPtr=(LPEVENTINFOS2)actionsInfos; n>0 && eiPtr->menu!=menuId; n--)
		eiPtr = EVINFO2_NEXT(eiPtr);
	if (n>0) 
		return eiPtr->infos.code;
#endif // !defined(RUN_ONLY)
	return -1;
}

short WINAPI DLLExport GetExpressionCodeFromMenu(mv _far *mV, short menuId)
{
#ifndef RUN_ONLY
	LPEVENTINFOS2	eiPtr;
	int				n;

	for (n=EXP_LAST, eiPtr=(LPEVENTINFOS2)expressionsInfos; n>0 && eiPtr->menu!=menuId; n--)
		eiPtr = EVINFO2_NEXT(eiPtr);
	if (n>0) 
		return eiPtr->infos.code;
#endif // !defined(RUN_ONLY)
	return -1;
}


// -------------------------------------------------------
// GetConditionInfos / GetActionInfos / GetExpressionInfos
// -------------------------------------------------------
// From a action / condition / expression code, returns 
// an infosEvents structure. 
//

LPINFOEVENTSV2 WINAPI DLLExport GetConditionInfos(mv _far *mV, short code)
{
#ifndef RUN_ONLY
	return &GetEventInformations((LPEVENTINFOS2)conditionsInfos, code)->infos;
#else
	return NULL;
#endif // !defined(RUN_ONLY)
}

LPINFOEVENTSV2 WINAPI DLLExport GetActionInfos(mv _far *mV, short code)
{
#ifndef RUN_ONLY
	return &GetEventInformations((LPEVENTINFOS2)actionsInfos, code)->infos;
#else
	return NULL;
#endif // !defined(RUN_ONLY)
}

LPINFOEVENTSV2 WINAPI DLLExport GetExpressionInfos(mv _far *mV, short code)
{
#ifndef RUN_ONLY
	return &GetEventInformations((LPEVENTINFOS2)expressionsInfos, code)->infos;
#else
	return NULL;
#endif // !defined(RUN_ONLY)
}


// ----------------------------------------------------------
// GetConditionString / GetActionString / GetExpressionString
// ----------------------------------------------------------
// From a action / condition / expression code, returns 
// the string to use for displaying it under the event editor
//

void WINAPI DLLExport GetConditionString(mv _far *mV, short code, LPSTR strPtr, short maxLen)
{
#ifndef RUN_ONLY
	// Check compatibility
	if ( IS_COMPATIBLE(mV) )
		LoadString(hInstLib, GetEventInformations((LPEVENTINFOS2)conditionsInfos, code)->string, strPtr, maxLen);
#endif // !defined(RUN_ONLY)
}

void WINAPI DLLExport GetActionString(mv _far *mV, short code, LPSTR strPtr, short maxLen)
{
#ifndef RUN_ONLY
	// Check compatibility
	if ( IS_COMPATIBLE(mV) )
		LoadString(hInstLib, GetEventInformations((LPEVENTINFOS2)actionsInfos, code)->string, strPtr, maxLen);
#endif // !defined(RUN_ONLY)
}

void WINAPI DLLExport GetExpressionString(mv _far *mV, short code, LPSTR strPtr, short maxLen)
{
#ifndef RUN_ONLY
	// Check compatibility
	if ( IS_COMPATIBLE(mV) )
		LoadString(hInstLib, GetEventInformations((LPEVENTINFOS2)expressionsInfos, code)->string, strPtr, maxLen);
#endif // !defined(RUN_ONLY)
}

// ----------------------------------------------------------
// GetExpressionParam
// ----------------------------------------------------------
// Returns the parameter name to display in the expression editor
//
void WINAPI DLLExport GetExpressionParam(mv _far *mV, short code, short param, LPSTR strBuf, short maxLen)
{
#if !defined(RUN_ONLY)
	short		strID;

	// Finds event in array
	LPEVENTINFOS2 eiPtr=GetEventInformations((LPEVENTINFOS2)expressionsInfos, code);

	// If a special string is to be returned
	strID = EVINFO2_PARAMTITLE(eiPtr, param);
	if ( strID != 0 )
		LoadString(hInstLib, strID, strBuf, maxLen);
	else
		*strBuf=0;
#endif // !defined(RUN_ONLY)
}

// ----------------------------------------------------------
// Custom Parameters
// ----------------------------------------------------------

// --------------------
// InitParameter
// --------------------
// Initialize the parameter.
//
void WINAPI InitParameter(mv _far *mV, short code, paramExt* pExt)
{
#if !defined(RUN_ONLY)
	// Example
	// -------
	// strcpy(&pExt->pextData[0], "Parameter Test");
	// pExt->pextSize = sizeof(paramExt) + strlen(pExt->pextData)+1;
#endif // !defined(RUN_ONLY)
}

// Example of custom parameter setup proc
// --------------------------------------
/*
#if !defined(RUN_ONLY)
BOOL CALLBACK DLLExport SetupProc(HWND hDlg, UINT msgType, WPARAM wParam, LPARAM lParam)
{
	paramExt*			pExt;

	switch (msgType)
	{
		case WM_INITDIALOG: // Init dialog

			// Save edptr
			SetWindowLong(hDlg, DWL_USER, lParam);
			pExt=(paramExt*)lParam;

			SetDlgItemText(hDlg, IDC_EDIT, pExt->pextData);
			return TRUE;

		case WM_COMMAND: // Command

			// Retrieve edptr
			pExt = (paramExt *)GetWindowLong(hDlg, DWL_USER);

			switch (wmCommandID)
			{
			case IDOK:	// Exit
				GetDlgItemText(hDlg, IDC_EDIT, pExt->pextData, 500);
				pExt->pextSize=sizeof(paramExt)+strlen(pExt->pextData)+1;
				EndDialog(hDlg, TRUE);
				return TRUE;

				default:
					break;
			}
			break;

		default:
			break;
	}
	return FALSE;
}
#endif // !defined(RUN_ONLY)
*/

// --------------------
// EditParameter
// --------------------
// Edit the parameter.
//
void WINAPI EditParameter(mv _far *mV, short code, paramExt* pExt)
{
#if !defined(RUN_ONLY)

	// Example
	// -------
	// DialogBoxParam(hInstLib, MAKEINTRESOURCE(DB_TRYPARAM), mV->mvHEditWin, SetupProc, (LPARAM)(LPBYTE)pExt);

#endif // !defined(RUN_ONLY)
}

// --------------------
// GetParameterString
// --------------------
// Initialize the parameter.
//
void WINAPI GetParameterString(mv _far *mV, short code, paramExt* pExt, LPSTR pDest, short size)
{
#if !defined(RUN_ONLY)

	// Example
	// -------
	// wsprintf(pDest, "Super parameter %s", pExt->pextData);

#endif // !defined(RUN_ONLY)
}

