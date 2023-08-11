Algorithms/Branch and Bound/Job_Scheduling.cppa#include <iostream>
#include <vector>
#include <algorithm>

// Structure to represent a job
struct Job {
    int id;
    int deadline;
    int profit;
};

// Compare function for sorting jobs based on profit in descending order
bool compareJobs(const Job& a, const Job& b) {
    return a.profit > b.profit;
}

// Function to schedule jobs using a greedy algorithm
void scheduleJobs(std::vector<Job>& jobs) {
    // Sort the jobs based on profit in descending order
    std::sort(jobs.begin(), jobs.end(), compareJobs);

    int n = jobs.size();
    int maxDeadline = 0;
    for (int i = 0; i < n; ++i) {
        maxDeadline = std::max(maxDeadline, jobs[i].deadline);
    }

    std::vector<int> slots(maxDeadline, -1);
    std::vector<int> selectedJobs;

    // Schedule the jobs greedily
    for (int i = 0; i < n; ++i) {
        int deadline = jobs[i].deadline;
        // Find the nearest slot available before the deadline
        for (int j = deadline - 1; j >= 0; --j) {
            if (slots[j] == -1) {
                slots[j] = jobs[i].id;
                selectedJobs.push_back(jobs[i].id);
                break;
            }
        }
    }

    // Display the selected jobs
    std::cout << "Selected Jobs: ";
    for (int i = 0; i < selectedJobs.size(); ++i) {
        std::cout << selectedJobs[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::vector<Job> jobs = {
        {1, 2, 100},
        {2, 1, 19},
        {3, 2, 27},
        {4, 1, 25},
        {5, 3, 15}
    };

    scheduleJobs(jobs);

    return 0;
}
