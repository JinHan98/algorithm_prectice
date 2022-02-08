#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer(id_list.size(),0);
    int reporter;
    int reported;
    vector<int> how_many(id_list.size(),0);
    vector<vector<bool> > reported_person(id_list.size(),vector<bool>(id_list.size(),false));
    for(int i=0;i<report.size();i++){
        for(int j=0;j<report[i].size();j++){
            if(report[i][j]==' '){
                for(int k=0;k<id_list.size();k++){
                    if(id_list[k]==report[i].substr(0,j)){
                        reporter=k;
                    }
                    else if(id_list[k]==report[i].substr(j+1)){
                        reported=k;
                    }
                }
                if(reported_person[reported][reporter]==false)
                    how_many[reported]++;
                reported_person[reported][reporter]=true;
                break;
            }
        }
    }
    for(int i=0;i<id_list.size();i++){
        if(how_many[i]<k)
            continue;
        else{
            for(int j=0;j<id_list.size();j++){
                if(reported_person[i][j]==true)
                    answer[j]++;
            }
        }
    }
    return answer;
}

int main(){
    vector<string> a;
    vector<string> b;
    a.push_back("muzi");
    a.push_back("frodo");
    a.push_back("apeach");
    a.push_back("neo");
    b.push_back("muzi frodo");
    b.push_back("apeach frodo");
    b.push_back("frodo neo");
    b.push_back("muzi neo");
    b.push_back("apeach muzi");
    int k=2;
    vector<int> c=solution(a,b,k);
    for(int k :c)
        cout<<k;
}