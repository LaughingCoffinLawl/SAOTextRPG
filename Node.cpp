#include "Node.h"

Node::Node(char vertex, int x, int y)
	: m_vertex{ vertex }
	, m_x{ x }
	, m_y{ y } {}

char Node::getVertex() const {
	return m_vertex;
}

int Node::getX() const {
	return m_x;
}

int Node::getY() const {
	return m_y;
}
