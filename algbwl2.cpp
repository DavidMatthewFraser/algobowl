#include <iostream> 
#include <vector>
#include <unordered_set>
#include <set>
//#include <bits/stdc++.h>

using namespace std;

unordered_set<int> seen = {1};
unordered_set<int> calculated;
set<pair<int, int>> sequence;

void getSequence(int n) {
    if (n==1)return;
    if(seen.find(n/2) != seen.end()) { // if we can use n/2
        if(calculated.find(n/2) == calculated.end()) { // if we have not already calculated n/2 + n/2
            sequence.insert(pair<int, int>(n / 2, n / 2));
            calculated.insert(n/2);
            seen.insert(2*(n/2));
        }
        if(n % 2) {
            sequence.insert(pair<int, int>(n - 1, 1));
            seen.insert(n);
        }
    } else {
        getSequence(n/2);
        getSequence(n);
    }
}

int main() {
    vector<int> input;
    int num;
    int vals;
    cin >> vals; //gets the first value out of the way. This is the length of the input. Not sure if we want to use it?
    // cout<<vals<<endl;
    while(cin >> num) input.push_back(num);
    for (int i = input.size() - 1; i >= 1; i--)  {
        getSequence(input[i]-input[i-1]);
        sequence.insert(pair<int, int>(input[i-1],input[i]-input[i-1]));
    }
    getSequence(input[0]);
    cout << sequence.size() << endl;
    for(auto it=sequence.begin(); it!=sequence.end(); ++it) {
        cout << it->first << " " << it->second << endl;
    }
    return 0;
}

// Some Ideas for test input

// int input[] = {2, 5};
// int input[] = {2, 5, 10, 15, 16, 24, 25};
// int input[] = {2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181, 6765, 10946, 17711, 28657, 46368, 75025, 121393, 196418, 317811};
// int input[] = {2,3,5,8,13,21,34,55,89,144,233,377,610,987,1597,2584,4181,6765,10946,17711,28657,46368,75025,121393,196418,317811,514229,832040,1346269,2178309,3524578,5702887,9227465,14930352,24157817,39088169,63245986,102334155,165580141,267914296};

// using the max number of inputs and the largest possible numbers:
/*
    vector<int> input;
    int maxInput = 1000000000;
    int maxInputs = 1000;
    for(int i=0; i<maxInputs; i++) input.push_back(maxInput-i);
    
*/

