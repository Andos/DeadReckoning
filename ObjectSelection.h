#if !defined(OBJECTSELECTION)
#define OBJECTSELECTION

#include "Common.h"

#if !defined(EF_ISHWA)
#define EF_ISHWA		112
#endif
#if !defined(EF_ISUNICODE)
#define EF_ISUNICODE	113
#endif

class ObjectSelection  
{
public:
	ObjectSelection(LPRH rhPtr);

	void SelectAll(short Oi);
	void SelectNone(short Oi);
	void SelectOneObject(LPRO object);
	void SelectObjects(short Oi, LPRO* objects, int count);
	bool FilterObjects(LPRDATA rdPtr, short Oi, bool negate, bool (*filterFunction)(LPRDATA, LPRO));
	bool ObjectIsOfType(LPRO object, short Oi);
	int GetNumberOfSelected(short Oi);
	
private:
	LPRH rhPtr;
	LPOBL ObjectList;
	LPOIL OiList;
	LPQOI QualToOiList;
	int oiListItemSize;

	bool FilterQualifierObjects(LPRDATA rdPtr, short Oi, bool negate, bool (*filterFunction)(LPRDATA, LPRO));
	bool FilterNonQualifierObjects(LPRDATA rdPtr, short Oi, bool negate, bool (*filterFunction)(LPRDATA, LPRO));
	LPOIL GetOILFromOI(short Oi);

};

#endif // !defined(OBJECTSELECTION)