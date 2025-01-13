
#include <SFML/Graphics.hpp>
#include <iostream>

#include "GameManager.h"
#include "SampleScene.h"
#include "RugbyScene.h"

#include <cstdlib>
#include <crtdbg.h>

int main()
{
    GameManager* pInstance = GameManager::Get();

	//pInstance->CreateWindow(1280, 720, "SampleScene", 60, sf::Color::Black);
	pInstance->CreateWindow(1280, 720, "RugbyScene", 60, sf::Color::Black);
	
	//pInstance->LaunchScene<SampleScene>();
	pInstance->LaunchScene<RugbyScene>();

	return 0;
}