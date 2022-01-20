# チュートリアル２
CMakeでinclude, 複数ファイルのビルド方法について解説していきます
gcc/g++で書くとこんな感じのやつですね
```
g++ -I include -c src/add.cc -o src/add.o
g++ -I include -c src/tutorial.cc src/add.o -o cmake_tutorial_2
```

## CMakeLists.txt

```CMake:tutorial_2/CMakeLists.txt
cmake_minimum_required(VERSION 3.13)

project(cmake_tutorial_2)

add_executable(cmake_tutorial_2
                src/tutorial_2.cc
                src/add.cc)

target_include_directories(cmake_tutorial_2 PRIVATE include)
```

1. `add_executable` でcmake_tutorial_2プロジェクトにsrc/tutorial_2.cc, src/add.ccを追加   
2. `target_include_directories`でcmake_tutorial_2プロジェクトのインクルードディレクトリにincludeを追加 

## ビルド

```
cd cmake_tutorials
cmake -S tutorial_2 -B build/tutorial_2
cmake --build build/tutorial_2
```

## 実行 
- Windows

```
build\tutorial_2\Debug\cmake_tutorial_2.exe
```

- Mac/Linux

```
build/tutorial_2/cmake_tutorial_2
```

---
出力結果
```
5 + 3 = 8
```