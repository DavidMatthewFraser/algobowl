x=270
for filename in ./out/out*; do
    x=$((x+1))
    ./checker < $filename > "./validate/val_$x" 
done