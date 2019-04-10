#include <stdio.h>
#include <stdbool.h>
 
int main() {
	printf("................................................BANKER'S ALGORITHM......................................................\n\n");
    int cur[5][5], max_claim[5][5], avail[5];
    int allocate[5] = {0, 0, 0, 0, 0}, max_res[5];
    int running[5]; 
    int i, j, exec, r, p, count = 0;
    bool safe = false;
    
    do{ 
    printf("\nEnter the number of resources: ");
    scanf("%d", &r);
    if(r<=0)
    printf("Invalid Entry Try Again!\n");
	}
	while(r<=0);
 	do{
    printf("\nEnter the number of processes: ");
    scanf("%d", &p);
    if(p<=0)
    printf("Invalid Entry Try Again!\n");
	}
	while(p<=0);
    for (i = 0; i < p; i++) {
        running[i] = 1;
        count++;
    }
 
    printf("\nEnter Claim Vector: ");
    for (i = 0; i < r; i++)
        scanf("%d", &max_res[i]);
 
    printf("\nEnter Allocated Resource Table: ");
    for (i = 0; i < p; i++) {
        for (j = 0; j < r; j++)
            scanf("%d", &cur[i][j]);
    }
 
    printf("\nEnter Maximum Claim table: ");
    for (i = 0; i < p; i++) {
        for (j = 0; j < r; j++)
            scanf("%d", &max_claim[i][j]);
    }
 
    printf("\nThe Claim vector is: ");
    for (i = 0; i < r; i++)
        printf("%d ", max_res[i]);
 
    printf("\nThe Allocated Resource Table:\n");
    for (i = 0; i < p; i++) {
        for (j = 0; j < r; j++)
            printf("\t%d", cur[i][j]);
        printf("\n");
    }
 
    printf("\nThe Maximum Claim Table:\n");
    for (i = 0; i < p; i++) {
        for (j = 0; j < r; j++)
            printf("\t%d", max_claim[i][j]);
        printf("\n");
    }
 
    for (i = 0; i < p; i++)
        for (j = 0; j < r; j++)
            allocate[j] += cur[i][j];
 
    printf("\nAllocated resources: ");
    for (i = 0; i < r; i++)
        printf("%d ", allocate[i]);
    for (i = 0; i < r; i++)
        avail[i] = max_res[i] - allocate[i];
 
    printf("\nAvailable resources: ");
    for (i = 0; i < r; i++)
        printf("%d ", avail[i]);
    printf("\n");
    
// Working Of Algorithm 
    while (count != 0) {
        safe = false;
        for (i = 0; i < p; i++) {
            if (running[i]) {
                exec = 1;
                for (j = 0; j < r; j++) {
                    if (max_claim[i][j] - cur[i][j] > avail[j]) {
                        exec = 0;
                        break;
                    }
                }
 
                if (exec) {
                    printf("\nProcess%d is executing.\n", i + 1);
                    running[i] = 0;
                    count--;
                    safe = true;
                    for (j = 0; j < r; j++)
                        avail[j] += cur[i][j];
                    break;
                }
            }
        }
 
        if (!safe) {
            printf("\nThe processes are in unsafe state.");
            break;
        }
 
        if (safe)
            printf("\nThe process is in safe state.");
 
        printf("\nAvailable vector: ");
        for (i = 0; i < r; i++)
            printf("%d ", avail[i]);
    }
 
    return 0;
}
