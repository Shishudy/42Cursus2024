#include "philosophers.h"
#include <stdio.h>

void print_philo(const t_philo *philo)
{
    if (!philo)
        return;
    printf("t_philo {\n");
    printf("  philo_id: %d\n", philo->philo_id);
    printf("  meals: %d\n", philo->meals);
    printf("  started_eating: %ld\n", philo->started_eating);
    printf("  philo_th: %p\n", (void*)philo->philo_th);
    printf("  meal_lock: %p\n", (void*)&philo->meal_lock);
    printf("  fork_left: %p\n", (void*)&philo->fork_left);
    printf("  fork_right: %p\n", (void*)philo->fork_right);
    printf("}\n");
}

void print_context(const t_context *ctx)
{
    if (!ctx)
        return;
    printf("t_context {\n");
    printf("  number_of_philosophers: %d\n", ctx->number_of_philosophers);
    printf("  number_of_times_each_philosopher_must_eat: %d\n", ctx->number_of_times_each_philosopher_must_eat);
    printf("  stop: %d\n", ctx->stop);
    printf("  time_to_die: %ld\n", ctx->time_to_die);
    printf("  time_to_eat: %ld\n", ctx->time_to_eat);
    printf("  time_to_sleep: %ld\n", ctx->time_to_sleep);
    printf("  start_time: %ld\n", ctx->start_time);
    printf("  arr_philos: %p\n", (void*)ctx->arr_philos);
    printf("  overseer: %p\n", (void*)ctx->overseer);
    printf("  stop_lock: %p\n", (void*)&ctx->stop_lock);
    printf("  print_lock: %p\n", (void*)&ctx->print_lock);
    if (ctx->arr_philos)
    {
        printf("  Philosophers:\n");
        for (int i = 0; i < ctx->number_of_philosophers; i++)
        {
            printf("    Philosopher %d:\n", i);
            print_philo(&ctx->arr_philos[i]);
        }
    }
    printf("}\n");
}
