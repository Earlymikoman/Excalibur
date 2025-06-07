/*********************************************************************
 * @file   Mesh.h
 * @brief  .
 * 
 * Project: Excalibur
 * 
 * @author Xander Boosinger (xboosinger@gmail.com)
 * @date   April 2025
 * 
 *********************************************************************
/*
 *			*	/\
 *			   / /	*
 *		*	__/ /__
 *		      /	  *
 *			 /
 */

#pragma once

#include "../DirectX/DirectXGraphics.h"

#include <string>

using std::string;

class Mesh
{
public:

	Mesh(string const& Name, vector<VertexData> const& Vertices, D3D_PRIMITIVE_TOPOLOGY const& MeshType = D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);

	string const& GetName() const { return name; }

	vector<VertexData> const& GetVertices() const { return vertexList; }

	D3D_PRIMITIVE_TOPOLOGY const& GetMeshType() const { return meshType; }

private:

	string name;

	//// The number of vertices in our single mesh
	//const int vertexCount;
	// The vertex data for our single mesh
	vector<VertexData> vertexList;

	D3D_PRIMITIVE_TOPOLOGY meshType;

};
