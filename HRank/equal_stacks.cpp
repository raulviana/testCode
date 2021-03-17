#include <bits/stdc++.h>

using namespace std;



// Complete the isBalanced function below.
string isBalanced(string s) {
    stack<char> pile;
    char simbol;
    for (int i = 0; i < s.size(); i++){
        simbol = s[i];
        if(simbol == '{' || simbol == '[' || simbol == '('){
            pile.push(simbol);
        }
        else{
                if((simbol == '}' && pile.top() == '{') ||
                   (simbol == ']' && pile.top() == '[') ||
                   (simbol == ')' && pile.top() == '(')){
                       pile.pop();
                   }
                else return "NO";
            }
        }
    if(pile.empty()) return "YES";
    else return "NO4";
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string s;
        getline(cin, s);

        string result = isBalanced(s);
cout << result;
        fout << result << "\n";
    }

    fout.close();

    return 0;
}
