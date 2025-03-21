# Технологии и методы программирования
# Лабораторная работа №3 (ДЗ)
# Студент: Зайцев Илья, группа ИУ8-23
##
## Положение директорий:
```
project_root/
├── formatter_lib/
│   ├── formatter.h
│   ├── formatter.cpp
│   └── CMakeLists.txt
├── formatter_ex/
│   ├── formatter_ex.h
│   ├── formatter_ex.cpp
│   └── CMakeLists.txt
├── hello_world/
│   ├── main.cpp
│   └── CMakeLists.txt
├── solver/
│   ├── main.cpp
│   └── CMakeLists.txt
└── solver_lib/
    ├── solver.h
    ├── solver.cpp
    └── CMakeLists.txt
```
## $\stackrel{👑}{1}$. Вам поручили перейти на систему автоматизированной сборки CMake. Исходные файлы находятся в директории formatter_lib. В этой директории находятся файлы для статической библиотеки formatter. Создайте CMakeList.txt в директории formatter_lib, с помощью которого можно будет собирать статическую библиотеку formatter.
### formatter_lib/CMakeLists.txt:
```
cmake_minimum_required(VERSION 3.10)
project(formatter_lib)

add_library(formatter STATIC formatter.h formatter.cpp)

install(TARGETS formatter
        DESTINATION lib) 
install(FILES formatter.h
        DESTINATION include)
        
# target_compile_features(formatter PUBLIC cxx_std_17)
# target_compile_options(formatter PUBLIC -Wall -Wextra)
```
##
## $\stackrel{👑}{2}$. У компании "Formatter Inc." есть перспективная библиотека, которая является расширением предыдущей библиотеки. Т.к. вы уже овладели навыком созданием CMakeList.txt для статической библиотеки formatter, ваш руководитель поручает заняться созданием CMakeList.txt для библиотеки formatter_ex, которая в свою очередь использует библиотеку formatter.
### formatter_ex/CMakeLists.txt:
```
cmake_minimum_required(VERSION 3.10)
project(formatter_ex)

add_library(formatter_ex STATIC formatter_ex.h formatter_ex.cpp)

# include_directories(${CMAKE_SOURCE_DIR}/../formatter_lib)
target_link_libraries(formatter_ex PRIVATE formatter) 

install(TARGETS formatter_ex
        DESTINATION lib)
install(FILES formatter_ex.h
        DESTINATION include)

# target_compile_features(formatter_ex PUBLIC cxx_std_17)
# target_compile_options(formatter_ex PUBLIC -Wall -Wextra)
```
##
## $\stackrel{👑}{3}$. Конечно же ваша компания предоставляет примеры использования своих библиотек. Чтобы продемонстрировать как работать с библиотекой formatter_ex, вам необходимо создать два CMakeList.txt для двух простых приложений: hello_world, которое использует библиотеку formatter_ex; solver, приложение которое испольует статические библиотеки formatter_ex и solver_lib.

### hello_world/CMakeLists.txt:
```
cmake_minimum_required(VERSION 3.10)
project(hello_world)

add_executable(hello_world main.cpp)

# include_directories(${CMAKE_SOURCE_DIR}/../formatter_ex)
target_link_libraries(hello_world PRIVATE formatter_ex)

# target_compile_features(hello_world PRIVATE cxx_std_17)
# target_compile_options(hello_world PRIVATE -Wall -Wextra)
```
## Также для примера в директории hello_world в файле main.cpp напишем простой код, который выводит выражение "Hello, world!"
```
#include <iostream>

int main() {
    std::cout << "Hello, world!" << std::endl;
    return 0;
}
```
##
### solver/CMakeLists.txt:
```
cmake_minimum_required(VERSION 3.10)
project(solver)

add_executable(solver main.cpp)

# include_directories(${CMAKE_SOURCE_DIR}/../formatter_ex)
# include_directories(${CMAKE_SOURCE_DIR}/../solver_lib)
target_link_libraries(solver PRIVATE formatter_ex solver_lib)

# target_compile_features(solver PRIVATE cxx_std_17)
# target_compile_options(solver PRIVATE -Wall -Wextra)
```
### solver_lib/CMakeLists.txt:
```
cmake_minimum_required(VERSION 3.10)
project(solver_lib)

add_library(solver_lib STATIC solver.h solver.cpp)

install(TARGETS solver_lib
        DESTINATION lib)
install(FILES solver.h
        DESTINATION include)
```
## В директории solver в файле main.cpp запишем простой код для коректной работы проекта.
```
#include <iostream>  // Обязательно, если используете cout

int main() {
    // Ваш код здесь
    std::cout << "Hello from solver!" << std::endl; // Пример
    return 0;
}
```
##
### Сборка:
```
cd project_root

mkdir formatter_lib/build && cd formatter_lib/build
cmake ..
make
sudo make install 

cd ../..

mkdir formatter_ex/build && cd formatter_ex/build
cmake ..
make
sudo make install

cd ../..

mkdir solver_lib/build && cd solver_lib/build
cmake ..
make
sudo make install

cd ../..


mkdir hello_world/build && cd hello_world/build
cmake ..
make
./hello_world 

cd ../..


mkdir solver/build && cd solver/build
cmake ..
make
./solver

cd ../..
```
### Вывод:
```
-- The C compiler identification is GNU 14.2.0
-- The CXX compiler identification is GNU 14.2.0
-- Detecting C compiler ABI info
-- Detecting C compiler ABI info - done
-- Check for working C compiler: /usr/bin/cc - skipped
-- Detecting C compile features
-- Detecting C compile features - done
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Check for working CXX compiler: /usr/bin/c++ - skipped
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- Configuring done (0.7s)
-- Generating done (0.0s)
-- Build files have been written to: /home/kali/lab03dz/project_root/formatter_lib/build

[ 50%] Building CXX object CMakeFiles/formatter.dir/formatter.cpp.o
[100%] Linking CXX static library libformatter.a
[100%] Built target formatter

[sudo] password for kali: 
[100%] Built target formatter
Install the project...
-- Install configuration: ""
-- Installing: /usr/local/lib/libformatter.a
-- Installing: /usr/local/include/formatter.h

[100%] Built target formatter
Install the project...
-- Install configuration: ""
-- Up-to-date: /usr/local/lib/libformatter.a
-- Up-to-date: /usr/local/include/formatter.h

- The C compiler identification is GNU 14.2.0
-- The CXX compiler identification is GNU 14.2.0                                                                                                                            
-- Detecting C compiler ABI info
-- Detecting C compiler ABI info - done
-- Check for working C compiler: /usr/bin/cc - skipped
-- Detecting C compile features
-- Detecting C compile features - done
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Check for working CXX compiler: /usr/bin/c++ - skipped
-- Detecting CXX compile features
-- Detecting CXX compile features - done
-- Configuring done (0.8s)
-- Generating done (0.0s)
-- Build files have been written to: /home/kali/lab03dz/project_root/formatter_ex/build

[ 50%] Building CXX object CMakeFiles/formatter_ex.dir/formatter_ex.cpp.o
[100%] Linking CXX static library libformatter_ex.a
[100%] Built target formatter_ex

[sudo] password for kali: 
[100%] Built target formatter_ex
Install the project...
-- Install configuration: ""
-- Installing: /usr/local/lib/libformatter_ex.a
-- Installing: /usr/local/include/formatter_ex.h

-- Configuring done (0.0s)
-- Generating done (0.0s)
-- Build files have been written to: /home/kali/lab03dz/project_root/solver_lib/build

[ 50%] Building CXX object CMakeFiles/solver_lib.dir/solver.cpp.o
[100%] Linking CXX static library libsolver_lib.a
[100%] Built target solver_lib

[sudo] password for kali: 
[100%] Built target solver_lib
Install the project...
-- Install configuration: ""
-- Installing: /usr/local/lib/libsolver_lib.a
-- Installing: /usr/local/include/solver.h

-- Configuring done (0.0s)
-- Generating done (0.0s)
-- Build files have been written to: /home/kali/lab03dz/project_root/hello_world/build

[ 50%] Building CXX object CMakeFiles/hello_world.dir/main.cpp.o
[100%] Linking CXX executable hello_world
[100%] Built target hello_world
Hello, world!


-- Configuring done (0.0s)
-- Generating done (0.0s)
-- Build files have been written to: /home/kali/lab03dz/project_root/solver/build

[ 50%] Building CXX object CMakeFiles/solver.dir/main.cpp.o
[100%] Linking CXX executable solver
[100%] Built target solver
Hello from solver!
```