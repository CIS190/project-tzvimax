# Serial Port Command Line Emulator
Command Line UI allows user to manage serial connections in a straightforward manner

## Build Instructions
clone the repo  
```
git submodule update --init --recursive # Pull in dependencies 
mkdir build  
cd build  
cmake -DCMAKE_BUILD_TYPE=Release ..  
make
```

To run, execute `./190.out` from the build directory
