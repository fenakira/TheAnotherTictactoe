#include "CStatePlay.h"

#include "App.h"
#include <algorithm>
#include <random>
#include <ctime>

CStatePlay::CStatePlay() {
	//Prepare random int generator between -1 and 1
	std::mt19937 gen(std::time(0));
	std::uniform_int_distribution<> dist(-1,1);

	for(auto& row : this->board)
		std::generate(row.begin(), row.end(), [&dist, &gen]() { return dist(gen); /* generate random number */});

	//Load graphics
	this->graphics["o_graph"].loadFromFile("../assets/o.png");
	this->graphics["x_graph"].loadFromFile("../assets/x.png");

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
	App::GetInstance().GetWindow()->draw(background);

	for(size_t i = 0; i < this->board.size(); i++) {
		for(size_t j = 0; j < this->board[0].size(); j++) {
			if(this->board[i][j] > -1)
				this->_RenderCell(i * 24, j * 24, this->board[i][j]);
		}
	}
}

void CStatePlay::_RenderCell(int x, int y, int val) {
	sf::Sprite sprite;
	sprite.setPosition(sf::Vector2f(static_cast<float>(x), 
		                            static_cast<float>(y)));

	if (val == 0)
		sprite.setTexture(this->graphics["o_graph"]);
	else if (val == 1) 
		sprite.setTexture(this->graphics["x_graph"]);

	App::GetInstance().GetWindow()->draw(sprite);
}