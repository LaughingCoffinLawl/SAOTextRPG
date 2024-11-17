#ifndef GRAPH_H
#define GRAPH_H

#include "BossRoom.h"
#include "Dungeon.h"
#include "EmptyRoom.h"
#include "Node.h"
#include "NormalRoom.h"
#include "Random.h"
#include "Room.h"
#include "StartRoom.h"
#include "TreasureRoom.h"
#include <array>
#include <iostream>
#include <unordered_map>
#include <vector>

class Graph {
  public:
	Graph();
	void addNode(Node& node);
	void linkNode(const Node& n1, const Node& n2);
	void print() const;
	void inizializeDungeon();
	void dfs(Node& node, int maxRooms = 10);
	void addToArray(char vertex, int x, int y);
	Dungeon returnDungeon();

  private:
	std::size_t m_length{ 6 };
	std::unordered_map<char, std::vector<char>> m_graph;
	std::array<std::unique_ptr<Room>, 36> m_dungeon;
	std::unordered_map<int, std::pair<int, int>> m_directions{
		{ 0, { 0, -1 } }, { 1, { 0, 1 } }, { 2, { -1, 0 } }, { 3, { 1, 0 } }
	};
};

#endif // !GRAPH_H
