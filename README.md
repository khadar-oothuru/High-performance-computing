 gcc -o sorting  S20210010164_HPC_ASSIGNMENT_01.c -pg
 ./sorting
gprof sorting  gmon.out > analysis.txt
