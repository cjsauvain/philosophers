# philosophers

> Projet réalisé dans le cadre du cursus de l’école 42.  

## 📌 Objectif
> Implémenter une simulation du problème des **philosophes mangeurs** :  
> Plusieurs philosophes s’assoient autour d’une table, chacun ayant besoin de deux fourchettes pour manger. Le but est d’éviter les conditions de compétition (race conditions), les blocages (deadlocks) et les famines (starvation) dans un environnement multithreadé.

## ✅ Prérequis

- gcc
- Bibliothèque `pthread` (POSIX threads)

## 🚀 Compilation && Execution

```bash
make

./philo <number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> [number_of_times_each_philosopher_must_eat]
```

## 🧠 Concepts abordés

- Multithreading
