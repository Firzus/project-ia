#pragma once

#include "Scene.h"

class Player;
class GoalZone;
class Ball;

class RugbyScene : public Scene
{
public:
	enum Tag
	{
		PLAYER_1,
		PLAYER_2,
		GOAL_ZONE_1,
		GOAL_ZONE_2,
		BALL
	};

private:
	Player* pPlayer1;
	Player* pPlayer2;
	GoalZone* pGoalZone1;
	GoalZone* pGoalZone2;
	Ball* pBall;

public:
	void OnInitialize() override;
	void OnEvent(const sf::Event& event) override;
	void OnUpdate() override;
};