#include "Task.h"
#include <iostream>
using namespace std;

Task::Task(void * (*func)(void *arg), void *arg) :
        func(func), arg(arg) {}

void Task::execute() {
        func(arg);
}

Task::~Task() {}