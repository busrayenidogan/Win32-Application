#include <Windows.h>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	MessageBoxA(NULL,"ereborlugimli","LOTR",MB_OK);
	return 0;
}

/*
MessageBoxA = ANSII
MessageBoxW = Unicode
MessageBox(NULL, L"Test", L"Test", MB_OK);

HINSTANCE hInstance
Programların yürütülebilir modülüne (bellekte .exe dosyası) yönlendirme

HINSTANCE hPrevInstance
Her zaman NULLWin32 programları için.

LPSTR lpCmdLine
Komut satırı bağımsız değişkenleri tek bir dize olarak. Program adı dahil DEĞİLDİR.

int nCmdShow
Geçirilebilmektedir bir tam sayı değeri ShowWindow(). Bunu daha sonra halledeceğiz.
*/
