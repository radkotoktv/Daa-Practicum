#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m, k;
vector<pair<int, int>> graph[20005];
bool used[20005];
int dist[20005];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> spis;

int main(){
    scanf("%d%d%d", &n, &m, &k);
    
    int start, end, price, time;
    for(int i = 0; i < m; i++){
        scanf("%d%d%d%d", &start, &end, &price, &time);
        graph[start].push_back({end, time - price});
        graph[end].push_back({start, time - price});
    }

    dist[1] = 0;
    for(int i = 2; i <= n; i++){
        dist[i] = 9999999;
    }

    spis.push({0, 1});  
    while(!spis.empty()){
        int node = spis.top().second;
        spis.pop();
        used[node] = true;
        for(int i = 0; i < graph[node].size(); i++){
            int next = graph[node][i].first;
            if(!used[next]){
                if(dist[node] + graph[node][i].second < dist[next]){
                    dist[next] = dist[node] + graph[node][i].second;
                    spis.push({dist[next], next});
                }
            }
        }
    }

    printf("%d", k - dist[n]);

}