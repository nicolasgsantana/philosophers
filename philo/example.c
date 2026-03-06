#include "inc/philo.h"

int mails = 0;
pthread_mutex_t mutex;

void	*routine()
{
	for (int i = 0; i < 1000000; i++)
	{
		pthread_mutex_lock(&mutex);
		mails++;
		pthread_mutex_unlock(&mutex);
	}
	return (NULL);
}


int	main(int argc, char **argv)
{
	pthread_t	t1, t2, t3, t4;

	(void)argc;
	(void)argv;
	pthread_mutex_init(&mutex, NULL);
	if (pthread_create(&t1, NULL, &routine, NULL))
		return (1);
	if (pthread_create(&t2, NULL, &routine, NULL))
		return (1);
	if (pthread_create(&t3, NULL, &routine, NULL))
		return (1);
	if (pthread_create(&t4, NULL, &routine, NULL))
		return (1);
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	pthread_join(t3, NULL);
	pthread_join(t4, NULL);
	pthread_mutex_destroy(&mutex);
	printf("We have %d mails", mails);
	return (0);
}
