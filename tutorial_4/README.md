# チュートリアル４

CMakeでのライブラリの作り方、複数プロジェクトの作成について解説していきます

## ルートプロジェクト
`${CMAKE_SOURCE_DIR}`は予約語でルートのCMakeLists.txtがあるディレクトリを指します  
ライブラリ・アプリケーションの両者で必要になるディレクトリのため、変数\${MYLIB_INCLUDE_DIRS}にtutorial4/mylib/includeを代入しています  

`add_subdeirectory(ディレクトリ名)`でサブディレクトリのCMakeLists.txtを解析します  
指定したサブディレクトリには必ずCMakeLists.txtが必要です  

```CMake
cmake_minimum_required(VERSION 3.13)

project(cmake_tutorial_4)

set(MYLIB_INCLUDE_DIRS "${CMAKE_SOURCE_DIR}/mylib/include")

add_subdirectory(mylib)
add_subdirectory(tutorial_4)
```

## ライブラリ
ライブラリのプロジェクトを作成するには`add_library`を使用します  
ダイナミック/スタティックライブラリのどちらかを作成することができます  
指定方法は後述します  

```CMake
add_library(${PROJECT_NAME} ${CMAKE_CURRENT_SOURCE_DIR}/src/mylib.cc)
```

## 実行ファイル
`add_dependencies`で依存関係を定義します  
cmake_tutorial_4はmylibに依存する、つまりcmake_tutorial_4よりmylibが先にビルドされます  

`target_link_libraries`でライブラリをリンクします  
今回は同じCMakeプロジェクトなので`mylib`というプロジェクト名で自動的にライブラリへのパスが解決されます  
外部ライブラリを使用する場合はパスが必要になります(これについては別のセクションで記述します)  

```CMake
add_dependencies(${PROJECT_NAME} mylib)

target_include_directories(${PROJECT_NAME} PRIVATE ${MYLIB_INCLUDE_DIRS})

target_link_libraries(${PROJECT_NAME} mylib)
```

## ビルド

```
cd cmake_tutorials
cmake -S tutorial_4 -B build/tutorial_4 -D BUILD_SHARED_LIBS=ON
cmake --build build/tutorial_4
```

今回は`-D BUILD_SHARED_LIBS=ON`が追加されていることに注意してください  
`-D 変数名=値・文字列`でCMakeLists.txt内部の変数の初期値を代入する事ができます  
`BUILD_SHARED_LIBS=ON`にする事でダイナミックリンクを作成するように指定しています  
スタティックリンクを作成する場合は`BUILD_SHARED_LIBS=OFF`、もしくは何も設定しないでください(デフォルト値はOFF)  
