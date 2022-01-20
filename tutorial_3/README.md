# チュートリアル３
CMakeでの変数の使い方やデバッグプリントの仕方などについて解説していきます  
今回は、冗長ですがCMakeの使い方を説明するため、四則演算の関数を全て別のファイルに分けています  
tutorial_3/CMakeLists.txtを開いてください  
前回より少し複雑になっています  

## 変数
CMakeで変数に値を代入するには`set`を使用します  
CMakeでは変数の型がないので内部的には文字列になります  
変数の種類は値・文字列・BOOLの３種類があります  

```CMake
set(VAR_VALUE       1)
set(VAR_STR         "文字列")
set(VAR_BOOL        ON)
```

## デバッグ
CMakeで変数のデバッグをするには`message`を使用します  
`""`で囲んだ文字列の中でも`${変数名}`とすれば出力できます  
また、`STATUS`の他にもいくつかのオプションが存在する  
これについては別のセクションで解説予定  

```CMake
message(STATUS  "VAR_VALUE=${VAR_VALUE}")
message(STATUS  "VAR_STR=${VAR_STR}") 
message(STATUS  "VAR_BOOL=${VAR_BOOL}")
```

## 環境変数
CMakeでシステム環境変数を取得するには`$ENV{環境変数名}`を使用する  
下記の例は環境変数`PATH`を出力する  

```CMake
message(STATUS  "PATH=$ENV{PATH})")
```

## 変数の外部入力
CMakeを実行する時に`-D 変数名=値・文字列`を付けて実行すると外部から変数に値を代入できます  

例)

```
cmake -S tutorial_3 -B build/tutorial_3 -D VAR_FLAG=ON
```

## 分岐
分岐文は以下のように記述します  

```CMake
if(分岐条件1)
    処理1
else if(分岐条件2)
    処理2
else()
    処理3
endif()
```

tutorial_3/CMakeLists.txtの分岐例は以下のようになっています  
変数`VAR_FLAG`をcmake実行時にON/OFFを代入することで通る分岐が変わります  

```CMake
if(VAR＿FLAG)
    message(STATUS "VAR_FLAG is TRUE")
else()
    message(STATUS "VAR_FLAG is FALSE")
endif()
```

## ファイル・リスト
ファイルのリストを１つの変数に代入できます  
下記の例ではtutorial_3/srcフォルダの中のソースコードを変数`SOURCES`に代入しています  
また、`*`はワイルドカード、`${CMAKE_CURRENT_SOURCE_DIR}`は予約語です  
`${CMAKE_CURRENT_SOURCE_DIR}`は現在のCMakeLists.txtがあるディレクトリを指します  

```CMake
file(GLOB_RECURSE SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.c
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cc
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cxx)
```

## ループ 
ループ文は以下のように記述します  
`${SOURCES}`にはadd.cc, sub.cc, mul.cc, div.ccが代入されているので４回ループします  
順番にファイル名が変数`file`に代入されます  

```CMake
foreach(file ${SOURCES})
    message(STATUS ${file})
endforeach()
```

## プロジェクトへの一括追加
`add_executable(${PROJECT_NAME} ${SOURCES})`で変数\${SOURCES}に入力したファイルをプロジェクトに一括追加することができます  

```CMake
add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME} PRIVATE include)
```

## ビルド

```Shell
cd cmake_tutorials
cmake -S tutorial_3 -B build/tutorial_3 -D VAR_FLAG=ON
cmake --build build/tutorial_3
```

## 実行 
- Windows

```PowerShell
build\tutorial_3\Debug\cmake_tutorial_3.exe
```

- Mac/Linux

```
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