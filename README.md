

> 此项目为南京大学2022下半学期计算机科学与技术系面向对象设计方法课程大作业



## 引言

### 开发任务介绍

基于设计模式的基础图形绘制软件

- 设计良好的用户界面，界面中要求至少有默认大小的三角形、方框、圆形、椭圆、连接线等种元素可供用户选择，绘制到画布上；
- 允许用户添加文字描述；
- 单机可以选中图形，并允许对图形的拷贝复制；
- 多个图形可以组合，组合后的图形同样有拷贝复制的功能；

- 支持撤销上一步操作的功能；



### 核心技术介绍

基于Qt的C++程序开发

> Qt是一个1991年由Qt Company开发的[跨平台](https://baike.baidu.com/item/跨平台/8558902)[C++](https://baike.baidu.com/item/C%2B%2B/99272)[图形用户界面](https://baike.baidu.com/item/图形用户界面/3352324)[应用程序](https://baike.baidu.com/item/应用程序/5985445)开发框架。它既可以开发GUI程序，也可用于开发非GUI程序，比如[控制台](https://baike.baidu.com/item/控制台/2438626)工具和[服务器](https://baike.baidu.com/item/服务器/100571)。Qt是[面向对象](https://baike.baidu.com/item/面向对象/2262089)的框架，使用特殊的[代码](https://baike.baidu.com/item/代码/86048)生成扩展（称为元对象编译器(Meta Object Compiler, moc)）以及一些[宏](https://baike.baidu.com/item/宏/2648286)，Qt很容易扩展，并且允许真正地组件编程。



## 目标系统分析

### 框架部分UML类图

![面向对象大作业 (1)](https://littleblacksimagesbed.oss-cn-hangzhou.aliyuncs.com/blogimages/%E9%9D%A2%E5%90%91%E5%AF%B9%E8%B1%A1%E5%A4%A7%E4%BD%9C%E4%B8%9A%20(1).png)

| 类名                    | 功能                                                         |
| ----------------------- | ------------------------------------------------------------ |
| Graphics                | 图形基类，拥有最基本的图形属性，保存一个QGraphicsItem对象    |
| LineItem                | 直线类，继承自Graphics图形基类                               |
| EllipseItem             | 椭圆类，继承自Graphics图形基类                               |
| RectangleItem           | 矩形类，继承自Graphics图形基类                               |
| TriangleItem            | 三角形类，继承自Graphics图形基类                             |
| TextItem                | 文本类，继承自Graphics图形基类                               |
| GraphicsGroup           | 图形组类，继承自Graphics图形基类，保存一个Graphics对象列表   |
| GraphicsValue           | 枚举类，保存所有可用的图形类型                               |
| AbstractGraphicsFactory | 抽象工厂类，定义产品生产方法                                 |
| GraphicsFactory         | 继承自抽象工厂类，实现产品生产方法                           |
| GraphicsAggregate       | 迭代器管理类，管理保存Graphics的迭代器                       |
| GraphicsIterator        | 迭代器单例类，保存场景内的所有Graphics                       |
| MyGraphicsScene         | 场景类，拥有GraphicsAggregate和GraphicsFactory实例，控制图元的添加等操作 |
| MyGraphicsView          | 继承自QGraphicsView，封装场景的容器                          |
| MyPaintBoard_ui         | Qt Designer根据设计文件自动生成的前端类，包含了GUI中所有组件 |
| MyPaintBoard            | 主类，控制鼠标点击，前端信号槽处理等核心功能                 |
| BoardMemento            | BoardMemento包含了要被恢复的MyGraphicsScene的状态            |
| BoardOriginator         | BoardOriginator 创建并在 BoardMemento对象中存储状态。        |
| BoardCareTaker          | BoardCareTaker对象负责从 BoardMemento中恢复对象的状态。      |
| main                    | 启动接口，装载CSS样式文件                                    |



### 设计模式介绍

#### 组合模式

![image-20220601222408179](https://littleblacksimagesbed.oss-cn-hangzhou.aliyuncs.com/blogimages/image-20220601222408179.png)

GraphicsGroup管理了多个Graphics对象，同时他自身又继承了Graphics基类，与Graphics一同存放在迭代器类中。

Graphics相当于树叶构件，GraphicsGroup相当于树枝构件



#### 工厂模式

![image-20220601222634973](https://littleblacksimagesbed.oss-cn-hangzhou.aliyuncs.com/blogimages/image-20220601222634973.png)

GraphicsFactory继承自抽象工厂类，拥有一系列创建不同GraphicsItem的方法



#### 迭代器模式

![image-20220601222751616](https://littleblacksimagesbed.oss-cn-hangzhou.aliyuncs.com/blogimages/image-20220601222751616.png)

GraphicsAggregate作为GraphicsIterator迭代器的管理类，负责管理迭代器的增删改查



#### 单例模式

![image-20220601222920039](https://littleblacksimagesbed.oss-cn-hangzhou.aliyuncs.com/blogimages/image-20220601222920039.png)

GraphicsIterator迭代器作为一个单例实现，使用内部类结构进行设计



#### 备忘录模式

![image-20220601223207433](https://littleblacksimagesbed.oss-cn-hangzhou.aliyuncs.com/blogimages/image-20220601223207433.png)

使用三个类BoardMemento、BoardOriginator 和 BoardCareTaker。BoardMemento包含了要被恢复的对象的状态。BoardOriginator 创建并在 BoardMemento对象中存储状态。BoardCareTaker对象负责从 BoardMemento中恢复对象的状态。



#### 适配器模式

![image-20220601223312445](https://littleblacksimagesbed.oss-cn-hangzhou.aliyuncs.com/blogimages/image-20220601223312445.png)

MyGraphicsScene直接作为一个适配器添加在架构中，拥有一个QGraphicsScene并封装了一系列与QGraphicsScene相关操作有关的接口和方法。





## 实现功能及界面展示

### 界面展示

![image-20220601223709085](https://littleblacksimagesbed.oss-cn-hangzhou.aliyuncs.com/blogimages/image-20220601223709085.png)



### 移动工具

移动工具可以单击选中图元。在按下鼠标不放时，可以拖动图元

![image-20220601224402341](https://littleblacksimagesbed.oss-cn-hangzhou.aliyuncs.com/blogimages/image-20220601224402341.png)



### 选择工具

![image-20220601224523401](https://littleblacksimagesbed.oss-cn-hangzhou.aliyuncs.com/blogimages/image-20220601224523401.png)

支持矩形选框批量选择图元，在批量选中的状态下，使用移动工具可以移动所有选中的图元



### 直线工具

![image-20220601223727114](https://littleblacksimagesbed.oss-cn-hangzhou.aliyuncs.com/blogimages/image-20220601223727114.png)

点击直线工具后，鼠标点击不放会自动生成虚线引导线，松开鼠标后自动绘制直线

同时，下方显示横纵坐标差和图元类型

![image-20220601223841103](https://littleblacksimagesbed.oss-cn-hangzhou.aliyuncs.com/blogimages/image-20220601223841103.png)

同时，可以双击直线设置宽度

![image-20220601223914261](https://littleblacksimagesbed.oss-cn-hangzhou.aliyuncs.com/blogimages/image-20220601223914261.png)

![image-20220601223921645](https://littleblacksimagesbed.oss-cn-hangzhou.aliyuncs.com/blogimages/image-20220601223921645.png)



### 矩形工具

右上角可设置线条宽度、边框颜色和填充颜色，并实时显示在示例矩形中

![image-20220601224039558](https://littleblacksimagesbed.oss-cn-hangzhou.aliyuncs.com/blogimages/image-20220601224039558.png)

![image-20220601224049175](https://littleblacksimagesbed.oss-cn-hangzhou.aliyuncs.com/blogimages/image-20220601224049175.png)

![image-20220601224102056](https://littleblacksimagesbed.oss-cn-hangzhou.aliyuncs.com/blogimages/image-20220601224102056.png)

随后绘制出的矩形会和示例中展示的样式完全一致

![image-20220601224133693](https://littleblacksimagesbed.oss-cn-hangzhou.aliyuncs.com/blogimages/image-20220601224133693.png)

同时，矩形的绘制也会在鼠标按下时生成虚线引导矩形方便绘制，松开鼠标后自动绘制

同时，下方显示横纵坐标差和图元类型

![image-20220601224226726](https://littleblacksimagesbed.oss-cn-hangzhou.aliyuncs.com/blogimages/image-20220601224226726.png)

双击矩形仍然可以设置线条宽度

![image-20220601224318017](https://littleblacksimagesbed.oss-cn-hangzhou.aliyuncs.com/blogimages/image-20220601224318017.png)

![image-20220601224327215](https://littleblacksimagesbed.oss-cn-hangzhou.aliyuncs.com/blogimages/image-20220601224327215.png)



### 三角形工具

![image-20220601224637075](https://littleblacksimagesbed.oss-cn-hangzhou.aliyuncs.com/blogimages/image-20220601224637075.png)

按下三角形工具，按住鼠标不放，会根据点击点和当前鼠标位置自动生成虚线等腰三角形引导，松开鼠标自动绘制，样式设置同上

同时，下方显示横纵坐标差和图元类型

![image-20220601224810279](https://littleblacksimagesbed.oss-cn-hangzhou.aliyuncs.com/blogimages/image-20220601224810279.png)

双击图元可设置宽度



### 文字工具

选择文字工具后，下方显示类型为”文字“，单击画布中任意位置出现文字输入框

![image-20220601225026595](https://littleblacksimagesbed.oss-cn-hangzhou.aliyuncs.com/blogimages/image-20220601225026595.png)

![image-20220601225038611](https://littleblacksimagesbed.oss-cn-hangzhou.aliyuncs.com/blogimages/image-20220601225038611.png)

文字输入完成并确定后，打开字体设置窗口，可设置字体、大小、样式等属性

![image-20220601225058924](https://littleblacksimagesbed.oss-cn-hangzhou.aliyuncs.com/blogimages/image-20220601225058924.png)

添加完成

![image-20220601225123762](https://littleblacksimagesbed.oss-cn-hangzhou.aliyuncs.com/blogimages/image-20220601225123762.png)



### 油漆桶工具

右上方靠右矩形颜色为油漆桶颜色，可通过下方按钮设置

![image-20220601225206540](https://littleblacksimagesbed.oss-cn-hangzhou.aliyuncs.com/blogimages/image-20220601225206540.png)

![image-20220601225210951](https://littleblacksimagesbed.oss-cn-hangzhou.aliyuncs.com/blogimages/image-20220601225210951.png)

随后单击油漆桶工具后点击图元，可将图元的填充颜色改为油漆桶的当前颜色

![image-20220601225249886](https://littleblacksimagesbed.oss-cn-hangzhou.aliyuncs.com/blogimages/image-20220601225249886.png)



### 组合工具

在选中多个图元的基础上，点击组合工具可以将所有选中的图元编组

![image-20220601225423939](https://littleblacksimagesbed.oss-cn-hangzhou.aliyuncs.com/blogimages/image-20220601225423939.png)

编组状态下，该图元组为单一图元，可统一拖拽和复制



### 打散工具 

在选中一个编组后，点击打散工具可以解散编组

![image-20220601230629280](https://littleblacksimagesbed.oss-cn-hangzhou.aliyuncs.com/blogimages/image-20220601230629280.png)

![image-20220601230638781](https://littleblacksimagesbed.oss-cn-hangzhou.aliyuncs.com/blogimages/image-20220601230638781.png)



### 复制工具

点击复制工具后，会自动复制所有选中的图元（包括图元组），并自动添加到场景内

![image-20220601230739801](https://littleblacksimagesbed.oss-cn-hangzhou.aliyuncs.com/blogimages/image-20220601230739801.png)





## 小结

通过本次大作业的编写，不仅提升了我的C++变慢能力，也使我对具体使用到的这些设计模式有了更为深入的了解和印象。同时，自己完成一个可用的项目也使得我非常有成就感，感谢老师和助教的辛勤付出！

