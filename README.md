# philosophers


using semaphores as a test (from https://www.youtube.com/watch?v=27lu1lwvoGY, https://dextutor.com/program-on-dining-philosopher-problem/)


mutex prolly model using (https://gist.github.com/theawless/88e78ba6979865e43289be37f9f01d47)



concurrency in c (https://www.classes.cs.uchicago.edu/archive/2018/spring/12300-1/lab6.html)


learning about process synchronization (https://www.geeksforgeeks.org/introduction-of-process-synchronization/?ref=lbp)






thread_philo.cpp (https://osandnetworkingcslab.wordpress.com/implementation-of-dining-philosophers-using-threads/)
	found in Using_mutext_test/thread_philo.cpp

https://en.wikipedia.org/wiki/Dining_philosophers_problem#Chandy/Misra_solution

using "./philosophers 6 1000 10000 60" as input


currently the routine goes in order of p1 eat, stop eating, dies, and repeates for p2, p3, p4 ...


IN using mutex:
used:
    printf()
    atoi()


when finished, change to:
    ft_printf()
    ft_atoi()
    
    
philo testing
- Do not test with more than 200 philosophers.
- Do not test with time_to_die or time_to_eat or time_to_sleep set
to values lower than 60 ms.
- Test 1 800 200 200. The philosopher should not eat and should die.
- Test 5 800 200 200. No philosopher should die.
- Test 5 800 200 200 7. No philosopher should die and the simulation
should stop when every philosopher has eaten at least 7 times.
- Test 4 410 200 200. No philosopher should die.
- Test 4 310 200 100. One philosopher should die.
- Test with 2 philosophers and check the different times: a death
delayed by more than 10 ms is unacceptable.
- Test with any values of your choice to verify all the requirements.
Ensure philosophers die at the right time, that they don't steal
forks, and so forth.

1 800 200 200

[philo-Test #1]: Given 4 310 200 100 arguments to philo, a philosopher should die !
[philo-Test #2]: Given 4 410 200 200 arguments to philo, no philosopher should die !
[philo-Test #3]: Given 4 800 200 200 arguments to philo, no philosopher should die !
[philo-Test #4]: Given 4 410 200 200 15 arguments to philo, philo should only be stopped if each philosopher ate at least 15 times !
[philo-Test #4]: Given 4 410 200 200 7 arguments to philo, philo should only be stopped if each philosopher ate at least 7 times !
[philo-Test #4]: Given 4 410 200 200 10 arguments to philo, philo should only be stopped if each philosopher ate at least 10 times !
[philo-Test #4]: Given 4 410 200 200 12 arguments to philo, philo should only be stopped if each philosopher ate at least 12 times !









    
