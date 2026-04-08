# CT17 -- Implementation Diagrams

Code-block diagrams referenced from `Graph.cpp`.

---

## 1. add_vertex() — Idempotent Vertex Insertion
*`Graph.cpp::add_vertex()` -- check if vertex exists, insert with empty neighbor list if new*

![add_vertex](svgs/add_vertex_impl.svg)

---

## 2. add_edge() — Undirected Edge
*`Graph.cpp::add_edge()` -- adding to both neighbor lists for an undirected graph*

![add_edge](svgs/add_edge_impl.svg)

---

## 3. has_vertex() — O(1) Vertex Lookup
*`Graph.cpp::has_vertex()` -- hash table lookup to check if vertex exists*

![has_vertex](svgs/has_vertex_impl.svg)

---

## 4. has_edge() — Two-Step Edge Lookup
*`Graph.cpp::has_edge()` -- find the vertex, then search its neighbor list*

![has_edge](svgs/has_edge_impl.svg)

---

## 4b. has_edge() — Step-by-Step Trace
*`Graph.cpp::has_edge()` -- tracing has_edge("A", "C") showing how it, it->first, and it->second work*

![has_edge trace](svgs/has_edge_trace.svg)

---

## 5. vertex_count() — Map Size
*`Graph.cpp::vertex_count()` -- one entry per vertex in the unordered_map*

![vertex_count](svgs/vertex_count_impl.svg)

---

## 6. edge_count() — Sum Neighbors, Divide by 2
*`Graph.cpp::edge_count()` -- each undirected edge is stored twice*

![edge_count](svgs/edge_count_impl.svg)

---

## 6b. edge_count() — For Loop Breakdown + Trace
*`Graph.cpp::edge_count()` -- structured binding syntax explained, then traced iteration by iteration*

![edge_count trace](svgs/edge_count_trace.svg)

---

## 7. neighbors() — Return Neighbor List
*`Graph.cpp::neighbors()` -- find vertex, return copy of its neighbor vector*

![neighbors](svgs/neighbors_impl.svg)

---

## 8. BFS — Queue-Based Traversal
*`Graph.cpp::bfs()` -- queue drives level-by-level exploration*

![BFS Implementation](svgs/bfs_impl.svg)

---

## 8b. BFS — Code Execution Trace
*`Graph.cpp::bfs()` -- tracing bfs("A") step by step: which line runs, what q/visited/result contain*

![BFS Code Trace](svgs/bfs_code_trace.svg)

---

## 9. DFS — Stack-Based Traversal
*`Graph.cpp::dfs()` -- stack drives depth-first exploration*

![DFS Implementation](svgs/dfs_impl.svg)

---

## 9a. DFS — Reverse Push Breakdown
*`Graph.cpp::dfs()` -- rbegin/rend, *it dereference, and why we push neighbors in reverse*

![DFS Reverse Push](svgs/dfs_reverse_push.svg)

---

## 9b. DFS — Code Execution Trace
*`Graph.cpp::dfs()` -- tracing dfs("A") step by step: shows duplicate on stack at step 6 being skipped*

![DFS Code Trace](svgs/dfs_code_trace.svg)

---

## 10. print() — Display Adjacency List
*`Graph.cpp::print()` -- iterate all vertices and print neighbor lists*

![print](svgs/print_impl.svg)
