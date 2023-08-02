#include <iostream>
#include <vector>
#include <random>
#include <chrono>

#define MAX_PROCESSES 5
#define MAX_RESOURCES_A 10
#define MAX_RESOURCES_B 15
#define MAX_RESOURCES_C 8
#define TIME_SLICE 3

enum class ProcessState { WAIT, RUN, BLOCK, FINISH };

class PCB {
public:
    std::string name;
    int total_resources;
    int allocated_resources;
    ProcessState state;

    PCB(const std::string& pname) : name(pname), total_resources(0), allocated_resources(0), state(ProcessState::WAIT) {}
};

std::vector<PCB> processes;
int available_resources_A = MAX_RESOURCES_A;
int available_resources_B = MAX_RESOURCES_B;
int available_resources_C = MAX_RESOURCES_C;

int getRandomNumber(int min, int max) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(min, max);
    return dis(gen);
}

void createProcess(PCB& process) {
    process.total_resources = getRandomNumber(1, 10);
    process.allocated_resources = 0;
    process.state = ProcessState::WAIT;
}

void requestResources(PCB& process) {
    int requested_A = getRandomNumber(1, process.total_resources - process.allocated_resources);
    int requested_B = getRandomNumber(1, process.total_resources - process.allocated_resources);
    int requested_C = getRandomNumber(1, process.total_resources - process.allocated_resources);

    if (requested_A <= available_resources_A && requested_B <= available_resources_B && requested_C <= available_resources_C) {
        available_resources_A -= requested_A;
        available_resources_B -= requested_B;
        available_resources_C -= requested_C;
        process.allocated_resources += requested_A + requested_B + requested_C;

        if (process.allocated_resources == process.total_resources) {
            process.state = ProcessState::FINISH;
            std::cout << "Process " << process.name << " completed." << std::endl;
        }
        else {
            process.state = ProcessState::RUN;
            std::cout << "Process " << process.name << " is running." << std::endl;
        }
    }
    else {
        process.state = ProcessState::BLOCK;
        std::cout << "Process " << process.name << " is blocked." << std::endl;
    }
}

void releaseResources(PCB& process) {
    available_resources_A += process.allocated_resources;
    available_resources_B += process.allocated_resources;
    available_resources_C += process.allocated_resources;
    process.allocated_resources = 0;
}

void schedule() {
    int current_process = -1;
    int time_remaining = TIME_SLICE;

    std::cout << "----- Scheduling -----" << std::endl;

    while (true) {
        if (current_process == -1) {
            // Find the next process in the WAIT state
            for (size_t i = 0; i < processes.size(); i++) {
                if (processes[i].state == ProcessState::WAIT) {
                    current_process = i;
                    processes[i].state = ProcessState::RUN;
                    std::cout << "Process " << processes[i].name << " is running." << std::endl;
                    break;
                }
            }
        }

        if (current_process != -1) {
            time_remaining--;

            if (time_remaining == 0) {
                processes[current_process].state = ProcessState::WAIT;
                std::cout << "Process " << processes[current_process].name << " is waiting." << std::endl;
                current_process = -1;
                time_remaining = TIME_SLICE;
            }
        }

        // Check if any processes need to be unblocked
        for (size_t i = 0; i < processes.size(); i++) {
            if (processes[i].state == ProcessState::BLOCK) {
                requestResources(processes[i]);
            }
        }

        // Check if any processes have completed
        for (size_t i = 0; i < processes.size(); i++) {
            if (processes[i].state == ProcessState::FINISH) {
                releaseResources(processes[i]);
                createProcess(processes[i]);
                std::cout << "New process " << processes[i].name << " created." << std::endl;
            }
        }

        // Print the current status
        std::cout << "----- Current Status -----" << std::endl;
        std::cout << "Running process: " << (current_process == -1 ? "None" : processes[current_process].name) << std::endl;
        std::cout << "Ready processes: ";
        for (const PCB& process : processes) {
            if (process.state == ProcessState::WAIT) {
                std::cout << process.name << " ";
            }
        }
        std::cout << std::endl;
        std::cout << "Blocked processes: ";
        for (const PCB& process : processes) {
            if (process.state == ProcessState::BLOCK) {
                std::cout << process.name << " ";
            }
        }
        std::cout << std::endl;
        std::cout << "Completed processes: ";
        for (const PCB& process : processes) {
            if (process.state == ProcessState::FINISH) {
                std::cout << process.name << " ";
            }
        }
        std::cout << std::endl << std::endl;

        // Sleep for 1 second
        //std::this_thread::sleep_for(std::chrono::seconds(1));
    }
}

int main() {
    // Create initial processes
    for (int i = 0; i < MAX_PROCESSES; i++) {
        std::string name = "P" + std::to_string(i + 1);
        processes.emplace_back(name);
        createProcess(processes[i]);
        std::cout << "Process " << processes[i].name << " created." << std::endl;
    }

    // Run the scheduler
    schedule();

    return 0;
}
