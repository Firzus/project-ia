#pragma once

#include "Entity.h"

class Player : public Entity
{
public:
	void OnInitialize() override;
	void OnCollision(Entity* other) override;
};

