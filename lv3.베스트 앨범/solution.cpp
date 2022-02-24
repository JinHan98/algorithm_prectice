#include <string>
#include <vector>
#include <algorithm>

using namespace std;
bool compare(pair<int,int> a,pair<int,int> b){
    return a.first>b.first;
}
//문제 이해 잘못함
vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    int op=0;
    vector<pair<int,int> > genres_sum;
    vector<int> genres_max;
    //vector<int> genres_max_index;
    vector<int> all_index;
    vector<string> genres_kind;
    vector<int> genres_index;
    pair<int,int> a;
    a.first=plays[0];
    a.second=0;
    genres_kind.push_back(genres[0]);
    genres_sum.push_back(a);
    genres_max.push_back(plays[0]);
    genres_index.push_back(0);
    //genres_max_index.push_back(0);
    all_index.push_back(0);
    for(int i=1;i<genres.size();i++){
        for(int j=0;j<genres_kind.size();j++){
            if(genres[i]==genres_kind[j]){//장르가 있다면
                genres_sum[j].first+=plays[i];
                genres_index[j]++;
                if(genres_max[j]<plays[i]){
                    plays[i]=genres_max[j];
                    //genres_max_index[j]=genres_index[j];
                    all_index[j]=i;
                }
                op=1;
                break;
            }
        }
        if(op==1){
            op=0;
            continue;
        }
        genres_kind.push_back(genres[i]);
        a.first=plays[i];
        a.second++;
        genres_sum.push_back(a);
        genres_max.push_back(plays[i]);
        genres_index.push_back(0);
        //genres_max_index.push_back(0);
        all_index.push_back(i);
    }
    sort(genres_sum.begin(),genres_sum.end(),compare);
    for(int i=0;i<genres_sum.size();i++){
        answer.push_back(all_index[genres_sum[i].second]);
        answer.push_back(genres_sum[i].second);
    }
    return answer;
}


int main(){
    vector<string> a={"classic", "pop", "classic", "classic", "pop"};
    vector<int> b={500, 600, 150, 800, 2500};
    solution(a,b);
}