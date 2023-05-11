//Implement the activity selection problem using a greedy approach

/*
The activity selection problem is a classic problem in computer science and is used to schedule a set of activities given their start and finish times. The problem is to select the maximum number of activities that can be performed by a single person or machine, assuming that a person or machine can only work on one activity at a time. The objective is to maximize the number of activities performed. This problem is also known as the Interval Scheduling Problem.
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Define an activity struct to store start and end times
struct Activity {
    int start, end;
};

// Define a function to compare activities based on end times
bool compare(Activity a, Activity b) {
    return a.end < b.end;
}

// Define a function to find the maximum number of activities that can be performed
int maxActivities(vector<Activity>& activities) {
    // Sort activities in increasing order of end times
    sort(activities.begin(), activities.end(), compare);
    
    int n = activities.size();
    int count = 1;
    int lastEnd = activities[0].end;
    
    // Select activities whose start time is greater than or equal to the end time of the last selected activity
    for (int i = 1; i < n; i++) {
        if (activities[i].start >= lastEnd) {
            count++;
            lastEnd = activities[i].end;
        }
    }
    
    return count;
}

int main() {
    int n;
    cout << "Enter the number of activities: ";
    cin >> n;
    
    vector<Activity> activities(n);
    for (int i = 0; i < n; i++) {
        cout << "Enter start and end times for activity " << i+1 << ": ";
        cin >> activities[i].start >> activities[i].end;
    }
    
    int maxCount = maxActivities(activities);
    cout << "Maximum number of activities that can be performed: " << maxCount << endl;
    
    return 0;
}

/*
In this implementation, we define an Activity struct to store the start and end times of each activity. We also define a function to compare activities based on end times, which is used to sort the activities in increasing order of end times.

The maxActivities function takes a vector of activities as input and returns the maximum number of activities that can be performed. It first sorts the activities using the compare function. It then iterates through the sorted activities, selecting activities whose start time is greater than or equal to the end time of the last selected activity. It keeps track of the count of selected activities and the end time of the last selected activity.

In the main function, we first take the input for the number of activities and the start and end times of each activity. We then call the maxActivities function to get the maximum number of activities that can be performed and print the result.

The time complexity of this implementation is O(nlogn) due to the sorting step. The space complexity is O(n) to store the vector of activities.

In comparison, a brute force approach would have a time complexity of O(2^n) as it would have to consider all possible combinations of activities. A greedy approach like this one has a better time complexity and can give an optimal solution in certain cases. However, it may not always give the optimal solution in all cases. */