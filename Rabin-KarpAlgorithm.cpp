// Created by Anushk Gautam
/*
GitHub Repo : https://github.com/Anushk2001/Optimisation-of-Pattern-Matching
Optimisation of Pattern Matching
*/
#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
void Robin_Karp(string &Text, string &Pattern)
{
    int Pat_Len = Pattern.length();
    int Text_Len = Text.length();
    vector<long long int> Hash(Text_Len + 1);
    vector<long long int> Power(Text_Len + 1);
    Power[0] = 1;

    for (int i = 1; i <= Text_Len; i++)
    {
        Power[i] = (Power[i - 1] * 2LL) % MOD;
    }
    for (int i = 1; i <= Text_Len; i++)
    {
        Hash[i] = Hash[i - 1] + ((Text[i - 1] - 'a' + 1) * Power[i - 1]) % MOD;
    }
    long long int Hash_Pattern = 0;
    for (int i = 0; i < Pat_Len; i++)
    {
        Hash_Pattern = (Hash_Pattern + (Pattern[i] - 'a' + 1) * Power[i]) % MOD;
    }

    for (int i = 0; i <= Text_Len - Pat_Len + 1; i++)
    {
        long long int temp_Hash = (Hash[i + Pat_Len] - Hash[i] + MOD) % MOD;

        if ((Hash_Pattern * Power[i]) % MOD == temp_Hash)
        {
            cout << "Text Found At Index : " << i << endl;
        }
    }
    return;
}
int main()
{
    string Pattern;
    string Text;
    cin >> Pattern >> Text;
    Robin_Karp(Pattern, Text);
    return 0;
}
