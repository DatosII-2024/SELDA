extends CharacterBody2D

var tilemap
var player
var path = []
var max_speed = 200

func _ready():
	# Buscar el nodo "World" en la jerarquía de nodos
	var world = get_parent()

	if world:
		# Buscar el nodo "TileMap" dentro de "World"
		tilemap = world.get_node("TileMap")
		# Buscar el nodo "Player" dentro de "World"
		player = world.get_node("Player")

func _process(delta):
	if player and path.size() == 0:
		# Encuentra la ruta desde la posición del enemigo hasta la posición del jugador
		var enemy_position = global_position
		var player_position = player.global_position
		path = find_path(enemy_position, player_position)
	
	# Sigue la ruta si se encontró una
	if path.size() > 0:
		# Mueve al enemigo hacia el siguiente nodo en la ruta
		var next_node = path[0]
		var next_position = tilemap.map_to_world(next_node)
		
		# Calcula la dirección hacia el siguiente nodo
		var direction = (next_position - global_position).normalized()
		
		# Aplica una fuerza al CharacterBody2D para moverlo en esa dirección
		move_and_collide(direction * max_speed * delta)
		
		# Si el enemigo está lo suficientemente cerca del nodo, lo remueve de la ruta
		if (next_position - global_position).length() < 10:
			path.pop_front()

# Implementación del algoritmo A*
func find_path(start_position, target_position):
	var open_list = []
	var closed_list = []

	var start_tile = Vector2(tilemap.local_to_map(start_position))
	var target_tile = Vector2(tilemap.local_to_map(target_position))

	var start_node = Node2D.new()
	start_node.position = start_tile

	open_list.append(start_node)

	while open_list.size() > 0:
		var current_node = open_list[0]
		var current_index = 0

		# Encuentra el nodo con el menor f_cost en la lista abierta
		for i in range(open_list.size()):
			if (open_list[i].position - target_tile).length() < (open_list[current_index].position - target_tile).length():
				current_node = open_list[i]
				current_index = i

		# Mueve el nodo actual de la lista abierta a la lista cerrada
		open_list.erase(current_index)
		closed_list.append(current_node)

		# Si llegamos al nodo objetivo, reconstruimos el camino y lo devolvemos
		if current_node.position == target_tile:
			var path_reverse = []
			var current = current_node
			while current != null:
				path_reverse.append(current.position)
				current = current.parent
			path = path_reverse.duplicate()
			path.reverse()
			return path

		# Genera los vecinos del nodo actual
		var neighbors = get_neighbors(current_node.position)
		for neighbor in neighbors:
			# Si el vecino está en la lista cerrada, lo ignoramos
			if contains_node(closed_list, neighbor):
				continue

			# Si el vecino no es transitable, lo ignoramos
			if not is_tile_walkable(neighbor):
				continue

			# Si el vecino está en la lista abierta y tiene un costo menor, lo actualizamos
			var neighbor_node = Node2D.new()
			neighbor_node.position = neighbor
			neighbor_node.parent = current_node
			open_list.append(neighbor_node)

	# Si no se encuentra un camino, se devuelve una lista vacía
	return []

# Función para obtener los vecinos de un nodo
func get_neighbors(position):
	var neighbors = []
	# Agrega los vecinos arriba, abajo, izquierda y derecha
	neighbors.append(position + Vector2(0, -1)) # Arriba
	neighbors.append(position + Vector2(0, 1))  # Abajo
	neighbors.append(position + Vector2(-1, 0)) # Izquierda
	neighbors.append(position + Vector2(1, 0))  # Derecha
	return neighbors

# Función para verificar si un nodo está en una lista de nodos
func contains_node(node_list, position):
	for node in node_list:
		if node.position == position:
			return true
	return false

# Función para verificar si un tile es transitable
func is_tile_walkable(position):
	var tile_id = tilemap.get_cellv(position)
	return tile_id != -1  # Si el tile_id es -1, significa que no hay tile en esa posición
