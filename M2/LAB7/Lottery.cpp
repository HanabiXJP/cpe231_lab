//66070501038 Phanthach
#include <bits/stdc++.h>

using namespace std;

vector<int> ShiftTable(vector<char> Pattern, int m)
{
    int size = 27;
    vector<int> Table(size);
    for (int i = 0; i < size; i++)
    {
        Table[i] = m;
    }
    for (int j = 0; j < m - 1; j++)
    {
        Table[(int)Pattern[j] - 64] = m - 1 - j;
    }

    return Table;
}

void HorspoolMatching(vector<char> Pattern, vector<char> Lottery, int m, int n)
{
    vector<int> Table = ShiftTable(Pattern, m);

    int i = m - 1;
    int counter = 0;
    while (i <= n - 1)
    {
        int k = 0;
        while(k <= m - 1 && Pattern[m - 1 - k] == Lottery[i - k])
        {
            k++;
        }
        if (k == m)
        {
            cout << "YES" << " " << counter << " " << i - m + 1;;
            return;
        }
        else {
            counter++;
            i = i + Table[(int)Lottery[i] - 64];
        }
    }
    cout << "NO" << " " << counter << " " << -1;
}

int main()
{
    int n,m;

    cin >> n >> m;

    vector<char> Lottery(n);
    vector<char> Pattern(m);

    for (int i = 0; i < n; i++) {

        cin >> Lottery[i];

    }

    for (int i = 0; i < m; i++) {

        cin >> Pattern[i];

    }

    HorspoolMatching(Pattern, Lottery, m, n);
    
    return 0;
}