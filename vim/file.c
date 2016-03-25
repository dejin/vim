#include <string.h> 
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <stdlib.h>
#include <sys/ioctl.h>


int gettags(char *filename, char *flag, char *out)
{
	FILE *file_p, *file_out;
	char *n = NULL;
	int num = 0;
	char oneline[3000];
	char tmp[300];
	//char *function = ";\"	f";
	char *tab = "\t";

	if((file_p = fopen(filename,"r"))==NULL) {
	    printf("Can not open %s file.\n", filename);
	    return;
	}

	if((file_out = fopen(out,"a+"))==NULL) {
	    printf("Can not open %s file.\n", out);
	    return;
	}

	while(fgets(oneline,3000,file_p)!=NULL)
	{
		if (strstr(oneline, flag) != NULL) {
			//printf("%s", oneline);
			n = strstr(oneline, tab);
			memset(tmp, 0, 300);
			num = n - oneline;
			if (num > 300)
				num = 300;
			strncpy(tmp, oneline, n - oneline);
			//printf("%s ",tmp);
			fprintf(file_out, "%s ", tmp);
			//fflush(file_out);
		}
	}

	fprintf(file_out, "\n");
	fclose(file_out);
	fclose(file_p);

	return 0;
}

int main(int argc, char *argv[])
{
	gettags(argv[1], ";\"	d", argv[2]);
	gettags(argv[1], ";\"	e", argv[2]);
	gettags(argv[1], ";\"	f", argv[2]);
	gettags(argv[1], ";\"	g", argv[2]);
	gettags(argv[1], ";\"	p", argv[2]);
	gettags(argv[1], ";\"	s", argv[2]);
	gettags(argv[1], ";\"	t", argv[2]);
	gettags(argv[1], ";\"	u", argv[2]);
	return 0;
}
