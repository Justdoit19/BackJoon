//clang++-7 -pthread -std=c++17 -o main 파일이름.cpp
//./main
#include <iostream>
#include <queue>
#include <algorithm>
#include <cmath>
#include <utility>
using namespace std;
typedef pair<int,int> par;

int main(){
  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
  int n;
  cin >> n;

  //기억하자... par 로 pair 를 만들어 priority_queue 를 만들어준다.
  priority_queue <par, vector<par>, greater<par> > minimumHeap1;
  while(n--){
    int temp;
    cin >> temp;
    if(!temp) {
      if (!minimumHeap1.empty()) {
        cout << minimumHeap1.top().second<<"\n";
        minimumHeap1.pop();
      }
      else {
        cout << "0\n";
      }
    }
    else {
      minimumHeap1.push({abs(temp),temp});
    }
  }
  return 0;
}