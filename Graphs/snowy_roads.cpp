#include <iostream>

using namespace std;

int n, m;
int parent[100001];
int height[100001];

int root(int u){
    int node = u;
    while(u != parent[u]){
        u = parent[u];
    }

    parent[node] = u;
    return u;
}

void join(int u, int v){
    if(height[u] > height[v]){
        parent[v] = u;
    }
    else { // za <=
        parent[u] = v;
    }
    height[v] += (height[u] == height[v]);
}

int main(){
    for(int i = 0; i < 100001; i++){
        parent[i] = i;
        height[i] = 0;
    }

    scanf("%d%d", &n, &m);

    if(n == 1){
        printf("0");
        return 0;
    }
    
    for(int i = 0; i < m; i++){
        int a, b;
        scanf("%d%d", &a, &b);
        
        int rootA = root(a);
        int rootB = root(b);

        if(rootA != rootB){ // v razlichni komponenti
            join(rootA, rootB);
            n--;
            if(n == 1){
                printf("%d", i + 1);
                return 0;
            }
        }
    }

    printf("-1");

}