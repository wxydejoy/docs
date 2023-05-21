## 9.4 设置主题样式

使用Beamer制作幻灯片的一道特色就是有现成的主题样式可供选择和直接使用，其中，主题样式对于幻灯片的演示效果而言十分重要，简言之，主题样式就是幻灯片的“外观”，改变幻灯片最简单的方式就是变换不同的主题样式。Beamer中提供的每种主题样式都具有良好的可用性和可读性，这也使得Beamer制作出来的幻灯片看起来十分专业，同时，反复使用的难度也不大。

在英文中，主题对应的英文单词为theme。狭义来看，幻灯片主题是指幻灯片的主题样式；但从广义来看，其实幻灯片主题包括了包括主题样式、颜色主题、字体主题、内部主题、外部主题。

### 9.4.1 基本介绍

使用Beamer制作幻灯片时，我们可以选择很多已经封装好的幻灯片主题样式，不同样式可以达到不同的视觉效果。其实，使用这些主题样式的方法非常简单。通常来说，在前导代码中插入`\usetheme{}`命令即可，例如使用`Copenhagen`（哥本哈根主题样式）只需要在前导代码中申明`\usetheme{Copenhagen}`，这种方式调用主题样式是非常省事。

<p align="center">
<img align="middle" src="tikz_graphics/beamer_theme.png" width="800" />
</p>

<center><b>图9.4.1</b> Beamer文档类型中的主题样式</center>

在Beamer文档类型中，有几十种主题样式可供选择和使用，比较常用的主题样式包括以下这些：

- `Berlin`：柏林主题样式，默认样式为蓝色调。
- `Copenhagen`： 哥本哈根主题样式，默认样式为蓝色调。
- `CambridgeUS`：美国剑桥主题样式，默认样式为红色调。
- `Berkeley`：伯克利主题样式，默认样式为蓝色调。
- `Singapore`：新加坡主题样式。
- `Warsaw`：默认样式为蓝色调。

【**例37**】在`beamer`文档类型中使用`CambridgeUS`主题样式制作一个简单的幻灯片。

```tex
\documentclass{beamer}
\usetheme{CambridgeUS}

\begin{document}

\begin{frame}{Example}

This is a simple example for the CambridgeUS theme.

\end{frame}

\end{document}
```

编译上述代码，得到幻灯片如图9.4.1所示。

<p align="center">
<img align="middle" src="docs/latex/chapter-9/graphics/example_sec2_1.png" width="450" />
</p>

<center><b>图9.4.1</b> 编译后的幻灯片效果</center>

当然，在这些主题样式基础上，我们也能够使用一些特定的主题样式如颜色主题、字体主题、内部主题、外部主题对幻灯片的显示效果进行调整。

<p align="center">
<img align="middle" src="tikz_graphics/other_themes.png" width="600" />
</p>

<center><b>图9.4.2</b> Beamer文档类型中的其他几种主题设置</center>


### 9.4.2 颜色主题

使用Beamer制作幻灯片时，我们能够自行设置幻灯片主题样式的色调，使用`\usecolortheme{}`命令即可，这些色调包括`beetle`、`beaver`、`orchid`、`whale`、`dolphin`等。这里的色调又被称为颜色主题，它定义了幻灯片各部分的颜色搭配，设置特定的颜色主题后，我们能够得到不同的组合样式，具体可参考[https://hartwork.org/beamer-theme-matrix/](https://hartwork.org/beamer-theme-matrix/)网站提供的组合样式矩阵。

【**例38**】在`beamer`文档类型中使用`CambridgeUS`主题样式和`dolphin`色调制作一个简单的幻灯片。

```tex
\documentclass{beamer}
\usetheme{CambridgeUS}
\usecolortheme{dolphin}

\begin{document}

\begin{frame}{Example}

This is a simple example for the CambridgeUS theme with dolphin (color theme).

\end{frame}

\end{document}
```

编译上述代码，得到幻灯片如图9.4.3所示。

<p align="center">
<img align="middle" src="docs/latex/chapter-9/graphics/example_sec2_2.png" width="450" />
</p>

<center><b>图9.4.3</b> 编译后的幻灯片效果</center>


### 9.4.3 字体主题

实际上，对于幻灯片的文本字体，我们可以调用字体样式对其进行调整。在Beamer中，字体样式被称为字体主题，它定义了幻灯片的字体搭配。具体使用方法是：在前导代码中要用到的命令为`\usefonttheme{A}`，位置A填写的一般是字体类型，例如`serif`。

【**例39**】使用`beamer`文档类型创建一个简单的幻灯片，并在前导代码中申明使用`serif`对应的字体样式。

```tex
\documentclass{beamer}
\usefonttheme{serif}

\begin{document}

\begin{frame}

This is a simple example for using \alert{serif} font theme.

\end{frame}

\end{document}
```

编译上述代码，得到幻灯片如图9.4.4所示。

<p align="center">
<img align="middle" src="docs/latex/chapter-9/graphics/example_sec2_3.png" width="450" />
</p>

<center><b>图9.4.4</b> 编译后的幻灯片效果</center>

我们知道：在常规文档中，可以使用各种字体对应的宏包达到调用字体的作用，使用规则为`\usepackage{A}`，位置A填写的一般是字体类型，包括serif、avant、bookman、chancery、charter、euler、helvet、mathtime、mathptm、mathptmx、newcent、palatino、pifont、utopia等。

【**例40**】使用`beamer`文档类型创建一个简单的幻灯片，并在前导代码中申明使用字体`palatino`对应的宏包。

```tex
\documentclass{beamer}
\usepackage{palatino}

\begin{document}

\begin{frame}

This is a simple example for using \alert{palatino} font.

\end{frame}

\end{document}
```

编译上述代码，得到幻灯片如图9.4.5所示。

<p align="center">
<img align="middle" src="docs/latex/chapter-9/graphics/example_sec2_4.png" width="450" />
</p>

<center><b>图9.4.5</b> 编译后的幻灯片效果</center>

### 9.4.4 内部主题

内部主题定义了幻灯片展示区域的样式，如列表、定理等，内部主题不包括页眉、页脚、导航栏等部分。每一种主题样式都有默认的内部主题，更换内部主题需使用`\useinnertheme{A}`命令，位置A可供选择的内部主题包括`circles`、`rectangles`、`rounded`和`inmargin`。

【**例41**】在`beamer`文档类型中分别使用`circles`和`inmargin`两种内部主题制作幻灯片。

- 使用`circles`内部主题：

```tex
\documentclass{beamer}
\usetheme{CambridgeUS}
\usefonttheme{professionalfonts}
\useinnertheme{circles}

\begin{document}

\begin{frame}
\frametitle{Parent function}
\framesubtitle{A short list}

Please check out the following parent function list.
\begin{enumerate}
\item $y=x$
\item $y=|x|$
\item $y=x^{2}$
\item $y=x^{3}$
\item $y=x^{b}$
\end{enumerate}

\end{frame}

\end{document}
```

编译上述代码，得到幻灯片如图9.4.6所示。

<p align="center">
<img align="middle" src="docs/latex/chapter-9/graphics/example_innertheme_circles.png" width="450" />
</p>

<center><b>图9.4.6</b> 编译后的幻灯片效果</center>

- 使用`inmargin`内部主题：

```tex
\documentclass{beamer}
\usetheme{CambridgeUS}
\usefonttheme{professionalfonts}
\useinnertheme{inmargin}

\begin{document}

\begin{frame}
\frametitle{Parent function}
\framesubtitle{A short list}

Please check out the following parent function list.
\begin{enumerate}
\item $y=x$
\item $y=|x|$
\item $y=x^{2}$
\item $y=x^{3}$
\item $y=x^{b}$
\end{enumerate}

\end{frame}

\end{document}
```

编译上述代码，得到幻灯片如图9.4.7所示。

<p align="center">
<img align="middle" src="docs/latex/chapter-9/graphics/example_innertheme_inmargin.png" width="450" />
</p>

<center><b>图9.4.7</b> 编译后的幻灯片效果</center>


### 9.4.5 外部主题

外部主题定义了幻灯片的边框、页眉、页脚、导航栏等部分的样式。更换外部主题需使用`\useoutertheme{A}`，位置A可供选择的外部主题包括`infolines`、`smoothbars`、`sidebar`、`split`和`tree`。

### 9.4.6 表格字体大小

在Beamer中制作表格，当我们想对表头或者表格内容文字大小进行调整时，可以使用在前导代码中申明使用`caption`宏包，即`\usepackage{caption}`，然后设置具体的字体大小即可，如`\captionsetup{font = scriptsize, labelfont = scriptsize}`可以将表头和表格内容字体大小调整为`scriptsize`。

【**例9-41**】使用`\begin{table} \end{table}`环境创建一个简单表格，并使用`caption`宏包将表头字体大小设置为`Large`、将表格内容字体大小设置为`large`。

```tex
\documentclass{beamer}
\usepackage{booktabs}
\usepackage{caption}
\captionsetup{font = large, labelfont = Large}

\begin{document}

\begin{frame}

\begin{table}
\caption{A simple table.}
\begin{tabular}{l|ccc}
\toprule
& \textbf{header3} & \textbf{header4} & \textbf{header5} \\
\midrule
\textbf{header1} & cell1 & cell2 & cell3 \\
\midrule
\textbf{header2} & cell4 & cell5 & cell6 \\
\bottomrule
\end{tabular}
\end{table}

\end{frame}

\end{document}
```

编译上述代码，得到幻灯片如图9.4.6所示。

<p align="center">
<img align="middle" src="docs/latex/chapter-9/graphics/example_sec2_4_0.png" width="450" />
</p>

<center><b>图9.4.6</b> 编译后的幻灯片效果</center>

其中，单就设置表头字体大小而言，除了使用`caption`宏包之外，还可以通过对幻灯片设置全局参数达到调整字体大小的效果，例如`\setbeamerfont{caption}{size = \Large}`。


### 9.5.4 样式调整

在Beamer文档类型中，除了可以使用各种主题样式，另外也可以根据幻灯片组成部分，分别对侧边栏、导航栏以及Logo等进行调整。其中，侧边栏是由所选幻灯片主题样式自动生成的，主要用于显示幻灯片目录。有时为了显示幻灯片的层次，使用侧边栏进行目录索引。

【**例9-42**】使用`Berkeley`主题样式，并将侧边栏显示在右侧。

```tex
\documentclass{beamer}
\PassOptionsToPackage{right}{beamerouterthemesidebar}
\usetheme{Berkeley}
\usefonttheme{professionalfonts}

\begin{document}

\begin{frame}
\frametitle{Parent function}
\framesubtitle{A short list}

Please check out the following parent function list.
\begin{enumerate}
\item $y=x$
\item $y=|x|$
\item $y=x^{2}$
\item $y=x^{3}$
\item $y=x^{b}$
\end{enumerate}

\end{frame}

\end{document}
```

编译上述代码，得到幻灯片如图9.4.7所示。

<p align="center">
<img align="middle" src="docs/latex/chapter-9/graphics/example_sec2_6.png" width="450" />
</p>

<center><b>图9.4.7</b> 编译后的幻灯片效果</center>

很多时候我们会发现，在各类学术汇报中，幻灯片的首页通常会有主讲人所在的研究机构Logo。在Beamer文档类型中，有`\logo`和`\titlegraphic`两个命令可供使用，使用`\logo`命令添加的Logo会在每一页幻灯片中都显示，而使用`\titlegraphic`命令添加的Logo只出现在标题页。

【**例9-43**】使用`\logo`命令在幻灯片中添加Logo。

```tex
\documentclass{beamer}
\usefonttheme{professionalfonts}

\title{A Simple Beamer Example}
\author{Author's Name}
\institute{Author's Institute}

\logo{\includegraphics[width=2cm]{logopolito}}

\begin{document}

\begin{frame}
\titlepage
\end{frame}

\begin{frame}{Parent function}{A short list}
Please check out the following parent function list.
\begin{enumerate}
\item $y=x$
\item $y=|x|$
\item $y=x^{2}$
\item $y=x^{3}$
\item $y=x^{b}$
\end{enumerate}
\end{frame}

\end{document}
```

编译上述代码，得到幻灯片如图9.4.8所示。

<p align="center">
<table>
<tr>
<td><img align="middle" src="docs/latex/chapter-9/graphics/example_sec2_7_0.png" width="450"></td>
<td><img align="middle" src="docs/latex/chapter-9/graphics/example_sec2_7_1.png" width="450"></td>
</tr>
</table>
</p>

<center><b>图9.4.8</b> 编译后的幻灯片效果</center>

【**例9-44**】使用`\titlegraphic`命令在幻灯片的标题页添加Logo。

```tex
\documentclass{beamer}
\usefonttheme{professionalfonts}

\title{A Simple Beamer Example}
\author{Author's Name}
\institute{Author's Institute}

\titlegraphic{\includegraphics[width=2cm]{logopolito}\hspace*{4.75cm}~
   \includegraphics[width=2cm]{logopolito}
}

\begin{document}

\begin{frame}
\titlepage
\end{frame}

\begin{frame}{Parent function}{A short list}
Please check out the following parent function list.
\begin{enumerate}
\item $y=x$
\item $y=|x|$
\item $y=x^{2}$
\item $y=x^{3}$
\item $y=x^{b}$
\end{enumerate}
\end{frame}

\end{document}
```

编译上述代码，得到幻灯片如图9.4.9所示。

<p align="center">
<table>
<tr>
<td><img align="middle" src="docs/latex/chapter-9/graphics/example_sec2_8_0.png" width="450"></td>
<td><img align="middle" src="docs/latex/chapter-9/graphics/example_sec2_8_1.png" width="450"></td>
</tr>
</table>
</p>

<center><b>图9.4.9</b> 编译后的幻灯片效果</center>


### 参考资料

- Prathik Naidu, Adam Pahlavan. [Fun with Beamer: An Epic Quest To Create the Perfect Presentation](http://web.mit.edu/rsi/www/pdfs/beamer-tutorial.pdf), June 28, 2017.
- [Beamer: change size of figure caption](https://tex.stackexchange.com/questions/52132).
- [logo in the first page only](https://tex.stackexchange.com/questions/61051).

【回放】[**9.3 块与盒子——添加框元素**](https://nbviewer.jupyter.org/github/xinychen/latex-cookbook/blob/main/chapter-9/section3.ipynb)

【继续】[**9.5 插入程序源代码**](https://nbviewer.jupyter.org/github/xinychen/latex-cookbook/blob/main/chapter-9/section5.ipynb)

### License

<div class="alert alert-block alert-danger">
<b>This work is released under the MIT license.</b>
</div>