/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) 2025 Media Design School
File Name : Node.h
Description : Nodes that are used for graphs.
Author : Daniel Kane
Mail : daniel.kane@mds.ac.nz
**************************************************************************/

#pragma once
class Node
{
public:
	char m_id;
	int m_xPos;
	int m_yPos;

	Node(int _x, int _y, char _id);
	Node();
};

