- return better errors for file objects (also check read/write allowed, etc.)

- introduce more specific exceptions (e.g., zero divide, index failure, ...)

- why do reads from stdin fail when I suspend the process?

- introduce macros to set/inspect errno for syscalls, to support things
  like getoserr()

- fix interrupt handling (interruptable system calls should call
  intrcheck() to clear the interrupt status)
