1. bfs: queue
2. dfs: recursion / stack
3. Cycle detection in undirected graph: 
    * Using bfs: store parent for each node in queue
    * Using dfs: pass parent for each node as parameter during recursion.
4. Cycle detection in Directed graph: 
    * dfs: Use visited and path_visited array.
    * bfs: Topological sort(Kahn's algorithm). If after topological sort, length of result array is less than number of nodes, then it has cycle else no cycle detected.
5. Bipartite: Instead of visited array, use color array which work for both visited and color. If color[i] == -1 => not visited. If color[i]==0  then color of ith node is 0 and if color[i]==1 then color of ith node is 1. If two neighbour have same color then that graph is not bipartite.
6. Topological sort:
    * Using dfs: Run the dfs. Before returning to dfs call push that node into stack.
    * Using bfs (Kahn's Algorithm): Use Indegree for all nodes. If indegree[i]==0 then push it into queue. When we remove node from queue, reduce indegree of all its neighbours by 1. If indegree is 0 then push that node.
7. DAG: For DAG, there must be atleast one node with indegree = 0.
8. __Shortest path in DAG from a src to every other node:__ Use topological sorting. Lets say we are using dfs. So, we have stack where nodes are pushed in stack in topological order. Now, create a distance array and fill it with infinite. Remove all elements from the stack until top is src. Then distance[src]=0. Do the weight relaxation then. If dist[node]+wt < dist[v] then dist[v] = dist[node]+wt;
9. __Shortest path in undirected graph with unit weight from an src to all nodes:__ 
    * Use BFS. 
    * Create a dist array and initilize it with INT_MAX and queue<pair<int,int>>. 
    * dist[src] = 0
    * When dist array is modified, that node with current distance with src will be pushed in queue.
    * If d+1 < dist[it] then dist[it]=d+1 and q.push({it,d+1});

10. __Dijkstra's Algorithm:__
    * Used to find the shortest path in directed/undirected graph.
    * Greedy Algorithm
    * Can't be used if graph has negative weight cycle. It will keep on running and will give TLE.
    * Use priority_queue (min heap) to solve.
        * `priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;`
    * Create a dist array and initilize it with INT_MAX
    * dist[src] = 0
    * pair of pq contains <distance, node>. Whenever we change dist array, we push that in pq.
    * Take out the top element from pq. Iterate over all the neighbours of top element. If d+wt(node,neighbour) < dist[neighbour] then modify the dist array for that neighbour.
    * It can be implemented using queue data structure also. But it will be like brute force, because it will consider all paths and not the minimal path everytime, thus it will do unnecessary exploration in graph.

11. __Bellman Ford Algorithm:__
    * Used to find the shortest part from source to all the nodes.
    * It works only on Directed graph.
    * It can also `detect negative cycles`. So, it work with graph having negative edges.
    * Create a distance array and initilize it with infinity.
    * Relax the edges for exactly N-1 times.
    * After that distance array contains the minimum distance from src to all nodes.
    * If graph has negative cycle, the distance array can still be modified in the Nth iteration.

12. __Floyd Warshal Algorithm:__
    * Multisource shortest path algorithm. Helps to find shortest path from each node to every other node in graph.
    * It can also detect negative edge cycle.
    * It is an algorithm where we try to reach a node via every other node.
    * We use cost matrix of size VxV. Initilize it with infinity. cost[i][i]=0
    * Update cost matrix as : `cost[i][j] = min(cost[i][j],cost[i][via]+cost[via][j])`.
    * If cost[i][i] < 0 => negative cycle for all i.
    * We can't use dijkstra for this because it can't deal with negative cycle.
    * We can use Bellman ford but Bellman ford's time complexity will be O(V\*V\*E) which is approx equal to O(V^4). 

13. __Prims Algorithm:__
    * Used to find the minimum spanning tree in graph.
    * It is a greedy algorithm.
    * Need priority_queue (min heap), visited array, sum counter. If we want to store the edges of MST, we need a vector<pair<int,int>>.
    * Start from any node. Push it into pq. If we want to store edges, we will push {wt, node, parent}.
    * Take out the top from pq. Check if node is visited. If node is visited then drop it and do nothing.
    * If node is not visited, mark it visited and add wt to sum. 
    * Store {parent,node} into MST.
    * Iterate through all the adjacent nodes of current node. If that adjacent node is not visited, then push that into pq.
    * When pq is empty, you have MST.

14. __Disjoint set:__
    * Used to find if two element are in same set or not. (alternatively if two nodes are part of same component or not).
    * Union and Find are the two operations used.
    * Find:
        * Declare a parent array of size n+1 and initilize it with its index.
        * Do path compression. That is find the ultimate parent for each node. Ultimate parent is someone which is parent of itself.
    * Union by rank/size.
        * Union by rank: 
            * Height consideration.
            * if ultimate parent of both nodes are same, then don't do anything and return. Since, they are part of same component.
            * Declare a rank array of size n+1 and initilize it with 0.
            * Join the less rank on high rank i.e. Update parent of less rank.
            * If rank is same then join anyone to other. Increase the rank by one on which other is added.
        * Union by size: 
            * Number of nodes are taken into consideration.
            * if ultimate parent of both nodes are same, then don't do anything and return. Since, they are part of same component.
            * Declare a size array of size n+1 and initilize it with 1.
            * Join the less size on high size i.e. Update parent of less size and update size as size[high]+=size[low]

15. __Kruskals Algorithm:__
    * Used to find MST.
    * Use Disjoint set data structure.
    * Sort all the edges based on their weight.
    * Now, iterate over all the sorted edges as:
        * If find(u)!=find(v) then sum+=wt and union(u,v)
    * return sum.

14. __Kosaraju Algorithm:__
    * Used to find strongly connected components.
    * All nodes are member of one SCC iff every node is visited via every other node.
    * Find finishing time. Use dfs and store it in stack.
    * Take the transpose of graph. (invert the direction of edge for all edges).
    * Perform dfs on the order of elements of stack.
    * Number of time dfs will run is the number of SCC.

15. __Tarzens Algorithm:__
    * Used to find bridges in graph.
    * Bridges are those edges, if we remove those then Graph is divided into two or more components.
    * Idea is to use dfs algorithm.
    * Time and minTime array used. Time stores the reaching time for that node via dfs. minTime stores the minimum time to reach there.
    * Every time dfs call, fill time and mintime with timer.
    * While returning from dfs update the minTime if possible.
    * Iterate over all the adjacent nodes. If node is not equal to parent then if not visited then perform dfs. Then update the minTime as min(minTime[node],minTime[it]).
    * If minTime[it] > time[node] then add that edge into bridegs.
    * If not equal to parent and visited then only update the minTime.







### Complexities:
1. BFS:
    * Time: O(E+V)
    * Space: O(E)
2. DFS:
    * Time: O(E+V)
    * Space: O(E)
3. Dijkstra:
    * Time: O(Elog(V))
    * Space: O(E)
4. Bellman Ford:
    * Time: O(E*V)
    * Space: O(V) (distance array).
5. Floyd Warshal:
    * Time: O(N^3)
    * Space: O(N^2)
6. Prims:
    * Time: O(Elog(V))
    * Space: O(E)
7. Kruskals:
    * Time: O(ElogE) 
    * Space: O(E+V)
8. Kosaraju:
    * Time: O(E+V)
    * Space: O(E+V)
9. Tarzen's:
    * Time: O(E+V)
    * Space: O(E+V)


### Graph code:
1. [BFS](https://practice.geeksforgeeks.org/problems/bfs-traversal-of-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=bfs_of_graph)
2. [DFS](https://practice.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=dfs_of_graph)
3. [Cycle detection in an undirected graph](https://practice.geeksforgeeks.org/problems/detect-cycle-in-an-undirected-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=detect-cycle-in-an-undirected-graph)
4. [Bipartite Graph](https://practice.geeksforgeeks.org/problems/bipartite-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=bipartite-graph)
5. [Cycle detection in directed graph using DFS](https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=detect-cycle-in-a-directed-graph)
6. [Topological Sort (Kahn's algorithm)](https://practice.geeksforgeeks.org/problems/topological-sort/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=topological-sort)
7. [Topological Sort (DFS)](topological_dfs.cpp)
8. [Shortest path in DAG (Topological sort)](https://practice.geeksforgeeks.org/problems/shortest-path-in-undirected-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=direct-acyclic-graph)
9. [Shortest path in Undirected graph with unit weights](https://practice.geeksforgeeks.org/problems/shortest-path-in-undirected-graph-having-unit-distance/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=shortest-path-in-undirected-graph-having-unit-distance)
10. [Dijkstra Algorithm](https://practice.geeksforgeeks.org/problems/implementing-dijkstra-set-1-adjacency-matrix/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=implementing-dijkstra-set-1-adjacency-matrix)
11. [Bellman Ford Algorithm](https://practice.geeksforgeeks.org/problems/distance-from-the-source-bellman-ford-algorithm/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=distance-from-the-source-bellman-ford-algorithm)
12. [Floyd Warshal Algorithm](https://practice.geeksforgeeks.org/problems/implementing-floyd-warshall2042/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=implementing-floyd-warshall)
13. [Prims Algorithm](https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=minimum-spanning-tree)
14. [Disjoint set](disjointSet.cpp)
15. [Kruskals Algorithm](https://practice.geeksforgeeks.org/problems/minimum-spanning-tree/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=minimum-spanning-tree)
16. [Kosaraju Algorithm](https://practice.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=strongly-connected-components-kosarajus-algo)
17. [Tarzen's Alg0rithm](https://leetcode.com/problems/critical-connections-in-a-network/submissions/)






### Examples:  
1. [Alien dictionary](https://practice.geeksforgeeks.org/problems/alien-dictionary/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=alien-dictionary)
2. [Course Scheduling-I](https://practice.geeksforgeeks.org/problems/prerequisite-tasks/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=prerequisite-tasks)
3. [Course Scheduling-II](https://practice.geeksforgeeks.org/problems/course-schedule/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=course-schedule)
4. [Shortest path in DAG](https://practice.geeksforgeeks.org/problems/shortest-path-in-undirected-graph/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=direct-acyclic-graph)
5. [Rotten Oranges](https://practice.geeksforgeeks.org/problems/rotten-oranges2536/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=rotten_oranges)
6. [Number of distinct Island](https://practice.geeksforgeeks.org/problems/number-of-distinct-islands/1?utm_source=youtube&utm_medium=collab_striver_ytdescription&utm_campaign=number-of-distinct-islands)
7. [Articulation Point](https://www.youtube.com/watch?v=j1QDfU21iZk&list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw&index=30)
8. [Minimum height trees](https://leetcode.com/problems/minimum-height-trees/submissions/)

