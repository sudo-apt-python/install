#include <bits/stdc++.h>
using namespace std;
#define d 256

void searchPattern(const char pattern[], const char text[], int prime)
{
    int patternLength = strlen(pattern);
    int textLength = strlen(text);
    int i, j;
    int patternHash = 0;
    int textHash = 0;
    int h = 1;

    for (i = 0; i < patternLength - 1; i++)
        h = (h * d) % prime;

    for (i = 0; i < patternLength; i++)
    {
        patternHash = (d * patternHash + pattern[i]) % prime;
        textHash = (d * textHash + text[i]) % prime;
    }

    for (i = 0; i <= textLength - patternLength; i++)
    {
        if (patternHash == textHash)
        {
            for (j = 0; j < patternLength; j++)
            {
                if (text[i + j] != pattern[j])
                {
                    break;
                }
            }

            if (j == patternLength)
                cout << "Pattern found at index " << i << endl;
        }

        if (i < textLength - patternLength)
        {
            textHash = (d * (textHash - text[i] * h) + text[i + patternLength]) % prime;

            if (textHash < 0)
                textHash = (textHash + prime);
        }
    }
}

int main()
{
    const int MAX_SIZE = 100;
    char text[MAX_SIZE], pattern[MAX_SIZE];

    cout << "Enter the text: ";
    cin.getline(text, MAX_SIZE);

    cout << "Enter the pattern: ";
    cin.getline(pattern, MAX_SIZE);

    int prime = INT_MAX;

    searchPattern(pattern, text, prime);
    return 0;
}
