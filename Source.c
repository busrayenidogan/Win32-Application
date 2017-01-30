#include <Windows.h>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	MessageBox(NULL,"ereborlugimli","LOTR",MB_OK);
	return 0;
}

/*
HINSTANCE hInstance
Programlarýn yürütülebilir modülüne (bellekte .exe dosyasý) yönlendirme

HINSTANCE hPrevInstance
Her zaman NULLWin32 programlarý için.

LPSTR lpCmdLine
Komut satýrý baðýmsýz deðiþkenleri tek bir dize olarak. Program adý dahil DEÐÝLDÝR.

int nCmdShow
Geçirilebilmektedir bir tam sayý deðeri ShowWindow(). Bunu daha sonra halledeceðiz.
*/