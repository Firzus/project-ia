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

	if (pCollidedWith->IsTag(RugbyScene::TagType::GOAL_ZONE))
	{
		//GetScene<RugbyScene>()->OnDestroyZombie(mLane);

		Destroy();
	}
}
