#include<stdio.h>

void swap(float *a,float *b){
    float temp = *a;
    *a=*b;
    *b=temp;
}

void sortItems(int val[],int weight[],int size){
    float ratio[size];
    for(int i=0;i<size;i++){
        ratio[i] = (float ) val[i]/weight[i];
    }
    for(int i=0;i<size;i++){
        for(int j=0;j<size-i-1;j++){
            if(ratio[j]<ratio[j+1]){
                swap(&ratio[j],&ratio[j+1]);
                //swap weights
                int tempW=weight[j];
                weight[j]=weight[j+1];
                weight[j+1]=tempW;
                //swap values
                int tempV=val[j];
                val[j]=val[j+1];
                val[j+1]=tempW;
            }
        }
    }
}

float fracKnap(int val[],int weight[],int size,int capacity){
    sortItems(val,weight,size);

    int currw=0;
    float totalval=0.0  ;
    for(int i=0;i<size;i++){
        if(currw+weight[i]<=capacity){
            currw+=weight[i];
            totalval+=val[i];
        }
        else{
            int remW=capacity-currw;
            totalval+=val[i]*((float)remW/weight[i]);
            break;
        }
    }
    return totalval;
}

int main() {
    int weights[] = {10, 20, 30};
    int values[] = {60, 100, 120};
    int n = sizeof(weights) / sizeof(weights[0]);
    int W = 50; // Knapsack capacity

    float maxValue = fracKnap(values,weights, n, W);
    printf("Maximum value in Knapsack = %.2f\n", maxValue);

    return 0;
}