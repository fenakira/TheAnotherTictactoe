#include "CBoard.h"

CBoard::CBoard(int rowSize, int colSize) : Sprite(), tiles(rowSize, std::vector<int>(colSize)) {
	//Prepare random int generator between -1 and 1
	std::mt19937 gen(std::time(0));
	std::uniform_int_distribution<> dist(-1,1);

	for(auto& row : this->tiles)
		std::generate(row.begin(), row.end(), [&dist, &gen]() { return dist(gen); /* generate random number */});

	//Load graphics
	this->unit["o_graph"].loadFromFile("../assets/o.png");
	this->unit["x_graph"].loadFromFile("../assets/x.png");

	this->texture.create(this->tiles[0].size() * 24, this->tiles.size() * 24);
	this->update();

	this->setTexture(this->texture.getTexture());
}

void CBoard::setTileValue(int row, int col, int value) {
	this->tiles[row][col] = value;
}

void CBoard::update() {
	this->texture.clear(sf::Color(255, 255, 255, 255));

	for(size_t i = 0; i < this->tiles.size(); i++) {
		for(size_t j = 0; j < this->tiles[0].size(); j++) {
			if(this->tiles[i][j] > -1)
				this->_RenderCell(i * 24, j * 24, this->tiles[i][j]);
		}
	}
}

void CBoard::_RenderCell(int x, int y, int val) {
	sf::Sprite sprite;
	sprite.setPosition(sf::Vector2f(static_cast<float>(x), 
		                            static_cast<float>(y)));

	if (val == 0)
		sprite.setTexture(this->unit["o_graph"]);
	else if (val == 1) 
		sprite.setTexture(this->unit["x_graph"]);

	this->texture.draw(sprite);
}