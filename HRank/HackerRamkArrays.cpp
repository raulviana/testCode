

#include <vector>
#include <iostream>
#include <cmath>
#include <limits> 

using namespace std;



int main(){

    int max = numeric_limits<int>::min();
    cout << max << endl;
    int temp = 0;


  vector<vector<int>> array = {
      {-1, -1,  0, -9, -2, -2},
      {-2, -1, -6, -8, -2, -5},
      {-1, -1, -1, -2, -3, -4},
      {-1, -9, -2, -4, -4, -5},
      {-7, -3, -3, -2, -9, -9},
      {-1, -3, -1, -2, -4, -5}
  };

for (int i = 0; i < array.size() - 2; i++){
    for (int j = 0; j < array.size() - 2; j++){
        cout << array[i][j] << " ";
          temp += array[i][j+1];
            temp += array[i][j];
            temp += array[i][j+2];
            temp += array[i+1][j+1];
            temp += array[i+2][j];
            temp += array[i+2][j+1];
            temp += array[i+2][j+2];
            if (max <= temp) {
              max = temp;
             
            }
             temp = 0;
    }
    cout << endl;
}

cout << endl << endl << "\t" << max;
    return 0;
}
