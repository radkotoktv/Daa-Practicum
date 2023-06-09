#include <iostream>
#include <vector>
#include <queue>

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

        int r1 = findRoot(a);
        int r2 = findRoot(b);
        if(r1 != r2){
            join(r1, r2);
            n--;
            if(c % 2 != 0){
                int temp = c/2 + 1;
                int low = min(a, b);
                int high = max(a, b);
                res += prices[low]*temp + prices[high]*(c/2);
            }
            else{
                res += prices[a]*(c/2) + prices[b]*(c/2);
            }
            if(n == 1){
                result = res;
            }

        }
    }

    printf("%d", result);
}