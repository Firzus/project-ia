#include "RugbyScene.h"

#include "Player.h"
#include "Ball.h"
#include "Debug.h"

void RugbyScene::TrySetSelectedPlayer(Player* pPlayer, int x, int y)
{
	if (pPlayer->IsInside(x, y) == false)
		return;

	pPlayerSelected = pPlayer;
}

void RugbyScene::OnInitialize()
{
	pBall = CreateEntity<Ball>(15, sf::Color::Green);
	pBall->SetPosition(625, 345);
	pBall->SetRigidBody(true);

	pPlayer1 = CreateEntity<Player>(30, sf::Color::Magenta);
	pPlayer1->SetPosition(260, 330);
	pPlayer1->SetRigidBody(true);

	pPlayer2 = CreateEntity<Player>(30, sf::Color::Yellow);
	pPlayer2->SetPosition(960, 330);
	pPlayer2->SetRigidBody(true);

	pPlayerSelected = nullptr;
}

void RugbyScene::OnEvent(const sf::Event& event)
{
	if (event.mouseButton.button == sf::Mouse::Button::Left)
	{
		if (pPlayerSelected != nullptr)
		{
			pPlayerSelected->GoToPosition(event.mouseButton.x, event.mouseButton.y, 100.f);
		}
	}
}

void RugbyScene::OnUpdate()
{
	// Line 1
	Debug::DrawLine(100, 0, 100, 720, sf::Color::White);

	// Line 2
	Debug::DrawLine(1180, 0, 1180, 720, sf::Color::White);
}
