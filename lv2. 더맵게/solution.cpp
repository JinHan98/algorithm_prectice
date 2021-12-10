#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    make_heap(scoville.begin(),scoville.end(),greater<int>());
    while(1){
        if(scoville[0]<=K){
            if(scoville.size()==1)
                return -1;
            int temp=scoville[0];
            pop_heap(scoville.begin(),scoville.end(),greater<int>());
            scoville.pop_back();
            temp=temp+(scoville[0]*2);
            pop_heap(scoville.begin(),scoville.end(),greater<int>());
            scoville.pop_back();
            scoville.push_back(temp);
            make_heap(scoville.begin(),scoville.end(),greater<int>());
            answer++;
        }
        else
            break;
    }
    return answer;
}


int main(){
    vector<int> a;
    a.push_back(1);
    a.push_back(1);
    a.push_back(1);
    a.push_back(1);
    a.push_back(1);
    a.push_back(1);
    int b=solution(a,4);
    cout<<b<<endl;
}