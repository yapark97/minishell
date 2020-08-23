#include "minishell.h"

static char *find_path(char *cmd)
{
    int i;
    char **env_path;
    char *new_path;
    char *temp;
    struct stat sb;

    i = -1;
    //relative path 실행파일 해보고 안되면 추가
    if (!stat(cmd, &sb))
        return (ft_strdup(cmd));
    while (g_envp[++i])
    {
        if (!ft_strncmp(g_envp[i], "PATH=", 5))
            env_path = ft_split(g_envp[i] + 5, ':');
    }
    i = -1;
    while (env_path[++i])
    {
        temp = ft_strjoin(env_path[i], "/");
        new_path = ft_strjoin(temp, cmd);
        free(temp);
        if (!stat(new_path, &sb))
        {
            free_2d_arr(env_path);
            return (new_path);
        }
        free(new_path);
    }
    free_2d_arr(env_path);
    return (0);
}

void pipes_exec(char **cmd1, char **cmd2)
{
    int fd[2];
    pid_t child, child2;
    int status;
    char *path1, *path2;

    path1 = find_path(cmd1[0]);
    path2 = find_path(cmd2[0]);
    
    child = fork();
    if (!child)
    {
        pipe(fd);
        child2 = fork();
        if (!child2)
        {
            close(fd[0]);
            dup2(fd[1], 1);
            execve(path1, cmd1, g_envp);
        }
        else
        {
            close(fd[1]);
            waitpid(child2, &status, 0);
            dup2(fd[0], 0);
            execve(path2, cmd2, g_envp);
        }
    }
    else
    {
        waitpid(child, &status, 0);
        g_exit_code = status / 256;
        free(path1);
        free(path2);
    }
    
}

int excutables(int fd_o, int fd_i, char **argv)
{
    pid_t   child;
    int     status;
    char    *path;

    path = find_path(argv[0]);
    child = fork();
    if (!child)
    {
        if (fd_o != 1)
            dup2(fd_o, 1);
        if (fd_i != 0)
            dup2(fd_i, 0);
        if (execve(path, argv, g_envp) == -1)
            exit(10);
    }
    else
    {
        waitpid(child, &status, 0);
        if (status == 2560)
            return (0);
        g_exit_code = status / 256;
        free(path);
    }
    
    return (1);
}