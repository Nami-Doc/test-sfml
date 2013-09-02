#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "NonCopyable.h"

using uint = unsigned int;

class Entity : public NonCopyable
{
public:
	Entity(const char* textureFile, uint x, uint y);
	Entity(const char* textureFile);
	~Entity();
	void loadSprite(const char* textureFile);
	void updateSpritePosition();
	sf::Sprite const& getSprite() const { return m_Sprite; };
	sf::IntRect const getBoundingBox() const;
	int getX() const { return m_X; };
	void setX(uint x) { m_X = x; };
	int getY() const { return m_Y; };
	void setY(uint y) { m_Y = y; };

protected:
	sf::Texture m_Texture;
	sf::Sprite m_Sprite;
	// might be negative while moving
	int m_X;
	int m_Y;
};
