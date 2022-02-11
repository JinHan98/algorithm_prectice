#include <string>
#include <vector>

using namespace std;

vector<int> solution(string msg) {
    vector<int> answer;
    vector<string> new_dic;
    int temp=-1;
    for(int i=0;i<msg.size();i++){
        for(int j=0;j<new_dic.size();j++){ //사전에 같은게 있는지 확인
            if(new_dic[j]==msg.substr(i,new_dic[j].size()))
                temp=j;
        }
        if(temp==-1){
            answer.push_back(msg[i]-64);
            new_dic.push_back(msg.substr(i,2));
        }
        else{
            answer.push_back(27+temp);
            new_dic.push_back(msg.substr(i,new_dic[temp].size()+1));
            i+=(new_dic[temp].size()-1);
        }
        temp=-1;
    }
    return answer;
}