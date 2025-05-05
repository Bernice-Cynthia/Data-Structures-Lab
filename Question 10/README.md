An operating system allocates a fixed time slot of CPU time for processes using a round-robin scheduling algorithm.
The fixed time slot will be initialized before the start of the menu-driven program. Implement the round-robin scheduling algorithm using the circular linked list. 

Include the appropriate header file. The program should offer the following operations:

1. Insert Process
2. Execute
3. Exit

The "Insert Process" operation gets an integer time from the user and adds it to the queue.

The "Execute" operation deletes from the beginning, subtracts the fixed time from the process.

If the processing time falls below 0, the process is considered complete.

Otherwise, the remaining time is inserted at the end of the circular linked list.
