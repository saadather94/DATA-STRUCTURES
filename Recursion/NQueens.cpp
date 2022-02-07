#include<iostream>
using namespace std;
#define N 8

int leftcheck(int ary[N][N], int n, int m)
{
    if(m == -1) {return 1;}

    if(ary[n][m]==1)
    {
        return 0;
    }

    return leftcheck(ary, n, m-1);

}

int rightcheck(int ary[N][N], int n, int m, int row, int col) 
{
    if (m == col) { return 1;}

    if (ary[n][m]==1)
    {
        return 0;
    }

    return rightcheck(ary, n, m + 1, row, col);
}

int topcheck(int ary[N][N], int n, int m)
{
    if (n == 0 ) { return 1;  }

    if (ary[n][m] == 1)
    {
        return 0;
    }

    return topcheck(ary, n - 1, m);
}
int downcheck(int ary[N][N], int n, int m, int row, int col)
{
    if (n == row) { return 1;}

    if (ary[n][m] == 1)
    {
        return 0;
    }

    return downcheck(ary, n + 1, m, row, col);
}

int leftup_diagcheck(int ary[N][N], int n, int m)
{
    if (m == -1 || n==-1 ) { return 1;}

    if (ary[n][m] == 1)
    {
        return 0;
    }

    return leftup_diagcheck(ary, n - 1, m - 1);
}

int rightup_diagcheck(int ary[N][N], int n, int m, int row, int col)
{
    if (m == col || n==-1)
    {
        return 1;
    }

    if (ary[n][m] == 1)
    {
        return 0;
    }

    return rightup_diagcheck(ary, n - 1, m + 1, row, col);
}

int leftdown_diagcheck(int ary[N][N], int n, int m, int row, int col)
{
    if (n == row || m==-1)
    {
        return 1;
    }

    if (ary[n][m] == 1)
    {
        return 0;
    }

    return leftdown_diagcheck(ary, n + 1, m - 1, row, col);
}


int rightdown_diagcheck(int ary[N][N], int n, int m, int row, int col)
{
    if (m == col || n==row)
    {
        return 1;
    }

    if (ary[n][m] == 1)
    {
        return 0;
    }

    return rightdown_diagcheck(ary, n + 1, m + 1, row, col);
}

int check(int ary[N][N], int n, int m, int row, int col)
{
    int a = leftcheck(ary, n, m);
    int b = rightcheck(ary, n, m,row,col);
    int c = topcheck(ary, n, m);
    int d = downcheck(ary, n, m, row, col);
    int e = leftup_diagcheck(ary, n, m);
    int f = rightup_diagcheck(ary, n, m, row, col);
    int g = leftdown_diagcheck(ary, n, m,row, col);
    int h = rightdown_diagcheck(ary, n, m, row, col);

    if(a==1 && b==1 && c==1 && d==1 && e==1 && f==1 && g==1 && h==1) {return 1;}

    return 0;
}



int placequeens(int array[N][N], int col)
{

    if (col >= N)
        return 1;

    for (int i = 0; i < N; i++)
    {
        if (check(array, i, col, N, N))
        {
            array[i][col] = 1;

            if (placequeens(array, col + 1))
            {
                return 1;
            }
            
            array[i][col] = 0; // BACKTRACK
        }

        
    }

    return 0;
}

void print(int array[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++){
            printf(" %d ", array[i][j]);}
        printf("\n");
    }
}

int main()
{

    int array[N][N] = {{0, 0, 0, 0},
                       {0, 0, 0, 0},
                       {0, 0, 0, 0},
                       {0, 0, 0, 0},
                       {0, 0, 0, 0},
                       {0, 0, 0, 0},
                       {0, 0, 0, 0},
                       {0, 0, 0, 0}};

    if(placequeens(array, 0)==0)	
    {
        printf("Solution does not exist");
        return 0;
    }

    print(array);

    return 0;
}