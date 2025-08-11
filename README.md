
#  What is a Deadlock?

In operating systems, a **deadlock** is a state where a group of processes are all waiting for resources that are held by other processes in the group. None of them can proceed, and the system gets stuck.

##  Four Necessary Conditions for Deadlock:
1. **Mutual Exclusion** – Only one process can use a resource at a time.
2. **Hold and Wait** – A process holding at least one resource is waiting to acquire additional resources.
3. **No Preemption** – A resource can’t be forcibly taken away from a process.
4. **Circular Wait** – A circular chain of processes exists, each waiting for a resource held by the next.

---

##  Deadlock Handling Strategies

| Strategy      | Description |
|---------------|-------------|
| **Prevention** | Alter system rules to ensure at least one of the four deadlock conditions cannot occur. |
| **Avoidance**  | Dynamically examine the resource allocation state to ensure the system will never enter a deadlock. |
| **Detection**  | Allow deadlocks to occur, then detect and recover. |
| **Recovery**   | Take action once a deadlock is detected — e.g., terminate or roll back processes. |

---

##  What is Banker's Algorithm?

**Banker's Algorithm** is a deadlock avoidance algorithm introduced by Edsger Dijkstra. It:
- Works like a "bank" giving loans (resources).
- Grants requests only if it leads to a **safe state**.
- A state is safe if the system can allocate resources to each process in some order and avoid deadlock.

---

##  Features of This Project

- Accepts:
  - Number of processes and resource types
  - Allocation matrix (currently allocated resources)
  - Max matrix (maximum required resources)
  - Available resources
- Checks if system is in a **safe state**
- Displays a **safe sequence** if one exists
- Detects if **deadlock** is possible


