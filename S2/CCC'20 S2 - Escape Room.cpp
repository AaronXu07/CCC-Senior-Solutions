#include <bits/stdc++.h> 

using namespace std; 

struct cell {

  int x; 
  int y; 
    
  cell(int x, int y) {
    
    this->x = x; 
    
    this->y = y; 
    
    }
}; 

int main() {
  
    int row, col; 
  
    cin >> row >> col; 

    vector<vector<int>> grid(row); 

    cell point(0, 0); 

    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) {
          
            int num; 
          
            cin >> num; 
          
            grid[i].push_back(num);  
        }
    }
    
    vector<vector<bool>> visited(row);  

    for(int i = 0; i < row; i++) {
        for(int j = 0; j < col; j++) { 
          
            visited[i].push_back(false);  
          
        }
    }   
     
    
    queue<cell> q;
  
    visited[point.x][point.y] = true;
    q.push(point);
    
    while(!q.empty()){
            
    cell point = q.front();
      
    int x = point.x; 
    int y = point.y;  
      
    if((x == row - 1 && y == col - 1) || (x == col - 1 && y == row - 1)) {
              
      cout << "yes"; 
              
      return 0; 
    }

    q.pop();

    int num = grid[x][y]; 
            
    for(int i = 1; i < num + 1; i++) {
              
      if(num % i == 0 && i <= row && num / i <= col) {
                  
        if(!visited[i - 1][(num / i) - 1]) {
                      
          visited[i - 1][(num / i) - 1] = true;
                      
          cell factors(i - 1, (num / i) - 1); 
                    
          q.push(factors);  
        }
      } 
      
      else if(num % i == 0 && i <= col && num / i <= row) {
        
        if(!visited[(num / i) - 1][i - 1]) {
          
          visited[(num / i) - 1][i - 1] = true;
          
          cell factors((num / i) - 1, i - 1); 
          
          q.push(factors); 
          }
                    
      }
    } 
  }
  
    cout << "no"; 
  
    return 0; 

}