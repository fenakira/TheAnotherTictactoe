#ifndef _APP_H_
#define _APP_H_

#include <SFML/Graphics.hpp>
#include <memory>

class CState;

class App
{
public:
	static App& GetInstance();

	int Run();

	void ChangeState(CState* newState);
	CState* GetCurrentState() const { return state; }
	sf::RenderWindow* GetWindow() const { return this->window.get(); }

	void RequestQuit() { running = false; }
	void TogglePause() { paused = !paused; }

	bool IsPaused() { return paused; }
private:
	App();
	App(App const&);
	App operator=(App const&);

	bool running;
	bool paused;
	bool windowed;

	std::unique_ptr<sf::RenderWindow> window;
	CState* state;
};

#endif
/* _APP_H_ */
