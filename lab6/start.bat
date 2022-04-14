g++ -c main.cpp
g++ -c LinkList.cpp
g++ -o main main.o LinkList.o
del main.o
del LinkList.o
start main.exe