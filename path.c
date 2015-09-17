
//使用c语言获得进程执行文件的绝对路径
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
#include<libpro.h>

int main(int argc, char *argv[])  
{
	pid_t pid, int ret;
	char pathbuf[PROC_PIDPATHINFO_MAXSIZE];

	if (argc > 1)
	{
		pid = (pid_t)atoi(argv[1]);
		ret = proc_pidpath(pid, pathbuf, sizeof(pathbuf));
		if (ret <= 0)
		{
			fprint(stderr, "PID %d:proc_pidpath();\n", pid);
			fprint(stderr, "  %s\n", stderror(errno));
		}
		else{
			print("proc %d:%s\n", pid, pathbuf);
		}
	}
	return 0;
}