#include <stdio.h>

#include "../Graph/Graph.h"

#define DEFAULT_EXIT_CODE 0
#define FILE_NOT_FOUND 1
#define MEMORY_LACK 2

int main(void)
{
    FILE* file = NULL;
    if (fopen_s(&file, "../input.txt", "r") != 0)
    {
        printf("File not found\n");
        return FILE_NOT_FOUND;
    }

    Graph* graph = getGraph(file);
    fclose(file);
    if (graph == NULL)
    {
        printf("Memory lack\n");
        return MEMORY_LACK;
    }

    size_t componentsCount = 0;
    int* components = getСonnectivityСomponents(graph, &componentsCount);
    size_t nodesCount = getNodesCount(graph);
    deleteGraph(&graph);
    if (components == NULL)
    {
        printf("Memory lack\n");
        return MEMORY_LACK;
    }
    for (size_t component = 1; component <= componentsCount; ++component)
    {
        printf("Component: %lld, nodes:", component);
        for (size_t node = 0; node < nodesCount; ++node)
        {
            if (components[node] == component)
            {
                printf(" %lld", node);
            }
        }
        printf("\n");
    }
    free(components);
    return DEFAULT_EXIT_CODE;
}
