

long num_sub_mat(int **mat, int matSize, int *matColSize, int x, int y)
{
    long num = 1;
    int i = 0, j = 0;

    for (i = x; i < matSize; i++) {
        if ()
    }
    for (i = x; i < matSize; i++) {
        for (j = y; j < matColSize; j++) {

        }
    }
}
int numSubmat(int** mat, int matSize, int* matColSize){
    int i = 0, j = 0;
    long num = 0;

    for (i = 0; i < matSize; i++) {
        for (j = 0; j < matColSize; j++) {
            if (mat[i][j] == 0) {
                continue;
            }
            num += num_sub_mat(mat, matSize, matColSize, i, j);
        }
    }
    return num;
}