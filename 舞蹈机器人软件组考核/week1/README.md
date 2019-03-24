# README

------

## 目录

- Linux指令学习

- Linux编程学习

  - C++编写程序

  - 编译方法

    - g++

    - make

    - make

      ------

      

### Linux指令学习



#### 1.wget

​	从指定URL下载文件

#### 2.pwd

​	显示当前目录的绝对路径

![](/home/sarah/%E5%9B%BE%E7%89%87/pwd.png)

#### 3.cd

		切换当前工作目录到dirName，可用直接路径或间接路径

|        选项        |          功能          |
| :----------------: | :--------------------: |
|       （空）       |     进入用户主目录     |
|         ~          |     进入用户主目录     |
|         -          | 返回进入该目录前的目录 |
|         ..         |      返回上级目录      |
|       ../..        |     返回上两级目录     |
| 直接路径、间接路径 |    进入路径所指目录    |

![](/home/sarah/%E5%9B%BE%E7%89%87/cd.png)

#### 4.ls

		显示指定目录下内容  

|     选项      |                  功能                   |
| :-----------: | :-------------------------------------: |
|      -a       |         显示当前目录下所有文件          |
|      -A       | 显示除'.'、'..'的文件（不显示隐藏文件） |
|      -1       |                单列输出                 |
|      -l       |            显示文件详细信息             |
|      -t       |           按最后修改时间排序            |
|      -S       |             按文件大小排序              |
| -F \| grep /$ |              只显示子目录               |

![](/home/sarah/%E5%9B%BE%E7%89%87/ls.png)

#### 5.mkdir

		创建目录

- 目录名前没有路径时，在当前目录下创建
- 目录名前有路径时，`按指定路径创建`  

![](/home/sarah/%E5%9B%BE%E7%89%87/mkdir0.png)

![](/home/sarah/%E5%9B%BE%E7%89%87/mkdir.png)

![](/home/sarah/%E5%9B%BE%E7%89%87/mkdir2.png)

![](/home/sarah/%E5%9B%BE%E7%89%87/mkdir3.png)

#### 6.mv

		更改文件名称或文件地址

![](/home/sarah/%E5%9B%BE%E7%89%87/mv1.png)

![](/home/sarah/%E5%9B%BE%E7%89%87/mv2.png)

![](/home/sarah/%E5%9B%BE%E7%89%87/mv3.png)  

![](/home/sarah/%E5%9B%BE%E7%89%87/mv4.png)

#### 7. rm

		删除目录或文件且无法恢复

#### 8. tar



| 选项  |       功能        |
| :---: | :---------------: |
| -cvf  |  仅打包、不压缩   |
| -zcvf | 打包并以gzip压缩  |
| -jcvf | 打包并以bzip2压缩 |

| 选项  |     功能      |
| :---: | :-----------: |
| -ztvf | 查询tar包内容 |

| 选项  |  功能  |
| :---: | :----: |
| -zxvf | 解压缩 |

#### 9. grep

		文本搜索

#### 10. find

		指定目录下查找文件

------

### Linux编程学习

#### C++编写程序

- 实现功能：计算给定日期n天后的日期

- 输入输出：

  头文件<iostream>：

  ​	定义cin、cout、cerr和clog，分别对应标准输入流、标准输出流、非缓冲标准输入流和缓冲标准错误流。

  - cin与>>结合使用：

  ​		可单独使用，如：cin >> n;

  ​		可多次使用、连续输入，如：cin >> today.year>>today.month>>today.day;

  - cout与<<结合使用：

  ​		<<被重载来输出内置类型的数据，如整型、浮点型、字符型；

  ​		endl用于换行，相当于C中\n。

- 程序结构：

  - 头文件date.h：

    ```c++
    #ifndef x //测试c是否被宏定义过
    #define x
    	part1 //若没被定义过，定义x，编译代码段1
    #endif
    	part2 //若被定义过，编译代码段2
    ```

  - 源文件

    ​	主函数中进行输入输出	

    ​	根据输入条件调用when函数，实现日期计算功能					

![](/home/sarah/图片/date.h.png)



![](/home/sarah/图片/main1.png)

![](/home/sarah/图片/main2.png)

------



#### 编译方法

##### g++

- 单一源文件编译

  - 预处理          

     g++ -E hello.cpp -o hello.i	

    //-E 激活与处理程序

  - 编译

    g++ -S hello.i -o hello.s

  - 汇编

    g++ -c hello.s -o hello.o

  - 链接

      g++ hello.o -o hello

  无选项编译链接

  ​	g++ hello.c 

​		//未指定输出文件名时自动命名为a.out

![](/home/sarah/图片/Hello.png)

![](/home/sarah/图片/hello.png)

- 多源文件编译

  - 对源文件分别编译后进行链接

    ```c++
    g++ -c test.c -o test.o
    g++ -c func.c -o func.o
    g++ -o test.o func.o -o test
    ```

  - 多源文件一起编译

![](/home/sarah/图片/date1.png)

​		![](/home/sarah/图片/date2.png)



------

##### Cmake

- 编译原理

~~~mermaid
graph TD
A(Cmake编写CMakeLists.txt)-->B(make需要的makefile)
B-->C(make命令编译源码)

~~~

- 编译过程

  - 准备程序文件

    - 文件目录结构

      ![](/home/sarah/图片/目录结构.png)

    - 头文件add.h

      ![](/home/sarah/图片/add.h.png)

    - 头文件sub.h

      ![](/home/sarah/图片/sub.h.png)

    - 函数代码add.cpp

      ![](/home/sarah/图片/add.cpp.png)

    - 函数代码sub.cpp

      ![](/home/sarah/图片/sub.cpp.png)

    - main.cpp

      ![](/home/sarah/图片/main.cpp.png)

  - 编写CMakeLists.txt

    ![](/home/sarah/图片/CMakeList.png)

  - 编译运行

  ![](/home/sarah/图片/cmake2.png)

  ![](/home/sarah/图片/cmake3.png)

------

##### make

- 主函数、功能函数、头文件库函数同Cmake

- makefile

  ![](/home/sarah/图片/makefile.png)

- 终端操作

  ![](/home/sarah/图片/make.png)

  > ![](/home/sarah/图片/make2.png)



------

