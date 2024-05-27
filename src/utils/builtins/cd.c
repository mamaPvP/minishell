#include "../../header/minishell.h"

int ft_strlen_tab(char **tab)
{
    int i;

    i = 0;
    while (tab[i])
        i++;
    return (i);
}

void cd(char **tab, char ***env){
    char *pwd = get_cwd(0);
    char *path;

    if(ft_strlen_tab(tab) > 1){
        printf("cd: too many arguments\n");
        return;
    }
    path = ft_strjoin(pwd, "/");
    path = ft_strjoin(path, tab[0]);
    if (chdir(path) == -1) {
        printf("cd: %s: No such file or directory\n", path);
    }
    export_var2(env, "OLDPWD", pwd);
    export_var2(env, "PWD", path);
}
