#pragma once

#include "Entity.h"

class Player : public Entity
{
private:
	Entity* mBall;

protected:
	void OnUpdate() override;
	void OnInitialize() override;
	void OnCollision(Entity* other) override;

	friend class PlayerAction_;
	friend class PlantAction_Reloading;
	friend class PlantAction_Shooting;
};