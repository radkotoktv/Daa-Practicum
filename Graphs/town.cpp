#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, a, b;
vector<int> graph[200420];
bool used[200420];
queue<int> spis;

void bfs(int node){
    used[node] = true;
    spis.push(node);
    while(!spis.empty()){
        int node = spis.front();
        spis.pop();
        for(int i = 0; i < graph[node].size(); i++){
            if(!used[graph[node][i]]){
                spis.push(graph[node][i]);
                used[graph[node][i]] = true;
            }
        }
    }
}

int main(){
    scanf("%d%d%d", &n, &a, &b);
    int start, end;
    for(int i = 0; i < n; i++){
        scanf("%d%d", &start, &end);
        graph[start].push_back(end);
    }

    bfs(a);

    printf("%d", used[b]);
}