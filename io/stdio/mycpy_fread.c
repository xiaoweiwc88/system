#include <stdio.h>
#include <stdlib.h>

#define BUFSIZE 1024

int main(int argc, char **argv)
{
    FILE *fps, *fpd;
    char buf[BUFSIZE];
    int n;

    if(argc < 3) {
        fprintf(stderr, "Usage:.%s<src_file> <dest_file>\n", argv[0]);
        exit(1);
    }

    fps = fopen(argv[1], "r");
    if(fps == NULL)
    {
        perror("fopen()");
        exit(1);
    }

    fpd = fopen(argv[2], "wb+");
    if(fpd == NULL)
    {
        fclose(fps);
        perror("fopen()");
        exit(1);
    }

    while((n = fread(buf, BUFSIZE, 1, fps)) >= 0) {
        printf("n = %d\n", n);
        fwrite(buf, BUFSIZE, n, fpd);
    }

    fclose(fpd);
    fclose(fps);

    exit(0);
}
