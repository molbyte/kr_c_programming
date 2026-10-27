---
tags:
  - Git
date: "Wednesday, May 27th 2026, 16: 47: 54 pm"
---

# 1. 背景

项目学习中，已经完成了一次`push`，GitHub存在历史提交记录，当前需求是：

```notes
删除一个用于测试的历史 commit
```

该commit存在于main分支历史中且已经push到了GitHub，不能简单通过git reset 完成，而是应该通过`git rebase -i`对历史进行重写。

# 2. 执行交互式rebase

```zsh
   // 对最近两个 commit 进行交互式历史编辑，HEAD~2代表从当前 HEAD 向前回退两个commit
   // Git 最终执行：取两个最近的 commit 重新构造链
   git rebase -i HEAD~2
```


# 3. rebase 相关理解
   
   并不是“删除commit”，而是 replay ，例如原始历史为：A <- B <- C，如果要删除 B ，是以A为基础重新应用 C ，生成新的 C1，这个 C1 != C，因为 commit hash 已经发生变化，本质上是生成了一条新的历史链。

# 4. Conflict

```zsh
CONFLICT (modify/delete):
ch05_ex01.c deleted in 16863ad
and modified in HEAD
```

## 4.1 冲突形成原理

重新形成历史链时发现某一侧历史已经删除了文件`ch05_ex01.c`，而当前HEAD状态又修改了该文件，Git无法自动判断最终应该保留文件还是删除文件。

## 4.2 最终解决

冲突本质在于**文件树发生了变化**，但无法理解自己最终真正想要保留那个状态，Git请求人类决策，此时明确执行`git rm ch05_ex01.c`即可。

解决后执行`git rebase --continue`，然后做出相应的处理，Git成功完成历史重写。

# 5. Push失败

本地历史和远程仓库历史完全不是同一条历史链，直接进行`git push`会被拒绝，错误的本质就在于`non-fast-forward`，即远程历史无法通过“前进”方式合并。

所以要执行`git push --force-with-lease`，使用本地新历史强制覆盖远程历史。`--force`会检查**远程是否被其他人更新**，避免误覆盖团队成员 commit 。