/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) 2025 Media Design School
File Name : MapManager.cpp
Description : Holds map and graph to perform functionality.
Author : Daniel Kane
Mail : daniel.kane@mds.ac.nz
**************************************************************************/

#include "MapManager.h"

MapManager::MapManager()
{

}

/// <summary>
/// Checks if the supplied map file is valid.
/// </summary>
/// <param name="_file"></param>
/// <returns></returns>
bool MapManager::CheckValid(std::ifstream* _file)
{
	int m_size = 20;
	std::string loadFileString;

	m_mapWidth = 0;
	m_mapHeight = 0;

	if (_file->is_open())
	{
		while (std::getline(*_file, loadFileString))
		{
			if (m_mapWidth == 0)
			{
				m_mapWidth = loadFileString.size();
			}
			assert(m_mapWidth == loadFileString.size());

			for (int i = 0; i < loadFileString.size(); i++)
			{
				map.m_Map[i][m_mapHeight] = loadFileString[i];

				if (map.m_Map[i][m_mapHeight] == 's')
				{
					if (m_startSquare == true)
					{
						std::cout << "ERROR: Too many start squares";
						return false;
					}
					m_startSquare = true;
					m_startNode = NodeAStar(i, m_mapHeight);
				}
				if (map.m_Map[i][m_mapHeight] == 'x')
				{
					if (m_exitSquare == true)
					{
						std::cout << "ERROR: Too many exit squares";
						return false;
					}
					m_exitSquare = true;
					m_endNode = NodeAStar(i, m_mapHeight);
				}

				// Check for valid amount of items
				if (std::find(m_items.begin(), m_items.end(), map.m_Map[i][m_mapHeight]) != m_items.end())
				{
					m_items.erase(find(m_items.begin(), m_items.end(), map.m_Map[i][m_mapHeight]));
					m_takenItems.push_back(map.m_Map[i][m_mapHeight]);

					graph.m_itemNodes.push_back(Node(i, m_mapHeight, map.m_Map[i][m_mapHeight]));

				}
				else if (std::find(m_takenItems.begin(), m_takenItems.end(), map.m_Map[i][m_mapHeight]) != m_takenItems.end())
				{
					std::cout << "ERROR: Item duplicates";
					return false;
				}
			}
			m_mapHeight++;
		}
		if (m_startSquare == false)
		{
			std::cout << "ERROR: No start square";
			return false;
		}
		if (m_exitSquare == false)
		{
			std::cout << "ERROR: No exit square";
			return false;
		}
		if (!m_items.empty())
		{
			std::cout << "ERROR: Not enough items";
			return false;
		}
		_file->close();
	}
	graph.m_itemNodes.insert(graph.m_itemNodes.begin(), Node(m_startNode.m_xPos, m_startNode.m_yPos, 's'));
	graph.SetNodes();
	return true;
}

/// <summary>
/// Print map.
/// </summary>
void MapManager::PrintMap()
{
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++)
		{
			std::cout << map.m_Map[j][i] << " ";
		}
		std::cout << std::endl;
	}
}
