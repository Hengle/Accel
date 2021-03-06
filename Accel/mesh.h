#ifndef MESH_H
#define MESH_H

#include "../glm/glm.hpp"
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include "utils.h"
#include "boundingBox.h"

class mesh{

public:
	mesh();
	mesh(std::string fileName);
	int numTris, numVerts;
	glm::vec3* tris;
	glm::vec3* verts;
	boundingBox bb;
};

#endif