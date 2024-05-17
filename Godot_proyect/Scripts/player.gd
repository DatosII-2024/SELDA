extends CharacterBody2D


var enemy_attack_inrange = false
var enemy_attack_cooldown = true
var healt = 4
var player_alive = true

const SPEED = 100.0
var current_direction = "none"

func _physics_process(delta):
	player_muvement()
	enemy_attack()
	
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

func enemy_attack():
	if enemy_attack_inrange and enemy_attack_cooldown == true:
		healt -=1
		enemy_attack_cooldown = false
		$attack_cooldown.start()
		print(healt)

func _on_hitbox_body_entered(body):
	if body.has_mathod("spectG"):
		print("body entered")
		enemy_attack_inrange = true


func _on_hitbox_body_exited(body):
	if body.has_method("spectG"):
		print("body exited")
		enemy_attack_inrange = false


func _on_attack_cooldown_timeout():
	enemy_attack_cooldown = true
