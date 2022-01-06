#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int K;
int solution(int k, vector<vector<int> > dungeons) {
    int answer = -1;
    K=k;
    dungeons.erase(remove_if(dungeons.begin(),dungeons.end(),is_can),dungeons.end());
    
    return answer;
}



bool is_can(int x){
    if(x>K)
        return true;
    else
        return false;
}