#include <stdio.h>
#include <stdbool.h>

// Number of vertices in the graph
#define V 5

// A utility function to check if the current color assignment is safe for vertex v
bool isSafe(int graph[V][V], int color[], int v, int c) {
    for (int i = 0; i < V; i++) {
        // Check if adjacent vertices have the same color
        if (graph[v][i] == 1 && color[i] == c) {
            return false;
        }
    }
    return true;
}

// A utility function to solve the m-coloring problem using backtracking
bool graphColoringUtil(int graph[V][V], int m, int color[], int v) {
    // If all vertices are assigned a color then return true
    if (v == V) {
        return true;
    }

    // Consider this vertex v and try different colors
    for (int c = 1; c <= m; c++) {
        // Check if assigning color c to vertex v is safe
        if (isSafe(graph, color, v, c)) {
            color[v] = c;

            // Recur to assign colors to the rest of the vertices
            if (graphColoringUtil(graph, m, color, v + 1)) {
                return true;
            }

            // If assigning color c doesn't lead to a solution, backtrack
            color[v] = 0;
        }
    }

    // If no color can be assigned to this vertex then return false
    return false;
}

// A function to solve the m-coloring problem
bool graphColoring(int graph[V][V], int m) {
    int color[V];

    // Initialize all color values to 0 (no color assigned)
    for (int i = 0; i < V; i++) {
        color[i] = 0;
    }

    // Call the utility function to solve the problem
    if (graphColoringUtil(graph, m, color, 0)) {
        // If solution exists, print the color assignments
        printf("Solution exists: Following are the assigned colors:\n");
        for (int i = 0; i < V; i++) {
            printf("Vertex %d --> Color %d\n", i, color[i]);
        }
        return true;
    } else {
        printf("Solution does not exist.\n");
        return false;
    }
}

int main() {
    // Representation of graph using an adjacency matrix
    // Example: 5 vertices (V=5) and an adjacency matrix for a graph
    int graph[V][V] = {
        {0, 1, 1, 1, 0},
        {1, 0, 1, 0, 1},
        {1, 1, 0, 1, 1},
        {1, 0, 1, 0, 0},
        {0, 1, 1, 0, 0}
    };

    int m = 3;  // Number of colors

    // Call the graphColoring function
    if (!graphColoring(graph, m)) {
        printf("No solution with %d colors\n", m);
    }

    return 0;
}
