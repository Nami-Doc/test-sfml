#pragma once
#include <stdlib.h>
#include "Player.h"
#include "Item.h"

class CollisionManager
{
public:
	CollisionManager(Player* const& player, const string& map, uint maxX, uint maxY);
	~CollisionManager();
	void checkCollisions();
	vector<Entity> const& getObstacles() const { return m_Obstacles; };
	vector<Item> const& getItems() const { return m_Items; };

private:
	void parseMap(const string& map);

	Player* m_Player;
	vector<Entity> m_Obstacles;
	vector<Item> m_Items;
	uint m_MaxX;
	uint m_MaxY;
};

