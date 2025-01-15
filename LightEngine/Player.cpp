#include "Player.h"

#include "RugbyScene.h"

#include "StateMachine.h"
#include "PlayerAction.h"
#include "PlayerCondition.h"

#include <iostream>

void Player::OnUpdate()
{

}

void Player::OnInitialize()
{
	SetTag(RugbyScene::TagType::PLAYER);
}

void Player::OnCollision(Entity* other)
{
	std::cout << "Player::OnCollision" << std::endl;
}
