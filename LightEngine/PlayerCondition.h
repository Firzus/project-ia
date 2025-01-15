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

class PlayerCondition_OnAdversaryHasBall: public Condition<Player>
{
public:
	bool OnTest(Player* owner) override;
};

class PlayerCondition_OnAllyHasBall : public Condition<Player>
{
public:
	bool OnTest(Player* owner) override;
};

class PlayerCondition_OnCatchBallByAlly : public Condition<Player>
{
public:
	bool OnTest(Player* owner) override;
};

class PlayerCondition_OnCatchBallByAdversary : public Condition<Player>
{
public:
	bool OnTest(Player* owner) override;
};

class PlayerCondition_OnPassedBallToAlly : public Condition<Player>
{
public:
	bool OnTest(Player* owner) override;
};

class PlayerCondition_OnLooseBallFromAdversary : public Condition<Player>
{
public:
	bool OnTest(Player* owner) override;
};
