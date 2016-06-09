
// Includes:

#include "RobotArmBaseLib.h"// The Robotarm Robot Library.
							// Always needs to be included!

int speed = 10;

void Event( int x )
{
	switch(x){
	    case 0: { setLEDs(0b0000); break;} // Nothing happend!

		case 1: { Pos_Servo_1--;
			Pos_Servo_1--;
			Pos_Servo_1--;
			Pos_Servo_1--;
			writeString_P("La pince se ferme \n"); break;}
		case 2: { Pos_Servo_1++;
			Pos_Servo_1++;
			Pos_Servo_1++;
			Pos_Servo_1++;
            writeString_P("La pince s'ouvre \n"); break;}

		case 3: { Pos_Servo_2--;
			Pos_Servo_2--;
			Pos_Servo_2--;
			Pos_Servo_2--; writeString_P("servo 2 se tourne à droite \n"); break;}
		case 4: { Pos_Servo_2++;
			Pos_Servo_2++;
			Pos_Servo_2++;
			Pos_Servo_2++;
			Pos_Servo_2++; writeString_P("servo 2 se tourne à gauche\n");
		//s_Move(2, 1000,4);
		 break;}

		case 5: { Pos_Servo_3--;
			Pos_Servo_3--;
			Pos_Servo_3--;
			Pos_Servo_3--; writeString_P("servo 3 s'incline vers le bas \n"); break;}
		case 6: {  Pos_Servo_3++;
			Pos_Servo_3++;
			Pos_Servo_3++;
			Pos_Servo_3++; writeString_P("servo 3 s'incline vers le haut \n"); break;}

		case 7: { Pos_Servo_4--;
			Pos_Servo_4--;
			Pos_Servo_4--;
			Pos_Servo_4;  sleep(speed); writeString_P("servo 4 s'incline vers le haut\n"); break;}
		case 8: { Pos_Servo_4++;
			Pos_Servo_4++;
			Pos_Servo_4++;
			Pos_Servo_4++;; writeString_P("servo 4 s'incline vers le bas\n"); break;}

		case 9: { Pos_Servo_5--;
			Pos_Servo_5--;
			Pos_Servo_5--;
			Pos_Servo_5--; writeString_P("servo 5 s'incline vers le haut\n"); break;}
		case 10: {  Pos_Servo_5++;
			Pos_Servo_5++;
			Pos_Servo_5++;
			Pos_Servo_5++; writeString_P("servo 5 s'incline vers le bas\n"); break;}

		case 11: {  Pos_Servo_6--;
			Pos_Servo_6--;
			Pos_Servo_6--;
			Pos_Servo_6--; writeString_P("servo 6 se tourne à droite\n"); break;}
		case 12: {  Pos_Servo_6++;
			Pos_Servo_6++;
			Pos_Servo_6++;
			Pos_Servo_6++; writeString_P("servo 6 se tourne à gauche\n"); break;}

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


/*****************************************************************************/
// Main function - The program starts here:

int main(void)
{
	initRobotBase(); 	// Always call this first! The Processor will not work
						// correctly otherwise.
	mSleep(1000);        // delay 1s

	speed = 10; //Speed for servo from '0'(fast) - '10'(slow)

	writeString_P("\n Key Board Control - Press a Key!\n\n");

	Servo_Power_And_Start(); // This powers on the servos and moves them to
							 // the start position.
							 // When you want to power off the servos,
							 // you need to call the function Power_Off_Servos();

	mSleep(800);

	setLEDs(0b0000);

	// ---------------------------------------
	// Main loop:
	while(true)
	{
		Event(scan_keyboard());
		mSleep(1);

	// End of main loop!
	// ---------------------------------------
	}
	return 0;
}
