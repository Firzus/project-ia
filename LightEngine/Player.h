#pragma once

#include "Entity.h"

class Player : public Entity
{
private:
	Entity* mBall;

public:
	void MakeAPass();

protected:
	void OnInitialize() override;
	void OnCollision(Entity* other) override;
	void OnUpdate() override;

	friend class PlayerAction_Idle;
	friend class PlayerAction_Rush;
	friend class PlayerAction_ScoreGoal;
	friend class PlayerAction_Support;

	friend class PlayerCondition_OnAdversaryHasBall;
	friend class PlayerCondition_OnAllyHasBall;
	friend class PlayerCondition_OnCatchBallByAlly;
	friend class PlayerCondition_OnCatchBallByAdversary;
	friend class PlayerCondition_OnPassedBallToAlly;
	friend class PlayerCondition_OnLooseBallFromAdversary;
};