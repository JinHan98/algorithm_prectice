#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string dirs) {
    int answer = 0;
    int c_col=55;
    int c_row=55;
    pair<int,int>k=make_pair(0,0);
    vector<int> colum(110,0);
    vector<int> row(110,0);
    for(int i=0;i<dirs.size();i++){
        if(dirs[i]=='U'){
            if(k.second<5){
                k.second++;
                if(row[c_row-1]==0)
                    answer++;
                row[c_row-1]=1;
                c_col-=10;
                c_row--;
            }
            else
                continue;

        }
        else if(dirs[i]=='D'){
            if(k.second>-5){
                k.second--;
                if(row[c_row]==0)
                    answer++;
                row[c_row]=1;
                c_col+=10;
                c_row++;
            }
            else
                continue;

        }
        else if(dirs[i]=='L'){
            if(k.first>-5){
                k.first--;
                if(colum[c_col-1]==0)
                    answer++;
                colum[c_col-1]=1;
                c_row-=10;
                c_col--;
            }
            else
                continue;

        }
        else{
            if(k.first<5){
                k.first++;
                if(colum[c_col]==0)
                    answer++;
                colum[c_col]=1;
                c_row+=10;
                c_col++;
            }
            else
                continue;

        }

    }
    return answer;
}

int main(){
    string a="LULLLLLLU";
    int b=solution(a);
    cout<<b<<endl;
    return 0;
}