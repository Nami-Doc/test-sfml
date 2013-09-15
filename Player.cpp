#include "Player.h"

using namespace sf;

Player::Player(const char* const textureFile)
	: super(textureFile), m_XSpeed(0), m_YSpeed(0), m_Accel(1) {
}

void Player::updateSpeed() {
	if (Keyboard::isKeyPressed(Keyboard::Right)) {
		m_XSpeed = 1;
	} else if (Keyboard::isKeyPressed(Keyboard::Left)) {
		m_XSpeed = -1;
	} else {
		m_XSpeed = 0;
	}
	m_XSpeed *= m_Accel;

	if (Keyboard::isKeyPressed(Keyboard::Down)) {
		m_YSpeed = 1;
	} else if (Keyboard::isKeyPressed(Keyboard::Up)) {
		m_YSpeed = -1;
	} else {
		m_YSpeed = 0;
	}
	m_YSpeed *= m_Accel;
}

void Player::move() {
	updateSpeed();

	m_X += m_XSpeed;
	m_Y += m_YSpeed;
}

void Player::revertX() {
	m_X -= m_XSpeed;
}

void Player::revertY() {
	m_Y -= m_YSpeed;
}

Player::~Player() {
}
