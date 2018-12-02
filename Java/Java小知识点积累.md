## String与char的转换

```
String str
//str==>char数组
char[] chars = str.toCharArray();
//char数组==>String
String.valueOf(chars);
```

## 生成随机数
```
Random ran = new Random();
// 生成1 - 100 的随机数
int temp = ran.nextInt(100) + 1;
```

## 直接打印出一个数组
```
System.out.println(Arrays.toString(num));
```