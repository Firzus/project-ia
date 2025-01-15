#pragma once

#include "Entity.h"

class Player : public Entity
{
public:
	void OnCollision(Entity* other) override;

protected:
	void OnUpdate() override;
	void OnInitialize() override;

	friend class PlayerAction_;
	friend class PlantAction_Reloading;
	friend class PlantAction_Shooting;
};