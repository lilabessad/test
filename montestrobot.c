
// CODE DE RBOT ARM PRO

#include "RobotArmBaseLib.h"

int speed = 10;

void Event( int x )
{
	printf(" --------------------- ROBOT ARM PRO ---------------- ");
	printf(" ************* VEUILLEZ COMMENCER A MANIPULER VOTRE ROBOT ***************");
	
	switch(x)
	{
		case 0: { setLEDs(0b0000); break;} // Nothing happend!
		case 1: { Pos_Servo_1--; sleep(speed); break;}
		case 2: { Pos_Servo_1++; sleep(speed); break;}
		case 3: { Pos_Servo_2--; sleep(speed); break;}
		case 4: { Pos_Servo_2++; sleep(speed); break;}
		case 5: { Pos_Servo_3--; sleep(speed); break;}
		case 6: { Pos_Servo_3++; sleep(speed); break;}
		case 7: { Pos_Servo_4--; sleep(speed); break;}
		case 8: { Pos_Servo_4++; sleep(speed); break;}
		case 9: { Pos_Servo_5--; sleep(speed);break;}
		case 10: {  Pos_Servo_5++; sleep(speed);break;}
		case 11: {  Pos_Servo_6--; sleep(speed);break;}
		case 12: {  Pos_Servo_6++; sleep(speed);break;}
		case 13: 
			writeString_P("\n SPEED INCREASE +++"); 
			speed--; 
			if(speed < 2) speed = 1;
			setLEDs(0b0001); 
			mSleep(500);
			break;
		case 14: 
			writeString_P("\n SPEED DECREASE ---"); 
			speed++; 
			if(speed > 150) speed = 150;
			setLEDs(0b0010); 
			mSleep(500);
			break;
		case 15: 
			writeString_P("\n SPEED INCREASE +++"); 
			speed--; 
			if(speed < 2) speed = 1;
			setLEDs(0b0100); 
			mSleep(500);
			break;
		case 16: 
			writeString_P("\n SPEED DECREASE ---"); 
			speed++; 
			if(speed > 150) speed = 150;
			setLEDs(0b1000); 
			mSleep(500);
			break;
	}

}

int main ( void)
{
	
	initRobotBase();
	
	Servo_Power_And_Start();
	
	mSleep(800);
	
	
	speed = 10;
	Servo_Power_And_Start(); 
	mSleep(800);
	
	while(true)
	{
		Event(scan_keyboard());
		mSleep(10);
		
	}
	return 0;
	
}
	