#pragma once

#include <unordered_map>
#include <vector>

#include <Box2D/Box2D.h>

#include "entity.h"

class EntityManager
{
public:
	EntityManager();

	void Add(std::string name, Entity* entity);
	void Add(std::string name, std::string filename, bool dynamic);
	Entity* Get(std::string name);

	bool Update(sf::RenderWindow* window);
	void Render(sf::RenderWindow* window);

	~EntityManager();
private:
	std::unordered_map<std::string, Entity*> entities;

	b2World* world;
};