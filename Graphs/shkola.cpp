#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
vector<int> graph[505];
int components[505];
int currentComponent = 1;
int used[505];

void dfs(int node){
    used[node] = 1;
    components[node] = currentComponent;
    for(int i = 0; i < graph[node].size(); i++){
        if(!used[graph[node][i]]){
            dfs(graph[node][i]);
        }
    }
}

int main(){
    scanf("%d%d", &n, &m);

    int start, end;
    for(int i = 0; i < m; i++){
        scanf("%d%d", &start, &end);
        graph[start].push_back(end);
        graph[end].push_back(start);
    }

    for(int i = 1; i <= n; i++){
        if(!components[i]){
            dfs(i);
            currentComponent++;
        }
    }

    printf("%d", currentComponent - 1);
}