#include<stdio.h>

int max(int a, int b){
    if(a>b) return a;
    return b;
}

int knapsack(int capacity,int weight[],int value[],int n){
    //an array of size (no.of items) x (capacity of knapsack)

    int knap[n+1][capacity+1]; //as 0 based indexing so for 4 objs(say) 5 rows (from 0 to 4) are req
    for(int i=0;i<=n;i++){
        for(int cap=0;cap<=capacity;cap++){
            if(i==0 || cap==0) knap[i][cap]=0; //if either of no. of items or capacity is 0 then that pos =0
            

            //when weight of the item(weight[i-1]) is equal to less than the current knapsack capacity(cap)
            else if(weight[i-1]<=cap){

            //considers 2 scenarios: including the ith item => value[i-1]+ what remaining could be added i.e knap[i-1][cap-weight[i-1]]
                //                     : excluding the ith item => knap[i-1][cap]
                knap[i][cap] = max(value[i-1]+knap[i-1][cap-weight[i-1]],knap[i-1][cap]);
            }

            else knap[i][cap]=knap[i-1][cap]; //just store the value of the previous row as it is
        }
    }
    for(int j=0;j<=n;j++){
        for(int k=0;k<=capacity;k++){
            printf("%d \t",knap[j][k]);
        }
        printf("\n");
    }
    return knap[n][capacity];
}


int main(){
    int cap;
    printf("Enter capacity of knapsack : ");
    scanf("%d",&cap);

    int n;
    printf("Enter number of items: ");
    scanf("%d",&n);

    int value[n],weights[n];

    for(int i=0;i<n;i++){
        printf("Enter value of item %d : ",i+1);
        scanf("%d",&value[i]);
        printf("Enter weight of item %d : ",i+1);
        scanf("%d",&weights[i]);
    }

    printf("The solution of 0 1 knapsack is : %d",knapsack(cap,weights,value,n));
    return 0;
}