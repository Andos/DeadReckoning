package Extensions
{
    import Actions.*;
    
    import Conditions.*;
    
    import Expressions.*;
    
    import Objects.CObject;
    
    import Params.CParamExpression;
    
    import RunLoop.*;
    
    import Services.*;
    
    import Sprites.*;
    
    import flash.utils.Dictionary;
	
    public class CRunDeadReckoning extends CRunExtension
    {
        private static var CND_LAST:int = 0;

        private static var ACT0_ADDOBJECT0:int = 0;
        private static var ACT1_REMOVEOBJECT0:int = 1;
        private static var ACT2_UPDATEPOSITIONOF0TO12:int = 2;
        private static var ACT3_UPDATEXOF0TO1:int = 3;
        private static var ACT4_UPDATEYOF0TO1:int = 4;
        private static var ACT5_UPDATEDIRECTIONOF0TO1:int = 5;
        private static var ACT6_UPDATEANGLEOF0TO1:int = 6;
        private static var ACT7_SETXOF0TO1:int = 7;
        private static var ACT8_SETYOF0TO1:int = 8;
        private static var ACT9_SETDIRECTIONOF0TO1:int = 9;
        private static var ACT10_SETANGLEOF0TO1:int = 10;
        private static var ACT11_SETXSPEEDOF0TO1:int = 11;
        private static var ACT12_SETYSPEEDOF0TO1:int = 12;
        private static var ACT13_SETDIRECTIONSPEEDOF0TO1:int = 13;
        private static var ACT14_SETANGLESPEEDOF0TO1:int = 14;
        private static var ACT15_0WASSTOPPED:int = 15;
        private static var ACT16_0BOUNCED:int = 16;
        private static var ACT17_SETEXTRAPOLATIONMODEOF0TO1:int = 17;
        private static var ACT18_SETACCELERATIONMODEOF0TO1:int = 18;
        private static var ACT19_SETMOVEMENTSMOOTHINGOF0TO1:int = 19;
        private static var ACT20_SETXMOVEMENTEXTRAPOLATIONMODEOF0TO1:int = 20;
        private static var ACT21_SETXMOVEMENTACCELERATIONMODEOF0TO1:int = 21;
        private static var ACT22_SETXMOVEMENTSMOOTHINGOF0TO1:int = 22;
        private static var ACT23_SETYMOVEMENTEXTRAPOLATIONMODEOF0TO1:int = 23;
        private static var ACT24_SETYMOVEMENTACCELERATIONMODEOF0TO1:int = 24;
        private static var ACT25_SETYMOVEMENTSMOOTHINGOF0TO1:int = 25;
        private static var ACT26_SETDIRECTIONEXTRAPOLATIONMODEOF0TO1:int = 26;
        private static var ACT27_SETDIRECTIONACCELERATIONMODEOF0TO1:int = 27;
        private static var ACT28_SETDIRECTIONSMOOTHINGOF0TO1:int = 28;
        private static var ACT29_SETANGLEEXTRAPOLATIONMODEOF0TO1:int = 29;
        private static var ACT30_SETANGLEACCELERATIONMODEOF0TO1:int = 30;
        private static var ACT31_SETANGLESMOOTHINGOF0TO1:int = 31;

        private static var EXP0_NUMOBJECTS:int = 0;
        private static var EXP1_PREDICTEDX:int = 1;
        private static var EXP2_PREDICTEDY:int = 2;
        private static var EXP3_PREDICTEDDIRECTION:int = 3;
        private static var EXP4_PREDICTEDANGLE:int = 4;
        private static var EXP5_XSPEED:int = 5;
        private static var EXP6_YSPEED:int = 6;
        private static var EXP7_DIRECTIONSPEED:int = 7;
        private static var EXP8_ANGLESPEED:int = 8;
        private static var EXP9_XSMOOTHING:int = 9;
        private static var EXP10_YSMOOTHING:int = 10;
        private static var EXP11_DIRSMOOTHING:int = 11;
        private static var EXP12_ANGLESMOOTHING:int = 12;
        private static var EXP13_MOVEDSPEED:int = 13;
        private static var EXP14_MOVEDDIRECTION:int = 14;
        private static var EXP15_MOVEDANGLE:int = 15;

		public var objects:Dictionary = new Dictionary(false);
		public var time:int;
		public var extrapolationMethod:int;
		public var useAcceleration:int;
		public var XSmoothing:Number;
		public var YSmoothing:Number;
		public var DirSmoothing:Number;
		public var AngleSmoothing:Number;
		
        public override function getNumberOfConditions():int
        {
            return CND_LAST;
        }
        public override function createRunObject(file:CBinaryFile, cob:CCreateObjectInfo, version:int):Boolean
        {
	        this.extrapolationMethod = file.readInt();
	        this.useAcceleration = file.readByte();
	        file.skipBytes(3);
	        this.XSmoothing = Number(file.readInt());
	        this.YSmoothing = Number(file.readInt());
	        this.DirSmoothing = Number(file.readInt());
        	this.AngleSmoothing = Number(file.readInt());
            return false;
        }
        public override function destroyRunObject(bFast:Boolean):void
        {
        	objects = null;
        }

		private function wrapInRange(value:int, range:int):int
		{
			value = value % range;
			if(value < 0)
				value += range;
			return value;
		}  
      
        public override function handleRunObject():int
        {
        	//Loop through all elements to ensure it isn't added twice.
			for each( var drobj:* in objects )
			{
				var obj:CRunDeadReckoningObject = drobj;
				var object:CObject = obj.object;
		
				if ((object.hoFlags & CObject.HOF_DESTROYED) != 0 )
				{
					delete objects[object];
					objects[object] = null;
					continue;
				}

				obj.xPosition.DoStep();
				obj.yPosition.DoStep();
				obj.direction.DoStep();
				obj.angle.DoStep();
	
				object.roc.rcCheckCollides = true;
				
				object.roc.rcOldX2 = object.roc.rcOldX1;
				object.roc.rcOldY2 = object.roc.rcOldY1;
				object.roc.rcOldX1 = object.roc.rcOldX;
				object.roc.rcOldY1 = object.roc.rcOldY;
				object.roc.rcOldX = object.hoX;
				object.roc.rcOldY = object.hoY;
				
				object.hoX = int(obj.xPosition.currentPos + 0.5);
				object.hoY = int(obj.yPosition.currentPos + 0.5);
				object.roc.rcDir = wrapInRange(int(obj.direction.currentPos), 32);
				object.roc.rcAngle = wrapInRange(int(obj.angle.currentPos), 360);
	
				object.roc.rcChanged = true;
			}
			time++;

            return 0;
        }
		
        // Conditions
        // -------------------------------------------------
        public override function condition(num:int, cnd:CCndExtension):Boolean
        {
            return false;
        }

		public function getActionFloatParam(act:CActExtension, num:int):Number
		{
			return rh.get_EventExpressionDouble( CParamExpression(act.evtParams[num]))
		}
		
        // Actions
        // -------------------------------------------------
        public override function action(num:int, act:CActExtension):void
        {
            switch (num)
            {
            case ACT0_ADDOBJECT0:
                act0_Addobject0(act.getParamObject(rh,0));
                break;
            case ACT1_REMOVEOBJECT0:
                act1_Removeobject0(act.getParamObject(rh,0));
                break;
            case ACT2_UPDATEPOSITIONOF0TO12:
                act2_Updatepositionof0to12(act.getParamObject(rh,0), getActionFloatParam(act,1), getActionFloatParam(act,2));
                break;
            case ACT3_UPDATEXOF0TO1:
                act3_UpdateXof0to1(act.getParamObject(rh,0), getActionFloatParam(act,1));
                break;
            case ACT4_UPDATEYOF0TO1:
                act4_UpdateYof0to1(act.getParamObject(rh,0), getActionFloatParam(act,1));
                break;
            case ACT5_UPDATEDIRECTIONOF0TO1:
                act5_Updatedirectionof0to1(act.getParamObject(rh,0), getActionFloatParam(act,1));
                break;
            case ACT6_UPDATEANGLEOF0TO1:
                act6_Updateangleof0to1(act.getParamObject(rh,0), getActionFloatParam(act,1));
                break;
            case ACT7_SETXOF0TO1:
                act7_SetXof0to1(act.getParamObject(rh,0), getActionFloatParam(act,1));
                break;
            case ACT8_SETYOF0TO1:
                act8_SetYof0to1(act.getParamObject(rh,0), getActionFloatParam(act,1));
                break;
            case ACT9_SETDIRECTIONOF0TO1:
                act9_Setdirectionof0to1(act.getParamObject(rh,0), getActionFloatParam(act,1));
                break;
            case ACT10_SETANGLEOF0TO1:
                act10_Setangleof0to1(act.getParamObject(rh,0), getActionFloatParam(act,1));
                break;
            case ACT11_SETXSPEEDOF0TO1:
                act11_SetXspeedof0to1(act.getParamObject(rh,0), getActionFloatParam(act,1));
                break;
            case ACT12_SETYSPEEDOF0TO1:
                act12_SetYspeedof0to1(act.getParamObject(rh,0), getActionFloatParam(act,1));
                break;
            case ACT13_SETDIRECTIONSPEEDOF0TO1:
                act13_Setdirectionspeedof0to1(act.getParamObject(rh,0), getActionFloatParam(act,1));
                break;
            case ACT14_SETANGLESPEEDOF0TO1:
                act14_Setanglespeedof0to1(act.getParamObject(rh,0), getActionFloatParam(act,1));
                break;
            case ACT15_0WASSTOPPED:
                act15_0wasstopped(act.getParamObject(rh,0));
                break;
            case ACT16_0BOUNCED:
                act16_0bounced(act.getParamObject(rh,0));
                break;
            case ACT17_SETEXTRAPOLATIONMODEOF0TO1:
                act17_Setextrapolationmodeof0to1(act.getParamObject(rh,0), act.getParamExpression(rh,1));
                break;
            case ACT18_SETACCELERATIONMODEOF0TO1:
                act18_Setaccelerationmodeof0to1(act.getParamObject(rh,0), act.getParamExpression(rh,1));
                break;
            case ACT19_SETMOVEMENTSMOOTHINGOF0TO1:
                act19_Setmovementsmoothingof0to1(act.getParamObject(rh,0), getActionFloatParam(act,1));
                break;
            case ACT20_SETXMOVEMENTEXTRAPOLATIONMODEOF0TO1:
                act20_SetXmovementextrapolationmodeof0to1(act.getParamObject(rh,0), act.getParamExpression(rh,1));
                break;
            case ACT21_SETXMOVEMENTACCELERATIONMODEOF0TO1:
                act21_SetXmovementaccelerationmodeof0to1(act.getParamObject(rh,0), act.getParamExpression(rh,1));
                break;
            case ACT22_SETXMOVEMENTSMOOTHINGOF0TO1:
                act22_SetXmovementsmoothingof0to1(act.getParamObject(rh,0), getActionFloatParam(act,1));
                break;
            case ACT23_SETYMOVEMENTEXTRAPOLATIONMODEOF0TO1:
                act23_SetYmovementextrapolationmodeof0to1(act.getParamObject(rh,0), act.getParamExpression(rh,1));
                break;
            case ACT24_SETYMOVEMENTACCELERATIONMODEOF0TO1:
                act24_SetYmovementaccelerationmodeof0to1(act.getParamObject(rh,0), act.getParamExpression(rh,1));
                break;
            case ACT25_SETYMOVEMENTSMOOTHINGOF0TO1:
                act25_SetYmovementsmoothingof0to1(act.getParamObject(rh,0), getActionFloatParam(act,1));
                break;
            case ACT26_SETDIRECTIONEXTRAPOLATIONMODEOF0TO1:
                act26_Setdirectionextrapolationmodeof0to1(act.getParamObject(rh,0), act.getParamExpression(rh,1));
                break;
            case ACT27_SETDIRECTIONACCELERATIONMODEOF0TO1:
                act27_Setdirectionaccelerationmodeof0to1(act.getParamObject(rh,0), act.getParamExpression(rh,1));
                break;
            case ACT28_SETDIRECTIONSMOOTHINGOF0TO1:
                act28_Setdirectionsmoothingof0to1(act.getParamObject(rh,0), getActionFloatParam(act,1));
                break;
            case ACT29_SETANGLEEXTRAPOLATIONMODEOF0TO1:
                act29_Setangleextrapolationmodeof0to1(act.getParamObject(rh,0), act.getParamExpression(rh,1));
                break;
            case ACT30_SETANGLEACCELERATIONMODEOF0TO1:
                act30_Setangleaccelerationmodeof0to1(act.getParamObject(rh,0), act.getParamExpression(rh,1));
                break;
            case ACT31_SETANGLESMOOTHINGOF0TO1:
                act31_Setanglesmoothingof0to1(act.getParamObject(rh,0), getActionFloatParam(act,1));
                break;
            }
        }

        // Expressions
        // -------------------------------------------------
        public override function expression(num:int):CValue
        {
            switch (num)
            {
            case EXP0_NUMOBJECTS:
                return exp0_NumObjects();
            case EXP1_PREDICTEDX:
                return exp1_PredictedX(ho.getExpParam().getInt());
            case EXP2_PREDICTEDY:
                return exp2_PredictedY(ho.getExpParam().getInt());
            case EXP3_PREDICTEDDIRECTION:
                return exp3_PredictedDirection(ho.getExpParam().getInt());
            case EXP4_PREDICTEDANGLE:
                return exp4_PredictedAngle(ho.getExpParam().getInt());
            case EXP5_XSPEED:
                return exp5_XSpeed(ho.getExpParam().getInt());
            case EXP6_YSPEED:
                return exp6_YSpeed(ho.getExpParam().getInt());
            case EXP7_DIRECTIONSPEED:
                return exp7_DirectionSpeed(ho.getExpParam().getInt());
            case EXP8_ANGLESPEED:
                return exp8_AngleSpeed(ho.getExpParam().getInt());
            case EXP9_XSMOOTHING:
                return exp9_XSmoothing(ho.getExpParam().getInt());
            case EXP10_YSMOOTHING:
                return exp10_YSmoothing(ho.getExpParam().getInt());
            case EXP11_DIRSMOOTHING:
                return exp11_DirSmoothing(ho.getExpParam().getInt());
            case EXP12_ANGLESMOOTHING:
                return exp12_AngleSmoothing(ho.getExpParam().getInt());
            case EXP13_MOVEDSPEED:
                return exp13_MovedSpeed(ho.getExpParam().getInt());
            case EXP14_MOVEDDIRECTION:
                return exp14_MovedDirection(ho.getExpParam().getInt());
            case EXP15_MOVEDANGLE:
                return exp15_MovedAngle(ho.getExpParam().getInt());
            }
            return new CValue(0);
        }

        private function act0_Addobject0(obj:CObject):void
        {
			for ( var index:* in objects )
			{
				if(index == obj)
					return;
			}
			
			var newObj:CRunDeadReckoningObject = new CRunDeadReckoningObject();
			newObj.Reset();
			newObj.object = obj;
			
			newObj.xPosition.lastUpdate = time;
			newObj.yPosition.lastUpdate = time;
			newObj.direction.lastUpdate = time;
			newObj.angle.lastUpdate = time;

			newObj.xPosition.SetValue(obj.hoX);
			newObj.yPosition.SetValue(obj.hoY);
			newObj.direction.SetValue(obj.roc.rcDir);
			newObj.angle.SetValue(obj.roc.rcAngle);
			
			newObj.xPosition.extrapolationMode = extrapolationMethod;
			newObj.yPosition.extrapolationMode = extrapolationMethod;
			newObj.direction.extrapolationMode = extrapolationMethod;
			newObj.angle.extrapolationMode = extrapolationMethod;

			newObj.xPosition.useAcceleration = useAcceleration;
			newObj.yPosition.useAcceleration = useAcceleration;
			newObj.direction.useAcceleration = useAcceleration;
			newObj.angle.useAcceleration = useAcceleration;

			newObj.xPosition.smoothing = XSmoothing;
			newObj.yPosition.smoothing = YSmoothing;
			newObj.direction.smoothing = DirSmoothing;
			newObj.angle.smoothing = AngleSmoothing;

			newObj.xPosition.wrapMode = CRunDeadReckoningValue.WRAP_LINEAR;
			newObj.yPosition.wrapMode = CRunDeadReckoningValue.WRAP_LINEAR;

			newObj.direction.wrapMode = CRunDeadReckoningValue.WRAP_CIRCULAR;
			newObj.angle.wrapMode = CRunDeadReckoningValue.WRAP_CIRCULAR;

			newObj.direction.wrapValue = 32.0;
			newObj.angle.wrapValue = 360.0;

			objects[obj] = newObj;
        }
        
        private function act1_Removeobject0(obj:CObject):void
        {
			for ( var key:Object in objects )
			{
				if(key == obj)
				{
					delete objects[obj];
					key = null;
				}
			}
        }

        private function act2_Updatepositionof0to12(obj:CObject, x:Number, y:Number):void
        {
			var drobj:CRunDeadReckoningObject = objects[obj];

			drobj.xPosition.UpdateValue(x, time);
			drobj.yPosition.UpdateValue(y, time);
        }

        private function act3_UpdateXof0to1(obj:CObject, x:Number):void
        {
			var drobj:CRunDeadReckoningObject = objects[obj];
			drobj.xPosition.UpdateValue(x, time);
        }

        private function act4_UpdateYof0to1(obj:CObject, y:Number):void
        {
			var drobj:CRunDeadReckoningObject = objects[obj];
			drobj.yPosition.UpdateValue(y, time);
        }

        private function act5_Updatedirectionof0to1(obj:CObject, dir:Number):void
        {
			var drobj:CRunDeadReckoningObject = objects[obj];
			drobj.direction.UpdateValue(dir, time);
        }

        private function act6_Updateangleof0to1(obj:CObject, angle:Number):void
        {
			var drobj:CRunDeadReckoningObject = objects[obj];
			drobj.angle.UpdateValue(angle, time);
        }

        private function act7_SetXof0to1(obj:CObject, x:Number):void
        {
			var drobj:CRunDeadReckoningObject = objects[obj];
			drobj.xPosition.SetValue(x);
        }

        private function act8_SetYof0to1(obj:CObject, y:Number):void
        {
			var drobj:CRunDeadReckoningObject = objects[obj];
			drobj.xPosition.SetValue(y);
        }

        private function act9_Setdirectionof0to1(obj:CObject, dir:Number):void
        {
			var drobj:CRunDeadReckoningObject = objects[obj];
			drobj.angle.SetValue(dir);
        }

        private function act10_Setangleof0to1(obj:CObject, angle:Number):void
        {
			var drobj:CRunDeadReckoningObject = objects[obj];
			drobj.angle.SetValue(angle);
        }

        private function act11_SetXspeedof0to1(obj:CObject, xspeed:Number):void
        {
			var drobj:CRunDeadReckoningObject = objects[obj];
			drobj.xPosition.SetValue(xspeed);
        }

        private function act12_SetYspeedof0to1(obj:CObject, yspeed:Number):void
        {
			var drobj:CRunDeadReckoningObject = objects[obj];
			drobj.yPosition.SetValue(yspeed);
        }

        private function act13_Setdirectionspeedof0to1(obj:CObject, dirspeed:Number):void
        {
			var drobj:CRunDeadReckoningObject = objects[obj];
			drobj.direction.SetValue(dirspeed);
        }

        private function act14_Setanglespeedof0to1(obj:CObject, anglespeed:Number):void
        {
			var drobj:CRunDeadReckoningObject = objects[obj];
			drobj.angle.SetValue(anglespeed);
        }

        private function act15_0wasstopped(obj:CObject):void
        {
			var drobj:CRunDeadReckoningObject = objects[obj];
			drobj.xPosition.SetValue(obj.hoX);
			drobj.yPosition.SetValue(obj.hoY);
        }

        private function act16_0bounced(obj:CObject):void
        {
			var drobj:CRunDeadReckoningObject = objects[obj];
			drobj.xPosition.SetValue(obj.hoX);
			drobj.yPosition.SetValue(obj.hoY);
			drobj.direction.SetValue(obj.roc.rcDir);
        }
		
		//All
        private function act17_Setextrapolationmodeof0to1(obj:CObject, mode:int):void
        {
			var drobj:CRunDeadReckoningObject = objects[obj];
			drobj.xPosition.extrapolationMode = mode;
			drobj.yPosition.extrapolationMode = mode;
			drobj.direction.extrapolationMode = mode;
			drobj.angle.extrapolationMode = mode;
        }

        private function act18_Setaccelerationmodeof0to1(obj:CObject, mode:int):void
        {
			var drobj:CRunDeadReckoningObject = objects[obj];
			drobj.xPosition.useAcceleration = mode;
			drobj.yPosition.useAcceleration = mode;
			drobj.direction.useAcceleration = mode;
			drobj.angle.useAcceleration = mode;
        }

        private function act19_Setmovementsmoothingof0to1(obj:CObject, smoothing:Number):void
        {
			var drobj:CRunDeadReckoningObject = objects[obj];
			drobj.xPosition.smoothing = smoothing;
			drobj.yPosition.smoothing = smoothing;
			drobj.direction.smoothing = smoothing;
			drobj.angle.smoothing = smoothing;
        }

		//X
        private function act20_SetXmovementextrapolationmodeof0to1(obj:CObject, mode:int):void
        {
			var drobj:CRunDeadReckoningObject = objects[obj];
			drobj.xPosition.extrapolationMode = mode;
        }

        private function act21_SetXmovementaccelerationmodeof0to1(obj:CObject, mode:int):void
        {
			var drobj:CRunDeadReckoningObject = objects[obj];
			drobj.xPosition.useAcceleration = mode;
        }

        private function act22_SetXmovementsmoothingof0to1(obj:CObject, smoothing:Number):void
        {
			var drobj:CRunDeadReckoningObject = objects[obj];
			drobj.xPosition.smoothing = smoothing;
        }

		//Y
        private function act23_SetYmovementextrapolationmodeof0to1(obj:CObject, mode:int):void
        {
			var drobj:CRunDeadReckoningObject = objects[obj];
			drobj.yPosition.extrapolationMode = mode;
        }

        private function act24_SetYmovementaccelerationmodeof0to1(obj:CObject, mode:int):void
        {
			var drobj:CRunDeadReckoningObject = objects[obj];
			drobj.yPosition.useAcceleration = mode;
        }

        private function act25_SetYmovementsmoothingof0to1(obj:CObject, smoothing:Number):void
        {
			var drobj:CRunDeadReckoningObject = objects[obj];
			drobj.yPosition.smoothing = smoothing;
        }

		//Dir
        private function act26_Setdirectionextrapolationmodeof0to1(obj:CObject, mode:int):void
        {
			var drobj:CRunDeadReckoningObject = objects[obj];
			drobj.direction.extrapolationMode = mode;
        }

        private function act27_Setdirectionaccelerationmodeof0to1(obj:CObject, mode:int):void
        {
			var drobj:CRunDeadReckoningObject = objects[obj];
			drobj.direction.useAcceleration = mode;
        }

        private function act28_Setdirectionsmoothingof0to1(obj:CObject, smoothing:Number):void
        {
			var drobj:CRunDeadReckoningObject = objects[obj];
			drobj.direction.smoothing = smoothing;
        }

		//Angle
        private function act29_Setangleextrapolationmodeof0to1(obj:CObject, mode:int):void
        {
			var drobj:CRunDeadReckoningObject = objects[obj];
			drobj.angle.extrapolationMode = mode;
        }

        private function act30_Setangleaccelerationmodeof0to1(obj:CObject, mode:int):void
        {
			var drobj:CRunDeadReckoningObject = objects[obj];
			drobj.angle.useAcceleration = mode;
        }

        private function act31_Setanglesmoothingof0to1(obj:CObject, smoothing:Number):void
        {
			var drobj:CRunDeadReckoningObject = objects[obj];
			drobj.angle.smoothing = smoothing;
        }

		// EXPRESSIONS
		
        private function exp0_NumObjects():CValue
        {
			var n:int = 0;
			for (var key:* in objects) {
				n++;
			}
            return new CValue(n);
        }

        private function objFromFixed(fixedValue:int):CObject
        {
			for (var key:* in objects)
			{
				var obj:CObject = key;
				var fixed:int = (obj.hoCreationId << 16) + obj.hoNumber;
				if(fixed == fixedValue)
					return obj;
			}
            return null;
        }

        private function exp1_PredictedX(fixedValue:int):CValue
        {
        	var obj:CObject = objFromFixed(fixedValue);
        	if(obj == null)
        		return new CValue(0);
        	
			var drobj:CRunDeadReckoningObject = objects[obj];
			return new CValue(drobj.xPosition.nextPos);
        }

        private function exp2_PredictedY(fixedValue:int):CValue
        {
        	var obj:CObject = objFromFixed(fixedValue);
        	if(obj == null)
        		return new CValue(0);
        	
            var drobj:CRunDeadReckoningObject = objects[obj];
            return new CValue(drobj.yPosition.nextPos);
        }

        private function exp3_PredictedDirection(fixedValue:int):CValue
        {
        	var obj:CObject = objFromFixed(fixedValue);
        	if(obj == null)
        		return new CValue(0);
        	
            var drobj:CRunDeadReckoningObject = objects[obj];
            return new CValue(drobj.direction.nextPos);
        }

        private function exp4_PredictedAngle(fixedValue:int):CValue
        {
        	var obj:CObject = objFromFixed(fixedValue);
        	if(obj == null)
        		return new CValue(0);
        	
            var drobj:CRunDeadReckoningObject = objects[obj];
            return new CValue(drobj.angle.nextPos);
        }

        private function exp5_XSpeed(fixedValue:int):CValue
        {
        	var obj:CObject = objFromFixed(fixedValue);
        	if(obj == null)
        		return new CValue(0);
        	
            var drobj:CRunDeadReckoningObject = objects[obj];
            return new CValue(drobj.xPosition.oldSpeed);
        }

        private function exp6_YSpeed(fixedValue:int):CValue
        {
        	var obj:CObject = objFromFixed(fixedValue);
        	if(obj == null)
        		return new CValue(0);
        	
            var drobj:CRunDeadReckoningObject = objects[obj];
            return new CValue(drobj.yPosition.oldSpeed);
        }

        private function exp7_DirectionSpeed(fixedValue:int):CValue
        {
        	var obj:CObject = objFromFixed(fixedValue);
        	if(obj == null)
        		return new CValue(0);
        	
            var drobj:CRunDeadReckoningObject = objects[obj];
            return new CValue(drobj.direction.oldSpeed);
        }

        private function exp8_AngleSpeed(fixedValue:int):CValue
        {
        	var obj:CObject = objFromFixed(fixedValue);
        	if(obj == null)
        		return new CValue(0);
        	
            var drobj:CRunDeadReckoningObject = objects[obj];
            return new CValue(drobj.angle.oldSpeed);
        }

        private function exp9_XSmoothing(fixedValue:int):CValue
        {
        	var obj:CObject = objFromFixed(fixedValue);
        	if(obj == null)
        		return new CValue(0);
        	
            var drobj:CRunDeadReckoningObject = objects[obj];
            return new CValue(drobj.xPosition.smoothing);
        }

        private function exp10_YSmoothing(fixedValue:int):CValue
        {
        	var obj:CObject = objFromFixed(fixedValue);
        	if(obj == null)
        		return new CValue(0);
        	
            var drobj:CRunDeadReckoningObject = objects[obj];
            return new CValue(drobj.yPosition.smoothing);
        }

        private function exp11_DirSmoothing(fixedValue:int):CValue
        {
        	var obj:CObject = objFromFixed(fixedValue);
        	if(obj == null)
        		return new CValue(0);
        	
            var drobj:CRunDeadReckoningObject = objects[obj];
            return new CValue(drobj.direction.smoothing);
        }

        private function exp12_AngleSmoothing(fixedValue:int):CValue
        {
        	var obj:CObject = objFromFixed(fixedValue);
        	if(obj == null)
        		return new CValue(0);
        	
            var drobj:CRunDeadReckoningObject = objects[obj];
            return new CValue(drobj.angle.smoothing);
        }

        private function exp13_MovedSpeed(fixedValue:int):CValue
        {
        	var obj:CObject = objFromFixed(fixedValue);
        	if(obj == null)
        		return new CValue(0);
        	
			var drobj:CRunDeadReckoningObject = objects[obj];
			var speed:Number = Math.sqrt( drobj.xPosition.oldSpeed*drobj.xPosition.oldSpeed + drobj.yPosition.oldSpeed*drobj.yPosition.oldSpeed );
            return new CValue(speed);
        }

		private function ToRadians(degrees:Number):Number
		{
			return degrees * Math.PI/180.0;
		}

		private function ToDegrees(radians:Number):Number
		{
			var ret:Number = radians * 180.0/Math.PI;
			if (ret < 0)
				return 360+ret;
			else
				return ret;
		}
		
        private function exp14_MovedDirection(fixedValue:int):CValue
        {
        	var obj:CObject = objFromFixed(fixedValue);
        	if(obj == null)
        		return new CValue(0);
        	
			var drobj:CRunDeadReckoningObject = objects[obj];
			if(drobj.xPosition.oldSpeed < 0.001 && drobj.yPosition.oldSpeed < 0.001)
				return new CValue( (int)(drobj.previousAngle/11.25) );

			drobj.previousAngle = 360.0 - ToDegrees(Math.atan2(drobj.yPosition.oldSpeed, drobj.xPosition.oldSpeed));
			return new CValue((int)(drobj.previousAngle/11.25));
        }

        private function exp15_MovedAngle(fixedValue:int):CValue
        {
        	var obj:CObject = objFromFixed(fixedValue);
        	if(obj == null)
        		return new CValue(0);
        	
			var drobj:CRunDeadReckoningObject = objects[obj];
			if(drobj.xPosition.oldSpeed < 0.001 && drobj.yPosition.oldSpeed < 0.001)
				return new CValue( (int)(drobj.previousAngle/11.25) );

			drobj.previousAngle = 360.0 - ToDegrees(Math.atan2(drobj.yPosition.oldSpeed, drobj.xPosition.oldSpeed));
			return new CValue(drobj.previousAngle);
        }

    }
}
