#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> solution(int rows, int columns, vector<vector<int> > queries) {
    vector<int> answer;
    vector <vector<int> > matrix(rows);
    vector <int> temp_heap;
    int temp=1;
    for(int i=0;i<rows;i++){
        for(int j=0;j<columns;j++){
            matrix[i].push_back(temp);
            temp++;
        }
    }
    for(int i=0 ;i<queries.size();i++){//queries의 행
        int role=matrix[queries[i][0]-1][queries[i][1]-1];
        for(int j=0;j<queries[i][3]-queries[i][1];j++){
            temp_heap.push_back(matrix[queries[i][0]-1][queries[i][1]+j]);
            matrix[queries[i][0]-1][queries[i][1]+j]=role;//matrix[queries[i][0]-1][queries[i][1]+j-1];
            role=temp_heap.back();
        }
        for(int j=0;j<queries[i][2]-queries[i][0];j++){
            temp_heap.push_back(matrix[queries[i][0]+j][queries[i][3]-1]);
            matrix[queries[i][0]+j][queries[i][3]-1]=role;//matrix[queries[i][0]+j-1][queries[i][3]-1];
            role=temp_heap.back();
        }
        for(int j=queries[i][3]-queries[i][1];j>0;j--){
            temp_heap.push_back(matrix[queries[i][2]-1][queries[i][1]+j-2]);
            matrix[queries[i][2]-1][queries[i][1]+j-2]=role;//matrix[queries[i][2]-1][queries[i][3]-j-1];
            role=temp_heap.back();
        }
        for(int j=queries[i][2]-queries[i][0];j>0;j--){
            temp_heap.push_back(matrix[queries[i][0]+j-2][queries[i][1]-1]);
            matrix[queries[i][0]+j-2][queries[i][1]-1]=role;//matrix[queries[i][2]-j-1][queries[i][1]-1];
            role=temp_heap.back();
        }
        make_heap(temp_heap.begin(),temp_heap.end(),greater<int>());
        answer.push_back(temp_heap[0]);
        temp_heap.clear();
    }
    return answer;
}

int main(){
    int a=3;
    int b=3;
    vector<vector<int> > c(4);//[[1,1,2,2],[1,2,2,3],[2,1,3,2],[2,2,3,3]]
    c[0].push_back(1);
    c[0].push_back(1);
    c[0].push_back(2);
    c[0].push_back(2);
    vector<int> d;
    c[1].push_back(1);
    c[1].push_back(2);
    c[1].push_back(2);
    c[1].push_back(3);
    c[2].push_back(2);
    c[2].push_back(1);
    c[2].push_back(3);
    c[2].push_back(2);
    c[3].push_back(2);
    c[3].push_back(2);
    c[3].push_back(3);
    c[3].push_back(3);
    d=solution(a,b,c);
    for(int i=0;i<d.size();i++)
        cout<<d[i]<<endl;

}