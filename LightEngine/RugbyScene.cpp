#include "RugbyScene.h"

#include "Player.h"
#include "Ball.h"
#include "Debug.h"

void RugbyScene::OnInitialize()
{
	pBall = CreateEntity<Ball>(15, sf::Color::Green);
	pBall->SetPosition(625, 345);
	pBall->SetRigidBody(true);

	pPlayer1 = CreateEntity<Player>(30, sf::Color::Magenta);
	pPlayer1->SetPosition(260, 330);
	pPlayer1->SetRigidBody(true);
	pPlayer1->SetTagTeam(TEAM_1);

	pPlayer2 = CreateEntity<Player>(30, sf::Color::Red);
	pPlayer2->SetPosition(960, 330);
	pPlayer2->SetRigidBody(true);
	pPlayer2->SetTagTeam(TEAM_2);

	pPlayerSelected = nullptr;
}

void RugbyScene::OnEvent(const sf::Event& event)
{
	if (event.mouseButton.button == sf::Mouse::Button::Left)
	{
		TrySetSelectedPlayer(pPlayer1, event.mouseButton.x, event.mouseButton.y);
		TrySetSelectedPlayer(pPlayer2, event.mouseButton.x, event.mouseButton.y);
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
}

void RugbyScene::TrySetSelectedPlayer(Player* pPlayer, int x, int y)
{
	if (pPlayer->IsInside(x, y) == false)
	{
		return;
	}

	pPlayerSelected = pPlayer;
}