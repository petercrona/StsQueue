#ifndef STS_QUEUE_H
#define STS_QUEUE_H

/*
 * Simple thread safe queue (StsQueue) is just an experiment with
 * simulated "namespaces" in C.
 *
 * The idea is simple, just return the functions in a struct.
 * Leak exactly the information that is needed, meaning no special
 * types, structs or other things.
 */

typedef struct StsHeader StsHeader;

typedef struct {
  StsHeader* (* const create)();
  void (* const destroy)(StsHeader *handle);
  void (* const push)(StsHeader *handle, void *elem);
  void* (* const pop)(StsHeader *handle);
} _StsQueue;

extern _StsQueue const StsQueue;

#endif
