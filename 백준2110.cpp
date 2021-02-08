//clang++-7 -pthread -std=c++17 -o main 파일이름.cpp
//./main
//이 친구 정말로... 이해하는데 오래걸렸다...
// 그냥 간단히 이해 하자면 공유기 까지의 최대 크기가 X1 ~ Xn 인데,
// 이 공유기 까지의 길이를 이분법으로 푸는 문제이다. (이래서 이분법인가 보오...)
// 처음부터 그냥 이렇게 풀려 했지만, 분류를 이분법으로 해놨길래... 뭔가 싶었던 문제.


#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int N,C;
int countHome[200001];

int binarySearch(int N,int C){
  // 집의 위치 첫번째와 마지막을 둔다.
  int first = 1;
  int Last = countHome[N-1];
  int Max_len=0;
  while (Last>=first){
    int Mid = (first + Last) /2;
    int ans = 1;
    int start=countHome[0];
    for(int i=1;i<N;i++){
      if(countHome[i]-start >= Mid) start=countHome[i],ans++;
    }
    if(ans >= C) first = Mid+1,Max_len=Mid;
    else Last = Mid-1;
  }
  return Max_len;
}

int main(){
  cin >>N >>C;
  for (int i;i<N;i++){
    int temp;
    cin >> temp;
    countHome[i]=temp;
  }
  sort(countHome,countHome+N);
  cout<<binarySearch(N,C);
}
