#include <iostream>
#include <vector>
#include <unordered_set>
#include <fstream>
#include <chrono>

using namespace std;
using namespace chrono;

unordered_set<int> seen = {1};
unordered_set<int> calculated;
vector<pair<int, int>> sequence;

void getSequence(int n){
    if(seen.find(n/2) != seen.end()) { // if we can use n/2
        if(calculated.find(n/2) == calculated.end()) { // if we have not already calculated n/2 + n/2
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
    // File I/O
    ifstream infile("input.txt");
    int num;
    vector<int> input;
    while(infile >> num) {
        input.push_back(num);
    }
    // int input[] = {2, 5};
    // int input[] = {2, 5, 10, 15, 16, 24, 25};
    // int input[] = {2, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181, 6765, 10946, 17711, 28657, 46368, 75025, 121393, 196418, 317811};
    // int input[] = {2,3,5,8,13,21,34,55,89,144,233,377,610,987,1597,2584,4181,6765,10946,17711,28657,46368,75025,121393,196418,317811,514229,832040,1346269,2178309,3524578,5702887,9227465,14930352,24157817,39088169,63245986,102334155,165580141,267914296};
    auto start = high_resolution_clock::now();
    /*********************************************/
        for(int i : input)
        getSequence(i);
    cout << sequence.size() << endl;
    for(pair<int, int> p : sequence) 
        cout << p.first << " " << p.second << endl;
    /*********************************************/
    auto stop = high_resolution_clock::now(); 
    cout << duration_cast<microseconds>(stop - start).count() <<  " microseconds" << endl;
    infile.close();
    return 0;
}
