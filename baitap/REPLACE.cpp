#include <bits/stdc++.h>
using namespace std;

int DP[100][100];

// Function to print the steps
void printChanges(string s1, string s2,
                  int dp[][100])
{
    int i = s1.length();
    int j = s2.length();

    // check till the end
    while (i and j)
    {
        // if characters are same
        if (s1[i - 1] == s2[j - 1])
        {
            i--;
            j--;
        }

        // Replace
        else if (dp[i][j] == dp[i - 1][j - 1] + 1)
        {
            cout << "change " << s1[i - 1]
                 << " to " << s2[j - 1] << endl;
            i--;
            j--;
        }

        // Delete the character
        else if (dp[i][j] == dp[i - 1][j] + 1)
        {
            cout << "Delete " << s1[i - 1] << endl;
            i--;
        }

        // Add the character
        else if (dp[i][j] == dp[i][j - 1] + 1)
        {
            cout << "Add " << s2[j - 1] << endl;
            j--;
        }
    }
}

// Function to compute the DP matrix
void editDP(string s1, string s2)
{
    int l1 = s1.length();
    int l2 = s2.length();
    DP[l1 + 1][l2 + 1];

    // initilize by the maximum edits possible
    for (int i = 0; i <= l1; i++)
        DP[i][0] = i;
    for (int j = 0; j <= l2; j++)
        DP[0][j] = j;

    // Compute the DP matrix
    for (int i = 1; i <= l1; i++)
    {
        for (int j = 1; j <= l2; j++)
        {
            // if the characters are same
            // no changes required
            if (s1[i - 1] == s2[j - 1])
                DP[i][j] = DP[i - 1][j - 1];
            else
                // minimu of three operations possible
                DP[i][j] = min(min(DP[i - 1][j - 1],
                                   DP[i - 1][j]),
                               DP[i][j - 1]) +
                           1;
        }
    }

    // print the steps
    printChanges(s1, s2, DP);
}
// Driver Code
int main()
{
    string s1 = "drpepper";
    string s2 = "cocacola";

    // calculate the DP matrix
    editDP(s1, s2);

    return 0;
}