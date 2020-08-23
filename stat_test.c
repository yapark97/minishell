#include <sys/stat.h>
#include <stdio.h>

int main()
{
    struct stat sb;
    int a, b;
    
    if (a = stat("a.out", &sb))
    {
        printf("exist!\n");
        printf("sb.st_mode : %d\n", sb.st_mode);
        if (sb.st_mode == S_IFLNK)
            printf("symlink\n");
    }
    b = stat("./a.out", &sb);
    printf("%d %d\n", a, b);
    return 0;
}