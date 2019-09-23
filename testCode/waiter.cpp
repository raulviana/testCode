#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);

bool is_prime(int numb){
    for(int i = 2; i < numb; i++){
        if(numb % i == 0) return false;
    }
    return true;
}

vector<int> print(vector<stack<int>> stacks, vector<int> number){
    vector<int> res;
    for(int i = 0; i < stacks.size(); i++){
        while(! stacks.at(i).empty()){
            res.push_back(stacks.at(i).top());
            stacks.at(i).pop();
        }
    }
    for(int i = 0; i < number.size(); i++){
        res.push_back(number.at(i));
    }
    return res;
}

int next_prime(int num){
    num++;
    while(true){
        if(is_prime(num)) return num;
        num++;
    }
}

vector<int> waiter(vector<int> number, int q) {
    vector<stack<int>> stacks(q);
    stack<int> temp_stack;
    int last_prime = 2;

    for(int i = 0; i < q; i++){
        for (int j = 0; j < number.size(); j++){
            
            if(number.at(j) % last_prime == 0){
                stacks.at(j).push(number.at(j));
            } 
            else{
                temp_stack.push(number.at(j));
            }
        }
        number.clear();
        while(! temp_stack.empty()){
            number.push_back(temp_stack.top());
            temp_stack.pop();
        }
        last_prime = next_prime(last_prime);
    }
    return print(stacks, number);
}

/*
5 1 
3 4 7 6 5
*/

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string nq_temp;
    getline(cin, nq_temp);

    vector<string> nq = split_string(nq_temp);

    int n = stoi(nq[0]);

    int q = stoi(nq[1]);

    string number_temp_temp;
    getline(cin, number_temp_temp);

    vector<string> number_temp = split_string(number_temp_temp);

    vector<int> number(n);

    for (int number_itr = 0; number_itr < n; number_itr++) {
        int number_item = stoi(number_temp[number_itr]);

        number[number_itr] = number_item;
    }

    vector<int> result = waiter(number, q);

    for (int result_itr = 0; result_itr < result.size(); result_itr++) {
    cout << result[result_itr];
        fout << result[result_itr];

        if (result_itr != result.size() - 1) {
            fout << "\n";
        }
    }

    fout << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
