Programacao Paralela - Osvaldo de Araujo Neto

[t4](./t4.cpp)

Exemplo de Saida
Osvaldo de Araujo Neto
Case 1: using schedule static
AAAAAAAAAAAAAAAAAAAACCCCCCCCCCCCCCCCCCCCBBBBBBBBBBBBBBBBBBBB
A=20 B=20 C=20
Case 2: using schedule dynamic
AAAAAAAAAAAAAAAAAACCCCCCCCCCCCCCCCCCCCAABBBBBBBBBBBBBBBBBBBB
A=20 B=20 C=20
Case 3: using schedule guided
AACCCCCCCCCCCCCCCCCCCCCCCCCCAAAAAAAAAAAAAAAAAABBBBBBBBBBBBBB
A=20 B=14 C=26
Case 4: using schedule runtime
AAAAAAAAAAAAAAAAAAAACCCCCCCCCCCCCCCCCCCCBBBBBBBBBBBBBBBBBBBB
A=20 B=20 C=20
Case 5: not using omp critical
BABCABCABCABCABCABCABCABCAACBACBCABCABCABCABCABCABCABCABC-B-
A=19 B=20 C=19

Referencias
[Scheduling of Parallel Loops](https://www.dartmouth.edu/~rc/classes/intro_openmp/schedule_loops.html)
[OpenMP* Loop Scheduling](https://software.intel.com/en-us/articles/openmp-loop-scheduling)
[OpenMP Scheduling](http://cs.umw.edu/~finlayson/class/fall14/cpsc425/notes/12-scheduling.html)