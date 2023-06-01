#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

char S[2000005];
int q;
int height[2000005];
int parent[2000005];

int findRoot(int node){
    if(parent[node] == node){
        return node;
    }
    return parent[node] = findRoot(parent[node]);
}

void join(int r1, int r2){
    if (height[r1] > height[r2]) {
        swap(r2, r1);
    }
    else if (height[r1] == height[r2]) {
        ++height[r2];
    }
    parent[r1] = parent[r2];
}

int main(){
    scanf("%s%d", &S, &q);

    for(int i = 0; i < strlen(S); i++){
        parent[i] = i;
    }

    int type, index;
    for(int i = 0; i < q; i++){
        scanf("%d%d", &type, &index);
    }
    
}