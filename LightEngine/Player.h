#pragma once

#include "Entity.h"

class Player : public Entity
{
private:
	Entity* mBall;

public:
	Player();
	~Player();

	void OnInitialize() override;
	void OnCollision(Entity* other) override;
	void OnUpdate() override;
};