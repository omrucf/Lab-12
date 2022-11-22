#include <iostream>
#include <vector>

#define INF INT_MAX

using namespace std;

typedef vector<vector<int>> MTRX;

MTRX getOptimalSplit(int[], int);

void printOptimal(int[], int , int , int);

int main()
{
  int b[] = {5,4,6,2,7};
  int n = 5;

  printOptimal(b, 1, n-1, n);
  cout << endl ;

  int a[] = {4,4,6,12,7};
  printOptimal(a, 1, n-1 ,n);

  cout << endl;
  return 0;
}

MTRX getOptimalSplit(int Ns[], int n)
{
  int M[n][n];
  MTRX S(n, vector<int> (n));
  for (int i = 1; i < n; i++)
    M[i][i] = 0;

  for (int l = 2; l < n; l++)
  {
    for (int i = 1; i < n - l + 1; i++)
    {
      int j = i + l - 1;

      M[i][j] = INF;

      for (int k = i; k <= j - 1; k++)
      {
        int q = M[i][k] + M[k + 1][j] + Ns[i - 1] * Ns[k] * Ns[j];

        if (q < M[i][j])
          {
            M[i][j] = q;
            S[i][j] = k;
          }
      }
    }
  }
  return S;
}

void printOptimal(int Ns[], int i , int j, int n)
{
  MTRX S = getOptimalSplit(Ns, n);

  if (i == j)
    {
      cout << "A" << i;
      return;
    }
  
  cout << "(" ;
  
  printOptimal(Ns, i , S[i][j], n);
  printOptimal(Ns, S[i][j]+1, j, n);

  cout << ")" ;
}