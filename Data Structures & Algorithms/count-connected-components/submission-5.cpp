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

        // if both have same parents means they belong to same components no merging
        // occurs
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
    int countComponents(int n, vector<vector<int>>& edges) {
        // use union set method
        // initially assume that we have n components after that simply union
        // all the edges now if we able to union them simply reduce the 
        // no. of components

        DSU dsu(n);
        int noOfComponents = n;
        for(auto edge : edges){
            int u = edge[0];
            int v = edge[1];
            if(dsu.unionNodes(u, v)){
                noOfComponents--;
            }
        }

        return noOfComponents;
    }
};
