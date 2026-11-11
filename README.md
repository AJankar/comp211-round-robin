# COMP 211 Checkoff 3 - Round-Robin Scheduling

This project explores how Round-Robin scheduling shares one CPU between processes. A short C simulation shows how changing the time slice affects when each process runs.

## How it works

Each ready process gets up to one time slice per turn. A process that still has work left goes to the back of the ready queue. A finished process leaves the queue.

All three processes are ready at time 0, in the order A, B, C.

| Process | CPU time needed |
| --- | --- |
| A | 5 units |
| B | 3 units |
| C | 1 unit |

The simulation cycles through an array and skips finished processes. This reproduces the ready-queue order for this fixed example, where all processes arrive together and have one CPU burst each.

## Run the program

You need a C compiler such as Clang or GCC.

Compile and run with GCC.

```sh
gcc -std=c11 -Wall -Wextra round_robin.c -o round_robin
./round_robin
```

## Change the time slice

Edit this variable inside `main` in `round_robin.c`.

```c
int quantum = 2;
```

Set it to a positive whole number, save, recompile, and run again. Each run uses the time slice you selected.

## Results

| Time slice | Execution timeline | B's first turn | Switches between processes |
| --- | --- | --- | --- |
| 2 units | A 0-2, B 2-4, C 4-5, A 5-7, B 7-8, A 8-9 | Time 2 | 5 |
| 4 units | A 0-4, B 4-7, C 7-8, A 8-9 | Time 4 | 3 |

The initial dispatch to A is excluded from the switch counts.

## What this example shows

- A time slice is the maximum allowed turn length. With a 2-unit slice, C finishes after using only 1 unit.
- B gets its first turn sooner with the 2-unit slice.
- The 2-unit run switches between processes more often.
- Both runs finish at time 9 because the total CPU work is 9 units and this simulation gives process switches zero time cost.

In a real system, switching processes takes time. The choice of time slice affects responsiveness and switching overhead. This simulation focuses on the execution order and assumes all processes arrive at time 0.

## Presentation

The presentation explains the scheduling rule, traces the 2-unit example, and compares the 2-unit and 4-unit runs. The final slides PDF will be added to this repository.

## Learning resources and AI use

- COMP 211 Checkoff 3 assignment instructions.
- ChatGPT explanations, hand-traced scheduling questions, and C code walkthrough during this project.

AI helped explain the topic, develop the code, and compare the timelines. The required written reflection separately documents the actual prompts and learning process.
