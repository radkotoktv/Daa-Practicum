#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Edge{
    int from;
    int to;
    int w;
};

vector<Edge> edges;
int n, m;
int k;
int uf[100000];
int d[100000];

int findRoot(int node){
    if(uf[node] == node){
        return node;
    }
    return uf[node] = findRoot(uf[node]);
}

void join(int root1 ,int root2){
    uf[root2] = uf[root1];
    if(d[root1] = d[root2]){
        d[root1]++;
    }
    else if(d[root1] < d[root2]){
        uf[root1] = root2;
    }
}

int main(){
    //kruskal //sledvashtata zadacha e single source to all vertices (dijkstra) (kopirame lovers);
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n ; i++){
        uf[i] = i + 1;
    }
    int a, b, c;
    for(int i = 0; i < m; i++){
        scanf("%d%d%d", &a, &b, &c);
        edges.push_back({a, b, c});
    }

    sort(edges.begin(), edges.end(), [](Edge& e1, Edge& e2){
        return e1.w > e2.w;
    });

    int ans = 0;
    for(int i = 0; i < m; i++){
        int root1 = findRoot(edges[i].from);
        int root2 = findRoot(edges[i].to);
        if(root1 != root2){
            join(root1, root2);
            if(edges[i].w < k){
                ans++;
            }
        }
    }
    printf("%d\n", ans);
}