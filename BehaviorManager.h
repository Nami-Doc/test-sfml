#pragma once
#include <stdlib.h>
#include <map>
#include "Player.h"

typedef void (*Behavior)(Player&);
class BehaviorManager {
public:
	Behavior getBehavior(std::string name);
	static BehaviorManager& getInstance()
	{
		static BehaviorManager bm;
		return bm;
	}
	~BehaviorManager();

private:
	BehaviorManager();
	std::map<std::string, Behavior> m_Behaviors;
};
