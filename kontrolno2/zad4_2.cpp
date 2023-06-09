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
int prices[1005];
int parent[1005];
int height[1005];
int res = 0;
int result = 0;
Edge edges[1005];
vector<pair<int, int>> resVector;

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
    else {
        parent[root1] = root2;
    }
    height[root2] += (height[root1] == height[root2]);
}

int main(){
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++){
        scanf("%d", &prices[i]);
    }

    for(int i = 0; i < 1005; i++){
        parent[i] = i;
    }

    int a, b, c;
    for(int i = 0; i < m; i++){
        scanf("%d%d%d", &a, &b, &c);
        edges[i] = {a, b, c};
    }

    sort(edges, edges + m, cmp);
        
    for(int i = 0; i < m; i++){
        int r1 = findRoot(edges[i].from);
        int r2 = findRoot(edges[i].to);
        if(r1 != r2){
            resVector.push_back({edges[i].from, edges[i].to});
            join(r1, r2);
            n--;
            if(c % 2 != 0){
                int temp = edges[i].w/2 + 1;
                int low = min(edges[i].from, edges[i].to);
                int high = max(edges[i].from, edges[i].to);
                res += prices[low]*temp + prices[high]*(edges[i].w/2);
            }
            else{
                res += prices[edges[i].from]*(edges[i].w/2) + prices[edges[i].to]*(edges[i].w/2);
            }
            if(n == 1){
                result = res;
            }
        }
    }
    printf("%d\n", result);
    for(int i = 0; i < resVector.size(); i++){
        printf("%d %d\n", resVector[i].first, resVector[i].second);
    }
}