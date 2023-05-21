## 5.4 调整表格样式

通过调用一些宏包及命令可以定制表格样式，从而创建更符合要求的表格。对表格样式的调整可以分为以下7个方面：表格尺寸、单元格自动对齐与换行、小数点对齐、行高、列宽、线宽、以及表格字体大小。

### 5.4.1 表格尺寸

如果想要修改表格尺寸，首先使用`\usepackage{graphicx}`语句调用`graphicx`宏包，并使用`\resizebox{宽度}{高度}{内容}`命令，该命令以`tabular`环境构建的表格作为内容。为了避免产生不协调的尺寸，在设置参数时只需要设置`{宽度}`和`{高度}`中的其中一个即可，另一个以`!`作为参数，表示根据宽高比进行自动调整。

【**例5-9**】使用`\resizebox`命令调整表格尺寸。

```tex
\documentclass[12pt]{article}
\usepackage{graphicx}
\begin{document}

This is the description for the following table. This is the description for the following table. This is the description for the following table. This is the description for the following table.

\begin{table}[h]
\centering
    \caption{Title of a table.}
    \label{first label}
    \resizebox{0.8\textwidth}{!}{
    \begin{tabular}{|l|l|l|l|}
        \hline
        Column1 & Column2 & Column3 & Column4 \\
        \hline
        A1 & A2 & A3 & A4 \\
        \hline
        B1 & B2 & B3 & B4 \\
        \hline
        C1 & C2 & C3 & C4 \\
        \hline
    \end{tabular}}
\end{table}   

\end{document}
```

编译上述代码，得到表格如图5.4.1所示。

<p align="center">
<img align="middle" src="graphics/eg5_6.png" width="350" />
</p>

<center><b>图5.4.1</b> 编译后的文档内容</center>

### 5.4.2 单元格自动对齐与换行

使用列类型参数`l`、`c`或`r`可以对每列的单元格设置左对齐、横向居中对齐和右对齐，但由此创建的单元格不仅无法设置顶部对齐、纵向居中对齐、以及底部对齐方式，而且单元格内容不论长短都被拉长为一行，显得不够灵活。下面介绍几种方式用于实现单元格自动对齐与换行。

#### （1）使用`array`宏包实现单元格自动对齐与换行

首先在导言区使用`\usepackage{array}`语句声明调用`array`宏包，该宏包提供了以下6个列类型参数分别对应不同的对齐方式：

- `p{列宽}`：单元格内容将根据设置的列宽自动换行，并且对齐方式为顶部对齐；

- `m{列宽}`：单元格内容将根据设置的列宽自动换行，并且对齐方式为纵向居中对齐；

- `b{列宽}`：单元格内容将根据设置的列宽自动换行，并且对齐方式为底部对齐；

- `>{\raggedright\arraybackslash}`：将一列的单元格内容设置为左对齐；

- `>{\centering\arraybackslash}`：将一列的单元格内容设置为横向居中对齐；

- `>{\raggedleft\arraybackslash}`：将一列的单元格内容设置为右对齐。

默认情况下，如果单独使用`p`、`m`或`b`参数，默认为左对齐。我们可以对上述参数进行组合使用，从而获得不同的对齐效果。需要注意的是，此时应使用`\tabularnewline`取代`\\`符号作为表格一行的结束。

【**例5-10**】调用`array`宏包及其提供的列类型参数实现单元格自动对齐与分行。

```tex
\documentclass[12pt]{article}
\usepackage{array}
\begin{document}

\begin{table}[h]
\centering
    \caption{Title of a table.}
    \label{first label}
    \begin{tabular}{|>{\raggedright\arraybackslash}m{2.3cm}|>{\centering\arraybackslash}m{2.3cm}|>{\centering}m{2.3cm}|>{\raggedleft\arraybackslash}m{2.3cm}|}
        \hline
        Column1 & Column2 Column2 & Column3 Column3 Column3 & Column4 Column4 Column4 Column4 \tabularnewline
        \hline
        Value1 & Value2 Value2 & Value3 Value3 Value3 & Value4 Value4 Value4 Value4 \tabularnewline
        \hline
        Value1 & Value2 Value2 & Value3 Value3 Value3 & Value4 Value4 Value4 Value4 \tabularnewline
        \hline
    \end{tabular}
\end{table}

\end{document}
```

编译上述代码，得到表格如图5.4.2所示。

<p align="center">
<img align="middle" src="graphics/eg5_7.png" width="350" />
</p>

<center><b>图5.4.2</b> 编译后的文档内容</center>

通过调用`array`宏包的方式虽然可以实现自动换行，但常常需要经过反复试验才能获得想要的宽度，更方便的方式是使用`tabularx`宏包或`tabulary`宏包及其相关命令自动计算列宽。对于涉及文本的表格，更推荐使用`tabulary`宏包。下面分别介绍通过这两个宏包及其命令如何实现自动换行。

#### （2）使用`tabularx`宏包实现自动换行

首先在导言区声明调用`tabularx`宏包，然后使用`\begin{tabularx} \end{tabularx}`环境取代`\begin{tabular} \end{tabular}`环境创建表格内容，`tabularx`环境的使用方式与`tabular`类似，不同之处主要在于：`\begin{tabularx}{表格宽度}{列类型}`中应设置表格宽度；在`tabularx`环境中，对于需要自动换行的列，其列类型应设置为大写的`X`。`X`参数可以与`>{\raggedright\arraybackslash}`、`>{\centering\arraybackslash}`或`>{\raggedleft\arraybackslash}`进行组合使用，从而修改单元格的对齐方式。

【**例5-11**】调用`tabularx`宏包并设置列类型参数`X`从而实现单元格内容自动换行。

```tex
\documentclass[12pt]{article}
\usepackage{array}
\usepackage{tabularx} % 调用tabularx宏包
\begin{document}

\begin{table}[h]
\centering
    \caption{Title of a table.}
    \label{first label}
    \begin{tabularx}{\linewidth}{|X|X|X|>{\centering\arraybackslash}X|} % 将需要自动换行的列的列类型参数设为X
        \hline
        Column1 & Column2 & Column3 & Column4 \\
        \hline
        This is Value1. This is Value1. & This is Value2. This is Value2. & This is Value3. This is Value3. & This is Value4. This is Value4. \\
        \hline
        This is Value1. This is Value1. This is Value1. & This is Value2. This is Value2. This is Value2. & This is Value3. This is Value3. This is Value3. & This is Value4. This is Value4. This is Value4. \\
        \hline
    \end{tabularx}
\end{table}

\end{document}
```

编译上述代码，得到表格如图5.4.3所示。

<p align="center">
<img align="middle" src="graphics/eg5_8.png" width="350" />
</p>

<center><b>图5.4.3</b> 编译后的文档内容</center>

#### （3）使用`tabulary`宏包实现自动换行

类似地，调用`tabulary`宏包并使用`\begin{tabulary}{表格宽度}{列类型} \end{tabulary}`环境创建表格。对于需要自动换行的列，只需将列类型改为大写字母即可，即，大写`L`表示左对齐并自动换行、大写`C`表示居中对齐并自动换行、大写`R`表示右对齐并自动换行。

【**例5-12**】调用`tabulary`宏包并设置大写列类型参数（`L`、`C`和`R`）从而实现单元格内容自动换行。

```tex
\documentclass[12pt]{article}
\usepackage{array}
\usepackage{tabulary} % 调用tabulary宏包
\begin{document}

\begin{table}[h]
\centering
    \caption{Title of a table.}
    \label{first label}
    \begin{tabulary}{\linewidth}{|L|C|C|R|} % 将需要自动换行的列的列类型参数改为大写
        \hline
        Column1 & Column2 & Column3 & Column4 \\
        \hline
        This is Value1. This is Value1. & This is Value2. This is Value2. & This is Value3. This is Value3. & This is Value4. This is Value4. \\
        \hline
        This is Value1. This is Value1. This is Value1. & This is Value2. This is Value2. This is Value2. & This is Value3. This is Value3. This is Value3. & This is Value4. This is Value4. This is Value4. \\
        \hline
    \end{tabulary}
\end{table}

\end{document}
```

编译上述代码，得到表格如图5.4.4所示。

<p align="center">
<img align="middle" src="graphics/eg5_9.png" width="350" />
</p>

<center><b>图5.4.4</b> 编译后的文档内容</center>

#### （4）使用`\parbox`命令实现人工换行

我们也可以通过使用`\parbox`命令对表格内容进行强制换行：

【**例5-13**】用`\parbox`命令来实现单元格中文本强制换行。

```tex
\documentclass{article} 
\begin{document}
\begin{center}    
    \begin{tabular}{|c|c|c|c|}
        \hline
        a & b & c & d \\ 
        \hline
        a & b & c & \parbox[t]{5cm}{In probability theory and statistics, the continuous uniform distribution\\ or rectangular distribution is a family of symmetric probability distributions.} \\ 
        \hline
    \end{tabular} 
\end{center}
\end{document}
```

编译上述代码，得到表格如图5.4.5所示。
<p align="center">
<img align="middle" src="graphics/example_sec2_6.png" width="350" />
</p>

<center><b>图5.4.5</b> 编译后的文档内容</center>

### 5.4.3 小数点对齐

为了更好地描述数据，在表格中常常将数据在小数点处进行对齐，在LaTeX中我们可以通过使用`dcolumn`包实现这一目的。这个包提供了一个名为`D`的列类型，可以方便实现基于小数点的数字对齐以及基于其它符号的对齐，使用方式为`D{输入符号}{输出符号}{符号后的数字位数}`。对于基于小数点的数字对齐，输入符号一般为“.”；有时需要根据特定符号进行数字对齐，比如千分位逗号，这时输入符号即为“,”。例如，`D{.}{\cdot}{2}`表示将某列的数据根据“.”符号对齐，输出时将该符号显示为点乘符号，并且显示2个小数位数。

列类型`D`可以像其它列类型一样在表格环境的开始命令处直接进行设置，但会导致语句过长，所以一般使用`array`宏包的`\newcolumntype`命令定义一个新的列类型，并为这个列类型赋予一个比较短的名称以方便调用。定义新的列类型的语句为`\newcolumntype{新列类型名称}[新列类型的参数个数]{定义新列类型}`，例如：`\newcolumntype{d}[1]{D{.}{\cdot}{#1}}`表示创建一个名为`d`的新列类型，该列类型的内容为`D{.}{\cdot}{符号后的数字位数}`，其中数字位数是传给`d`的参数。

【**例5-14**】调用`dcolumn`宏包和列类型`D`来实现表格数据的小数点对齐。

```tex
\documentclass[12pt]{article}
\usepackage{dcolumn}
\newcolumntype{d}[1]{D{.}{\cdot}{#1}}
\begin{document}
    \begin{tabular}{|l|c|r|d{3}|}
        \hline
        Left & Center & Right & \mathrm{Decimal}\\
        \hline
        1.1 & 1.1 & 1.1 & 1.1\\
        \hline
        33.3 & 33.3 & 33.3 & 33.3\\
        \hline
        3.333 & 3.333 & 3.333 & 3.333\\
        \hline
    \end{tabular}
\end{document}
```

编译上述代码，得到表格如图5.4.6所示。
<p align="center">
<img align="middle" src="graphics/eg5_10.png" width="350" />
</p>

<center><b>图5.4.6</b> 编译后的文档内容</center>

### 5.4.4 行高

如果需要调整表格整体行高，可以在导言区使用`\renewcommand{\arraystretch}{行高倍数}`命令，从而根据设置的行高倍数在默认值的基础上对行高进行扩大或缩小。

【**例5-15**】使用`\renewcommand{\arraystretch}{2}`命令将表格整体行高设为两倍行距。

```tex
\documentclass[12pt]{article}
\renewcommand{\arraystretch}{2}
\begin{document}

\begin{tabular}{|c|c|c|c|}
    \hline
    Column1 & Column2 & Column3 & Column4\\
    \hline
    A1 & A2 & A3 & A4\\
    \hline
    B1 & B2 & B3 & B4\\
    \hline
    C1 & C2 & C3 & C4\\
    \hline
\end{tabular}

\end{document}
```

编译上述代码，得到表格如图5.4.7所示。
<p align="center">
<img align="middle" src="graphics/eg5_15new.png" width="350" />
</p>

<center><b>图5.4.7</b> 编译后的文档内容</center>

另一种调整行高的方式是通过在每行的结束标志`\\`后加上行高增减量选项，即`\\[行高增减量]`，从而在默认值的基础上对各行行高进行增减。

【**例5-16**】使用`\\[行高增减量]`命令为表格各行设置不同的行高。

```tex
\documentclass[12pt]{article}
\begin{document}

\begin{tabular}{|c|c|c|c|}
    \hline
    Column1 & Column2 & Column3 & Column4\\[0cm]
    \hline
    A1 & A2 & A3 & A4\\[0.2cm]
    \hline
    B1 & B2 & B3 & B4\\[0.4cm]
    \hline
    C1 & C2 & C3 & C4\\[0.6cm]
    \hline
\end{tabular}

\end{document}
```

编译上述代码，得到表格如图5.4.8所示。
<p align="center">
<img align="middle" src="graphics/eg5_16new.png" width="350" />
</p>

<center><b>图5.4.8</b> 编译后的文档内容</center>

### 5.4.5 列宽

在5.4.2节中，我们介绍了使用`array`宏包提供的列类型参数可以在设置单元格对齐方式的同时对列宽进行调整。此外，也可以在导言区使用`\setlength{\tabcolsep}{文本和列分隔线的间距}`命令修改表格列宽，默认情况下，单元格内容与列分隔线的间距为6pt。

【**例5-17**】使用`\setlength{\tabcolsep}{12pt}`命令将表格单元格文本和列分隔线的间距设为12pt。

```tex
\documentclass[12pt]{article}
\setlength{\tabcolsep}{12pt}
\begin{document}

\begin{tabular}{|c|c|c|c|}
    \hline
    Column1 & Column2 & Column3 & Column4\\
    \hline
    A1 & A2 & A3 & A4\\
    \hline
    B1 & B2 & B3 & B4\\
    \hline
    C1 & C2 & C3 & C4\\
    \hline
\end{tabular}

\end{document}
```

编译上述代码，得到表格如图5.4.9所示。
<p align="center">
<img align="middle" src="graphics/eg5_17.png" width="350" />
</p>

<center><b>图5.4.9</b> 编译后的文档内容</center>


```tex
\documentclass[12pt]{article}
\usepackage{tabularx} 
\begin{document}

\begin{table}
    \centering
    \begin{tabularx}{\textwidth}{|p{3cm}|p{3cm}|p{3cm}|p{3cm}|}
    \hline
    Column1 & Column2 & Column3 & Column4\\
    \hline
    A1 & A2 & A3 & A4\\
    \hline
    B1 & B2 & B3 & B4\\
    \hline
    C1 & C2 & C3 & C4\\
    \hline
    \end{tabularx}
    \label{table1}
\end{table}

\end{document}
```


### 5.4.6 线宽

通过在导言区使用`\setlength{\arrayrulewidth}{线宽}`命令，可以修改表格线宽，默认为0.4pt。然而当线宽设置过大时，可能导致表格线交叉处不连续的情况。对此，在导言区调用`xcolor`宏包、并设置`table`选项可以解决。

【**例5-18**】在导言区使用`\usepackage[table]{xcolor}`命令调用设置了`table`选项的`xcolor`宏包，并使用`\setlength{\arrayrulewidth}{线宽}`命令设置表格线宽。

```tex
\documentclass[12pt]{article}
\usepackage[table]{xcolor} % 调用设置了table选项的xcolor宏包
\setlength{\arrayrulewidth}{2pt} % 修改表格线宽
\begin{document}

\begin{tabular}{|l|l|l|l|}
    \hline
    Column1 & Column2 & Column3 & Column4\\
    \hline
    A1 & A2 & A3 & A4\\
    \hline
    B1 & B2 & B3 & B4\\
    \hline
    C1 & C2 & C3 & C4\\
    \hline
\end{tabular}

\end{document}
```

编译上述代码，得到表格如图5.4.10所示。
<p align="center">
<img align="middle" src="graphics/eg5_11.png" width="350" />
</p>

<center><b>图5.4.10</b> 编译后的文档内容</center>

### 5.4.7 表格字体大小

在文本编辑中我们知道，调整字体大小的方式既有全局方式也有局部方式，其中，全局方式是通过在文档类型中指定字体大小，例如`\documentclass[12pt]{article}`，而局部方式则是通过一系列设置字体大小的命令，例如`\large`、`Large`、`huge`、`\fontsize`等，在全局字体大小的基础上作进一步的调整。类似地，在使用LaTeX创建表格时，我们也可以对表格字体大小做全局或局部调整。

【**例5-19**】使用`\Large`命令调整表格局部字体大小。

```tex
\documentclass[12pt]{article}
\begin{document}

% 正常字体大小
\begin{table}[htp]
    \centering
    \begin{tabular}{l|cccr}
        \hline
        & $x=1$ & $x=2$ & $x=3$ & $x=4$ \\
        \hline
        $y=x$ & 1 & 2 & 3 & 4 \\
        $y=x^{2}$ & 1 & 4 & 9 & 16 \\
        $y=x^{3}$ & 1 & 8 & 27 & 64 \\
        \hline
    \end{tabular}
\end{table}

% Large字体大小
\begin{table}[htp]
    \Large
    \centering
    \begin{tabular}{l|cccr}
        \hline
        & $x=1$ & $x=2$ & $x=3$ & $x=4$ \\
        \hline
        $y=x$ & 1 & 2 & 3 & 4 \\
        $y=x^{2}$ & 1 & 4 & 9 & 16 \\
        $y=x^{3}$ & 1 & 8 & 27 & 64 \\
        \hline
    \end{tabular}
\end{table}

\end{document}
```

编译上述代码，得到表格如图5.4.11所示。

<p align="center">
<img align="middle" src="graphics/eg5_28.png" width="350" />
</p>

<center><b>图5.4.11</b> 编译后的文档内容</center>

【**例5-20**】使用`\fontsize`命令通过具体设置来调整表格局部字体大小。

```tex
\documentclass[12pt]{article}
\begin{document}

% 正常字体大小
\begin{table}[htp]
    \centering
    \begin{tabular}{l|cccr}
        \hline
        & $x=1$ & $x=2$ & $x=3$ & $x=4$ \\
        \hline
        $y=x$ & 1 & 2 & 3 & 4 \\
        $y=x^{2}$ & 1 & 4 & 9 & 16 \\
        $y=x^{3}$ & 1 & 8 & 27 & 64 \\
        \hline
    \end{tabular}
\end{table}

% 将字体大小设为18pt、行距设为24pt
\begin{table}[htp]
    \fontsize{18pt}{24pt}\selectfont
    \centering
    \begin{tabular}{l|cccr}
        \hline
        & $x=1$ & $x=2$ & $x=3$ & $x=4$ \\
        \hline
        $y=x$ & 1 & 2 & 3 & 4 \\
        $y=x^{2}$ & 1 & 4 & 9 & 16 \\
        $y=x^{3}$ & 1 & 8 & 27 & 64 \\
        \hline
    \end{tabular}
\end{table}

\end{document}
```

编译上述代码，得到表格如图5.4.12所示。

<p align="center">
<img align="middle" src="graphics/eg5_29.png" width="350" />
</p>

<center><b>图5.4.12</b> 编译后的文档内容</center>

### 5.4.8 文字环绕表格

如果想要实现文字环绕表格效果，可以使用`wrapfig`宏包，并使用其提供的`wraptable`环境嵌套`tabular`环境创建表格，从而达到文字环绕表格的效果。

【**例5-21**】使用`wraptable`环境嵌套`tabular`环境创建表格，实现文字环绕表格；并使用`\begin{wraptable}{r}{8cm}`将表格置于文字右侧，同时将表格和文字的距离设为8cm。

```tex
\documentclass[12pt]{article}
\usepackage{wrapfig}
\begin{document}

In descriptive statistics, a box plot or boxplot is a method for graphically depicting groups of numerical data through their quartiles. Box plots may also have lines extending from the boxes (whiskers) indicating variability outside the upper and lower quartiles, hence the terms box-and-whisker plot and box-and-whisker diagram. Outliers may be plotted as individual points. Box plots are non-parametric: they display variation in samples of a statistical population without making any assumptions of the underlying statistical distribution (though Tukey's boxplot assumes symmetry for the whiskers and normality for their length).

\begin{wraptable}{r}{8cm}
\centering

\begin{tabular}{lcccc}
    \hline
     & $x=1$ & $x=2$ & $x=3$ & $x=4$ \\
    \hline
    $y=x$ &\multicolumn{1}{c}{1}  & 2 & 3 & 4 \\
    $y=x^{2}$ & 1 & \multicolumn{1}{c}{4} & 9 & 16 \\
    $y=x^{3}$ & 1 & 8 & \multicolumn{1}{c}{27} & 64 \\
    \hline
\end{tabular}

\end{wraptable}
The spacings between the different parts of the box indicate the degree of dispersion (spread) and skewness in the data, and show outliers. In addition to the points themselves, they allow one to visually estimate various L-estimators, notably the interquartile range, midhinge, range, mid-range, and trimean. Box plots can be drawn either horizontally or vertically. Box plots received their name from the box in the middle, and from the plot that they are.

\end{document}
```

编译上述代码，得到表格如图5.4.13所示。

<p align="center">
<img align="middle" src="graphics/eg5_30.png" width="550" />
</p>

<center><b>图5.4.13</b> 编译后的文档内容</center>


【回放】[**5.3 插入斜线与表注**](https://nbviewer.jupyter.org/github/xinychen/latex-cookbook/blob/main/chapter-5/section3.ipynb)

【继续】[**5.5 创建彩色表格**](https://nbviewer.jupyter.org/github/xinychen/latex-cookbook/blob/main/chapter-5/section5.ipynb)

### License

<div class="alert alert-block alert-danger">
<b>This work is released under the MIT license.</b>
</div>