

#include <TCHAR.h>
#include <windows.h>
#include <process.h>
#include <string.h>
#include <iostream>

class CSerial
{
public:
	CSerial(void);
	~CSerial(void);

	//打开串口
	BOOL OpenSerialPort(TCHAR* port, UINT baud_rate, BYTE date_bits, BYTE stop_bit, BYTE parity = NOPARITY);

	//发送数据
	BOOL SendData(char* data, int len);


	void ChangeSpeed(int speed);
	void SendChar(char c);
public:
	HANDLE m_hComm;
};
