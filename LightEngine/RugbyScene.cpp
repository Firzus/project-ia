#include "RugbyScene.h"

#include "Player.h"
#include "Ball.h"
#include "Debug.h"
#include <iostream>

void RugbyScene::OnInitialize()
{
	pBall = CreateEntity<Ball>(15, sf::Color::Green);
	pBall->SetPosition(625, 345);
	pBall->SetRigidBody(true);

	// Team 1 players
	mPlayers.push_back(CreatePlayer(30, sf::Color::Magenta, 200, 135, 1, 1, TEAM_1));
	mPlayers.push_back(CreatePlayer(30, sf::Color::Magenta, 290, 215, 1, 1, TEAM_1));
	mPlayers.push_back(CreatePlayer(30, sf::Color::Magenta, 440, 375, 1, 1, TEAM_1));
	mPlayers.push_back(CreatePlayer(30, sf::Color::Magenta, 290, 535, 1, 1, TEAM_1));
	mPlayers.push_back(CreatePlayer(30, sf::Color::Magenta, 200, 615, 1, 1, TEAM_1));

	// Team 2 players
	mPlayers.push_back(CreatePlayer(30, sf::Color::Red, 1120, 135, 1, 1, TEAM_2));
	mPlayers.push_back(CreatePlayer(30, sf::Color::Red, 1020, 215, 1, 1, TEAM_2));
	mPlayers.push_back(CreatePlayer(30, sf::Color::Red, 870, 375, 1, 1, TEAM_2));
	mPlayers.push_back(CreatePlayer(30, sf::Color::Red, 1020, 535, 1, 1, TEAM_2));
	mPlayers.push_back(CreatePlayer(30, sf::Color::Red, 1120, 615, 1, 1, TEAM_2));

	pPlayerSelected = nullptr;
}

void RugbyScene::OnEvent(const sf::Event& event)
{
	if (event.mouseButton.button == sf::Mouse::Button::Left)
	{
		for (int i = 0; i < mPlayers.size(); i++)
		{
			TrySetSelectedPlayer(mPlayers[i], event.mouseButton.x, event.mouseButton.y);
		}
	}

	if (event.mouseButton.button == sf::Mouse::Button::Right)
	{
		if (pPlayerSelected != nullptr)
		{
			pPlayerSelected->GoToPosition(event.mouseButton.x, event.mouseButton.y, 100.0f);
		}
	}
}

void RugbyScene::OnUpdate()
{
	// Line Zone 1
	Debug::DrawLine(100, 0, 100, 720, sf::Color::White);

	// Line Zone 2
	Debug::DrawLine(1180, 0, 1180, 720, sf::Color::White);

	if (pPlayerSelected != nullptr)
	{
		sf::Vector2f position = pPlayerSelected->GetPosition();
		Debug::DrawCircle(position.x, position.y, 10, sf::Color::White);
	}

	if (!pBall->GetCanBeTaken())
	{
		if (mBallDelayClock < mBallDelay)
		{
			mBallDelayClock++;
		}
		else
		{
			mBallWait = false;
			mBallDelayClock = 0;
			pBall->SetCanBeTaken(true);
		}
	}

	if (pBall->GetPosition().x < 100 || pBall->GetPosition().x > 1180)
	{
		if (pBall->GetPosition().x < 100)
		{
			mTeam2Points++;
		}
		else if (pBall->GetPosition().x > 1180)
		{
			mTeam1Points++;
		}

		// Reset ball and players
		NewSleeve();
	}

	if (mTeam1Points == 3 || mTeam2Points == 3)
	{
		std::cout << "Team " << (mTeam1Points == 3 ? "1" : "2") << " wins!" << std::endl;

		NewGame();
	}
}

Player* RugbyScene::CreatePlayer(float radius, const sf::Color& color, float x, float y, float ratioX, float ratioY, int tagTeam)
{
	Player* player = CreateEntity<Player>(radius, color);
	player->SetPosition(x, y, ratioX, ratioY);
	player->SetRigidBody(true);
	player->SetTagTeam(tagTeam);

	return player;
}

void RugbyScene::TrySetSelectedPlayer(Player* pPlayer, int x, int y)
{
	if (pPlayer->IsInside(x, y) == false)
	{
		return;
	}

	pPlayerSelected = pPlayer;
}

void RugbyScene::NewSleeve()
{
	pBall->Respawn();
	pBall->SetPosition(pBall->GetInitialPosition().x, pBall->GetInitialPosition().y);

	for (int i = 0; i < mPlayers.size(); i++)
	{
		mPlayers[i]->SetPosition(mPlayers[i]->GetInitialPosition().x, mPlayers[i]->GetInitialPosition().y);
	}
}

void RugbyScene::NewGame()
{
	NewSleeve();

	mTeam1Points = 0;
	mTeam2Points = 0;
}
