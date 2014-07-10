#ifndef SHAREDMEMORY_H
#define SHAREDMEMORY_H

#include <semaphore.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <memory.h>
#include <errno.h>

class SharedMemory
{
protected:
	sem_t *mtx;
	char *resourceName;
	
	key_t id; //Shared memory ID to open.
	int shmid; //ID returned from shmget
	void *shared; //Pointer to the shared memory segment.
	int size; //Size of our shared memory segment.
	
	bool master; //The master will release the shared memory segment.
	
	void releaseShared(); //Releases the shared memory in a thread safe manner.	

public:
	
	SharedMemory(char *resName, int id, int bytes);
	~SharedMemory();
	
	void read(void *buffer);
	void write(void *buffer);
};

#endif // SHAREDMEMORY_H
