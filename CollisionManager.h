#pragma once
#include <stdlib.h>
#include "Player.h"
#include "Item.h"

class CollisionManager
{
public:
	CollisionManager(Player* player, const std::string& map, uint maxX, uint maxY);
	~CollisionManager();
	void checkCollisions();
	std::vector<Entity> const& getObstacles() const { return m_Obstacles; };
	std::vector<Item> const& getItems() const { return m_Items; };

private:
	void parseMap(const std::string& map);

	Player* m_Player;
	std::vector<Entity> m_Obstacles;
	std::vector<Item> m_Items;
	uint m_MaxX;
	uint m_MaxY;
};
