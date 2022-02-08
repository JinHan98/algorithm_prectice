#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool cmp(vector<int> a, vector<int>b){
    return a[1]<b[1];
}

int solution(int k, vector<vector<int> > dungeons) {
    int answer = 0;
    sort(dungeons.begin(),dungeons.end(),greater<int>());
    sort(dungeons.begin(),dungeons.end(),cmp);
    for(int i=0;i<dungeons.size();i++){
        if(k<dungeons[i][0]){//던전 못돔
            continue;
        }
        else{
            k-=dungeons[i][1];
            answer++;
        }
    }
    return answer;
}