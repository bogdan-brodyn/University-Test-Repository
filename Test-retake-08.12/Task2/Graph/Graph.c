#include "Graph.h"

struct Graph
{
    size_t nodesCount;
    size_t edgesCount;
    int** matrix;
};

static Graph* createGraph(size_t nodesCount, size_t edgesCount)
{
    Graph* newGraph = (Graph*)malloc(sizeof(Graph));
    if (newGraph == NULL)
    {
        return NULL;
    }
    newGraph->nodesCount = nodesCount;
    newGraph->edgesCount = edgesCount;
    newGraph->matrix = (int**)calloc(nodesCount, sizeof(int*));
    if (newGraph->matrix == NULL)
    {
        free(newGraph);
        return NULL;
    }
    for (size_t node = 0; node < nodesCount; ++node)
    {
        newGraph->matrix[node] = (int*)calloc(edgesCount, sizeof(int));
        if (newGraph->matrix[node] == NULL)
        {
            deleteGraph(&newGraph);
            return NULL;
        }
    }
    return newGraph;
}

size_t getNodesCount(const Graph* const graph)
{
    return graph->nodesCount;
}

Graph* getGraph(FILE* stream)
{
    size_t nodesCount = 0;
    size_t edgesCount = 0;
    fscanf_s(stream, "%lld %lld", &nodesCount, &edgesCount);
    Graph* graph = createGraph(nodesCount, edgesCount);
    if (graph == NULL)
    {
        return NULL;
    }
    for (size_t node = 0; node < nodesCount; ++node)
    {
        for (size_t edge = 0; edge < edgesCount; ++edge)
        {
            fscanf_s(stream, "%d", &graph->matrix[node][edge]);
        }
    }
    return graph;
}

static void dfs(Graph* graph, size_t currentNode, int* used, 
    size_t component, int* components)
{
    if (used[currentNode] != 0)
    {
        return;
    }
    used[currentNode] = 1;
    components[currentNode] = component;
    for (size_t edge = 0; edge < graph->edgesCount; ++edge)
    {
        if (graph->matrix[currentNode][edge] == 1)
        {
            for (size_t node = 0; node < graph->nodesCount; ++node)
            {
                if (graph->matrix[node][edge] == 1 && node != currentNode)
                {
                    dfs(graph, node, used, component, components);
                    break;
                }
            }
        }
    }
}

int* getСonnectivityСomponents(const Graph* const graph, size_t* componentsCount)
{
    int* used = (int*)calloc(graph->nodesCount, sizeof(int));
    int* components = (int*)calloc(graph->nodesCount, sizeof(int));
    if (used == NULL || components == NULL)
    {
        free(used);
        free(components);
        return NULL;
    }
    size_t currentComponentsCount = 0;
    for (size_t node = 0; node < graph->nodesCount; ++node)
    {
        if (used[node] == 0)
        {
            dfs(graph, node, used, ++currentComponentsCount, components);
        }
    }
    *componentsCount = currentComponentsCount;
    free(used);
    return components;
}

void deleteGraph(Graph** const graph)
{
    if (graph == NULL || *graph == NULL)
    {
        return;
    }
    for (size_t node = 0; node < (*graph)->nodesCount; ++node)
    {
        free((*graph)->matrix[node]);
    }
    free((*graph)->matrix);
    free(*graph);
    *graph = NULL;
}
