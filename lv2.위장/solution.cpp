#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool SortSecCol(const vector<string>& v1, const vector<string>& v2)
{
    return v1[1] < v2[1];
}

int solution(vector<vector<string> > clothes) {
    int answer = 0;
    vector<int> many;
    vector<int> temp;
    sort(clothes.begin(),clothes.end(),SortSecCol);
    int how_many=1;
    for(int i=0;i<clothes.size()-1;i++){
        if(clothes[i][1]==clothes[i+1][1]){
            how_many++;
            if(i==clothes.size()-2)
                many.push_back(how_many);
        }
        else{
            many.push_back(how_many);
            how_many=1;
        }
    }
    for(int i=0;i<many.size();i++)
        answer+=many[i];
    int max=answer;
    int max_2=0;
    for(int i=0;i<many.size();i++){
        answer+=(many[i]*(max-many[i]));
        max_2+=many[i]*(max-many[i]);
        temp.push_back(many[i]*(max-many[i]));
        max-=many[i];
    }
    for(int i=3;i<many.size();i++){
        for(int j=0;j<many.size();j++){
            answer+=(many[i]*(temp[j]))
        }
    }
    return answer;
}

int main(){
    vector<vector<string> > a(3);//[["yellowhat", "headgear"], ["bluesunglasses", "eyewear"], ["green_turban", "headgear"]];
    a[0].push_back("yellowhat");
    a[0].push_back("headgear");
    a[1].push_back("bluesunglasses");
    a[1].push_back("eyewear");
    a[2].push_back("green_turban");
    a[2].push_back("headgear");
    int b=solution(a);
}