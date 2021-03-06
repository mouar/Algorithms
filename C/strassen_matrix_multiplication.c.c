#include<stdio.h>
#include<math.h>
int strassen(int *A,int *B,int *c,int m,int n)
{
	int p1,p2,p3,p4,p5,p6,p7;
   if(m==2)
   {
      p1=(*A+*(A+n+1))*(*B+*(B+n+1));
      p2=(*(A+n)+*(A+n+1))*(*B);
      p3=(*A)*(*(B+1)-*(B+n+1));
      p4=(*(A+n+1))*(-*B+*(B+n));
      p5=(*A+*(A+1))*(*(B+n+1));
      p6=(-*A+*(A+n))*(*B+*(B+1));
      p7=(*(A+1)-(*(A+n+1)))*(*(B+n)+*(B+n+1));

      *c=*c+p1+p4-p5+p7;
      *(c+1)=*(c+1)+p3+p5;
      *(c+n)=*(c+n)+p2+p4;
      *(c+n+1)=*(c+n+1)+p1-p2+p3+p6;
   }
   else
   {
   	m=m/2;
   	strassen(A,B,c,m,n);
   	strassen(A+m,B+m*n,c,m,n);
   	strassen(A,B+m,c+m,m,n);
    strassen(A+m,B+m*(n+1),c+m,m,n);
    strassen(A+m*n,B,c+m*n,m,n);
    strassen(A+m*(n+1),B+m*n,c+m*n,m,n);
    strassen(A+m*n,B+m,c+m*(n+1),m,n);
    strassen(A+m*(n+1),B+m*(n+1),c+m*(n+1),m,n);
   }
  return 0;
}
int main()
{
	int m;
	printf("enter the dimension of square matrix you want to multiply\n");
	scanf("%d",&m);
	int a[m][m];

	for(int i=0;i<m;i++)
	{
		printf("enter the elements of the row %d of matrix 1\n",i+1);
		for(int j=0;j<m;j++)
		{
			scanf("%d",&a[i][j]);
		}
	}
	int b[m][m];
	for(int i=0;i<m;i++)
	{
		printf("\nenter the elements of the row %d of matrix 2: \n",i+1);
		for(int j=0;j<m;j++)
		{
			scanf("%d",&b[i][j]);
		}
	}
    int C[m][m];
    for(int i=0;i<m;i++)
	{
		for(int j=0;j<m;j++)
		{
		  C[i][j]=0;
		}
	}
	printf("\nthe resultant matrix is:\n");
	strassen(a,b,C,m,m);
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<m;j++)
		{
		  printf("%d\t",C[i][j]);
		}
		printf("\n");
	}
return 0;
}
