#include "Player.h"

#include <iostream>

void Player::OnInitialize()
{
}

void Player::OnCollision(Entity* other)
{
	std::cout << "Player::OnCollision" << std::endl;
}
