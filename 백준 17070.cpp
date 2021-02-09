//clang++-7 -pthread -std=c++17 -o main 파일이름.cpp
//./main
#include <iostream>
using namespace std;

#define max 16+1
int n;
// dx 와 dy를 통하여 가로, 세로, 대각선 움직이는 방향을 정하여 주었음.
int dx[3]={0,1,1};
int dy[3]={1,0,1};
int space[max][max];
int ans;

bool isthereroot(int a,int b,int dir){
  //가로로 갈 수 있는지 판단
  if (dir == 0){
    bool temp;
    if (space[a+1][b]==0) temp=1;
    else temp=0;
    if(a+1<=n&&temp) return true;
  }
  //세로로 갈 수 있는지 판단
  else if (dir == 1){
    bool temp;
    if (space[a][b+1]==0) temp=1;
    else temp=0;
    if(b+1<=n&&temp) return true;
  }
  // 대각선으로 갈 수 있는지 판단
  else if (dir==2) {
    bool temp1,temp2,temp3;
    if (space[a+1][b]==0) temp1=1;
    else temp1=0;
    if (space[a][b+1]==0) temp2=1;
    else temp2=0;
    if (space[a+1][b+1]==0) temp3=1;
    else temp3=0;
    if(b+1<=n&&a+1<=n&&temp1&&temp2&&temp3) return true;
  }
  return false;
}

void findroot(int a,int b,int dir){
  if (a==n&&b==n) ans+=1;
  else {
    //가로로 움직였을 시, 가능한 경로 = 가로 & 대각선
    if (dir ==0) {
      if (isthereroot(a,b,0)) findroot(a+1,b,0);
      if (isthereroot(a,b,2)) findroot(a+1,b+1,2);
    }
    //세로로 움직였을 시, 가능한 경로 = 세로 & 대각선
    else if (dir == 1){
      if (isthereroot(a,b,1)) findroot(a,b+1,1);
      if (isthereroot(a,b,2)) findroot(a+1,b+1,2);
    }
    else if (dir ==2){
      if (isthereroot(a,b,0)) findroot(a+1,b,0);
      if (isthereroot(a,b,1)) findroot(a,b+1,1);
      if (isthereroot(a,b,2)) findroot(a+1,b+1,2);      
    }
  }  
}

void solution(){
  cin >> n;
  for (int i=1;i<=n;i++){
    for (int j=1;j<=n;j++){
      cin >> space[j][i];
    }
  }
  findroot(2,1,0);
  cout<<ans;
}
int main() {
  solution();
}
