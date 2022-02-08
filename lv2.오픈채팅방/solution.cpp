#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    vector<string> uid;
    vector<string> name;
    for(int i=0;i<record.size();i++){
        if(record[i][0]=='E'){
            answer.push_back("님이 들어왔습니다.");
            for(int j=0;j<uid.size();j++){
                if(record[i].substr(9,4)==uid[j])
                    name[j]=record[i].substr(14);
            }
            name.push_back(record[i].substr(14));
        }
        else if(record[i][0]=='L'){
            answer.push_back("님이 나갔습니다.");
            for(int j=0;j<uid.size();j++){
                if(record[i].substr(9,4)==uid[j]){
                    name.push_back(name[j]);
                    break;
                }
            }
        }
        else{
            for(int j=0;j<uid.size();j++){
                if(record[i].substr(10,4)==uid[j]){
                    name[j]=record[i].substr(15);
                }
            }
            continue;
        }
        uid.push_back(record[i].substr(9,4));
    }
    for(int i=0;i<name.size();i++){
        answer[i]=name[i]+answer[i];
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