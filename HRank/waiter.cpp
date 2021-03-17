#include <bits/stdc++.h>
#include <stack>

using namespace std;

vector<string> split_string(string);

bool is_prime(int last){
    for(int i  = 2; i < last; i++){
        if((last % i) == 0) return true;
    }
    return true;

}

int get_prime(vector<int> primes, int index){
    if(primes.size() >= index) return primes.at(index);
    int dif = index - primes.size();
    int last_prime = primes.at(primes.size() - 1);
    while(dif <= index){
        last_prime++; 
        while (! is_prime(last_prime)){
            last_prime++;
        } 
        dif++;
    }

vector<int> waiter(vector<int> number, int q) {
    <stack<int> a;
    vector<stack<int>> b;

    vector<int> primes(number.size());

    for(int i = 0; i < number.size(); i++){
        int ith_prime = get_prime(primes, i);
        primes.push_back(ith_prime);
        if
    }


}

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