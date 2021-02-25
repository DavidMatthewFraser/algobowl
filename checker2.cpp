#include <iostream>
#include <unordered_set>

using namespace std;

unordered_set<int> seen;

// expected 0(1) worst case O(n)
bool is_seen(int x) {
    if(seen.find(x) == seen.end()) return false;
    return true;
}

//O(1)
void add_seen(int x) {
    seen.insert(x);
}

int main() {
    seen.insert(1);
    int num_operations, x, y;
    cin >> num_operations;
    // are they using valid operations?
    for(int i=0; i<num_operations*2; i++) { // expected n, worst case n^2
        cin >> x >> y;
        if(is_seen(x) && is_seen(y)) {
            add_seen(x+y);
        } else {
            cout << "invalid" << endl;
            return -1;
        }
    }
    // did they hit all the values?
    int target, num_targets;
    vector<int> targets;
    cin >> num_operations;
    for(int i=0; i<num_targets; i++) { // n
        cin >> target;
        targets.push_back(target);
    }
    for(int i : targets) { // expected n, worst case n^2
        if(!is_seen(i)) {
            cout << "invalid" << endl;
            return -1;
        } 
    }
    cout << "valid" << endl;
    return 0;
}