#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer(n);
    for(int i=0;i<arr1.size();i++){
        for(int j=0;j<arr1.size();j++){
            int temp=arr1[i]%2;
            if(temp==1)
                answer[i].insert(answer[i].begin(),'#');
            else
                answer[i].insert(answer[i].begin(),' ');
            arr1[i]=arr1[i]/2;
        }
    }
    for(int i=0;i<arr2.size();i++){
        for(int j=0;j<arr2.size();j++){
            int temp=arr2[i]%2;
            if(temp==1){
                if(answer[i][n-1-j]==' ')
                    answer[i][n-1-j]='#';
            }
            arr2[i]=arr2[i]/2;
        }
    }
    return answer;
}
//[9, 20, 28, 18, 11] [30, 1, 21, 17, 28]
int main(){
    int a=5;
    vector<int> k;
    vector<int> j;
    k.push_back(9);
    k.push_back(20);
    k.push_back(28);
    k.push_back(18);
    k.push_back(11);
    j.push_back(30);
    j.push_back(1);
    j.push_back(21);
    j.push_back(17);
    j.push_back(28);
    vector<string> c=solution(a,k,j);
    for( auto i:c)
        cout<<i<<endl;
}