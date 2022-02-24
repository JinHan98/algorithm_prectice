#include<vector>
using namespace std;

int solution(vector<vector<int> > maps)
{
    int answer = 0;
    pair<int,int> cur_location;
    cur_location.first=0;
    cur_location.second=0;
    int distance=0;
    vector<vector<bool> > is_check(maps.size(),vector<bool>(false,maps[0].size()));
    while(cur_location.first!=maps.size()&&cur_location.second!=maps[0].size()){
        if(maps[cur_location.first][cur_location.second])
    }
    return answer;
}