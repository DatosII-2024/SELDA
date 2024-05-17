#include "Player.h"

void Player::_bind_methods() {
    ClassDB::bind_method(D_METHOD("_init"), &Player::_init);
    //ClassDB::bind_method(D_METHOD("_physics_process", "delta"), &Player::_physics_process);
    ClassDB::bind_method(D_METHOD("player_movement", "delta"), &Player::player_movement);
    ClassDB::bind_method(D_METHOD("play_anim", "action", "direction"), &Player::play_anim);
}

void Player::_init() {
    current_direction = "none";
}

void Player::_physics_process(float delta) {
    //player_movement(delta);
}

void Player::player_movement(float delta) {
    if (Input::get_singleton()->is_action_pressed("rigth")) {
        set_velocity(Vector2(SPEED, 0));
        current_direction = "right";
        play_anim("walk", current_direction);
    }
    else if (Input::get_singleton()->is_action_pressed("left")) {
        set_velocity(Vector2(-SPEED, 0));
        current_direction = "left";
        play_anim("walk", current_direction);
    }
    else if (Input::get_singleton()->is_action_pressed("down")) {
        set_velocity(Vector2(0, SPEED));
        current_direction = "down";
        play_anim("walk", current_direction);
    }
    else if (Input::get_singleton()->is_action_pressed("up")) {
        set_velocity(Vector2(0, -SPEED));
        current_direction = "up";
        play_anim("walk", current_direction);
    }
    else if (Input::get_singleton()->is_action_pressed("attack")) {
        play_anim("attack", current_direction);
    }
    else {
        set_velocity(Vector2(0,0));
        play_anim("idle", current_direction);
    }

    move_and_slide();
}

void Player::play_anim(String action, String direction) {
    auto anim_node = get_node<AnimatedSprite2D>("AnimatedSprite2D");
    if (anim_node) {
        auto anim = Object::cast_to<AnimatedSprite2D>(anim_node);
        if (anim) {
            String anim_name = action + "_";

            if (direction == "left") {
                anim->set_flip_h(true);
                anim_name += "right";
                anim->play(anim_name);
            }
            else if (direction == "right" || direction == "up" || direction == "down") {
                anim->set_flip_h(false);
                anim_name += direction;
                anim->play(anim_name);
            }
        }
        else {
            return;
            // El nodo no es un AnimatedSprite
            // Manejar el error o mostrar un mensaje de advertencia
        }
    }
    else {
        return;
        // No se encontró el nodo AnimatedSprite
        // Manejar el error o mostrar un mensaje de advertencia
    }
}
