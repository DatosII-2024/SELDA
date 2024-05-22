extends CharacterBody2D


var speed = 40
var player_chase = false
var player = null


func _physics_process(delta):
	var anim_sprite := $AnimatedSprite2D as AnimatedSprite2D
	var detector := $detection_area as Area2D

	if player_chase:
		if player:
			set_position(get_position() + (player.get_position() - get_position()) / speed)
			if (player.get_position() - get_position())[0] < 0:
				anim_sprite.flip_h = true
				detector.rotation_degrees = 180
			else:
				anim_sprite.flip_h = false
				detector.rotation_degrees = 0
	else:
		anim_sprite.play("stat_right")
func _on_detection_area_body_entered(body):
	player = body
	player_chase = true

func _on_detection_area_body_exited(body):
	player = null
	player_chase = false
