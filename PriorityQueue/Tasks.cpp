// I want to make a priority queue that can be used for tasks management
// there are 3 levels of priority: WHENEVER, IMPORTANT, URGENT
// URGENT tasks should be done first, then IMPORTANT, then WHENEVER
// If there are multiple tasks of the same difficulty, do them in the order they were added
// If there are no tasks left, print "No tasks left"

#include <iostream>

enum Priority { WHENEVER, IMPORTANT, URGENT };
// EASY = 0, MEDIUM = 1, HARD = 2

class Task {
    public:
        Task(std::string name, Priority priority);
        std::string getName();
        std::string getPriority();
    private:
        std::string name;
        Priority priority;
        Task* next;
        friend class TaskManager;
};

class TaskManager {
    public:
        TaskManager();
        void addTask(Task* task);
        void seeTasks();
        void seeTasks(Priority priority);
        void doTask(); // remove the task from the queue
        // easy tasks should be done first, then medium, then hard
        int getSize();

    private:
        Task* head;
        Task* tail;
        int size;
};

// Task class methods
Task::Task(std::string name, Priority priority) {
    this->name = name;
    this->priority = priority;
    this->next = nullptr;
}

std::string Task::getName() {
    return this->name;
}

std::string Task::getPriority() {
    if (this->priority == WHENEVER) {
        return "WHENEVER";
    } else if (this->priority == IMPORTANT) {
        return "IMPORTANT";
    } else if (this->priority == URGENT) {
        return "URGENT";
    }
}

// ----------------------------------------------

// TaskManager class methods
TaskManager::TaskManager() {
    head = nullptr;
    tail = nullptr;
    size = 0;
}

void TaskManager::addTask(Task* task) {
    // WITH PRIORITY
    // check if the list is empty
    if (head == nullptr) {
        head = task;
        tail = task;
    } else {
        // create 2 pointers to traverse the list
        Task* curr = head;
        Task* prev = nullptr;
        // traverse the list until we find a task with a higher priority
        while (curr != nullptr && curr->priority >= task->priority) {
            prev = curr;
            curr = curr->next;
        }
        // if we are at the end of the list, add the task to the end
        if (curr == nullptr) {
            tail->next = task;
            tail = task;
            return;
        }

        // if we are at the beginning of the list, add the task to the beginning
        if (prev == nullptr) {
            task->next = head;
            head = task;
            return;
        }

        // if we are in the middle of the list, add the task in the middle
        prev->next = task;
        task->next = curr;
    }
    size++;
}

void TaskManager::doTask() {
    if (head == nullptr) {
        std::cout << "No tasks left" << std::endl;
        return;
    }
    Task* temp = head;
    head = head->next;
    delete temp;
    size--;
}

void TaskManager::seeTasks() {
    Task* temp = head;
    while (temp != nullptr) {
        std::cout << temp->name << "\t" << temp->getPriority() << std::endl;
        temp = temp->next;
    }
    std::cout << std::endl;
}

void TaskManager::seeTasks(Priority priority) {
    Task* temp = head;
    while (temp != nullptr) {
        if (temp->priority == priority) { // SIMPLY ADD THIS LINE
            std::cout << temp->name << std::endl;
        }
        temp = temp->next;
    }
    std::cout << std::endl;
}

int TaskManager::getSize() {
    return size;
}

// ----------------------------------------------

// Test cases with main
int main() {
    // create a task manager
    TaskManager* TM = new TaskManager();

    // create some tasks
    Task* task1 = new Task("Task 1", URGENT);
    Task* task2 = new Task("Task 2", IMPORTANT);
    Task* task3 = new Task("Task 3", IMPORTANT);
    Task* task4 = new Task("Task 4", WHENEVER);
    Task* task5 = new Task("Task 5", IMPORTANT);

    // add the tasks to the task manager
    TM->addTask(task1);
    TM->addTask(task2);
    TM->addTask(task3);

    // see the tasks
    TM->seeTasks();

    // add more tasks
    TM->addTask(task4);
    TM->addTask(task5);

    // see the tasks
    TM->seeTasks();

    // see the IMPORTANT tasks
    TM->seeTasks(IMPORTANT);
    // see the URGENT tasks
    TM->seeTasks(URGENT);

    // do the tasks
    TM->doTask();
    TM->doTask();

    // see the tasks
    TM->seeTasks();
}

// how to compile:
// g++ Tasks.cpp -o Tasks.exe
// ./Tasks.exe