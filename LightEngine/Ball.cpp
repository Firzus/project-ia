#include "Ball.h"

#include "RugbyScene.h"

#include <iostream>

void Ball::OnInitialize()
{
	SetTag(RugbyScene::TagType::BALL);
}

void Ball::OnCollision(Entity* pCollidedWith)
{
	std::cout << "Ball::OnCollision" << std::endl;

	if (pCollidedWith->IsTag(RugbyScene::TagType::PLAYER))
	{
		if (mCanBeTaken)
		{
			mCanBeTaken = false;

			if (mPlayer != NULL)
			{
				mPlayer->SetHasBall(false);
			}

			mPlayer = pCollidedWith;
			mPlayer->SetHasBall(true);
			ResetTarget();
		}
	}
}

void Ball::ResetHoldable(bool canBeTaken)
{
	mCanBeTaken = canBeTaken;

	if (mPlayer != NULL)
	{
		mPlayer->SetHasBall(false);
	}

	mPlayer = NULL;
}
