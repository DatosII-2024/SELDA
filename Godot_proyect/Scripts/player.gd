extends CharacterBody2D

var healt = 5

const SPEED = 100.0
var current_direction = "none"

func _physics_process(delta):
	player_muvement()
	
func player_muvement():
	if Input.is_action_pressed("rigth"):
		velocity.x = SPEED
		velocity.y = 0
		current_direction = "right"
		play_anim(1)
	elif Input.is_action_pressed("left"):
		velocity.x = -SPEED
		velocity.y = 0
		current_direction = "left"
		play_anim(1)
	elif Input.is_action_pressed("down"):
		velocity.x = 0
		velocity.y = SPEED
		current_direction = "down"
		play_anim(1)
	elif Input.is_action_pressed("up"):
		velocity.x = 0
		velocity.y = -SPEED
		current_direction = "up"
		play_anim(1)
	elif Input.is_action_pressed("attack"):
		velocity.x = 0
		velocity.y = 0
		play_anim(2)
	else:
		velocity.x = 0
		velocity.y = 0
		play_anim(0)
	move_and_slide()
func play_anim(movement):
	var dir = current_direction
	var anim = $AnimatedSprite2D
	
	if dir == "right":
		anim.flip_h = false
		if movement == 1:
			anim.play("walk_right")
		elif movement == 0:
			anim.play("idle_right")
		elif movement == 2:
			anim.play("attack_right")
	elif dir == "left":
		anim.flip_h = true
		if movement == 1:
			anim.play("walk_right")
		elif movement == 0:
			anim.play("idle_right")
		elif movement == 2:
			anim.play("attack_right")
	elif dir == "down":
		if movement == 1:
			anim.play("walk_down")
		elif movement == 0:
			anim.play("idle_down")
		elif movement == 2:
			anim.play("attack_down")
	elif dir == "up":
		if movement == 1:
			anim.play("walk_up")
		elif movement == 0:
			anim.play("idle_up")
		elif movement == 2:
			anim.play("attack_up")

