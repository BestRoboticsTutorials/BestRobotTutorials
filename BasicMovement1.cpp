
task main()
{
	while(true){
		motor[port1] = -vexRT(Ch3);
		motor[port10] = vexRT(Ch2);
	}

}
