#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <type_traits>

template <typename T>
struct Context
{
    T *data = nullptr;
    bool isAborted = false;
};

template <typename T>
class TaskBoard
{
private:
    int size = 0;
    Context<T> c;
    void (**tasks)(Context<T> *) = nullptr;

public:
    TaskBoard(/* args */) {

    };
    ~TaskBoard()
    {
        this->size = 0;
        delete this->c.data;
        delete this->tasks;
    };

public:
    void push_task(void (*f)(Context<T> *))
    {
        this->size++;
        this->tasks = (void (**)(Context<T> *))realloc(this->tasks, this->size * sizeof(void (*)(Context<T> *)));
        this->tasks[size - 1] = f;
    }
    void pop_task()
    {
        this->size--;
        this->tasks = (void (**)(Context<T> *))realloc(this->tasks, this->size * sizeof(void (*)(Context<T> *)));
    }
    void execute()
    {
        this->c.isAborted = false;
        for (int i = 0; i < this->size; i++)
        {
            this->tasks[i](&this->c);
            if (this->c.isAborted)
            {
                printf("Error at handler No.%d\n", i);
                if (std::is_same<T, int>::value)
                {
                    *this->c.data = -1;
                }
                return;
            }
        }
    }
    T get_data()
    {
        return *this->c.data;
    }
};

void add1(Context<int> *c)
{
    if (c->data == nullptr)
    {
        c->data = new int(1);
        return;
    }
    (*c->data)++;
}
void add2(Context<int> *c)
{
    if (c->data == nullptr)
    {
        c->data = new int(2);
        return;
    }
    *c->data += 2;
}
void add5(Context<int> *c)
{
    if (c->data == nullptr)
    {
        c->data = new int(5);
        return;
    }
    // Put this line in anywhere you want
    c->isAborted = true;
    *c->data += 5;
}

int main()
{
    TaskBoard<int> c;
    c.push_task(add1);
    c.push_task(add1);
    c.push_task(add2);
    c.push_task(add5);
    c.execute();
    int a = c.get_data();
    printf("Result is %d\n", a);

    c.pop_task();
    c.execute();
    a = c.get_data();
    printf("Result is %d\n", a);
}