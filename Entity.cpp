#include "Entity.h"

/** Normal constructor.
 */
Entity::Entity(const char* textureFile, uint x, uint y)
  : m_X{x},
    m_Y{y},
    m_Texture{new sf::Texture()} {

	m_Texture->loadFromFile(textureFile);
	//m_Sprite = new sf::Sprite(*m_Texture.get());
	updateSpritePosition();
}

/** Used by Player::Player.
 */
Entity::Entity(const char* textureFile)
	: Entity(textureFile, 0, 0) {
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
	m_Sprite->setPosition(static_cast<float>(m_X), static_cast<float>(m_Y));
}

Entity::~Entity() {
    std::cout << "cya\n";
}
