#include <bits/stdc++.h>
using namespace std;

struct CoinAlignment{

  int step;
  vector<vector<int>> slots;

  CoinAlignment(int step){
    this->step = step;
  }

  string MakeSlotString(){
    
  string strResult = "";
  
  for(int i = 0; i < slots.size(); i++){

    if(slots[i].size() == 0)
      strResult += "0;";
      
    else{
      for(int j = 0; j < slots[i].size(); j++)

        strResult += to_string(slots[i][j]);

        strResult += ";";
        }
      }
    
    return strResult;
    }

    bool isSolution(){
      
      for(int i = 0; i < slots.size(); i++){

        if(slots[i].size() != 1 || slots[i][0] != i+1){

          return false;
          }
        }

      return true;
    }
};

int main(){
  
int Total;
cin >> Total;
int coin;

while(Total > 0){
  
  CoinAlignment alignment(0);
  
  for(int i = 0; i < Total; i++){

    cin >> coin;
    vector<int> slot(1, coin);
    alignment.slots.push_back(slot);
    
  }

  queue<CoinAlignment> my_queue;
  unordered_set<string> MySlotStrings;

  my_queue.push(alignment);
  MySlotStrings.insert(alignment.MakeSlotString());

  bool solutionFound = false;
  int minSteps;
  
  while(!my_queue.empty()){

    CoinAlignment align = my_queue.front();

    if(align.isSolution()){

      solutionFound = true;
      minSteps = align.step;
      break;
    }
    my_queue.pop();

    for(int i = 0; i < Total - 1; i++){

      //check if we can move a coin from slot i to slot i+1
      if(!align.slots[i].empty() && (align.slots[i+1].empty() || align.slots[i].back() < align.slots[i+1].back()))
      {
        CoinAlignment newAlign(align.step+1);
        newAlign.slots = align.slots;
        newAlign.slots[i+1].push_back(newAlign.slots[i].back());//move the top item fom slot i to slot i+1
        newAlign.slots[i].pop_back();//delete the top item from slot i
        string strSlotString = newAlign.MakeSlotString();
        if(MySlotStrings.find(strSlotString) == MySlotStrings.end()){
          MySlotStrings.insert(strSlotString);
          my_queue.push(newAlign);
        }
      }
      
      //check if we can move a coin from slot i+1 to slot i
      if(!align.slots[i+1].empty() && (align.slots[i].empty() || align.slots[i+1].back() < align.slots[i].back()))
      {//1) slot i+1 is not empty; and 2) slot i is empty or the top item in slot i+1 is smaller than the top item in slot i
          CoinAlignment newAlign(align.step+1);
          newAlign.slots = align.slots;
          newAlign.slots[i].push_back(newAlign.slots[i+1].back());//move the top item from slot i+1 to slot i
          newAlign.slots[i+1].pop_back();//delete the top item from slot i+1
          string strSlotString = newAlign.MakeSlotString();
          if(MySlotStrings.find(strSlotString) == MySlotStrings.end())
          {
              MySlotStrings.insert(strSlotString);
              my_queue.push(newAlign);
          }
      }


    }
  }

  if(solutionFound == true)
    cout << minSteps << endl;
  else
    cout << "IMPOSSIBLE" << endl;

  cin >> Total;

  }
  return 0;
  }