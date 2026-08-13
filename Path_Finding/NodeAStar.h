/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) 2025 Media Design School
File Name : NodeAStar.h
Description : Nodes that are used for A* pathfinding.
Author : Daniel Kane
Mail : daniel.kane@mds.ac.nz
**************************************************************************/

#pragma once
class NodeAStar
{
	
public:
	float m_f = 0;
	float m_g = 0;
	float m_h = 0;
	int m_xPos;
	int m_yPos;
	NodeAStar* m_parent = nullptr;

	NodeAStar();
	NodeAStar(int _x, int _y);
	NodeAStar FindClosestNeighbors(NodeAStar _current);

	NodeAStar* North = nullptr;
	NodeAStar* NorthEast = nullptr;
	NodeAStar* East = nullptr;
	NodeAStar* SouthEast = nullptr;
	NodeAStar* South = nullptr;
	NodeAStar* SouthWest = nullptr;
	NodeAStar* West = nullptr;
	NodeAStar* NorthWest = nullptr;
};

