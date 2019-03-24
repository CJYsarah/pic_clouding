# Week 2 学习笔记

------

## 目录

- Q&A

- GIT

------

## Q&A

1. 如何在后台执行任务？

- 任务正在终端进行

~~~ mermaid
graph LR
A[Ctrl+Z 暂停当前进程]-->B[bg 将任务放在后台运行]
C[jobs 查看后台任务]
~~~

```c++

	$ tar -zxvf Markdown.tar.gz
	$ bg
	$ jobs

```

- 任务还未进行

```c++
	$ tar -zxvf Markdown.tar.gz.&
	$ jobs

```

- nohup 可保证用户退出终端后，任务仍在后台进行。

------

2. 如何批量替换文本

- 查找并替换

  $ sed -i "s/old_string/new_string/g" `grep -rl "要找查找的文本" ./`

- 查找文件包含内容

  $ grep -rn "find_string" ./

3. 快速查找文件或目录

- find

  根据文件属性查找

```c++
        $ find / -name LargeNum #根目录下查找LargeNum，在整个磁盘查找
        $ find /etc -name LargeNum #/etc下查找LargeNum
        $ find . -name 'La*' #/当前目录下查找以"La"开头的文件
        $ find / -amin -10 #/查找系统中最近十分钟访问的文件
        $ find / -empty #/查找空文件（夹）
```

- grep

  根据文件内容查找

------

4. 软链接

​	软链接可以看作Windows的快捷方式，可快速链接到目标、目录。

优点：没有文件系统的限制，任何用户可以创建指向目录的符号链接。

缺点：当原文件被移动到其他目录后，再访问链接文件，系统无法找到。

用法：

```
		$ ln -s sourc_file target_file
```

------

5. 环境变量

- 环境变量是操作系统或程序执行时候默认设定的参数。

- 测试当前环境变量：	

```
		$ echo $PATH
```

- 设置环境变量
  - 添加路径到PATH		
  - 命名新环境变量

```
	#添加路径到PATH
	$ export PATH=$PATH:/path/to/your/dir #加到PATH末尾
	$ export PATH=/path/to/your/dir:$PATH #加到PATH开头
```



------

6. 终端打包解包

- tar

![](/home/sarah/图片/2019-03-24 10-42-51屏幕截图tar.png)

- gz

| 功能 | 命令            |
| ---- | --------------- |
| 解压 | gunzip name.gz  |
| 解压 | gzip -d name.gz |
| 压缩 | gzip name       |

- bz2

| 功能 | 命令              |
| ---- | ----------------- |
| 解压 | bzip2 -d name.bz2 |
| 解压 | bunzip2 name.bz2  |
| 压缩 | bzip2 -z n        |

- bz

| 功能 | 命令             |
| ---- | ---------------- |
| 解压 | bzip2 -d name.bz |
| 解压 | bunzip2 name.bz  |

- zip

| 功能 | 命令                       |
| ---- | -------------------------- |
| 解压 | unzip name.zip             |
| 压缩 | zip file_name.zip dir_name |

------

## GIT

~~上周在网上找图床意外注册了github~~

![](/home/sarah/图片/github.png)

![](/home/sarah/图片/new.png)

![](/home/sarah/图片/git2.png)

![](/home/sarah/图片/git安装.png)

![](/home/sarah/图片/SSH keys.png)

![](/home/sarah/图片/SSH keys2.png)

![](/home/sarah/图片/fit2.png)

![](/home/sarah/图片/远程链接.png)

