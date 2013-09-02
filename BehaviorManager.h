#pragma once
#include <stdlib.h>
#include <map>
#include "Player.h"

using namespace std;

typedef void (*Behavior)(Player&);
class BehaviorManager {
public:
	Behavior getBehavior(string name);
	static BehaviorManager& getInstance()
	{
		static BehaviorManager bm;
		return bm;
	}
	~BehaviorManager();

private:
	BehaviorManager();
	map<string, Behavior> m_Behaviors;
};