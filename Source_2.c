#include <Windows.h>

//Form taraf�ndan g�nderilen mesajlar� al�yor ve gelen mesaja g�re i�lem yap�yoruz

const char _WindowClass [20] = "WindowClass"; //wc i�in i�in isimdir

LRESULT CALLBACK WndProc(HWND hwnd,UINT msg,WPARAM wParam,LPARAM lParam)
{
	switch (msg)
	{
	case WM_CLOSE: //form kapat�l�rken
		DestroyWindow(hwnd);
		break;
	case WM_DESTROY://form yok edilirken windowsa g�derilen mesaj
		PostQuitMessage(0);
	default:
		return DefWindowProc(hwnd, msg, wParam, lParam);
	}
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	WNDCLASSEX wc; //Pencere �zellikleri tan�mlanacak
	HWND hwnd; //Pencere kontrolunde kullanilacak
	MSG msg; //Mesaj i�in de�i�ken

	//Pencere �zelliklerini Kaydet
	//Registering thw Window Class
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.style = 0;
	wc.lpfnWndProc = WndProc;  //LRESULT CALLBACK fonksiyonun ad�, pencere mesajlar� oraya yollayacak
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION); //Pencere i�in gerekli icon
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);  // Pencere �zerinde iken fare i�ater�isi hangi �ekilde olacak
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);  //Pencere rengi
	wc.lpszMenuName = NULL;
	wc.lpszClassName = _WindowClass; //Tan�mlanan Bu yap�y� �a��rmak i�in kullan�lacak isim
	wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);  // Pencere i�in minik icon

	if (!RegisterClassEx(&wc))
	{
		MessageBoxA(NULL, "Window Registration Failed !", "Error!", MB_ICONEXCLAMATION | MB_OK);
		return 0;
	}

	//Step 2: Creating the Window
	//Pencereyi olu�turuyoruz

	hwnd = CreateWindowEx(WS_EX_CLIENTEDGE,
		_WindowClass,
		"The title of my Window",
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT, 240, 120,
		NULL, NULL, hInstance, NULL);
		if (hwnd == NULL)
		{
			MessageBoxA(NULL, "Window Creation Failed!", "Error!",
				MB_ICONEXCLAMATION | MB_OK);
			return 0;
		}

	ShowWindow(hwnd, nCmdShow); //Pencereyi g�sterir
	UpdateWindow(hwnd); //Pencereyi g�ncelle

	// Step 3: The Message Loop
	//Mesajlar�n al�nmas�
	while (GetMessage(&msg, NULL, 0, 0) > 0)
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.wParam;

}