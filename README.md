# Problem 043 - 小可怜的双链表

**ACMOJ Problem ID**: 14296

## Table of Contents

- [Problem 043 - 小可怜的双链表](#problem-043-小可怜的双链表)
  - [Table of Contents](#table-of-contents)
  - [Introduction](#introduction)
    - [Background](#background)
  - [Assignment Description](#assignment-description)
    - [Grade Composition](#grade-composition)
  - [Assignment Requirements](#assignment-requirements)
    - [Input Format](#input-format)
    - [Output Format](#output-format)
    - [Samples](#samples)
    - [Data Constraints](#data-constraints)
  - [Per-Testcase Resource Limits](#per-testcase-resource-limits)
  - [Test Data](#test-data)
  - [Submission Requirements](#submission-requirements)
    - [OJ Git Repository Compilation Process](#oj-git-repository-compilation-process)
    - [Git Configuration Requirements](#git-configuration-requirements)
    - [Submission Guidelines](#submission-guidelines)
    - [Evaluation Notes](#evaluation-notes)
    - [Academic Integrity](#academic-integrity)

## Introduction

### Background

Implement doubly linked list with pointer and struct. Full CRUD operations.

## Assignment Description

### Grade Composition

| Grading Component | Percentage |
| :--: | :--: |
| Pass **14296. 小可怜的双链表** | 80% |
| Code Review | 20% |

Here are several points that need clarification:

- In the Code Review, we will **strictly examine your code style and repository organization structure, etc.**

- This assignment provides some sample data for testing, stored in the `/workspace/data/043/data_test/` directory. Note that these are not the test cases on the Online Judge. Passing all local test cases does not guarantee that you will pass the OJ tests.

- Besides the provided sample data, we also encourage you to design your own test data based on your program logic to assist debugging.

## Assignment Requirements

### Problem Description

author: 小可怜
原OJ链接：https://acm.sjtu.edu.cn/OnlineJudge-old/problem/4296

助教是个小可怜，因为她不知道要出什么机考题了。
然后她发现大家已经学完了指针和结构体，欣喜若狂。
她想让你写一个双链表。
你需要完成以下内容：（注意这里的i都为**0-base**）
- 0 返回链表长度

- 1 在位置i插入一个数，注意这里是指插入的数在插入后处于位置i，即插入在现在位置i数字的前面。

- 2 输出第x个数，如果x超出链表长度，请输出-1.

- 3 删除位置i的数，整个链表长度--。

- 4 输出整个list，如果表为空请输出-1。

- 为防止内存泄漏，你需要在程序最后删除整个列表，此项，我们会通过检查你的代码来确定你是否完成。

要求如下：

- 必须使用指针和结构体
- 在双链表中，每个结点有一个数据元素、一个后继指针、一个前驱指针组成，后继指针指向存储该元素直接后继的结点，前驱指针指向存储该元素直接前驱的结点。
- 存储一个单链表需要一个指向头结点的指针和一个指向尾结点的指针。
- 可以使用单独的变量记录链表长度
- 请严格按照以上要求完成此题。我们会检查你提交的代码。虽然有其他的实现方式，但如果你未按照要求写代码，我们**不会**给你分数。(比如，你没有使用指针和结构体或在每个结点中记录了要求以外的内容等等都会判为0分)。
- 请不要修改给定的部分。
- 同时，**此题需要你注意提交代码的代码风格！！！极为糟糕的代码风格（例如改变语法的某些宏定义）会酌情扣分！！！**

![](https://acm.sjtu.edu.cn/w/images/3/3d/Insert.png)

![](https://acm.sjtu.edu.cn/w/images/1/1a/Twolist.png)

`sample.cpp`

    #include <iostream>
    #include <cstdio>
    using namespace std;
    
    namespace LIST
    {
    
    struct NODE
    {
        // TODO
    };
    
    NODE *head = nullptr, *tail = nullptr;
    int len = 0;
    
    void Pre()
    {
        // TODO
    }
    NODE* move(int i)
    {
        // TODO
    }
    void insert(int i, int x)
    {
        // TODO
    }
    void remove(int i)
    {
        // TODO
    }
    int Get_length()
    {
        // TODO
    }
    int Query(int i)
    {
        // TODO
    }
    
    void Print()
    {
        // TODO
    }
    
    void Clear()
    {
        // TODO
    }
    
    }
    int n;
    int main()
    {
        cin >> n;
        int op, x, p, ans;
        LIST::Pre();
        for (int _=0;_<n;++_)
        {
            cin >> op;
            switch(op)
            {
                case 0:
                    ans = LIST::Get_length();
                    cout << ans << endl;
                    break;
                case 1:
                    cin >> p >> x;
                    LIST::insert(p,x);
                    break;
                case 2:
                    cin >> p;
                    ans = LIST::Query(p);
                    cout << ans << endl;
                    break;
                case 3:
                    cin >> p;
                    LIST::remove(p);
                    break;
                case 4:
                    LIST::Print();
                    break;
            }
        }
        LIST::Clear();
        return 0;
    }

### Input Format

第一行一个 $n$ 表示操作数  

之后 $n$ 行每行第一个数 $op$ 代表操作编号，分别对应前文中的编号。  

如果 $op$ 为 $1$，其后会输入两个整数 $p,x$，表示在 $p$ 位置插入的数值为 $x$。  

如果 $op$ 为 $2$，其后会输入一个整数 $p$，表示你需要输出链表中 $p$ 位置的值，输出要求见上。

(数据保证插入删除操作不会操作无效位置。)

### Output Format

对于操作1,3，你不用输出任何东西。

对于操作0，输出一个整数，表示链表长度。

对于操作2，输出一个整数，表示第x个数。

对于操作4，按链表顺序输出一行整数。

### Samples

#### Sample 1

**Input:**
```
```
16
0
1 0 1
1 0 2
1 2 3
4
2 1
1 2 4
4
3 2
4
1 0 5
2 3
2 4
3 0
4
0
```
```

**Output:**
```
```
0
2 1 3
1
2 1 4 3
2 1 3
3
-1
2 1 3
3
```
```

### Data Constraints

$n \leq 1000$, 保证链表中所有数字为int范围内正整数。

保证所给部分和所给要求不会产生超时问题。

测试点编号 | 包含操作号|  
-|-|
1 | 0、1 |
2 | 1、2、4 |
3 | 1、3、4 |
4 | all |
5 | all |

## Per-Testcase Resource Limits

- **Time Limit (per test case)**: 2000 ms
- **Memory Limit (per test case)**: 1024 MiB
- **Disk Usage**: No disk usage is permitted.

## Test Data

The test data for this problem is located at `/workspace/data/043/data_test/`.

## Submission Requirements

### OJ Git Repository Compilation Process

For Git compilation, we will first clone the repository using a command similar to:
```bash
git clone <repo_url> . --depth 1 --recurse-submodules --shallow-submodules --no-local
```

Then we check if there is a `CMakeLists.txt` file. If it exists, we run (if not, a warning message will be displayed):
```bash
cmake .
```

Finally, we check if there is any of `GNUmakefile`/`makefile`/`Makefile` (if cmake was run previously, this will be the generated Makefile). If it exists, we run (if not, a warning message will be displayed):
```bash
make
```

After this process is complete, we will use the `code` file in the project root directory as the compilation result.

A `CMakeLists.txt` file is provided in the project. You can use or modify it as needed. The local environment has gcc-13 and g++-13 available.

### Git Configuration Requirements

**IMPORTANT**: You must create a `.gitignore` file in your project root directory to avoid OJ evaluation conflicts.

The `.gitignore` file should include at least the following entries:

```gitignore
CMakeFiles/
CMakeCache.txt
```

### Submission Guidelines

- The submitted code must be able to compile successfully through the above compilation process
- The compiled executable file name must be `code`
- The program needs to be able to read data from standard input and write results to standard output
- Please ensure the code runs correctly within the given time and space limits
- **You must use C++ or C language** to implement this assignment

### Evaluation Notes

- The evaluation system will test your program using the provided test data
- The program output must exactly match the expected output (including format)
- Exceeding time or memory limits will be judged as the corresponding error type
- Please pay attention to the overall time performance of your code and the time complexity of each part of your algorithm.

### Academic Integrity

If any violations are found during evaluation or code review (including but not limited to using unconventional methods to pass test cases), your final score may be significantly reduced or become **0 points**.
