// Created by Anushk Gautam
/*
GitHub Repo : https://github.com/Anushk2001/Optimisation-of-Pattern-Matching
Optimisation of Pattern Matching
*/
#include <bits/stdc++.h>
using namespace std;
bool isMatching(int &N)
{
    if (N == 0)
        return false;
    else
        return true;
}
void print_Indexes(vector<int> &res)
{
    // 0-Base Indexing
    int N = res.size();
    if (!isMatching(N))
    {
        cout << "Pattern Not Found!\n";
    }
    else
    {
        cout << "Pattern Found At Indexes:\n";
        for (int i = 0; i < N; i++)
        {
            cout << res[i] << " ";
        }
        cout << "\n";
    }
}
void string_matching(string &S, string &s)
{
    vector<int> res;
    int n = S.length();
    int m = s.length();
    for (int i = 0; i <= n - m; i++)
    {
        string temp = S.substr(i, m);
        if (temp == s)
        {
            res.push_back(i);
        }
    }
    print_Indexes(res);
}
int main()
{
    string S, s;
    cin >> S;
    cin >> s;
    string_matching(S, s);

    return 0;
}