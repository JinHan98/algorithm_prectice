#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    vector<string> act;
    vector<string> uid;
    vector<string> name;
    for(int i=0;i<record.size();i++){
        int stack=0;
        int start=0;
        for(int j=0;j<record[i].size();j++){
            if(record[i][j]==' '){
                if(stack==0){
                    act.push_back(record[i].substr(0,j));
                    if(act[i]=="Leave"){
                        uid.push_back(record[i].substr(j,10));
                        for(int k=0;k<i;k++){
                            if(uid[i]==uid[k]){
                                name.push_back(name[k]);
                                break;
                            }
                        }
                        break;
                    }
                    stack++;
                    start=j;
                    continue;
                }
                if(stack==1){
                    uid.push_back(record[i].substr(start,j-start));
                    name.push_back(record[i].substr(j+1,record.size()-j));
                    break;
                }
            }
        }
    }
    for(int i=0;i<act.size();i++){
        if(act[i]=="Change"||act[i]=="Enter"){
            for(int j=0;j<i;j++){
                if(uid[i]==uid[j]){
                    name[j]=name[i];
                }
            }
        }
    }
    for(int i=0;i<act.size();i++){
        if(act[i]=="Change")
            continue;
        if(act[i]=="Enter")
            answer.push_back(name[i]+"님이 들어왔습니다.");
        if(act[i]=="Leave")
            answer.push_back(name[i]+"님이 나갔습니다.");
    }
    return answer;
}


//시간복잡도 생각
int main(){
    vector<string> a;
    a.push_back("Enter uid1234 Muzi");
    a.push_back("Enter uid4567 Prodo");
    a.push_back("Leave uid1234");
    a.push_back("Enter uid1234 Prodo");
    a.push_back("Change uid4567 Ryan");
    vector<string> b=solution(a);
    for(int i=0;i<b.size();i++){
        cout<<b[i]<<" ";
    }
}