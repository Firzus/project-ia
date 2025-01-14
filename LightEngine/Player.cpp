#include "Player.h"

#include "RugbyScene.h"

#include <iostream>

Player::Player()
{
}

Player::~Player()
{
}

void Player::OnInitialize()
{
	SetTag(RugbyScene::Tag_Type::PLAYER);
}

void Player::OnCollision(Entity* other)
{
	std::cout << "Player::OnCollision" << std::endl;

	if (other->IsTag(RugbyScene::Tag_Type::BALL))
	{
		mBall = other;
	}
}

void Player::OnUpdate()
{
	if (mHasBall)
	{
		if (IsTagTeam(RugbyScene::Tag_Team::TEAM_1))
		{
			mBall->SetPosition(GetPosition().x + GetRadius() + 15, GetPosition().y);
		}
		else if (IsTagTeam(RugbyScene::Tag_Team::TEAM_2))
		{
			mBall->SetPosition(GetPosition().x - GetRadius() - 15, GetPosition().y);
		}
	}
}
