#include <bits/stdc++.h>
using namespace std;

class SegmentTree{
    vector<int> tree;
    int size;
    public:
        SegmentTree(int _size){
            size = 4 * _size;
            tree.resize(size);
        }
    
        void printTree(){
            for (int it = 0; it < size; it++){
                cout << tree[it] << " ";
            } cout << endl;
        }
    
        void build(int node, int start, int end, vector<int>& arr){
            if (start == end){
                tree[node] = arr[start];
                return;
            }
            int mid = start + (end-start)/2;
            build(2*node, start, mid, arr);
            build(2*node+1, mid+1, end, arr);
            
            tree[node] = tree[2*node] + tree[2*node+1];
            return;
        }
    
        void buildTree(vector<int>& arr){
            int n = arr.size();
            build(1, 0, n-1, arr);
        }
    
        int query(int node, int start, int end, int left, int right, vector<int>& arr){
            if (right < start || left > end){
                return 0;
            }
            if (left <= start && right >= end){
                return tree[node];
            }
            int mid = start + (end-start)/2;
            int qLeft = query(2*node, start, mid, left, right, arr);
            int qRight = query(2*node+1, mid+1, end, left, right, arr);
            return qLeft + qRight;
        }
    
        int queryTree(int left, int right, vector<int>& arr){
            int n = arr.size();
            return query(1, 0, n-1, left, right, arr);
        }
    
        void update(int node, int start, int end, int idx, int value, vector<int>& arr){
            if (start == end){
                arr[idx] = value;
                tree[node] = value;
                return;
            }
            int mid = start + (end-start)/2;
            if (idx <= mid){
                update(2*node, start, mid, idx, value, arr);
            }
            else {
                update(2*node+1, mid+1, end, idx, value, arr);
            }
            
            tree[node] = tree[2*node] + tree[2*node+1];
            return;
        }
    
        void updateTree(int idx, int value, vector<int>& arr){
            int n = arr.size();
            update(1, 0, n-1, idx, value, arr);
        }
};

int main(){
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = arr.size();
    
    // How to use it ?
    // Use indexes for query and update.
    SegmentTree s(n);
    s.buildTree(arr);
    // s.printTree();
    // cout << s.queryTree(0, 9, arr) << endl;
    // s.updateTree(9, 20, arr);
    // cout << s.queryTree(0, 9, arr) << endl;
    
    return 0;
}
