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
int main()
{
    string S;
    cin >> S;
    compute_LPS(S);
    output_LPS(S);
    return 0;
}