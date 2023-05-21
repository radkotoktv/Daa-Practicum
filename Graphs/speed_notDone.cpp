#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Edge{
    int from;
    int to;
    int w;
};

int n, m;
Edge edges[10005];
int parent[1005];
int height[1005];
int low = 30005;
int high = 0;

bool cmp(Edge e1, Edge e2){
    return e1.w < e2.w;
}

int findRoot(int node){
    if(node != parent[node]){
        parent[node] = findRoot(parent[node]);
    }
    return parent[node];
}

void join(int root1, int root2){
    if(height[root1] > height[root2]){
        parent[root2] = root1;
    }
    else if(height[root1] == height[root2]){
        height[root1]++;
    }
    parent[root2] = root1;
}

Edge solve(int mid){
    int low = edges[mid].w;
    int counter = n;
    for(int i = 0; i < m; i++){
        
        int r1 = findRoot(edges[mid].from);
        int r2 = findRoot(edges[mid].to);
        if(r1 != r2){
            join(r1, r2);
            counter--;
            if(counter == 1){
                return {low, edges[i].w, edges[i].w - low};
            }
        }
    }

    return {0, 0, 100000};
}

int main(){
    scanf("%d%d", &n, &m);

    for(int i = 1; i <= n; i++){
        parent[i] = i;
    }

    int f, t, s;
    for(int i = 0; i < m; i++){
        scanf("%d%d%d", &f, &t, &s);
        edges[i] = {f, t, s};
        low = min(low, s);
        high = max(high, s);
    }

    sort(edges, edges + m, cmp);

    Edge result = solve(0);
    for(int i = 1; i < m; i++){
        Edge res = solve(i);
        if(res.w < result.w){
            result = res;
        }
    }

    printf("%d %d", result.from, result.to);
}