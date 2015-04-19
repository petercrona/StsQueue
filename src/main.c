#include <stdio.h>
#include "sts_queue/sts_queue.h"
#include <stdlib.h>

int main() {
  // Create queue
  StsHeader *handle = StsQueue.create();

  // Put stuff into queue
  int elems[101];
  for (int i = 0; i <= 100; i++) {
	elems[i] = i;
	StsQueue.push(handle, &elems[i]);
  }

  // Print stuff from queue
  int *mem;
  while ( (mem = StsQueue.pop(handle)) != NULL) {
	printf("%i\n", *mem);
  }

  // Kill queue
  StsQueue.destroy(handle);

  return 0;
}
