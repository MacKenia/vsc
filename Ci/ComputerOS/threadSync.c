#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
const int N = 10;

int empty = N;
int full = 0;

int mutedx = 1;


void *consumer() {
	int number = 0;
	while (1) {
		if (mutedx) {
			if(empty != N) {
				mutedx = 0;
				printf("[Consumer]Consumer has just consumed the %d th product.\n", ++number);
				empty++;
				full--;
				mutedx = 1;
			} else {
				printf("[Consumer]The buffer is empty.\n");
				wait(NULL);
			}
		} else {
			printf("[Consumer]Permission denied.\n");
		}
		usleep(100001);// unix sleep(ms/1000)
	}
	return 0;
}

void *producer() {
	int number = 0;
	int i = 11;
	while(i--) {
		if(mutedx) {
			if(full != N) {
				mutedx = 0;
				printf("[Producer]Producer has just produced the %d th product.\n", ++number);
				empty--;
				full++;
				mutedx = 1;
			} else {
				printf("[Producer]The buffer is full.\n");
				wait(NULL);
			
			}
		} else {
			printf("[Producer]Permission denied.\n");
		}
		usleep(1000010);
	}
	return 0;
}

int main() {
	pthread_t con;
	pthread_t pro;
	pthread_create(&pro, NULL, producer(), NULL);
	pthread_create(&con, NULL, consumer(), NULL);

	//pthread_join(con, NULL);
	//pthread_join(pro, NULL);
	return 0;
}
