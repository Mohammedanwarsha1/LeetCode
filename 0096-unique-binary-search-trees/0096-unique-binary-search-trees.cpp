class Solution {
public:
    int f(int n){
        if(n==0||n==1) return 1;
        if(n==2) return 2;
        int sum=0;
        for(int k=1;k<=n;k++){
            sum+=f(k-1)*f(n-k);
        }
        return sum;

    }
    int numTrees(int n) {
        return f(n);
    }
};