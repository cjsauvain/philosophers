/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsauvain <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/15 09:07:33 by jsauvain          #+#    #+#             */
/*   Updated: 2022/09/26 11:55:18 by jsauvain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdio.h>
# include <stdlib.h>

typedef struct s_all	t_all;

typedef struct s_thread
{
	pthread_t		philo;
	int				index;
	int				meals;
	int				time;
	t_all			*data;
}	t_thread;

typedef struct s_all
{
	int				die;
	int				args;
	int				time;
	int				nb_philos;
	int				philo_meals;
	int				to_eat;
	int				to_sleep;
	int				to_die;
	t_thread		*threads;
	pthread_mutex_t	*mutex_forks;
	pthread_mutex_t	mutex_time;
	pthread_mutex_t	mutex_die;
	pthread_mutex_t	mutex_message;
	pthread_mutex_t	mutex_meals;
}	t_all;

//check_errors.c
void		print_error_message(char *str);
int			check_arguments(int argc, char **argv);
int			check_errors(int argc, char **argv);

//1_utils.c
int			ft_strlen(char *str);
int			ft_isdigit(int c, int j);
long int	ft_atoi(char *nptr);

//2_utils.c
void		ft_usleep(t_thread *thread, int usleep);
int			get_time(int time_0);
void		print_message(t_thread *thread, char *color, char *str);
void		exit_program(t_all *infos);

//init_utils.c
void		initialize_thread_infos(t_all *infos, char **argv, int i);
void		init_life_infos(t_all *infos, char **argv, int argc);
int			infos_mutex_init(t_all *infos);

//life_utils.c
void		to_eat(t_thread *thread);
void		to_sleep(t_thread *thread);
void		to_think(t_thread *thread);

//mutex_utils.c
void		destroy_mutex(t_all *infos);
void		mutex_lock(t_thread *thread);
void		mutex_unlock(t_thread *thread);

//threads_utils.c
void		*start_routine(void *arg);
void		one_philo(t_all *infos);
void		many_philo(t_all *infos, char **argv);
int			thread_init(t_all *infos, char **argv);

//get_status
int			get_die_status(t_thread *thread);
int			get_meals_status(t_thread *thread);

//die.c
void		thread_death(t_all *infos, int i);
void		every_philos_ate(t_all *infos);
void		*check_die(void *arg);

//free.c
void		ft_free(t_all *infos, int i);

#endif
