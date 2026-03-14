#include "GraphManager.h"

void GraphManager::addEdge(int a, int b) {
    adj[a].insert(b);
    adj[b].insert(a);
}

std::vector<int> GraphManager::getRelated(int bookId) const {
    std::vector<int> result;
    auto it = adj.find(bookId);
    if (it != adj.end()) {
        for (int n : it->second) result.push_back(n);
    }
    return result;
}
