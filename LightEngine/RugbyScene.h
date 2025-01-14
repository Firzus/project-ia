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

	std::vector<Player*> mPlayers;

	Ball* pBall;

	Player* pPlayerSelected;

	bool mBallWait = false;
	float mBallHoldDelayClock = 0;
	float mBallHoldDelay = 100;

	bool mBallIsBeingPassed = false;
	float mBallPassDelayClock = 0;
	float mBallPassDelay = 40;

	int mTeam1Points = 0;
	int mTeam2Points = 0;
	int mTeamWhoLostPoint = -1;

	bool isMatchPlaying = false;

public:
	void OnInitialize() override;
	void OnEvent(const sf::Event& event) override;
	void OnUpdate() override;
	Player* CreatePlayer(float radius, const sf::Color& color, float x, float y, float ratioX, float ratioY, int tagTeam);
	void PassBall(float x, float y);

	bool IsMatchPlaying() const { return isMatchPlaying; }

	void SetBallDelay(bool setDelay) { mBallWait = setDelay; }
	std::vector<Player*> GetPlayerList() { return mPlayers; }
	Ball* GetBall() { return pBall; }

private:
	void TrySetSelectedPlayer(Player* pPlayer, int x, int y);
	void NewSleeve();
	void NewGame();
};