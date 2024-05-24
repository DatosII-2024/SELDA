
#ifndef PLAYER_H
#define PLAYER_H

#include <Godot.hpp>
#include <character_body2d.hpp>
#include <Input.hpp>
#include <animated_sprite2d.hpp>
#include <glog/logging.h>

using namespace godot;

class Player : public CharacterBody2D {
    GDCLASS(Player, CharacterBody2D)

private:
    static constexpr float SPEED = 100.0;
    String current_direction;

public:
    static void _bind_methods();
    void _init();
    void _physics_process(float delta);
    void player_movement(float delta);
    void play_anim(String action, String direction);
};

#endif // PLAYER_H

