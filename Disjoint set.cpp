#include <bits/stdc++.h>
using namespace std;

class DisjointSet{
    public:
        vector<int> parent, rank;
        DisjointSet(int n){
            parent.resize(n);
            for (int node = 0; node < n; node++){
                parent[node] = node;
            }
            rank.resize(n);
        }
    
        int findParent(int node){
            if (parent[node] == node){
                return node;
            }
            return parent[node] = findParent(parent[node]);
        }
    
        void unionByRank(int node1, int node2){
            int parent1 = findParent(node1);
            int parent2 = findParent(node2);
            if (parent1 != parent2){
                if (rank[parent1] == rank[parent2]){
                    parent[parent2] = parent1;
                    rank[parent1] += 1;
                }
                else if (rank[parent1] < rank[parent2]){
                    parent[parent1] = parent2;
                }
                else {
                    parent[parent2] = parent1;
                }
            }
        }
};

int main(){
    DisjointSet s(6);
    s.unionByRank(0, 1);
    cout << s.findParent(1) << endl;
    
    return 0;
}
