#define WIN32_LEAN_AND_MEAN

#include <windows.h>
#include "resource.h"

typedef enum {false,true} bool;

bool Prog_Init();
void Prog_Done();
void Prog_Loop();
/*----------------------*/
/*DEFINES				*/
/*----------------------*/

#define WINDOWCLASS "DAPLAYER" 										//name of our windows class
#define WINDOWTITLE "Diamond Age Player" 							// title of our application
						
/*----------------------*/						
/*GLOBALS				*/						
/*----------------------*/						
						
HINSTANCE hInstMain=NULL;											//main application handle
HWND hWndMain=NULL;													//main window handle

/*----------------------*/
/*WINDOWPROC			*/
/*----------------------*/

LRESULT CALLBACK TheWindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	switch(uMsg) {													//which message did we get?
		case WM_LBUTTONDOWN: {
			char szFileName[MAX_PATH];
			GetModuleFileName(hInstMain, szFileName, MAX_PATH);
			MessageBox(hwnd,szFileName, "This program is:", MB_OK | MB_ICONINFORMATION);
		}break;
		case WM_CLOSE: {											//the window is being closed
			DestroyWindow(hwnd);									//destroy the current window
			return(0);												//handled message, so return 0
		}break;
		case WM_DESTROY: {											//the window is being destroyed
			PostQuitMessage(0);										//tell the application we are quitting
			return(0);												//handled message, so return 0
		}break;						
		case WM_PAINT: {											//the window needs repainting
			PAINTSTRUCT ps;											//a variable needed for painting information
			HDC hdc=BeginPaint(hwnd,&ps);							//start painting
									
			/*painting code would go here*/						
									
			EndPaint(hwnd,&ps);										//end painting
			return(0);
		}break;
	}
	return(DefWindowProc(hwnd,uMsg,wParam,lParam));
}

/*----------------------*/
/*WINMAIN				*/
/*----------------------*/

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,LPSTR lpCmdLine, int nShowCmd) {
	hInstMain = hInstance;											//assign instance to global variable;
	WNDCLASSEX wcx;													//create window class
	wcx.cbSize=sizeof(WNDCLASSEX);									//set the size of the structure
	wcx.style = CS_OWNDC | CS_HREDRAW | CS_VREDRAW | CS_DBLCLKS;	//class style
	wcx.lpfnWndProc=TheWindowProc;									//window procedure
	wcx.cbClsExtra=0;												//class extra
	wcx.cbWndExtra=0;												//window extra
	wcx.hInstance=hInstMain;										//application handle
	wcx.hIcon=LoadIcon(hInstMain,MAKEINTRESOURCE(IDI_MYICON));		//icon
	wcx.hCursor=LoadCursor(NULL,IDC_ARROW);							//cursor
	wcx.hbrBackground=(HBRUSH)(COLOR_WINDOW+1);						//background color
	wcx.lpszMenuName=NULL;											//menu
	wcx.lpszClassName=WINDOWCLASS;									//class name
	wcx.hIconSm=NULL;												//small icon
	if(!RegisterClassEx(&wcx)) return(0);							//register the window class, return 0 if not successfull
	//create main window
	hWndMain=CreateWindowEx(0,WINDOWCLASS,WINDOWTITLE,WS_BORDER | WS_SYSMENU | WS_VISIBLE,0,0,320,240,NULL,NULL,hInstMain,NULL);
	if(!hWndMain) return(0);										//error check		
	if(!Prog_Init()) return(0);										//if program initialization failed, return with 0
	MSG msg;														//message structure
	for(;;) {														//message pump
		if(PeekMessage(&msg,NULL,0,0,PM_REMOVE)) {					//look for a message
			if(msg.message==WM_QUIT) break;							//check that we aren't quitting
			TranslateMessage(&msg);									//translate message
			DispatchMessage(&msg);									//dispatch message
		}
		Prog_Loop();												//run main game loop
	}
	Prog_Done();													//clean up program data
	return(msg.wParam);
}

/*----------------------*/
/*INITIALIZATION		*/
/*----------------------*/
bool Prog_Init() {
	
	/*your initialization code goes here*/
	
	return(true);													//return success
}

/*----------------------*/
/*CLEANUP				*/
/*----------------------*/

void Prog_Done() {

	/*cleanup code goes here*/

}

/*----------------------*/
/*MAIN GAME LOOP		*/
/*----------------------*/
void Prog_Loop() {

	/*main game logic goes here*/

}