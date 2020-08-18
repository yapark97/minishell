int		get_next_line(int fd, char **line);

int main()
{
    int t;
    char *test;

    t = get_next_line(0, &test);
    return 0;
}