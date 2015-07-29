#pragma once

#include "entity_manager.h"
#include "game_state.h"

class test_state : public tiny_state
{
public:
	void Initialize(sf::RenderWindow* window);
	void Update(sf::RenderWindow* window);
	void Render(sf::RenderWindow* window);
	void Destroy(sf::RenderWindow* window);
private:
	EntityManager* manager;
};