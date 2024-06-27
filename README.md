<p align="center">
  <img src="doc/pic/main_pic_dinner_phiosopher.png" alt="Beschreibung des Bildes">
</p>

# Philosophers [Projekt](doc/PDF/Philosphers_subject.pdf)

## Überblick

Dieses Projekt ist Teil der 42Schule und simuliert das klassische Problem der Philosophen. Das Problem beschreibt eine Situation, in der mehrere Philosophen abwechselnd denken und essen, jedoch begrenzte Ressourcen (Gabeln) teilen müssen. Ziel ist es, eine Lösung zu finden, die sowohl Deadlocks als auch Verhungern vermeidet.

## Lernziele des Projekts

- Verstehen und Implementieren von Synchronisationsmechanismen.
- Umgang mit Nebenläufigkeit und paralleler Programmierung.
- Sicherstellen, dass das Programm Deadlocks und Verhungern der Philosophen verhindert.

## Installation

Klonen Sie das Repository:
   ```sh
   git clone https://github.com/ELREKO/Philosphers.git
   cd philosopherprojekt
   ```

Kompilieren Sie das Projekt:
   ```sh
   make
   ```

Nach Programmänderungen
   ```sh
   make re
   ```



## Ausführung

Nach der Kompilierung können Sie das Programm mit folgendem Befehl ausführen:

```shell
./philo <Anzahl_der_Philosophen>  <Zeit_bis_Philsoph_stirbt> <Zeit_zum_essen> <Zeit_die_ein_Phiosph_schlaffen_muss> <optional: Anzahl_die_ein_Philsoph_haben_muss>
```

Beispiel:
```sh
./philo 5 200 100 70
```
Dies startet eine Simulation mit 5 Philosophen, wobei jeder Philosoph 200 Millisekunden hat bis er stirbt, 100 Millisekunden zum essen benötigt, und 70Millisekunden mindesten schlaffen muss. 

Beispiel:
```sh
./philo 5 200 100 70 2
```
Das sind die selben Parmeter wie oben nur mit der Erweiterung das jedes Philosph mindesten 2 mal essen muss. 

## Funktionsweise

Jeder Philosoph durchläuft die folgenden Zustände:

1. **Denken**: Der Philosoph denkt für eine bestimmte Zeit.
2. **Hungrig**: Der Philosoph versucht, beide Gabeln zu greifen.
3. **Essen**: Der Philosoph isst für eine bestimmte Zeit.

<p align="center">
  <img src="doc/pic/Programm_resualt.png" alt="Beschreibung des Bildes">
</p>


### Synchronisation

- Gabeln werden als binäre Semaphore implementiert.
- Jeder Philosoph greift zuerst nach der linken und dann nach der rechten Gabel (oder umgekehrt, je nach Implementierung).
- Die Synchronisation stellt sicher, dass keine zwei Philosophen gleichzeitig dieselbe Gabel benutzen.


### Weiter Informationen
[Unterschied zwischen Thread und Process](doc/Proccess_vs_Thread.md)


