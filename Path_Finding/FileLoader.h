/***********************************************************************
Bachelor of Software Engineering
Media Design School
Auckland
New Zealand
(c) 2025 Media Design School
File Name : FileLoader.h
Description : Loads a file from fileexplorer.
Author : Daniel Kane
Mail : daniel.kane@mds.ac.nz
**************************************************************************/

#pragma once
#include <fstream>
#include <Windows.h>
#include <ShObjIdl.h>
#include <string>

void LoadFile(std::ifstream* _file);

void SaveFile(std::ofstream* _file);