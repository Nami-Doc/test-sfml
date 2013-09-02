#pragma once
#include "Entity.h"

class Player : public Entity {
public:
	Player(const char* textureFile);
	~Player();
	void move();
	void revertX();
	void revertY();
	uint getAccel() const { return m_Accel; };
	void setAccel(uint speed) { m_Accel = speed; };

private:
	typedef Entity super;
	void updateSpeed();
	int m_XSpeed;
	int m_YSpeed;
	uint m_Accel;
};

