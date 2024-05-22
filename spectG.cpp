#include "SpectG.h"

void spectG::_bind_methods() {
	ClassDB::bind_method(D_METHOD("_init"), &spectG::_init);
	ClassDB::bind_method(D_METHOD("_on_detection_area_body_entered"), &spectG::_on_detection_area_body_entered);
	ClassDB::bind_method(D_METHOD("_on_detection_area_body_exited"), &spectG::_on_detection_area_body_exited);

}

void spectG::_init() {
	player_chase = false;
	player = nullptr;
}

void spectG::_physics_process(float delta) {
	auto* anim_sprite = Object::cast_to<AnimatedSprite2D>(get_node<AnimatedSprite2D>("AnimatedSprite2D"));
	auto* detector = Object::cast_to<Area2D>(get_node<Area2D>("detection_area"));
	try {
		if (player_chase) {
			if (player) {
				set_position(get_position() + (player->get_position() - get_position()) / SPEED);
				if ((player->get_position() - get_position())[0] < 0) {
					anim_sprite->set_flip_h(true);
					detector->set_rotation_degrees(180);
				}
				else {
					anim_sprite->set_flip_h(false);
					detector->set_rotation_degrees(0);
				}
			}
		}
		else {
			anim_sprite->play("stat_right");
		}
	}
	catch (const std::exception e) {

	}
}

void spectG::_on_detection_area_body_entered(Node* body) {
	player = Object::cast_to<Node2D>(body);
	player_chase = true;
}

void spectG::_on_detection_area_body_exited(Node* body) {
	player = nullptr;
	player_chase = false;
}