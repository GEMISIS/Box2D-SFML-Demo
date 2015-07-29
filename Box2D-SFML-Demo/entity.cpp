#include "entity.h"

Entity::Entity(b2World* world)
{
	this->texture = new sf::Texture();
	this->active = 1;
	this->groupId = 0;
	this->world = world;
}

void Entity::Load(std::string filename, bool dynamic)
{
	this->texture->loadFromFile("Graphics/sprites/" + filename);
	this->setTexture(*this->texture);

	this->bodyDef = new b2BodyDef();
	if (dynamic)
	{
		this->bodyDef->type = b2_dynamicBody;
	}
	else
	{
		this->bodyDef->type = b2_staticBody;
	}
	this->bodyDef->position.Set(this->getPosition().x, this->getPosition().y);
	this->body = this->world->CreateBody(this->bodyDef);

	this->shape = new b2PolygonShape();
	this->shape->SetAsBox(this->texture->getSize().x * 0.5f - b2_polygonRadius, this->texture->getSize().y * 0.5f - b2_polygonRadius);

	this->fixtureDef = new b2FixtureDef();
	this->fixtureDef->shape = this->shape;

	if (dynamic)
	{
		this->fixtureDef->density = 1.0f;
		this->fixtureDef->friction = 0.3f;
		this->body->CreateFixture(this->fixtureDef);
	}
	else
	{
		this->body->CreateFixture(this->shape, 0);
	}
}

bool Entity::Update(sf::RenderWindow* window)
{
	b2Vec2 pos = this->body->GetPosition();
	float32 rot = this->body->GetAngle();
	this->setPosition(pos.x, -pos.y);
	this->setRotation(rot);
	return true;
}
void Entity::Collision(Entity* entity)
{
}

bool Entity::CheckCollision(Entity* entity)
{
	return this->getGlobalBounds().intersects(entity->getGlobalBounds());
}

int Entity::GroupID()
{
	return this->groupId;
}

int Entity::Active()
{
	return this->active;
}

void Entity::Destroy()
{
	this->active = 0;
}

Entity::~Entity()
{
	delete this->texture;
	delete this->bodyDef;
	delete this->shape;
	delete this->fixtureDef;
}