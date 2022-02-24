#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int fee_cal(vector<int> f,string start,string end){
    int time=0;
    int upper=0;
    time=(stoi(end.substr(0,2))-stoi(start.substr(0,2)))*60+((end[3]-start[3])*10+(end[4]-start[4]));
    return time;
    
}
int cal(vector<int> f,int time){
    int upper;
    if(time<=f[0])
        return f[1];
    else{
        time-=f[0];
        if(time%f[2]==0)
            upper=time/f[2];
        else
            upper=(time/f[2])+1;
        return f[1]+upper*f[3];
    }
}

bool compare(pair<string,int> a,pair<string,int> b){
    return a.first<b.first;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    vector<string> time;
    vector<string> number;
    vector<pair<string,int> > fee;
    for(int i=0;i<records.size();i++){
        if(records[i].substr(11)=="IN"){
            time.push_back(records[i].substr(0,5));
            number.push_back(records[i].substr(6,4));
        }
        if(records[i].substr(11)=="OUT"){
            for(int j=0;j<time.size();j++){
                if(number[j]==records[i].substr(6,4)){
                    pair<string,int> k;
                    k.first=number[j];
                    k.second=fee_cal(fees,time[j],records[i].substr(0,5));
                    fee.push_back(k);
                    time.erase(time.begin()+j);
                    number.erase(number.begin()+j);
                    break;
                }
            }
        }
    }
    for(int i=0;i<time.size();i++){
        pair<string,int> k;
        k.first=number[i];
        k.second=fee_cal(fees,time[i],"23:59");
        fee.push_back(k);
    }
    sort(fee.begin(),fee.end(),compare);
    int temp=0;
    if(fee.size()>1){
        for(int i=0;i<fee.size();i++){
            if(i!=fee.size()-1){
                if(fee[i].first==fee[i+1].first)
                    temp+=fee[i].second;
                else{
                    temp+=fee[i].second;
                    answer.push_back(temp);
                    temp=0;
                }
            }
            else{
                if(fee[i-1].first!=fee[i].first)
                    answer.push_back(fee[i].second);
                else
                    answer.push_back(temp+fee[i].second);
            
            }
        }
    }
    else{
        answer.push_back(fee[0].second);
    }
    for(int i=0;i<answer.size();i++)
        answer[i]=cal(fees,answer[i]);
    return answer;
}

int main(){
    vector<int> a={1, 10, 1, 11};
    vector<string> b={"00:00 1234 IN","00:00 4567 IN"};
    solution(a,b);
}