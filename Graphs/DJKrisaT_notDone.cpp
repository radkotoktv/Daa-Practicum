#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Edge{
    int to;
    int time;
    int price;
};

int n, m, k;
vector<Edge> graph[100005];
bool used[100005];
int dist[100005];

bool OK(int maxPrice){
    fill(used, used + n + 1, false);
    fill(dist, dist + n + 1, 9999999);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> spis;

    spis.push({0, 1});
    dist[1] = 0;
    while(!spis.empty()){
        int top = spis.top().second;
        int curTime = spis.top().first;
        used[top] = true;
        spis.pop();
        for(int i = 0; i < graph[top].size(); i++){
            int vtime = graph[top][i].time;
            int vprice = graph[top][i].price;
            int vto = graph[top][i].to;
            if(!used[vto] && vprice <= maxPrice && (curTime + vtime < dist[vto])){
                dist[vto] = curTime + vtime;
                spis.push({dist[vto], vto});
            }
        }
    }

    return dist[n] <= k;
}

int main(){
    scanf("%d%d%d", &n, &m, &k);

    int start, end, price, time;
    for(int i = 0; i < m; i++){
        scanf("%d%d%d%d", &start, &end, &price, &time);
        graph[start].push_back({end, price, time});
    }

    int l = 1;
    int r = 1000000;
    while(l <= r){
        int mid = l + (r - l) / 2;
        if(OK(mid)){
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }

    if (r == 1000000) {
        printf("-1\n");
    }
    else {
        printf("%d\n", l);
    }

}