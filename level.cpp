#include <iostream>
#include "level.h"
#include "GameState.h"
#include "player.h"


//void Level::checkCollisions()
//{
//	for (auto& box : m_blocks) {
//
//	}
//
//}

void Level::update(float dt)
{
	if (m_state->getPlayer()->isActive())
		m_state->getPlayer()->update(dt);

	GameObject::update(dt);
}

void Level::init() {
	m_brush_background.outline_opacity = 0.0f;
	m_brush_background.texture ="background_2.png";
	std::cout << m_brush_background.texture;
	//printf("%s\n", m_brush_bakground.texture.c_str());

	///cout << m_brush_background.texture;

	/*for (auto p_gob : m_static_objects)
		if (p_gob) p_gob->init();

	for (auto p_gob : m_dynamic_objects)
		if (p_gob) p_gob->init();*/

}	

void Level::draw() {
	float w = m_state->getCanvasWidth();
	float h = m_state->getCanvasHeight();

	float offset_x = m_state->m_global_offset_x/2.0f + w / 2.0f;
	float offset_y = m_state->m_global_offset_y/2.0f + h / 2.0f;

	//draw background
	graphics::drawRect(offset_x,offset_y,w,h, m_brush_background);
	
	/*if (m_state->getPlayer()->isActive())
		m_state->getPlayer()->draw();

	for (auto p_gob : m_static_objects)
		if (p_gob) p_gob->draw();

	for (auto p_gob : m_dynamic_objects)
		if (p_gob) p_gob->draw();*/

}

Level::Level(const std::string& name) {
	
}

Level:: ~Level() {
	for (auto p_gob : m_static_objects)
		if (p_gob) delete p_gob;

	for (auto p_gob : m_dynamic_objects)
		if (p_gob) delete p_gob;
}