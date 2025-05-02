#!/bin/bash
output_file1="results1.dat"
> "$output_file1"
output_file2="results2.dat"
> "$output_file2"
dt_array=(0.05 0.025 0.0125 0.006250 0.003125 0.001563 0.000781 0.000391 0.000195 0.000098 0.000049 0.000024 0.000012)
for dt in "${dt_array[@]}"; do 
  echo "dt = $dt"
  ./box <<EOF
10
0 1.0
0 95 ${dt}
EOF
  ./box2 <<EOF
10
0 1.0
0 95 ${dt}
EOF
  paste -d ' ' <(tail -n 1 "box1D_1.dat" | awk -v dt="$dt" '{print dt, $1, $2}') <(tail -n 1 "box1D_2.dat" | awk '{print $2}') >> results1.dat
  done

