#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
vector<int> graph[2005];
int q;
pair<int, int> questions[100005];
int used[2005];
int components[2005];
int currentComponent = 1;

void dfs(int node){
    components[node] = currentComponent;
    used[node] = 1;
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

    scanf("%d", &q);
    for(int i = 0; i < q; i++){
        scanf("%d%d", &questions[i].first, &questions[i].second);
    }

    for(int i = 1; i <= n; i++){
        if(!components[i]){
            dfs(i);
            currentComponent++;
        }

    }

    for(int i = 0; i < q; i++){
        printf("%d", components[questions[i].first] == components[questions[i].second]);
    }

}