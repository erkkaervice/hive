/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   area51.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 19:14:41 by eala-lah          #+#    #+#             */
/*   Updated: 2024/07/15 13:12:27 by eala-lah         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//testicals[1][2]

void execute_push_swap(void) {
	pid_t pid;
	int pipe_fd[2];
	char *argv[] = {"./push_swap", NULL}; // Assuming push_swap is in the same directory
	char buffer[1024];
	int bytes_read;

	pipe(pipe_fd); // Create a pipe

	pid = fork();
	if (pid == 0) {
		// Child process
		close(pipe_fd[0]); // Close reading end
		dup2(pipe_fd[1], STDOUT_FILENO); // Redirect stdout to pipe
		execvp(argv[0], argv); // Execute push_swap
		exit(1); // If exec fails
	} else {
		// Parent process
		close(pipe_fd[1]); // Close writing end
		while ((bytes_read = read(pipe_fd[0], buffer, sizeof(buffer) - 1)) > 0) {
			buffer[bytes_read] = '\0'; // Null terminate
			write(STDOUT_FILENO, buffer, bytes_read); // Output moves
		}
		wait(NULL); // Wait for child process to finish
	}
}
