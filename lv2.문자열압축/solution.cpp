#include <string>
#include <vector>
#include <iostream>

using namespace std;

string put_how_many(string k,int how_many){
    while(how_many>0){
        int temp=how_many%10;
        k.insert(k.begin(),temp+48);
        how_many/=10;
    }
    return k;
}

int solution(string s) {
    int answer = s.size();
    vector<int> k;
    k.push_back(0);
    k.push_back(s.size());
    for(int i=1;i<=s.size()/2;i++){
        string temp=s.substr(0,i);
        string semi_ans;
        int how_many=1;
        for(int j=i;j<s.size();j+=i){
            string temp1=s.substr(j,i);
            if(temp==temp1){
                how_many++;
            }
            else{
                if(how_many==1){
                    semi_ans.append(temp);
                    temp=temp1;
                }
                else{
                    temp=put_how_many(temp,how_many);
                    semi_ans.append(temp);
                    temp=temp1;
                    how_many=1;
                }
            }
            if(j+i==s.size()){
                if(how_many>1)
                    temp=put_how_many(temp,how_many);
                semi_ans.append(temp);
                temp=temp1;
                how_many=1;
            }
            else if(j+i>s.size()){
                semi_ans.append(temp1);
            }
        }
        k.push_back(semi_ans.size());
    }
    for(int i=1;i<k.size();i++)
        if(k[i]<answer)
            answer=k[i];
    return answer;
}

int main(){
    string a="aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
    int s=solution(a);
    cout<<s<<endl;
    return 0;
}

//2,7,17,18,20,21,23,27