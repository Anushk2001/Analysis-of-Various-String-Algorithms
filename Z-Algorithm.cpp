// Created by Anushk Gautam
/*
GitHub Repo : https://github.com/Anushk2001/Optimisation-of-Pattern-Matching
Optimisation of Pattern Matching
*/
#include <bits/stdc++.h>
using namespace std;
void compute_Z_Array(string str, int Z[])
{
    int n = str.length();
    int L, R, k;

    L = R = 0;
    for (int i = 1; i < n; ++i)
    {
        if (i > R)
        {
            L = R = i;
            while (R < n && str[R - L] == str[R])
                R++;
            Z[i] = R - L;
            R--;
        }
        else
        {
            k = i - L;

            if (Z[k] < R - i + 1)
                Z[i] = Z[k];

            else
            {
                L = i;
                while (R < n && str[R - L] == str[R])
                    R++;
                Z[i] = R - L;
                R--;
            }
        }
    }
}

void Z_Algorithm(string &Text, string &Pattern)
{

    string concat = Pattern + "$" + Text;
    int l = concat.length();

    // Constructing Z array
    int Z[l];
    compute_Z_Array(concat, Z);

    for (int i = 0; i < l; ++i)
    {
        if (Z[i] == Pattern.length())
            cout << "Pattern found at index : " << i - Pattern.length() - 1 << endl;
    }
}

int main()
{
    string Text;
    string Pattern;
    cin >> Text;
    cin >> Pattern;
    Z_Algorithm(Text, Pattern);
    return 0;
}