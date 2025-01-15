#pragma once

#include "Entity.h"

class Player : public Entity
{
private:
	Entity* mBall;

protected:
	void OnInitialize() override;
	void OnCollision(Entity* other) override;
	void OnUpdate() override;

	friend class PlayerAction_;
	friend class PlantAction_Reloading;
	friend class PlantAction_Shooting;
};