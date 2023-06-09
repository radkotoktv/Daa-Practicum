#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int n, a, b;
vector<pair<int, int>> graph[200005];
queue<int> spis;
int edgesPassed[200005];
int sum[200005];
bool used[200005];

void bfs(int node){
    used[node] = true;
    spis.push(node);
    while(!spis.empty()){
        int top = spis.front();
        spis.pop();
        for(int i = 0; i < graph[top].size(); i++){
            if(!used[graph[top][i].first]){
                edgesPassed[graph[top][i].first]++;
                sum[graph[top][i].first] += graph[top][i].second;
                used[graph[top][i].first] = true;
                spis.push(graph[top][i].first);
            }
        }
    }
}

int main(){
    scanf("%d%d%d", &n, &a, &b);

    int start, end;
	while(cin >> start >> end)
	{
		graph[start].push_back({end, 1});
		graph[end].push_back({start, 0});
	}

    bfs(a);

    if(used[b]){
        printf("%d", edgesPassed[b] - sum[b]);
    }
    else {
        printf("X");
    }
}