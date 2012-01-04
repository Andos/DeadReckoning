package Extensions
{
	import Objects.CObject;
	
	public class CRunDeadReckoningObject
	{
		public var object:CObject;
		public var previousAngle:Number;

		public var xPosition:CRunDeadReckoningValue;
		public var yPosition:CRunDeadReckoningValue;
		public var direction:CRunDeadReckoningValue;
		public var angle:CRunDeadReckoningValue;
	
		public function CRunDeadReckoningObject()
		{
			xPosition = new CRunDeadReckoningValue();
			yPosition = new CRunDeadReckoningValue();
			direction = new CRunDeadReckoningValue();
			angle = new CRunDeadReckoningValue();
		}
	
		public function Reset():void
		{
			object = null;
			previousAngle = 0.0;
			xPosition.Reset();
			yPosition.Reset();
			direction.Reset();
			angle.Reset();
		}
	}
}