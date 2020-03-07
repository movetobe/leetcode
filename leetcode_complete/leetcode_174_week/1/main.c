/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* kWeakestRows(int** mat, int matSize, int* matColSize, int k, int* returnSize){
    int row, col;                                                                  
    int *weak = calloc(1, sizeof(int) * k);            
    int *visited = calloc(1, sizeof(int) * matSize);
                                                                                   
    *returnSize = 0;                                                               
    for (col = 0; col < matColSize[0]; col++) {                                    
        for (row = 0; (row < matSize) && (*returnSize < k); row++) {               
            if (!mat[row][col] && !visited[row])  {                                         
                weak[*returnSize] = row;        
                visited[row] = 1;
                *returnSize = *returnSize + 1;                                     
            }                                                                      
        }                                                                          
    }       
    for (row = 0; (row < matSize) && (*returnSize < k); row++) {               
        if (!visited[row])  {                                         
            weak[*returnSize] = row;        
            *returnSize = *returnSize + 1;                                     
        }                                                                      
    }  

    free(visited);
    return weak;  

}
