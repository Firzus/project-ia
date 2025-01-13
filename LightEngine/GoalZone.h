#pragma once

#include "Entity.h"

class GoalZone : public Entity
{
public:
	void OnCollision(Entity* pEntity) override;
};

