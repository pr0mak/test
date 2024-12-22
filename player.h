#pragma once

#include "GameObject.h"
#include <sgg/graphics.h>
#include "box.h"

class Player : public Box ,public GameObject {

	graphics::Brush m_brush_player;

public:
	Player(std::string name) : GameObject(name){}

	 void update(float dt) override;
	 void draw() override;
	 void init() override;

protected:
	void debugDraw();
};	