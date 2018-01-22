//
// Created by sarit on 21/01/18.
//

#ifndef EX5_THREADPOOL_H
#define EX5_THREADPOOL_H

#include "Task.h"
#include <queue>
#include <pthread.h>
using namespace std;

class ThreadPool {
public:
    ThreadPool(int threadsNum);
    void addTask(Task* task);
    void terminate();
    virtual ~ThreadPool();

private:
    queue<Task*> taskQueue;
    pthread_t* threads;
    void executeTasks();
    bool stopped;
    pthread_mutex_t lock;

    static void *execuete(void *arg);
};


#endif //EX5_THREADPOOL_H
