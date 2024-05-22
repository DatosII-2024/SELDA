#ifndef SPECTG_H
#define SPECTG_H

#include <Godot.hpp>
#include <character_body2d.hpp>
#include <animated_sprite2d.hpp>
#include <area2d.hpp>

using namespace godot;

class spectG: public CharacterBody2D {
	GDCLASS(spectG, CharacterBody2D)

public:
	static void _bind_methods();
	void _init();
	void _physics_process(float delta);
	void _on_detection_area_body_entered(Node* body);
	void _on_detection_area_body_exited(Node* body);


private:
	static constexpr int SPEED = 50;
	bool player_chase;
	Node2D* player;

};






#endif // !SPECTG_H
