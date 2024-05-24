#include "SpectG.h"

void spectG::_bind_methods() {

	{
	/*ClassDB::bind_method(D_METHOD("_init"), &spectG::_init);
	ClassDB::bind_method(D_METHOD("find_path"), &spectG::find_path);
	ClassDB::bind_method(D_METHOD("get_neighbors"), &spectG::get_neighbors);
	ClassDB::bind_method(D_METHOD("contains_node"), &spectG::contains_node);
	ClassDB::bind_method(D_METHOD("is_tile_walkable"), &spectG::is_tile_walkable);

}

void spectG::_init() {
	player_chase = false;
	player = nullptr;
}

void spectG::_ready()
{
	Node* world = get_parent();
	if (world) {
		tilemap = Object::cast_to<TileMap>(world->get_node<TileMap>("TileMap"));
		player = Object::cast_to<Node2D>(world->get_node<Node2D>("Player"));
	}
}

void spectG::_physics_process(float delta)
{
	if (player && path.size() == 0) {
		Vector2 enemy_position = get_global_position();
		Vector2 player_position = player->get_global_position();
		path = find_path(enemy_position, player_position);
	}
	if (path.size() > 0) {
		Vector2 next_node = path[0];
		Vector2 next_position = tilemap->map_to_local(next_node);

		Vector2 direction = (next_position - get_global_position());
		set_velocity(direction * max_speed);
		move_and_slide();

		if ((next_position - get_global_position()).length() < 10) {
			path.pop_front();
		}
	}

	/*auto* anim_sprite = Object::cast_to<AnimatedSprite2D>(get_node<AnimatedSprite2D>("AnimatedSprite2D"));
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

Array spectG::find_path(Vector2 start_position, Vector2 target_position)
{
	Array open_list;
	Array closed_list;

	Vector2 start_tile = tilemap->local_to_map(start_position);
	Vector2 target_tile = tilemap->local_to_map(target_position);

	Node2D* start_node = new Node2D;
	start_node->set_position(start_tile);

	open_list.append(start_node);

	while (open_list.size() > 0) {
		Node2D* current_node = Object::cast_to<Node2D>(open_list[0]);
		int current_index = 0;

		// Encuentra el nodo con el menor f_cost en la lista abierta
		for (int i = 0; i < open_list.size(); ++i) {
			Node2D* node = Object::cast_to<Node2D>(open_list[i]);
			if ((node->get_position() - target_tile).length() < (Object::cast_to<Node2D>(open_list[current_index])->get_position() - target_tile).length()) {
				current_node = node;
				current_index = i;
			}
		}

		// Mueve el nodo actual de la lista abierta a la lista cerrada
		open_list.erase(current_index);
		closed_list.append(current_node);

		// Si llegamos al nodo objetivo, reconstruimos el camino y lo devolvemos
		if (current_node->get_position() == target_tile) {
			Array path_reverse;
			Node2D* current = current_node;
			while (current != nullptr) {
				path_reverse.append(current->get_position());
				current = Object::cast_to<Node2D>(current->get_parent());
			}
			Array path;
			for (int i = path_reverse.size() - 1; i >= 0; --i) {
				path.append(path_reverse[i]);
			}
			return path;
		}

		// Genera los vecinos del nodo actual
		Array neighbors = get_neighbors(current_node->get_position());
		for (int i = 0; i < neighbors.size(); ++i) {
			Vector2 neighbor = neighbors[i];
			// Si el vecino está en la lista cerrada, lo ignoramos
			//if (contains_node(closed_list, neighbor)) {
				//continue;
			//}

			// Si el vecino no es transitable, lo ignoramos
			if (!is_tile_walkable(neighbor)) {
				continue;
			}

			// Si el vecino está en la lista abierta y tiene un costo menor, lo actualizamos
			Node2D* neighbor_node = new Node2D;
			neighbor_node->set_position(neighbor);
			neighbor_node->get_parent()->remove_child(current_node);
			current_node->add_child(neighbor_node);
			//neighbor_node->set_parent(current_node);
			open_list.append(neighbor_node);
		}
	}

	// Si no se encuentra un camino, se devuelve una lista vacía
	Array empty_path;
	return empty_path;
}

Array spectG::get_neighbors(Vector2 position)
{
	Array neighbors;

	neighbors.append(position + Vector2(0, -1));
	neighbors.append(position + Vector2(0, 1));
	neighbors.append(position + Vector2(-1, 0));
	neighbors.append(position + Vector2(1, 0));
	return neighbors;
}

bool spectG::contains_node(Array node_list, Vector2 position)
{
	for (int i = 0; i < sizeof(node_list);++i) {
		Node2D* node = Object::cast_to<Node2D>(node_list[i]);
		if (node && node->get_position()==position) {
			return true;
		}
	}
	return false;
}

bool spectG::is_tile_walkable(Vector2 position)
{
	Vector2i pos = position.round();
	int tile_id = tilemap->get_cell_source_id(1,pos);
	return tile_id != -1;
}*/


