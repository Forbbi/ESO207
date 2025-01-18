#include <stdio.h>
#include <time.h>
#define MOD 2025

void mM(long int a[2][2], long int b[2][2]) {
    long int result[2][2];
    result[0][0] = (a[0][0] * b[0][0] + a[0][1] * b[1][0]) % MOD;
    result[0][1] = (a[0][0] * b[0][1] + a[0][1] * b[1][1]) % MOD;
    result[1][0] = (a[1][0] * b[0][0] + a[1][1] * b[1][0]) % MOD;
    result[1][1] = (a[1][0] * b[0][1] + a[1][1] * b[1][1]) % MOD;
    a[0][0] = result[0][0];
    a[0][1] = result[0][1];
    a[1][0] = result[1][0];
    a[1][1] = result[1][1];
}

void mP(long int mat[2][2], long int n) {
    if (n == 0 || n == 1) {
        return;
    }

    long int base[2][2] = {{1, 1}, {1, 0}};

    mP(mat, n / 2);
    mM(mat, mat); 

    if (n % 2 != 0) {
        mM(mat, base); 
    }
}


long int CleverFib(long int n) {
    if (n == 0||n==1) {
        return n;
    }

    long int fibMatrix[2][2] = {{1, 1}, {1, 0}};

    mP(fibMatrix, n - 1);

    
    return fibMatrix[0][0];
}

int RFib(int n){
    if(n==0||n==1)return n;
    return (RFib(n-1)+RFib(n-2))%MOD;
} 
int TrivialGCD(int a, int b){
    if(a>b)TrivialGCD(b,a);
    for(int i=a;i>=1;i--){
        if(a%i==0&&b%i==0)
        return i;
    }
    return 1;
}
 long int EuclidGCD(long int a, long int b){

    if(b==0)return a;
    return EuclidGCD(b,a%b);
 }
// int main() {
//     clock_t start_t, end_t;
// double total_t;
// start_t = clock();
//     long int n;
//     printf("Enter the value of n: ");
//     scanf("%ld", &n);

//     printf("The %ldth Fibonacci number modulo 2025 is: %ld\n", n, CleverFib(n));
//     // printf("The %ldth Fibonacci number modulo 2025 is: %ld\n", n, RFib(n));
//    end_t = clock();
// total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
// // CLOCKS_PER_SEC is a constant defined in time.h and its value is 10^6.
// printf("Total time taken: %f\n", total_t );
// return 0;
// }

// int main(){
// clock_t start_t, end_t;
// double total_t;
// start_t = clock();
//     int a,b;
//     printf("Two Number\n");

//     scanf("%d %d",&a , &b);
//     printf("GCD of A and B : %d",EuclidGCD(a,b));
//     // printf("GCD of A and B : %d",TrivialGCD(a,b));
  // printf("The %ldth Fibonacci number modulo 2025 is: %ld\n", n, RFib(n));
//    end_t = clock();
// total_t = (double)(end_t - start_t) / CLOCKS_PER_SEC;
// // CLOCKS_PER_SEC is a constant defined in time.h and its value is 10^6.
// printf("Total time taken: %f\n", total_t );
// }
