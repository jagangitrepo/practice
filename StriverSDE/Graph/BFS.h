#pragma once
// Link : https://takeuforward.org/data-structure/depth-first-search-bfs-traversal-graph/
#pragma once
#include "common.h"
#include "IProblem.h"

class BFS : public IProblem {

public:
  void addEdge(std::vector<int> adj[], int u, int v)
  {
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  void bfs_iterative(std::vector<int> adj[], int node, std::vector<bool>& visited_nodes, std::vector<int>& result)
  {
    // BFS uses the stack to perform traversal
    std::queue<int> stk;
    stk.push(node);

    while (!stk.empty())
    {
      auto currnode = stk.front();
      stk.pop();

      // Skip the visited node
      if (visited_nodes[currnode])
        continue;

      // Add the un visited node into the result path
      result.push_back(currnode);
      visited_nodes[currnode] = true;

      for (auto& neighbour : adj[currnode])
      {
        if (!visited_nodes[neighbour])
        {
          stk.push(neighbour);
        }
      }
    }
  }

  std::vector<int> getBFS_Iterative(int noofnodes, std::vector<int> adj[])
  {
    std::vector<int> result;

    // Visited Node list
    std::vector<bool> visited_nodes(noofnodes + 1, false);
    for (int idx = 1; idx < noofnodes; idx++)
    {
      if (!visited_nodes[idx])
      {
        bfs_iterative(adj, idx, visited_nodes, result);
      }
    }

    //return the stored result
    return result;
  }

  int run() override
  {
    BFS bfs;
    std::vector<int> adj[15];
    bfs.addEdge(adj, 1, 2);
    bfs.addEdge(adj, 1, 3);
    bfs.addEdge(adj, 1, 4);
    bfs.addEdge(adj, 2, 5);
    bfs.addEdge(adj, 2, 6);
    bfs.addEdge(adj, 5, 9);
    bfs.addEdge(adj, 5, 10);
    bfs.addEdge(adj, 4, 7);
    bfs.addEdge(adj, 4, 8);
    bfs.addEdge(adj, 7, 11);
    bfs.addEdge(adj, 7, 12);

    std::vector<int> df_iter;
    df_iter = bfs.getBFS_Iterative(15, adj);
    std::cout << "Graph BFS Iterative: ";
    for (auto it : df_iter)
      std::cout << it << " ";
    std::cout << std::endl;
    return 0;
  }
};