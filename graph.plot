set terminal png
set output "res.png"
set xlabel 'St. Petersburg paradox'
set xlabel '# of game played'
set ylabel 'earing per game'
plot "res.csv" using "%lf,%lf"
