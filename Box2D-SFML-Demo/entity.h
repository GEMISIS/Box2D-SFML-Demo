#pragma once

#include <SFML/Graphics.hpp>
#include <string>

#include <Box2D/Box2D.h>

class Entity : public sf::Sprite
{
public:
	sf::Vector2f velocity;

	Entity(b2World* world);

	virtual void Load(std::string filename, bool dynamic);

	virtual bool Update(sf::RenderWindow* window);

	bool CheckCollision(Entity* entity);

	virtual void Collision(Entity* entity);

	int GroupID();

	int Active();

	void Destroy();
	b2Body* body;

	~Entity();
protected:
	int active;
	int groupId;
	b2World* world;
	b2BodyDef* bodyDef;
	b2PolygonShape* shape;
	b2FixtureDef* fixtureDef;
private:
	sf::Texture* texture;
};

