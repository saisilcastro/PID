#ifndef PID_H
#define PID_H

typedef struct pid_s	pid_t;
struct pid_s{
	float	kp; // constant proportional
	float	ki; // contant integral
	float	kd; // constant derivative
	float	value;
	struct{
		float	setpoint;
		float	prev;
	}error[1];
	float	sum;
};

extern pid_t	*pid_get(void);
extern void		pid_set(pid_t *set, float kp, float ki, float kd, float error);
extern float	error_get(pid_t *set);
extern float	kp_get(pid_t *set);
extern float	ki_get(pid_t *set);
extern float	kd_get(pid_t *set);
extern float	sum_get(pid_t *set);

#endif