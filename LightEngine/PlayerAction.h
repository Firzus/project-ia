#pragma once

#include "Action.h"
#include "Player.h"

class PlayerAction_Rush : public Action<Player>
{
private:

public:
	void OnStart(Player* pPlayer) override;
	void OnUpdate(Player* pPlayer) override;
	void OnEnd(Player* pPlayer) override;
};

class PlayerAction_ScoreGoal: public Action<Player>
{
private:

public:
	void OnStart(Player* pPlayer) override;
	void OnUpdate(Player* pPlayer) override;
	void OnEnd(Player* pPlayer) override;
};

class PlayerAction_Support: public Action<Player>
{
private:

public:
	void OnStart(Player* pPlayer) override;
	void OnUpdate(Player* pPlayer) override;
	void OnEnd(Player* pPlayer) override;
};