#include <iostream>
#include "gamestate.h"
#include "level.h"
#include "player.h"

GameState::GameState()
{
}

void GameState::init()
{
	m_current_level = new Level("lvl");
	m_current_level->init();

	m_player = new Player("Player");
	m_player->init();

	//graphics::preloadBitmaps(getAssestDir());
	//graphics:: setFont

}

void GameState::draw()
{
	if (m_current_level != nullptr) {
		std::cout << "test";
		m_current_level->draw();
	}

}
 
void GameState::update(float dt)
{
	if (dt > 500) //ms 
		return;

	if (!m_current_level)
		return;

	m_current_level->update(dt);

	m_debugging = graphics::getKeyState(graphics::SCANCODE_0);
}

GameState* GameState::getInstance()
{
	if (m_unique_instance == nullptr)
		m_unique_instance = new GameState();	

	return m_unique_instance;
}

GameState::~GameState()
{
	if (m_player)
		delete	m_player;
	if (m_current_level)
		delete m_current_level;
}

std::string GameState::getFullAssetPath(const std::string& asset) 
{
	return m_asset_path + asset;
}

GameState* GameState::m_unique_instance = nullptr;

std::string GameState::getAssestDir()
{
	return m_asset_path;
}
