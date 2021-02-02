#include <iostream>

using namespace std;

int main(){

    int numb = 12365475;
    bool isprime = true;

    for(int i = 2; i < numb; i++){
        if(numb % i == 0){
            cout << "Not a prime number" << endl;
            isprime = false;
        }
    }
    
    if(isprime) cout << numb << " is a prime number"  << endl;

    return 0;
}   