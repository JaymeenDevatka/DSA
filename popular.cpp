#include <iostream>
#include <vector>
using namespace std;

int SpecialInteger(vector<int>& array) {
    int n = array.size();
    int threshold = n / 4;

    for (int i = 0; i < n; i++) {
        if (array[i] == array[i + threshold]) {
            return array[i];
        }
    }

    return -1; // No special integer found (though there should be one as per problem statement)
}

int main() {
    int n;
    cin >> n;
    vector<int> array(n);
    
    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }

    int result = SpecialInteger(array);
    
    cout << "Special Integer: " << result << endl;

    return 0;
}
