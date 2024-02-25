#include <pid.h>

pid_t	*pid_get(void)
{
	static pid_t	pid;

	return (&pid);
}

void		pid_set(pid_t *set, float kp, float ki, float kd, float error)
{
	set->kp = kp;
	set->ki = ki;
	set->kd = kd;
	set->error->setpoint = set->error->prev = error;
}

float	error_get(pid_t *set)
{
	return (set->error->setpoint - set->value);
}

float	kp_get(pid_t *set)
{
	return (error_get(set) * set->kp);
}

float	ki_get(pid_t *set)
{
	return (set->ki * set->sum);
}

float	kd_get(pid_t *set)
{
	return (set->kd * (error_get(set) - set->error->prev));
}

float	sum_get(pid_t *set)
{
	return (kp_get(set) + ki_get(set)) + kd_get(set);
}