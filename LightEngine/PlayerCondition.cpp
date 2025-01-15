#include "PlayerCondition.h"
#include "RugbyScene.h"

bool PlayerCondition_OnAdversaryHasBall::OnTest(Player* owner)
{
	return false;
}

bool PlayerCondition_OnAllyHasBall::OnTest(Player* owner)
{
	return false;
}

bool PlayerCondition_OnCatchBallByAlly::OnTest(Player* owner)
{
	return false;
}

bool PlayerCondition_OnCatchBallByAdversary::OnTest(Player* owner)
{
	return false;
}

bool PlayerCondition_OnPassedBallToAlly::OnTest(Player* owner)
{
	return false;
}

bool PlayerCondition_OnLooseBallFromAdversary::OnTest(Player* owner)
{
	return false;
}