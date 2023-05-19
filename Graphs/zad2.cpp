#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n; // broi vurhove;
int m; // broi rebra;
vector<int> graph[1024];
int visited[1024];
int components[1024];
queue<int> spis;
int comp = 1;


void bfs(int node){
    visited[node] = 1;
    spis.push(node);
    components[node] = comp;
    while(!spis.empty()){
        int node = spis.front();
        spis.pop();
        for(int i = 0; i < graph[node].size(); i++){
            if(!visited[graph[node][i]]){
                spis.push(graph[node][i]);
                visited[graph[node][i]] = 1;
                components[graph[node][i]] = comp;
            }
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

    //namirame vseki vruh ot koq komponenta e;
    for(int node = 1; node <= n; node++){
        if(!visited[node]){
            bfs(node);
            comp++;
        }
    }

    

}