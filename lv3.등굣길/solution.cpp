#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(int m, int n, vector<vector<int> > puddles) {
    int answer = 0;
    vector<vector<int> > road(n,vector<int>(m,-1));
    road[0][0]=1;
    for(int i=0;i<puddles.size();i++){
        road[puddles[i][1]-1][puddles[i][0]-1]=0;
    }
    for(int i=1;i<n;i++){
        if(road[i][0]==-1)
            road[i][0]=1;
        else{
            for(int j=i;j<n;j++)
                road[j][0]=0;
            break;
        }
    }
    for(int i=1;i<m;i++){
        if(road[0][i]==-1)
            road[0][i]=1;
        else{
            for(int j=i;j<m;j++)
                road[0][j]=0;
            break;
        }
    }
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            if(road[i][j]==-1)
                road[i][j]=(road[i-1][j]+road[i][j-1])%1000000007;
        }
    }
    answer=road[n-1][m-1];
    return answer;
}
int main(){
    vector<vector<int> > a(1);
    a[0].push_back(1);
    a[0].push_back(5);
    cout<<solution(1,100,a);
    return 0;
}