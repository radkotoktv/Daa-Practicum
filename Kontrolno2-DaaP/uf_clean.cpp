#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
int height[100005];
int parent[100005];
int res = 0;

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
    
    for(int i = 0; i <= n; i++){
        parent[i] = i;
    }

    if(n == 1){
        printf("0");
        return 0;
    }

    int a, b;
    for(int i = 0; i < m; i++){
        scanf("%d%d", &a, &b);

        int r1 = findRoot(a);
        int r2 = findRoot(b);

        if(r1 != r2){
            join(r1, r2);
            n--;
            if(n == 1){
                res = i + 1;
            }
        }
    }

    if(res == 0){
        res = -1;
    }

    printf("%d", res);
}