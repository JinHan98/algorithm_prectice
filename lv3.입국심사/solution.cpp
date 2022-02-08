#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
//문제점: 예약이 되어있는데 그 반복문에 지금 기다리는게 없다고 시간을 올려버리는 경우
long long solution(int n, vector<int> times) {
    long long answer = 0;
    vector<int> left_time;
    int max_num=0;
    sort(times.begin(),times.end());
    n-=times.size();
    answer=times[0];
    int min_time=1000000001;
    bool wait=false;
    vector<bool> vaca(times.size(),false);
    for(int i=0;i<times.size();i++)
        left_time.push_back(times[i]-times[0]);
    while(n>0){
        for(int i=0;i<left_time.size();i++){//예약이 있는경우 
            if(vaca[i]==true&&left_time[i]==0){
                vaca[i]=false;
                n--;
                left_time[i]=times[i];
            }
        }
        if(n==0)
            break;
        for(int i=0;i<left_time.size();i++){
            if(left_time[i]==0){
                for(int j=0;j<i&&vaca[j]==false;j++){
                    if(times[i]>(left_time[j]+times[j])){
                        vaca[j]=true;
                        wait=true;
                        break;
                    }
                }
                if(wait==false){
                    left_time[i]=times[i];
                    n--;
                }
            }
        }
        if(n==0)
            break;
        for(int i=0;i<left_time.size();i++)
            min_time=(min_time>left_time[i]) ? left_time[i] : min_time;
        if(min_time==0){
            for(int i=0;i<left_time.size();i++){
                left_time[i]--;
            }
            answer++;
        }
        answer+=min_time;    
        for(int i=0;i<left_time.size();i++)
            left_time[i]-=min_time;
        wait=false;
        min_time=1000000001;
    }
    for(int i=0;i<left_time.size();i++)
        max_num=(max_num>left_time[i]) ? max_num : left_time[i];
    answer+=max_num;
    
    return answer;
}

int main(){
    int n=6;
    vector<int> a;
    a.push_back(7);
    a.push_back(10);
    int b=solution(n,a);
    cout<<b<<endl;
}