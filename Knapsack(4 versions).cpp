// GROUP:   X
// ID:      XXXXXXXX
// Assign:  09
// Assign:  Knapsack
// UVA:     10130
// Name:    XXX MY FULL NAME

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////////////////

struct Obj
{
    int v; // value (price) of object
    int w; // weight of object
};

Obj a[1000];

////////////////////////////////////////////////////////////////////////////////////////////////////////////

int T1[1001][31];
int Knapsack1(int n, int w){

    if(n==0) return 0;
    if(T1[n][w]!=-1) return T1[n][w];
    int v1=0;
    if(w>=a[n-1].w) v1=a[n-1].v +Knapsack1(n - 1, w - a[n - 1].w);
    int v2= Knapsack1(n-1,w);
    int  v = max(v1,v2);
    T1[n][w]=v;
    return v;



}
int ComputeKnapsack1(int N, int W){


    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= W; j++) {
            T1[i][j] = -1;
        }
    }
    return Knapsack1(N,W);
}// Recursive - memoization - initialize T then call Knapsack1(N,W);

////////////////////////////////////////////////////////////////////////////////////////////////////////////


int ComputeKnapsack2(int N, int W){
    int T2[N+1][W+1];
    for(int w=0;w<=W;w++){T2[0][w]=0;}
    for(int n=1;n<=N;n++){
        for(int w=0;w<=W;w++){
            int v1=0;
            if(w>=a[n-1].w) v1=a[n-1].v +T2[n-1][w-a[n-1].w];
            int v2=T2[n-1][w];
            int  v = max(v1,v2);
            T2[n][w]=v;

        }
    }


    return T2[N][W];


} // Bottom-up, do not save space

////////////////////////////////////////////////////////////////////////////////////////////////////////////


int ComputeKnapsack3(int N, int W){
    int T3[2][W+1];

    for(int w=0;w<=W;w++){T3[0][w]=0;}
    for(int n=1;n<=N;n++){
        for(int w=0;w<=W;w++){
            int v1=0;
            if(w>=a[n-1].w) v1=a[n-1].v +T3[(n-1)%2][w-a[n-1].w];
            int v2=T3[(n-1)%2][w];
            int  v = max(v1,v2);
            T3[1-(n%2)][w]=v;

        }
    }
    return T3[N%2][W];

} // Bottom-up, use two rows only

////////////////////////////////////////////////////////////////////////////////////////////////////////////


int ComputeKnapsack4(int N, int W){
    int T4[W+1];
    for(int w=0;w<=W;w++){T4[w]=0;}
    for(int n=1;n<=N;n++){
        for(int w=W;w>=0;w--){
            int v1=0;
            if(w>=a[n-1].w) v1=a[n-1].v +T4[w-a[n-1].w];
            int v2=T4[w];
            int  v = max(v1,v2);
            T4[w]=v;

        }
    }
    return T4[W];

} // Bottom-up, save maximum space

////////////////////////////////////////////////////////////////////////////////////////////////////////////

int ComputeKnapsack(int N, int W) // Here we can choose the method
{
    //return ComputeKnapsack1(N,W);
    //return ComputeKnapsack2(N,W);
    //return ComputeKnapsack3(N,W);
    return ComputeKnapsack4(N,W);
}

void Compute(){

    int T;
    cin >> T; // Number of test cases
    while (T--) {
        int t;
        cin >> t; // Number of items
        for (int i = 0; i < t; i++) {
            cin >> a[i].v >> a[i].w; // Value and weight
        }
        int MW;
        cin >> MW; // Maximum weight capacity
        cout << ComputeKnapsack(t, MW) << endl; // Output the result
    }



} // Get input and call ComputeKnapsack() whenever needed


////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{
    //freopen("input_assign09_10130.txt", "r", stdin);
    Compute();
    return 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////
