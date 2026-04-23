class DSU{
    vector<int> Parent, Size;
    int noOfComponents;
public:
    DSU(int n){
        noOfComponents = n;
        Parent.resize(n+1);
        Size.resize(n+1);

        for(int i = 0; i <= n; i++){
            Parent[i] = i;
            Size[i] = 1;
        }
    }

    int findParent(int node){
        if(Parent[node] == node){
            return node;
        }
        return Parent[node] = findParent(Parent[node]);
    }

    bool unionNodes(int u, int v){
        int pu = findParent(u);
        int pv = findParent(v);

        // if both have same parents means after adding edge they will form
        // cycle which means after adding the edge u->v its not possible to 
        // form tree
        if(pu == pv){
            return false;
        }

        if(Size[pu] > Size[pv]){
            Parent[pv] = Parent[pu];
            Size[pu] += Size[pv];
        }else{
            Parent[pu] = Parent[pv];
            Size[pv] += Size[pu];
        }
        noOfComponents--;
        return true;
    }

    int getComponents(){
        return noOfComponents;
    }
};

class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        // if there are more edges than nodes count - 1 so simply return false
        if(edges.size() > n-1){
            return false;
        }

        DSU dsu(n);
        for(const auto& edge : edges){
            int u = edge[0], v = edge[1];
            if(!dsu.unionNodes(u, v)){
                return false;
            }
        }

        // if at the end only one component left means there is possible
        // valid tree
        if(dsu.getComponents() == 1){
            return true;
        }
        return false;
    }
};
