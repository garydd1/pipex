/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarizad <dgarizad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 18:46:44 by dgarizad          #+#    #+#             */
/*   Updated: 2023/02/09 19:13:50 by dgarizad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_error(char *error)
{
	write(2, error , ft_strlen(error));
	return(1);
}

void	exit_error(char *error)
{
	perror(error);
	exit (1);
}

unsigned int	ft_pathlen(const char *s)
{
	unsigned int	i;

	i = 0;
	while (s[i] != '\n' && s[i])
		i++;
	return (i);
}
/**
* @brief Forks and execs any cmd,
writes the result in fd[1] of the pipe.
* 
* @param fd Previously piped in the calling function.
* @param path "string with the exact path".
* @param cmd array of strings with the cmd and arguments/flags.
* @param envp Enviroment variables array of strings.
*/

void	ft_exec_next_cmd(int *fd, char *path, char **cmd, int file, char **envp)
{
	pid_t	pid;
	int		status;

	// pid = fork();
	// if (pid == -1)
	// 	ft_error("fork");
	// if (pid == 0)
	// {
		close(fd[0]);
		dup2(file, 0);
		close(file);
		dup2(fd[1], 1);
		close(fd[1]);
		execve(path, cmd, envp);
		exit_error("exxecve");
	// }
	// waitpid(pid, &status, 0);
}

void	ft_exec_cmd2(int *fd, char *path, char **cmd, int file, char **envp)
{
	//pid_t	pid;
	// int		status;

	// //pid = fork ();
	// if (pid == 0)
	// {
		close(fd[1]);
		if (dup2(fd[0], 0) == -1)
			ft_error("dup2");
		close(fd[0]);
		if (dup2(file, 1) == -1)
			ft_error("dup2");
		close(file);
		execve(path, cmd, envp);
		exit_error("exxecve");
		
	// }
	//waitpid(pid, &status, 0);
}

void	ft_get_next_path(int *fd, char **which, char **envp)
{
	pid_t	pid;
	int		status;

	pid = fork();
	if (pid == -1)
		perror("fork");
	if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], 1);
		close(fd[1]);
		execve("/usr/bin/which", which, envp);
		ft_error("ecxecve");
	}
	waitpid(pid, &status, 0);
	// printf("\nstatys: %d \n", status);
	if (status == 256)
		exit_error("Command not found");
}

void	ft_magic_pipe(int filein, int fileout, char *argv[], char *envp[])
{
	int			fd[2];
	char		path[2][200];
	pid_t		pid[2];
	char		**cmds[2];
	char		*which[3];
	int			status1;
	
	cmds[0] = ft_split(argv[2], ' '); // NEED TO BE FREED
	cmds[1] = ft_split(argv[3], ' '); // NEED TO BE FREED 119 72 73 99 72
	which[0] = "which";
	which[1] = cmds[0][0];
	which[2] = NULL;
	if (pipe(fd) < 0) 
		exit_error("pipe: ");
	
	// printf("\nFirst command '%s' '%s'\n", which[1], cmds[0][1]);
	// printf("\nsecond command: '%s %s '\n", cmds[1][0], cmds[1][1]);
	ft_get_next_path(fd, which, envp);
	read(fd[0], path[0], 200);
	which[1] = cmds[1][0];
	ft_get_next_path(fd, which, envp);
	read(fd[0], path[1], 200);
	path[0][ft_pathlen(path[0])] = '\0';
	path[1][ft_pathlen(path[1])] = '\0';
	// if (access(path[0], 0) == -1 || access(path[1], 0) == -1 ) 
	// 	exit_error("access");
	//printf("\npipped1: '%s', \nbuffer2:'%s'\n", path[0], path[1]);
	pid[0] = fork();
	if (pid[0] == 0)
	{
		ft_exec_next_cmd(fd, path[0], cmds[0], filein, envp);
		free(cmds[0]);
		free(cmds[1]);
	}
	close(fd[1]);
	pid[1] = fork();
	if (pid[1] == 0)
	{
		ft_exec_cmd2(fd, path[1], cmds[1], fileout, envp);
		// free(cmds[0]);
		// free(cmds[1]);
	}
	waitpid(pid[0], &status1, WNOHANG);
	// write(2,"X", 1);
	// printf("\nstatys: %d \n", status1);
	waitpid(pid[1], NULL, 0);
	free(cmds[0]);
	free(cmds[1]);
}	
/**
* @brief  This program executes two commands in the smae order than
1 pipe. < filein "first command" | "second command" fileout >
* 
* @param argc 
* @param argv [1]input file [2]first command [3]second command
[4]output filename
* @param envp 
* @return int 
*/

int	main(int argc, char *argv[], char *envp[])
{
	int	filein;
	int	fileout;
		
	if (argc != 5)
	{
		return (ft_error("Input"));
	}

	filein = open(argv[1], O_RDONLY);
	if (filein < 0)
		exit_error("pipex: input");
	fileout = open(argv[4], O_WRONLY | O_TRUNC | O_CREAT, 0644);
	if (fileout < 0)
		exit_error("Outfile");
	ft_magic_pipe(filein, fileout, argv, envp);
	close(fileout);
	close(filein);
	//write(1, "\nTHE END", 8);
	return (0);
}
