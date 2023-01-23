for i in 1 2 3; do
    clear; g++ -std=c++17 lazy_init-$i.cpp 2>&1 | tee build_lazy_init-$i.log && 
    ./a.out 2>&1 | tee run_lazy_init-$i.log ; 
done
