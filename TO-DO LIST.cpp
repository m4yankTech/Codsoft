#include <iostream>
#include <vector>
#include <string>

// Task structure to hold task information
struct Task {
    std::string description;
    bool completed;

    Task(const std::string& desc) : description(desc), completed(false) {}
};

// Function prototypes
void displayMenu();
void addTask(std::vector<Task>& tasks);
void viewTasks(const std::vector<Task>& tasks);
void markTaskCompleted(std::vector<Task>& tasks);
void removeTask(std::vector<Task>& tasks);

int main() {
    std::vector<Task> tasks;
    int choice;

    while (true) {
        displayMenu();
        std::cin >> choice;
        std::cin.ignore();  // Ignore the newline character left in the input buffer

        switch (choice) {
            case 1:
                addTask(tasks);
                break;
            case 2:
                viewTasks(tasks);
                break;
            case 3:
                markTaskCompleted(tasks);
                break;
            case 4:
                removeTask(tasks);
                break;
            case 5:
                std::cout << "Exiting the To-Do List Manager. Goodbye!" << std::endl;
                return 0;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
                break;
        }
    }

    return 0;
}

void displayMenu() {
    std::cout << "\nTo-Do List Manager\n";
    std::cout << "1. Add Task\n";
    std::cout << "2. View Tasks\n";
    std::cout << "3. Mark Task as Completed\n";
    std::cout << "4. Remove Task\n";
    std::cout << "5. Exit\n";
    std::cout << "Enter your choice: ";
}

void addTask(std::vector<Task>& tasks) {
    std::string description;
    std::cout << "Enter task description: ";
    std::getline(std::cin, description);
    tasks.push_back(Task(description));
    std::cout << "Task added successfully." << std::endl;
}

void viewTasks(const std::vector<Task>& tasks) {
    if (tasks.empty()) {
        std::cout << "No tasks to display." << std::endl;
        return;
    }

    std::cout << "\nTo-Do List:\n";
    for (size_t i = 0; i < tasks.size(); ++i) {
        std::cout << i + 1 << ". " << tasks[i].description 
                  << " [" << (tasks[i].completed ? "Completed" : "Pending") << "]" << std::endl;
    }
}

void markTaskCompleted(std::vector<Task>& tasks) {
    if (tasks.empty()) {
        std::cout << "No tasks to mark as completed." << std::endl;
        return;
    }

    int taskNumber;
    std::cout << "Enter task number to mark as completed: ";
    std::cin >> taskNumber;

    if (taskNumber > 0 && taskNumber <= tasks.size()) {
        tasks[taskNumber - 1].completed = true;
        std::cout << "Task marked as completed." << std::endl;
    } else {
        std::cout << "Invalid task number." << std::endl;
    }
}

void removeTask(std::vector<Task>& tasks) {
    if (tasks.empty()) {
        std::cout << "No tasks to remove." << std::endl;
        return;
    }

    int taskNumber;
    std::cout << "Enter task number to remove: ";
    std::cin >> taskNumber;

    if (taskNumber > 0 && taskNumber <= tasks.size()) {
        tasks.erase(tasks.begin() + taskNumber - 1);
        std::cout << "Task removed successfully." << std::endl;
    } else {
        std::cout << "Invalid task number." << std::endl;
    }
}

