#include "Entity.h"

/** Normal constructor.
 */
Entity::Entity(const char* const textureFile, uint x, uint y)
	: m_X(x), m_Y(y), m_Texture(sf::Texture()) {
	m_Texture.loadFromFile(textureFile);
	m_Sprite = sf::Sprite(m_Texture);
	updateSpritePosition();
}

/** Used by Player::Player.
 */
Entity::Entity(const char* const textureFile)
	: m_X(0), m_Y(0), m_Texture(sf::Texture()) {
	m_Texture.loadFromFile(textureFile);
	m_Sprite = sf::Sprite(m_Texture);
}

sf::IntRect const Entity::getBoundingBox() const {
	sf::IntRect boundingBox;
	boundingBox.left = static_cast<uint>(m_X);
	boundingBox.top = static_cast<uint>(m_Y);
	boundingBox.width = boundingBox.height = 32;

	return boundingBox;
}

/* Updates sprite's X and Y.
 */
void Entity::updateSpritePosition() {
	m_Sprite.setPosition(static_cast<float>(m_X), static_cast<float>(m_Y));
}

Entity::~Entity() {
}
