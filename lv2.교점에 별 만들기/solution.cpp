#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int multi(pair<int,int> a,pair<int,int> b){
    pair<int,int> k;
    k.first=a.first*b.first;
    k.second=a.second*b.second;
    if(k.first%k.second==0)
        return k.first/k.second;
    else
        return 100001;
}

vector<string> solution(vector<vector<int> > line) {
    vector<string> answer;
    vector<pair<int,int> > star;
    int big_x=-100001;
    int big_y=-100001;
    int small_x=100001;
    int small_y=100001;
    for(int i=0;i<line.size()-1;i++){
        for(int j=i+1;i<line.size();j++){
            pair<int,int> k;
            k.first=line[i][2]*line[j][1]-(line[i][1]*line[j][2]);
            k.second=line[i][1]*line[j][1];
            pair<int,int> h;
            h.first=line[i][1]*line[j][1];
            h.second=line[i][1]*line[j][0]-(line[i][0]*line[j][1]);
            if(multi(k,h)==100001)
                continue;
            h.first=multi(k,h);
            k.first=line[i][0]*h.first+line[i][2];
            if(k.first%line[i][1]!=0)
                continue;
            h.second=k.first/line[i][1];
            star.push_back(h);
            if(h.first>big_x)
                big_x=h.first;
            if(h.first<small_x)
                small_x=h.first;
            if(h.second>big_y)
                big_y=h.second;
            if(h.second<small_y)
                small_y=h.second;
        }
    }
    for(int i=small_y;i<=big_y;i++){
        string f;
        for(int j=small_x;j<=big_x;j++){
            f.push_back('.');
        }
        answer.push_back(f);
    }
    for(int i=0;i<star.size();i++){
        answer[star[i].second-small_y][star[i].first-small_x]='*';
    }
    return answer;
}

int main(){
    vector<vector<int> > k(3);
    k[0].push_back(0);
    k[0].push_back(1);
    k[0].push_back(-1);
    k[1].push_back(1);
    k[1].push_back(0);
    k[1].push_back(-1);
    k[2].push_back(1);
    k[2].push_back(0);
    k[2].push_back(1);
    solution(k);
    return 0;
}