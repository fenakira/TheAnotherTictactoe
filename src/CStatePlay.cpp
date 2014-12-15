#include "CStatePlay.h"

#include "App.h"
#include "DxLib.h"

void CStatePlay::OnEnter() {}
void CStatePlay::OnExit()  {}

void CStatePlay::OnEvent()  {
	if (CheckHitKey(KEY_INPUT_ESCAPE))
		App::GetInstance().RequestQuit();

}
void CStatePlay::OnUpdate()  {}
void CStatePlay::OnRender()  {
	printfDx("Hello World!");
}