# StsQueue
Simple thread safe Queue in C.
Check out main.c to see how it is used. Thread safety comes from using pthread mutex on write/read.

## Simulated namespaces in C
What might be interesting is to see how I used a struct to simulate a namespace. 
Everything except of what I choose to export is "private". This makes it easy to think in terms of modules.
The design of a module's interface becomes a separate task, and might thus get more attention than otherwise.
