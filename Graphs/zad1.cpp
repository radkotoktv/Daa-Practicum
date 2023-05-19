#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n; // broi vurhove;
int m; // broi rebra;
vector<int> graph[1024];
int visited[1024];

void dfs(int node){
    visited[node] = 1;
    for(int i = 0; i < graph[node].size(); i++){
        if(!visited[graph[node][i]]){
            dfs(graph[node][i]);
        }
    }
}

int main(){
    scanf("%d%d", &n, &m);

    int from, to;
    for(int i = 0; i < n; i++){
        scanf("%d%d", &from, &to);
        graph[from].push_back(to);
        graph[to].push_back(from);
    }

    int source, sink; // nachalen i kraen vruh;

    scanf("%d%d", &source, &sink);

    dfs(source); 
    if(visited[sink] == 1){
        printf("There is a path!");
    }
}