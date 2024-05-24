#ifndef SPECTG_H
#define SPECTG_H

#include <Godot.hpp>
#include <character_body2d.hpp>
#include <animated_sprite2d.hpp>
#include <area2d.hpp>
#include <array.hpp>
#include <tile_map.hpp>

using namespace godot;

class spectG: public CharacterBody2D {
	GDCLASS(spectG, CharacterBody2D)

public:
	static void _bind_methods();
	/*void _init();
	void _ready();
	void _physics_process(float delta);
	Array find_path(Vector2 start_position, Vector2 target_position);
	Array get_neighbors(Vector2 position);
	bool contains_node(Array node_list, Vector2 position);
	bool is_tile_walkable(Vector2 position);


private:
	float max_speed = 200;
	bool player_chase;
	Node2D* player;
	TileMap* tilemap;
	Array path;*/

};






#endif // !SPECTG_H
