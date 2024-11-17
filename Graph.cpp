#include "Graph.h"

Graph::Graph() {
	for (auto& room : m_dungeon)
		room = std::make_unique<EmptyRoom>();
	inizializeDungeon();
}

Dungeon Graph::returnDungeon() {
	return Dungeon{ m_dungeon };
}

// adds the vertex as key in the map, with empty neighbour's vector
void Graph::addNode(Node& node) {
	m_graph.insert({ node.getVertex(), {} });
}

// prints the graph
void Graph::print() const {
	for (const auto& node : m_graph) {
		std::cout << node.first << ": ";
		for (const auto& neighbor : node.second) {
			std::cout << neighbor << " ";
		}
		std::cout << '\n';
	}
}

void Graph::linkNode(const Node& n1, const Node& n2) {
	// check if nodes already exists as key in the map
	auto n1Exists{ m_graph.find(n1.getVertex()) };
	auto n2Exists{ m_graph.find(n2.getVertex()) };

	// if they exists
	if (n1Exists != m_graph.end() && n2Exists != m_graph.end()) {
		// and they are not already in the vector's neighbours
		if (std::find(n1Exists->second.begin(), n1Exists->second.end(), n2.getVertex()) ==
			n1Exists->second.end()) {
			// add the to the vector
			n1Exists->second.push_back(n2.getVertex());
		}

		// if they are not already in the vector's neighbours
		if (std::find(n2Exists->second.begin(), n2Exists->second.end(), n1.getVertex()) ==
			n2Exists->second.end()) {
			// add them in the other node's vector as well
			n2Exists->second.push_back(n1.getVertex());
		}
	} else {
		// something went wrong
		std::cout << "Impossible to link\n";
	}
}

void Graph::addToArray(char vertex, int x, int y) {
	std::size_t index = (x * m_length) + y;
	switch (vertex) {
	case 'N':
		m_dungeon[index] = std::make_unique<NormalRoom>();
		break;
	case 'T':
		m_dungeon[index] = std::make_unique<TreasureRoom>();
		break;
	case 'B':
		m_dungeon[index] = std::make_unique<BossRoom>();
		break;
	case 'S':
		m_dungeon[index] = std::make_unique<StartRoom>();
		break;
	default:
		m_dungeon[index] = std::make_unique<EmptyRoom>();
		break;
	}
}

void Graph::inizializeDungeon() {
	int startX{ Random::get(0, static_cast<int>(m_length) - 1) };
	int startY{ Random::get(0, static_cast<int>(m_length) - 1) };

	Node startNode('S', startX, startY);
	addNode(startNode);
	dfs(startNode);
}

void Graph::dfs(Node& node, int maxRooms) {
	addToArray(node.getVertex(), node.getX(), node.getY());

	if (maxRooms <= 0)
		return;

	std::pair<int, int> direction{ m_directions[Random::get(0, 3)] };

	int newX{ node.getX() + direction.first };
	int newY{ node.getY() + direction.second };

	if (newX >= 0 && newX < static_cast<int>(m_length) && newY >= 0 &&
		newY < static_cast<int>(m_length) &&
		(m_dungeon[(newX * m_length) + newY]->textToDisplay()) == "#") {
		Node newNode('#', 0, 0);

		switch (maxRooms) {
		case 10 / 2:
			newNode = Node('T', newX, newY);
			break;
		case 1:
			newNode = Node('B', newX, newY);
			break;
		default:
			newNode = Node('N', newX, newY);
			break;
		}

		addNode(newNode);
		addToArray(newNode.getVertex(), newX, newY);
		linkNode(node, newNode);
		dfs(newNode, --maxRooms);
	} else {
		dfs(node, maxRooms);
	}
}
