extends Node2D

var chage_scene
var player
var player_pos

# Called when the node enters the scene tree for the first time.
func _ready():
	chage_scene = preload("res://scene/nivel_2.tscn")
	player = get_node("Player")


# Called every frame. 'delta' is the elapsed time since the previous frame.
func _process(delta):
	player_pos = player.global_position
	if is_fin():
		get_tree().change_scene_to_packed(chage_scene)
	if player_dead():
		player.position(Vector2(30.0,59.0))
		player.healt = 5
func is_fin():
	if player_pos.x>1013.338 and player_pos.y>488.9989:
		if player_pos.x<1031.672 and player_pos.y<497.3322:
			return true
	return false
func player_dead():
	return player.healt == 0
