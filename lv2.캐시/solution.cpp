#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;
    int exi=0;
    pair<string,int> a;
    a.first="";
    a.second=0;
    int min_index=0;
    if(cacheSize==0)
        return 5*cities.size();
    for(int i=0;i<cities.size();i++){
        for(int j=0;j<cities[i].size();j++){
            if(cities[i][j]>='A'&&cities[i][j]<='Z'){
                cities[i][j]+=32;
            }
        }
    }
    vector<pair<string,int> > cache(cacheSize,a);
    for(int i=0;i<cities.size();i++){
        exi=0;
        for(int j=0;j<cache.size();j++){
            if(cache[j].first==cities[i]){//캐시에 존재할때
                answer++;
                exi=1;
                cache[j].second=i+1;
                break;
            }
        }
        if(exi==0){//캐시에 존재하지 않을때
            int min=cities.size()+1;
            for(int j=0;j<cache.size();j++){
                if(min>cache[j].second){
                    min=cache[j].second;
                    min_index=j;
                }
            }
            cache[min_index].first=cities[i];
            cache[min_index].second=i+1;
            answer+=5;
        }
    }
    return answer;
}

int main(){
    vector<string> a;
    a.push_back("Jeju");
    a.push_back("Seoul");
    a.push_back("Jeju");
    a.push_back("Pangyo");
    a.push_back("Seoul");
    a.push_back("Jeju");
    a.push_back("Pangyo");
    a.push_back("Seoul");
    a.push_back("Pangyo");
    cout<<solution(3,a);
}