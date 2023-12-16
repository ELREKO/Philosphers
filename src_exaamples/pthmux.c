#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

pthread_mutex_t lock;

typedef struct {
    char* text;
    int iterations;
} ThreadArgs;

void* write_to_console(void* arg) {
    ThreadArgs* args = (ThreadArgs*) arg;

    for (int i = 0; i < args->iterations; ++i) {
        pthread_mutex_lock(&lock);

        printf("%s Iteration %d\n", args->text, i + 1);
        // Optional: Kurze Pause
        pthread_mutex_unlock(&lock);
    }

    return NULL;
}

int main() {
    pthread_t thread1, thread2;
    ThreadArgs args1 = {"Thread 1: Hallo!", 4};
    ThreadArgs args2 = {"Thread 2: Hallo Word!", 4};

    // Initialisierung des Mutex
    if (pthread_mutex_init(&lock, NULL) != 0) {
        printf("Mutex-Initialisierung fehlgeschlagen\n");
        return 1;
    }

    // Erstellen von zwei Threads
    pthread_create(&thread1, NULL, write_to_console, &args1);
    pthread_create(&thread2, NULL, write_to_console, &args2);

    // Warten auf das Ende der Threads
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    args1.iterations = 1;
    args1.text = "Neuer Test"; 
    pthread_create(&thread1, NULL, write_to_console, &args1);
    pthread_join(thread1, NULL);

    // Zerstören des Mutex
    pthread_mutex_destroy(&lock);

    return 0;
}
