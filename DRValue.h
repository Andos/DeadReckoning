#if !defined(DRVALUEH)
#define DRVALUEH


#include	<map>
using namespace std;
#include	<cmath>

#define ABS(x)				((x>0)?x:0-x)
#define MAX(x,y)			((x>y)?x:y)
#define MIN(x,y)			((x>y)?y:x)
#define CLAMP(x,a,b)		MAX(MIN(x,b),a)
#define AVERAGEWINDOW		8

enum {
	INTERPOLATION_LINEAR = 0,
	INTERPOLATION_CUBIC = 1
};

enum {
	WRAP_LINEAR = 0,
	WRAP_CIRCULAR = 1
};

struct DeadReckoningValue
{
	float	currentPos;			//The object's actual current position.
	float	stepPos;			//The currently interpolated value (ideal position, currentPos will approach this value each step)
	float	posAtUpdate;		//The position at the last update (used for correcting errors)
	float	diffAtUpdate;		//The latest value difference
	
	float	oldPos;				//Position at last update
	float	oldSpeed;			//Speed at last update
	
	float	prevPos;			//The previous value; used in cubic extrapolation
	float	nextPos;			//Guessed next position

	bool	doSpeedOverride;	//If the next update should override it's speed calculation
	float	speedOverride;		//The speed to override with;

	//Timing data
	long	lastUpdate;
	long	currentStep;
	long	timeDeltaIndex;
	long	numDeltas;
	long	timeDeltas[AVERAGEWINDOW];	//Circular array of timeDeltas for calculating the average update interval.
	float	averageUpdateInterval;
	
	//Settings
	bool	useAcceleration;
	int		extrapolationMode;
	float	smoothing;
	bool	wrapMode;
	float	wrapValue;

	void Reset();
	void UpdateValue(float newValue, long time);
	void SetValue(float value);
	void SetSpeed(float speed);
	void DoStep();
	float CubicInterpolation(float y0, float y1, float y2, float y3, float mu);
	void UpdateAverageInterval(long timeDelta);
	float CircularDifference(float angleA, float angleB, float wrapValue);
};

struct DRObj
{
	long	fixedValue;
	float	previousAngle;
	int oldX;
	int oldY;

	DeadReckoningValue	xPosition;
	DeadReckoningValue	yPosition;
	DeadReckoningValue	direction;
	DeadReckoningValue	angle;
	
	void Reset();
};


typedef map<long,DRObj> DRMap;



#endif // !defined(DRVALUEH)
