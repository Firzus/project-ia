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
		PLAYER,
		GOAL_ZONE,
		BALL,
		TEAM_1,
		TEAM_2
	};

private:
	Player* pPlayer1;
	Player* pPlayer2;
	Player* pPlayer3;
	Player* pPlayer4;
	Player* pPlayer5;
	Player* pPlayer6;
	Player* pPlayer7;
	Player* pPlayer8;
	Player* pPlayer9;
	Player* pPlayer10;

	Ball* pBall;

	Player* pPlayerSelected;

private:
	void TrySetSelectedPlayer(Player* pPlayer, int x, int y);

public:
	void OnInitialize() override;
	void OnEvent(const sf::Event& event) override;
	void OnUpdate() override;
};