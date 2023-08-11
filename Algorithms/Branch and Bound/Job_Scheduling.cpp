#include <iostream>
#include <vector>
#include <algorithm>

// Structure to represent a job
struct Job {
    int id;
    int processingTime;
    int deadline;


    
};

// Compare function for sorting jobs based on processing time in non-decreasing order
bool compareJobs(const Job& a, const Job& b) {
    return a.processingTime < b.processingTime;
}

// Function to compute the total delay of a schedule
int computeDelay(const std::vector<Job>& schedule) {
    int delay = 0;
    int currentTime = 0;

    for (const Job& job : schedule) {
        currentTime += job.processingTime;
        delay += std::max(0, currentTime - job.deadline);
    }

    return delay;
}

// Branch and bound algorithm for job scheduling
void jobSchedulingBranchAndBound(const std::vector<Job>& jobs, std::vector<Job>& currentSchedule,
                                 std::vector<Job>& bestSchedule, int& minDelay, int currentIndex) {
    // Base case: All jobs have been assigned
    if (currentIndex == jobs.size()) {
        int currentDelay = computeDelay(currentSchedule);

        if (currentDelay < minDelay) {
            minDelay = currentDelay;
            bestSchedule = currentSchedule;
        }

        return;
    }

    // Check if it's worth exploring this branch
    int currentLowerBound = computeDelay(currentSchedule);
    if (currentLowerBound >= minDelay) {
        return;
    }

    // Branching: Try assigning the current job to different positions in the schedule
    for (int i = 0; i <= currentSchedule.size(); ++i) {
        std::vector<Job> updatedSchedule = currentSchedule;
        updatedSchedule.insert(updatedSchedule.begin() + i, jobs[currentIndex]);

        jobSchedulingBranchAndBound(jobs, updatedSchedule, bestSchedule, minDelay, currentIndex + 1);
    }
}

int main() {
    std::vector<Job> jobs = {
        {1, 3, 6},
        {2, 2, 8},
        {3, 5, 4},
        {4, 4, 5},
        {5, 1, 7}
    };

    // Sort the jobs based on processing time in non-decreasing order
    std::sort(jobs.begin(), jobs.end(), compareJobs);

    std::vector<Job> currentSchedule;
    std::vector<Job> bestSchedule;
    int minDelay = INT_MAX;iff==
    // Run the branch and bound algorithm
    jobSchedulingBranchAndBound(jobs, currentSchedule, bestSchedule, minDelay, currentIndex);

    // Display the best schedule and its delay
    std::cout << "Best Schedule: ";
    for (const Job& job : bestSchedule) {
        std::cout << job.id << " ";
    }
    std::cout << std::endl;

    std::cout << "Minimum Delay: " << minDelay << std::endl;

    return 0;



}
