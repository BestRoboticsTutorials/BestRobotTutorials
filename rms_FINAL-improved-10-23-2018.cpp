//tMotor = motor port on cortex
//TVexJoysticks = joystick channel or button

void driveMotor(tMotor m,TVexJoysticks joystick);
void armRotate(tMotor m,TVexJoysticks joystick2); // lazysusan
void armLift_Lower(tMotor m,TVexJoysticks buttonUp, TVexJoysticks buttonDown);
void claw(tMotor s1 ,tMotor s2 ,tMotor s3, TVexJoysticks clawOpen, TVexJoysticks clawClose);
void armbottom(tMotor m,TVexJoysticks armUp, TVexJoysticks armDown);
float percentToMotorValue(float OneTwentySeven);
int config=1;
task main(){

	while(true){
		if(vexRT(Btn7U))config=-1;
 		driveMotor(port2,Ch3);
 		armRotate(port3,Ch1);
 		armLift_Lower(port4,Btn6U ,Btn6D);
 		claw(port5,port6,port7,Btn8U ,Btn8D);
 		armbottom(port8,Btn5U ,Btn5D);
 	}
}
void driveMotor(tMotor m, TVexJoysticks joystick){
	motor(m) = -vexRT[joystick]*config;
}
void armRotate(tMotor m,TVexJoysticks joystick2){// lazysusan
	motor(m) = vexRT[joystick2]/1.5;
}
void armLift_Lower(tMotor m,TVexJoysticks buttonUp, TVexJoysticks buttonDown){
	if (vexRT(buttonUp)){
		motor[m] = percentToMotorValue(100);}
	else if (vexRT(buttonDown)){
		motor[m] = -percentToMotorValue(100);
	}else{
		motor[m] = 0;
	}
}
void claw(tMotor s1 ,tMotor s2 ,tMotor s3,TVexJoysticks clawOpen, TVexJoysticks clawClose){
	if(vexRT(clawOpen)){
		motor[s1] = percentToMotorValue(100);
		motor[s2] = percentToMotorValue(100);
		motor[s3] = percentToMotorValue(100);
	}else if(vexRT(clawClose)){
		motor[s1] = -percentToMotorValue(100);
		motor[s2] = -percentToMotorValue(100);
		motor[s3] = -percentToMotorValue(100);
	}
}
void armbottom(tMotor m,TVexJoysticks armUp, TVexJoysticks armDown){
	if(vexRT(armUp)){
		motor[m] = percentToMotorValue(100);
	}else if(vexRT(armDown)){
		motor[m] = -percentToMotorValue(100);
	}else{
		motor[m] = 0;
	}
}
float percentToMotorValue(float OneTwentySeven){
	return OneTwentySeven/100.0*127.0;
}
