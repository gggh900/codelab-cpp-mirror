set -x
i=$1
if [[ ! -z $i  ]] ; then
    sudo rm -rf ./$i.out
    sudo bash ./build.sh $i   
     
    sudo mkdir log
    for c in {1..1000000}; do
        ./$i.out | sudo tee log/$c.log 
    done
else
    echo "Please specify file."
fi
