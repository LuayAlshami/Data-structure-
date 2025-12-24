#include <stdio.h>

int main()
{
    int matrix[10][10];
    int sparse[20][3];
    int rows, cols;
    int i, j, k = 1;
    int nonZero = 0;

    
    printf("Enter number of rows and columns: ");
    scanf("%d %d", &rows, &cols);

   
    printf("Enter matrix elements:\n");
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            scanf("%d", &matrix[i][j]);
            if (matrix[i][j] != 0)
                nonZero++;
        }
    }

    sparse[0][0] = rows;
    sparse[0][1] = cols;
    sparse[0][2] = nonZero;

    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            if (matrix[i][j] != 0)
            {
                sparse[k][0] = i;
                sparse[k][1] = j;
                sparse[k][2] = matrix[i][j];
                k++;
            }
        }
    }

    printf("\nSparse Matrix Representation:\n");
    printf("Row\tCol\tValue\n");
    for (i = 0; i <= nonZero; i++)
    {
        printf("%d\t%d\t%d\n", sparse[i][0], sparse[i][1], sparse[i][2]);
    }

    return 0;
}
