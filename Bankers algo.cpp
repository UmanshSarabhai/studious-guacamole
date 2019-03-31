#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
int i = 0;
int j = 0;
pthread_mutex_t mutex;//mutex lock for access to global variable

int initResourceVector [resourceTypeQuan];
int availResourceVector [resourceTypeQuan];
int allocMatrix [processQuan][resourceTypeQuan] = {{1,1,0},{1,3,0},{0,0,2},{0,1,1},{0,2,0}};
int maxMatrix [processQuan][resourceTypeQuan] = {{5,5,5},{3,3,6},{3,5,3},{7,1,4},{7,2,2}};
int needMatrix [processQuan][resourceTypeQuan];

int requestResource(int processID,int requestVector[]);
int releaseResource(int processID,int releaseVector[]);
int ifGreaterThanNeed(int processID,int requestVector[]);
int ifEnoughToRelease(int processID,int releaseVector[]);
int ifInSafeMode();
int ifEnoughToAlloc();
void printNeedMatrix();
void printAllocMatrix();
void printAvailable();
void printReqOrRelVector(int vec[]);
void *customer(void* customerID);
