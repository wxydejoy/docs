## 10.1 添加程序源代码

很多时候，在技术文档中添加程序源代码具有一定的必要性，这源于：

- 在很多文档（如实验报告）中，程序源代码往往作为重要组成部分，必须作为辅助材料放在文档末尾的附录中。
- 程序源代码既可以直接展现计算机编程的实现过程和细节，又可以评估实验的真实性，同时也能供读者学习和使用。

事实上，使用LaTeX制作文档时，添加程序源代码是一件看似简单、但又比较考验技巧的事，因为在文档中添加程序源代码并不能通过简单的“复制+粘贴”来实现。我们需要保持代码在原来程序语言中的格式，包括代码所采用的高亮颜色和等宽字体，目的都是为了让代码本来的面貌得以完美展现。

在LaTeX中，有很多宏包可供制作文档时添加程序源代码到正文或附录中，最常用的宏包包括`listings`和`minted`这两种，除此之外，还有一种插入程序源代码非常简便的一种方式，即使用`\begin{verbatim} \end{verbatim}`环境。

### 10.1.1 使用verbatim插入程序源代码

在LaTeX中插入Python代码可以使用`verbatim`环境，即在`\begin{verbatim} \end{verbatim}`之间插入代码，代码的文本是等宽字体。需要注意的是，这一环境不会对程序源代码进行高亮处理。

【**例1**】使用`verbatim`环境插入如下Python代码：

```python
import numpy as np

x = np.random.rand(4)
print(x)
```

```tex
\documentclass[12pt]{article}

\begin{document}

Python code example:

\begin{verbatim}
import numpy as np

x = np.random.rand(4)
print(x)
\end{verbatim}
\end{document}
```

编译后效果如图10.1.1所示。

<p align="center">
<img align="middle" src="docs/latex/chapter-10/graphics/example10_1_1.png" width="450" />
</p>

<center><b>图10.1.1</b> 编译后效果</center>

### 10.1.2 使用listings插入程序源代码

如果想要对程序源代码进行高亮处理，可以使用专门排版代码的工具包`listings`，除了在前导代码中申明使用`listings`工具包，即`\usepackage{listings}`，有时候还可以根据需要自定义一些参数。

【**例2**】使用`listings`工具包插入如下Python代码：

```python
import numpy as np

x = np.random.rand(4)
print(x)
```

```tex
\documentclass[12pt]{article}
\usepackage{listings}

\begin{document}

Python code example:

\begin{lstlisting}[language = python]
import numpy as np

x = np.random.rand(4)
print(x)
\end{lstlisting}
\end{document}
```

编译后效果如图10.1.2所示。

<p align="center">
<img align="middle" src="docs/latex/chapter-10/graphics/example10_1_2.png" width="450" />
</p>

<center><b>图10.1.2</b> 编译后效果</center>

> 参考listings使用手册[The Listings Package](https://texdoc.org/serve/listings.pdf/0)。

【**例3**】使用`listings`工具包插入Python代码，并自定义代码高亮。

```tex
\documentclass[12pt]{article}
\usepackage{listings}
\usepackage{color}
\definecolor{codegreen}{rgb}{0,0.6,0}
\definecolor{codegray}{rgb}{0.5,0.5,0.5}
\definecolor{codepurple}{rgb}{0.58,0,0.82}
\definecolor{backcolour}{rgb}{0.95,0.95,0.92}

\lstdefinestyle{mystyle}{
    backgroundcolor=\color{backcolour},   
    commentstyle=\color{codegreen},
    keywordstyle=\color{magenta},
    numberstyle=\tiny\color{codegray},
    stringstyle=\color{codepurple},
    basicstyle=\ttfamily\footnotesize,
    breakatwhitespace=false,         
    breaklines=true,                 
    captionpos=b,                    
    keepspaces=true,                 
    numbers=left,                    
    numbersep=5pt,                  
    showspaces=false,                
    showstringspaces=false,
    showtabs=false,                  
    tabsize=2
}

\lstset{style=mystyle}

\begin{document}

Python code example:

\begin{lstlisting}[language = python]
import numpy as np

x = np.random.rand(4)
print(x)
\end{lstlisting}
\end{document}
```

编译后效果如图10.1.3所示。

<p align="center">
<img align="middle" src="docs/latex/chapter-10/graphics/example10_1_3.png" width="450" />
</p>

<center><b>图10.1.3</b> 编译后效果</center>

> 参考[Code listing](https://www.overleaf.com/learn/latex/Code_listing)。



【回放】[**导言**](https://nbviewer.jupyter.org/github/xinychen/latex-cookbook/blob/main/chapter-10/section0.ipynb)

【继续】[**10.2 算法伪代码**](https://nbviewer.jupyter.org/github/xinychen/latex-cookbook/blob/main/chapter-10/section2.ipynb)

### License

<div class="alert alert-block alert-danger">
<b>This work is released under the MIT license.</b>
</div>