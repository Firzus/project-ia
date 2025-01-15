#include "Player.h"

#include "RugbyScene.h"

#include "StateMachine.h"
#include "PlayerAction.h"
#include "PlayerCondition.h"

#include <iostream>

void Player::OnInitialize()
{
	SetTag(RugbyScene::TagType::PLAYER);
}

void Player::OnCollision(Entity* other)
{
	std::cout << "Player::OnCollision" << std::endl;

	if (other->IsTag(RugbyScene::TagType::BALL))
	{
		mBall = other;
	}
}

void Player::OnUpdate()
{
	if (mHasBall)
	{
		if (IsTagTeam(RugbyScene::TagTeam::TEAM_1))
		{
			mBall->SetPosition(GetPosition().x + GetRadius() + 15, GetPosition().y);
		}
		else if (IsTagTeam(RugbyScene::TagTeam::TEAM_2))
		{
			mBall->SetPosition(GetPosition().x - GetRadius() - 15, GetPosition().y);
		}
	}
}

void Player::MakeAPass()
{
	Player* nearestTeammate = NULL;
	float shortestDistance = 10000000;

	RugbyScene* rugbyScene = GetScene<RugbyScene>();

	// Search for the nearest player of the same team of the player holding the ball (excluding himself)
	for (int i = 0; i < rugbyScene->GetPlayerList().size(); i++)
	{
		if (rugbyScene->GetPlayerList()[i]->IsTagTeam(GetTagTeam()))
		{
			if (rugbyScene->GetPlayerList()[i] != this)
			{
				float distance = std::pow(GetPosition().x - rugbyScene->GetPlayerList()[i]->GetPosition().x, 2) +
					std::pow(GetPosition().y - rugbyScene->GetPlayerList()[i]->GetPosition().y, 2);

				if (distance < shortestDistance)
				{
					nearestTeammate = rugbyScene->GetPlayerList()[i];
					shortestDistance = distance;
				}
			}
		}
	}

	if (nearestTeammate != NULL)
	{
		rugbyScene->PassBall(nearestTeammate->GetPosition().x, nearestTeammate->GetPosition().y);
	}
}
