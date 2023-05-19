#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, u, v, q, currentComponent;
vector<int> adj[1001];
int components[1001];

void dfs(int u){
    components[u] = currentComponent;
    for(int v: adj[u]){
        if(!components[v]){
            dfs(v);
        }
    }
}

int main(){
    // BFS - queue
    // DFS - stack/recursion
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; i++){
        scanf("%d%d", &u, &v);
        adj[u].push_back(v);
        adj[v].push_back(u);
    }


    for(int i = 1; i <= n; i++){
        if(!components[i]){
            currentComponent = i;
            dfs(i);
        }
    }


    scanf("%d", &q);
    for(int i = 0; i < q; i++){
        scanf("%d%d", &u, &v);

        printf("%d", components[u] == components[v]);
    }
}