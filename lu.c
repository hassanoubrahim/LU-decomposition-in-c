#include <stdlib.h>
#include <stdio.h>
#define N 10

//solve ly=b
float *descente(float L[N][N], float B[N], int n)
{
  float   *y;
  y = malloc(sizeof(float) * n);
  y[0]=B[0]/L[0][0];

   for(int i=1; i<n; i++){
	float sum=0;
	for(int j=0; j<=i-1;j++){
		sum+=L[i][j]*y[j];
	}
	y[i]=(B[i]-sum)/L[i][i];

	}
  return (y);
}


//solve ux=y equation

float *remontee(float U[N][N], float y[N], int n)
{

  float* x;
  x=malloc(sizeof(float) * n);
  x[n-1]=y[n-1]/U[n-1][n-1];

	for(int i=n-2;i>=0;i--){
		float sum=0;
		for(int j=i;j<n;j++){
			sum+=U[i][j]*x[j];
		}
	x[i]=(y[i]-sum)/U[i][i];
	}
  return x;
}


float *lu(float A[N][N], float B[N], int n)
{

 //LU algorithm
  float *x;
  float *y;
  float L[N][N];
  float U[N][N];
  
  
  for(int i=0;i<n;i++)
  	for(int j=0; j<n; j++){
  		if(i==j)
  			L[i][j]=1;
  			}
  
  for(int i=0;i<n;i++){
  		U[0][i]=A[0][i];
  		}
  
  for(int k=0;k<n-1; k++){
		for(int i=k+1;i<n;i++){
			L[i][k]=A[i][k]/A[k][k];
			for(int j=k+1; j<n; j++){
				A[i][j]=A[i][j]-L[i][k]*A[k][j];
				if(i<=j)
					U[i][j]=A[i][j];
			}
		}
	}
  /***************************************/
  y=descente(L, B, n);
  x=remontee(U, y, n);
  return (x);
}

int main()
{
  float   A[N][N], B[N];
  float   *x;
  int     n;

  printf("Enter the size of the matrix: ");
  scanf("%d", &n);

  /* Filling the matrix A */
  printf("Filling the matrix A\n");
  for(int i = 0; i < n; i++)
  {
    for(int j = 0; j < n; j++)
    {
      printf("A[%d][%d] = ", i, j);
      scanf("%f", &A[i][j]);
    }
  }

  /* Filling the vector B*/
  printf("Filling the matrix B\n");
  for (int i = 0; i < n; i++)
  {
    printf("B[%d] = ", i);
    scanf("%f", &B[i]);
  }

  /* The calculation of the result */
  x = lu(A, B, n);

  /* Printing the results */
  printf("\nThe resulting vector: [");
  for (int i = 0; i < n; i++)
    printf("%f%c", x[i], ",]"[i == n - 1]);
}

