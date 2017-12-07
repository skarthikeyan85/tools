#include <string>
#include <iostream>
#include <stack>
#include <unordered_map>

using namespace::std;

inline const char * const BoolToString(bool b)
{
      return b ? "true" : "false";
}

bool doesSyntaxMatch(const string &str)
{
    stack<char> s;
    const unordered_map <char,char> m = {{'[',']'}, {'(',')'}};

    for (int i = 0; i < str.size(); i++) {
        if (m.count(str[i])) {
            s.push(str[i]);
        } else {
            if (s.empty() || str[i] != m.at(s.top()))
                return false;
            s.pop();
        }
    }

    return s.empty();
}

int main()
{
    cout << BoolToString(doesSyntaxMatch("[(]]")) << endl;
    cout << BoolToString(doesSyntaxMatch("[()]")) << endl;
    cout << BoolToString(doesSyntaxMatch("[)")) << endl;
    return 0;
}
