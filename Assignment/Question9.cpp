//  Develop a greedy algorithm for the Job Scheduling Problem, and evaluate its
// effectiveness on a variety of input instances.

/*
The Job Scheduling Problem is a classic optimization problem in computer science. In this problem, we are given a set of jobs, each with a specific processing time and a deadline by which it must be completed. The goal is to schedule the jobs in such a way that we meet all the deadlines and minimize the total time taken to complete all the jobs.

One approach to solving the Job Scheduling Problem is to use a greedy algorithm. The basic idea is to sort the jobs in decreasing order of their processing times and then schedule them in that order, starting with the earliest possible start time for each job. This approach is known as the "Earliest Deadline First" (EDF) algorithm.

*/


#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Job {
    int id;
    int processing_time;
    int deadline;
};

bool compare_jobs(const Job& j1, const Job& j2) {
    return j1.processing_time > j2.processing_time;
}

vector<int> schedule_jobs(vector<Job>& jobs) {
    sort(jobs.begin(), jobs.end(), compare_jobs);
    int current_time = 0;
    vector<int> schedule;
    for (int i = 0; i < jobs.size(); i++) {
        if (current_time + jobs[i].processing_time <= jobs[i].deadline) {
            schedule.push_back(jobs[i].id);
            current_time += jobs[i].processing_time;
        }
    }
    return schedule;
}

int main() {
    vector<Job> jobs = {
        {1, 4, 7},
        {2, 3, 3},
        {3, 1, 1},
        {4, 2, 4},
        {5, 5, 10}
    };
    vector<int> schedule = schedule_jobs(jobs);
    cout << "Job schedule: ";
    for (int i = 0; i < schedule.size(); i++) {
        cout << schedule[i] << " ";
    }
    cout << endl;
    return 0;
}

/*
In this implementation, we define a Job struct that stores the id, processing time, and deadline for each job. We also define a comparison function compare_jobs that sorts the jobs in decreasing order of their processing times.

The schedule_jobs function takes a vector of jobs as input and returns a vector of job ids representing the schedule. It first sorts the jobs using the compare_jobs function, and then iterates through the jobs in that order, adding each job to the schedule if its deadline has not yet been exceeded.

In the main function, we create a vector of jobs and call the schedule_jobs function to generate a schedule. We then print out the schedule to the console.

The time complexity of this algorithm is O(nlogn), where n is the number of jobs, due to the sorting step. The space complexity is O(n), since we need to store the sorted list of jobs and the schedule vector.

The effectiveness of this algorithm depends on the input instances. In general, the EDF algorithm performs well when the processing times are relatively short compared to the deadlines, since it prioritizes jobs with short processing times. However, if there are jobs with very tight deadlines or very long processing times, the EDF algorithm may not be able to meet all the deadlines. In such cases, more complex scheduling algorithms may be required.*/