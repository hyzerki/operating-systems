#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>

void cycle(int countIteration, char* str) {
	for (int i = 0; i < countIteration; i++) {
		sleep(2);
		printf("%s PID: %d-#%d\n", str, getpid(), i);
	}
}

int main() {
	pid_t pid;
	switch (pid = fork()) {
	case -1:
		perror("fork");
		exit(1);
	case 0:
		cycle(50, "os03_05_1.out");
	default:
		cycle(100, "os03_05.out");
	}

	exit(0);
}