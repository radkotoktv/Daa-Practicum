#include <iostream>
#include <vector>

using namespace std;

int lengthOfLongestSubstring(string s){
    int n = s.size();
    int lastSeen[256];
    fill(lastSeen ,lastSeen + 256, -1);
    int current = 0;
    int result = 0;
    for(std::size_t i = 0 ; i < n; ++i){
        if(lastSeen[s[i]] == -1) {
            ++current;
        }
        else {
            if(i - current > lastSeen[s[i]]){
                ++current;
            }
            else {
                current = i - lastSeen[s[i]];
            }
        }
        
        lastSeen[s[i]] = i;
        result = max(result, current);
    }

    return result;
}

int main(){
    string test = "abcabcbb";
    cout << lengthOfLongestSubstring(test);
}