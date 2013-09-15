#include <stdlib.h>
#include <iostream>
#include <SFML/Graphics.hpp>

#include "Player.h"
#include "Item.h"
#include "CollisionManager.h"

const int FPS_LIMIT = 60;

int main(int argc, char *argv[]) {
	sf::RenderWindow window(sf::VideoMode(192, 192), "SFML test");
	window.setFramerateLimit(FPS_LIMIT);

	Player player("marine.png");
	std::vector<Entity> obstacles;
	std::vector<Item> items;
	std::string obstacleMap = \
"  *\n\
_ _ _\n\
\n\
 _* p_\n\
\n\
_____";

	CollisionManager colMgr(&player, obstacleMap, 192, 192);

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			switch (event.type) {
				case sf::Event::Closed:
					window.close();
				break;
			}
		}

		player.move();
		colMgr.checkCollisions();
		player.updateSpritePosition();

		window.clear();
		window.draw(*player.getSprite());

		for (auto obstacle : colMgr.getObstacles()) {
			window.draw(*obstacle->getSprite());
		}
		for (auto item : colMgr.getItems()) {
			window.draw(*item->getSprite());
		}

		window.display();
	}

	return EXIT_SUCCESS;
}
