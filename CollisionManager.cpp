#include "CollisionManager.h"

using namespace std;

CollisionManager::CollisionManager(Player* player, const string& map, uint maxX, uint maxY)
 : m_Player{player},
    m_MaxX{maxX},
    m_MaxY{maxY},
    m_Obstacles{vector<Entity>()},
    m_Items{vector<Item>()} {

	parseMap(map);
}

void CollisionManager::parseMap(const string& map) {
	int line = 0; int caret = 0;
	for (int i = 0, l = map.length(); i < l; ++i) {
		string c(&map[i], 1);

		int x = caret * 32;
		int y = line * 32;
		if (c == "*") {
			m_Player->setX(x);
			m_Player->setY(y);
		} else if (c != "\n" && c != " ") {
			if (c == "_") {
				m_Obstacles.emplace_back("wall.jpg", x, y);
			} else {
				m_Items.emplace_back((c + ".png").c_str(), x, y);
			}
		}

		if (c == "\n") {
			++line;
			caret = 0;
		} else {
			++caret;
		}
	}
}

void CollisionManager::checkCollisions() {
	// if we're colliding with an obstacle AND with
	// a boundary, we shouldn't revert[XY] more than once
	bool hasXReset = false, hasYReset = false;

	int entitySize = 32;
	int maxX = m_MaxX - entitySize;

	if (m_Player->getX() < 0) {
		hasXReset = true;
		m_Player->setX(0);
	} else if (m_Player->getX() > maxX) {
		hasXReset = true;
		m_Player->setX(maxX);
	}

	int maxY = m_MaxY - entitySize;
	if (m_Player->getY() < 0) {
		hasYReset = true;
		m_Player->setY(0);
	} else if (m_Player->getY() > maxY) {
		hasYReset = true;
		m_Player->setY(maxY);
	}

	if (hasXReset && hasYReset) {
		return;
	}

	sf::IntRect boundingBox = m_Player->getBoundingBox();

	for (Entity& obstacle : m_Obstacles) {
		if (boundingBox.intersects(obstacle.getBoundingBox())) {
			if (!hasXReset) {
				m_Player->revertX();
			}
			if (!hasYReset) {
				m_Player->revertY();
			}
			break;
		}
	}

	for (auto& item = m_Items.begin(); item != m_Items.end();) {
		if (boundingBox.intersects(item->getBoundingBox())) {
			item->trigger(*m_Player);
			m_Items.erase(item);
			break;
		}
		++item;
	}
}

CollisionManager::~CollisionManager() {
}
