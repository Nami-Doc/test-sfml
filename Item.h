#pragma once
#include "Player.h"
#include "BehaviorManager.h"

class Item : public Entity
{
public:
	Item(const char* textureFile, uint x, uint y);
	~Item(void);
	void trigger(Player&);

private:
	typedef Entity super;
	void (*m_Behavior)(Player&);
};

