#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void *thread_function(void *arg) {
    int *result = malloc(sizeof(int)); // Speicher für das Ergebnis reservieren
    *result = 42; // Einige Berechnungen, setzen des Ergebnisses
    return result; // Rückgabe als void*
}

int main() {
    pthread_t thread_id;
    void *thread_result;

    pthread_create(&thread_id, NULL, thread_function, NULL);
    pthread_join(thread_id, &thread_result);

    printf("Thread beendet mit Ergebnis: %d\n", *(int *)thread_result);
    free(thread_result); // Freigabe des reservierten Speichers
    return 0;
}
