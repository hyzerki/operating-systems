#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
	char* const argv[] = { "ps", "-eF", 0 };

	for (int i = 0; i < 100; i++) {
		sleep(2);
		printf("OS03_07 PID: %d-#%d\n", getpid(), i);
		if (i == 2)
		{
			execv("./os03_05_1.out", argv);
		}
	}

	exit(0);
}