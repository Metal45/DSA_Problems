    
    
    int maxProfit(vector<int>& prices){
        
        // Keeping the track of the last minimum and finding the maxProfit
        int maxProfit = INT_MIN, MinSoFar = prices[0];

        for(int i = 0; i < prices.size(); i++){
            MinSoFar = min(prices[i], MinSoFar);
            int profit = prices[i] - MinSoFar;
            maxProfit = max(profit, maxProfit);
        }

        return maxProfit;
    }

    


    int maxProfit(vector<int>& prices){

        // Keeping the track of the next Maximum and finding the maxProfit
        int maxProfit = INT_MIN, MaxSoFar = prices[prices.size() - 1];

        for(int i = prices.size() - 1; i >= 0; i--){
            MaxSoFar = max(prices[i], MaxSoFar);
            int profit = MaxSoFar - prices[i];
            maxProfit = max(profit, maxProfit);
        }

        return maxProfit;
    }
    



    int maxProfit(vector<int>& prices){

        // Making the next Maximum array and finding the maxProfit
        int maxProfit = 0, MaxSoFar = prices[prices.size() - 1];
        int *NexMaximum = new int[prices.size()];

        for(int i = prices.size() - 1; i >= 0; i--){
            MaxSoFar = max(prices[i], MaxSoFar);
            NexMaximum[i] = MaxSoFar;
        }

        for(int i = 0; i < prices.size() - 1; i++){
            int profit = NexMaximum[i] - prices[i];
            maxProfit = max(maxProfit, profit);
        }

        return maxProfit;
    }