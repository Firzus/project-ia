#include "Player.h"

#include "RugbyScene.h"

#include <iostream>

void Player::OnInitialize()
{
	SetTag(RugbyScene::Tag::PLAYER);
}

void Player::OnCollision(Entity* other)
{
	std::cout << "Player::OnCollision" << std::endl;
}
