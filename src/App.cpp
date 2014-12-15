#include "App.h"

#include "DxLib.h"
#include "CStatePlay.h"

#include <iostream>

App::App() {
	this->state = CStatePlay::GetInstance();
}

App& App::GetInstance() {
	static std::unique_ptr<App> instance(new App());

	return *instance;
}

int App::Run() {
	windowed = true;
	running  = true;

	ChangeWindowMode(windowed);
	SetGraphMode( 800 , 600 , 32 ) ;
	SetDrawScreen(DX_SCREEN_BACK);

	if( DxLib_Init() == -1 ) {
		return -1 ;
	}

	std::unique_ptr<CStatePlay> play(new CStatePlay());

	int prevTime = GetNowCount();
	while(running) {
		int nowTime     = GetNowCount(),
			elapsedTime = nowTime - prevTime;

		prevTime = nowTime;
		
		ProcessMessage();

		//Input handling pool
		if (CheckHitKey(KEY_INPUT_P)) {
			paused = !paused;
		}
		if (CheckHitKey(KEY_INPUT_W)) {
			windowed = !windowed;
			ChangeWindowMode(windowed);
		}

		this->GetCurrentState()->OnEvent();

		//Update pool
		this->GetCurrentState()->OnUpdate();

		//Rendering pool
		ClearDrawScreen();

		this->GetCurrentState()->OnRender();
	
		ScreenFlip();
	}

	DxLib_End();

	return 0;
}

void App::ChangeState(CState* newState) {
	this->state->OnExit();
	this->state = newState;
	this->state->OnEnter();
}