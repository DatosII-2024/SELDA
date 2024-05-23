extends Sprite2D

const SPEED = 17.0


func _process(delta):
	if Input.is_action_pressed("rigth"):
		position.x += SPEED*delta
	elif Input.is_action_pressed("left"):
		position.x -= SPEED*delta
	elif Input.is_action_pressed("down"):
		position.y += SPEED*delta
	elif Input.is_action_pressed("up"):
		position.y -= SPEED*delta
