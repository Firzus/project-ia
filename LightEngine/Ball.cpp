#include "Ball.h"

#include <iostream>

void Ball::OnCollision(Entity* other)
{
	std::cout << "Ball::OnCollision" << std::endl;
}
