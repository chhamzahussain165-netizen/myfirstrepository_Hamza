#ifndef GRAPHMANAGER_H
#define GRAPHMANAGER_H

#include <unordered_map>
#include <vector>
#include <set>

class GraphManager {
    // adjacency list: book id to set of related book ids
    std::unordered_map<int, std::set<int>> adj;

public:
    void addEdge(int a, int b);
    std::vector<int> getRelated(int bookId) const;
};

#endif // GRAPHMANAGER_H
