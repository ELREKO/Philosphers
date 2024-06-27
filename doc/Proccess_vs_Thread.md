# Difference between Thread and Process
- A **Process** is isolated and self-contained. A <u>CPU</u> can handle <u>only one process</u> at a time. This means that with only one CPU, multitasking is managed by "switching" between processes.

- One or more **Threads** are part of a process. Unlike processes, threads are not isolated, so a faulty thread can affect other threads within the same process.

## Overview

| Aspect                | Processes                                    | Threads                                     |
|-----------------------|----------------------------------------------|---------------------------------------------|
| **Definition**        | Independent execution contexts               | Execution contexts within a process         |
| **Resources**         | Own resources                                | Share resources within the same process     |
| **Isolation**         | Fully isolated                               | Less isolated; thread crash can affect the process |
| **Communication**     | Through IPC mechanisms (e.g., pipes, sockets)| Direct communication through shared variables |
| **Overhead**          | Higher overhead (more resources, time)       | Lower overhead, as resources are shared     |
| **Stability**         | More stable (crash of one process does not affect others) | More prone to crashes (crash of one thread can affect the entire process) |
| **Startup Time**      | Longer startup time (creation of new address space) | Shorter startup time (sharing existing resources) |

<p align="center">
  <img src="pic/Proccec_vs_thread.png" alt="Process vs Thread">
</p>


## Differences between User and Kernel Threads

| Aspect                | Kernel Threads                               | User-Level Threads                            |
|-----------------------|----------------------------------------------|-----------------------------------------------|
| **Management**        | Managed by the OS kernel                     | Managed at the user level (user space)        |
| **System Calls**      | Often require system calls (kernel operations) | Can operate without system calls unless accessing kernel resources | 
| **Overhead**          | Higher overhead due to direct kernel involvement | Lower overhead, as they are managed at the user level |
| **Parallelism**       | Can efficiently scale on multi-core systems  | Can have difficulties with parallelism on multi-core systems |
| **Flexibility**       | Better access to system resources and functions | Lightweight and faster in creating and terminating threads, but less control over resources |
| **Scheduling**        | Managed by the OS kernel's scheduling algorithm | Can be managed by the runtime library scheduler or application logic |
| **Visibility**        | OS has full control and visibility           | OS often has no direct knowledge of user-level threads, treating them as normal application processes |

<p align="center">
  <img src="pic/user_vs_kernel_thread.png" alt="User vs Kernel Thread">
</p>

## Problems with Multithreading

### Synchronization
- For example, if multiple threads write to the same output, it can result in mixed or incomplete output. Use mutexes (mutual exclusion locks), semaphores, or conditional variables to handle this.

### Race Conditions
The result of missing synchronization is race conditions. This occurs when two or more threads try to access the same resource simultaneously.

#### Deadlocks
A state where processes or threads are stuck in their current state due to mutual blocking. For example, this can happen when they are waiting for each other to release resources.

## Further Information
- [Mutex](mutex.md)
- [Function Description](function.md)

