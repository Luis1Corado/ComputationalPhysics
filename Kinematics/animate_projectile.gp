
set terminal gif animate delay 10 size 1280,720
set output "projectile_animation.gif"
set xlabel "x"
set ylabel "y"
set title "Projectile Motion"
n = system("wc -l Projectile.dat | cut -d   -f 1") - 1
do for [i=1:n] {
    plot "Projectile.dat" u 2:3 w l lw 2 title "Trajectory", \
         "" every ::1::i u 2:3 w p pt 7 ps 2 lc "red" title "Projectile"
}
set output

