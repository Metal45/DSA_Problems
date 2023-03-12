int findMinDifference(vector<string>& timePoints) {
    vector<int> minute;
    
    // convert time string into int vetcor of minutes
    for(int i = 0; i < timePoints.size(); i++){
        string curr = timePoints[i];
        int hours = stoi(curr.substr(0,2));
        int minutes = stoi(curr.substr(3,2));
        minutes = hours*60 + minutes;
        minute.push_back(minutes);
    }

    //sorting the minutes vector
    sort(minute.begin(), minute.end());

    // find the minimum difference after sorting the minutes vector
    int minDiff = INT_MAX;
    int n = minute.size();
    for(int i = 0; i < n -1; i++){
        int diff = minute[i + 1] - minute[i];
        minDiff = min(diff, minDiff);
    }

    // edge case 
    int lastDiff = (minute[0] + 1440) - minute[n - 1];
    minDiff = min(lastDiff, minDiff);

    return minDiff;
}
};