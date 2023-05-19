#include <iostream>
#include <algorithm>
//using Dot = std::pair<int,int>;
#define Dot std::pair<int,int>

struct Rectangle {
    int start = 0;
    int end;
    int height;
};

int n, m, length, res;
Rectangle rects[10000];
Dot dots[100420];

int main(){
    scanf("%d%d", &n, &m);
    int w, h;
    for(int i = 0; i < n; ++i){
        scanf("%d%d", &w, &h);
        rects[i].start = length;
        rects[i].end = length + w;
        rects[i].height = h;
        length += w;
    }

    for(int i = 0; i < m; ++i){
        scanf("%d%d", &dots[i].first, &dots[i].second);
    }
    
    std::sort(dots, dots + m);

    int rectIdx = 0;
    for(int i = 0; i < m; ++i){
        int currDotX = dots[i].first;
        int currDotY = dots[i].second;
        while(rectIdx < n && rects[rectIdx].end < currDotX){
            ++rectIdx;
        }

        if(rectIdx == n)
            break;

        if(rects[rectIdx].height >= currDotY || rects[rectIdx + 1].end == currDotX && rects[rectIdx + 1].height >= currDotY){
            ++res;
        }
    }

    printf("%d\n", res);
}