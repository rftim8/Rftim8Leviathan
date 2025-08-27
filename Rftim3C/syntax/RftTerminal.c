#include "RftTerminal.h"

void RftTerminal() {

	char* command = "dir";
	FILE* fpipe = popen(command, "r");
	char line[256];
	while (fgets(line, sizeof(line), fpipe)) {
		printf("%s", line);
	}
	pclose(fpipe);
}