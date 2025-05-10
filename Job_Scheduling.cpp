#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Sort by profit (second element of pair) in descending order
bool compare(pair<int,int> p1, pair<int,int> p2){
    return p1.second > p2.second;
}

int maxProfit(vector<pair<int,int>> jobs){
    sort(jobs.begin(), jobs.end(), compare);

    int maxDeadline = 0;
    for(auto job : jobs){
        maxDeadline = max(maxDeadline, job.first);
    }

    vector<bool> slot(maxDeadline + 1, false);  // To mark days as occupied
    vector<pair<int,int>> selectedJobs;

    int profit = 0;

    for(int i=0; i<jobs.size(); i++){
        int deadline = jobs[i].first;
        int val = jobs[i].second;

        // Try to find a free day before or on the deadline
        for(int d=deadline; d>=1; d--){
            if(!slot[d]){
                slot[d] = true;
                profit += val;
                selectedJobs.push_back(jobs[i]);
                break;
            }
        }
    }

    cout << "Selected Jobs (deadline, profit): ";
    for(auto job : selectedJobs){
        cout << "(" << job.first << "," << job.second << ") ";
    }
    cout << "\nMax Profit = " << profit << endl;

    return profit;
}

int main(){
    vector<pair<int,int>> jobs = {
        {4, 20},
        {1, 10},
        {1, 40},
        {1, 30}
    };

    maxProfit(jobs);

    return 0;
}
