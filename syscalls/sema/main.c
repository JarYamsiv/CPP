#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <semaphore.h>
#include <sys/mman.h>
#include <fcntl.h>
 
typedef struct {
    sem_t one;
    sem_t two;
} SemPair;
 
int main(int argc, const char *argv[]) {
    int shm = shm_open("/test", O_CREAT | O_RDWR, S_IRUSR | S_IWUSR);
    ftruncate(shm, sizeof(sem_t));
    SemPair *sem = mmap(NULL, sizeof(sem_t), PROT_READ | PROT_WRITE, MAP_SHARED, shm, 0);
 
    sem_init(&(sem->one), 1, 0);
    sem_init(&(sem->two), 1, 0);
 
    pid_t pid = fork();
    if (!pid) {
        while (1) {
            sem_wait(&(sem->two));
            fprintf(stderr,"Child %d\n", getpid());
            sem_post(&(sem->one));
        }
    } else {
        while (1) {
            sem_post(&(sem->two));
            sem_wait(&(sem->one));
            fprintf(stderr,"Parent %d\n", getpid());
            sleep(1); /* regulate both processes */
        }
    }
    return 0;
}