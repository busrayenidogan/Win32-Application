#include <Windows.h>

//Form tarafından gönderilen mesajları alıyor ve gelen mesaja göre işlem yapıyoruz

const char _WindowClass [20] = "WindowClass"; //wc için için isimdir

LRESULT CALLBACK WndProc(HWND hwnd,UINT msg,WPARAM wParam,LPARAM lParam)
{
	switch (msg)
	{
	case WM_CLOSE: //form kapatılırken
		DestroyWindow(hwnd);
		break;
	case WM_DESTROY://form yok edilirken windowsa göderilen mesaj
		PostQuitMessage(0);
	default:
		return DefWindowProc(hwnd, msg, wParam, lParam);
	}
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	WNDCLASSEX wc; //Pencere özellikleri tanımlanacak
	HWND hwnd; //Pencere kontrolunde kullanilacak
	MSG msg; //Mesaj için değişken

	//Pencere Özelliklerini Kaydet
	//Registering thw Window Class
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.style = 0;
	wc.lpfnWndProc = WndProc;  //LRESULT CALLBACK fonksiyonun adı, pencere mesajları oraya yollayacak
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION); //Pencere için gerekli icon
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);  // Pencere üzerinde iken fare işaterçisi hangi şekilde olacak
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);  //Pencere rengi
	wc.lpszMenuName = NULL;
	wc.lpszClassName = _WindowClass; //Tanımlanan Bu yapıyı çağırmak için kullanılacak isim
	wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);  // Pencere için minik icon

	if (!RegisterClassEx(&wc))
	{
		MessageBoxA(NULL, "Window Registration Failed !", "Error!", MB_ICONEXCLAMATION | MB_OK);
		return 0;
	}

	//Step 2: Creating the Window
	//Pencereyi oluşturuyoruz

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

	ShowWindow(hwnd, nCmdShow); //Pencereyi gösterir
	UpdateWindow(hwnd); //Pencereyi güncelle

	// Step 3: The Message Loop
	//Mesajların alınması
	while (GetMessage(&msg, NULL, 0, 0) > 0)
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.wParam;

}