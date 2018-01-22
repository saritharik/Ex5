#ifndef EX5_THREADPOOL_H
#define EX5_THREADPOOL_H

#include "Task.h"
#include <queue>
#include <pthread.h>
using namespace std;

class ThreadPool {
public:
    /**
     * Constructor.
     * @param threadsNum - num of threads.
     */
    ThreadPool(int threadsNum);
    /**
     * Add task to queue.
     * @param task - to add.
     */
    void addTask(Task* task);
    /**
     * Terminate.
     */
    void terminate();
    /**
     * D'tor.
     */
    virtual ~ThreadPool();

private:
    queue<Task*> taskQueue;
    pthread_t* threads;
    void executeTasks();
    bool stopped;
    pthread_mutex_t lock;

    /**
     * Execute tasks.
     * @param arg - to activate the function.
     * @return void *.
     */
    static void *execuete(void *arg);
};


#endif //EX5_THREADPOOL_H
