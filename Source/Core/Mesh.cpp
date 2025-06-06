/*********************************************************************
 * @file   Mesh.cpp
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

#include "Mesh.h"

Mesh::Mesh(string const& Name, vector<VertexData> const& Vertices, D3D_PRIMITIVE_TOPOLOGY const& MeshType)
	: name(Name)
	, vertexList(Vertices)
	, meshType(MeshType)
{
}
