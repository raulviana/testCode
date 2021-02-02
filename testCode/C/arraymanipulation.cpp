#include <iostream>
#include <vector>

using namespace std;

long arrayManipulation(int n, vector<vector<int>> queries) {
    vector<int> res(n, 0);
    long max = 0;
    int index1, index2;
    long num;

    for (int i = 0; i < queries.size(); i++){
        index1 = queries.at(i).at(0);
        index2 = queries.at(i).at(1);
        index1--;
        index2--;
        num = queries.at(i).at(2);
        do{
            res.at(index1) += num;
            index1++;
        }while(index1 <= index2);

    }

    for (int i = 1; i < res.size(); i++){ 
        if(res.at(i) > max) max = res.at(i);
    }
    return max;
}

int main(){
    long n = 10;
    vector<vector<int>> query = {
                                {2, 6, 8},
                                {3, 5, 7},
                                {1, 8, 1},
                                {5, 9, 15}};

long max = arrayManipulation(n, query);

cout << max;

    return 0;
}