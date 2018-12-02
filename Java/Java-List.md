## ArrayList小知识基类

### 简单操作
添加是 add,获得第i个数字是get,删除是`list.remove()`删除所有元素是`list.clear()`或者`list = null`

注意点：
如果二维数组test想加入list，方法自然是
```
test.add(list)
```
但是如果用了
```
list.clear()
```
则会出现test中的list元素也被删除的情况，这个问题的解决方案是
```
test.add(new Arraylist<Integer>(list))
```
这样就不会出现上面的问题

### List是否包含某个元素
```
list.contains(ch)
```


### 创建
一般是
```
List<Integer> list = new ArrayList<Integer>();
```

### 输出整个数组
```
//方法1
for(int i = 0;i < list.size();i++){
    System.out.println(list.get(i));
}
//方法2
Iterator it = list.iterater();
while(it.hasNext()){
    System.out.println(it.next());
}
```

### 实现排序
```
Collections.sort(list);
```
如果想要按照自己的方式进行排序,采用一下方式:

首先import进两个包:
```
import java.util.Collections;
import java.util.Comparator;
```
然后重写Comparator接口的compare方法
```
Collections.sort(list,new Comparator<String>(){
    @Override
    public int compare(String s1,String s2){
        String c1 = s1 + s2;
        String c2 = s2 + s1;
        return c1.compareTo(c2);
    }
});
```