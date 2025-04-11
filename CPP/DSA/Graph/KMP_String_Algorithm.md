```cpp
#include<iostream>
#include<string>
#include<vector>
using namespace std;

vector<int> pre_kmp(string pattern) {
    int size = pattern.size();
    vector<int> pie(size);
    pie[0] = 0;
    int k = 0;

    for (int i = 1; i < size; i++) {
        while (k > 0 && pattern[k] != pattern[i]) {
            k = pie[k - 1];
        }
        if (pattern[k] == pattern[i]) {
            k++;
        }
        pie[i] = k;
    }

    return pie;
}

void kmp(string text, string pattern) {
    vector<int> pie = pre_kmp(pattern);
    int matched_pos = 0;

    for (int current = 0; current < text.length(); current++) {
        while (matched_pos > 0 && pattern[matched_pos] != text[current]) {
            matched_pos = pie[matched_pos - 1];
        }

        if (pattern[matched_pos] == text[current]) {
            matched_pos++;
        }

        if (matched_pos == pattern.length()) {
            cout << "Pattern occurs with shift " << current - pattern.length() + 1 << endl;
            matched_pos = pie[matched_pos - 1];
        }
    }
}

int main() {
    string text, pattern;
    cout << "Enter text: ";
    cin >> text;
    cout << "Enter pattern: ";
    cin >> pattern;

    kmp(text, pattern);
    return 0;
}

```
Output:
```
Enter text: ababababbewew
Enter pattern: babbe
Pattern occurs with shift 5
```
Time complexity:
O(m + n)
Brutch Force:
```cpp
#include <iostream>
#include <string>
using namespace std;

void bruteForceMatch(string text, string pattern) {
    int n = text.length();
    int m = pattern.length();

    for (int i = 0; i <= n - m; i++) {
        int j;

        // Compare pattern with substring starting at i
        for (j = 0; j < m; j++) {
            if (text[i + j] != pattern[j])
                break;
        }

        // If full pattern matched
        if (j == m) {
            cout << "Pattern occurs with shift " << i << endl;
        }
    }
}

int main() {
    string text, pattern;
    cout << "Enter text: ";
    cin >> text;
    cout << "Enter pattern: ";
    cin >> pattern;

    bruteForceMatch(text, pattern);

    return 0;
}

```
