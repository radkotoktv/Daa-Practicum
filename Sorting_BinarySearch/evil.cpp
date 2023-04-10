#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair<int, int>& label1, pair<int, int>& label2){
    return label1.first == label2.first ? label1.second < label2.second : label1.first < label2.first;
}

int n, m;

int main(){
    scanf("%d%d", &n, &m);
    vector<pair<int, int>> labels;
    
    int start, end;
    for(int i = 0; i < m; i++){
        scanf("%d%d", &start, &end);
        labels.push_back({start, end});
    }

    sort(labels.begin(), labels.end(), cmp);

    int covered = 0;
    int left = labels[0].first;
    int right = labels[0].second;

    for(int i = 1; i < m; i++){
        if(labels[i].first <= right){
            right = max(labels[i].second, right);
        }
        else {
            covered += (right - left + 1);
            left = labels[i].first;
            right = labels[i].second;
        }
    }
    covered += (right - left + 1);


    cout << covered;
}