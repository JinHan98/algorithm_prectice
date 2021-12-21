#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> citations) {
    sort(citations.begin(),citations.end(),greater<int>());
    if(citations[0]==0)
        return 0;
    for(int i=0;i<citations.size();i++){
        if(citations[i]<i+1)
            return i;
    }
}