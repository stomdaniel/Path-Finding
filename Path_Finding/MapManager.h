/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) 2025 Media Design School
File Name : MapManager.h
Description : Holds map and graph to perform functionality.
Author : Daniel Kane
Mail : daniel.kane@mds.ac.nz
**************************************************************************/

#pragma once
#include <fstream>
#include <vector>
#include <string>
#include <cassert>
#include "Map.h"
#include "Node.h"
#include "Graph.h"
#include "Pathfinding.h";
#include <iostream>


class MapManager
{
public:
	Map map;
	Graph graph;
	int m_mapWidth = 20;
	int m_mapHeight = 20;

	bool m_startSquare = false;
	bool m_exitSquare = false;
	std::vector<char> m_items = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'};
	std::vector<char> m_takenItems;

	NodeAStar m_startNode;
	NodeAStar m_endNode;

	MapManager();

	void LoadFile(std::string _file);
	bool CheckValid(std::ifstream* _file);

	void PrintMap();
};

