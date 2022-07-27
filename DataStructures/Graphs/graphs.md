<h1>Graph Traversal</h1>  

<h2>Breadth First Search</h2>  
Start from start node and use a boolean array to mark the visited node because Graph may contain cycle. Use a queue to push all adjacent nodes of current node.  

Time complexity of BFS is O(E+V)  
See the code [Here](BFS.cpp)  

<h2>Depth First Search</h2>  
Use a boolean array to mark the visited node. Use a stack to traverse in depth first fashion. 
Start from a start node and push any of its adjacent node into stack and mark it visited. Now do this until no adjacent element of top element of stack left. Then backtrack which means pop element from stack and check if there is some unvisited adjacent node left. When stack become empty, search stops. Search can also stop if number of visited node equal to total number of nodes.  

__Application of DFS:__  
1. Detecting cycles in a graph.
2. Finding path between start and destination node.  
3. Topological sorting.  
4. To check if graph is bipartite.  
5. Finding strongly connected components of graph.
6. Solving puzzles with one solution.

Time complexity of DFS is O(V+E)  
See the code of Recursive DFS [Here](DFS_recursive.cpp)  
See the code for Iterative DFS [Here](DFS_iterative.cpp)  




