#ifndef _CSTATEPLAY_H_
#define _CSTATEPLAY_H_

#include "CState.h"
#include "CBoard.h"

#include <SFML/Graphics.hpp>

#include <memory>

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

	CBoard board;
	sf::RectangleShape background;
};

#endif
/* _CSTATEPLAY_H_ */
