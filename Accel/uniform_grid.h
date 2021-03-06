#ifndef UNIFORM_GRID_H
#define UNIFORM_GRID_H

#include <vector>
#include "../glm/glm.hpp"
#include <iostream>
#include <thrust/device_ptr.h>
#include <thrust/device_vector.h>
#include <thrust/sort.h>

class hash_grid{
public:
	int m_numParticles;
	glm::vec3* m_points;
	glm::vec3 m_gridSize;
	int* m_ids;
	int m_maxNeighbors;
	int* m_gridNumNeighbors;
	int* m_bruteNumNeighbors;
	int* m_gridNeighbors;
	int* m_bruteNeighbors;
	float m_h;

public:
	hash_grid(int numParticles, glm::vec3* points, glm::vec3 gridSize);

	void findNeighbors(int maxNeighbors, float h, bool useGrid = true, bool useGPU = true);

	int hashParticle(int id) const;

	~hash_grid();

private:

	void findNeighborsGPU(bool useGrid);
	void findNeighborsCPU(bool useGrid);
	void findNeighborsCPUGridHelper();
	void findNeighborsCPUBruteHelper();

	bool neighborsAlloc;

	glm::vec3 *c_positions;
	std::pair<int, int>* c_grid;
	int* c_neighbors;
	int* c_ids, *c_cellIds, *c_pIds;
	int* c_numNeighbors;

	std::pair<int, int>* m_grid;
	int *m_cellIds, *m_pIds;

	float* c_distances;
	int* c_ids_test;

};

#endif