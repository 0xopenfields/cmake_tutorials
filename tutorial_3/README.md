# チュートリアル３
CMakeでの変数の使い方やデバッグプリントの仕方などについて解説していきます  
今回は、冗長ですがCMakeの使い方を説明するため、四則演算の関数を全て別のファイルに分けています

## CMakeLists.txt
tutorial_3/CMakeLists.txtを開いてください  
前回より少し複雑になっています  

```CMake
file(GLOB_RECURSE SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cxx)
```

CMakeでは変数のアクセスは\${変数名}と記述します  
`${CMAKE_CURRENT_SOURCE_DIR}`はCMakeの予約語で、現在のCMakeLists.txtがあるディレクトリを指します  
`file(GLOB_RECURSE SOURCES 引数)`で変数SOURCEに引数にマッチするファイル名を入力します  
今回の場合、src/add.cc, src/sub.cc, src/mul.cc, src/div.ccになります  

```CMake
foreach(file ${SOURCES})
    message(STATUS ${file})
endforeach()
```
 
また、`message(STATUS "文字列")`でデバッグプリントします  
`foreach(file ${SOURCES})`はループ文です  
変数SOURCESから順番に変数fileにファイル名を格納して、`message(STATUS ${file})`でファイル名を出力します  

```CMake
add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME} PRIVATE include)
```

`${PROJECT_NAME}`、こちらも予約語です  
`project(cmake_tutorial_3)`で定義した名前が適用されます  
`add_executable(${PROJECT_NAME} ${SOURCES})`で変数\${SOURCES}に入力したファイルをプロジェクトに一括追加することができます  

## ビルド

```Shell
cd cmake_tutorials
cmake -S tutorial_3 -B build/tutorial_3
cmake --build build/tutorial_3
```

## 実行 
- Windows

```PowerShell
build\tutorial_3\Debug\cmake_tutorial_3.exe
```

- Mac/Linux

```Shell
build/tutorial_3/cmake_tutorial_3
```

---
出力結果
```
5 + 3 = 8
10 - 7 = 3
3 * 8 = 24.000000
13 / 3 = 4.333333
```

---
CMakeの予約語については[こちら](https://cmake.org/cmake/help/v3.22/manual/cmake-variables.7.html)