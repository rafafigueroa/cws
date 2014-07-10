#include "shared_memory_feedback.h"

SharedMemory::SharedMemory(char *resName, int id, int bytes)
{
	size = bytes;
	resourceName = resName;
	this->id = id;
	
	// get our semaphore
	mtx = (sem_t *)sem_open(resName, O_CREAT, 0664, 1);
	if (mtx == SEM_FAILED)
	{
		perror("Unable to allocate semaphore!");
		//printf("Error: %i", errno);
		sem_unlink(resName);
		exit(-1);
	}
	
	//Allocate our shared memory.
	
	shmid = shmget(id, bytes, IPC_CREAT | 0666);
	if (shmid < 0)
	{
		perror("Error allocating shared memory!");
		//printf("Error: %i", errno);
		sem_close(mtx);
		sem_unlink(resName);
		exit(-1);
	}
	
	//Attach
	shared = shmat(shmid, NULL,0);			
	if (shared == (void *)-1)
	{
		perror("Error mapping shared segment! ");
		exit(-1);
	}
}

void SharedMemory::write(void *buffer)
{
	// Wait until the shared memory segment is not in use.
	sem_wait(mtx);
	// Write to our shared memory segment
	memcpy( shared, buffer, size);
	sem_post(mtx); //Release our semaphore
	
}

void SharedMemory::read(void *buffer)
{
	sem_wait(mtx);
	memcpy( buffer, shared, size);
	sem_post(mtx);
}

SharedMemory::~SharedMemory()
{	
	shmctl(shmid, IPC_RMID, 0); //Release shared memory.	
	sem_close(mtx);
	sem_unlink(resourceName);
}

