//
// Created by sarit on 21/01/18.
//

#include "ThreadPool.h"
#include <unistd.h>

ThreadPool::ThreadPool(int threadsNum): stopped(false) {
    threads = new pthread_t[threadsNum];
    for (int i = 0; i < threadsNum; i++) {
        pthread_create(threads + i, NULL, execuete, this);
    }
    pthread_mutex_init(&lock, NULL);
}

void* ThreadPool::execuete(void *arg) {
    ThreadPool *pool = (ThreadPool *)arg;
    pool->executeTasks();
}

void ThreadPool::addTask(Task *task) {
    taskQueue.push(task);
}

void ThreadPool::executeTasks() {
    while (!stopped) {
        pthread_mutex_lock(&lock);
        if (!taskQueue.empty()) {
            Task *task = taskQueue.front();
            taskQueue.pop();
            pthread_mutex_unlock(&lock);
            task->execute();
        } else {
            pthread_mutex_unlock(&lock);
            sleep(1);
        }
    }
}

void ThreadPool::terminate() {
    pthread_mutex_destroy(&lock);
    stopped = true;
}

ThreadPool::~ThreadPool() {

    for (int i = 0; i < 5; i++) {
        pthread_cancel(threads[i]);
    }
    delete[] threads;
}