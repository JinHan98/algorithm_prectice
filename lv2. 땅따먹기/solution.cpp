#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int> > land)
{
    int answer=0;
    vector<int> max_index;
    for(int i=0;i<land.size();i++){
        int max=0;
        for(int j=0;j<4;j++){

        }
    }
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