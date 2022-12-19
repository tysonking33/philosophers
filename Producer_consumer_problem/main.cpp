struct semaphore {
    enum value(0, 1);
 
    // q contains all Process Control Blocks (PCBs)
    // corresponding to processes got blocked
    // while performing down operation.
    Queue<process> q;
 
}

Sleep(semaphore s){
    if (s.value == 1) {
        s.value = 0;
    }
    else {
        // add the process to the waiting queue
        q.push(P) sleep();
    }
}

Wake_up(Semaphore s)
{
    if (s.q is empty) {
        s.value = 1;
    }
    else {
 
        // select a process from waiting queue
        Process p = q.front();
        // remove the process from waiting as it has been
        // sent for CS
        q.pop();
        wakeup(p);
    }
}

int main()
{
    //kinitalise prod
    do{

        //produce an item

        wait(empty);
        wait(mutex);

        //place in buffer

        signal(mutex);
        signal(full);

    }while(true)

    //initalise cons
    do{

        wait(full);
        wait(mutex);

        // consume item from buffer

        signal(mutex);
        signal(empty);


    }while(true)
}


