#include <gtest/gtest.h>
#include "Graph.h"
#include <algorithm>
#include <unordered_set>

// =============================================================================
// Helper: build the standard test graph
// =============================================================================
//     A --- B --- D
//     |     |
//     C --- E
//
static Graph build_test_graph() {
    Graph g;
    g.add_edge("A", "B");
    g.add_edge("A", "C");
    g.add_edge("B", "D");
    g.add_edge("B", "E");
    g.add_edge("C", "E");
    return g;
}

// =============================================================================
// Constructor
// =============================================================================

TEST(GraphConstructor, EmptyGraph) {
    Graph g;
    EXPECT_EQ(g.vertex_count(), 0);
    EXPECT_EQ(g.edge_count(), 0);
}

// =============================================================================
// add_vertex
// =============================================================================

TEST(GraphAddVertex, SingleVertex) {
    Graph g;
    g.add_vertex("A");
    EXPECT_TRUE(g.has_vertex("A"));
    EXPECT_EQ(g.vertex_count(), 1);
    EXPECT_EQ(g.edge_count(), 0);
}

TEST(GraphAddVertex, DuplicateIgnored) {
    Graph g;
    g.add_vertex("A");
    g.add_vertex("A");
    EXPECT_EQ(g.vertex_count(), 1);
}

// =============================================================================
// add_edge
// =============================================================================

TEST(GraphAddEdge, CreatesVertices) {
    Graph g;
    g.add_edge("A", "B");
    EXPECT_TRUE(g.has_vertex("A"));
    EXPECT_TRUE(g.has_vertex("B"));
    EXPECT_EQ(g.vertex_count(), 2);
}

TEST(GraphAddEdge, UndirectedEdge) {
    Graph g;
    g.add_edge("A", "B");
    EXPECT_TRUE(g.has_edge("A", "B"));
    EXPECT_TRUE(g.has_edge("B", "A"));
}

TEST(GraphAddEdge, EdgeCount) {
    Graph g = build_test_graph();
    EXPECT_EQ(g.edge_count(), 5);
}

// =============================================================================
// has_vertex / has_edge
// =============================================================================

TEST(GraphQuery, HasVertexTrue) {
    Graph g = build_test_graph();
    EXPECT_TRUE(g.has_vertex("A"));
    EXPECT_TRUE(g.has_vertex("E"));
}

TEST(GraphQuery, HasVertexFalse) {
    Graph g = build_test_graph();
    EXPECT_FALSE(g.has_vertex("Z"));
}

TEST(GraphQuery, HasEdgeFalse) {
    Graph g = build_test_graph();
    EXPECT_FALSE(g.has_edge("A", "D"));
    EXPECT_FALSE(g.has_edge("C", "D"));
}

// =============================================================================
// neighbors
// =============================================================================

TEST(GraphNeighbors, CorrectNeighbors) {
    Graph g = build_test_graph();
    auto n = g.neighbors("B");
    std::unordered_set<std::string> nset(n.begin(), n.end());
    EXPECT_EQ(nset.size(), 3);
    EXPECT_TRUE(nset.count("A"));
    EXPECT_TRUE(nset.count("D"));
    EXPECT_TRUE(nset.count("E"));
}

TEST(GraphNeighbors, NonexistentVertex) {
    Graph g = build_test_graph();
    auto n = g.neighbors("Z");
    EXPECT_TRUE(n.empty());
}

// =============================================================================
// BFS
// =============================================================================

TEST(GraphBFS, VisitsAllVertices) {
    Graph g = build_test_graph();
    auto result = g.bfs("A");
    EXPECT_EQ(result.size(), 5);
    // A must be first (start vertex)
    EXPECT_EQ(result[0], "A");
}

TEST(GraphBFS, AllVerticesPresent) {
    Graph g = build_test_graph();
    auto result = g.bfs("A");
    std::unordered_set<std::string> visited(result.begin(), result.end());
    EXPECT_TRUE(visited.count("A"));
    EXPECT_TRUE(visited.count("B"));
    EXPECT_TRUE(visited.count("C"));
    EXPECT_TRUE(visited.count("D"));
    EXPECT_TRUE(visited.count("E"));
}

TEST(GraphBFS, SingleVertex) {
    Graph g;
    g.add_vertex("X");
    auto result = g.bfs("X");
    EXPECT_EQ(result.size(), 1);
    EXPECT_EQ(result[0], "X");
}

TEST(GraphBFS, NonexistentStart) {
    Graph g = build_test_graph();
    auto result = g.bfs("Z");
    EXPECT_TRUE(result.empty());
}

// =============================================================================
// DFS
// =============================================================================

TEST(GraphDFS, VisitsAllVertices) {
    Graph g = build_test_graph();
    auto result = g.dfs("A");
    EXPECT_EQ(result.size(), 5);
    EXPECT_EQ(result[0], "A");
}

TEST(GraphDFS, AllVerticesPresent) {
    Graph g = build_test_graph();
    auto result = g.dfs("A");
    std::unordered_set<std::string> visited(result.begin(), result.end());
    EXPECT_TRUE(visited.count("A"));
    EXPECT_TRUE(visited.count("B"));
    EXPECT_TRUE(visited.count("C"));
    EXPECT_TRUE(visited.count("D"));
    EXPECT_TRUE(visited.count("E"));
}

TEST(GraphDFS, SingleVertex) {
    Graph g;
    g.add_vertex("X");
    auto result = g.dfs("X");
    EXPECT_EQ(result.size(), 1);
    EXPECT_EQ(result[0], "X");
}

TEST(GraphDFS, NonexistentStart) {
    Graph g = build_test_graph();
    auto result = g.dfs("Z");
    EXPECT_TRUE(result.empty());
}
