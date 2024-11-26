#include <iostream>
#include <stack>
using namespace std;

int LargestNumber(stack<int> st)
{
    if (st.empty())
    {
        return -1;
    }

    int max = st.top();
    st.pop();

    while (!st.empty())
    {
        if (st.top() > max)
        {
            max = st.top();
        }

        st.pop();
    }

    return max;
}

int main()
{
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    st.push(10);
    cout << "Largest Numbers: " << LargestNumber(st) << endl;

    return 0;
}