#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Edge{
    long long int w;
    long long int to;
    bool hasUp;
};

struct Compare{
    bool operator()(const Edge& e1, const Edge& e2) {
        if (e1.hasUp != e2.hasUp)
            return !e1.hasUp;
        return e1.w > e2.w;
    }
};

long long int n, m;
vector<pair<long long int, long long int>> graph[100005];
priority_queue<Edge, vector<Edge>, Compare> spis;
pair<long long int,long long int> dist[100005];

const long long int INF = 1e18;

int main(){
    cin.tie(NULL);

    scanf("%lld%lld", &n, &m);

    long long int start, end, w;
    for(long long int i = 0; i < m; i++){
        scanf("%lld%lld%lld", &start, &end, &w);
        graph[start].push_back({end, w});
        graph[end].push_back({start, w});
    }

    for(long long int i = 2; i <= n; i++){
        dist[i].first = INF;
        dist[i].second = INF;
    }

    dist[1].first = 0;
    dist[1].second = 0;

    spis.push({0, 1, true});
    while(!spis.empty()){
        long long int node = spis.top().to;
        bool lever = spis.top().hasUp;
        spis.pop();
        for(long long int i = 0; i < graph[node].size(); i++){
            long long int next = graph[node][i].first;
            if(lever){
                if(node > next){
                    continue;
                }

                if(dist[node].second + graph[node][i].second < dist[next].first){
                    dist[next].first = dist[node].second + graph[node][i].second;
                    spis.push({dist[next].first, next, false});
                }
            }
            else {
                if(node < next){
                    continue;
                }

                if(dist[node].first + graph[node][i].second < dist[next].second){
                    dist[next].second = dist[node].first + graph[node][i].second;
                    spis.push({dist[next].second, next, true});
                }
            }
        }
    }

    printf("%lld", dist[n].first);
}