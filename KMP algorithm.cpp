#include <bits/stdc++.h>
#include <stdio.h>
#define fin freopen("input", "r", stdin)

using namespace std;

vector<int> constructTempArray(string pattern) {
    vector<int> lps(pattern.length());
    int index = 0;
    for (int i = 1; i < (int) pattern.length(); ) {
        if (pattern[i] == pattern[index]) lps[i] = index + 1, ++index, ++i;
        else {

            if (index != 0) index = lps[index - 1];
            else lps[i] = index, ++i;
        }
    }
    cout<<"LPS array : ";
    for(auto u : lps) cout<<u<<" ";
    cout<<endl;
    return lps;
}

void KMPMultipleTimes (string text, string pattern) {
    bool found = false;
    vector<int> lps = constructTempArray(pattern);
    int j = 0, i = 0;

    // i --> text, j --> pattern
    while (i < (int) text.length()) {
        if (text[i] == pattern[j]) ++i, ++j;
        else {
            if (j != 0) j = lps[j - 1];
            else ++i;
        }

        if (j == (int) pattern.length()) {
            cout << "found match at : " << (i - pattern.length()) << endl;
            j = lps[j-1];
            found = true;
        }
    }

    if (!found) cout << "not found" << endl;
}

int main() {
    string text, pattern;
    getline(cin, text);
    getline(cin, pattern);
    KMPMultipleTimes(text, pattern);

    return 0;
}

/**
Algorithm:

Construct LPS Array (Longest Proper Prefix which is also Suffix):

Initialize lps array with zeros.
Traverse pattern with indices i and index.
If characters at i and index are equal, set lps[i] = index + 1.
If not equal:
If index is not 0, update index to lps[index - 1].
If index is 0, set lps[i] = index and increment i.
Print the constructed LPS array.
KMP Pattern Matching:

Initialize indices i and j to 0.
While i is within the text:
If characters at i and j match, increment both indices.
If mismatch:
If j is not 0, update j to lps[j - 1].
If j is 0, increment i.
If j equals pattern length:
Print match index (i - pattern.length()).
Update j to lps[j - 1].
Set found to true.
If no match, print "not found."
Main Function:

Take input for text and pattern.
Call KMPMultipleTimes function.
This algorithm efficiently finds all occurrences of a pattern in a given text using the KMP algorithm, utilizing the LPS array for optimized pattern matching.
*/
