#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
#include<string.h>

int main(){
	char command[100];
	char *args[10];

	while(1){
		printf("Mshell-> ");
		fgets(command,sizeof(command),stdin);
		command[strcspn(command,"\n")]=0;
		if(strcmp(command,"exit")==0)
			break;

		int i=0;
		args[i]=strtok(command," ");
		while(args[i]!=NULL)
			args[++i]=strtok(NULL," ");

		pid_t pid=fork();

		if(pid==0){
			execvp(args[0],args);

			char exe_path[200];
            		snprintf(exe_path, sizeof(exe_path), "./EXE/%s", args[0]);
            		execv(exe_path, args);

            		perror("exec failed");
            		exit(1);
		}

		else{
			wait(NULL);
		}
	}
	return 0;
}

