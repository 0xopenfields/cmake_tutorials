# チュートリアル１
CMakeには、CMake-GUIというGUIでプロジェクトを出力する方法もありますが、敢えてコマンドベースで解説していきます

## CMakeLists.txtの書き方

CMakeコマンドでプロジェクトを出力するにはCMakeLists.txtを書きます  
CMakeコマンドがルートディレクトリのCMakeLists.txtを解釈してプロジェクトを作成します  

```cmake:tutorial_1/CMakeLists.txt
# CMakeの最低要求バージョンの定義
cmake_minimum_required(VERSION 3.13)
# プロジェクト名の定義
project(cmake_tutorial_1)
# プロジェクトにtutorial_1.ccを追加
add_executable(cmake_tutorial_1 tutorial_1.cc)
```

1. `cmake_minimum_required(VERSION 3.13)` でCMakeの最低要求バージョンを指定します(満たさない場合はエラーが出ます)   
2. `project(cmake_tutorial_1)`でプロジェクト名を定義します  
3. `add_executable(cmake_tutorial_1 tutorial_1.cc)`でcmake_tutorial1プロジェクトにtutorial_1.ccを追加します(tutorial_1.ccはただのhello, world)  

## ビルド

```
cd cmake_tutorials
cmake -S tutorial_1 -B build
cmake --build build
```

1. `cmake -S tutorial_1 -B build`  
    `-S tutorial_1`でソースコード(CMakeLists.txtのルート)を指定  
    `-B build`で中間・出力ディレクトリを指定、buildフォルダが作成されます

2. `cmake --build build`  
    `--build`はビルドコマンド  
    `--build build`でbuildフォルダをビルドする  

※CMake 3.12以前は以下のようにビルドしてました  

```
cd cmake_tutorials
mkdir build
cd build
cmake ../tutorial_1
make
```

## 実行
ビルドが成功するとbuildフォルダに中間ファイルや実行ファイルが出力されます  
出力先などはCMakeLists.txtで変更は可能ですが、その方法はまた別途  
今回はビルドオプションを指定していないのでDebugモードでビルドされているため、Winとその他で若干出力ディレクトリが異なる  
- Windows

```
build\Debug\cmake_tutorial_1.exe
```

- Mac/Linux

```
build/cmake_tutorial_1
```
