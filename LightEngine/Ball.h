#pragma once

#include "Entity.h"

class Ball : public Entity
{
private:
	Entity* mPlayer;

	bool mCanBeTaken = true;

public:
	void OnInitialize() override;
	void OnCollision(Entity* other) override;

	bool GetCanBeTaken() { return mCanBeTaken; }
	void SetCanBeTaken(bool canBeTaken) { mCanBeTaken = canBeTaken; }
};