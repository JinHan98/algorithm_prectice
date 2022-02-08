#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int time_cal(string a, string b){
    int ant;
    int anm;
    int am=stoi(a.substr(3,2));
    int bm=stoi(b.substr(3,2));
    if(am-bm<0){
        ant=stoi(a.substr(0,2))-stoi(b.substr(0,2))-1;
        anm=stoi(a.substr(3,2))-stoi(b.substr(3,2))+60;
    }
    else{
        ant=stoi(a.substr(0,2))-stoi(b.substr(0,2));
        anm=am-bm;
    }
    return ant*60+anm;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    vector<string> time;
    vector<string> number;
    vector<string> in_out;
    vector<string> real_num;
    istringstream ss(string);
    string stringbuffer;
    int buffer=1;
    int mid;
    bool already=false;
    int index;
    for(int i=0;i<records.size();i++){
        for(int j=0;j<records[i].size();j++){
            if(records[i][j]==' '){
                if(buffer==1){
                    time.push_back(records[i].substr(0,j));
                    mid=j;
                    buffer++;
                }
                else if(buffer==2){
                    number.push_back(records[i].substr(mid+1,4));
                    mid=j;
                    buffer=1;
                }
            }
            if(j==records[i].size()-1)
                in_out.push_back(records[i].substr(mid+1,j+1));
        }
    }
    for(int i=0;i<time.size();i++){
        if(in_out[i]=="IN")
            continue;
        already=false;
        index=-1;
        for(int j=0;j<real_num.size();j++){
            if(number[i]==real_num[j]){
                already=true;
                index=j;
                break;
            }
        }
        if(already==false){
            if(real_num.empty()==true){
                real_num.push_back(number[i]);
                index=0;
            }
            for(int j=0;j<real_num.size();j++){
                if(stoi(real_num[j])>stoi(number[i])){
                    real_num.insert(real_num.begin()+j,number[i]);
                    index=j;
                    break;
                }
            }
            if(index==-1){
                index=real_num.size();
                real_num.push_back(number[i]);
            }            
        }
        for(int j=0;j<i;j++){
            if(number[i]==number[j]){
                if(already==false)
                    answer.insert(answer.begin()+index,time_cal(time[i],time[j]));
                else
                    answer[index]+=time_cal(time[i],time[j]);
                time.erase(time.begin()+i);
                time.erase(time.begin()+j);
                number.erase(number.begin()+i);
                number.erase(number.begin()+j);
                in_out.erase(in_out.begin()+i);
                in_out.erase(in_out.begin()+j);
                i-=2;
                break;
            }
        }
    }
    int temp=-1;
    int op=0;
    for(int i=0;i<time.size();i++){
        if(real_num.size()!=0){
            for(int j=0;j<real_num.size();j++){
                if(number[i]==real_num[j]){
                    temp=j;
                    break;
                }
                else if(number[i]>real_num[j])
                    op=j+1;
            }
        }
        if(temp==-1){
            if(op>0)
                answer.insert(answer.begin()+op,time_cal("23:59",time[i]));
            else    
                answer.insert(answer.begin()+temp+1,time_cal("23:59",time[i]));
        }
        else
            answer[temp]+=time_cal("23:59",time[i]);
        temp=-1;
    }
    for(int i=0;i<answer.size();i++){
        if(fees[0]<answer[i]){
            answer[i]-=fees[0];
            if(answer[i]%fees[2]==0)
                answer[i]/=fees[2];
            else
                answer[i]=(answer[i]/fees[2])+1;
            answer[i]=fees[1]+(answer[i]*fees[3]);
        }
        else{
            answer[i]=fees[1];
        }
    }
    return answer;
}

int main(){
    vector<int> a;
    vector<string> b;
    a.push_back(1);
    a.push_back(10);
    a.push_back(1);
    a.push_back(11);
    /*b.push_back("05:34 5961 IN");
    b.push_back("06:00 0000 IN");
    b.push_back("06:34 0000 OUT");
    b.push_back("07:59 5961 OUT");
    b.push_back("07:59 0148 IN");
    b.push_back("18:59 0000 IN");
    b.push_back("19:09 0148 OUT");
    b.push_back("22:59 5961 IN");*/
    b.push_back("00:00 1234 IN");
    b.push_back("00:02 1234 OUT");
    vector<int> k=solution(a,b);
    for(int i :k)
        cout<<i<<endl;
    return 0;

}