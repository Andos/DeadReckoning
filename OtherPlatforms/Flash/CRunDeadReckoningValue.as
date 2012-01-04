package Extensions
{
	public class CRunDeadReckoningValue
	{
		public static var AVERAGEWINDOW:int = 8;
		
		public static var INTERPOLATION_LINEAR:int = 0;
		public static var INTERPOLATION_CUBIC:int = 1;
		
		public static var WRAP_LINEAR:Boolean = false;
		public static var WRAP_CIRCULAR:Boolean = true;

		public var currentPos:Number;			//The object's actual current position.
		public var stepPos:Number;				//The currently interpolated value (ideal position, currentPos will approach this value each step)
		public var	posAtUpdate:Number;			//The position at the last update (used for correcting errors)
		public var	diffAtUpdate:Number;		//The latest value difference
		
		public var	oldPos:Number;				//Position at last update
		public var	oldSpeed:Number;			//Speed at last update
		
		public var	prevPos:Number;				//The previous value; used in cubic extrapolation
		public var	nextPos:Number;				//Guessed next position

		public var	doSpeedOverride:Boolean;	//If the next update should override it's speed calculation
		public var	speedOverride:Number;		//The speed to override with;

		//Timing data
		public var	lastUpdate:int;
		public var	currentStep:int;
		public var	timeDeltaIndex:int;
		public var	numDeltas:int;
		public var	timeDeltas:Array;			//Circular array of timeDeltas for calculating the average update interval.
		public var	averageUpdateInterval:Number;
		
		//Settings
		public var useAcceleration:int;
		public var extrapolationMode:int;
		public var smoothing:Number;
		public var wrapMode:Boolean;
		public var wrapValue:Number;

		public function Reset():void
		{
			currentPos = stepPos = posAtUpdate = prevPos = oldPos = oldSpeed = nextPos = averageUpdateInterval = 0;
			lastUpdate = currentStep = timeDeltaIndex = numDeltas = smoothing = speedOverride = 0;
			extrapolationMode = 0;
			doSpeedOverride = false;
			useAcceleration = 0;
			wrapMode = false;
			wrapValue = 0;
			timeDeltas = new Array(AVERAGEWINDOW);
			for(var i:int=0; i<AVERAGEWINDOW; i++)
				timeDeltas[i]=0;
		}

		public function UpdateValue(newValue:Number, time:int):void
		{
			var speed:Number;
			var timeDelta:int = time - lastUpdate;
			if(timeDelta == 0)
				return;

			//If the value is circular, map it down into a linear value
			if(wrapMode == WRAP_CIRCULAR)
			{
				diffAtUpdate = CircularDifference(newValue, oldPos, wrapValue);
				newValue = oldPos + diffAtUpdate;
			}
			else
				diffAtUpdate = newValue-oldPos;

			UpdateAverageInterval(timeDelta);

			if(!doSpeedOverride)
				speed = diffAtUpdate/timeDelta;
			else
			{
				speed = speedOverride;
				doSpeedOverride = false;
			}
			
			//If the object changes direction
			if((speed>0 && oldSpeed<0) || (speed<0 && oldSpeed>0))
				oldSpeed = 0;

			if(useAcceleration)
			{
				var acceleration:Number = speed - oldSpeed;

				var increaseFactor:Number = 1.0;
				//The increasefactor can kinda be seen as the acceleration of the acceleration.
				if(oldSpeed != 0)
					increaseFactor = Math.max(  Math.min(speed/oldSpeed, 1.0), 0.0);
				else
					increaseFactor = 0;

				//Predict the next position
				nextPos = newValue + (speed + acceleration*increaseFactor) * averageUpdateInterval;
			}
			else
				nextPos = newValue + speed * averageUpdateInterval;
			
			//Store values for next update
			currentStep = 0;
			
			prevPos = oldPos;
			oldPos = newValue;
			
			lastUpdate = time;
			oldSpeed = speed;
			posAtUpdate = currentPos;
			timeDeltaIndex = (timeDeltaIndex+1) % AVERAGEWINDOW;
		}

		public function SetValue(value:Number):void
		{
			currentPos = prevPos = posAtUpdate = stepPos = nextPos = oldPos = value;
		}

		public function SetSpeed(speed:Number):void
		{
			//Recalculate movement
			doSpeedOverride = true;
			speedOverride = speed;
			oldPos = currentPos;
			nextPos = currentPos + speed * averageUpdateInterval;	
		}
		
		public function DoStep():void
		{
			var timespan:int = averageUpdateInterval;
			if(currentStep >= timespan)
				return;

			currentStep++;

			var mu:Number = 1.0/averageUpdateInterval * currentStep;
			var secondGuess:Number = nextPos + (nextPos-oldPos);
			
			switch(extrapolationMode)
			{
			case INTERPOLATION_CUBIC:
				stepPos = CubicInterpolation(prevPos, posAtUpdate, nextPos, secondGuess, mu);
				break;
			case INTERPOLATION_LINEAR:
				stepPos = posAtUpdate+(nextPos-posAtUpdate)*mu;
				break;
			}
			
			//Movement smoothing
			if(smoothing > 1)
				currentPos = currentPos + (stepPos-currentPos)/smoothing;
			else
				currentPos = stepPos;
		}

		public function CubicInterpolation(y0:Number, y1:Number, y2:Number, y3:Number, mu:Number):Number
		{
			var a0:Number, a1:Number, a2:Number, a3:Number, mu2:Number;
			mu2 = mu*mu;
			a0 = y3 - y2 - y0 + y1;
			a1 = y0 - y1 - a0;
			a2 = y2 - y0;
			a3 = y1;
			return a0*mu*mu2+a1*mu2+a2*mu+a3;
		}

		public function UpdateAverageInterval(timeDelta:int):void
		{
			timeDeltas[timeDeltaIndex] = timeDelta;
			if(numDeltas < AVERAGEWINDOW)
				numDeltas++;

			averageUpdateInterval = 0;
			var maxLoop:int = Math.min(AVERAGEWINDOW, numDeltas);
			for(var i:int=0; i<maxLoop; i++)
				averageUpdateInterval += timeDeltas[i];
			averageUpdateInterval /= maxLoop;
		}
		
		public function CircularDifference(angleA:Number, angleB:Number, wrapValue:Number):Number
		{
			var ret:Number = (angleA - angleB) - (wrapValue * Math.floor((angleA - angleB)/wrapValue));
			var halfWrap:Number = wrapValue / 2.0;

			if(ret >= halfWrap)
				return ret-wrapValue;
			else if(ret < -halfWrap)
				return ret+wrapValue;
			else
				return ret;
		}
	}
}
