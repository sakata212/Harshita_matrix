#include <bits/stdc++.h>
using namespace std;
int MatrixChainOrder(int p[], int n)
{
    int m[n][n];

    int i, j, k, L, q;


    for (i = 1; i < n; i++)
        m[i][i] = 0;

    for (L = 2; L < n; L++)
    {
        for (i = 1; i < n - L + 1; i++)
        {
            j = i + L - 1;
            m[i][j] = 99999;
            for (k = i; k <= j - 1; k++)
            {
                q = m[i][k] + m[k + 1][j]
                    + p[i - 1] * p[k] * p[j];
                if (q < m[i][j])
                    m[i][j] = q;
            }
        }
    }

    return m[1][n - 1];
}
int main()
{
    int n;
    cout<<"Enter number of matrices"<<endl;
    cin>>n;
    int arr[n+1];
    cout<<"Enter the array of size of matrices"<<endl;
    for(int i=0;i<n+1;i++)
        cin>>arr[i];
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Minimum number of multiplications is "
         << MatrixChainOrder(arr, size);


    return 0;
}
