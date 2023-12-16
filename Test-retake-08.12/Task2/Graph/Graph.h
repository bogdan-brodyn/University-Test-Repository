#pragma once

#include <stdio.h>
#include <stdlib.h>

typedef struct Graph Graph;

size_t getNodesCount(const Graph* const graph);

Graph* getGraph(FILE* stream);

int* get—onnectivity—omponents(const Graph* const graph, size_t* componentsCount);

void deleteGraph(Graph** const graph);
