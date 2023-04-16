
//Binary Exponentiation 
// TC -> O(LogN) as N is getting divided by 2

double myPow(double x, int n) {
    double ans = 1.0;
    long nn = n;
    if(nn < 0){
        nn *= -1;
    }
    
    while(nn > 0){
        if(nn % 2 == 1){
            ans = ans * x;
            nn = nn -1;
        }else{
            x = x*x;
            nn = nn/2;
        }
    }

    if(n < 0){
        ans = (double)(1.0)/(double)(ans);
    }

    return ans;
}



// Brute Force -> TC O(N) SC -> O(N)
// Linear Time as the N is getting decreased by 1 so there will be n calls until it becomes 0

double helper(double x, int n){
    if(n <= 0){
        return 1;
    }

    return x * myPow(x, n-1);
}

double myPow(double x, int n) {
    if(n == INT_MAX){
        if(x == 1){
            return 1;
        }else if(x == -1){
            return -1;
        }else{
            return 0;
        }
    }else if(n == INT_MIN){
        if(x == 1 || x == -1){
            return 1;
        }else{
            return 0;
        }
    }
    
    if(n >= 0){
        return helper(x,n);
    }else{
        n *= -1;
        return 1/helper(x, n);
    }
}