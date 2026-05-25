# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Project Overview

LeetCode Hot 100 题解练习，使用 C++。按题目分类组织目录结构。

## Directory Convention

```
<编号>_<题目英文名>/
  solution.cpp      # 题解代码，包含 main 函数用于本地测试
```

示例：`01_two_sum/solution.cpp`

## Build & Run

编译并运行单个题解：
```bash
g++ -std=c++17 -Wall -g <目录>/solution.cpp -o /tmp/leetcode_out && /tmp/leetcode_out
```

无构建系统，每道题独立编译运行。

## Coding Conventions

- 使用 C++17 标准
- 每道题的 `solution.cpp` 包含完整可编译代码（含 `#include` 和 `main`）
- `main` 中编写测试用例，验证后可复制纯 Solution 类到 LeetCode 提交
- 注释用中文解释思路
- 文件头注释格式：题号、题目名称、难度、核心算法标签
