/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) 2025 Media Design School
File Name : Graph.h
Description : Stores graph representation and functionality.
Author : Daniel Kane
Mail : daniel.kane@mds.ac.nz
**************************************************************************/

#pragma once
#include <vector>
#include <queue>
#include <iostream>
#include "Node.h"

class Graph
{
public:
	
	float AdjacencyMatrix[11][11];
	Node m_startNode;
	std::vector<Node> m_itemNodes;
	std::vector<bool> visitedDFS;

	std::vector<bool> visitedBFS;
	std::vector<int> resultBFS;
	std::queue<int> queue;

	void SetNodes();
	void PrintMatrix();

	void DepthFirstSearch(float _AdjacencyMatrix[11][11], std::vector<bool>& _visited, int _id);
	void BreadthFirstSearch(float _AdjacencyMatrix[11][11], std::vector<bool>& _visited, int _id);
};