/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
private:
    Node* f(int r,int c,int n,vector<vector<int>>& arr) {
        bool isSame = 1;
        bool prev = arr[r][c];
        for(int i=r;i<n+r;i++) {
            for(int j=c;j<n+c;j++) {
                if(prev != arr[i][j]) {
                    isSame = 0;
                    break;
                }
            }
        }
        if(isSame) return new Node(arr[r][c] , 1);
        int mid = n/2;
        Node* topleft = f(r,c,mid,arr);
        Node* topright = f(r,c+mid,mid,arr);
        Node* bottomleft = f(r+mid,c,mid,arr);
        Node* bottomright = f(r+mid,c+mid,mid,arr);
        return new Node(1,0,topleft,topright,bottomleft,bottomright);
    }
public:
    Node* construct(vector<vector<int>>& arr) {
        int n = arr.size();
        return f(0,0,n,arr);
    }
};