#pragma once

#include "Condition.h"
#include "Player.h"

class PlayerCondition_OnMatchStart : public Condition<Player>
{
public:
	bool OnTest(Player* owner) override;
};

class PlayerCondition_OnMatchEnd : public Condition<Player>
{
public:
	bool OnTest(Player* owner) override;
};