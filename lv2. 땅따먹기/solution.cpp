#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int solution(vector<vector<int> > land)
{
    int answer = 0;
    priority_queue<int> temp;
    int each_case=0;
    int now_index;
    for(int i=0;i<land[0].size();i++){
        each_case=land[0][i];
        now_index=i;
        for(int j=1;j<land.size();j++){
            int big=0;
            int max_index;
            for(int k=0;k<land[0].size();k++){
                if(k!=now_index){
                    if(big<land[j][k]){
                        big=land[j][k];
                        max_index=k;
                    }
                }
            }
            each_case=each_case+land[j][max_index];
            now_index=max_index;
        }
        temp.push(each_case);
        each_case=0;
    }
    answer=temp.top();
    return answer;
}
//[[1,2,3,5],[5,6,7,8],[4,3,2,1]]
int main(){
    vector<vector<int> > k(3);
    k[0].push_back(1);
    k[0].push_back(2);
    k[0].push_back(3);
    k[0].push_back(5);
    k[1].push_back(5);
    k[1].push_back(6);
    k[1].push_back(1);
    k[1].push_back(8);
    k[2].push_back(4);
    k[2].push_back(3);
    k[2].push_back(2);
    k[2].push_back(1);
    int a=solution(k);
    cout<<a;
}