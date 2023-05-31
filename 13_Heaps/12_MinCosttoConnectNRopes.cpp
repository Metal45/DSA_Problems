long long connectRopes(int* arr, int n)
{
    // Your code goes here
    priority_queue<long long, vector<long long>, greater<long long>> minHeap;

    for(int i = 0; i < n; i++){
        minHeap.push(arr[i]);
    }

    long long minCost = 0;

    while(minHeap.size() > 1){
        int l1 = minHeap.top();
        minHeap.pop();
        int l2 = minHeap.top();
        minHeap.pop();
        int newlen = l1 + l2;
        minCost += newlen;
        minHeap.push(newlen);
    }

    return minCost;
}
