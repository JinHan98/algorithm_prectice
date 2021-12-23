#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer(arr1.size());
    int temp=0;
    if(arr1[0].size()!=arr2.size())
        return solution(arr2,arr1);
    for(int a=0;a<arr1.size();a++){
        for(int b=0;b<arr2[0].size();b++){
            for(int i=0;i<arr2.size();i++){
                temp=temp+arr1[a][i]*arr2[i][b];
            }
            answer[a].push_back(temp);
            temp=0;
        }
    }
    return answer;
}

int main(){
    vector<vector<int>> a(2);
    vector<vector<int>> b(3);
    a[0].push_back(1);
    a[0].push_back(2);
    a[0].push_back(3);
    a[1].push_back(4);
    a[1].push_back(5);
    a[1].push_back(6);
    b[0].push_back(1);
    b[0].push_back(4);
    b[1].push_back(2);
    b[1].push_back(5);
    b[2].push_back(3);
    b[2].push_back(6);
    vector<vector<int>> c=solution(a,b);
}