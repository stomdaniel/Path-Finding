/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) 2025 Media Design School
File Name : Graph.cpp
Description : Stores graph representation and functionality.
Author : Daniel Kane
Mail : daniel.kane@mds.ac.nz
**************************************************************************/

#include "Graph.h"

/// <summary>
/// Set the location of nodes.
/// </summary>
void Graph::SetNodes()
{
	for (int i = 0; i < m_itemNodes.size(); i++)
	{
		for (int j = 0; j < m_itemNodes.size(); j++)
		{
			float x = m_itemNodes[i].m_xPos - m_itemNodes[j].m_xPos;
			float y = m_itemNodes[i].m_yPos - m_itemNodes[j].m_yPos;
			AdjacencyMatrix[i][j] = sqrt((x * x) + (y * y));
		}

		visitedDFS.push_back(false);
		visitedBFS.push_back(false);
	}

}

/// <summary>
///  Print the adjacency matrix
/// </summary>
void Graph::PrintMatrix()
{
	for (int i = 0; i < 11; i++)
	{
		std::cout << "Node: " << m_itemNodes[i].m_id << std::endl;
		for (int j = 0; j < 11; j++)
		{
			std::cout << "Distance to Node " << m_itemNodes[j].m_id << ": " << AdjacencyMatrix[i][j] << std::endl;
		}
		std::cout << std::endl;
	}
}

/// <summary>
/// Sort nodes using deapth first search
/// </summary>
/// <param name="_AdjacencyMatrix"></param>
/// <param name="_visited"></param>
/// <param name="_id"></param>
void Graph::DepthFirstSearch(float _AdjacencyMatrix[11][11], std::vector<bool>& _visited, int _id)
{
	_visited[_id] = true;
	std::cout << m_itemNodes[_id].m_id << std::endl;

	float minDis = 100;
	int nextNode = -1;

	for (int i = 0; i < _visited.size(); ++i)
	{
		if (!_visited[i] && _AdjacencyMatrix[_id][i] > 0 && _AdjacencyMatrix[_id][i] < minDis)
		{
			minDis = _AdjacencyMatrix[_id][i];
			nextNode = i;
		}
	}
	if (nextNode == -1)
	{
		return;
	}	
	DepthFirstSearch(_AdjacencyMatrix, _visited, nextNode);
}

/// <summary>
/// Sort nodes using breadth first search
/// </summary>
/// <param name="_AdjacencyMatrix"></param>
/// <param name="_visited"></param>
/// <param name="_id"></param>
void Graph::BreadthFirstSearch(float _AdjacencyMatrix[11][11], std::vector<bool>& _visited, int _id)
{
	queue.push(_id);
	_visited[_id] = true;

	while (queue.size() > 0)
	{
		_id = queue.front();
		queue.pop();
		std::cout << m_itemNodes[_id].m_id << std::endl;

		float minDis = 100;
		int nextNode = -1;

		for (int i = 0; i < _visited.size(); ++i)
		{
			if (!_visited[i] && _AdjacencyMatrix[_id][i] > 0 && _AdjacencyMatrix[_id][i] < minDis)
			{
				minDis = _AdjacencyMatrix[_id][i];
				nextNode = i;
			}
			if (!_visited[i] && _AdjacencyMatrix[_id][i] > 0 && minDis == _AdjacencyMatrix[_id][i])
			{
				_visited[i] = true;
				queue.push(i);
			}
		}
		
	}
}

