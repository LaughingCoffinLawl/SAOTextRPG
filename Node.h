#ifndef NODE_H
#define NODE_H

#include <iomanip>
#include <iostream>
#include <vector>

class Node {
  public:
	Node(char vertex, int x, int y);
	int getX() const;
	int getY() const;
	char getVertex() const;

  private:
	char m_vertex;
	int m_x;
	int m_y;
};

#endif
