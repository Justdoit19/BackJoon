#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
 
int main() {
    cin.sync_with_stdio(false);
    cin.tie(NULL);
 
    int N,C;
    cin >> N >> C;
    vector<int> yousep(N);
    for (int i = 0 ; i<N;i++){
      yousep[i]=i+1;
    }
    int iter=C;
    int ans=0;
    while (ans!=N){
      for(int i=0;i<C-1;++i){
        yousep.push_back(yousep[0]);
        yousep.erase(yousep.begin());
      }
      cout << yousep[0] << endl;
      yousep.erase(yousep.begin());
      ans+=1;
    }
}