/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) 2025 Media Design School
File Name : main.cpp
Description : Calls main program functionality.
Author : Daniel Kane
Mail : daniel.kane@mds.ac.nz
**************************************************************************/

#include "FileLoader.h";
#include "MapManager.h";
#include "Map.h";

/// <summary>
/// Main functionality, calls the other functions. Repeats.
/// </summary>
/// <returns></returns>
int main()
{
	bool game = true;
	int input = 0;
	while (game == true)
	{
		std::ifstream* file = new std::ifstream();

		MapManager mapManager;

		LoadFile(file);
		if (mapManager.CheckValid(file) == true)
		{
			mapManager.PrintMap();
		}
		std::cout << "\nInput 1 for depth first search graph traversal.";
		std::cout << "\nInput 2 for breadth first search graph traversal.";
		std::cout << "\nInput 3 A* pathfinding.";
		std::cin >> input;
		while (std::cin.fail() || (input != 1 && input != 2 && input != 3))
		{
			std::cin.clear();
			std::cin.ignore();
			std::cout << "\nInvalid input!";
			std::cin >> input;
		}
		std::vector<NodeAStar*> empty;
		auto path = empty;
		switch (input)
		{
		case 1:
			std::cout << std::endl << "Depth First Search:" << std::endl;
			mapManager.graph.DepthFirstSearch(mapManager.graph.AdjacencyMatrix, mapManager.graph.visitedDFS, 0);
			break;
		case 2:
			std::cout << std::endl << "Breadth First Search:" << std::endl;
			mapManager.graph.BreadthFirstSearch(mapManager.graph.AdjacencyMatrix, mapManager.graph.visitedBFS, 0);
			break;
		case 3:
			path = Pathfinding(mapManager.map.m_Map, &mapManager.m_startNode, &mapManager.m_endNode);
			if (!path.empty())
			{
				std::cout << "Path found:\n";
				for (auto node : path)
					std::cout << "(" << node->m_xPos << "," << node->m_yPos << ") ";
				std::cout << "\n";
			}
			else
			{
				std::cout << "No path found.\n";
			}
			break;
		default: // Default case should not occur.
			std::cout << std::endl << "Depth First Search:" << std::endl;
			mapManager.graph.DepthFirstSearch(mapManager.graph.AdjacencyMatrix, mapManager.graph.visitedDFS, 0);
			break;
		}


		std::cout << "\nInput 1 to continue app\nInput 2 to quit app.";
		std::cin >> input;
		while (std::cin.fail() || (input != 1 && input != 2))
		{
			std::cin.clear();
			std::cin.ignore();
			std::cout << "\nInvalid input!";
			std::cin >> input;
		}

		if (input == 2)
		{
			game = false;
		}
	}
}