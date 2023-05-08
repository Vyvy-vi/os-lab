#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Process;

queue<Process *> completed_queue;

class Process
{
public:
    string name;
    int arrival_time;
    int estimated_run_time;
    int remaining_time;
    int waiting_time;
    float priority;

    Process(string name, int arrival_time, int burst_time)
    {
        this->name = name;
        this->arrival_time = arrival_time;
        this->estimated_run_time = burst_time;
        this->remaining_time = burst_time;
        this->waiting_time = 0;
        this->priority = 1;
    }

    void run()
    {
        this->remaining_time--;
        if (this->remaining_time == 0)
        {
            cout << this->name << " completed." << endl;
            completed_queue.push(this);
        }
        else
        {
            cout << this->name << " running." << endl;
            this->priority = 1 + (float)this->waiting_time / this->estimated_run_time;
        }
    }

    void wait()
    {
        this->waiting_time++;
        this->priority = 1 + (float)this->waiting_time / this->estimated_run_time;
    }
};

vector<Process> get_processes()
{
    vector<Process> processes;
    while (true)
    {
        string name;
        int arrival_time, burst_time;
        cout << "Enter process name (or 'q' to quit): ";
        cin >> name;
        if (name == "q")
        {
            break;
        }
        cout << "Enter arrival time: ";
        cin >> arrival_time;

        cout << "Enter burst time: ";
        cin >> burst_time;

        processes.push_back(Process(name, arrival_time, burst_time));
    }
    return processes;
}

bool operator<(const Process &p1, const Process &p2)
{
    return p1.priority > p2.priority;
}

void run_priority_scheduling(vector<Process> processes)
{
    priority_queue<Process> ready_queue;

    int current_time = 0;
    float total_waiting_time = 0;

    while (!ready_queue.empty() && !processes.empty())
    {
        // Add newly arrived processes to the ready queue
        while (!processes.empty() && processes.back().arrival_time <= current_time)
        {
            ready_queue.push(processes.back());
            processes.pop_back();
        }

        if (ready_queue.empty())
        {
            // No processes to run, wait for the next one to arrive
            current_time = processes.back().arrival_time;
        }
        else
        {
            // Run the highest priority process from the ready queue
            Process current_process = ready_queue.top();
            ready_queue.pop();

            // Update waiting time for all other processes in the ready queue
            while (!ready_queue.empty())
            {
                Process p = ready_queue.top();
                p.wait();
                ready_queue.pop();
            }

            current_process.run();
            for (auto p : processes)
                cout << p.name << " " << p.priority << " ";
            cout << endl;
            current_time++;

            // Add back the current process if it still has some remaining time
            if (current_process.remaining_time > 0)
            {
                ready_queue.push(current_process);
            }
            else
            {
                total_waiting_time += current_process.waiting_time;
            }
        }
    }

    float avg_waiting_time = total_waiting_time / processes.size();

    cout << "Average waiting time: " << avg_waiting_time << endl;
}

int main()
{
    vector<Process> processes = get_processes();

    run_priority_scheduling(processes);

    return 0;
}