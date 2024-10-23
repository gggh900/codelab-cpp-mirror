set -x
for i in $1; do
    sudo g++ $i.cpp -o $i.out; 
    [[ $? -eq 0 ]] || exit 1
done
