/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: albozkur <albozkur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 13:08:02 by albozkur          #+#    #+#             */
/*   Updated: 2024/01/16 13:08:15 by albozkur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 16
# endif

void	*ft_free_stash(char **stash, int create_line);
char	*ft_copy_to_stash(char *stash, char *buf);
char	*ft_extract_line(char *stash);
char	*ft_recreate_stash(char *stash);
char	*get_next_line(int fd);

#endif
