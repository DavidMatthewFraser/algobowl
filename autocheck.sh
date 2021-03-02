echo "validate:" > ./validate/summary
for filename in ./out/out*; do
    echo "" >> ./validate/summary
    echo "* $filename:" >> ./validate/summary
    ./checker < $filename >> ./validate/summary 
done