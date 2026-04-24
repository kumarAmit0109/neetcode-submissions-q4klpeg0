class DSU{
    vector<int> Parent, Size;
public:
    DSU(int n){
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
        // cycle which means after adding the edge u->v, it will form cycle
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
        return true;
    }

    
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        // use dsu to track connected components while adding edges one by one
        // if while adding edge u->v , it create the cycle means that edge
        // is redundant connection

        DSU dsu(n);
        for(const auto& edge : edges){
            int u = edge[0];
            int v = edge[1];
            if(!dsu.unionNodes(u, v)){
                return {u, v};
            }
        }
        return {};
    }
};
