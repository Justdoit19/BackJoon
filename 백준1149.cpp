//clang++-7 -pthread -std=c++17 -o main 파일이름.cpp
//./main

#include <iostream>
#include <algorithm>
using namespace std;
int n;
int houseprice[1001][3];
int visit[1001][3];

int main(){
  cin >> n;
  for (int i=1;i<=n;i++){
    for (int j=0;j<3;j++){
      cin >> houseprice[i][j];
    }
  }
  for(int i=1;i<=n;i++){
    if (i==1){
      visit[i][0]=houseprice[i][0];
      visit[i][1]=houseprice[i][1];
      visit[i][2]=houseprice[i][2];
    }
    visit[i][0]=houseprice[i][0]+min(visit[i-1][1],visit[i-1][2]);
    visit[i][1]=houseprice[i][1]+min(visit[i-1][0],visit[i-1][2]);
    visit[i][2]=houseprice[i][2]+min(visit[i-1][0],visit[i-1][1]);
  }
  cout<< min(min(visit[n][0],visit[n][1]),visit[n][2]);
}