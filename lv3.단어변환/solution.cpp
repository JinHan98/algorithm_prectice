#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

bool one_only(string a, string b){
    int op=0;
    for(int i=0;i<a.size();i++){
        if(a[i]!=b[i])
            op++;
    }
    if(op==1)
        return true;
    else
        return false;
}


int solution(string begin, string target, vector<string> words) {
    int answer = 1;
    bool con=false;
    vector<bool> check(words.size(),false);
    queue<int> qu;
    vector<int> how_many(words.size(),words.size()+1);
    int op=-1;
    for(int i=0;i<words.size();i++){
        if(words[i]==target)
            con=true;
        if(words[i]==begin)
            op=i;
    }
    if(con==false)
        return 0;
    if(op==-1){
        for(int i=0;i<words.size();i++){
            if(one_only(begin,words[i])){
                how_many[i]=1;
                qu.push(i);
            }
        }
    }
    else{
        qu.push(op);
        how_many[op]=0;
    }
    int now=qu.front();
    while(!qu.empty()){
        if(words[qu.front()]==target)
            break;
        qu.pop();
        for(int i=0;i<words.size();i++){
            if(check[i]==false){
                if(one_only(words[now],words[i])){
                    if(how_many[i]>how_many[now]+1){
                        how_many[i]=how_many[now]+1;
                    }
                    qu.push(i);
                }
            }
        }
        check[now]=true;
        if(words[qu.front()]==target)
            break;
        now=qu.front();
    }
    if(qu.empty())
        answer=0;
    else
        answer=how_many[qu.front()];
    return answer;
}

int main(){//"hit", "cog", ["hot", "dot", "dog", "lot", "log", "cog"]
    vector<string> a={"aaaaaaaaab", "aaaaaaabbb", "aaaaaabbbb","aaaaabbbbb","bbbbbbbbbb"};
    solution("aaaaaaaaaa","bbbbbbbbbb",a);
    queue<int> b;
    b.pop();
}