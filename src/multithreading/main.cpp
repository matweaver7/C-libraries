#include <iostream>
#include <pthread.h>


#define NUM_THREADS 1
bool shouldFire = true;

void* stuff(void* arg) {
    std::cout << "Type \"exit\" to close." << std::endl;
    bool keepGoing = true;
    while(keepGoing) {
        std::string name;
        std::cin >> name;
        std::cout << "You entered: " << name << std::endl;
        if (name == "exit") {
            keepGoing = false;
        }
    }

    shouldFire = false;

    pthread_exit(0);
}

int main() {
    int sum = 0;
    pthread_t threads[NUM_THREADS];
    

    for(int i = 0; i < NUM_THREADS; i++ ) {
        std::cout << "starting thread: " << i << std::endl;
        pthread_create(&threads[i], NULL, stuff, NULL);
    }

    while (shouldFire) {
        sum += 1;
    }
    
    for (int i = 0; i < NUM_THREADS; i++ ) {
        pthread_join(threads[i], NULL);
    }


    
    
    std::cout << "sum turned out to be: " << sum << std::endl;
    return 0;
}
