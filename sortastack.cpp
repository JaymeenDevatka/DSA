#include <iostream>
#include <stack>
using namespace std;

void sort_stack(stack<int>& st)
{
    stack<int> Tst;

    while (!st.empty())
    {
        int temp = st.top();
        st.pop();

        while (!Tst.empty() && Tst.top() > temp)
        {
            st.push(Tst.top());
            Tst.pop();
        }

        Tst.push(temp);
    }

    // Transfer sorted elements back to the original stack
    while (!Tst.empty()) 
    {
        st.push(Tst.top());
        Tst.pop();
    }
}

void printStack(stack<int> stack)
{
    while (!stack.empty())
    {
        cout << stack.top() << " ";
        stack.pop();
    }
    cout << endl;
}

int main()
{
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);

    cout << "Original stack: ";
    printStack(st);

    sort_stack(st);

    cout << "Sorted stack: ";
    printStack(st);

    return 0;
}
