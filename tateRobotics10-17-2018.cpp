
task main()
{
	motor[port3] = 127;
	while (true){
		//drive
		motor[port2] = vexRT(Ch3);
		//claw
		if(VexRT(Btn7U)) {
			motor[port3] = 127;
		}
		else if(VexRT(Btn7D)){
			motor[port3] = -127;
		}
		//arm rotate
		motor[port4] = vexRT[ch1];
		//arm lift
		if(vexRT(Btn8U)){
			motor[port5] = 127;
		}
		else if(vexRT(Btn8D)){
			motor[port5] = -60;
		}
		else{
			motor[port5] = 0;
		}
	}

}
