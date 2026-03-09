*This project has been created as part of the 42 curriculum by nde-sant*

---

## Description
The goal of this project is to create a version of the [dining philosophers problem](https://en.wikipedia.org/wiki/Dining_philosophers_problem):

One or more philosophers sit at a round table with a large bowl of spaghetti in the middle.

The philosophers take turns eating, thinking and sleeping. As expected each philosopher can only perform one task at a time.

The problem is that even knowing how *uncivilized* it is to eat spaghetti with only one fork, we only have as many forks as philosophers. Each philosopher must pick up both the fork to their right and the fork to their left before eating.

When a philosopher has finished eating, they put their forks back on the table and
start sleeping. Once awake, they start thinking again. The simulation stops when
a philosopher dies of starvation.

## Instructions
Clone the repository and enter the folder:
```bash
git clone https://github.com/nicolasgsantana/philosophers
cd philosophers/philo
```
Compile and run the program:
```bash
make 
./philo [number_of_philosophers] [time_to_die] [time_to_eat] [time_to_sleep] [number_of_times_each_philosopher_must_eat]
```
### Info
`number_of_philosophers` = number of philosophers and forks at the table
`time_to_die (in milliseconds)` = If a philosopher has not started eating within
`time_to_die` milliseconds since the start of their last meal or the start of the
simulation, they die.
`time_to_eat (in milliseconds)` = The time it takes for a philosopher to eat.
During that time, they will need to hold two forks.
`time_to_sleep (in milliseconds)` = The time a philosopher will spend sleeping.
`number_of_times_each_philosopher_must_eat (optional argument)` = If all
philosophers have eaten at least `number_of_times_each_philosopher_must_eat`
times, the simulation stops. If not specified, the simulation stops when a
philosopher dies.


## Resources
References used during development:
- [Unix Threads in C by CodeVault on Youtube](https://www.youtube.com/playlist?list=PLfqABt5AS4FmuQf70psXrsMLEDQXNkLq2)
- [Deadlock article on Wikipedia](https://en.wikipedia.org/wiki/Deadlock_(computer_science))
- [Race condition article on Wikipedia](https://en.wikipedia.org/wiki/Race_condition#Data_race)
- AI was used for:
    - Research
    - Help with manual tests
