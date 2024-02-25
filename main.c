#include <pid.h>
#include <stdio.h>

int	main(void)
{
	pid_t	*pid = pid_get();

	float	pos[] = {0, 30, 50, 70, 80, 90, 100, 100, 100};
	short	i;

	pid_set(pid, 0.1, 0.018, 0.1, 100);
	i = -1;
	while (++i < 9)
	{
		pid->error->prev = error_get(pid);
		// pos é só um jeito generico pra testar constantes.
		pid->value = pos[i]; // analogRead(pinNumber); no arduino usa essa função no lugar
		pid->sum += error_get(pid);
		printf("%f %f %f %f %f %f\n", pos[i], error_get(pid), kp_get(pid), ki_get(pid), kd_get(pid), sum_get(pid));
	}	
	return (0);
}
