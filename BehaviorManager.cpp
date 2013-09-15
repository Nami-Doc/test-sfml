#include "BehaviorManager.h"

void behaviorNoop(Player& /*player*/) {

}

void behaviorXSpeedUpgrade(Player& player) {
	player.setAccel(2);
}

BehaviorManager::BehaviorManager()
 : m_Behaviors{std::map<char, Behavior>()} {
	m_Behaviors['p'] = behaviorXSpeedUpgrade;
}

Behavior BehaviorManager::getBehavior(char name) {
	if (m_Behaviors.find(name) != m_Behaviors.end()) {
		return m_Behaviors[name];
	} else {
		std::cout << "Unable to find behavior '" << name << "'\n";
		return behaviorNoop;
	}
}

BehaviorManager::~BehaviorManager() {
}
