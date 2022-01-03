/* RFF.c : Recursive find file utility */
/*                                     */
/*                          PGMD by TH */
#include <stdio.h>
#include <dos.h>
#include <dir.h>

#define ALL_ATTRIB FA_RDONLY|FA_HIDDEN|FA_SYSTEM|FA_LABEL|FA_DIREC|FA_ARCH

void findfile(char *mask) {
	char path[80];
	struct ffblk info;
	if(findfirst(mask, &info, ALL_ATTRIB) == 0) {
		do {
			getcwd(path, 80);
			printf("\n%s%s%s"
				, path
				, strlen(path)==3 ? "": "\\"
				, info.ff_name);
		}while(findnext(&info) == 0);
	}

	if(findfirst("*", &info, FA_DIREC) == 0) {
		do {
			if(info.ff_name[0] == '.' || info.ff_attrib != FA_DIREC)
				continue;
			chdir(info.ff_name);
			findfile(mask);
			chdir("..");
		}while(findnext(&info) == 0);
	}
}

void main(void) {
	char curpath[30];
	char file1[256];
	printf("\nTo find file name --> ");
	scanf("%s", file1);

	getcwd(curpath, 30);
	chdir("\\TURBOC3\\");
	findfile(file1);
	chdir(curpath);
	getch();
}