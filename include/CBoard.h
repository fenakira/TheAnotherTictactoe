#ifndef _CBOARD_H_
#define _CBOARD_H_

#include <SFML/Graphics.hpp>

#include <vector>
#include <string>
#include <unordered_map>

class CBoard : public sf::Sprite 
{
public:
	CBoard() : CBoard(3, 3) {}
	CBoard(int rowSize, int colSize);

	void update();
	void setTileValue(int row, int col, int value);
private:
	void _RenderCell(int x, int y, int val);

	std::vector<std::vector<int>> tiles;
	std::unordered_map<std::string, sf::Texture> unit;
	sf::RenderTexture texture;
};
#endif
/* _CBOARD_H_ */
