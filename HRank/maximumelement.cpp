#include <algorithm>
#include <sstream>
#include <string>
#include <stack>
#include <iostream>

using namespace std;

void process_stack(stack<long int> &pile,long int code, long int value,
                    stack<long int> &max_pile, long int max){
    switch(code){
        case 1:
            pile.push(value);
            if(! max_pile.empty()){
                if(max > max_pile.top()) max_pile.push(max);
            }
            else max_pile.push(max);
            break;
        case 2:
            if(pile.top() == max) max_pile.pop();
            pile.pop();
            break;
        case 3:
            cout << max_pile.top();
    }
}

int main() {

    long int n, query, query_value, temp;
    long int max = 0;
    string line;
    stack<long int> pile;
    stack<long int> max_pile;
    cin >> n;
    for(int i = 0; i <= n; i++){
        getline(cin, line);
        stringstream ss(line);
        ss >> query;
        if(query == 1) ss >> query_value;
        max = query_value;
        process_stack(pile, query, query_value, max_pile, max);
        ss.clear();
        line.clear();
    }
    return 0;
}