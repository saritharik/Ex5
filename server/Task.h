#ifndef EX5_TASK_H
#define EX5_TASK_H
class Task {
public:
    /**
     * Constructor.
     * @param func - function to activate.
     * @param arg - arguments to function.
     */
    Task(void * (*func)(void *arg), void *arg);
    /**
     * Activate the function.
     */
    void execute();
    /**
     * D'tor.
     */
    virtual ~Task();
private:
    void * (*func)(void *arg);
    void *arg;
};
#endif //EX5_TASK_H
