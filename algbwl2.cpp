#include <iostream> 
#include <vector>
#include <unordered_set>
// #include <set>
//#include <bits/stdc++.h>

using namespace std;

unordered_set<int> seen = {1};
unordered_set<int> calculated;
// *3/2-edit* this can't be a set, we need the sequence ordered by when each addition is performed
vector<pair<int, int>> sequence;

void getSequence(int n) {
    if (n==1)return;
    if(seen.find(n/2) != seen.end()) {
        if(calculated.find(n/2) == calculated.end()) {
            sequence.push_back(pair<int, int>(n / 2, n / 2));
            calculated.insert(n/2);
            seen.insert(2*(n/2));
        }
        if(n % 2) {
            sequence.push_back(pair<int, int>(n - 1, 1));
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
    cin >> vals;
    while(cin >> num) input.push_back(num);
    /**********
     * Note: "The addition operations may appear in any order in the output, 
     * as long as any given operation appears after the two operations that 
     * compute its operands." - algobowl_s21.pdf
    **********/
    // *3/2-edit* we need to start from low to high so we actually compute i-1 before i
    getSequence(input[0]);
    for (int i = 1; i <= input.size()-1; i++)  {
        int a = input[i] - input[i-1];
        getSequence(a);
        sequence.push_back(pair<int, int>(input[i-1],input[i]-input[i-1]));
        // *3/2-edit* make sure to insert the value we just computed to seen
        seen.insert(input[i]);
    }
    cout << sequence.size() << endl;
    for(auto it=sequence.begin(); it!=sequence.end(); ++it) {
        cout << it->first << " " << it->second << endl;
    }
    return 0;
}
