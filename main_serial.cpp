#include<iostream>
#include"Serial.h"
#include <TCHAR.h>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
#include <sstream>

CSerial serial;

void  serialInit() {
	serial.OpenSerialPort(_T("COM2:"), 115200, 8, 1);
}

int main(int argc, char** argv) {
	serialInit();
	int a;
	int t = 29;
	while (1)
	{	
		cin >> a;
		serial.ChangeSpeed(a);
		//Sleep(1000);
	}
	return 0;
}