extends Sprite2D

const SPEED = 6.0
var player

func _ready():
	player = get_parent().get_parent().get_parent().get_node("Player")
	
func _process(delta):
	var pos = player.global_position
	position.x = pos.x/SPEED
	position.y = pos.y/SPEED
