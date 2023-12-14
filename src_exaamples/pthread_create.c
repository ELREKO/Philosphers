#include <pthread.h>
#include <stdio.h>

// Thread-Funktion
void *do_work(void *arg) {
    char *test = (char*)arg;
    printf ("Das ist ein Test %s", test);
    return NULL;
}

int main() {
    pthread_t thread_id;
    int result;

    // Thread erstellen
    result = pthread_create(&thread_id, NULL, do_work, "Test");

    if (result != 0) {
        // Fehler beim Erstellen des Threads
    }

    // Warte auf die Beendigung des Threads
    pthread_join(thread_id, NULL);

    return 0;
}
