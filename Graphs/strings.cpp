#include <iostream>
#include <cstring>
#include <stack>

using namespace std;

char S[2000005];
pair<int, int> qs[2000005];
int parent[2000005];
int treeSize[2000005];
bool marked[2000005];
int q;
stack<int> res;

int findRoot(int node){
    if(node == parent[node]){
        return node;
    }
    return parent[node] = findRoot(parent[node]);
}

void join(int r1, int r2){
    if (treeSize[r2] > treeSize[r1]) {
        swap(r1, r2);
    }
    parent[r2] = r1;
    treeSize[r1] += treeSize[r2];
}


int main(){
    scanf("%s%d", &S, &q);
    int n = strlen(S);

    for(int i = 0; i <= n; i++){
        parent[i] = i;
        treeSize[i] = 1;
    }

    for(int i = 0; i < q; i++){
        scanf("%d%d", &qs[i].first, &qs[i].second);
        if(qs[i].first == 2) {
            marked[qs[i].second] = true;
        }
    }

    for(int i = 1; i < n; i++){
        if(!marked[i - 1] && !marked[i] && S[i - 1] == S[i]){
            int r1 = findRoot(i - 1);
            int r2 = findRoot(i);
            if(r1 != r2){
                join(r1, r2);
            }
        }
    }
    
    for(int i = q - 1; i >= 0; i--){
        int index = qs[i].second;
        if(qs[i].first == 1){
            parent[index] = findRoot(index);
            res.push(treeSize[parent[index]]);
        }
        else {
            marked[index] = false;
            if(!marked[index + 1] && S[index] == S[index + 1]){
                int r1 = findRoot(index);
                int r2 = findRoot(index + 1);
                if(r1 != r2){
                    join(r1, r2);
                }
            }
            if(!marked[index - 1] && S[index] == S[index - 1]){
                int r1 = findRoot(index);
                int r2 = findRoot(index - 1);
                if(r1 != r2){
                    join(r1, r2);
                }
            }
        }
    }

    while(!res.empty()){
        printf("%d\n", res.top());
        res.pop();
    }


}

/*
AABBBBCCDDDDDD
12
1 5
1 10
2 11
2 3
1 2
1 1
2 6
2 8
2 12
2 0
1 1
1 5
*/