#include "App.h"

#include "GameStates.h"
#include <chrono>

App::App() :
	window(new sf::RenderWindow(sf::VideoMode(640, 480), "SFML works!")) 
{
	this->GetWindow()->setFramerateLimit(60);

	this->state = CStatePlay::GetInstance();
} 

App& App::GetInstance() {
	static std::unique_ptr<App> instance(new App());

	return *instance;
}

int App::Run() {
	windowed = true;
	running  = true;

	auto prevTime = std::chrono::system_clock::now();
	while(running) {
		auto nowTime     = std::chrono::system_clock::now();
		auto elapsedTime = nowTime - prevTime;

		prevTime = nowTime;
		
		sf::Event event;

		//Event pool
		while(this->GetWindow()->pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				running = false;

			this->GetCurrentState()->OnEvent();
		}

		//Update pool
		this->GetCurrentState()->OnUpdate();

		//Rendering pool
		this->GetWindow()->clear();

		this->GetCurrentState()->OnRender();
	
		this->GetWindow()->display();
	}

	this->GetWindow()->close();

	return 0;
}

void App::ChangeState(CState* newState) {
	this->state->OnExit();
	this->state = newState;
	this->state->OnEnter();
}