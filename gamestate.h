#pragma once
#include <string>
#include <sgg/graphics.h>

class GameState {

private:
	std::string m_asset_path = "assets\\";
	 
	float m_canvas_width = 6.0f;
	float m_canvas_height = 6.0f;

	graphics::Brush m_brush_background;
	graphics::Brush m_brush_player;

	float m_player_pos_x = m_canvas_width / 2.0f;
	float m_player_pos_y = m_canvas_height / 2.0f;
	float m_player_size = 1.0f;

	static GameState* m_unique_instance;

	GameState();
	
	 class Player* m_player = nullptr;
	 class Level* m_current_level = nullptr;

public:   

	float getCanvasWidth() { return m_canvas_width; }
	float getCanvasHeight() { return m_canvas_height; }

	float m_global_offset_x = 0.0f;
	float m_global_offset_y = 0.0f;
	bool m_debugging = false; 
	
	void init();
	void draw();
	void update(float dt);
	
	static GameState* getInstance(); 
	~GameState();

	std::string getAssestDir();
	std::string getFullAssetPath(const std:: string& asset);

	class Player* getPlayer() {
		return m_player;
	}
};  