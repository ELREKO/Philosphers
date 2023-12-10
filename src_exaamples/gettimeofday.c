#include <stdio.h>
#include <sys/time.h>

int main() {
    struct timeval start, end;

    // Startzeit messen
    gettimeofday(&start, NULL);

    /*Code zum messeen*/
    for (int i = 0; i<= 1000 ; ++i )
        printf("count %d\n", i);

    // Endzeit messen
    gettimeofday(&end, NULL);

    // Berechne die vergangene Zeit in Sekunden und Mikrosekunden
    long seconds = end.tv_sec - start.tv_sec;
    long microseconds = end.tv_usec - start.tv_usec;
    
    // Falls die Mikrosekunden negativ sind, korrigiere dies
    if (microseconds < 0) {
        seconds--;
        microseconds += 1000000;
    }

    // Ausgabe der vergangenen Zeit
    printf("Time elapsed: %ld seconds and %ld microseconds\n", seconds, microseconds);

    
    return 0;
}