#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(int n, vector<vector<int> > edge) {
    int answer = 0;
    vector<int> dis(n,0);
    int temp;
    vector<bool> is_done(n,false);
    is_done[0]=true;
    vector<vector<bool> > line(n,vector<bool>(n,false));
    queue<int> qu;
    qu.push(0);
    for(int i=0;i<edge.size();i++){
        line[edge[i][0]-1][edge[i][1]-1]=true;
        line[edge[i][1]-1][edge[i][0]-1]=true;
    }
    while(!qu.empty()){
        temp=qu.front();
        for(int i=0;i<line[temp].size();i++){
            if(line[temp][i]==true&&is_done[i]!=true){
                dis[i]=dis[temp]+1;
                is_done[i]=true;
                qu.push(i);
            }
        }
        qu.pop();
    }
    for(int k=1;k<n;k++){
        if(dis[k]==dis[temp])
            answer++;
    }
    return answer;
}


int main(){
    int n=6;
    vector <vector<int> > k(7);
    k[0].push_back(3);
    k[0].push_back(6);
    k[1].push_back(4);
    k[1].push_back(3);
    k[2].push_back(3);
    k[2].push_back(2);
    k[3].push_back(1);
    k[3].push_back(3);
    k[4].push_back(1);
    k[4].push_back(2);
    k[5].push_back(2);
    k[5].push_back(4);
    k[6].push_back(5);
    k[6].push_back(2);
    int a=solution(n,k);
    cout<<a<<endl;
}