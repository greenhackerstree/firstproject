#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void symmetric();
void identity();
void determinant();
void main()
{
int i,j,r1,r2,c1,c2,m1[20][20],m2[20][20],m3[20][20],k,sum;
do
{
system("clear");
printf(" Select any one option from the following\n");
printf("1.identity matrix\n 2.symmetric condition\n 3.determinant of a matrix\n 5. Matrix multiplication\n  6.Sum of diagonals of a matrix \n 4. Transpose of a matrix");
scanf("%d",&c1);
switch(c1)
{
case 1: identity();
break;
case 5: printf("Enter the order of the matrix 1");
scanf("%d%d",&r1,&c1);
printf("Enter the order of the matrix 2");
scanf("%d%d",&r2,&c2);
printf("Enter the elements in to the matrix 1");
for(i=0;j=0;jscanf("%d",&m1[i][j]));
printf("Enter the elements in to the matrix 2");
for(i=0;ifor(j=0;jscanf("%d",&m2[i][j]));
printf("Product of the above two matrices:\n");
for(i=0;i{
for(j=0;j{
m3[i][j]==0;
for(k=0;k{
m3[i][j]= m3[i][j]+m1[i][k]*m2[k][j];
}
printf("%d\t",m3[i][j]);
}
printf("\n");
}
break;
case 6: printf("Enter the order of the matrix");
scanf("%d%d",&r1,&c1);
printf("Enter the elements in to the matrix");
for(i=0;ifor(j=0;jscanf("%d",&m1[i][j]));
sum=0;
for(i=0;i{
for(j=0;j{
If(i==j)
{
sum=sum+m1[i][j];
}
}
}
printf("Sum of diagonal elements of the above matrix=%d",sum);
break;
case 4: printf("Enter the order of the matrix");
scanf("%d%d",&r1,&c1);
printf("Enter the elements in to the matrix");
for(i=0;ifor(j=0;jscanf("%d",&m1[i][j]);
printf("Transpose of the above matrix:\n");
for(i=0;i{
for(j=0;j{
printf("%d\t",m1[i][j]);
}
printf("\n");
}
break;
case 2: symmetric();
break;
default: printf("Inavalid choice");
}
printf("Do you want to continue(y/n)";
scanf("%c",&c2);
}
while(c2=='y'||c2=='Y');
getch();
}

void symmetric()
{
int m, n, c, d, matrix[10][10], transpose[10][10];
 
   printf("Enter the number of rows and columns of matrix\n");
   scanf("%d%d",&m,&n);
   printf("Enter the elements of matrix\n");
 
   for (  c = 0 ; c < m ; c++ )
      for ( d = 0 ; d < n ; d++ )
         scanf("%d",&matrix[c][d]);
 
   for( c = 0 ; c < m ; c++ )
   {
      for( d = 0 ; d < n ; d++ )
      {
         transpose[d][c] = matrix[c][d];
      }
   }
 
   if ( m == n ) /* check if order is same */
   {
       for ( c = 0 ; c < m ; c++ )
       {
           for ( d = 0 ; d < m ; d++ )
           {
               if ( matrix[c][d] != transpose[c][d] )
                  break;
           }
           if ( d != m )
              break;
       }
       if ( c == m )
          printf("Symmetric matrix.\n");
   }
   else
       printf("Not a symmetric matrix.\n");
 
}


void identity()
{
    int a[10][10];

    int i, j, row, column, flag = 1;

 
  printf("Enter the order of the matrix A \n");

    scanf("%d %d", &row, &column);

    printf("Enter the elements of matrix A \n");

    for (i = 0; i < row; i++)

    {

        for (j = 0; j < column; j++)

        {

            scanf("%d", &a[i][j]);

        }

    }

    printf("MATRIX A is \n");

    for (i = 0; i < row; i++)

    {

        for (j = 0; j < column; j++)

        {

            printf("%3d", a[i][j]);

        }

        printf("\n");

    }
}

void determinant()
{
  int a[3][3], i, j;

 

  long determinant;

  printf("Enter the 9 elements of matrix: ");

  for(i = 0 ;i < 3;i++)

      for(j = 0;j < 3;j++)

           scanf("%d", &a[i][j]);

 

  printf("\nThe matrix is\n");

  for(i = 0;i < 3; i++)
{

      printf("\n");

      for(j = 0;j < 3; j++)

           printf("%d\t", a[i][j]);

  }
  determinant = a[0][0] * ((a[1][1]*a[2][2]) - (a[2][1]*a[1][2])) -a[0][1] * (a[1][0]

   * a[2][2] - a[2][0] * a[1][2]) + a[0][2] * (a[1][0] * a[2][1] - a[2][0] * a[1][1]);
  printf("\nDeterminant of 3X3 matrix: %ld", determinant);
   return 0;

}
