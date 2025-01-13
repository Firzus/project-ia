#pragma once

#include "Entity.h"

class Ball : public Entity
{
public:
	void OnCollision(Entity* other) override;
};

