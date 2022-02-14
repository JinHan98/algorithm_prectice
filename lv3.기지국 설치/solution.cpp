#include <iostream>
#include <vector>

using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    int how_many=0;
    int pointer=0;
    for(int i=0;i<stations.size();i++){
        if(stations[i]-w-1<pointer){
            pointer=stations[i]+w;
        }
        else{
            int temp=stations[i]-w-pointer-1;
            answer+=(temp/(2*w+1));
            if(temp%(2*w+1)!=0)
                answer++;
            pointer=stations[i]+w;
        }
    }
    if(pointer<n){
        answer+=((n-pointer)/(2*w+1));
        if((n-pointer)%(2*w+1)!=0)
            answer++;
    }
    return answer;
}

int main(){
    vector<int> a;
    a.push_back(3);
    a.push_back(9);
    cout<<solution(10,a,2);
}