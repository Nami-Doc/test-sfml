#pragma once
#include <stdlib.h>
#include <map>
#include "Player.h"

typedef void (*Behavior)(Player&);
class BehaviorManager {
public:
	Behavior getBehavior(char name);
	static BehaviorManager& getInstance()
	{
		static BehaviorManager bm;
		return bm;
	}
	~BehaviorManager();

private:
	BehaviorManager();
	std::map<char, Behavior> m_Behaviors;
};
