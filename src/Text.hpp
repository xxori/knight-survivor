#ifndef TEXT_HPP
#define TEXT_HPP
#include "GameEntity.hpp"

// A simple text class that represents some text rendered to the screen
class Text : public GameEntity {
private:
	std::string text;
	int size;
	raylib::Color color;

public:
	Text(Game* game);
	Text(Game* game, std::string text, raylib::Vector2 pos, int size, raylib::Color color);
	
	void Update(float dt);
	void Draw();

	int get_size();
	void set_size(int size);
	std::string get_text();
	void set_text(std::string text);
};

#endif