/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) 2025 Media Design School
File Name : Pathfinding.cpp
Description : Functions related to A* pathfinding.
Author : Daniel Kane
Mail : daniel.kane@mds.ac.nz
**************************************************************************/

#include "Pathfinding.h"

/// <summary>
/// Gets the neighbors of nearby nodes, discluding untravable nodes.
/// </summary>
/// <param name="_node"></param>
/// <param name="_Map"></param>
/// <returns></returns>
std::vector<NodeAStar*> GetNeighbors(NodeAStar* _node, char _Map[20][20])
{
    std::vector<NodeAStar*> neighbors;
    int directions[8][2] = {
        {0, 1},   // North
        {1, 1},   // North East
        {1, 0},   // East
        {1, -1},  // South East
        {0, -1},  // South
        {-1, -1}, // South West
        {-1, 0},  // West
        {-1, 1}   // North West
    };

    for (auto& currentDirection : directions)
    {
        int newX = _node->m_xPos + currentDirection[0];
        int newY = _node->m_yPos + currentDirection[1];
        bool diagonalBlocked = false;

        if (_Map[newX][newY + 1] == 'w')
        {
            diagonalBlocked = true;
        }
        if (_Map[newX - 1][newY] == 'w')
        {
            diagonalBlocked = true;
        }
        if (_Map[newX][newY - 1] == 'w')
        {
            diagonalBlocked = true;
        }
        if (_Map[newX + 1][newY] == 'w')
        {
            diagonalBlocked = true;
        }

        if (diagonalBlocked == true && (abs(currentDirection[0]) + abs(currentDirection[1]) == 2))
        {
            continue;
        }

        // Make sure square is navigatable
        if (newX >= 0 && newY >= 0 && newX < 20 && newY < 20 && _Map[newX][newY] != 'w')
        {
            neighbors.push_back(new NodeAStar(newX, newY));
        }
    }

    return neighbors;
}

/// <summary>
/// Returns the valid path
/// </summary>
/// <param name="_current"></param>
/// <param name="_Map"></param>
/// <returns></returns>
std::vector<NodeAStar*> BackTrack(NodeAStar* _current, char _Map[20][20])
{
    std::vector<NodeAStar*> path;
    while (_current)
    {
        _Map[_current->m_xPos][_current->m_yPos] = 'P';
        path.push_back(_current);
        _current = _current->m_parent;
    }
    std::reverse(path.begin(), path.end());

    // Display
    system("cls");
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 20; j++)
        {
            std::cout << _Map[j][i] << " ";
        }
        std::cout << std::endl;
    }

    return path;
}

/// <summary>
/// Calculates euclidean value
/// </summary>
/// <param name="_child"></param>
/// <param name="_current"></param>
/// <returns></returns>
float Euclidean(NodeAStar* _child, NodeAStar* _current)
{
    return std::sqrt((_current->m_xPos - _child->m_xPos) * (_current->m_xPos - _child->m_xPos) + (_current->m_yPos - _child->m_yPos) * (_current->m_yPos - _child->m_yPos));
}

/// <summary>
/// Calculates Mahattan value
/// </summary>
/// <param name="_current"></param>
/// <param name="_goal"></param>
/// <returns></returns>
float Manhattan(NodeAStar* _current, NodeAStar* _goal)
{
    return std::abs(_current->m_xPos - _goal->m_xPos) + std::abs(_current->m_yPos - _goal->m_yPos);
}

/// <summary>
/// A star path finding function
/// </summary>
/// <param name="_Map"></param>
/// <param name="_start"></param>
/// <param name="_end"></param>
/// <returns></returns>
std::vector<NodeAStar*> Pathfinding(char _Map[20][20], NodeAStar* _start, NodeAStar* _end) // pass in map as well
{
    // Create lists
	std::list<NodeAStar*> openList;
	std::list<NodeAStar*> closedList;

    // Add start node
	openList.push_back(_start);

    // Loop until end is found
    while (!openList.empty())
    {
        // Current node is node with lowest f value
        NodeAStar* current = openList.front();
        for (auto node : openList)
        {
            if (node->m_f < current->m_f)
                current = node;
        }

        openList.remove(current);
        closedList.push_back(current);

        // Found end
        if (current->m_xPos == _end->m_xPos && current->m_yPos == _end->m_yPos)
        {
            return BackTrack(current, _Map);
        }

        // Generate children
        for (NodeAStar* child : GetNeighbors(current, _Map))
        {
            // Skip if already in closed list
            bool inClosedList = false;
            for (NodeAStar* node : closedList)
            {
                if (node->m_xPos == child->m_xPos && node->m_yPos == child->m_yPos)
                {
                    inClosedList = true;
                    break;
                }
            }

            if (inClosedList)
            {
                delete child;
                continue;
            }

            // Calculate costs
            child->m_g = current->m_g + Euclidean(child, current);
            child->m_h = Manhattan(child, _end);
            child->m_f = child->m_g + child->m_h;

            // Set parent and add to open list
            child->m_parent = current;
            openList.push_back(child);
        }
    }

    // No path found
    return {};

}
