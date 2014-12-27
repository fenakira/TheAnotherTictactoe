#include "CStatePlay.h"

#include "App.h"

#include <algorithm>
#include <random>
#include <ctime>

CStatePlay::CStatePlay() {
	/* bg color setup */
	auto windowWidth  = 800;
	auto windowHeight = 640;

	this->background.setPosition(0, 0);
	this->background.setSize(sf::Vector2f(windowWidth, windowHeight));
	this->background.setFillColor(sf::Color(255, 255, 255, 255));
}

void CStatePlay::OnEnter() {}
void CStatePlay::OnExit()  {}

void CStatePlay::OnEvent()  {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		App::GetInstance().RequestQuit();

}

void CStatePlay::OnUpdate()  {}
void CStatePlay::OnRender()  {
	// App::GetInstance().GetWindow()->draw(background);
	App::GetInstance().GetWindow()->draw(board);
}