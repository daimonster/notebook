## 数组小知识点总结

### 直接打印出一个数组
```
System.out.println(Arrays.toString(num));
```

### 数字数组的快速排序
```
int [] a = {4,2,3,1,6};
Arrays.sort(a);
```
    如果想自定义sort的话,就重写Arrays的Comparator借口,详情参见ArrayList的sort接口
    
### 复制数组
```
//方法一：for循环  
for (int i = 0; i < b.length; i++)   
{  
    b[i] = a[i];  
}  
//方法二： System.arraycopy(src, srcPos, dest, destPos, length)  
//src: 源数组  
//srcPos: 从源数组复制数据的起始位置  
//dest: 目标数组  
//destPos: 复制到目标数组的起始位置  
//length: 复制的长度  
System.arraycopy(a, 0, b, 0, 3);  
```