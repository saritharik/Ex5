#ifndef EX5_TASK_H
#define EX5_TASK_H
class Task {
public:
    Task(void * (*func)(void *arg), void *arg) :
            func(func), arg(arg) {}
    void execute() {
        func(arg);
    }
    virtual ~Task() {}
private:
    void * (*func)(void *arg);
    void *arg;
};
#endif //EX5_TASK_H
