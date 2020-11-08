
#include <bits/stdc++.h>

using namespace std;

string isBalanced(string s)
{
    stack<char> st;
    char x;

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '{' || s[i] == '[' || s[i] == '(')
        {
            st.push(s[i]);
            continue;
        }

        if (st.empty())
        {
            return "NO";
        }

        if (s[i] == '}')
        {
            if (st.top() != '{')
            {
                return "NO";
            }
            st.pop();
        }
        else if (s[i] == ']')
        {
            if (st.top() != '[')
            {
                return "NO";
            }
            st.pop();
        }
        else if (s[i] == ')')
        {
            if (st.top() != '(')
            {
                return "NO";
            }
            st.pop();
        }
    }
    return st.empty() ? "YES" : "NO";
}

void main()
{
    string input{"{{[[(())]]}}"};
    cout << isBalanced(input);        
}
