// Link : https://takeuforward.org/data-structure/depth-first-search-dfs-traversal-graph/
#pragma once
#include "common.h"
#include "IProblem.h"

class DFS : public IProblem {

public:
  void addEdge(std::vector<int> adj[], int u, int v)
  {
    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  void dfs(vector<int> adj[], int node, std::vector<bool>& visited_nodes, std::vector<int>& result)
  {
    // Mark it visited and store the result
    visited_nodes[node] = true;
    result.push_back(node);
 
    for (auto& node : adj[node])
    {
      // Iterate to next unvisited node.
      if (!visited_nodes[node])
        dfs(adj, node, visited_nodes, result);
    }
  }

  void dfs_iterative(vector<int> adj[], int node, std::vector<bool>& visited_nodes, std::vector<int>& result)
  {
    // DFS uses the stack to perform traversal
    std::stack<int> stk;
    stk.push(node);

    while (!stk.empty())
    {
      auto currnode = stk.top();
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

  std::vector<int> getDFS_Iterative(int noofnodes, vector<int> adj[])
  {
    std::vector<int> result;

    // Visited Node list
    std::vector<bool> visited_nodes(noofnodes + 1, false);
    for (int idx = 1; idx < noofnodes; idx++)
    {
      if (!visited_nodes[idx])
      {
        dfs_iterative(adj, idx, visited_nodes, result);
      }
    }

    //return the stored result
    return result;
  }
   
  std::vector<int> getDFS_Recursive(int noofnodes, vector<int> adj[])
  {
    std::vector<int> ret;

    // Visited Node list
    std::vector<bool> visited_nodes(noofnodes +1, false);
    for (int idx = 1; idx < noofnodes; idx++)
    {
      if (!visited_nodes[idx])
      {
        dfs(adj, idx, visited_nodes, ret);
      }
    }
    
    //return the stored result
    return ret;
  }
  int run() override
  {
    DFS dfs;
    vector<int> adj[6];
    dfs.addEdge(adj, 1, 2);
    dfs.addEdge(adj, 1, 3);
    dfs.addEdge(adj, 1, 4);
    dfs.addEdge(adj, 1, 5);
    dfs.addEdge(adj, 2, 4);
    dfs.addEdge(adj, 2, 1);
    dfs.addEdge(adj, 3, 1);
    dfs.addEdge(adj, 4, 1);
    dfs.addEdge(adj, 4, 2);
    dfs.addEdge(adj, 5, 1);

    std::vector<int> df_recur;
    df_recur = dfs.getDFS_Recursive(5, adj);
    std::cout << "Graph DFS Recursive: ";
    for (auto it : df_recur)
      std::cout << it << " ";
    std::cout << std::endl;

    std::vector<int> df_iter;
    df_iter = dfs.getDFS_Iterative(5, adj);
    std::cout << "Graph DFS Iterative: ";
    for (auto it : df_iter)
      std::cout << it << " ";
    std::cout << std::endl;
    return 0;
  }
};