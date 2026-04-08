#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>

// =============================================================================
// CT17: Graph Representations & Traversals
// =============================================================================
//
// A graph is a collection of vertices (nodes) connected by edges (links).
// Unlike trees, graphs can have cycles, multiple paths between vertices,
// and vertices with any number of connections.
//
// ? SEE DIAGRAM: images/header_diagrams.md #1 — graph vs tree comparison
//
// ! DISCUSSION: Two ways to represent a graph in code.
//   - Adjacency List: each vertex stores a list of its neighbors
//     - space efficient for sparse graphs: O(V + E)
//     - fast neighbor iteration
//   - Adjacency Matrix: 2D array where matrix[i][j] = 1 if edge exists
//     - fast edge lookup: O(1)
//     - wastes space on sparse graphs: O(V^2)
//
// ? SEE DIAGRAM: images/header_diagrams.md #2 — adjacency list vs matrix
//
// This implementation uses an adjacency list (unordered_map of vectors).
//

class Graph {
public:
    // -------------------------------------------------------------------------
    // Constructor
    // -------------------------------------------------------------------------

    /// Constructs an empty undirected graph.
    Graph();

    // -------------------------------------------------------------------------
    // Modifiers
    // -------------------------------------------------------------------------

    /// Adds a vertex to the graph. Ignored if vertex already exists.
    void add_vertex(const std::string& vertex);

    /// Adds an undirected edge between two vertices.
    /// Creates the vertices if they don't exist.
    void add_edge(const std::string& from, const std::string& to);

    // -------------------------------------------------------------------------
    // Queries
    // -------------------------------------------------------------------------

    /// Returns true if the vertex exists in the graph.
    bool has_vertex(const std::string& vertex) const;

    /// Returns true if an edge exists between from and to.
    bool has_edge(const std::string& from, const std::string& to) const;

    /// Returns the number of vertices in the graph.
    int vertex_count() const;

    /// Returns the number of edges in the graph.
    int edge_count() const;

    /// Returns the neighbors of a vertex.
    std::vector<std::string> neighbors(const std::string& vertex) const;

    // -------------------------------------------------------------------------
    // Traversals
    // -------------------------------------------------------------------------
    //
    // ? SEE DIAGRAM: images/header_diagrams.md #3 — BFS vs DFS visit order
    //
    // ! DISCUSSION: BFS and DFS visit every reachable vertex exactly once.
    //   - BFS (Breadth-First Search): explores level by level using a QUEUE
    //     - finds shortest path in unweighted graphs
    //     - visits all neighbors before going deeper
    //   - DFS (Depth-First Search): explores as deep as possible using a STACK
    //     - useful for cycle detection, topological sort, pathfinding
    //     - visits one branch completely before backtracking
    //

    /// Breadth-First Search from start vertex. Returns vertices in visit order.
    std::vector<std::string> bfs(const std::string& start) const;

    /// Depth-First Search from start vertex. Returns vertices in visit order.
    std::vector<std::string> dfs(const std::string& start) const;

    // -------------------------------------------------------------------------
    // Display
    // -------------------------------------------------------------------------

    /// Prints the adjacency list representation.
    void print() const;

private:
    // ! DISCUSSION: Why unordered_map instead of map?
    //   - unordered_map: O(1) average lookup — backed by a hash table (Module 5)
    //   - map: O(log n) lookup — backed by a red-black tree, keeps keys sorted
    //   - we don't need alphabetical order, just fast lookup by vertex name
    //   - same reason we'd pick a hash table over a BST for a dictionary
    //
    /// Adjacency list: maps each vertex to its list of neighbors.
    std::unordered_map<std::string, std::vector<std::string>> adj_list_;
};
