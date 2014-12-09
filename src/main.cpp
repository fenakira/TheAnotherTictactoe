#include "DxLib.h"

#include "App.h"

int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance,
						LPSTR lpCmdLine, int nCmdShow )
{
	return App::GetInstance().Run();
}
