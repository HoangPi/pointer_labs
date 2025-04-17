#include <stdio.h>
#include <stdbool.h>

struct Context{
    void *data = nullptr;
    bool isAborted = false;
};

void handler1(Context *c){
    if(c->isAborted){
        printf("Something happened, context is aborted\n");
        return;
    }
    // insert you handler logics here
    printf("This is handler1\n");
}
void handler2(Context *c){
    if(c->isAborted){
        printf("Something happened, context is aborted\n");
        return;
    }
    // insert you handler logics here
    printf("This is handler2\n");

    // Assume, something happends here
    if(true){
        c->isAborted = true;
        return;
    }
}
void handler3(Context *c){
    if(c->isAborted){
        printf("Something happened, context is aborted\n");
        return;
    }
    // insert you handler logics here
    printf("This is handler3\n");
}
int main(){
    Context c;
    handler1(&c);
    handler2(&c);
    handler3(&c);
}