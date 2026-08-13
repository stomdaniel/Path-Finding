/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) 2025 Media Design School
File Name : Pathfinding.h
Description : Functions related to A* pathfinding.
Author : Daniel Kane
Mail : daniel.kane@mds.ac.nz
**************************************************************************/

#pragma once
#include <list>
#include "NodeAStar.h"
#include <vector>
#include <cmath>
#include "MapManager.h";

std::vector<NodeAStar*> GetNeighbors(NodeAStar* _node, char _Map[20][20]);

std::vector<NodeAStar*> BackTrack(NodeAStar* _current, char _Map[20][20]);

float Euclidean(NodeAStar* _current, NodeAStar* _goal);
float Manhattan(NodeAStar* _current, NodeAStar* _goal);

std::vector<NodeAStar*> Pathfinding(char _Map[20][20], NodeAStar* _start, NodeAStar* _end);