# MSCR-Minimalist-Shaogod-for-Cinese-Runner-
## 简介
MSCR(Minimalist Shaogod for Cinese Runner)是我开发的一款采用c++语言的中文编程语言的运行工具，内部实现类似JVM，基于我早期开发的sws语言GUI版本。<br/> MSCR类似c语言，只不过体积比gcc小得多（仅14kb），同时支持简单的图形界面，MSCR采用中文编程，比sws语言更好玩。 MSCR全部由我（邵帝）开发，由于本人刚刚初中毕业，水平有限，软件可能存在一些bug，希望大家理解，也欢迎报告问题和建议!<br/>
[立即下载体验](https://github.com/Shaoqirui/MSCR-Minimalist-Shaogod-for-Cinese-Runner-/releases/tag/1)<br/>
## MSCR的语法
### 基本语句:
MSCR的基本语句类似c语言，不详细解释了，直接上示例
示例1：
 ```
创建一个函数 d
定义全局变量 q
q 为 ( 1 + 2 )
数字 a
a 为 0
输出 "ok\n" ;
如果 ( q 等于 0 ) {
输出 q , "函数" ;
}
返回
创建一个函数 main
运行 d
坚持住！
返回

 ```
窗体组建:
窗口:
如何创建一个窗口:
 ```
窗口 100 90 80 70 form1
 ```
(创建一个窗口，距离窗体顶端100个像素，距离窗体左端90个像素，长度80个像素，宽度70个像素，名称为form1)
完整创建按钮代码：
 ```
创建   
窗口 100 90 80 70 form1
结束
支持事件：鼠标点击，鼠标移过:
鼠标点击：
form1_click
鼠标移过:
form1_mousemove
实例代码（鼠标点击输出字符）:
创建   
窗口 100 90 80 70 form1
结束
事件 form1_click
print "mouse has moved on form1!" ;
完成
 ```
-----------------------
Button:
如何创建一个按钮:
 ```
button 100 90 80 70 button1
 ```
(创建一个按钮，距离窗体顶端100个像素，距离窗体左端90个像素，长度80个像素，宽度70个像素，名称为button1)
完整创建按钮代码：
 ```
创建   
按钮 100 90 80 70 button1
结束
支持事件：鼠标点击，鼠标移过:
鼠标点击：
button1_click
鼠标移过:
button1_mousemove
实例代码（鼠标移过输出字符）:
创建   
按钮 100 90 80 70 button1
结束
事件 button1_mousemove
print "mouse has moved on button1!" ;
完成
 ```
-----------------------
Label:
如何创建一个文本标签:
 ```
标签 100 90 80 70 label1
 ```
(创建一个文本标签，距离窗体顶端100个像素，距离窗体左端90个像素，长度80个像素，宽度70个像素，名称为label1)
完整创建文本标签代码：
 ```
创建   
标签 100 90 80 70 label1
结束
支持事件：鼠标点击，鼠标移过:
鼠标点击：
label1_click
鼠标移过:
label1_mousemove
实例代码（鼠标移过输出字符）:
创建   
label 100 90 80 70 label1
结束
事件 label1_mousemove
print "mouse has moved on label1!" ;
完成
 ```
-----------------------
Textbox:
如何创建一个文本框:
 ```
文本框 100 90 80 70 textbox1
 ```
(创建一个文本框，距离窗体顶端100个像素，距离窗体左端90个像素，长度80个像素，宽度70个像素，名称为label1)
完整创建文本框代码：

 ```
创建   
文本框 100 90 80 70 textbox1
结束
支持事件：鼠标点击，鼠标移过:
鼠标点击：
textbox1_click
鼠标移过:
textbox1_mousemove
实例代码（鼠标移过输出字符）:
创建   
textbox 100 90 80 70 textbox1
结束
事件 textbox1_mousemove
print "mouse has moved on textbox1!" ;
完成
 ```
-----------------------

