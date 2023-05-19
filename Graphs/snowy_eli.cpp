#include <iostream>

using namespace std;

int n, m;
int parent[100001];
int depth[100001];

int findRoot(int node){
    if(node != parent[node]){
        parent[node] = findRoot(parent[node]);
    }
    return parent[node];
}

void join(int root1, int root2){
    if(depth[root2] > depth[root1]){
        std::swap(root1, root2);
    }
    else if(depth[root2] == depth[root1]){
        depth[root1]++;
    }
    parent[root2] = root1;
}

int main(){
    scanf("%d%d", &n, &m);
    for(int i = 1 ;i <= n; i++){
        parent[i] = i;
    }

    if(n == 1){
        printf("0");
        return 0;
    }

    int start, end;
    for(int i = 0; i < m; i++){
        scanf("%d%d", &start, &end);

        int r1 = findRoot(start);
        int r2 = findRoot(end);

        if(r1 != r2){
            join(r1, r2);
            n--;
            if(n == 1){
                printf("%d", i + 1);
                return 0;
            }
        }
    }

    printf("-1");
}