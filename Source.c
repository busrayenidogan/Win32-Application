#include <Windows.h>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	MessageBox(NULL,"ereborlugimli","LOTR",MB_OK);
	return 0;
}

/*
HINSTANCE hInstance
Programlar�n y�r�t�lebilir mod�l�ne (bellekte .exe dosyas�) y�nlendirme

HINSTANCE hPrevInstance
Her zaman NULLWin32 programlar� i�in.

LPSTR lpCmdLine
Komut sat�r� ba��ms�z de�i�kenleri tek bir dize olarak. Program ad� dahil DE��LD�R.

int nCmdShow
Ge�irilebilmektedir bir tam say� de�eri ShowWindow(). Bunu daha sonra halledece�iz.
*/