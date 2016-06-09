
#include "RobotArmBaseLib.h"// librairie du robot

int speed;
uint8_t bytesToReceive;
char receiveBuffer[3];



void Leds_Beeper (void)
{
	changeBeepsound(150);
	setBeepsound();
	PowerLEDred();
	mSleep(500);

	changeBeepsound(200);
	PowerLEDgreen();
	mSleep(500);

	changeBeepsound(255);
	PowerLEDorange();
	mSleep(500);

	PowerLEDoff();
	clearBeepsound();
}


void askAQuestion(void)
{
	uint8_t i=0;

	receiveBytes(1);
	mSleep(10);
	//waitUntilReceptionComplete();
	copyReceivedBytesToBuffer(&receiveBuffer[0]);


	if(receiveBuffer[0] == '1') //&& receiveBuffer[1] == '0')
	{
		Pos_Servo_1--;
		Pos_Servo_1--;
		Pos_Servo_1--;
		Pos_Servo_1--;
		writeString_P("La pince se ferme \n");


		//s_Move(1, -1000,4);
	}

	if(receiveBuffer[0] == '2') //&& receiveBuffer[1] == '1')
	{
		Pos_Servo_1++;
		Pos_Servo_1++;
		Pos_Servo_1++;
		Pos_Servo_1++;
		writeString_P("La pince s'ouvre \n");

		//s_Move(1, 1000,4);

	}

	if(receiveBuffer[0] == '3') //&& receiveBuffer[1] == '2')
	{
		Pos_Servo_2--;
		Pos_Servo_2--;
		Pos_Servo_2--;
		Pos_Servo_2--;
		writeString_P("servo 2 se tourne à droite \n");

		//s_Move(2, -1000,4);

	}

	if(receiveBuffer[0] == '4')// && receiveBuffer[1] == '3')
	{
		Pos_Servo_2++; //mSleep(500);
		Pos_Servo_2++;
		Pos_Servo_2++;
		Pos_Servo_2++;
		writeString_P("servo 2 se tourne à gauche\n");
		//s_Move(2, 1000,4);
	}

	if(receiveBuffer[0] == '5')// && receiveBuffer[1] == '4')
	{
		Pos_Servo_3--; //mSleep(500);
		Pos_Servo_3--;
		Pos_Servo_3--;
		Pos_Servo_3--;
		writeString_P("servo 3 s'incline vers le bas \n");
		//s_Move(3, -1000,4);
	}

	if(receiveBuffer[0] == '6')// && receiveBuffer[1] == '5')
	{
		Pos_Servo_3++; //mSleep(500);
		Pos_Servo_3++;
		Pos_Servo_3++;
		Pos_Servo_3++;
		writeString_P("servo 3 s'incline vers le haut \n");
		//s_Move(3, 1000,4);
	}

	if(receiveBuffer[0] == '7')// && receiveBuffer[1] == '6')
	{
		Pos_Servo_4--; //mSleep(500);
		Pos_Servo_4--;
		Pos_Servo_4--;
		Pos_Servo_4--;
		writeString_P("servo 4 s'incline vers le haut\n");
		//s_Move(4, -1000,4);
	}

	if(receiveBuffer[0] == '8')// && receiveBuffer[1] == '7')
	{
		Pos_Servo_4++; //mSleep(500);
		Pos_Servo_4++;
		Pos_Servo_4++;
		Pos_Servo_4++;
		writeString_P("servo 4 s'incline vers le bas\n");
		//s_Move(4, 1000,4);
	}

	if(receiveBuffer[0] == '9')// && receiveBuffer[1] == '8')
	{
		Pos_Servo_5--; //mSleep(500);
		Pos_Servo_5--;
		Pos_Servo_5--;
		Pos_Servo_5--;
		writeString_P("servo 5 s'incline vers le haut\n");
		//s_Move(5, -1000,4);
	}

	if(receiveBuffer[0] == 'a')// && receiveBuffer[1] == '9')
	{
		Pos_Servo_5++; //mSleep(500);
		Pos_Servo_5++;
		Pos_Servo_5++;
		Pos_Servo_5++;
		writeString_P("servo 5 s'incline vers le bas\n");
		//s_Move(5, 1000,4);
	}

	if(receiveBuffer[0] == 'b')// && receiveBuffer[1] == '0')
	{
		Pos_Servo_6--; //mSleep(500);
		Pos_Servo_6--;
		Pos_Servo_6--;
		Pos_Servo_6--;
		writeString_P("servo 6 se tourne à droite\n");
		//s_Move(6, -1000,4);
	}

	if(receiveBuffer[0] == 'c')// && receiveBuffer[1] == '1')
	{
		Pos_Servo_6++; //mSleep(500);
		Pos_Servo_6++;
		Pos_Servo_6++;
		Pos_Servo_6++;
		writeString_P("servo 6 se tourne à gauche\n");
		//s_Move(6, 1000,4);
	}
}

int main(void)
{

	initRobotBase(); // Always call this first! The Processor will not work
					 // correctly otherwise.

	Servo_Power_And_Start();

	mSleep(800);

	Leds_Beeper();

	speed = 1;



	//writeString_P("\nHello! My name is RobotArmy\n");

	while(true)
	{
		writeString_P("Entrer commande\n");
		askAQuestion();
		writeString_P("Commande bien recu\n");

	}
	return 0;
}


/*	char receiveBuffer[bytesToReceive]; // intialiser le tableau, avec ByteToReceive:nombre de caractere à recevoir
	receiveBytes(bytesToReceive);// lecture du port usb pour recevoir les caracteres
	waitUntilReceptionComplete(); // on s'en fout mais on est obliger de le mettre!
	copyReceivedBytesToBuffer(&receiveBuffer[0]); // copy les caractere recu dans notre tableau de caractere
	writeStringLength(&receiveBuffer[0],bytesToReceive,0); // Affiche le tableau
	writeString_P("\" !\n");*/


/*if(getUARTReceiveStatus() != UART_BUISY)
		{
			copyReceivedBytesToBuffer(&receiveBuffer[0]);



			if(receiveBuffer[0]=='o' && receiveBuffer[1]=='k' )
			*/
