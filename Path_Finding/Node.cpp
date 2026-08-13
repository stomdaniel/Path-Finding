/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) 2025 Media Design School
File Name : Node.cpp
Description : Nodes that are used for graphs.
Author : Daniel Kane
Mail : daniel.kane@mds.ac.nz
**************************************************************************/

#include "Node.h"

/// <summary>
/// Node constructor.
/// </summary>
/// <param name="_x"></param>
/// <param name="_y"></param>
/// <param name="_id"></param>
Node::Node(int _x, int _y, char _id)
{
	m_xPos = _x;
	m_yPos = _y;
	m_id = _id;
}

Node::Node()
{
}
