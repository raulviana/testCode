#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the truckTour function below.
 */
int truckTour(vector<vector<int>> petrolpumps) {
    long int liters = 0;
    stack<int, int> pumps; 
    long int res;
   
    for(unsigned int i = 0; i < petrolpumps.size(); i++){
        for(unsigned int j = i; j < petrolpumps.size(); j++){
            unsigned int k = j - 1;
            while(k >= 0){
                pumps.push(make_pair(petrolpumps.at(k).at(0), petrolpumps.at(k).at(1)));
                k--;
            }
            liters += petrolpumps.at(j).at(0) - petrolpumps.at(j).at(1);
            if(liters <= 0) break;
        }
        res = i;
    }
    return res;
}

/*
3
1 5
10 3
3 4
*/
int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    vector<vector<int>> petrolpumps(n);
    for (int petrolpumps_row_itr = 0; petrolpumps_row_itr < n; petrolpumps_row_itr++) {
        petrolpumps[petrolpumps_row_itr].resize(2);

        for (int petrolpumps_column_itr = 0; petrolpumps_column_itr < 2; petrolpumps_column_itr++) {
            cin >> petrolpumps[petrolpumps_row_itr][petrolpumps_column_itr];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    int result = truckTour(petrolpumps);

cout << result << "\n";
    fout << result << "\n";

    fout.close();

    return 0;
}
