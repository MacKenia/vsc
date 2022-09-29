# Dart 变量

> 一切皆对象, 数字也不例外

## 注释

``` dart
// 注释
/* 注释 */
```

## 在字符串中使用变量

```dart
print("$variableName");
print("${expression}");
```

## 变量

``` dart
var name = 'Bob';           // 建议申请局部变量
Object name = 'Bob';
String name = 'Bob';
```

## 默认值

``` dart
int? lineCount;             // 初始值为 null
```

## Late 变量

### 显示声明一个非空变量，但不初始化

``` dart
class cal {
    late String temperature;
}
```

如果不加 `late` 关键字，类实例化时此值是不确定的，无法通过静态检查，加上 `late` 关键字可以通过静态检查，但由此会带来运行时风险

### 延时初始化一个变量

``` dart
late String temperature = readThermometer();
```

若 `temperature` 未被访问，那么 `readThermometer()` 就不会被调用

## `final` 和 `const`

用于申请不可更改的值

### final

``` dart
final name = "Bob";     // √

final name;             // ×
name = "Bob";

class cal {

}

```

运行时赋值且只能赋值一次

该值在运行时确定

### const

``` dart
```

`const` 修饰的变量会在编译器以至于应用整个生命周期内都是不可变的常量，在内存中也只会创建一次，之后的每次调用都会复用第一次创建的对象变量属于编译时变量

该值在编译时确定