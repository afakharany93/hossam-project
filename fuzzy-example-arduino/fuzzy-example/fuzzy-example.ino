#include "fuzzy.h"

fuzzy magic(9,1024,0,255,0);

int op = 0;	//output
int ch_op = 0;
int i = 0 ;	//input, sensor reading
void setup() 
{
	Serial.begin(115200);


}

void loop() 
{
	i = analogRead(A0);	//input
	ch_op = magic.fuzzy_controller(i , 200);	//input, setpoint
	op = op + ch_op;
	analogWrite(9, op);
	Serial.println(op);
	delay(100);	//sampling time


}
