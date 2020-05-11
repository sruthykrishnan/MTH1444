#include <iostream>
#include<math.h>
using namespace std;
int main()
{
		int i, j, k, n;
    	int matrix[3][3]= { {1,2,4},{3,8,14},{2,6,13} }; ;
		int A[20][20], factor, C[10], x = 0.0;
		cout << "Order of matrix: " << endl;
		cin >> n;
		cout << "Elements of matrix in row wise:" << endl;
		for (i = 1; i <= n; i++)
		{
			for (j = 1; j <= (n + 1); j++)
			{

				cin >> A[i][j];
				
			}
		}
		
		cout << "Augmented matrix:" << endl;
		for (i = 1; i <= n; i++)
		{
			for (j = 1; j <= (n + 1); j++)
			{
				if (j == 4)
					cout << ":" << " " << A[i][j] << endl;               
				else
					cout << A[i][j] << " ";

			}
		}
		for (j = 1; j <= n; j++)        
		{
			for (i = 1; i <= n; i++)
			{
				if (i > j)
				{
					factor = A[i][j] / A[j][j];
					for (k = 1; k <= n + 1; k++)
					{
						A[i][k] = A[i][k] - factor * A[j][k];
					}
				}
			}
		}
		C[n] = A[n][n + 1] / A[n][n];

		for (i = n - 1; i >= 1; i--)            
		{
			x = 0;
			for (j = i + 1; j <= n; j++)
			{
				x = x + A[i][j] * C[j];
			}
			C[i] = (A[i][n + 1] - x) / A[i][i];
		}
		cout << endl;
		cout << "The solution is : " << endl;
		for (i = 1; i <= n; i++)
		{

			cout << "x" << i << "=" << C[i] << endl;      
		}
     	n = 3;
		int low[3][3], up[3][3]; 
		for (int i = 0; i < n; i++)
		{ 
			for (int l = i; l < n; l++)
			{
            	int sum = 0;
				for (int j = 0; j < i; j++)
					sum += (low[i][j] * up[j][l]); 
				up[i][l] = matrix[i][l] - sum;
			}

			
			for (int l = i; l < n; l++) {
				if (i == l)
					low[i][i] = 1; 
				else 
				{
					int sum = 0;
					for (int j = 0; j < i; j++)
						sum += (low[l][j] * up[j][i]);
					low[l][i] = (matrix[l][i] - sum) / up[i][i];
				}
			}
		}

		cout << "The lower matrix is :" << endl << endl;
	 
		for (int i = 0; i < n; i++)
			
		{
			for (int j = 0; j < n; j++)
			{
				if ((i + j) <= 3 && i < j)
					cout << "0" << " ";
				else
					cout << low[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
		cout << "The upper matrix is:" << endl << endl;
		for (int i = 0; i < n; i++)
		{
			 
			for (int j = 0; j < n; j++)
			{
				if ((i + j) <= 3 && i > j)
					cout << "0" << " ";
				else
					cout << up[i][j] << " ";

			}
			cout << endl;
		}
}
