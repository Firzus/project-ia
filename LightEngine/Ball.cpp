#include "Ball.h"

#include "RugbyScene.h"

#include <iostream>

void Ball::OnInitialize()
{
	SetTag(RugbyScene::Tag::BALL);
}

void Ball::OnCollision(Entity* pCollidedWith)
{
	std::cout << "Ball::OnCollision" << std::endl;

	if (pCollidedWith->IsTag(RugbyScene::Tag::GOAL_ZONE))
	{
		//GetScene<RugbyScene>()->OnDestroyZombie(mLane);

		Destroy();
	}
}
