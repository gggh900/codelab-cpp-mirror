sudo g++ reproduce-race.cpp && echo "" | sudo tee reproduce-race.txt ; 
echo "starting /a.out, reproducer...will take a while with 1000000 loop" 
sudo ./a.out
echo "done"
egrep -v "1 \+ 2 = 3" reproduce-race.txt | head -5
