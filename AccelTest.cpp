long Ax = 0;
long Ay = 0;
long Az = 0;
task main()
{
	while(true){
		Ax = vexRT[AccelX];
		Ay = vexRT[AccelY];
		Az = vexRT[AccelZ];
		motor[port1] = 75;

	}
}
