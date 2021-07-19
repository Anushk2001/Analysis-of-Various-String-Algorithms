// Created by Anushk Gautam
/*
GitHub Repo : https://github.com/Anushk2001/Optimisation-of-Pattern-Matching
Optimisation of Pattern Matching
*/
#include <bits/stdc++.h>
using namespace std;
vector<int> LPS;
void compute_LPS(string &S)
{
    LPS.resize(S.length() + 1);
    int len = 0;
    LPS[0] = 0;
    int L = S.length();
    int i = 1;
    while (i < L)
    {
        if (S[i] == S[len])
        {
            len++;
            LPS[i] = len;
            i++;
        }
        else
        {
            if (len == 0)
            {
                LPS[i] = 0;
                i++;
            }
            else
            {
                len = LPS[len - 1];
            }
        }
    }
}
void output_LPS(string &S)
{
    int L = S.length();
    for (int i = 0; i < L; i++)
    {
        cout << LPS[i] << " ";
    }
}
vector<int> pattern_search(string &S, string &s)
{
    vector<int> res;
    int L = S.length();
    int l = s.length();
    int i = 0, j = 0;
    while (i < L)
    {
        if (S[i] == s[j])
        {
            i++, j++;
        }
        if (j == l)
        {
            res.push_back(i);
            j = LPS[j - 1];
        }
        else if (i < L && S[i] != s[j])
        {
            if (j != 0)
            {
                j = LPS[j - 1];
            }
            else
                i++;
        }
    }
    return res;
}
void output_Result(vector<int> &result)
{
    if (result.size() == 0)
    {
        cout << "Pattern not found\n";
        return;
    }
    cout << "Pattern found at index:\n";
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    cout << "\n";
    return;
}
int main()
{
    string S, s;
    cin >> S;
    cin >> s;
    compute_LPS(S);
    vector<int> result = pattern_search(S, s);
    output_Result(result);
    return 0;
}