#include <bits/stdc++.h>
using namespace std;

int main() {

  int N, x, y;
  

  cin >> N;

  int data[N][N];

  //input the array

  for (int i = 0; i < N; i++){
    for (int j = 0; j < N; j++){
      cin >> data[i][j];
      }
  }

  //find smallest number

  if (data[0][0] < data[0][N-1]){
    x = 0;
  }
  else {
    x = N-1;
  }
  if (data[0][x] < data[N-1][x]){
    y = 0;
  }
  else{
    y = N-1;
  }

  //case if smallest number in top left corner

  if(x == 0 && y == 0){

    for (int i = 0; i < N; i++){
      for (int j = 0; j < N; j++){
        cout << data[i][j] << " ";
        }
      cout << endl;
      }
  }

  //case if smallest number in top right corner

  else if(x > 0 && y == 0){

    for (int j = N-1; j >= 0; j--){
      for (int i = 0; i < N; i++){
        cout << data[i][j] << " ";
      }
      cout << endl;
    }
  }

  //case if smallest number in bottom right corner

  else if(x > 0 && y > 0){
    for (int i = N-1; i >= 0; i--){
      for (int j = N-1; j >= 0; j--){
        cout << data[i][j] << " ";
      }
      cout << endl;
    }
  }

  //case if smallest number in bottom left corner

  else if(x == 0 && y > 0){
      for (int j = 0; j < N; j++){
        for (int i = N-1; i >= 0; i--){
        cout << data[i][j] << " ";
      }
    cout << endl;
    }
  }

}