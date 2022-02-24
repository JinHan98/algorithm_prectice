#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool SortSecCol(const vector<string>& v1, const vector<string>& v2)
{
    return v1[1] < v2[1];
}

int solution(vector<vector<string> > clothes) {
    long long answer = 1;
    vector<int> many;
    vector<int> temp;
    sort(clothes.begin(),clothes.end(),SortSecCol);
    int how_many=1;
    string last=clothes[0][1];
    if(clothes.size()==1)
        return 1;
    for(int i=1;i<clothes.size();i++){
        if(clothes[i][1]==last){
            how_many++;
            if(i==clothes.size()-1)
                many.push_back(how_many);
        }
        else{
            many.push_back(how_many);
            how_many=1;
            if(i==clothes.size()-1)
                many.push_back(how_many);
        }
        last=clothes[i][1];
    }
    for(int i=0;i<many.size();i++)
        answer*=(many[i]+1);
    answer--;
    return answer;
}

int main(){
    vector<vector<string> > a={{"a","A"}};
    
    int b=solution(a);
}