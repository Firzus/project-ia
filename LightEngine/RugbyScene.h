#pragma once

#include "Scene.h"

class Player;
class GoalZone;
class Ball;

class RugbyScene : public Scene
{
public:
	enum TagType
	{
		PLAYER,
		BALL
	};

	enum TagTeam
	{
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

	bool mBallWait = false;
	float mBallDelayClock = 0;
	float mBallDelay = 100;

	int mTeam1Points = 0;
	int mTeam2Points = 0;

public:
	void OnInitialize() override;
	void OnEvent(const sf::Event& event) override;
	void OnUpdate() override;

	void SetBallDelay(bool setDelay) { mBallWait = setDelay; }

private:
	void TrySetSelectedPlayer(Player* pPlayer, int x, int y);
};