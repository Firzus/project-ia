#pragma once

#include "Entity.h"

class Ball : public Entity
{
public:
	void OnInitialize() override;
	void OnCollision(Entity* other) override;
};