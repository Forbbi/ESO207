#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<limits.h>
#include<math.h>
#define maxsize 909000
#define MOD 1000000007LL
#define min(a, b) ((a) < (b) ? (a) : (b))
void compute_k_scores(int *array, int n, int *k_scores, int max_val) {
    int *left = (int *)malloc(n * sizeof(int));
    int *right = (int *)malloc(n * sizeof(int));
    int *stack = (int *)malloc(n * sizeof(int));
    int top = -1;
    for (int i = 0; i < n; i++) {
        left[i] = -1;
        right[i] = n;
    }
    for (int i = 0; i < n; i++) {
        while (top >= 0 && array[stack[top]] >= array[i]) {
            top--;
        }
        if (top >= 0) {
            left[i] = stack[top];
        }
        stack[++top] = i;
    }
    top = -1;
    for (int i = n - 1; i >= 0; i--) {
        while (top >= 0 && array[stack[top]] >= array[i]) {
            top--;
        }
        if (top >= 0) {
            right[i] = stack[top];
        }
        stack[++top] = i;
    }
    for (int i = 0; i < n; i++) {
        int k = array[i];
        int length = right[i] - left[i] - 1;
        if (k_scores[k] < length) {
            k_scores[k] = length;
        }
    }
    free(left);
    free(right);
    free(stack);
}

void answer_queries(int *k_scores, int max_val, int *queries, int q, int *results) {
    for (int i = 0; i < q; i++) {
        int k = queries[i];
        if (k <= max_val) {
            results[i] = k_scores[k];
        } else {
            results[i] = 0;
        }   }
}
void function4(){
    int n, q;
    scanf("%d %d", &n, &q);
    int *array = (int *)malloc(n * sizeof(int));
    int max_val = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
        if (array[i] > max_val) {
        max_val = array[i];
    }
    }

    int *queries = (int *)malloc(q * sizeof(int));
    for (int i = 0; i < q; i++) {
    scanf("%d", &queries[i]);
    }

    int *k_scores = (int *)calloc(max_val + 1, sizeof(int));

    compute_k_scores(array, n, k_scores, max_val);

    int *results = (int *)malloc(q * sizeof(int));

    answer_queries(k_scores, max_val, queries, q, results);

    for (int i = 0; i < q; i++) {
printf("%d\n", results[i]);
    }

    free(array);
    free(queries);
    free(k_scores);
    free(results);
}






void function1(){
    int arr[maxsize];
    int maxarr[maxsize];
    int q;
    int front=0,back=0,max_front=0,max_back=-1;
    scanf("%d",&q);
    while(q--){
        int x;
        scanf("%d",&x);
        if(x==1){
            int a;
            scanf("%d",&a);
            arr[back]=a;
            back++;
            while(max_back>=max_front&&maxarr[max_back]<a){
                max_back--;
            }
            maxarr[++max_back]=a;
        }else if(x==2){
            int a=arr[front];
            if(max_front<=max_back&&maxarr[max_front]==a){
                max_front++;
            }
            front++;
        }else{
            printf("%d\n",maxarr[max_front]);
        }

    }
}


long long mult(int n, long long dp[]) {
    if (n == 0)
        return 1LL;
    if (dp[n] != -1)
        return dp[n];
    long long result = 0;
    for (int i = 0; i < n; i++) {
        long long left = mult(i, dp);
        long long right = mult(n - 1 - i, dp);
        result = (result + (left * right) % MOD) % MOD;
    }
    dp[n] = result;
    return result;
}
void function3(){
    int n;
    if (scanf("%d", &n) != 1) {
        return 1;
    }
    long long *dp = (long long *)malloc((n + 1) * sizeof(long long));
    if (dp == NULL) {        return 1;
    }

for (int i = 0; i <= n; i++) {
    dp[i] = -1;
    }
    printf("%lld\n", mult(n, dp));
    free(dp);
    
}





void function2(){
    int n,q;
    scanf("%d",&n);
    scanf("%d",&q);
    int arr[n];
    int a=n;
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int lg[n+1];
    int k=0;
    for(int i=0;(1<<i)<=n;i++){
            k++;
    }
    int matrix[n][k];
    lg[1]=0;
    for(int i=2;i<=n;i++){
        lg[i]=lg[i/2]+1;
    }
    for(int i=0;i<n;i++){
        matrix[i][0]=arr[i];
    }
    for(int j=1;(1<<j)<=n;j++){
        for(int i=0;(i+(1<<j)-1<n);i++){
      
            matrix[i][j]=min(matrix[i][j-1],matrix[i+(1<<(j-1))][j-1]);
        }
    }
    while(q--){
        int i,j;
        scanf("%d",&i);
        scanf("%d",&j);
        j--;
        i--;
        int l=j-i+1;
        int answer = min(matrix[i][lg[l]], matrix[j-(1<<lg[l])+1][lg[l]]);
        printf("%d\n",answer);
    }
}
