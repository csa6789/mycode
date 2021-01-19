#include <cstdio>

bool Find(int* matrix, int rows, int columns, int number)
{
    if(matrix == nullptr || rows <= 0 || columns <= 0)
        return false;
    int row = 0;
    int col = columns - 1;

    while (row < rows && col >= 0)
    {
        if(matrix[row * columns + col] == number) {
            return true;
        } else if(matrix[row * columns + col] > number) {
            --col;
        } else {
               --row;
            }           
    }
    return false;
    
}