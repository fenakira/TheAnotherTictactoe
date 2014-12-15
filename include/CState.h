#ifndef _CSTATE_H_
#define _CSTATE_H_

class CState {
public:
	~CState() {}

	virtual void OnEnter() {}
	virtual void OnExit() {}

	virtual void OnEvent()  {}
	virtual void OnUpdate() {}
	virtual void OnRender() {}
};

#endif
/* _CSTATE_H_ */
