set terminal png
set output "res.png"
plot "res.csv" using "%lf,%lf"
