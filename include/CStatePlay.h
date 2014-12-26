#ifndef _CSTATEPLAY_H_
#define _CSTATEPLAY_H_

#include "CState.h"

#include <SFML/Graphics.hpp>

#include <array>
#include <memory>
#include <string>
#include <unordered_map>

class CStatePlay :
	public CState 
{
public:	
	~CStatePlay() {}

	void OnEnter();
	void OnExit();

	void OnEvent();
	void OnUpdate();
	void OnRender();

	static CState* GetInstance() {
		static std::unique_ptr<CStatePlay> instance(new CStatePlay());

		return instance.get();
	}

private:
	CStatePlay();

	void _RenderCell(int x, int y, int val);

	std::array<std::array<int, 3>, 3> board;
	std::unordered_map<std::string, sf::Texture> graphics;
	sf::RectangleShape background;
};

#endif
/* _CSTATEPLAY_H_ */
