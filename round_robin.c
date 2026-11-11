#include <stdio.h>

static void simulate_round_robin(int quantum) {
    const char names[] = {'A', 'B', 'C'};
    int remaining[] = {5, 3, 1};
    const size_t process_count = sizeof remaining / sizeof remaining[0];
    size_t unfinished = process_count;
    int time = 0;

    printf("Time slice: %d units\n", quantum);

    while (unfinished > 0) {
        for (size_t i = 0; i < process_count; i++) {
            if (remaining[i] == 0) {
                continue;
            }

            int run_time = quantum;
            if (remaining[i] < quantum) {
                run_time = remaining[i];
            }

            printf("%c runs from time %d to %d.\n",
                   names[i], time, time + run_time);

            time += run_time;
            remaining[i] -= run_time;

            if (remaining[i] == 0) {
                unfinished--;
            }
        }
    }

    printf("All processes finished at time %d.\n", time);
}

int main(void) {
    int quantum = 2;

    if (quantum <= 0) {
        fprintf(stderr, "The time slice must be a positive whole number.\n");
        return 1;
    }

    simulate_round_robin(quantum);
    return 0;
}
