# C++ Concurrency and Process Management Tasks

This repository contains five C++ programming tasks focusing on **multithreading**, **multiprocessing**, **synchronization**, and **scheduling**. The problems simulate real-world systems in software engineering, finance, operating systems, and education.

## Tasks Overview

1. **Round Robin Task Management System**  
   Implements a round robin scheduler to assign tasks to team members (engineers, testers, managers) based on their availability and skills, ensuring fair workload distribution.

2. **Concurrent Financial Transactions**  
   Uses multiple threads to handle concurrent banking operations:
   - Deduct amount
   - Add amount to recipient
   - Calculate transaction fees
   - Update transaction history
   - Send notifications  
   Includes synchronization to protect critical sections.

3. **Dining Philosophers with Multiple Tables**  
   Simulates philosophers seated at multiple tables with limited forks using threads and semaphores to prevent conflicts at the same table while allowing parallel eating across tables.

4. **Multithreaded Workplace Simulation**  
   Simulates task flow across three rooms:
   - **Reception:** Reads and queues tasks.
   - **Dispatcher:** Assigns units of execution (Unit 0–4) to process task values.
   - **Units:** Perform specific computations.
   - **Print Room:** Outputs results in FCFS order.  
   Uses `clock_gettime` or `gettimeofday` for timing.

5. **Multi-Process + Multi-Thread Student Data Processing**  
   Multi-process design where:
   - **Process A:** Calculates average grade.
   - **Process B:** Identifies students needing counseling.
   - **Process C:** Sorts students by grade.  
   Each process creates threads to process student data subsets in parallel.

## Requirements
- C++17 or later
- POSIX Threads (`pthread`)
- Linux/Unix environment

## Compilation Example
```bash
g++ task1.cpp -o task1 -lpthread
./task1
