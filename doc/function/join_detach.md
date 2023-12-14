# Compaer pthread_join and pthread_detach

| Criteria             | pthread_join                                          | pthread_detach                                      |
|----------------------|------------------------------------------------------|-----------------------------------------------------|
| **Purpose**          | Waits for a thread to finish and retrieves the thread's exit status. | Detaches the thread, allowing it to run independently and clean up upon completion. |
| **Behavior**         | Blocks the calling thread until the specified thread terminates. | Allows the specified thread to release its resources automatically once it terminates. |
| **Return Value**     | Allows capturing the return value of the finished thread. | No return value from the thread is captured. |
| **Resource Release** | The calling thread must wait for the finished thread to release its resources. | The thread releases its resources automatically upon termination. |
| **Invocation**       | Can be called once for each non-detached thread. | Can be called once for each thread, before it terminates. |
| **Synchronization**  | Used for synchronization between threads. | No direct synchronization between threads. |
| **Typical Use**      | In situations where the output of a thread or its proper completion is important for the program's further execution. | In situations where the thread operates in the background and its result or exact termination time is not critical for the program's further execution. |
| **Error Handling**   | Need to check if the thread has terminated successfully. | Need to check if the thread has been successfully detached. |

---
< [back to funtion overview](../function.md)