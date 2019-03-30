# KLaTexEditor
使用Qt5.11.3 的QWebEngine。
使用klatex mathjax 渲染公式



# todo
- [ ] 应用程序单例
- [ ] 工具栏 ribbon
- [ ] 无边框 Linux下要重写xevent
- [ ] 文本编辑框多标签
- [ ] 渲染引擎的选择
- [ ] 书签
- [ ] 语法提示
- [ ] 打开文本
- [ ] 历史
- [ ] hdpi
- [ ] 离线版本

# OCR - todo
- git clone git@github.com:Mathpix/api-examples.git
- Mathpix可以识别公式。具体使用方法在这里 http://cn.docs.mathpix.com/
- 调用python没问题。这个可以做成一个dll or so。用动态加载的方式去搞比较好。
- 这个东西放到工具栏比较好。

## webview工具栏 - todo

- 下面JS渲染器是指Katex与MathJax两个渲染器。JS语法是指使用JS的形式 

功能 | 可否实现 |  实现方式  
-|-|-
字体颜色 | √ | 1.JS渲染器都支持自定义文本颜色 2.使用JS语法|
背景颜色 | √ | 1.qwidget可以设置背景颜色。 2. 使用JS语法 |
字体大小选择 | √ | JS渲染器支持 |
字体类型选择 | √ | JS渲染器支持|
拷贝到系统剪切板 | √ | 1.QWidget render函数 2. JS渲染器的语法
另存为 | √ | 1.调用Qt对话框 2. 调用系统对话框。 png，svg，jpg。
图片质量 | √ | 这个放到ribbbon工具栏是不是比较好

## katex
- [ ] 导出png
- [ ] 导出jpg
- [ ] 导出svg
- [x] 行内公式
- [x] 行外公式

## MathJax
- [x] MathJax渲染
- [ ] 导出png
- [ ] 导出jpg
- [ ] 导出svg
- [ ] 行内公式
- [x] 行外公式





